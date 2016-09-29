#include "ProcessoreSpecsWidget.h"
#include <QLayout>
#include <QFont>

ProcessoreSpecsWidget::ProcessoreSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(socketLabel,3,0,1,1);
    gridLayout->addWidget(socketValueLabel,3,1,1,1);
    gridLayout->addWidget(larghezzaDatiLabel,4,0,1,1);
    gridLayout->addWidget(larghezzaDatiValueLabel,4,1,1,1);
    gridLayout->addWidget(frequenzaOperativaLabel,5,0,1,1);
    gridLayout->addWidget(frequenzaOperativaValueLabel,5,1,1,1);
    gridLayout->addWidget(frequenzaTurboLabel,6,0,1,1);
    gridLayout->addWidget(frequenzaTurboValueLabel,6,1,1,1);
    gridLayout->addWidget(numeroCoreLabel,7,0,1,1);
    gridLayout->addWidget(numeroCoreValueLabel,7,1,1,1);
    gridLayout->addWidget(l1CacheLabel,8,0,1,1);
    gridLayout->addWidget(l1CacheValueLabel,8,1,1,1);
    gridLayout->addWidget(l2CacheLabel,9,0,1,1);
    gridLayout->addWidget(l2CacheValueLabel,9,1,1,1);
    gridLayout->addWidget(l3CacheLabel,10,0,1,1);
    gridLayout->addWidget(l3CacheValueLabel,10,1,1,1);
    gridLayout->addWidget(litografiaLabel,11,0,1,1);
    gridLayout->addWidget(litografiaValueLabel,11,1,1,1);
    gridLayout->addWidget(tdpLabel,12,0,1,1);
    gridLayout->addWidget(tdpValueLabel,12,1,1,1);
    gridLayout->addWidget(includeDissipatoreLabel,13,0,1,1);
    gridLayout->addWidget(includeDissipatoreValueLabel,13,1,1,1);
    gridLayout->addWidget(hyperThreadingLabel,14,0,1,1);
    gridLayout->addWidget(hyperThreadingValueLabel,14,1,1,1);
    gridLayout->addWidget(graficaIntegrataLabel,15,0,1,1);
    gridLayout->addWidget(graficaIntegrataValueLabel,15,1,1,1);

    setLayout(gridLayout);
}

void ProcessoreSpecsWidget::createLabels(){
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

    socketLabel=new QLabel(tr("Socket"));
    socketLabel->setMinimumSize(QSize(0,0));
    socketLabel->setFont(font_form);

    socketValueLabel=new QLabel("");
    socketValueLabel->setMinimumSize(QSize(0,0));
    socketValueLabel->setFont(font_form);
    socketValueLabel->setWordWrap(true);

    larghezzaDatiLabel=new QLabel(tr("Larghezza dati"));
    larghezzaDatiLabel->setMinimumSize(QSize(0,0));
    larghezzaDatiLabel->setFont(font_form);

    larghezzaDatiValueLabel=new QLabel("");
    larghezzaDatiValueLabel->setMinimumSize(QSize(0,0));
    larghezzaDatiValueLabel->setFont(font_form);
    larghezzaDatiValueLabel->setWordWrap(true);

    frequenzaOperativaLabel=new QLabel(tr("Frequenza operativa"));
    frequenzaOperativaLabel->setMinimumSize(QSize(0,0));
    frequenzaOperativaLabel->setFont(font_form);

    frequenzaOperativaValueLabel=new QLabel("");
    frequenzaOperativaValueLabel->setMinimumSize(QSize(0,0));
    frequenzaOperativaValueLabel->setFont(font_form);
    frequenzaOperativaValueLabel->setWordWrap(true);

    frequenzaTurboLabel=new QLabel(tr("Frequenza turbo"));
    frequenzaTurboLabel->setMinimumSize(QSize(0,0));
    frequenzaTurboLabel->setFont(font_form);

    frequenzaTurboValueLabel=new QLabel("");
    frequenzaTurboValueLabel->setMinimumSize(QSize(0,0));
    frequenzaTurboValueLabel->setFont(font_form);
    frequenzaTurboValueLabel->setWordWrap(true);

    numeroCoreLabel=new QLabel(tr("Numero core"));
    numeroCoreLabel->setMinimumSize(QSize(0,0));
    numeroCoreLabel->setFont(font_form);

    numeroCoreValueLabel=new QLabel("");
    numeroCoreValueLabel->setMinimumSize(QSize(0,0));
    numeroCoreValueLabel->setFont(font_form);
    numeroCoreValueLabel->setWordWrap(true);

    l1CacheLabel=new QLabel(tr("L1 Cache"));
    l1CacheLabel->setMinimumSize(QSize(0,0));
    l1CacheLabel->setFont(font_form);

    l1CacheValueLabel=new QLabel("");
    l1CacheValueLabel->setMinimumSize(QSize(0,0));
    l1CacheValueLabel->setFont(font_form);
    l1CacheValueLabel->setWordWrap(true);

    l2CacheLabel=new QLabel(tr("L2 Cache"));
    l2CacheLabel->setMinimumSize(QSize(0,0));
    l2CacheLabel->setFont(font_form);

    l2CacheValueLabel=new QLabel("");
    l2CacheValueLabel->setMinimumSize(QSize(0,0));
    l2CacheValueLabel->setFont(font_form);
    l2CacheValueLabel->setWordWrap(true);

    l3CacheLabel=new QLabel(tr("L3 Cache"));
    l3CacheLabel->setMinimumSize(QSize(0,0));
    l3CacheLabel->setFont(font_form);

    l3CacheValueLabel=new QLabel("");
    l3CacheValueLabel->setMinimumSize(QSize(0,0));
    l3CacheValueLabel->setFont(font_form);
    l3CacheValueLabel->setWordWrap(true);

    litografiaLabel=new QLabel(tr("Litografia"));
    litografiaLabel->setMinimumSize(QSize(0,0));
    litografiaLabel->setFont(font_form);

    litografiaValueLabel=new QLabel("");
    litografiaValueLabel->setMinimumSize(QSize(0,0));
    litografiaValueLabel->setFont(font_form);
    litografiaValueLabel->setWordWrap(true);

    tdpLabel=new QLabel(tr("TDP"));
    tdpLabel->setMinimumSize(QSize(0,0));
    tdpLabel->setFont(font_form);

    tdpValueLabel=new QLabel("");
    tdpValueLabel->setMinimumSize(QSize(0,0));
    tdpValueLabel->setFont(font_form);
    tdpValueLabel->setWordWrap(true);

    includeDissipatoreLabel=new QLabel(tr("Include dissipatore"));
    includeDissipatoreLabel->setMinimumSize(QSize(0,0));
    includeDissipatoreLabel->setFont(font_form);

    includeDissipatoreValueLabel=new QLabel("");
    includeDissipatoreValueLabel->setMinimumSize(QSize(0,0));
    includeDissipatoreValueLabel->setFont(font_form);
    includeDissipatoreValueLabel->setWordWrap(true);

    hyperThreadingLabel=new QLabel(tr("Hyper-threading"));
    hyperThreadingLabel->setMinimumSize(QSize(0,0));
    hyperThreadingLabel->setFont(font_form);

    hyperThreadingValueLabel=new QLabel("");
    hyperThreadingValueLabel->setMinimumSize(QSize(0,0));
    hyperThreadingValueLabel->setFont(font_form);
    hyperThreadingValueLabel->setWordWrap(true);

    graficaIntegrataLabel=new QLabel(tr("Grafica integrata"));
    graficaIntegrataLabel->setMinimumSize(QSize(0,0));
    graficaIntegrataLabel->setFont(font_form);

    graficaIntegrataValueLabel=new QLabel("");
    graficaIntegrataValueLabel->setMinimumSize(QSize(0,0));
    graficaIntegrataValueLabel->setFont(font_form);
    graficaIntegrataValueLabel->setWordWrap(true);
}

void ProcessoreSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void ProcessoreSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void ProcessoreSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void ProcessoreSpecsWidget::setSocketValueLabel(const QString& socket){
    socketValueLabel->setText(socket);
}

void ProcessoreSpecsWidget::setLarghezzaDatiValueLabel(const QString& larghezzaDati){
    larghezzaDatiValueLabel->setText(larghezzaDati);
}

void ProcessoreSpecsWidget::setFrequenzaOperativaValueLabel(const QString& frequenzaOperativa){
    frequenzaOperativaValueLabel->setText(frequenzaOperativa);
}

void ProcessoreSpecsWidget::setFrequenzaTurboValueLabel(const QString& frequenzaTurbo){
    frequenzaTurboValueLabel->setText(frequenzaTurbo);
}

void ProcessoreSpecsWidget::setNumeroCoreValueLabel(const QString& numeroCore){
    numeroCoreValueLabel->setText(numeroCore);
}

void ProcessoreSpecsWidget::setL1CacheValueLabel(const QString& l1Cache){
    l1CacheValueLabel->setText(l1Cache);
}

void ProcessoreSpecsWidget::setL2CacheValueLabel(const QString& l2Cache){
    l2CacheValueLabel->setText(l2Cache);
}

void ProcessoreSpecsWidget::setL3CacheValueLabel(const QString& l3Cache){
    l3CacheValueLabel->setText(l3Cache);
}

void ProcessoreSpecsWidget::setLitografiaValueLabel(const QString& litografia){
    litografiaValueLabel->setText(litografia);
}

void ProcessoreSpecsWidget::setTdpValueLabel(const QString& tdp){
    tdpValueLabel->setText(tdp);
}

void ProcessoreSpecsWidget::setIncludeDissipatoreValueLabel(const QString& includeDissipatore){
    includeDissipatoreValueLabel->setText(includeDissipatore);
}

void ProcessoreSpecsWidget::setHyperThreadingValueLabel(const QString& hyperThreading){
    hyperThreadingValueLabel->setText(hyperThreading);
}

void ProcessoreSpecsWidget::setGraficaIntegrataValueLabel(const QString& graficaIntegrata){
    graficaIntegrataValueLabel->setText(graficaIntegrata);
}
