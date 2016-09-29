#include "MyWidget_GestisciComponentiPCBuilder.h"


#include <QFont>

MyWidget_GestisciComponentiPCBuilder::MyWidget_GestisciComponentiPCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createPushButtons();
    createLineEdits();
    createComboBoxes();

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout4=new QHBoxLayout;
    QHBoxLayout* horizontalLayout5=new QHBoxLayout;
    QHBoxLayout* horizontalLayout7=new QHBoxLayout;
    QHBoxLayout* horizontalLayout9=new QHBoxLayout;

    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QVBoxLayout* verticalLayout3=new QVBoxLayout;
    QVBoxLayout* verticalLayout5=new QVBoxLayout;
    QVBoxLayout* verticalLayout6=new QVBoxLayout;

    horizontalLayout3=new QHBoxLayout;

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_Gestione_componentiLabel);

    horizontalLayout2->setContentsMargins(0,20,0,10);
    horizontalLayout2->addWidget(rimuovi_componenteLabel);
    horizontalLayout2->addWidget(rimuoviComponenteLineEdit);
    horizontalLayout2->addWidget(rimuoviPushButton);

    horizontalLayout4->addWidget(aggiungiPushButton);

    horizontalLayout5->setContentsMargins(0,0,0,25);
    horizontalLayout5->addWidget(tipo_componenteAggiungi);

    horizontalLayout7->setContentsMargins(0,25,0,0);
    horizontalLayout7->addWidget(aggiungi_componenteLabel);


    verticalLayout1->addLayout(horizontalLayout7);
    verticalLayout1->addLayout(horizontalLayout5);



    verticalLayout3->addLayout(verticalLayout1);
    verticalLayout3->addLayout(verticalLayout6);
    verticalLayout3->addLayout(horizontalLayout3);
    verticalLayout3->addLayout(horizontalLayout4);

    horizontalLayout9->addLayout(verticalLayout3);

    verticalLayout5->addLayout(horizontalLayout1);
    verticalLayout5->addLayout(horizontalLayout9);
    verticalLayout5->addLayout(horizontalLayout2);

    setLayout(verticalLayout5);
}

void MyWidget_GestisciComponentiPCBuilder::createLabels(){

    PCBuilder_Gestione_componentiLabel=new QLabel("PCBuilder - "+(tr("Gestione componenti")));
    QFont font_PCBuilder_Gestione_componentiLabel=PCBuilder_Gestione_componentiLabel->font();
    font_PCBuilder_Gestione_componentiLabel.setPointSize(24);
    PCBuilder_Gestione_componentiLabel->setFont(font_PCBuilder_Gestione_componentiLabel);
    PCBuilder_Gestione_componentiLabel->setMaximumSize(QSize(550,50));
    PCBuilder_Gestione_componentiLabel->setMinimumSize(QSize(0,0));

    aggiungi_componenteLabel=new QLabel(tr("Aggiungi componente"));
    QFont font_aggiungi_componenteLabel=aggiungi_componenteLabel->font();
    font_aggiungi_componenteLabel.setPointSize(18);
    aggiungi_componenteLabel->setFont(font_aggiungi_componenteLabel);
    aggiungi_componenteLabel->setMaximumSize(QSize(270,30));
    aggiungi_componenteLabel->setMinimumSize(QSize(0,0));

    rimuovi_componenteLabel=new QLabel(tr("Rimuovi componente"));
    QFont font_rimuovi_componenteLabel=rimuovi_componenteLabel->font();
    font_rimuovi_componenteLabel.setPixelSize(18);
    rimuovi_componenteLabel->setFont(font_rimuovi_componenteLabel);
    rimuovi_componenteLabel->setMaximumSize(QSize(270,30));
    rimuovi_componenteLabel->setMinimumSize(QSize(0,0));    
}

void MyWidget_GestisciComponentiPCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));

    aggiungiPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiPushButton->setMaximumSize(QSize(160,60));
    aggiungiPushButton->setMinimumSize(QSize(0,0));

    rimuoviPushButton=new QPushButton(tr("Rimuovi"));
    rimuoviPushButton->setMaximumSize(160,60);
    rimuoviPushButton->setMinimumSize(QSize(0,0));
}

void MyWidget_GestisciComponentiPCBuilder::createComboBoxes(){
    tipo_componenteAggiungi=new QComboBox;
    tipo_componenteAggiungi->setMaximumSize(QSize(250,25));
    tipo_componenteAggiungi->setMinimumSize(QSize(0,0));
    tipo_componenteAggiungi->addItem(tr("Seleziona il componente"));
    tipo_componenteAggiungi->addItem(tr("Memoria"));
    tipo_componenteAggiungi->addItem(tr("Scheda grafica"));
    tipo_componenteAggiungi->addItem(tr("Scheda madre"));
    tipo_componenteAggiungi->addItem(tr("Processore"));
    tipo_componenteAggiungi->addItem(tr("Archiviazione"));
    tipo_componenteAggiungi->addItem(tr("Alimentatore"));
    tipo_componenteAggiungi->addItem(tr("Dissipatore processore"));
    tipo_componenteAggiungi->addItem(tr("Case"));
    tipo_componenteAggiungi->addItem(tr("Unità ottica"));
    tipo_componenteAggiungi->addItem(tr("Monitor"));
    tipo_componenteAggiungi->addItem(tr("Sistema operativo"));
    tipo_componenteAggiungi->addItem(tr("Mouse"));
    tipo_componenteAggiungi->addItem(tr("Tastiera"));
    tipo_componenteAggiungi->addItem(tr("Cuffie"));
    tipo_componenteAggiungi->addItem(tr("Altoparlanti"));
}

void MyWidget_GestisciComponentiPCBuilder::createLineEdits(){    

    rimuoviComponenteLineEdit=new QLineEdit;
    rimuoviComponenteLineEdit->setPlaceholderText(tr("Inserire nome componente da rimuovere"));
    rimuoviComponenteLineEdit->setMaximumSize(QSize(200,30));
    rimuoviComponenteLineEdit->setMinimumSize(QSize(0,0));
}

QHBoxLayout* MyWidget_GestisciComponentiPCBuilder::getHorizontalLayout3() const{
    return horizontalLayout3;
}

QPushButton* MyWidget_GestisciComponentiPCBuilder::get_indietroPushButton() const{
    return indietroPushButton;
}

QPushButton* MyWidget_GestisciComponentiPCBuilder::get_aggiungi_PushButton() const{
    return aggiungiPushButton;
}

QPushButton* MyWidget_GestisciComponentiPCBuilder::get_rimuoviPushButton() const{
    return rimuoviPushButton;
}

QString MyWidget_GestisciComponentiPCBuilder::tipo_componenteAggiungiValue() const{
    return tipo_componenteAggiungi->currentText();
}

QString MyWidget_GestisciComponentiPCBuilder::rimuoviComponenteValue() const{
    return rimuoviComponenteLineEdit->text();
}

QLineEdit* MyWidget_GestisciComponentiPCBuilder::getRimuoviComponenteLineEdit() const{
    return rimuoviComponenteLineEdit;
}

QComboBox* MyWidget_GestisciComponentiPCBuilder::getTipo_componenteAggiungi() const{
    return tipo_componenteAggiungi;
}
