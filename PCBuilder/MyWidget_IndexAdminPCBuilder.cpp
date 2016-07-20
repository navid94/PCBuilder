#include "MyWidget_IndexAdminPCBuilder.h"
#include <QLayout>

MyWidget_IndexAdminPCBuilder::MyWidget_IndexAdminPCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createPushButtons();

    QVBoxLayout* verticalLayout=new QVBoxLayout;
    verticalLayout->setSpacing(200);
    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(pcbuilderadminLabel);
    horizontalLayout1->setContentsMargins(100,0,200,0);

    horizontalLayout2->addWidget(gestiscicompPushButton);
    horizontalLayout2->addWidget(gestisciutentiPushButton);

    verticalLayout->addLayout(horizontalLayout1);
    verticalLayout->addLayout(horizontalLayout2);

    setLayout(verticalLayout);
}

void MyWidget_IndexAdminPCBuilder::createLabels(){
    pcbuilderadminLabel=new QLabel("PCBuilder - Admin");
    pcbuilderadminLabel->setMaximumSize(QSize(300,50));
    pcbuilderadminLabel->setMinimumSize(QSize(0,0));
    QFont pcbuilderadminLabel_font=pcbuilderadminLabel->font();
    pcbuilderadminLabel_font.setPointSize(24);
    pcbuilderadminLabel->setFont(pcbuilderadminLabel_font);
}

void MyWidget_IndexAdminPCBuilder::createPushButtons(){
    gestiscicompPushButton=new QPushButton(tr("Gestisci componenti"));
    gestiscicompPushButton->setMaximumSize(QSize(160,60));
    gestiscicompPushButton->setMinimumSize(QSize(0,0));

    gestisciutentiPushButton=new QPushButton(tr("Gestisci utenti"));
    gestisciutentiPushButton->setMaximumSize(QSize(160,60));
    gestisciutentiPushButton->setMinimumSize(QSize(0,0));

    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMinimumSize(QSize(0,0));
    indietroPushButton->setMaximumSize(QSize(150,30));
}

QPushButton* MyWidget_IndexAdminPCBuilder::get_gestiscicompPushButton() const{
    return gestiscicompPushButton;
}

QPushButton* MyWidget_IndexAdminPCBuilder::get_gestisciutentiPushButton() const{
    return gestisciutentiPushButton;
}

QPushButton* MyWidget_IndexAdminPCBuilder::get_indietroPushButton() const{
    return indietroPushButton;
}
