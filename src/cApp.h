//
// Created by Rukshan Perera on 2021-10-02.
//

#ifndef WATCHNEXT_CAPP_H
#define WATCHNEXT_CAPP_H

#include "wx/wx.h"
#include "cMain.h"

#include <wx/defs.h>     // for wxOVERRIDE
#include <wx/osx/app.h>  // for wxApp
class cMain;

class cApp : public wxApp {

        private:
        cMain * m_frame = nullptr;

        public:
        bool OnInit() wxOVERRIDE;
};


#endif //WATCHNEXT_CAPP_H
