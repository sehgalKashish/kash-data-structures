/***************************************************************
 * Name:      mousewxApp.cpp
 * Purpose:   Code for Application Class
 * Author:    thomas ()
 * Created:   2011-05-26
 * Copyright: thomas (codebase.eu)
 * License:
 **************************************************************/

#include "mousewxApp.h"

//(*AppHeaders
#include "mousewxMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(mousewxApp);

mousewxFrame* Frame2 ;

bool mousewxApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	mousewxFrame* Frame = new mousewxFrame(0);
    	Frame2 = Frame ;

    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
