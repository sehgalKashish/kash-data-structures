/***************************************************************
 * Name:      mousewxMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    thomas ()
 * Created:   2011-05-26
 * Copyright: thomas (codebase.eu)
 * License:
 **************************************************************/


#include <iostream>
#include <fstream>
#include <pthread.h>
#include "mousewxMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(mousewxFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)


extern  mousewxFrame * Frame2;
void communicate() ;
int t_lb=0,t_rb,t_mb;
bool autoup = false ;
void * function1(void * argument);


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(mousewxFrame)
const long mousewxFrame::ID_BUTTON1 = wxNewId();
const long mousewxFrame::ID_STATICTEXT1 = wxNewId();
const long mousewxFrame::ID_BUTTON2 = wxNewId();
const long mousewxFrame::ID_BUTTON3 = wxNewId();
const long mousewxFrame::ID_BUTTON4 = wxNewId();
const long mousewxFrame::ID_BUTTON5 = wxNewId();
const long mousewxFrame::ID_STATICTEXT2 = wxNewId();
const long mousewxFrame::ID_STATICTEXT3 = wxNewId();
const long mousewxFrame::ID_STATICTEXT4 = wxNewId();
const long mousewxFrame::ID_STATICTEXT5 = wxNewId();
const long mousewxFrame::ID_STATICTEXT6 = wxNewId();
const long mousewxFrame::ID_TEXTCTRL1 = wxNewId();
const long mousewxFrame::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mousewxFrame,wxFrame)
    //(*EventTable(mousewxFrame)
    //*)
END_EVENT_TABLE()

mousewxFrame::mousewxFrame(wxWindow * parent,wxWindowID id)
{
    //(*Initialize(mousewxFrame)
    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(418,407));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(136,216), wxSize(418,304), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Start thread"), wxPoint(128,8), wxSize(160,29), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("-"), wxPoint(152,56), wxSize(88,17), 0, _T("ID_STATICTEXT1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Show leftclicks in a messagebox"), wxPoint(8,136), wxSize(400,29), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button2->Disable();
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Show right clicks in the label"), wxPoint(8,168), wxSize(400,29), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Button3->Disable();
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Show middle clicks in label"), wxPoint(8,200), wxSize(400,29), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    Button4->Disable();
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("Update left clicks automatically using an event"), wxPoint(8,232), wxSize(400,32), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    Button5->Disable();
    lblleftclick = new wxStaticText(Panel1, ID_STATICTEXT2, _("Left clicks "), wxPoint(56,56), wxSize(88,17), 0, _T("ID_STATICTEXT2"));
    lblmidbtn = new wxStaticText(Panel1, ID_STATICTEXT3, _("MIddle btn "), wxPoint(56,80), wxSize(88,17), 0, _T("ID_STATICTEXT3"));
    mid_clicks = new wxStaticText(Panel1, ID_STATICTEXT4, _("-"), wxPoint(152,80), wxSize(88,17), 0, _T("ID_STATICTEXT4"));
    lblrightclick = new wxStaticText(Panel1, ID_STATICTEXT5, _("Right clicks"), wxPoint(56,104), wxSize(80,17), 0, _T("ID_STATICTEXT5"));
    right_clicks = new wxStaticText(Panel1, ID_STATICTEXT6, _("-"), wxPoint(152,104), wxSize(88,17), 0, _T("ID_STATICTEXT6"));
    explain = new wxTextCtrl(Panel1, ID_TEXTCTRL1, wxEmptyString, wxPoint(8,272), wxSize(400,120), wxTE_AUTO_SCROLL|wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL1"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mousewxFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mousewxFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mousewxFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mousewxFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mousewxFrame::OnButton5Click);
//    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&mousewxFrame::OnPanel1Paint,0,this);
    //*)
}

mousewxFrame::~mousewxFrame()
{
    //(*Destroy(mousewxFrame)
    //*)
}

void mousewxFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void mousewxFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void mousewxFrame::OnButton1Click(wxCommandEvent& event)
{
   pthread_t t1;
   pthread_create( &t1, NULL, function1,NULL);

   Button2->Enable( true );
   Button3->Enable( true );
   Button4->Enable( true );
   Button5->Enable( true );

}

void communicate()
{

 Frame2->showit();

}



void * function1(void * argument)
{

  int lb=0,mb=0,rb=0;
  bool lb_up = false, rb_up= false,mb_up=false;

  char b[3];

 std::ifstream invoer("/dev/input/mice",std::ios::binary|std::ios::in);

 if (invoer.is_open())
    {
        //std::cout <<"success.";
    }
    else
    {

         std::cout << "Error opening device file. Are you root?"<< std::endl;
         pthread_exit(NULL) ;

    }

  while(1)
    {


        invoer.read(b,sizeof(b));

        // showing the output in terminal
        //std::cout  <<" lb="<< lb <<  " rb=" << rb << " mb=" << mb <<  std::endl;

        lb=(b[0]&1)>0;
        rb=(b[0]&2)>0;
        mb=(b[0]&4)>0;


      if (lb ==1)
        {
            lb_up = true ;
        }
        if (lb_up == true && lb == 0)
        {
            t_lb++;
            if (autoup) Frame2->setsome() ;
            lb_up = false;
        }


         if (rb ==1)
        {
            rb_up = true ;
        }
        if (rb_up == true && rb == 0)
        {
            t_rb++;

            rb_up = false;
        }

        if (mb ==1)
        {
            mb_up = true ;
        }
        if (mb_up == true && mb == 0)
        {
            t_mb++;

            mb_up = false;
        }


    }
    pthread_exit(NULL) ;

}


void mousewxFrame::OnButton2Click(wxCommandEvent& event)
{


   autoup=false;
   wxString expl =wxString(_("This is the simplest method. It just reads global variable ")) +
   wxString(_("t_lb and displays it in a message box. WxMessageBox can be called "))+
   wxString(_("from anywhere in your main thread, but calling it from an other thread (like the thread we started) results in errors."));

   explain->SetValue(expl);


    wxString Foobar;
    Foobar.Printf( wxT("Number of clicks : %d"), t_lb);
    wxMessageBox(Foobar);

}



void mousewxFrame::OnButton3Click(wxCommandEvent& event)
{
   autoup=false;
   wxString expl =wxString(_("This is the standard method. It just puts global ")) +
   wxString(_("var t_rb in the label using SetLabel. It can be called only from inside "))+
   wxString(_("a member of the class."));

   explain->SetValue(expl);


      wxString Foobar;
        Foobar.Printf( wxT("%d"), t_rb);
        right_clicks->SetLabel(Foobar);

}

void mousewxFrame::OnButton4Click(wxCommandEvent& event)
{

autoup=false;

wxString expl =wxString(_("This method uses a pointer to the Frame object for direct ")) +
   wxString(_("access to the GUI from outside a member of the class. It can be called from anywhere in the code, but "))+
   wxString(_("calling it from the thread will result in error sooner or later, because it's NOT thread safe."));
   explain->SetValue(expl);
    communicate();
}



void mousewxFrame::OnButton5Click(wxCommandEvent& event)
{
    // automatically call a event
    if (autoup==false)
    {
        wxString expl =wxString(_("This method calls for an event to happen. ")) +
   wxString(_("In this case the event is the click of this button. "))+
   wxString(_("This is the method you should use when working with threads. "))+
   wxString(_("Click anywhere (except on the buttons above) to see it in action. "));
   explain->SetValue(expl);
   autoup = true ;
    }


    wxString Foobar;
    Foobar.Printf( wxT("%d"), t_lb);
    StaticText1->SetLabel(Foobar);


}
