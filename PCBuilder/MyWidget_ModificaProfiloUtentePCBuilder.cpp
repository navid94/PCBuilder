#include "MyWidget_ModificaProfiloUtentePCBuilder.h"
#include "MainWindow.h"
#include "PCBuilderController.h"

#include <QLayout>

MyWidget_ModificaProfiloUtentePCBuilder::MyWidget_ModificaProfiloUtentePCBuilder(MainWindow* input_mw,QWidget* parent):
    QWidget(parent),mw(input_mw){
    createLabels();
    createPushButtons();
    createLineEdits();
    createComboBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setSpacing(25);

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout3=new QHBoxLayout;

    QVBoxLayout* verticalLayout1=new QVBoxLayout;

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_ModificaProfiloLabel);

    gridLayout->addWidget(emailLabel,0,0,1,1);
    gridLayout->addWidget(emailLineEdit,0,1,1,1);
    gridLayout->addWidget(nomeLabel,1,0,1,1);
    gridLayout->addWidget(nomeLineEdit,1,1,1,1);
    gridLayout->addWidget(cognomeLabel,2,0,1,1);
    gridLayout->addWidget(cognomeLineEdit,2,1,1,1);
    gridLayout->addWidget(nuovaPasswordLabel,3,0,1,1);
    gridLayout->addWidget(nuovaPasswordLineEdit,3,1,1,1);
    gridLayout->addWidget(confermaNuovaPasswordLabel,4,0,1,1);
    gridLayout->addWidget(confermaNuovaPasswordLineEdit,4,1,1,1);

    horizontalLayout2->addWidget(dataDiNascitaLabel);
    horizontalLayout2->addWidget(giornoNascitaComboBox);
    horizontalLayout2->addWidget(meseNascitaComboBox);
    horizontalLayout2->addWidget(annoNascitaComboBox);

    horizontalLayout3->addWidget(eliminaAccountPushButton);
    horizontalLayout3->addWidget(modificaPushButton);
    horizontalLayout3->addWidget(diventaPremiumPushButton);

    if (mw->get_Controller()->getUserType()=="UtentePremium")
        diventaPremiumPushButton->hide();

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(gridLayout);
    verticalLayout1->addLayout(horizontalLayout2);
    verticalLayout1->addLayout(horizontalLayout3);

    setLayout(verticalLayout1);
}

void MyWidget_ModificaProfiloUtentePCBuilder::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    PCBuilder_ModificaProfiloLabel=new QLabel("PCBuilder - "+(tr("Modifica profilo")));
    QFont font_PCBuilder_ModificaProfiloLabel=PCBuilder_ModificaProfiloLabel->font();
    font_PCBuilder_ModificaProfiloLabel.setPointSize(24);
    PCBuilder_ModificaProfiloLabel->setFont(font_PCBuilder_ModificaProfiloLabel);
    PCBuilder_ModificaProfiloLabel->setMaximumSize(QSize(430,50));
    PCBuilder_ModificaProfiloLabel->setMinimumSize(QSize(0,0));

    emailLabel=new QLabel("Email:");
    emailLabel->setFont(font_formLabel);
    emailLabel->setMaximumSize(QSize(60,30));
    emailLabel->setMinimumSize(QSize(0,0));

    nomeLabel=new QLabel(tr("Nome:"));
    nomeLabel->setFont(font_formLabel);
    nomeLabel->setMaximumSize(QSize(70,30));
    nomeLabel->setMinimumSize(QSize(0,0));

    cognomeLabel=new QLabel(tr("Cognome:"));
    cognomeLabel->setFont(font_formLabel);
    cognomeLabel->setMaximumSize(QSize(100,30));
    cognomeLabel->setMinimumSize(QSize(0,0));

    nuovaPasswordLabel=new QLabel(tr("Nuova password:"));
    nuovaPasswordLabel->setFont(font_formLabel);
    nuovaPasswordLabel->setMaximumSize(QSize(170,30));
    nuovaPasswordLabel->setMinimumSize(QSize(0,0));

    confermaNuovaPasswordLabel=new QLabel(tr("Conferma nuova \npassword"));
    confermaNuovaPasswordLabel->setFont(font_formLabel);
    confermaNuovaPasswordLabel->setMaximumSize(QSize(170,50));
    confermaNuovaPasswordLabel->setMinimumSize(QSize(0,0));

    dataDiNascitaLabel=new QLabel(tr("Data di nascita:"));
    dataDiNascitaLabel->setFont(font_formLabel);
    dataDiNascitaLabel->setMaximumSize(QSize(160,30));
    dataDiNascitaLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_ModificaProfiloUtentePCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));

    modificaPushButton=new QPushButton(tr("Modifica"));
    modificaPushButton->setMaximumSize(QSize(200,50));
    modificaPushButton->setMinimumSize(QSize(0,0));

    eliminaAccountPushButton=new QPushButton(tr("Elimina account"));
    eliminaAccountPushButton->setMaximumSize(QSize(250,50));
    eliminaAccountPushButton->setMinimumSize(QSize(0,0));

    diventaPremiumPushButton=new QPushButton(tr("Diventa Premium"));
    diventaPremiumPushButton->setMaximumSize(QSize(250,50));
    diventaPremiumPushButton->setMinimumSize(QSize(0,0));
}

void MyWidget_ModificaProfiloUtentePCBuilder::createLineEdits(){
    emailLineEdit=new QLineEdit;
    emailLineEdit->setPlaceholderText(tr("Inserire la nuova email"));
    emailLineEdit->setMaximumSize(QSize(200,30));
    emailLineEdit->setMinimumSize(QSize(0,0));

    nomeLineEdit=new QLineEdit;
    nomeLineEdit->setPlaceholderText(tr("Inserire il nuovo nome"));
    nomeLineEdit->setMaximumSize(QSize(200,30));
    nomeLineEdit->setMinimumSize(QSize(0,0));

    cognomeLineEdit=new QLineEdit;
    cognomeLineEdit->setPlaceholderText(tr("Inserire il nuovo cognome"));
    cognomeLineEdit->setMaximumSize(QSize(200,30));
    cognomeLineEdit->setMinimumSize(QSize(0,0));

    nuovaPasswordLineEdit=new QLineEdit;
    nuovaPasswordLineEdit->setEchoMode(QLineEdit::Password);
    nuovaPasswordLineEdit->setPlaceholderText(tr("Inserire la nuova password"));
    nuovaPasswordLineEdit->setMaximumSize(QSize(200,30));
    nuovaPasswordLineEdit->setMinimumSize(QSize(0,0));

    confermaNuovaPasswordLineEdit=new QLineEdit;
    confermaNuovaPasswordLineEdit->setEchoMode(QLineEdit::Password);
    confermaNuovaPasswordLineEdit->setPlaceholderText(tr("Inserire la conferma della password"));
    confermaNuovaPasswordLineEdit->setMaximumSize(QSize(200,30));
    confermaNuovaPasswordLineEdit->setMinimumSize(QSize(0,0));
}

void MyWidget_ModificaProfiloUtentePCBuilder::createComboBoxes(){
    giornoNascitaComboBox=new QComboBox;
    giornoNascitaComboBox->setMaximumSize(QSize(70,25));
    giornoNascitaComboBox->setMinimumSize(QSize(0,0));
    giornoNascitaComboBox->addItem("");
    for (int i=1;i<32;i++)
        giornoNascitaComboBox->addItem(QString::number(i));

    meseNascitaComboBox=new QComboBox;
    meseNascitaComboBox->setMaximumSize(QSize(70,25));
    meseNascitaComboBox->setMinimumSize(QSize(0,0));
    meseNascitaComboBox->addItem("");
    for (int i=1;i<13;i++)
        meseNascitaComboBox->addItem(QString::number(i));

    annoNascitaComboBox=new QComboBox;
    annoNascitaComboBox->setMaximumSize(QSize(100,25));
    annoNascitaComboBox->setMinimumSize(QSize(0,0));
    annoNascitaComboBox->addItem("");
    for (int i=1900;i<2017;i++)
        annoNascitaComboBox->addItem(QString::number(i));
}

QPushButton* MyWidget_ModificaProfiloUtentePCBuilder::getIndietroPushButton() const{
    return indietroPushButton;
}

QPushButton* MyWidget_ModificaProfiloUtentePCBuilder::getModificaPushButton() const{
    return modificaPushButton;
}

QPushButton* MyWidget_ModificaProfiloUtentePCBuilder::getEliminaAccountPushButton() const{
    return eliminaAccountPushButton;
}

QPushButton* MyWidget_ModificaProfiloUtentePCBuilder::getDiventaPremiumPushButton() const{
    return diventaPremiumPushButton;
}

QString MyWidget_ModificaProfiloUtentePCBuilder::emailValue() const{
    return emailLineEdit->text();
}

QString MyWidget_ModificaProfiloUtentePCBuilder::nomeValue() const{
    return nomeLineEdit->text();
}

QString MyWidget_ModificaProfiloUtentePCBuilder::cognomeValue() const{
    return cognomeLineEdit->text();
}

QString MyWidget_ModificaProfiloUtentePCBuilder::nuovaPasswordValue() const{
    return nuovaPasswordLineEdit->text();
}

QString MyWidget_ModificaProfiloUtentePCBuilder::confermaNuovaPasswordValue() const{
    return confermaNuovaPasswordLineEdit->text();
}

QString MyWidget_ModificaProfiloUtentePCBuilder::giornoNascitaValue() const{
    return giornoNascitaComboBox->currentText();
}

QString MyWidget_ModificaProfiloUtentePCBuilder::meseNascitaValue() const{
    return meseNascitaComboBox->currentText();
}

QString MyWidget_ModificaProfiloUtentePCBuilder::annoNascitaValue() const{
    return annoNascitaComboBox->currentText();
}
