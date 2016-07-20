#include "MyWidget_IndexPCBuilder.h"
#include <QLayout>
#include <QFont>

MyWidget_IndexPCBuilder::MyWidget_IndexPCBuilder(QWidget* parent):QWidget(parent){

    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QVBoxLayout* verticalLayout2=new QVBoxLayout;
    QHBoxLayout* horizontalLayout=new QHBoxLayout;

    createLabels();
    createPushButtons();

    verticalLayout1->addWidget(pcbuilderLabel);
    verticalLayout1->addWidget(selmodaccessoLabel);
    verticalLayout1->setSpacing(50);
    verticalLayout1->setContentsMargins(0, 0, 0, 100);

    verticalLayout2->addLayout(verticalLayout1);

    horizontalLayout->addWidget(utentePushButton);
    horizontalLayout->addWidget(adminPushButton);
    horizontalLayout->setContentsMargins(0, 0, 0, 50);

    verticalLayout2->addLayout(horizontalLayout);
    setLayout(verticalLayout2);
}

void MyWidget_IndexPCBuilder::createLabels(){
    pcbuilderLabel=new QLabel("PCBuilder");
    pcbuilderLabel->setAlignment(Qt::AlignHCenter);
    QFont font_pcbuilderLabel=pcbuilderLabel->font();
    font_pcbuilderLabel.setBold(true);
    font_pcbuilderLabel.setPointSize(24);
    pcbuilderLabel->setFont(font_pcbuilderLabel);

    selmodaccessoLabel=new QLabel(tr("Selezionare la modatà di accesso"));
    selmodaccessoLabel->setAlignment(Qt::AlignHCenter);
    QFont font_selmodaccessoLabel=selmodaccessoLabel->font();
    font_selmodaccessoLabel.setPointSize(16);
    selmodaccessoLabel->setFont(font_selmodaccessoLabel);
}

void MyWidget_IndexPCBuilder::createPushButtons(){
    adminPushButton=new QPushButton("Admin");
    adminPushButton->setMaximumSize(QSize(160,60));
    adminPushButton->setMinimumSize(QSize(160,60));

    utentePushButton=new QPushButton(tr("Utente"));
    utentePushButton->setMaximumSize(QSize(160,60));
    utentePushButton->setMinimumSize(QSize(160,60));
}

QPushButton* MyWidget_IndexPCBuilder::getutentePushButton() const{
    return utentePushButton;
}

QPushButton* MyWidget_IndexPCBuilder::getadminPushButton() const{
    return adminPushButton;
}
