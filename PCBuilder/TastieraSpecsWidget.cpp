#include "TastieraSpecsWidget.h"
#include <QLayout>
#include <QFont>

TastieraSpecsWidget::TastieraSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(coloreLabel,3,0,1,1);
    gridLayout->addWidget(coloreValueLabel,3,1,1,1);
    gridLayout->addWidget(retroilluminazioneLabel,4,0,1,1);
    gridLayout->addWidget(retroilluminazioneValueLabel,4,1,1,1);
    gridLayout->addWidget(connessioneLabel,5,0,1,1);
    gridLayout->addWidget(connessioneValueLabel,5,1,1,1);
    gridLayout->addWidget(tipologiaLabel,6,0,1,1);
    gridLayout->addWidget(tipologiaValueLabel,6,1,1,1);
    gridLayout->addWidget(tipologiaSwitchLabel,7,0,1,1);
    gridLayout->addWidget(tipologiaSwitchValueLabel,7,1,1,1);

    setLayout(gridLayout);
}

void TastieraSpecsWidget::createLabels(){
    QFont font_form;
    font_form.setPointSize(14);

    nomeLabel=new QLabel(tr("Nome"));
    nomeLabel->setMinimumSize(QSize(0,0));
    nomeLabel->setFont(font_form);

    nomeValueLabel=new QLabel("");
    nomeValueLabel->setMinimumSize(QSize(0,0));
    nomeValueLabel->setFont(font_form);
    nomeValueLabel->setWordWrap(true);

    produttoreLabel=new QLabel(tr("Produttore"));
    produttoreLabel->setMinimumSize(QSize(0,0));
    produttoreLabel->setFont(font_form);

    produttoreValueLabel=new QLabel("");
    produttoreValueLabel->setMinimumSize(QSize(0,0));
    produttoreValueLabel->setFont(font_form);
    produttoreValueLabel->setWordWrap(true);

    prezzoLabel=new QLabel(tr("Prezzo"));
    prezzoLabel->setMinimumSize(QSize(0,0));
    prezzoLabel->setFont(font_form);

    prezzoValueLabel=new QLabel("");
    prezzoValueLabel->setMinimumSize(QSize(0,0));
    prezzoValueLabel->setFont(font_form);
    prezzoValueLabel->setWordWrap(true);

    coloreLabel=new QLabel(tr("Colore"));
    coloreLabel->setMinimumSize(QSize(0,0));
    coloreLabel->setFont(font_form);

    coloreValueLabel=new QLabel("");
    coloreValueLabel->setMinimumSize(QSize(0,0));
    coloreValueLabel->setFont(font_form);
    coloreValueLabel->setWordWrap(true);

    retroilluminazioneLabel=new QLabel(tr("Retroilluminazione"));
    retroilluminazioneLabel->setMinimumSize(QSize(0,0));
    retroilluminazioneLabel->setFont(font_form);

    retroilluminazioneValueLabel=new QLabel("");
    retroilluminazioneValueLabel->setMinimumSize(QSize(0,0));
    retroilluminazioneValueLabel->setFont(font_form);
    retroilluminazioneValueLabel->setWordWrap(true);

    connessioneLabel=new QLabel(tr("Connessione"));
    connessioneLabel->setMinimumSize(QSize(0,0));
    connessioneLabel->setFont(font_form);

    connessioneValueLabel=new QLabel("");
    connessioneValueLabel->setMinimumSize(QSize(0,0));
    connessioneValueLabel->setFont(font_form);
    connessioneValueLabel->setWordWrap(true);

    tipologiaLabel=new QLabel(tr("Tipologia"));
    tipologiaLabel->setMinimumSize(QSize(0,0));
    tipologiaLabel->setFont(font_form);

    tipologiaValueLabel=new QLabel("");
    tipologiaValueLabel->setMinimumSize(QSize(0,0));
    tipologiaValueLabel->setFont(font_form);
    tipologiaValueLabel->setWordWrap(true);

    tipologiaSwitchLabel=new QLabel(tr("Tipologia switch"));
    tipologiaSwitchLabel->setMinimumSize(QSize(0,0));
    tipologiaSwitchLabel->setFont(font_form);

    tipologiaSwitchValueLabel=new QLabel("");
    tipologiaSwitchValueLabel->setMinimumSize(QSize(0,0));
    tipologiaSwitchValueLabel->setFont(font_form);
    tipologiaSwitchValueLabel->setWordWrap(true);
}

void TastieraSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void TastieraSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void TastieraSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void TastieraSpecsWidget::setColoreValueLabel(const QString& colore){
    coloreValueLabel->setText(colore);
}

void TastieraSpecsWidget::setRetroilluminazioneValueLabel(const QString& retroilluminazione){
    retroilluminazioneValueLabel->setText(retroilluminazione);
}

void TastieraSpecsWidget::setConnessioneValueLabel(const QString& connessione){
    connessioneValueLabel->setText(connessione);
}

void TastieraSpecsWidget::setTipologiaValueLabel(const QString& tipologia){
    tipologiaValueLabel->setText(tipologia);
}

void TastieraSpecsWidget::setTipologiaSwitchValueLabel(const QString& tipologiaSwitch){
    tipologiaSwitchValueLabel->setText(tipologiaSwitch);
}
