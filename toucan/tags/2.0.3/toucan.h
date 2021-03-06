/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2006-2008 Steven Lamerton
// License:     GNU GPL 2 (See readme for more info)
/////////////////////////////////////////////////////////////////////////////////

#ifndef _TOUCAN_H_
#define _TOUCAN_H_

#include <wx/wx.h>
#include <wx/process.h>
#include <wx/image.h>
#include <wx/intl.h>

#include "frmmain.h"
#include "settings.h"
#include "frmprogress.h"
#include "script.h"
//class frmMain;

/*!
* Toucan class declaration
*/

class Toucan: public wxApp
{    
	public:

	/// Constructor
	Toucan();

	void Init();

	/// Initialises the application
	virtual bool OnInit();

	/// Called on exit
	virtual int OnExit();

	void SetLanguage(wxString langcode);
				
	bool ShouldAbort() { return blAbort; }
	void SetAbort(bool abort) { blAbort = abort; }
	
	wxString GetSettingsPath() { return strSettingsPath; }
	void SetSettingsPath(wxString settingspath) { strSettingsPath = settingspath; }
		
	frmMain* MainWindow;
	frmProgress* ProgressWindow;
	Settings* m_Settings;
	wxLocale* m_Locale;	
	ScriptManager* m_Script;
	bool blGUI;
	
protected:
	//Abort the current job
	bool blAbort;
	//The settings path
	wxString strSettingsPath;

};

DECLARE_APP(Toucan)

#endif

