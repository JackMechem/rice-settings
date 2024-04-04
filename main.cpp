#include <cstdlib>
#include <string>
#include <wx/button.h>
#include <wx/event.h>
#include <wx/font.h>
#include <wx/gdicmn.h>
#include <wx/sizer.h>
#include <wx/string.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "main.h"

// {{{ MyApp Class

// serves as the main function
wxIMPLEMENT_APP(MyApp);

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame) EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout)
        EVT_BUTTON(ID_Run, MainFrame::OnRun) wxEND_EVENT_TABLE();

bool MyApp::OnInit() {
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    MainFrame *frame = new MainFrame();

    ScrolledEntrySection *scrolledPane =
        new ScrolledEntrySection(frame, wxID_ANY);
    sizer->Add(scrolledPane, 1, wxEXPAND);
    frame->SetSizer(sizer);

    frame->Show(true);
    return true;
}

// }}}

ScrolledEntrySection::ScrolledEntrySection(wxFrame *parent, wxWindowID id)
    : wxScrolledWindow(parent, id) {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    // A Dropdown menu for Help
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");

    parent->SetMenuBar(menuBar);

    parent->CreateStatusBar();
    parent->SetStatusText("Rice Settings Version: " + version);

    std::vector<entry> parsedEntries = config.getParsedEntries();

    wxFont categoryFont;
    categoryFont.SetPointSize(titleFontSize);
    categoryFont.SetWeight(titleFontWeight);
    categoryFont.SetFamily(fontFamily);

    wxFont nameFont;
    nameFont.SetPointSize(bodyFontSize);
    nameFont.SetWeight(bodyFontWeight);
    nameFont.SetFamily(fontFamily);

    wxBoxSizer *mainSizer = new wxBoxSizer(wxVERTICAL);

    for (int i = 0; i < parsedEntries.size(); i++) {
        entry ent = parsedEntries[i];
        if (ent.command.size() > 0) { // For commands

            wxBoxSizer *entrySizer = new wxBoxSizer(wxHORIZONTAL);

            wxStaticText *text = new wxStaticText(this, 0, ent.name);
            text->SetFont(nameFont);

            wxButton *btn = new wxButton(this, FIRST_BUTTON_ID + i, "Execute");
            btn->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                         wxCommandEventHandler(MainFrame::OnRun));
            btn->SetFont(nameFont);

            entrySizer->AddSpacer(entryPaddingX);
            entrySizer->Add(text, wxALIGN_CENTER_VERTICAL, 0);
            entrySizer->AddStretchSpacer(1);
            entrySizer->Add(btn, 0);
            entrySizer->AddSpacer(entryPaddingX);

            mainSizer->Add(entrySizer, 0, wxALL | wxEXPAND, 2);
            mainSizer->AddSpacer(entryPaddingY);
        } else { // For titles
            wxBoxSizer *titleSizer = new wxBoxSizer(wxHORIZONTAL);

            wxStaticText *text = new wxStaticText(this, 0, ent.name);
            text->SetFont(categoryFont);

            titleSizer->AddSpacer(titlePaddingX);
            titleSizer->Add(text, 0);

            mainSizer->AddSpacer(titlePaddingY);
            mainSizer->Add(titleSizer, 0);
            mainSizer->AddSpacer(titlePaddingY);
        }
    }

    SetSizer(mainSizer);

    this->FitInside();
    this->SetScrollRate(5, 5);
}

// {{{ MyFrame Class

MainFrame::MainFrame()
    : wxFrame(NULL, -1, "Rice Settings", wxPoint(50, 50), wxSize(400, 650)) {

    // this->Bind(wxEVT_CHAR_HOOK, &MainFrame::OnKeyDown, this);
}

void MainFrame::OnExit(wxCommandEvent &event) { Close(true); }

void MainFrame::OnAbout(wxCommandEvent &event) {
    wxMessageBox("Created By: Jack Mechem\nThis is a side project I created "
                 "because I want to learn c++ :)",
                 "About rice-settings", wxOK | wxICON_INFORMATION);
}

void MainFrame::OnRun(wxCommandEvent &event) {
    int id = event.GetId();

    // If is an entry button
    if (id >= 10000 && id <= 19999) {
        int idIndex = id - FIRST_BUTTON_ID;

        ConfigFile config;
        std::vector<entry> parsedEntries = config.getParsedEntries();
        ConfigFile::dialog commandDialog = config.getCommandDialog();
        bool closeApplication = config.getCloseApplication();

        if (commandDialog.commandDialog) {

            if (commandDialog.dialogConfirm) {

                int messageReturn = wxMessageBox(
                    "Are you sure you want to execute this program?\n\n" +
                        parsedEntries[idIndex].command + "\n",
                    "Confirm", wxYES_NO | wxICON_QUESTION);

                if (messageReturn == wxYES) {
                    wxExecute(parsedEntries[idIndex].command.c_str());
                    if (closeApplication) {
                        wxGetApp().ExitMainLoop();
                    }
                }

            } else {
                wxLogMessage(wxString("Executed Command: " +
                                      parsedEntries[idIndex].command));
                wxExecute(parsedEntries[idIndex].command.c_str());
                if (closeApplication) {
                    wxGetApp().ExitMainLoop();
                }
            }
        } else {
            wxExecute(parsedEntries[idIndex].command.c_str());
            if (closeApplication) {
                wxGetApp().ExitMainLoop();
            }
        }
    }
    event.Skip();
}

// }}}
