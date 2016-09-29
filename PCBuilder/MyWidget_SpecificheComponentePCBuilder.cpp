#include "MyWidget_SpecificheComponentePCBuilder.h"
#include "MainWindow.h"
#include "PCBuilderController.h"
#include "DBComponenti.h"

#include <QMap>
#include <QFile>
#include <QVector>
#include <QDomNode>

MyWidget_SpecificheComponentePCBuilder::MyWidget_SpecificheComponentePCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createPushButtons();

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    verticalLayout1=new QVBoxLayout;
    horizontalLayout1->setContentsMargins(0,50,0,0);
    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_SpecificheComponenteLabel);

    verticalLayout1->addLayout(horizontalLayout1);

    setLayout(verticalLayout1);
}

void MyWidget_SpecificheComponentePCBuilder::createLabels(){
    PCBuilder_SpecificheComponenteLabel=new QLabel("PCBuilder - "+(tr("Specifiche componenti")));
    QFont font_PCBuilder_SpecificheComponenteLabel=PCBuilder_SpecificheComponenteLabel->font();
    font_PCBuilder_SpecificheComponenteLabel.setPixelSize(24);
    PCBuilder_SpecificheComponenteLabel->setFont(font_PCBuilder_SpecificheComponenteLabel);
    PCBuilder_SpecificheComponenteLabel->setMaximumSize(QSize(570,50));
    PCBuilder_SpecificheComponenteLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_SpecificheComponentePCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));
}

QPushButton* MyWidget_SpecificheComponentePCBuilder::getIndietroPushButton() const{
    return indietroPushButton;
}

QVBoxLayout* MyWidget_SpecificheComponentePCBuilder::getVerticalLayout1() const{
    return verticalLayout1;
}
