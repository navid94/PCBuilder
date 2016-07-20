#ifndef MYWIDGET_SPECIFICHECOMPONENTEPCBUILDER_H
#define MYWIDGET_SPECIFICHECOMPONENTEPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>

class MainWindow;

class MyWidget_SpecificheComponentePCBuilder:public QWidget{
    Q_OBJECT
private:
    MainWindow* mw;
    QString componente;
    QLabel* PCBuilder_SpecificheComponenteLabel;



    QPushButton* indietroPushButton;

    void createLabels();
    void createPushButtons();
public:
    MyWidget_SpecificheComponentePCBuilder(MainWindow*,const QString&,QWidget* =0);

    QPushButton* getIndietroPushButton() const;

};

#endif // MYWIDGET_SPECIFICHECOMPONENTEPCBUILDER_H
