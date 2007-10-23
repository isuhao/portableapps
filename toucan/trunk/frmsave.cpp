/////////////////////////////////////////////////////////////////////////////////
// Author:      Steven Lamerton
// Copyright:   Copyright (C) 2006-2007 Steven Lamerton
// Licence:     GNU GPL 2 (See readme for more info
/////////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "frmsave.h"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "frmsave.h"
#include "toucan.h"
#include "basicops.h"

#include <wx/stdpaths.h>
#include <wx/fileconf.h>

////@begin XPM images
////@end XPM images

/*!
 * frmSave type definition
 */

IMPLEMENT_DYNAMIC_CLASS( frmSave, wxDialog )

/*!
 * frmSave event table definition
 */

BEGIN_EVENT_TABLE( frmSave, wxDialog )

////@begin frmSave event table entries
    EVT_BUTTON( wxID_SAVE, frmSave::OnSAVEClick )

    EVT_BUTTON( wxID_NEW, frmSave::OnNEWClick )

    EVT_BUTTON( wxID_CANCEL, frmSave::OnCANCELClick )

////@end frmSave event table entries

END_EVENT_TABLE()

/*!
 * frmSave constructors
 */

frmSave::frmSave()
{
}

frmSave::frmSave( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Create(parent, id, caption, pos, size, style);
}

/*!
 * frmSave creator
 */

bool frmSave::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
m_List = NULL;
////@begin frmSave creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end frmSave creation
SetIcon(GetIconResource(wxT("Toucan.ico")));
    return true;
}

/*!
 * frmSave destructor
 */

frmSave::~frmSave()
{
////@begin frmSave destruction
////@end frmSave destruction
}

/*!
 * Control creation for frmSave
 */

void frmSave::CreateControls()
{ 
	//Load language if one exists from toucan.h
	wxGetApp().SelectLanguage();
////@begin frmSave content construction
    frmSave* itemDialog1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemDialog1, wxID_STATIC, _("Please Select One"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxADJUST_MINSIZE, 5);

    wxArrayString m_ListStrings;
    m_List = new wxListBox( itemDialog1, ID_LISTBOX3, wxDefaultPosition, wxSize(250, 200), m_ListStrings, wxLB_SINGLE|wxLB_ALWAYS_SB );
    itemBoxSizer2->Add(m_List, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxButton* itemButton6 = new wxButton( itemDialog1, wxID_SAVE, _("&Save"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton7 = new wxButton( itemDialog1, wxID_NEW, _("&New"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton8 = new wxButton( itemDialog1, wxID_CANCEL, _("&Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer5->Add(itemButton8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end frmSave content construction
    
    wxFileConfig *config = new wxFileConfig( wxT(""), wxT(""), wxPathOnly(wxStandardPaths::Get().GetExecutablePath()).Left(wxPathOnly(wxStandardPaths::Get().GetExecutablePath()).Length() - 11) + wxT("\\Data\\Jobs.ini") );
    wxFileConfig::Set( config );
    
    wxString str;
    long dummy;
    bool bCont = config->GetFirstGroup(str, dummy);
    
    while ( bCont ) 
    {
        //wxMessageBox(config->Read(str +wxT("/Type"), wxEmptyString));
        //wxMessageBox(wxGetApp().GetStrTemp());
        if(config->Read(str +wxT("/Type"), wxEmptyString) == wxGetApp().GetStrTemp())
        {
            m_List->Append(str);
        }
    bCont = config->GetNextGroup(str, dummy);
    }
}

/*!
 * Should we show tooltips?
 */

bool frmSave::ShowToolTips()
{
    return true;
}

/*!
 * Get bitmap resources
 */

wxBitmap frmSave::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin frmSave bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end frmSave bitmap retrieval
}

/*!
 * Get icon resources
 */

wxIcon frmSave::GetIconResource( const wxString& name )
{
    wxUnusedVar(name);
	if (name == _T("Toucan.ico"))
	{
		wxIcon icon(_T("App\\toucan\\bitmaps\\Toucan.ico"), wxBITMAP_TYPE_ICO);
		return icon;
	}
	return wxNullIcon;
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_SAVE
 */

void frmSave::OnSAVEClick( wxCommandEvent& event )
{
    if(m_List->GetStringSelection() != wxEmptyString)
    {
        wxGetApp().SetStrTemp(m_List->GetStringSelection());
        EndModal(wxID_OK);
    }
    else
    {
        wxLogError(_("Please select one."));
    }
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_NEW
 */

void frmSave::OnNEWClick( wxCommandEvent& event )
{
    wxTextEntryDialog dialog(this, _("Please enter the name for your new job"), _("New") ,wxEmptyString, wxOK|wxCANCEL);
	if(dialog.ShowModal() == wxID_OK){
            m_List->Append(dialog.GetValue());	
            m_List->Select(m_List->GetCount() - 1);
	}
}

/*!
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void frmSave::OnCANCELClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in frmSave.
    // Before editing this code, remove the block markers.
    EndModal(wxID_CANCEL);
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in frmSave. 
}

