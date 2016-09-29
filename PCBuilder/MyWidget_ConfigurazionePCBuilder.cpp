#include "MyWidget_ConfigurazionePCBuilder.h"

MyWidget_ConfigurazionePCBuilder::MyWidget_ConfigurazionePCBuilder(QWidget* parent)
    :QWidget(parent){
    createLabels();
    createPushButtons();


    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    horizontalLayout1->setContentsMargins(0,30,0,0);

    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    horizontalLayout2->setContentsMargins(300,25,0,0);

    QHBoxLayout* horizontalLayout3=new QHBoxLayout;
    horizontalLayout3->setContentsMargins(0,0,0,25);

    QVBoxLayout* verticalLayout1=new QVBoxLayout;

    gridLayout=new QGridLayout;

    gridLayout->setContentsMargins(150,0,0,50);

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuiler_ConfigurazioneLabel);

    horizontalLayout2->addWidget(nomeConfigurazioneLabel);
    horizontalLayout2->addWidget(nomeConfigurazioneValueLabel);

    horizontalLayout3->addWidget(totaleLabel);
    horizontalLayout3->addWidget(prezzoTotaleLabel);

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(horizontalLayout2);
    verticalLayout1->addLayout(gridLayout);
    verticalLayout1->addLayout(horizontalLayout3);

    setLayout(verticalLayout1);
}

void MyWidget_ConfigurazionePCBuilder::createLabels(){
    QFont font_headerFormLabel;
    font_headerFormLabel.setPointSize(18);
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    PCBuiler_ConfigurazioneLabel=new QLabel("PCBuilder - "+(tr("Configurazione")));
    QFont font_PCBuilder_ConfigurazioneLabel=PCBuiler_ConfigurazioneLabel->font();
    font_PCBuilder_ConfigurazioneLabel.setPointSize(24);
    PCBuiler_ConfigurazioneLabel->setFont(font_PCBuilder_ConfigurazioneLabel);
    PCBuiler_ConfigurazioneLabel->setMaximumSize(QSize(620,40));
    PCBuiler_ConfigurazioneLabel->setMinimumSize(QSize(0,0));

    nomeConfigurazioneLabel=new QLabel(tr("Nome configurazione:"));
    QFont font_nomeConfigurazioneLabel=nomeConfigurazioneLabel->font();
    font_nomeConfigurazioneLabel.setPointSize(20);
    nomeConfigurazioneLabel->setFont(font_nomeConfigurazioneLabel);
    nomeConfigurazioneLabel->setMaximumSize(300,40);
    nomeConfigurazioneLabel->setMinimumSize(QSize(0,0));

    nomeConfigurazioneValueLabel=new QLabel("");
    nomeConfigurazioneValueLabel->setFont(font_headerFormLabel);
    nomeConfigurazioneValueLabel->setMinimumSize(QSize(0,0));
    nomeConfigurazioneValueLabel->setMaximumHeight(30);

    componenteLabel=new QLabel(tr("Componente"));
    componenteLabel->setFont(font_headerFormLabel);
    componenteLabel->setMaximumSize(QSize(160,30));
    componenteLabel->setMinimumSize(QSize(0,0));

    selezioneLabel=new QLabel(tr("Selezione"));
    selezioneLabel->setFont(font_headerFormLabel);
    selezioneLabel->setMaximumSize(QSize(120,30));
    selezioneLabel->setMinimumSize(QSize(0,0));

    prezzoLabel=new QLabel(tr("Prezzo"));
    prezzoLabel->setFont(font_headerFormLabel);
    prezzoLabel->setMaximumSize(QSize(80,30));
    prezzoLabel->setMinimumSize(QSize(0,0));

    totaleLabel=new QLabel(tr("Totale"));
    totaleLabel->setFont(font_headerFormLabel);
    totaleLabel->setMaximumSize(QSize(70,30));
    totaleLabel->setMinimumSize(QSize(0,0));

    prezzoTotaleLabel=new QLabel("");
    prezzoTotaleLabel->setFont(font_formLabel);
    prezzoTotaleLabel->setMaximumSize(QSize(150,30));
    prezzoTotaleLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_ConfigurazionePCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));
}

QGridLayout* MyWidget_ConfigurazionePCBuilder::getGridLayout() const{
    return gridLayout;
}

QPushButton* MyWidget_ConfigurazionePCBuilder::getIndietroPushButton() const{
    return indietroPushButton;
}

void MyWidget_ConfigurazionePCBuilder::setNomeConfigurazioneValueLabel(const QString& nomeConfigurazione){
    nomeConfigurazioneValueLabel->setText(nomeConfigurazione);
}

void MyWidget_ConfigurazionePCBuilder::setPrezzoTotaleLabel(const QString& totale){
    prezzoTotaleLabel->setText("€ "+totale);
}
