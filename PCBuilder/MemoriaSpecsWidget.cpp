#include "MemoriaSpecsWidget.h"
#include <QLayout>
#include <QFont>

MemoriaSpecsWidget::MemoriaSpecsWidget(QWidget* parent):QWidget(parent){
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
    gridLayout->addWidget(capacitaLabel,4,0,1,1);
    gridLayout->addWidget(capacitaValueLabel,4,1,1,1);
    gridLayout->addWidget(velocitaLabel,5,0,1,1);
    gridLayout->addWidget(velocitaValueLabel,5,1,1,1);
    gridLayout->addWidget(latenzaLabel,6,0,1,1);
    gridLayout->addWidget(latenzaValueLabel,6,1,1,1);

    setLayout(gridLayout);
}

void MemoriaSpecsWidget::createLabels(){
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

    capacitaLabel=new QLabel(tr("Capacita"));
    capacitaLabel->setMinimumSize(QSize(0,0));
    capacitaLabel->setFont(font_form);

    capacitaValueLabel=new QLabel("");
    capacitaValueLabel->setMinimumSize(QSize(0,0));
    capacitaValueLabel->setFont(font_form);
    capacitaValueLabel->setWordWrap(true);

    velocitaLabel=new QLabel(tr("Velocita"));
    velocitaLabel->setMinimumSize(QSize(0,0));
    velocitaLabel->setFont(font_form);

    velocitaValueLabel=new QLabel("");
    velocitaValueLabel->setMinimumSize(QSize(0,0));
    velocitaValueLabel->setFont(font_form);
    velocitaValueLabel->setWordWrap(true);

    latenzaLabel=new QLabel(tr("Latenza"));
    latenzaLabel->setMinimumSize(QSize(0,0));
    latenzaLabel->setFont(font_form);

    latenzaValueLabel=new QLabel("");
    latenzaValueLabel->setMinimumSize(QSize(0,0));
    latenzaValueLabel->setFont(font_form);
    latenzaValueLabel->setWordWrap(true);
}

void MemoriaSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void MemoriaSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void MemoriaSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void MemoriaSpecsWidget::setTipologiaValueLabel(const QString& tipologia){
    tipologiaValueLabel->setText(tipologia);
}

void MemoriaSpecsWidget::setCapacitaValueLabel(const QString& capacita){
    capacitaValueLabel->setText(capacita);
}

void MemoriaSpecsWidget::setVelocitaValueLabel(const QString& velocita){
    velocitaValueLabel->setText(velocita);
}

void MemoriaSpecsWidget::setLatenzaValueLabel(const QString& latenza){
    latenzaValueLabel->setText(latenza);
}
