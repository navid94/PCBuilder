#include "CuffieSpecsWidget.h"
#include <QLayout>
#include <QFont>

CuffieSpecsWidget::CuffieSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(tipologiaLabel,3,0,1,1);
    gridLayout->addWidget(tipologiaValueLabel,3,1,1,1);
    gridLayout->addWidget(sistemaAcusticoLabel,4,0,1,1);
    gridLayout->addWidget(sistemaAcusticoValueLabel,4,1,1,1);
    gridLayout->addWidget(coloreLabel,5,0,1,1);
    gridLayout->addWidget(coloreValueLabel,5,1,1,1);
    gridLayout->addWidget(microfonoLabel,6,0,1,1);
    gridLayout->addWidget(microfonoValueLabel,6,1,1,1);
    gridLayout->addWidget(canaliLabel,7,0,1,1);
    gridLayout->addWidget(canaliValueLabel,7,1,1,1);
    gridLayout->addWidget(impedenzaLabel,8,0,1,1);
    gridLayout->addWidget(impedenzaValueLabel,8,1,1,1);
    gridLayout->addWidget(frequenzaDiRispostaLabel,9,0,1,1);
    gridLayout->addWidget(frequenzaDiRispostaValueLabel,9,1,1,1);
    gridLayout->addWidget(connessioneLabel,10,0,1,1);
    gridLayout->addWidget(connessioneValueLabel,10,1,1,1);
    gridLayout->addWidget(connettoreLabel,11,0,1,1);
    gridLayout->addWidget(connettoreValueLabel,11,1,1,1);

    setLayout(gridLayout);
}

void CuffieSpecsWidget::createLabels(){
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

    tipologiaLabel=new QLabel(tr("Tipologia"));
    tipologiaLabel->setMinimumSize(QSize(0,0));
    tipologiaLabel->setFont(font_form);

    tipologiaValueLabel=new QLabel("");
    tipologiaValueLabel->setMinimumSize(QSize(0,0));
    tipologiaValueLabel->setFont(font_form);
    tipologiaValueLabel->setWordWrap(true);

    sistemaAcusticoLabel=new QLabel(tr("Sistema acustico"));
    sistemaAcusticoLabel->setMinimumSize(QSize(0,0));
    sistemaAcusticoLabel->setFont(font_form);

    sistemaAcusticoValueLabel=new QLabel("");
    sistemaAcusticoValueLabel->setMinimumSize(QSize(0,0));
    sistemaAcusticoValueLabel->setFont(font_form);
    sistemaAcusticoValueLabel->setWordWrap(true);

    coloreLabel=new QLabel(tr("Colore"));
    coloreLabel->setMinimumSize(QSize(0,0));
    coloreLabel->setFont(font_form);

    coloreValueLabel=new QLabel("");
    coloreValueLabel->setMinimumSize(QSize(0,0));
    coloreValueLabel->setFont(font_form);
    coloreValueLabel->setWordWrap(true);

    microfonoLabel=new QLabel(tr("Microfono"));
    microfonoLabel->setMinimumSize(QSize(0,0));
    microfonoLabel->setFont(font_form);

    microfonoValueLabel=new QLabel("");
    microfonoValueLabel->setMinimumSize(QSize(0,0));
    microfonoValueLabel->setFont(font_form);
    microfonoValueLabel->setWordWrap(true);

    canaliLabel=new QLabel(tr("Canali"));
    canaliLabel->setMinimumSize(QSize(0,0));
    canaliLabel->setFont(font_form);

    canaliValueLabel=new QLabel("");
    canaliValueLabel->setMinimumSize(QSize(0,0));
    canaliValueLabel->setFont(font_form);
    canaliValueLabel->setWordWrap(true);

    impedenzaLabel=new QLabel(tr("Impedenza"));
    impedenzaLabel->setMinimumSize(QSize(0,0));
    impedenzaLabel->setFont(font_form);

    impedenzaValueLabel=new QLabel("");
    impedenzaValueLabel->setMinimumSize(QSize(0,0));
    impedenzaValueLabel->setFont(font_form);
    impedenzaValueLabel->setWordWrap(true);

    frequenzaDiRispostaLabel=new QLabel(tr("Frequenza di risposta0"));
    frequenzaDiRispostaLabel->setMinimumSize(QSize(0,0));
    frequenzaDiRispostaLabel->setFont(font_form);

    frequenzaDiRispostaValueLabel=new QLabel("");
    frequenzaDiRispostaValueLabel->setMinimumSize(QSize(0,0));
    frequenzaDiRispostaValueLabel->setFont(font_form);
    frequenzaDiRispostaValueLabel->setWordWrap(true);

    connessioneLabel=new QLabel(tr("Connessione"));
    connessioneLabel->setMinimumSize(QSize(0,0));
    connessioneLabel->setFont(font_form);

    connessioneValueLabel=new QLabel("");
    connessioneValueLabel->setMinimumSize(QSize(0,0));
    connessioneValueLabel->setFont(font_form);
    connessioneValueLabel->setWordWrap(true);

    connettoreLabel=new QLabel(tr("Connettore"));
    connettoreLabel->setMinimumSize(QSize(0,0));
    connettoreLabel->setFont(font_form);

    connettoreValueLabel=new QLabel("");
    connettoreValueLabel->setMinimumSize(QSize(0,0));
    connettoreValueLabel->setFont(font_form);
    connettoreValueLabel->setWordWrap(true);
}

void CuffieSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void CuffieSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void CuffieSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void CuffieSpecsWidget::setTipologiaValueLabel(const QString& tipologia){
    tipologiaValueLabel->setText(tipologia);
}

void CuffieSpecsWidget::setSistemaAcusticoValueLabel(const QString& sistemaAcustico){
    sistemaAcusticoValueLabel->setText(sistemaAcustico);
}

void CuffieSpecsWidget::setColoreValueLabel(const QString& colore){
    coloreValueLabel->setText(colore);
}

void CuffieSpecsWidget::setMicrofonoValueLabel(const QString& microfono){
    microfonoValueLabel->setText(microfono);
}

void CuffieSpecsWidget::setCanaliValueLabel(const QString& canali){
    canaliValueLabel->setText(canali);
}

void CuffieSpecsWidget::setImpedenzaValueLabel(const QString& impedenza){
    impedenzaValueLabel->setText(impedenza);
}

void CuffieSpecsWidget::setFrequenzaDiRispostaValueLabel(const QString& frequenzaDiRisposta){
    frequenzaDiRispostaValueLabel->setText(frequenzaDiRisposta);
}

void CuffieSpecsWidget::setConnessioneValueLabel(const QString& connessione){
    connessioneValueLabel->setText(connessione);
}

void CuffieSpecsWidget::setConnettoreValueLabel(const QString& connettore){
    connettoreValueLabel->setText(connettore);
}
