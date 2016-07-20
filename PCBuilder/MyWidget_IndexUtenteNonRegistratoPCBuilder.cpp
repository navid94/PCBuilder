#include "MyWidget_IndexUtenteNonRegistratoPCBuilder.h"

#include <QLayout>

MyWidget_IndexUtenteNonRegistratoPCBuilder::MyWidget_IndexUtenteNonRegistratoPCBuilder(QWidget * parent):QWidget(parent){
    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QVBoxLayout* verticalLayout2=new QVBoxLayout;

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout3=new QHBoxLayout;
    QHBoxLayout* horizontalLayout4=new QHBoxLayout;
    QHBoxLayout* horizontalLayout5=new QHBoxLayout;
    QHBoxLayout* horizontalLayout6=new QHBoxLayout;
    QHBoxLayout* horizontalLayout7=new QHBoxLayout;

    createLabels();
    createLineEdits();
    createPushButtons();

    horizontalLayout1->addWidget(creaconfPushButton);

    horizontalLayout2->addWidget(oppureLabel);
    horizontalLayout2->addWidget(registratiPushButton);
    horizontalLayout2->setSpacing(50);

    horizontalLayout3->addWidget(usernameLabel);
    horizontalLayout3->addWidget(usernameLineEdit);
    horizontalLayout3->setContentsMargins(0,0,60,0);
    horizontalLayout3->setSpacing(30);

    horizontalLayout4->addWidget(passwordLabel);
    horizontalLayout4->addWidget(passwordLineEdit);
    horizontalLayout4->setContentsMargins(0,0,60,0);
    horizontalLayout4->setSpacing(30);

    horizontalLayout5->addWidget(accediPushButton);

    verticalLayout1->addLayout(horizontalLayout3);
    verticalLayout1->addLayout(horizontalLayout4);
    verticalLayout1->addLayout(horizontalLayout5);
    verticalLayout1->setSpacing(30);

    horizontalLayout6->addLayout(verticalLayout1);
    horizontalLayout6->addLayout(horizontalLayout2);
    horizontalLayout6->setContentsMargins(0,0,20,0);

    horizontalLayout7->addWidget(indietroPushButton);
    horizontalLayout7->addWidget(PCBuilder_IndexUtenteNonRegistratoLabel);
    horizontalLayout7->setSpacing(30);

    verticalLayout2->addLayout(horizontalLayout7);
    verticalLayout2->addLayout(horizontalLayout1);
    verticalLayout2->addLayout(horizontalLayout6);

    setLayout(verticalLayout2);
}

void MyWidget_IndexUtenteNonRegistratoPCBuilder::createLabels(){
    QFont fontLabel;
    fontLabel.setPointSize(14);

    PCBuilder_IndexUtenteNonRegistratoLabel=new QLabel("PCBuilder - "+tr("Index utente non registrato"));
    QFont font_PCBuilder_IndexUtenteNonRegistratoLabel=PCBuilder_IndexUtenteNonRegistratoLabel->font();
    font_PCBuilder_IndexUtenteNonRegistratoLabel.setPointSize(24);
    PCBuilder_IndexUtenteNonRegistratoLabel->setFont(font_PCBuilder_IndexUtenteNonRegistratoLabel);
    PCBuilder_IndexUtenteNonRegistratoLabel->setMaximumSize(QSize(630,50));
    PCBuilder_IndexUtenteNonRegistratoLabel->setMinimumSize(QSize(0,0));

    usernameLabel=new QLabel("Username");
    usernameLabel->setFont(fontLabel);
    usernameLabel->setMaximumSize(QSize(110,25));
    usernameLabel->setMinimumSize(QSize(0,0));

    passwordLabel=new QLabel("Password");
    passwordLabel->setFont(fontLabel);
    passwordLabel->setMaximumSize(QSize(100,25));
    passwordLabel->setMinimumSize(QSize(0,0));

    oppureLabel=new QLabel(tr("oppure"));
    oppureLabel->setFont(fontLabel);
    oppureLabel->setMaximumSize(QSize(100,25));
    oppureLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_IndexUtenteNonRegistratoPCBuilder::createLineEdits(){
    usernameLineEdit=new QLineEdit;
    usernameLineEdit->setMaximumSize(QSize(250,25));
    usernameLineEdit->setMinimumSize(QSize(0,0));

    passwordLineEdit=new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMaximumSize(QSize(250,25));
    passwordLineEdit->setMinimumSize(QSize(0,0));
}

void MyWidget_IndexUtenteNonRegistratoPCBuilder::createPushButtons(){
    creaconfPushButton=new QPushButton(tr("Crea una configurazione"));
    creaconfPushButton->setMaximumSize(QSize(200,70));
    creaconfPushButton->setMinimumSize(QSize(0,0));

    accediPushButton=new QPushButton(tr("Accedi"));
    accediPushButton->setMaximumSize(QSize(150,50));
    accediPushButton->setMinimumSize(QSize(0,0));

    registratiPushButton=new QPushButton(tr("Registrati"));
    registratiPushButton->setMinimumSize(QSize(0,0));
    registratiPushButton->setMaximumSize(QSize(150,50));

    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMinimumSize(QSize(0,0));
    indietroPushButton->setMaximumSize(QSize(150,30));
}

QPushButton* MyWidget_IndexUtenteNonRegistratoPCBuilder::get_creaconfPushButton() const{
    return creaconfPushButton;
}

QPushButton* MyWidget_IndexUtenteNonRegistratoPCBuilder::get_accediPushButton() const{
    return accediPushButton;
}

QPushButton* MyWidget_IndexUtenteNonRegistratoPCBuilder::get_registratiPushButton() const{
    return registratiPushButton;
}

QPushButton* MyWidget_IndexUtenteNonRegistratoPCBuilder::get_indietroPushButton() const{
    return indietroPushButton;
}

QString MyWidget_IndexUtenteNonRegistratoPCBuilder::usernameValue() const{
    return usernameLineEdit->text();
}

QString MyWidget_IndexUtenteNonRegistratoPCBuilder::passwordValue() const{
    return passwordLineEdit->text();
}
