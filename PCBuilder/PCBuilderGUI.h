#ifndef PCBUILDERGUI_H
#define PCBUILDERGUI_H

#include "PCBuilderController.h"
#include "MainWindow.h"
#include "DBUtenti.h"
#include "Utente.h"

class PCBuilderGUI{
private:
    PCBuilderController* controller;
    MainWindow* mw;
    Utente* u;
public:
    PCBuilderGUI();
    ~PCBuilderGUI();
};

#endif // PCBUILDERGUI_H
