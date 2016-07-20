#include "MyWidget_ConfigurazionePCBuilder.h"
#include "MainWindow.h"

MyWidget_ConfigurazionePCBuilder::MyWidget_ConfigurazionePCBuilder(MainWindow* input_mw,QWidget* parent)
    :QWidget(parent),mw(input_mw){

}

MyWidget_ConfigurazionePCBuilder::~MyWidget_ConfigurazionePCBuilder(){
    delete mw;
    mw=0;
}
