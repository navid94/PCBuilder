#include "SchedaGraficaSpecsWidget.h"
#include <QLayout>
#include <QFont>

SchedaGraficaSpecsWidget::SchedaGraficaSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(interfacciaLabel,3,0,1,1);
    gridLayout->addWidget(interfacciaValueLabel,3,1,1,1);
    gridLayout->addWidget(chipsetLabel,4,0,1,1);
    gridLayout->addWidget(chipsetValueLabel,4,1,1,1);
    gridLayout->addWidget(memoriaLabel,5,0,1,1);
    gridLayout->addWidget(memoriaValueLabel,5,1,1,1);
    gridLayout->addWidget(tipologiaMemoriaLabel,6,0,1,1);
    gridLayout->addWidget(tipologiaMemoriaValueLabel,6,1,1,1);
    gridLayout->addWidget(frequenzaCoreLabel,7,0,1,1);
    gridLayout->addWidget(frequenzaCoreValueLabel,7,1,1,1);
    gridLayout->addWidget(tdpLabel,8,0,1,1);
    gridLayout->addWidget(tdpValueLabel,8,1,1,1);
    gridLayout->addWidget(supportoSLILabel,9,0,1,1);
    gridLayout->addWidget(supportoSLIValueLabel,9,1,1,1);
    gridLayout->addWidget(supportoCrossfireLabel,10,0,1,1);
    gridLayout->addWidget(supportoCrossfireValueLabel,10,1,1,1);
    gridLayout->addWidget(lunghezzaLabel,11,0,1,1);
    gridLayout->addWidget(lunghezzaValueLabel,11,1,1,1);

    setLayout(gridLayout);
}

void SchedaGraficaSpecsWidget::createLabels(){
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

    interfacciaLabel=new QLabel(tr("Interfaccia"));
    interfacciaLabel->setMinimumSize(QSize(0,0));
    interfacciaLabel->setFont(font_form);

    interfacciaValueLabel=new QLabel("");
    interfacciaValueLabel->setMinimumSize(QSize(0,0));
    interfacciaValueLabel->setFont(font_form);
    interfacciaValueLabel->setWordWrap(true);

    chipsetLabel=new QLabel(tr("Chipset"));
    chipsetLabel->setMinimumSize(QSize(0,0));
    chipsetLabel->setFont(font_form);

    chipsetValueLabel=new QLabel("");
    chipsetValueLabel->setMinimumSize(QSize(0,0));
    chipsetValueLabel->setFont(font_form);
    chipsetValueLabel->setWordWrap(true);

    memoriaLabel=new QLabel(tr("Memoria"));
    memoriaLabel->setMinimumSize(QSize(0,0));
    memoriaLabel->setFont(font_form);

    memoriaValueLabel=new QLabel("");
    memoriaValueLabel->setMinimumSize(QSize(0,0));
    memoriaValueLabel->setFont(font_form);
    memoriaValueLabel->setWordWrap(true);

    tipologiaMemoriaLabel=new QLabel(tr("Tipologia memoria"));
    tipologiaMemoriaLabel->setMinimumSize(QSize(0,0));
    tipologiaMemoriaLabel->setFont(font_form);

    tipologiaMemoriaValueLabel=new QLabel("");
    tipologiaMemoriaValueLabel->setMinimumSize(QSize(0,0));
    tipologiaMemoriaValueLabel->setFont(font_form);
    tipologiaMemoriaValueLabel->setWordWrap(true);

    frequenzaCoreLabel=new QLabel(tr("Frequenza core"));
    frequenzaCoreLabel->setMinimumSize(QSize(0,0));
    frequenzaCoreLabel->setFont(font_form);

    frequenzaCoreValueLabel=new QLabel("");
    frequenzaCoreValueLabel->setMinimumSize(QSize(0,0));
    frequenzaCoreValueLabel->setFont(font_form);
    frequenzaCoreValueLabel->setWordWrap(true);

    tdpLabel=new QLabel(tr("TDP"));
    tdpLabel->setMinimumSize(QSize(0,0));
    tdpLabel->setFont(font_form);

    tdpValueLabel=new QLabel("");
    tdpValueLabel->setMinimumSize(QSize(0,0));
    tdpValueLabel->setFont(font_form);
    tdpValueLabel->setWordWrap(true);

    supportoSLILabel=new QLabel(tr("Supporto SLI"));
    supportoSLILabel->setMinimumSize(QSize(0,0));
    supportoSLILabel->setFont(font_form);

    supportoSLIValueLabel=new QLabel("");
    supportoSLIValueLabel->setMinimumSize(QSize(0,0));
    supportoSLIValueLabel->setFont(font_form);
    supportoSLIValueLabel->setWordWrap(true);

    supportoCrossfireLabel=new QLabel(tr("Supporto Crossfire"));
    supportoCrossfireLabel->setMinimumSize(QSize(0,0));
    supportoCrossfireLabel->setFont(font_form);

    supportoCrossfireValueLabel=new QLabel("");
    supportoCrossfireValueLabel->setMinimumSize(QSize(0,0));
    supportoCrossfireValueLabel->setFont(font_form);
    supportoCrossfireValueLabel->setWordWrap(true);

    lunghezzaLabel=new QLabel(tr("Lunghezza"));
    lunghezzaLabel->setMinimumSize(QSize(0,0));
    lunghezzaLabel->setFont(font_form);

    lunghezzaValueLabel=new QLabel("");
    lunghezzaValueLabel->setMinimumSize(QSize(0,0));
    lunghezzaValueLabel->setFont(font_form);
    lunghezzaValueLabel->setWordWrap(true);
}

void SchedaGraficaSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void SchedaGraficaSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void SchedaGraficaSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void SchedaGraficaSpecsWidget::setInterfacciaValueLabel(const QString& interfaccia){
    interfacciaValueLabel->setText(interfaccia);
}

void SchedaGraficaSpecsWidget::setChipsetValueLabel(const QString& chipset){
    chipsetValueLabel->setText(chipset);
}

void SchedaGraficaSpecsWidget::setMemoriaValueLabel(const QString& memoria){
    memoriaValueLabel->setText(memoria);
}

void SchedaGraficaSpecsWidget::setTipologiaMemoriaValueLabel(const QString& tipologiaMemoria){
    tipologiaMemoriaValueLabel->setText(tipologiaMemoria);
}

void SchedaGraficaSpecsWidget::setFrequenzaCoreValueLabel(const QString& frequenzaCore){
    frequenzaCoreValueLabel->setText(frequenzaCore);
}

void SchedaGraficaSpecsWidget::setTdpValueLabel(const QString& tdp){
    tdpValueLabel->setText(tdp);
}

void SchedaGraficaSpecsWidget::setSupportoSLIValueLabel(const QString& supportoSLI){
    supportoSLIValueLabel->setText(supportoSLI);
}

void SchedaGraficaSpecsWidget::setSupportoCrossfireValueLabel(const QString& supportoCrossfire){
    supportoCrossfireValueLabel->setText(supportoCrossfire);
}

void SchedaGraficaSpecsWidget::setLunghezzaValueLabel(const QString& lunghezza){
    lunghezzaValueLabel->setText(lunghezza);
}
