#ifndef MYWIDGET_SPECIFICHECOMPONENTEPCBUILDER_H
#define MYWIDGET_SPECIFICHECOMPONENTEPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QLayout>

class MyWidget_SpecificheComponentePCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* PCBuilder_SpecificheComponenteLabel;

    QVBoxLayout* verticalLayout1;

    QPushButton* indietroPushButton;

    void createLabels();
    void createPushButtons();
public:
    MyWidget_SpecificheComponentePCBuilder(QWidget* =0);

    QPushButton* getIndietroPushButton() const;
    QVBoxLayout* getVerticalLayout1() const;

};

#endif // MYWIDGET_SPECIFICHECOMPONENTEPCBUILDER_H
