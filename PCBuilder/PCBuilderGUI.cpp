#include "PCBuilderGUI.h"
#include "UtenteNonRegistrato.h"

PCBuilderGUI::PCBuilderGUI(){
    controller=new PCBuilderController;
    controller->get_MainWindow()->show();
}

PCBuilderGUI::~PCBuilderGUI(){
    delete controller;
    controller=0;
}
