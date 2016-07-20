#include "MyWidget_LeMieConfigurazioniPCBuilder.h"
#include "MainWindow.h"
#include "PCBuilderController.h"
#include "Utente.h"
#include "Configurazione.h"

#include <QLayout>
#include <QVector>

MyWidget_LeMieConfigurazioniPCBuilder::MyWidget_LeMieConfigurazioniPCBuilder(MainWindow* input_mw, QWidget* parent)
    :QWidget(parent),mw(input_mw){
    createLabels();
    createPushButtons();

    signalMapper=new QSignalMapper(this);

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QGridLayout* gridLayout=new QGridLayout;

    QVector<QPushButton*> modificaPushButtons;
    QVector<QLabel*> nomeConfigurazioneLabels;

    QVector<Configurazione*>* v=mw->get_Controller()->getUser()->getConfigurazioni();

    QFont font_form;
    font_form.setPointSize(14);

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_LeMieConfigurazioniLabel);

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(gridLayout);

    gridLayout->addWidget(nomeConfigurazioneLabel,0,0,1,1);
    for (int i=0;i<v->size();i++)
    {
        QString nomeConfigurazione=v->at(i)->getNome();
        nomeConfigurazioneLabels.append(new QLabel(nomeConfigurazione));
        nomeConfigurazioneLabels[i]->setFont(font_form);
        nomeConfigurazioneLabels[i]->setMaximumHeight(30);
        nomeConfigurazioneLabels[i]->setMinimumSize(QSize(0,0));
        gridLayout->addWidget(nomeConfigurazioneLabels[i],i+1,0,1,1);

        modificaPushButtons.append(new QPushButton(tr("Modifica")));
        modificaPushButtons[i]->setMaximumSize(QSize(150,30));
        modificaPushButtons[i]->setMinimumSize(QSize(0,0));
        connect(modificaPushButtons[i],SIGNAL(clicked()),signalMapper,SLOT(map()));
        signalMapper->setMapping(modificaPushButtons[i],nomeConfigurazione);
        gridLayout->addWidget(modificaPushButtons[i],i+1,1,1,1);
    }
    connect(signalMapper,SIGNAL(mapped(const QString&)),this,SIGNAL(sendMessage(const QString&)));
    setLayout(verticalLayout1);
}

void MyWidget_LeMieConfigurazioniPCBuilder::createLabels(){

    PCBuilder_LeMieConfigurazioniLabel=new QLabel("PCBuilder - "+tr("Le mie configurazioni"));
    QFont font_PCBuilder_LeMieConfigurazioniLabel=PCBuilder_LeMieConfigurazioniLabel->font();
    font_PCBuilder_LeMieConfigurazioniLabel.setPointSize(24);
    PCBuilder_LeMieConfigurazioniLabel->setFont(font_PCBuilder_LeMieConfigurazioniLabel);
    PCBuilder_LeMieConfigurazioniLabel->setMaximumSize(QSize(530,50));
    PCBuilder_LeMieConfigurazioniLabel->setMinimumSize(QSize(0,0));

    nomeConfigurazioneLabel=new QLabel(tr("Nome configurazione"));
    QFont font_nomeConfigurazioneLabel=nomeConfigurazioneLabel->font();
    font_nomeConfigurazioneLabel.setPointSize(18);
    nomeConfigurazioneLabel->setFont(font_nomeConfigurazioneLabel);
    nomeConfigurazioneLabel->setMaximumSize(QSize(260,30));
    nomeConfigurazioneLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_LeMieConfigurazioniPCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));
}

QPushButton* MyWidget_LeMieConfigurazioniPCBuilder::getIndietroPushButton() const{
    return indietroPushButton;
}
