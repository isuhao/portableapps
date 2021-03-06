// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2009 Steven Lamerton
// License:     GNU GPL 2 (See readme for more info)
/////////////////////////////////////////////////////////////////////////////////

#include "syncbase.h"
#include "syncfiles.h"
#include "../md5.h"
#include "../toucan.h"
#include "../basicfunctions.h"
#include <list>
#include <map>
#include <wx/string.h>
#include <wx/datetime.h>
#include <wx/filename.h>
#include <wx/dir.h>

SyncFiles::SyncFiles(wxString syncsource, wxString syncdest, SyncData* syncdata, Rules syncrules){
	if(syncsource[syncsource.Length() - 1] == wxFILE_SEP_PATH){
		this->sourceroot = syncsource.Left(syncsource.Length() - 1);
	}
	else{
		sourceroot = syncsource;
	}
	if(syncdest[syncdest.Length() - 1] == wxFILE_SEP_PATH){
		this->destroot = syncdest.Left(syncdest.Length() - 1);
	}
	else{
		destroot = syncdest;
	}
	this->data = syncdata;
	this->rules = syncrules;
}

bool SyncFiles::Execute(){
	std::list<wxString> sourcepaths = FolderContentsToList(sourceroot);
	std::list<wxString> destpaths = FolderContentsToList(destroot);
	std::map<wxString, short> mergeresult = MergeListsToMap(sourcepaths, destpaths);
	OperationCaller(mergeresult);
	return true;
}

bool SyncFiles::OnSourceNotDestFile(wxString path){
	wxString source = sourceroot + wxFILE_SEP_PATH + path;
	wxString dest = destroot + wxFILE_SEP_PATH + path;
	//Whatever function we have we always copy in this case, unless it is excluded
	if(!rules.ShouldExclude(source, false)){
		CopyFile(source, dest);		
	}

	return true;
}
bool SyncFiles::OnNotSourceDestFile(wxString path){
	wxString source = sourceroot + wxFILE_SEP_PATH + path;
	wxString dest = destroot + wxFILE_SEP_PATH + path;
	if(data->GetFunction() == _("Mirror")){
		if(!rules.ShouldExclude(dest, false)){
			RemoveFile(dest);			
		}
	}
	else if(data->GetFunction() == _("Equalise")){
		if(!rules.ShouldExclude(dest, false)){
			//Swap them around as we are essentially in reverse
			CopyFile(dest, source);
		}
	}
	return true;
}
bool SyncFiles::OnSourceAndDestFile(wxString path){
	wxString source = sourceroot + wxFILE_SEP_PATH + path;
	wxString dest = destroot + wxFILE_SEP_PATH + path;
	if(!rules.ShouldExclude(source, false)){
		if(data->GetFunction() == _("Copy") || data->GetFunction() == _("Mirror")){
			//Use the hash check version to minimise copying
			CopyFileHash(source, dest);
		}
		else if(data->GetFunction() == _("Update")){
			UpdateFile(source, dest);
		}		
	}
	if(data->GetFunction() == _("Equalise")){
		SourceAndDestCopy(source, dest);
	}
	return true;
}
bool SyncFiles::OnSourceNotDestFolder(wxString path){
	//Call the function on the next subfolder
	wxString source = sourceroot + wxFILE_SEP_PATH + path;
	wxString dest = destroot + wxFILE_SEP_PATH + path;
	//Always recurse into the next directory
	SyncFiles sync(source, dest, data, rules);
	sync.Execute();
	wxDir dir(dest);
	if(!dir.HasFiles() && !dir.HasSubDirs() && rules.ShouldExclude(source, true)){
		wxRmdir(dest);
	}
	else{
		//Set the timestamps if needed
		if(data->GetTimeStamps()){
			CopyFolderTimestamp(source, dest);
		}	
	}
	return true;
}
bool SyncFiles::OnNotSourceDestFolder(wxString path){
	wxString source = sourceroot + wxFILE_SEP_PATH + path;
	wxString dest = destroot + wxFILE_SEP_PATH + path;
	if(data->GetFunction() == _("Mirror")){
		if(!rules.ShouldExclude(dest, true)){
			RemoveDirectory(dest);		
		}
	}
	if(data->GetFunction() == _("Equalise")){
		SyncFiles sync(source, dest, data, rules);
		sync.Execute();
		wxDir dir(source);
		if(!dir.HasFiles() && !dir.HasSubDirs() && rules.ShouldExclude(dest, true)){
			wxRmdir(dest);
		}
		else{
			//Set the timestamps if needed
			if(data->GetTimeStamps()){
				CopyFolderTimestamp(dest, source);
			}	
		}
	}
	return true;
}
bool SyncFiles::OnSourceAndDestFolder(wxString path){
	wxString source = sourceroot + wxFILE_SEP_PATH + path;
	wxString dest = destroot + wxFILE_SEP_PATH + path;
	//Always recurse into the next directory
	SyncFiles sync(source, dest, data, rules);
	sync.Execute();
	wxDir dir(dest);
	if(!dir.HasFiles() && !dir.HasSubDirs() && rules.ShouldExclude(source, true)){
		wxRmdir(dest);
	}
	else{
		//Set the timestamps if needed
		if(data->GetTimeStamps()){
			CopyFolderTimestamp(source, dest);
		}	
	}
	return true;
}

bool SyncFiles::CopyFile(wxString source, wxString dest){
	bool ShouldTimeStamp = false;
	#ifdef __WXMSW__
		long destAttributes = 0;
		long sourceAttributes = 0;
	#endif
	if(data->GetIgnoreRO()){
		#ifdef __WXMSW__
			destAttributes = GetFileAttributes(dest);
			if(destAttributes == -1){
				destAttributes = FILE_ATTRIBUTE_NORMAL;					
			}
			SetFileAttributes(dest,FILE_ATTRIBUTE_NORMAL); 
			sourceAttributes = GetFileAttributes(source);
			if(sourceAttributes == -1){
				sourceAttributes = FILE_ATTRIBUTE_NORMAL;					
			}
			SetFileAttributes(source,FILE_ATTRIBUTE_NORMAL); 
		#endif
		//To make sure that we can copy attributes and such
		
	} 

	if(wxCopyFile(source, wxPathOnly(dest) + wxFILE_SEP_PATH + wxT("Toucan.tmp"), true)){
		if(wxRenameFile(wxPathOnly(dest) + wxFILE_SEP_PATH + wxT("Toucan.tmp"), dest, true)){
			OutputProgress(wxT("Copied  ") + data->GetPreText() +  source.Right(source.Length() - data->GetLength()));
			ShouldTimeStamp = true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
	if(wxFileExists(wxPathOnly(dest) + wxFILE_SEP_PATH + wxT("Toucan.tmp"))){
		if(!wxRemoveFile(wxPathOnly(dest) + wxFILE_SEP_PATH + wxT("Toucan.tmp"))){
			return false;
		}
	}
	if(data->GetTimeStamps() && ShouldTimeStamp){
		wxFileName from(source);
		wxFileName to(dest);
		wxDateTime access, mod, created;
		from.GetTimes(&access ,&mod ,&created );
		to.SetTimes(&access ,&mod , &created); 
	}	
	//Set the old attributes back
	if(data->GetIgnoreRO()){
		#ifdef __WXMSW__
			SetFileAttributes(dest, destAttributes); 
			SetFileAttributes(source, sourceAttributes); 
		#endif
	} 
	if(data->GetAttributes()){
		#ifdef __WXMSW__
			int filearrtibs = GetFileAttributes(source);
			SetFileAttributes(dest,FILE_ATTRIBUTE_NORMAL);                       
			SetFileAttributes(dest,filearrtibs);
		#endif
	}
	return true;
}

bool SyncFiles::UpdateFile(wxString source, wxString dest){
	wxDateTime tmTo, tmFrom;
	wxFileName flTo(dest);
	wxFileName flFrom(source);
	flTo.GetTimes(NULL, &tmTo, NULL);
	flFrom.GetTimes(NULL, &tmFrom, NULL);		

	if(data->GetIgnoreDLS()){
		tmFrom.MakeTimezone(wxDateTime::Local, true);
	}

	if(tmFrom.IsLaterThan(tmTo)){
		CopyFileHash(source, dest);
	}
	return true;
}

bool SyncFiles::CopyFileHash(wxString source, wxString dest){
	wxMD5* md5 = new wxMD5();
	if(md5->GetFileMD5(source) != md5->GetFileMD5(dest)){
		CopyFile(source, dest);
	}
	delete md5;
	return true;
}

bool SyncFiles::RemoveDirectory(wxString path){
	if(wxGetApp().ShouldAbort()){
		return true;
	}
	// ATTN : Can be replaced when move to wxWidgets 2.9
	if(wxGetApp().ShouldAbort()){
		return true;
	}
	//Make sure that the correct ending is appended
	if (path[path.length()-1] != wxFILE_SEP_PATH) {
		path += wxFILE_SEP_PATH;       
	}
	// if it's a possible root directory
	if (path.length() <= 3) {
		wxLogError(_("Toucan tried to delete a root directory. This has been forbidden for your own safety"));
		return false;
	}
	wxDir* dir = new wxDir(path);
	wxString filename;
	bool blDir = dir->GetFirst(&filename);
	if(blDir){
		do {
			if(wxGetApp().ShouldAbort()){
				return true;
			}
			if(wxDirExists(path + filename)){
				RemoveDirectory(path + filename);
			}
			else{
				if(wxRemoveFile(path + filename)){
                    OutputProgress(_("Removed ") + path + filename);
					//We have to increment the gauge for ourself here
					if(wxGetApp().GetUsesGUI()){
						IncrementGauge();					
					}
                }
            }
	
		}
		while (dir->GetNext(&filename) );
	} 
	delete dir;
  	wxLogNull log;
	if(wxFileName::Rmdir(path)){
        OutputProgress(_("Removed ") + path);
    }
	return true;
}

bool SyncFiles::CopyFolderTimestamp(wxString source, wxString dest){
	// ATTN : Can be replaced when move to wxWidgets 2.9, or patch backport
	#ifdef __WXMSW__
		//Need to tidy up this code and submit as a patch to wxWidgets
		FILETIME ftCreated,ftAccessed,ftModified;
		HANDLE hFrom = CreateFile(source, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
		if(hFrom == INVALID_HANDLE_VALUE){
		  return false;
		}  
		
		GetFileTime(hFrom,&ftCreated,&ftAccessed,&ftModified);
		CloseHandle(hFrom);
		HANDLE hTo = CreateFile(dest, GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
		if(hTo == INVALID_HANDLE_VALUE){
		  return false;
		}  
		SetFileTime(hTo,&ftCreated,&ftAccessed,&ftModified);
		CloseHandle(hTo);
	#else
		wxFileName from(source);
		wxFileName to(dest);
		wxDateTime access, mod, created;
		from.GetTimes(&access ,&mod ,&created );
		to.SetTimes(&access ,&mod , &created); 
	#endif
	return true;
}

bool SyncFiles::RemoveFile(wxString path){
	if(wxRemoveFile(path)){
		OutputProgress(_("Removed  ") + data->GetPreText() + path.Right(path.Length() - data->GetLength()));			
	}
	return true;
}

bool SyncFiles::SourceAndDestCopy(wxString source, wxString dest){
	wxDateTime tmTo, tmFrom;
	wxFileName flTo(dest);
	wxFileName flFrom(source);
	flTo.GetTimes(NULL, &tmTo, NULL);
	flFrom.GetTimes(NULL, &tmFrom, NULL);		

	if(data->GetIgnoreDLS()){
		tmFrom.MakeTimezone(wxDateTime::Local, true);
	}

	if(tmFrom.IsLaterThan(tmTo)){
		if(!rules.ShouldExclude(source, false)){
			CopyFileHash(source, dest);			
		}
	}
	else if(tmTo.IsLaterThan(tmFrom)){
		if(!rules.ShouldExclude(dest, false)){
			CopyFileHash(dest, source);
		}
	}
	return true;	
}
