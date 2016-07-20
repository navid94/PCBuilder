#include "MyWidget_SpecificheComponentePCBuilder.h"
#include "MainWindow.h"
#include "PCBuilderController.h"
#include "DBComponenti.h"

#include <QLayout>
#include <QMap>
#include <QFile>
#include <QVector>
#include <QDomNode>

MyWidget_SpecificheComponentePCBuilder::MyWidget_SpecificheComponentePCBuilder(MainWindow* input_mw,const QString& input_componente,QWidget* parent)
    :QWidget(parent),mw(input_mw),componente(input_componente){
    createLabels();
    createPushButtons();

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);
    horizontalLayout1->setContentsMargins(0,50,0,0);
    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_SpecificheComponenteLabel);

    QFont font_form;
    font_form.setPointSize(14);

    QMap<QString,QString> specs=mw->get_Controller()->getComponentSpecs(componente);
    QVector<QLabel*> nomeAttributoLabels;
    QVector<QLabel*> valoreAttributoLabels;
    int n=0;
    for (QMap<QString,QString>::const_iterator it=specs.begin();it!=specs.end();it++)
    {
        nomeAttributoLabels.append(new QLabel(it.key()));
        nomeAttributoLabels[n]->setFont(font_form);
        nomeAttributoLabels[n]->setMaximumHeight(30);
        nomeAttributoLabels[n]->setMinimumSize(QSize(0,0));
        gridLayout->addWidget(nomeAttributoLabels[n],n,0,1,1);
        valoreAttributoLabels.append(new QLabel(it.value()));
        valoreAttributoLabels[n]->setFont(font_form);
        valoreAttributoLabels[n]->setMaximumHeight(30);
        valoreAttributoLabels[n]->setMinimumSize(QSize(0,0));
        gridLayout->addWidget(valoreAttributoLabels[n],n,1,1,1);
        n++;
    }

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(gridLayout);

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
