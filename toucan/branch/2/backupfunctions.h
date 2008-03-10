#ifndef H_BACKUPFUNCTIONS
#define H_BACKUPFUNCTIONS

bool CreateList(wxTextFile *file, Rules rules, wxString strPath, int iRootLength){
	//Clean up the path passed
	if (strPath[strPath.length()-1] != wxFILE_SEP_PATH) {
		strPath += wxFILE_SEP_PATH;       
	}
	wxDir dir(strPath);
	wxString strFilename;
	bool blDir = dir.GetFirst(&strFilename);
	//If the path is ok
	if(blDir){
		//Loop through all of the files and folders in the directory
		do {
			//If it is a directory
			if(wxDirExists(strPath + strFilename))
			{
				//Always call the function again to ensure that ALL files and folders are processed
				CreateList(file, rules, strPath + strFilename, iRootLength);
			}
			//If it is a file
			else{
				if(rules.ShouldExclude(strPath + strFilename, false)){
				//	wxMessageBox(_("Excluding"));
					wxString strCombined = strPath + strFilename;
					strCombined = strCombined.Right(strCombined.Length() - iRootLength - 1);
					file->AddLine(strCombined);
				}
			}
		}
		while (dir.GetNext(&strFilename) );
	}  
	return true;
}

#endif
