#include "MyWidget_LeMieConfigurazioniPCBuilder.h"

MyWidget_LeMieConfigurazioniPCBuilder::MyWidget_LeMieConfigurazioniPCBuilder(QWidget* parent)
    :QWidget(parent){
    createLabels();
    createPushButtons();

    viewSignalMapper=new QSignalMapper(this);
    editSignalMapper=new QSignalMapper(this);

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    gridLayout=new QGridLayout;

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_LeMieConfigurazioniLabel);

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(gridLayout);

    gridLayout->addWidget(nomeConfigurazioneLabel,0,0,1,1);
    connect(editSignalMapper,SIGNAL(mapped(const QString&)),this,SIGNAL(sendEditMessage(const QString&)));
    connect(viewSignalMapper,SIGNAL(mapped(const QString&)),this,SIGNAL(sendViewMessage(const QString&)));
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

QGridLayout* MyWidget_LeMieConfigurazioniPCBuilder::getGridLayout() const{
    return gridLayout;
}

QSignalMapper* MyWidget_LeMieConfigurazioniPCBuilder::getViewSignalMapper() const{
    return viewSignalMapper;
}

QSignalMapper* MyWidget_LeMieConfigurazioniPCBuilder::getEditSignalMapper() const{
    return editSignalMapper;
}
