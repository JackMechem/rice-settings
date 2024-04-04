#include <wx/event.h>
#include <wx/font.h>
#include <wx/rtti.h>
#include <wx/scrolwin.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "configFile.h"

class MyApp : public wxApp {
  public:
    virtual bool OnInit();
};

class MainFrame : public wxFrame {
  public:
    MainFrame();
    void OnRun(wxCommandEvent &event);

  private:
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();
};

class ScrolledEntrySection : public wxScrolledWindow {
  public:
    ScrolledEntrySection(wxFrame *parent, wxWindowID id);

    std::string version = "1.0";

  private:
    // Padding
    int titlePaddingX{15}, titlePaddingY{20};
    int entryPaddingX{30}, entryPaddingY{5};

    // Fonts
    wxFontFamily fontFamily = wxFONTFAMILY_MAX;

    int titleFontSize = 12;
    wxFontWeight titleFontWeight = wxFONTWEIGHT_SEMIBOLD;

    int bodyFontSize = 12;
    wxFontWeight bodyFontWeight = wxFONTWEIGHT_MEDIUM;

    // Config
    ConfigFile config;
};

// Event Ids
enum { ID_Hello = 1 };
enum { ID_Run };
enum { ID_Focus };
enum { FIRST_BUTTON_ID = 10000 };
