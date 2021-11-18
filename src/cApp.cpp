//
// Created by Rukshan Perera on 2021-10-02.
//

#include "cApp.h"

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit() {

    if ( !wxApp::OnInit() )
        return false;

    m_frame = new cMain();
    m_frame->Show();

    return true;
}