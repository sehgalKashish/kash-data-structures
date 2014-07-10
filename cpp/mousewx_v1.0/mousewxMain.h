/***************************************************************
 * Name:      mousewxMain.h
 * Purpose:   Defines Application Frame
 * Author:    thomas ()
 * Created:   2011-05-26
 * Copyright: thomas (codebase.eu)
 * License:
 **************************************************************/

#ifndef MOUSEWXMAIN_H
#define MOUSEWXMAIN_H

//(*Headers(mousewxFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

extern int t_mb;

class mousewxFrame: public wxFrame
{
    public:

        mousewxFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~mousewxFrame();

        void showit()
        {

         wxString Foobar;
        Foobar.Printf( wxT("%d"), t_mb);
        mid_clicks->SetLabel(Foobar);
        };

       void setsome()
        {

        wxCommandEvent MyEvent( wxEVT_COMMAND_BUTTON_CLICKED ); // Keep it simple, don't give a specific event ID

        MyEvent.SetId(ID_BUTTON5);

        wxPostEvent(Button5, MyEvent); // This posts to ourselves: it'll be caught and sent to a different method

        };



    private:

        //(*Handlers(mousewxFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(mousewxFrame)
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_TEXTCTRL1;
        static const long ID_PANEL1;
        //*)

        //(*Declarations(mousewxFrame)
        wxButton* Button4;
        wxStaticText* right_clicks;
        wxButton* Button1;
        wxStaticText* lblmidbtn;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* lblrightclick;
        wxButton* Button2;
        wxButton* Button5;
        wxButton* Button3;
        wxTextCtrl* explain;
        wxStaticText* lblleftclick;
        wxStaticText* mid_clicks;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // MOUSEWXMAIN_H
