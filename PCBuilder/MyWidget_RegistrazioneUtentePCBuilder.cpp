#include "MyWidget_RegistrazioneUtentePCBuilder.h"
#include <QLayout>
#include <QFont>

MyWidget_RegistrazioneUtentePCBuilder::MyWidget_RegistrazioneUtentePCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createPushButtons();
    createComboBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setSpacing(25);
    gridLayout->setContentsMargins(0,50,0,50);
    gridLayout->addWidget(usernameLabel,0,0,1,1);
    gridLayout->addWidget(usernameLineEdit,0,1,1,1);
    gridLayout->addWidget(emailLabel,1,0,1,1);
    gridLayout->addWidget(emailLineEdit,1,1,1,1);
    gridLayout->addWidget(nomeLabel,2,0,1,1);
    gridLayout->addWidget(nomeLineEdit,2,1,1,1);
    gridLayout->addWidget(cognomeLabel,3,0,1,1);
    gridLayout->addWidget(cognomeLineEdit,3,1,1,1);
    gridLayout->addWidget(passwordLabel,4,0,1,1);
    gridLayout->addWidget(passwordLineEdit,4,1,1,1);
    gridLayout->addWidget(confermapasswordLabel,5,0,1,1);
    gridLayout->addWidget(confermapasswordLineEdit,5,1,1,1);

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_registrazioneLabel);


    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    horizontalLayout2->addWidget(registratiPushButton);

    QHBoxLayout* horizontalLayout3=new QHBoxLayout;
    horizontalLayout3->setContentsMargins(100,0,100,30);
    horizontalLayout3->addWidget(datanascitaLabel);
    horizontalLayout3->addWidget(giornonascitaComboBox);
    horizontalLayout3->addWidget(mesenascitaComboBox);
    horizontalLayout3->addWidget(annonascitaComboBox);

    QVBoxLayout* verticalLayout=new QVBoxLayout;
    verticalLayout->addLayout(horizontalLayout1);
    verticalLayout->addLayout(gridLayout);
    verticalLayout->addLayout(horizontalLayout3);
    verticalLayout->addLayout(horizontalLayout2);

    setLayout(verticalLayout);
}

void MyWidget_RegistrazioneUtentePCBuilder::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    usernameLabel=new QLabel("Username:");
    usernameLabel->setMaximumSize(QSize(110,25));
    usernameLabel->setMinimumSize(QSize(0,0));
    usernameLabel->setFont(font_formLabel);

    passwordLabel=new QLabel("Password:");
    passwordLabel->setMinimumSize(QSize(0,0));
    passwordLabel->setMaximumSize(QSize(110,25));
    passwordLabel->setFont(font_formLabel);

    confermapasswordLabel=new QLabel(tr("Conferma password:"));
    confermapasswordLabel->setMinimumSize(QSize(0,0));
    confermapasswordLabel->setMaximumSize(QSize(200,25));
    confermapasswordLabel->setFont(font_formLabel);

    emailLabel=new QLabel("Email:");
    emailLabel->setMaximumSize(QSize(70,25));
    emailLabel->setMinimumSize(QSize(0,0));
    emailLabel->setFont(font_formLabel);

    nomeLabel=new QLabel(tr("Nome:"));
    nomeLabel->setMaximumSize(QSize(70,25));
    nomeLabel->setMinimumSize(QSize(0,0));
    nomeLabel->setFont(font_formLabel);

    cognomeLabel=new QLabel(tr("Cognome:"));
    cognomeLabel->setMaximumSize(QSize(110,25));
    cognomeLabel->setMinimumSize(QSize(0,0));
    cognomeLabel->setFont(font_formLabel);

    datanascitaLabel=new QLabel(tr("Data di nascita:"));
    datanascitaLabel->setMaximumSize(QSize(150,50));
    datanascitaLabel->setMinimumSize(QSize(0,0));
    datanascitaLabel->setFont(font_formLabel);

    PCBuilder_registrazioneLabel=new QLabel("PCBuilder - "+tr("Registrazione"));
    PCBuilder_registrazioneLabel->setMaximumSize(QSize(410,50));
    PCBuilder_registrazioneLabel->setMinimumSize(QSize(0,0));
    QFont font_PCBuilder_registrazioneLabel=PCBuilder_registrazioneLabel->font();
    font_PCBuilder_registrazioneLabel.setPointSize(24);
    PCBuilder_registrazioneLabel->setFont(font_PCBuilder_registrazioneLabel);
}

void MyWidget_RegistrazioneUtentePCBuilder::createLineEdits(){
    usernameLineEdit=new QLineEdit;
    usernameLineEdit->setMaximumSize(QSize(200,25));
    usernameLineEdit->setMinimumSize(QSize(0,0));

    passwordLineEdit=new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMinimumSize(QSize(0,0));
    passwordLineEdit->setMaximumSize(QSize(200,25));

    confermapasswordLineEdit=new QLineEdit;
    confermapasswordLineEdit->setEchoMode(QLineEdit::Password);
    confermapasswordLineEdit->setMinimumSize(QSize(0,0));
    confermapasswordLineEdit->setMaximumSize(QSize(200,25));

    emailLineEdit=new QLineEdit;
    emailLineEdit->setMinimumSize(QSize(0,0));
    emailLineEdit->setMaximumSize(QSize(200,25));

    nomeLineEdit=new QLineEdit;
    nomeLineEdit->setMinimumSize(QSize(0,0));
    nomeLineEdit->setMaximumSize(QSize(200,25));

    cognomeLineEdit=new QLineEdit;
    cognomeLineEdit->setMinimumSize(QSize(0,0));
    cognomeLineEdit->setMaximumSize(QSize(200,25));
}

void MyWidget_RegistrazioneUtentePCBuilder::createPushButtons(){
    registratiPushButton=new QPushButton(tr("Registrati"));
    registratiPushButton->setMaximumSize(QSize(150,50));
    registratiPushButton->setMinimumSize(QSize(0,0));

    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(100,30));
    indietroPushButton->setMinimumSize(QSize(0,0));
}

void MyWidget_RegistrazioneUtentePCBuilder::createComboBoxes(){
    giornonascitaComboBox=new QComboBox;
    giornonascitaComboBox->setMaximumSize(QSize(70,25));
    giornonascitaComboBox->setMinimumSize(QSize(0,0));
    giornonascitaComboBox->addItem("");
    for (int i=1;i<32;i++)
        giornonascitaComboBox->addItem(QString::number(i));

    mesenascitaComboBox=new QComboBox;
    mesenascitaComboBox->setMinimumSize(QSize(0,0));
    mesenascitaComboBox->setMaximumSize(QSize(70,25));
    mesenascitaComboBox->addItem("");
    for (int i=1;i<13;i++)
        mesenascitaComboBox->addItem(QString::number(i));

    annonascitaComboBox=new QComboBox;
    annonascitaComboBox->setMinimumSize(QSize(0,0));
    annonascitaComboBox->setMaximumSize(QSize(100,25));
    annonascitaComboBox->addItem("");
    for (int i=1900;i<2017;i++)
        annonascitaComboBox->addItem(QString::number(i));
}

QPushButton* MyWidget_RegistrazioneUtentePCBuilder::get_registratiPushButton() const{
    return registratiPushButton;
}

QPushButton* MyWidget_RegistrazioneUtentePCBuilder::get_indietroPushButton() const{
    return indietroPushButton;
}

QString MyWidget_RegistrazioneUtentePCBuilder::usernameValue() const{
    return usernameLineEdit->text();
}

QString MyWidget_RegistrazioneUtentePCBuilder::passwordValue() const{
    return passwordLineEdit->text();
}

QString MyWidget_RegistrazioneUtentePCBuilder::confermapasswordValue() const{
    return confermapasswordLineEdit->text();
}

QString MyWidget_RegistrazioneUtentePCBuilder::emailValue() const{
    return emailLineEdit->text();
}

QString MyWidget_RegistrazioneUtentePCBuilder::nomeValue() const{
    return nomeLineEdit->text();
}

QString MyWidget_RegistrazioneUtentePCBuilder::cognomeValue() const{
    return cognomeLineEdit->text();
}

QString MyWidget_RegistrazioneUtentePCBuilder::giornonascitaValue() const{
    return giornonascitaComboBox->currentText();
}

QString MyWidget_RegistrazioneUtentePCBuilder::mesenascitaValue() const{
    return mesenascitaComboBox->currentText();
}

QString MyWidget_RegistrazioneUtentePCBuilder::annonascitaValue() const{
    return annonascitaComboBox->currentText();
}
