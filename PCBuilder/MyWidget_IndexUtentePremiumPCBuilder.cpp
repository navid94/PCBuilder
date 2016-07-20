#include "MyWidget_IndexUtentePremiumPCBuilder.h"
#include <QLayout>

MyWidget_IndexUtentePremiumPCBuilder::MyWidget_IndexUtentePremiumPCBuilder(QWidget* parent):QWidget(parent){
    createPushButtons();
    createLabels();

    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QVBoxLayout* verticalLayout2=new QVBoxLayout;
    QVBoxLayout* verticalLayout3=new QVBoxLayout;

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout3=new QHBoxLayout;
    QHBoxLayout* horizontalLayout4=new QHBoxLayout;
    QHBoxLayout* horizontalLayout5=new QHBoxLayout;
    QHBoxLayout* horizontalLayout6=new QHBoxLayout;

    horizontalLayout6->addWidget(PCBuilder_IndexUtentePremiumLabel);

    horizontalLayout1->addWidget(creaconfPushButton);
    horizontalLayout1->addWidget(cercapartiPushButton);

    verticalLayout2->addLayout(horizontalLayout2);
    horizontalLayout2->addWidget(mostraconfsalvatePushButton);

    verticalLayout3->addLayout(horizontalLayout3);
    verticalLayout3->addLayout(horizontalLayout4);

    horizontalLayout3->addWidget(modificaprofiloPushButton);
    horizontalLayout4->addWidget(esciPushButton);
    horizontalLayout4->setContentsMargins(0,30,0,0);

    horizontalLayout5->addLayout(verticalLayout2);
    horizontalLayout5->addLayout(verticalLayout3);

    verticalLayout1->addLayout(horizontalLayout6);
    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(horizontalLayout5);

    setLayout(verticalLayout1);
}

void MyWidget_IndexUtentePremiumPCBuilder::createLabels(){
    PCBuilder_IndexUtentePremiumLabel=new QLabel("PCBuilder - "+tr("Index utente premium"));
    QFont font_PCBuilder_IndexUtentePremiumLabel=PCBuilder_IndexUtentePremiumLabel->font();
    font_PCBuilder_IndexUtentePremiumLabel.setPointSize(24);
    PCBuilder_IndexUtentePremiumLabel->setFont(font_PCBuilder_IndexUtentePremiumLabel);
    PCBuilder_IndexUtentePremiumLabel->setMaximumSize(QSize(570,50));
    PCBuilder_IndexUtentePremiumLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_IndexUtentePremiumPCBuilder::createPushButtons(){
    creaconfPushButton=new QPushButton(tr("Crea una configurazione"));
    creaconfPushButton->setMaximumSize(QSize(200,70));
    creaconfPushButton->setMinimumSize(QSize(0,0));

    cercapartiPushButton=new QPushButton(tr("Cerca tra le parti"));
    cercapartiPushButton->setMaximumSize(QSize(200,70));
    cercapartiPushButton->setMinimumSize(QSize(0,0));

    mostraconfsalvatePushButton=new QPushButton(tr("Mostra configurazioni salvate"));
    mostraconfsalvatePushButton->setMaximumSize(QSize(200,70));
    mostraconfsalvatePushButton->setMinimumSize(QSize(0,0));

    modificaprofiloPushButton=new QPushButton(tr("Modifica profilo"));
    modificaprofiloPushButton->setMaximumSize(QSize(170,50));
    modificaprofiloPushButton->setMinimumSize(QSize(0,0));

    esciPushButton=new QPushButton(tr("Esci"));
    esciPushButton->setMaximumSize(QSize(170,50));
    esciPushButton->setMinimumSize(QSize(0,0));
}

QPushButton* MyWidget_IndexUtentePremiumPCBuilder::getCreaconfPushButton() const{
    return creaconfPushButton;
}

QPushButton* MyWidget_IndexUtentePremiumPCBuilder::getCercapartiPushButton() const{
    return cercapartiPushButton;
}

QPushButton* MyWidget_IndexUtentePremiumPCBuilder::getMostraconfsalvatePushButton() const{
    return mostraconfsalvatePushButton;
}

QPushButton* MyWidget_IndexUtentePremiumPCBuilder::getModificaProfiloPushButton() const{
    return modificaprofiloPushButton;
}

QPushButton* MyWidget_IndexUtentePremiumPCBuilder::getEsciPushButton() const{
    return esciPushButton;
}
