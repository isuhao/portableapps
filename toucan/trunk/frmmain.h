/////////////////////////////////////////////////////////////////////////////
// Name:        frmmain.h
// Purpose:     
// Author:      Steven Lamerton
// Modified by: 
// Created:     08/02/2007 19:08:07
// RCS-ID:      
// Copyright:   Copyright (C)  2006 Steven Lamerton
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// Generated by DialogBlocks (Personal Edition), 08/02/2007 19:08:07

#ifndef _FRMMAIN_H_
#define _FRMMAIN_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma interface "frmmain.h"
#endif

/*!
* Includes
*/

////@begin includes
#include "wx/notebook.h"
#include "wx/listctrl.h"
////@end includes

#include <wx/dirctrl.h>
/*!
* Forward declarations
*/

////@begin forward declarations
class wxBoxSizer;
class wxListCtrl;
////@end forward declarations

/*!
* Control identifiers
*/

////\@begin control identifiers
#define ID_DIALOG_MAIN 10000
#define SYMBOL_FRMMAIN_STYLE wxDEFAULT_DIALOG_STYLE|wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX|wxDIALOG_MODAL
#define SYMBOL_FRMMAIN_TITLE wxT("Toucan")
#define SYMBOL_FRMMAIN_IDNAME ID_DIALOG_MAIN
#define SYMBOL_FRMMAIN_SIZE wxSize(640, 500)
#define SYMBOL_FRMMAIN_POSITION wxDefaultPosition
#define ID_NOTEBOOK1 10001
#define ID_PANEL_SYNC 10002
#define ID_TEXTCTRL_SYNC_FIRST 10005
#define ID_BUTTON_SYNC1 10006
#define ID_BITMAPBUTTON_SYNC_ADDVAR1 10049
#define ID_BITMAPBUTTON_SYNC_SAVE 10023
#define ID_BITMAPBUTTON_SYNC_OPEN 10024
#define ID_TEXTCTRL_SYNC_SECOND 10007
#define ID_BUTTON_SYNC2 10008
#define ID_BITMAPBUTTON_SYNC_ADDVAR2 10030
#define ID_RADIOBOX1 10009
#define ID_LISTBOX2 10031
#define ID_BITMAPBUTTON_SYNC_ADDEX 10034
#define ID_BITMAPBUTTON_SYNC_REMOVEEX 10035
#define ID_BUTTON_SYNC 10015
#define ID_PANEL_BACKUP 10003
#define wxID_STATIC_1 10047
#define ID_TEXTCTRL_BACKUP1 10016
#define ID_BUTTON_BACKUP1 10017
#define ID_BITMAPBUTTON_BACKUP_ADDVAR1 10026
#define ID_BITMAPBUTTON_BACKUP_SAVE 10025
#define ID_BITMAPBUTTON_BACKUP_OPEN 10060
#define wxID_STATIC_2 10048
#define ID_TEXTCTRL_BACKUP2 10018
#define ID_BUTTON_BACKUP2 10019
#define ID_BITMAPBUTTON_BACKUP_ADDVAR2 10029
#define ID_RADIOBOX_BACKUPTYPE 10020
#define ID_RADIOBOX3 10021
#define ID_RADIOBOX4 10022
#define ID_LISTBOX 10011
#define ID_BITMAPBUTTON_BACKUPEXADD 10064
#define ID_BITMAPBUTTON_BACKUPEXREM 10065
#define ID_BUTTON_BACKUP 10027
#define ID_PANEL_SECURE 10004
#define ID_BITMAPBUTTON_SECURE_ADD 10043
#define ID_BITMAPBUTTON_SECURE_REMOVE 10044
#define ID_BITMAPBUTTON_SECURE_SAVE 10045
#define ID_BITMAPBUTTON_SECURE_OPEN 10046
#define ID_BITMAPBUTTON_SECURE_MAKERELATIVE 10037
#define ID_BITMAPBUTTON_SECURE_ADDVAR 10042
#define ID_LISTBOX1 10032
#define ID_RADIOBOX5 10038
#define ID_TEXTCTRL5 10039
#define ID_TEXTCTRL6 10040
#define ID_BUTTON_SECURE 10041
#define ID_PANEL_PV 10050
#define ID_COMBOBOX 10014
#define ID_BITMAPBUTTON_PVADD 10028
#define ID_BITMAPBUTTON_PVREMOVE 10051
#define ID_LISTCTRL 10052
#define ID_BITMAPBUTTON_PVADDLIST 10053

#define ID_PANEL_OTHER 10010
////\@end control identifiers
#define ID_TREECTRL1 10050
#define ID_TOOLTIP 10100
#define ID_TABSTYLE 10101
#define ID_BITMAPBUTTON_PVREMOVELIST 10102
#define ID_HELP 10103
/*!
* Compatibility
*/

#ifndef wxCLOSE_BOX
#define wxCLOSE_BOX 0x1000
#endif

/*!
* frmMain class declaration
*/

class frmMain: public wxDialog
{    
	DECLARE_DYNAMIC_CLASS( frmMain )
	DECLARE_EVENT_TABLE()

public:
	/// Constructors
	frmMain( );
	frmMain( wxWindow* parent, wxWindowID id = SYMBOL_FRMMAIN_IDNAME, const wxString& caption = SYMBOL_FRMMAIN_TITLE, const wxPoint& pos = SYMBOL_FRMMAIN_POSITION, const wxSize& size = SYMBOL_FRMMAIN_SIZE, long style = SYMBOL_FRMMAIN_STYLE );

	/// Creation
	bool Create( wxWindow* parent, wxWindowID id = SYMBOL_FRMMAIN_IDNAME, const wxString& caption = SYMBOL_FRMMAIN_TITLE, const wxPoint& pos = SYMBOL_FRMMAIN_POSITION, const wxSize& size = SYMBOL_FRMMAIN_SIZE, long style = SYMBOL_FRMMAIN_STYLE );

	/// Initialises member variables
	void Init();

	/// Creates the controls and sizers
	void CreateControls();

	////\@begin frmMain event handler declarations

	/// wxEVT_CLOSE_WINDOW event handler for ID_DIALOG_MAIN
	void OnCloseWindow( wxCloseEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SYNC1
	void OnButtonSync1Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SYNC_ADDVAR1
	void OnBitmapbuttonSyncAddvar1Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SYNC_SAVE
	void OnBitmapbuttonSyncSaveClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SYNC_OPEN
	void OnBitmapbuttonSyncOpenClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SYNC2
	void OnButtonSync2Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SYNC_ADDVAR2
	void OnBitmapbuttonSyncAddvar2Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SYNC_ADDEX
	void OnBitmapbuttonSyncAddexClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SYNC_REMOVEEX
	void OnBitmapbuttonSyncRemoveexClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SYNC
	void OnButtonSyncClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BACKUP1
	void OnButtonBackup1Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_BACKUP_ADDVAR1
	void OnBitmapbuttonBackupAddvar1Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_BACKUP_SAVE
	void OnBitmapbuttonBackupSaveClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_BACKUP_OPEN
	void OnBitmapbuttonBackupOpenClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BACKUP2
	void OnButtonBackup2Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_BACKUP_ADDVAR2
	void OnBitmapbuttonBackupAddvar2Click( wxCommandEvent& event );

	/// wxEVT_COMMAND_RADIOBOX_SELECTED event handler for ID_RADIOBOX_BACKUPTYPE
	void OnRadioboxBackuptypeSelected( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_BACKUPEXADD
	void OnBitmapbuttonBackupexaddClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_BACKUPEXREM
	void OnBitmapbuttonBackupexremClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_BACKUP
	void OnButtonBackupClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SECURE_ADD
	void OnBitmapbuttonSecureAddClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SECURE_REMOVE
	void OnBitmapbuttonSecureRemoveClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SECURE_SAVE
	void OnBitmapbuttonSecureSaveClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SECURE_OPEN
	void OnBitmapbuttonSecureOpenClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SECURE_MAKERELATIVE
	void OnBitmapbuttonSecureMakerelativeClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_SECURE_ADDVAR
	void OnBitmapbuttonSecureAddvarClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON_SECURE
	void OnButtonSecureClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_COMBOBOX
	void OnComboboxSelected( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PVADD
	void OnBitmapbuttonPvaddClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PVREMOVE
	void OnBitmapbuttonPvremoveClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_LIST_ITEM_ACTIVATED event handler for ID_LISTCTRL
	void OnListctrlItemActivated( wxListEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PVADDLIST
	void OnBitmapbuttonPvaddlistClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BITMAPBUTTON_PVREMOVELIST
	void OnBitmapbuttonPvremovelistClick( wxCommandEvent& event );

	/// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_ABOUT
	void OnABOUTClick( wxCommandEvent& event );
		/// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_ABOUT
	void OnHELPClick( wxCommandEvent& event );

	////\@end frmMain event handler declarations

	////\@begin frmMain member function declarations

	wxString GetStrMain() const { return strMain ; }
	void SetStrMain(wxString value) { strMain = value ; }

	/// Retrieves bitmap resources
	wxBitmap GetBitmapResource( const wxString& name );

	/// Retrieves icon resources
	wxIcon GetIconResource( const wxString& name );
	////\@end frmMain member function declarations

	/// Should we show tooltips?
	static bool ShowToolTips();
	wxGenericDirCtrl* m_Tree;
	////\@begin frmMain member variables
	wxTextCtrl* m_Sync_First;
	wxTextCtrl* m_Sync_Second;
	wxRadioBox* m_Sync_Function;
	wxListBox* m_sync_listex;
	wxStaticText* m_BackupText1;
	wxTextCtrl* m_Backup1;
	wxStaticText* m_BackupText2;
	wxTextCtrl* m_Backup2;
	wxRadioBox* m_BackupType;
	wxRadioBox* m_BackupFormat;
	wxRadioBox* m_BackupRatio;
	wxListBox* m_backup_listex;
	wxBoxSizer* m_GenericBox;
	wxListBox* m_ListSecure;
	wxRadioBox* m_FunctionSecure;
	wxTextCtrl* m_Pass;
	wxTextCtrl* m_RePass;
	wxComboBox* m_PVCombo;
	wxListCtrl* m_List;
	wxRadioBox* m_Tooltip;
	wxRadioBox* m_TabStyle;
	public:
	wxString strMain;
	////\@end frmMain member variables

};

#endif
// _FRMMAIN_H_