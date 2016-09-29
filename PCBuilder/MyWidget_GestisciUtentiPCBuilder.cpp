#include "MyWidget_GestisciUtentiPCBuilder.h"
#include <QLayout>
#include <QFont>

MyWidget_GestisciUtentiPCBuilder::MyWidget_GestisciUtentiPCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createPushButtons();
    createLineEdits();
    createComboBoxes();

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout3=new QHBoxLayout;
    QHBoxLayout* horizontalLayout4=new QHBoxLayout;
    QHBoxLayout* horizontalLayout5=new QHBoxLayout;
    QHBoxLayout* horizontalLayout6=new QHBoxLayout;
    QHBoxLayout* horizontalLayout7=new QHBoxLayout;
    QHBoxLayout* horizontalLayout8=new QHBoxLayout;
    QHBoxLayout* horizontalLayout9=new QHBoxLayout;


    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QVBoxLayout* verticalLayout2=new QVBoxLayout;
    QVBoxLayout* verticalLayout3=new QVBoxLayout;
    QVBoxLayout* verticalLayout4=new QVBoxLayout;

    QGridLayout* gridLayout1=new QGridLayout;

    horizontalLayout1->addWidget(elimina_utentePushButton);
    horizontalLayout2->addWidget(username_utenterimuovereLineEdit);
    horizontalLayout3->addWidget(rimuovi_utenteLabel);

    verticalLayout1->addLayout(horizontalLayout3);
    verticalLayout1->addLayout(horizontalLayout2);
    verticalLayout1->addLayout(horizontalLayout1);

    horizontalLayout4->addWidget(modificaPushButton);

    horizontalLayout5->addWidget(data_di_nascitaLabel);
    horizontalLayout5->addWidget(giornonascitaComboBox);
    horizontalLayout5->addWidget(mesenascitaComboBox);
    horizontalLayout5->addWidget(annonascitaComboBox);
    horizontalLayout5->setContentsMargins(0,0,0,25);

    gridLayout1->setSpacing(25);
    gridLayout1->setContentsMargins(0,25,0,25);
    gridLayout1->addWidget(usernameLabel,0,0,1,1);
    gridLayout1->addWidget(usernameLineEdit,0,1,1,1);
    gridLayout1->addWidget(emailLabel,1,0,1,1);
    gridLayout1->addWidget(emailLineEdit,1,1,1,1);
    gridLayout1->addWidget(nomeLabel,2,0,1,1);
    gridLayout1->addWidget(nomeLineEdit,2,1,1,1);
    gridLayout1->addWidget(cognomeLabel,3,0,1,1);
    gridLayout1->addWidget(cognomeLineEdit,3,1,1,1);
    gridLayout1->addWidget(passwordLabel,4,0,1,1);
    gridLayout1->addWidget(passwordLineEdit,4,1,1,1);
    gridLayout1->addWidget(tipo_accountLabel,5,0,1,1);
    gridLayout1->addWidget(tipoaccountComboBox,5,1,1,1);

    horizontalLayout6->addWidget(username_utentemodificaLineEdit);
    horizontalLayout7->addWidget(modifica_dati_utenteLabel);

    verticalLayout2->addLayout(horizontalLayout7);
    verticalLayout2->addLayout(horizontalLayout6);

    verticalLayout3->addLayout(verticalLayout2);
    verticalLayout3->addLayout(gridLayout1);
    verticalLayout3->addLayout(horizontalLayout5);
    verticalLayout3->addLayout(horizontalLayout4);

    horizontalLayout8->addLayout(verticalLayout3);
    horizontalLayout8->addLayout(verticalLayout1);

    horizontalLayout9->addWidget(indietroPushButton);
    horizontalLayout9->addWidget(PCBuilder_Gestione_utentiLabel);
    horizontalLayout9->setContentsMargins(0,0,0,50);

    verticalLayout4->addLayout(horizontalLayout9);
    verticalLayout4->addLayout(horizontalLayout8);

    setLayout(verticalLayout4);
}

void MyWidget_GestisciUtentiPCBuilder::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    PCBuilder_Gestione_utentiLabel=new QLabel("PCBuilder - "+(tr("Gestione utenti")));
    QFont font_PCBuilder_Gestione_utentiLabel=PCBuilder_Gestione_utentiLabel->font();
    font_PCBuilder_Gestione_utentiLabel.setPointSize(24);
    PCBuilder_Gestione_utentiLabel->setFont(font_PCBuilder_Gestione_utentiLabel);
    PCBuilder_Gestione_utentiLabel->setMinimumSize(QSize(0,0));
    PCBuilder_Gestione_utentiLabel->setMaximumSize(QSize(450,50));

    modifica_dati_utenteLabel=new QLabel(tr("Modifica dati utente"));
    QFont font_modifica_dati_utenteLabel=modifica_dati_utenteLabel->font();
    font_modifica_dati_utenteLabel.setPointSize(18);
    modifica_dati_utenteLabel->setFont(font_modifica_dati_utenteLabel);
    modifica_dati_utenteLabel->setMinimumSize(QSize(0,0));
    modifica_dati_utenteLabel->setMaximumSize(QSize(250,30));

    rimuovi_utenteLabel=new QLabel(tr("Rimuovi utente"));
    QFont font_rimuovi_utenteLabel=rimuovi_utenteLabel->font();
    font_rimuovi_utenteLabel.setPointSize(18);
    rimuovi_utenteLabel->setFont(font_rimuovi_utenteLabel);
    rimuovi_utenteLabel->setMinimumSize(QSize(0,0));
    rimuovi_utenteLabel->setMaximumSize(QSize(190,50));

    usernameLabel=new QLabel("Username:");
    usernameLabel->setFont(font_formLabel);
    usernameLabel->setMinimumSize(QSize(0,0));
    usernameLabel->setMaximumSize(QSize(110,30));

    emailLabel=new QLabel("Email:");
    emailLabel->setFont(font_formLabel);
    emailLabel->setMinimumSize(QSize(0,0));
    emailLabel->setMaximumSize(QSize(70,30));

    nomeLabel=new QLabel(tr("Nome:"));
    nomeLabel->setFont(font_formLabel);
    nomeLabel->setMinimumSize(QSize(0,0));
    nomeLabel->setMaximumSize(QSize(70,30));

    cognomeLabel=new QLabel(tr("Cognome:"));
    cognomeLabel->setFont(font_formLabel);
    cognomeLabel->setMinimumSize(QSize(0,0));
    cognomeLabel->setMaximumSize(QSize(100,30));

    passwordLabel=new QLabel("Password:");
    passwordLabel->setFont(font_formLabel);
    passwordLabel->setMinimumSize(QSize(0,0));
    passwordLabel->setMaximumSize(QSize(100,30));

    tipo_accountLabel=new QLabel(tr("Tipo account"));
    tipo_accountLabel->setFont(font_formLabel);
    tipo_accountLabel->setMinimumSize(QSize(0,0));
    tipo_accountLabel->setMaximumSize(QSize(140,30));

    data_di_nascitaLabel=new QLabel(tr("Data di nascita"));
    data_di_nascitaLabel->setFont(font_formLabel);
    data_di_nascitaLabel->setMinimumSize(QSize(0,0));
    data_di_nascitaLabel->setMaximumSize(QSize(150,30));
}

void MyWidget_GestisciUtentiPCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMinimumSize(QSize(0,0));
    indietroPushButton->setMaximumSize(QSize(150,30));

    modificaPushButton=new QPushButton(tr("Modifica"));
    modificaPushButton->setMinimumSize(QSize(0,0));
    modificaPushButton->setMaximumSize(QSize(160,60));

    elimina_utentePushButton=new QPushButton(tr("Elimina utente"));
    elimina_utentePushButton->setMinimumSize(QSize(0,0));
    elimina_utentePushButton->setMaximumSize(QSize(160,60));
}

void MyWidget_GestisciUtentiPCBuilder::createLineEdits(){
    username_utentemodificaLineEdit=new QLineEdit;
    username_utentemodificaLineEdit->setPlaceholderText(tr("Inserire username utente da aggiornare"));
    username_utentemodificaLineEdit->setMaximumSize(QSize(250,30));
    username_utentemodificaLineEdit->setMinimumSize(QSize(0,0));

    usernameLineEdit=new QLineEdit;
    usernameLineEdit->setPlaceholderText(tr("Inserire nuovo username"));
    usernameLineEdit->setMinimumSize(QSize(0,0));
    usernameLineEdit->setMaximumSize(QSize(200,30));

    emailLineEdit=new QLineEdit;
    emailLineEdit->setPlaceholderText(tr("Inserire nuova email"));
    emailLineEdit->setMinimumSize(QSize(0,0));
    emailLineEdit->setMaximumSize(QSize(200,30));

    nomeLineEdit=new QLineEdit;
    nomeLineEdit->setPlaceholderText(tr("Inserire nuovo nome"));
    nomeLineEdit->setMinimumSize(QSize(0,0));
    nomeLineEdit->setMaximumSize(QSize(200,30));

    cognomeLineEdit=new QLineEdit;
    cognomeLineEdit->setPlaceholderText(tr("Inserire nuovo cognome"));
    cognomeLineEdit->setMinimumSize(QSize(0,0));
    cognomeLineEdit->setMaximumSize(QSize(200,30));

    passwordLineEdit=new QLineEdit;
    passwordLineEdit->setPlaceholderText(tr("Inserire nuova password"));
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMinimumSize(QSize(0,0));
    passwordLineEdit->setMaximumSize(200,30);

    username_utenterimuovereLineEdit=new QLineEdit;
    username_utenterimuovereLineEdit->setPlaceholderText(tr("Inserire username utente da rimuovere"));
    username_utenterimuovereLineEdit->setMinimumSize(QSize(0,0));
    username_utenterimuovereLineEdit->setMaximumSize(QSize(250,30));
}

void MyWidget_GestisciUtentiPCBuilder::createComboBoxes(){

    tipoaccountComboBox=new QComboBox;
    tipoaccountComboBox->setMinimumSize(QSize(0,0));
    tipoaccountComboBox->setMaximumSize(QSize(200,25));
    tipoaccountComboBox->addItem("");
    tipoaccountComboBox->addItem("UtentePremium");
    tipoaccountComboBox->addItem("UtenteRegistrato");

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

QPushButton* MyWidget_GestisciUtentiPCBuilder::get_indietroPushButton() const{
    return indietroPushButton;
}

QPushButton* MyWidget_GestisciUtentiPCBuilder::get_elimina_utentePushButton() const{
    return elimina_utentePushButton;
}

QPushButton* MyWidget_GestisciUtentiPCBuilder::get_modificaPushButton() const{
    return modificaPushButton;
}

QString MyWidget_GestisciUtentiPCBuilder::username_utentemodificaValue() const{
    return username_utentemodificaLineEdit->text();
}

QString MyWidget_GestisciUtentiPCBuilder::usernameValue() const{
    return usernameLineEdit->text();
}

QString MyWidget_GestisciUtentiPCBuilder::emailValue() const{
    return emailLineEdit->text();
}

QString MyWidget_GestisciUtentiPCBuilder::nomeValue() const{
    return nomeLineEdit->text();
}

QString MyWidget_GestisciUtentiPCBuilder::cognomeValue() const{
    return cognomeLineEdit->text();
}

QString MyWidget_GestisciUtentiPCBuilder::passwordValue() const{
    return passwordLineEdit->text();
}

QString MyWidget_GestisciUtentiPCBuilder::username_utenterimuovereValue() const{
    return username_utenterimuovereLineEdit->text();
}

QString MyWidget_GestisciUtentiPCBuilder::tipoaccountValue() const{
    return tipoaccountComboBox->currentText();
}

QString MyWidget_GestisciUtentiPCBuilder::giornonascitaValue() const{
    return giornonascitaComboBox->currentText();
}

QString MyWidget_GestisciUtentiPCBuilder::mesenascitaValue() const{
    return mesenascitaComboBox->currentText();
}

QString MyWidget_GestisciUtentiPCBuilder::annonascitaValue() const{
    return annonascitaComboBox->currentText();
}

QLineEdit* MyWidget_GestisciUtentiPCBuilder::get_username_utenterimuovereLineEdit() const{
    return username_utenterimuovereLineEdit;
}
