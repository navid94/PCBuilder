#ifndef MYWIDGET_CONFIGURAZIONEPCBUILDER_H
#define MYWIDGET_CONFIGURAZIONEPCBUILDER_H

#include <QWidget>

class MainWindow;

class MyWidget_ConfigurazionePCBuilder:public QWidget{
    Q_OBJECT
private:
    MainWindow* mw;
public:
    MyWidget_ConfigurazionePCBuilder(MainWindow*,QWidget* =0);
    ~MyWidget_ConfigurazionePCBuilder();
};


#endif // MYWIDGET_CONFIGURAZIONEPCBUILDER_H
