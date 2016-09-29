#include "ProcessoreAddWidget.h"
#include <QLayout>
#include <QFont>

ProcessoreAddWidget::ProcessoreAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createCheckBoxes();
    createSpinBoxes();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelProcessore,0,0,1,1);
    gridLayout->addWidget(nomeLineEditProcessore,0,1,1,1);
    gridLayout->addWidget(prezzoLabelProcessore,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxProcessore,1,1,1,1);
    gridLayout->addWidget(produttoreLabelProcessore,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditProcessore,2,1,1,1);
    gridLayout->addWidget(socketLabelProcessore,3,0,1,1);
    gridLayout->addWidget(socketLineEditProcessore,3,1,1,1);
    gridLayout->addWidget(larghezzaDatiLabelProcessore,4,0,1,1);
    gridLayout->addWidget(larghezzaDatiLineEditProcessore,4,1,1,1);
    gridLayout->addWidget(frequenzaOperativaLabelProcessore,5,0,1,1);
    gridLayout->addWidget(frequenzaOperativaLineEditProcessore,5,1,1,1);
    gridLayout->addWidget(frequenzaTurboLabelProcessore,6,0,1,1);
    gridLayout->addWidget(frequenzaTurboLineEditProcessore,6,1,1,1);
    gridLayout->addWidget(numeroCoreLabelProcessore,7,0,1,1);
    gridLayout->addWidget(numeroCoreSpinBoxProcessore,7,1,1,1);
    gridLayout->addWidget(includeDissipatoreCheckBoxProcessore,8,1,1,1);
    gridLayout->addWidget(hyperThreadingCheckBoxProcessore,9,1,1,1);
    gridLayout->addWidget(l1CacheLabelProcessore,10,0,1,1);
    gridLayout->addWidget(l1CacheLineEditProcessore,10,1,1,1);
    gridLayout->addWidget(l2CacheLabelProcessore,11,0,1,1);
    gridLayout->addWidget(l2CacheLineEditProcessore,11,1,1,1);
    gridLayout->addWidget(l3CacheLabelProcessore,12,0,1,1);
    gridLayout->addWidget(l3CacheLineEditProcessore,12,1,1,1);
    gridLayout->addWidget(litografiaLabelProcessore,13,0,1,1);
    gridLayout->addWidget(litografiaLineEditProcessore,13,1,1,1);
    gridLayout->addWidget(tdpLabelProcessore,14,0,1,1);
    gridLayout->addWidget(tdpLineEditProcessore,14,1,1,1);
    gridLayout->addWidget(graficaIntegrataLabelProcessore,15,0,1,1);
    gridLayout->addWidget(graficaIntegrataLineEditProcessore,15,1,1,1);
    setLayout(gridLayout);
}

void ProcessoreAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelProcessore=new QLabel(tr("Nome:"));
    nomeLabelProcessore->setFont(font_formLabel);
    nomeLabelProcessore->setMaximumSize(QSize(70,30));
    nomeLabelProcessore->setMinimumSize(QSize(0,0));

    prezzoLabelProcessore=new QLabel(tr("Prezzo:"));
    prezzoLabelProcessore->setFont(font_formLabel);
    prezzoLabelProcessore->setMaximumSize(QSize(80,30));
    prezzoLabelProcessore->setMinimumSize(QSize(0,0));

    produttoreLabelProcessore=new QLabel(tr("Produttore:"));
    produttoreLabelProcessore->setFont(font_formLabel);
    produttoreLabelProcessore->setMaximumSize(QSize(110,30));
    produttoreLabelProcessore->setMinimumSize(QSize(0,0));

    socketLabelProcessore=new QLabel("Socket "+(tr("processore:")));
    socketLabelProcessore->setFont(font_formLabel);
    socketLabelProcessore->setMaximumSize(QSize(70,30));
    socketLabelProcessore->setMinimumSize(QSize(0,0));

    larghezzaDatiLabelProcessore=new QLabel(tr("Larghezza dati:"));
    larghezzaDatiLabelProcessore->setFont(font_formLabel);
    larghezzaDatiLabelProcessore->setMaximumSize(QSize(150,30));
    larghezzaDatiLabelProcessore->setMinimumSize(QSize(0,0));

    frequenzaOperativaLabelProcessore=new QLabel(tr("Frequenza operativa:"));
    frequenzaOperativaLabelProcessore->setFont(font_formLabel);
    frequenzaOperativaLabelProcessore->setMaximumSize(QSize(200,30));
    frequenzaOperativaLabelProcessore->setMinimumSize(QSize(0,0));

    frequenzaTurboLabelProcessore=new QLabel(tr("Frequenza turbo:"));
    frequenzaTurboLabelProcessore->setFont(font_formLabel);
    frequenzaTurboLabelProcessore->setMaximumSize(QSize(170,30));
    frequenzaTurboLabelProcessore->setMinimumSize(QSize(0,0));

    numeroCoreLabelProcessore=new QLabel(tr("Numero ")+("core:"));
    numeroCoreLabelProcessore->setFont(font_formLabel);
    numeroCoreLabelProcessore->setMaximumSize(QSize(130,30));
    numeroCoreLabelProcessore->setMinimumSize(QSize(0,0));

    l1CacheLabelProcessore=new QLabel("L1 Cache:");
    l1CacheLabelProcessore->setFont(font_formLabel);
    l1CacheLabelProcessore->setMaximumSize(QSize(100,30));
    l1CacheLabelProcessore->setMinimumSize(QSize(0,0));

    l2CacheLabelProcessore=new QLabel("L2 Cache:");
    l2CacheLabelProcessore->setFont(font_formLabel);
    l2CacheLabelProcessore->setMaximumSize(QSize(100,30));
    l2CacheLabelProcessore->setMinimumSize(QSize(0,0));

    l3CacheLabelProcessore=new QLabel("L3 Cache:");
    l3CacheLabelProcessore->setFont(font_formLabel);
    l3CacheLabelProcessore->setMaximumSize(QSize(100,30));
    l3CacheLabelProcessore->setMinimumSize(QSize(0,0));

    litografiaLabelProcessore=new QLabel(tr("Litografia:"));
    litografiaLabelProcessore->setFont(font_formLabel);
    litografiaLabelProcessore->setMaximumSize(QSize(100,30));
    litografiaLabelProcessore->setMinimumSize(QSize(0,0));

    tdpLabelProcessore=new QLabel("TDP:");
    tdpLabelProcessore->setFont(font_formLabel);
    tdpLabelProcessore->setMaximumSize(QSize(50,30));
    tdpLabelProcessore->setMinimumSize(QSize(0,0));

    graficaIntegrataLabelProcessore=new QLabel(tr("Grafica integrata:"));
    graficaIntegrataLabelProcessore->setFont(font_formLabel);
    graficaIntegrataLabelProcessore->setMaximumSize(QSize(170,30));
    graficaIntegrataLabelProcessore->setMinimumSize(QSize(0,0));
}

void ProcessoreAddWidget::createLineEdits(){
    nomeLineEditProcessore=new QLineEdit;
    nomeLineEditProcessore->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditProcessore->setMaximumSize(QSize(200,30));
    nomeLineEditProcessore->setMinimumSize(QSize(0,0));

    produttoreLineEditProcessore=new QLineEdit;
    produttoreLineEditProcessore->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditProcessore->setMaximumSize(QSize(200,30));
    produttoreLineEditProcessore->setMinimumSize(QSize(0,0));

    socketLineEditProcessore=new QLineEdit;
    socketLineEditProcessore->setPlaceholderText(tr("Inserire socket"));
    socketLineEditProcessore->setMaximumSize(QSize(200,30));
    socketLineEditProcessore->setMinimumSize(QSize(0,0));

    larghezzaDatiLineEditProcessore=new QLineEdit;
    larghezzaDatiLineEditProcessore->setPlaceholderText(tr("Inserire larghezza dati"));
    larghezzaDatiLineEditProcessore->setMaximumSize(QSize(200,30));
    larghezzaDatiLineEditProcessore->setMinimumSize(QSize(0,0));

    frequenzaOperativaLineEditProcessore=new QLineEdit;
    frequenzaOperativaLineEditProcessore->setPlaceholderText(tr("Inserire frequenza operativa"));
    frequenzaOperativaLineEditProcessore->setMaximumSize(QSize(200,30));
    frequenzaOperativaLineEditProcessore->setMinimumSize(QSize(0,0));

    frequenzaTurboLineEditProcessore=new QLineEdit;
    frequenzaTurboLineEditProcessore->setPlaceholderText(tr("Inserire frequenza turbo"));
    frequenzaTurboLineEditProcessore->setMaximumSize(QSize(200,30));
    frequenzaTurboLineEditProcessore->setMinimumSize(QSize(0,0));

    l1CacheLineEditProcessore=new QLineEdit;
    l1CacheLineEditProcessore->setPlaceholderText(tr("Inserire L1Cache"));
    l1CacheLineEditProcessore->setMaximumSize(QSize(200,30));
    l1CacheLineEditProcessore->setMinimumSize(QSize(0,0));

    l2CacheLineEditProcessore=new QLineEdit;
    l2CacheLineEditProcessore->setPlaceholderText(tr("Inserire L2Cache"));
    l2CacheLineEditProcessore->setMaximumSize(QSize(200,30));
    l2CacheLineEditProcessore->setMinimumSize(QSize(0,0));

    l3CacheLineEditProcessore=new QLineEdit;
    l3CacheLineEditProcessore->setPlaceholderText(tr("Inserire L3Cache"));
    l3CacheLineEditProcessore->setMaximumSize(QSize(200,30));
    l3CacheLineEditProcessore->setMinimumSize(QSize(0,0));

    litografiaLineEditProcessore=new QLineEdit;
    litografiaLineEditProcessore->setPlaceholderText(tr("Inserire litografia"));
    litografiaLineEditProcessore->setMaximumSize(QSize(200,30));
    litografiaLineEditProcessore->setMinimumSize(QSize(0,0));

    tdpLineEditProcessore=new QLineEdit;
    tdpLineEditProcessore->setPlaceholderText(tr("Inserire TDP"));
    tdpLineEditProcessore->setMaximumSize(QSize(200,30));
    tdpLineEditProcessore->setMinimumSize(QSize(0,0));

    graficaIntegrataLineEditProcessore=new QLineEdit;
    graficaIntegrataLineEditProcessore->setPlaceholderText(tr("Inserire grafica integrata"));
    graficaIntegrataLineEditProcessore->setMaximumSize(QSize(200,30));
    graficaIntegrataLineEditProcessore->setMinimumSize(QSize(0,0));
}

void ProcessoreAddWidget::createSpinBoxes(){
    numeroCoreSpinBoxProcessore=new QSpinBox;
    numeroCoreSpinBoxProcessore->setMaximum(99);
    numeroCoreSpinBoxProcessore->setMaximumSize(QSize(50,25));
    numeroCoreSpinBoxProcessore->setMinimumSize(QSize(0,0));
}

void ProcessoreAddWidget::createCheckBoxes(){
    includeDissipatoreCheckBoxProcessore=new QCheckBox(tr("Include dissipatore processore"));
    includeDissipatoreCheckBoxProcessore->setMaximumSize(QSize(210,30));
    includeDissipatoreCheckBoxProcessore->setMinimumSize(QSize(0,0));

    hyperThreadingCheckBoxProcessore=new QCheckBox("Hyper-Threading");
    hyperThreadingCheckBoxProcessore->setMaximumSize(QSize(120,30));
    hyperThreadingCheckBoxProcessore->setMinimumSize(QSize(0,0));
}

void ProcessoreAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxProcessore=new QDoubleSpinBox;
    prezzoDoubleSpinBoxProcessore->setSuffix(" €");
    prezzoDoubleSpinBoxProcessore->setMaximum(9999.99);
    prezzoDoubleSpinBoxProcessore->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxProcessore->setMinimumSize(QSize(0,0));
}


QString ProcessoreAddWidget::nomeProcessoreValue() const{
    return nomeLineEditProcessore->text();
}

QString ProcessoreAddWidget::produttoreProcessoreValue() const{
    return produttoreLineEditProcessore->text();
}

QString ProcessoreAddWidget::socketProcessoreValue() const{
    return socketLineEditProcessore->text();
}

QString ProcessoreAddWidget::larghezzaDatiProcessoreValue() const{
    return larghezzaDatiLineEditProcessore->text();
}

QString ProcessoreAddWidget::frequenzaOperativaProcessoreValue() const{
    return frequenzaOperativaLineEditProcessore->text();
}

QString ProcessoreAddWidget::frequenzaTurboProcessoreValue() const{
    return frequenzaTurboLineEditProcessore->text();
}

QString ProcessoreAddWidget::l1CacheProcessoreValue() const{
    return l1CacheLineEditProcessore->text();
}

QString ProcessoreAddWidget::l2CacheProcessoreValue() const{
    return l2CacheLineEditProcessore->text();
}

QString ProcessoreAddWidget::l3CacheProcessoreValue() const{
    return l3CacheLineEditProcessore->text();
}

QString ProcessoreAddWidget::litografiaProcessoreValue() const{
    return litografiaLineEditProcessore->text();
}

QString ProcessoreAddWidget::tdpProcessoreValue() const{
    return tdpLineEditProcessore->text();
}

QString ProcessoreAddWidget::graficaIntegrataProcessoreValue() const{
    return graficaIntegrataLineEditProcessore->text();
}

bool ProcessoreAddWidget::includeDissipatoreProcessoreValue() const{
    return includeDissipatoreCheckBoxProcessore->isChecked();
}

bool ProcessoreAddWidget::hyperThreadingProcessoreValue() const{
    return hyperThreadingCheckBoxProcessore->isChecked();
}

int ProcessoreAddWidget::numeroCoreProcessoreValue() const{
    return numeroCoreSpinBoxProcessore->value();
}

double ProcessoreAddWidget::prezzoProcessoreValue() const{
    return prezzoDoubleSpinBoxProcessore->value();
}

QLineEdit* ProcessoreAddWidget::getNomeLineEditProcessore() const{
    return nomeLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getProduttoreLineEditProcessore() const{
    return produttoreLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getSocketLineEditProcessore() const{
    return socketLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getLarghezzaDatiLineEditProcessore() const{
    return larghezzaDatiLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getFrequenzaOperativaLineEditProcessore() const{
    return frequenzaOperativaLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getFrequenzaTurboLineEditProcessore() const{
    return frequenzaTurboLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getL1CacheLineEditProcessore() const{
    return l1CacheLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getL2CacheLineEditProcessore() const{
    return l2CacheLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getL3CacheLineEditProcessore() const{
    return l3CacheLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getLitografiaLineEditProcessore() const{
    return litografiaLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getTdpLineEditProcessore() const{
    return tdpLineEditProcessore;
}

QLineEdit* ProcessoreAddWidget::getGraficaIntegrataLineEditProcessore() const{
    return graficaIntegrataLineEditProcessore;
}

QCheckBox* ProcessoreAddWidget::getIncludeDissipatoreCheckBoxProcessore() const{
    return includeDissipatoreCheckBoxProcessore;
}

QCheckBox* ProcessoreAddWidget::getHyperThreadingCheckBoxProcessore() const{
    return hyperThreadingCheckBoxProcessore;
}

QSpinBox* ProcessoreAddWidget::getNumeroCoreSpinBoxProcessore() const{
    return numeroCoreSpinBoxProcessore;
}

QDoubleSpinBox* ProcessoreAddWidget::getPrezzoDoubleSpinBoxProcessore() const{
    return prezzoDoubleSpinBoxProcessore;
}
