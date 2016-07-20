#include "PCBuilderGUI.h"

PCBuilderGUI::PCBuilderGUI(){
    controller=new PCBuilderController;
    controller->get_MainWindow()->show();
}

PCBuilderGUI::~PCBuilderGUI(){
    delete controller;
    controller=0;
    delete mw;
    mw=0;
    delete u;
    u=0;
}
