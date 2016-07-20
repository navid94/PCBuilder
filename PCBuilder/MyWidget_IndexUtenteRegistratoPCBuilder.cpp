#include "MyWidget_IndexUtenteRegistratoPCBuilder.h"
#include <QLayout>

MyWidget_IndexUtenteRegistratoPCBuilder::MyWidget_IndexUtenteRegistratoPCBuilder(QWidget* parent):QWidget(parent){
    createPushButtons();
    createLabels();

    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QVBoxLayout* verticalLayout2=new QVBoxLayout;

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout3=new QHBoxLayout;
    QHBoxLayout* horizontalLayout4=new QHBoxLayout;
    QHBoxLayout* horizontalLayout5=new QHBoxLayout;

    horizontalLayout1->addWidget(PCBuilder_IndexUtenteRegistratoLabel);

    horizontalLayout2->addWidget(creaconfPushButton);
    horizontalLayout2->addWidget(mostraconfsalvatePushButton);
    horizontalLayout2->setSpacing(30);

    verticalLayout2->addLayout(horizontalLayout3);
    verticalLayout2->addLayout(horizontalLayout4);

    horizontalLayout3->addWidget(modificaprofiloPushButton);
    horizontalLayout4->addWidget(esciPushButton);
    horizontalLayout4->setContentsMargins(0,30,0,0);

    horizontalLayout5->addLayout(horizontalLayout2);
    horizontalLayout5->addLayout(verticalLayout2);

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(horizontalLayout5);

    setLayout(verticalLayout1);
}


void MyWidget_IndexUtenteRegistratoPCBuilder::createLabels(){
    PCBuilder_IndexUtenteRegistratoLabel=new QLabel("PCBuilder - "+tr("Index utente registrato"));
    QFont font_PCBuilder_IndexUtenteRegistratoLabel=PCBuilder_IndexUtenteRegistratoLabel->font();
    font_PCBuilder_IndexUtenteRegistratoLabel.setPointSize(24);
    PCBuilder_IndexUtenteRegistratoLabel->setFont(font_PCBuilder_IndexUtenteRegistratoLabel);
    PCBuilder_IndexUtenteRegistratoLabel->setMaximumSize(QSize(570,50));
    PCBuilder_IndexUtenteRegistratoLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_IndexUtenteRegistratoPCBuilder::createPushButtons(){
    creaconfPushButton=new QPushButton(tr("Crea una configurazione"));
    creaconfPushButton->setMaximumSize(QSize(200,70));
    creaconfPushButton->setMinimumSize(QSize(0,0));

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

QPushButton* MyWidget_IndexUtenteRegistratoPCBuilder::getCreaconfPushButton() const{
    return creaconfPushButton;
}

QPushButton* MyWidget_IndexUtenteRegistratoPCBuilder::getMostraconfsalvatePushButton() const{
    return mostraconfsalvatePushButton;
}

QPushButton* MyWidget_IndexUtenteRegistratoPCBuilder::getModificaProfiloPushButton() const{
    return modificaprofiloPushButton;
}

QPushButton* MyWidget_IndexUtenteRegistratoPCBuilder::getEsciPushButton() const{
    return esciPushButton;
}
