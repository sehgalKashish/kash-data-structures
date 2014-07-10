/***************************************************************
 * Name:      mousewxApp.h
 * Purpose:   Defines Application Class
 * Author:    thomas ()
 * Created:   2011-05-26
 * Copyright: thomas (codebase.eu)
 * License:
 **************************************************************/

#ifndef MOUSEWXAPP_H
#define MOUSEWXAPP_H

#include <wx/app.h>



class mousewxApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // MOUSEWXAPP_H
