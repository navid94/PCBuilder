#include "SchedaMadreAddWidget.h"
#include <QFont>
#include <QLayout>

SchedaMadreAddWidget::SchedaMadreAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();
    createSpinBoxes();
    createCheckBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelSchedaMadre,0,0,1,1);
    gridLayout->addWidget(nomeLineEditSchedaMadre,0,1,1,1);
    gridLayout->addWidget(prezzoLabelSchedaMadre,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxSchedaMadre,1,1,1,1);
    gridLayout->addWidget(produttoreLabelSchedaMadre,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditSchedaMadre,2,1,1,1);
    gridLayout->addWidget(fattoreDiFormaLabelSchedaMadre,3,0,1,1);
    gridLayout->addWidget(fattoreDiFormaLineEditSchedaMadre,3,1,1,1);
    gridLayout->addWidget(chipsetLabelSchedaMadre,4,0,1,1);
    gridLayout->addWidget(chipsetLineEditSchedaMadre,4,1,1,1);
    gridLayout->addWidget(socketProcessoreLabelSchedaMadre,5,0,1,1);
    gridLayout->addWidget(socketProcessoreLineEditSchedaMadre,5,1,1,1);
    gridLayout->addWidget(slotMemoriaLabelSchedaMadre,6,0,1,1);
    gridLayout->addWidget(slotMemoriaLineEditSchedaMadre,6,1,1,1);
    gridLayout->addWidget(tipologiaMemoriaLabelSchedaMadre,7,0,1,1);
    gridLayout->addWidget(tipologiaMemoriaLineEditSchedaMadre,7,1,1,1);
    gridLayout->addWidget(memoriaMassimaLabelSchedaMadre,8,0,1,1);
    gridLayout->addWidget(memoriaMassimaLineEditSchedaMadre,8,1,1,1);
    gridLayout->addWidget(supportoRAIDCheckBoxSchedaMadre,9,1,1,1);
    gridLayout->addWidget(supportoSLICheckBoxSchedaMadre,10,1,1,1);
    gridLayout->addWidget(supportoCrossfireCheckBoxSchedaMadre,11,1,1,1);
    gridLayout->addWidget(ethernetLabelSchedaMadre,12,0,1,1);
    gridLayout->addWidget(ethernetLineEditSchedaMadre,12,1,1,1);
    gridLayout->addWidget(sata3GBsLabelSchedaMadre,13,0,1,1);
    gridLayout->addWidget(sata3GBsSpinBoxSchedaMadre,13,1,1,1);
    gridLayout->addWidget(sata6GBsLabelSchedaMadre,14,0,1,1);
    gridLayout->addWidget(sata6GBsSpinBoxSchedaMadre,14,1,1,1);
    gridLayout->addWidget(sataExpressLabelSchedaMadre,15,0,1,1);
    gridLayout->addWidget(sataExpressSpinboxSchedaMadre,15,1,1,1);
    gridLayout->addWidget(usb2LabelSchedaMadre,16,0,1,1);
    gridLayout->addWidget(usb2SpinBoxSchedaMadre,16,1,1,1);
    gridLayout->addWidget(usb3LabelSchedaMadre,17,0,1,1);
    gridLayout->addWidget(usb3SpinBoxSchedaMadre,17,1,1,1);
    setLayout(gridLayout);
}

void SchedaMadreAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelSchedaMadre=new QLabel(tr("Nome:"));
    nomeLabelSchedaMadre->setFont(font_formLabel);
    nomeLabelSchedaMadre->setMaximumSize(QSize(70,30));
    nomeLabelSchedaMadre->setMinimumSize(QSize(0,0));

    prezzoLabelSchedaMadre=new QLabel("Prezzo:");
    prezzoLabelSchedaMadre->setFont(font_formLabel);
    prezzoLabelSchedaMadre->setMaximumSize(QSize(80,30));
    prezzoLabelSchedaMadre->setMinimumSize(QSize(0,0));

    produttoreLabelSchedaMadre=new QLabel(tr("Produttore:"));
    produttoreLabelSchedaMadre->setFont(font_formLabel);
    produttoreLabelSchedaMadre->setMaximumSize(QSize(110,30));
    produttoreLabelSchedaMadre->setMinimumSize(QSize(0,0));

    fattoreDiFormaLabelSchedaMadre=new QLabel(tr("Fattore di forma:"));
    fattoreDiFormaLabelSchedaMadre->setFont(font_formLabel);
    fattoreDiFormaLabelSchedaMadre->setMaximumSize(QSize(160,30));
    fattoreDiFormaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    chipsetLabelSchedaMadre=new QLabel("Chipset");
    chipsetLabelSchedaMadre->setFont(font_formLabel);
    chipsetLabelSchedaMadre->setMaximumSize(QSize(80,30));
    chipsetLabelSchedaMadre->setMinimumSize(QSize(0,0));

    socketProcessoreLabelSchedaMadre=new QLabel("Socket "+(tr("\nprocessore:")));
    socketProcessoreLabelSchedaMadre->setFont(font_formLabel);
    socketProcessoreLabelSchedaMadre->setMaximumSize(QSize(110,50));
    socketProcessoreLabelSchedaMadre->setMinimumSize(QSize(0,0));

    slotMemoriaLabelSchedaMadre=new QLabel("Slot "+(tr("memoria:")));
    slotMemoriaLabelSchedaMadre->setFont(font_formLabel);
    slotMemoriaLabelSchedaMadre->setMaximumSize(QSize(140,30));
    slotMemoriaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLabelSchedaMadre=new QLabel(tr("Tipologia \nmemoria:"));
    tipologiaMemoriaLabelSchedaMadre->setFont(font_formLabel);
    tipologiaMemoriaLabelSchedaMadre->setMaximumSize(QSize(90,50));
    tipologiaMemoriaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    memoriaMassimaLabelSchedaMadre=new QLabel(tr("Memoria massima:"));
    memoriaMassimaLabelSchedaMadre->setFont(font_formLabel);
    memoriaMassimaLabelSchedaMadre->setMaximumSize(QSize(190,30));
    memoriaMassimaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    ethernetLabelSchedaMadre=new QLabel("Ethernet");
    ethernetLabelSchedaMadre->setFont(font_formLabel);
    ethernetLabelSchedaMadre->setMaximumSize(QSize(80,30));
    ethernetLabelSchedaMadre->setMinimumSize(QSize(0,0));

    sata3GBsLabelSchedaMadre=new QLabel("SATA 3GB/s:");
    sata3GBsLabelSchedaMadre->setFont(font_formLabel);
    sata3GBsLabelSchedaMadre->setMaximumSize(QSize(120,30));
    sata3GBsLabelSchedaMadre->setMinimumSize(QSize(0,0));

    sata6GBsLabelSchedaMadre=new QLabel("SATA 6GB/s:");
    sata6GBsLabelSchedaMadre->setFont(font_formLabel);
    sata6GBsLabelSchedaMadre->setMaximumSize(QSize(120,30));
    sata6GBsLabelSchedaMadre->setMinimumSize(QSize(0,0));

    sataExpressLabelSchedaMadre=new QLabel("SATA Express:");
    sataExpressLabelSchedaMadre->setFont(font_formLabel);
    sataExpressLabelSchedaMadre->setMaximumSize(QSize(140,30));
    sataExpressLabelSchedaMadre->setMinimumSize(QSize(0,0));

    usb2LabelSchedaMadre=new QLabel("USB 2.0:");
    usb2LabelSchedaMadre->setFont(font_formLabel);
    usb2LabelSchedaMadre->setMaximumSize(QSize(80,30));
    usb2LabelSchedaMadre->setMinimumSize(QSize(0,0));

    usb3LabelSchedaMadre=new QLabel("USB 3.0:");
    usb3LabelSchedaMadre->setFont(font_formLabel);
    usb3LabelSchedaMadre->setMaximumSize(QSize(80,30));
    usb3LabelSchedaMadre->setMinimumSize(QSize(0,0));
}

void SchedaMadreAddWidget::createLineEdits(){
    nomeLineEditSchedaMadre=new QLineEdit;
    nomeLineEditSchedaMadre->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    nomeLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    produttoreLineEditSchedaMadre=new QLineEdit;
    produttoreLineEditSchedaMadre->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    produttoreLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    fattoreDiFormaLineEditSchedaMadre=new QLineEdit;
    fattoreDiFormaLineEditSchedaMadre->setPlaceholderText(tr("Inserire fattore di forma"));
    fattoreDiFormaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    fattoreDiFormaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    chipsetLineEditSchedaMadre=new QLineEdit;
    chipsetLineEditSchedaMadre->setPlaceholderText(tr("Inserire chipset"));
    chipsetLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    chipsetLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    socketProcessoreLineEditSchedaMadre=new QLineEdit;
    socketProcessoreLineEditSchedaMadre->setPlaceholderText(tr("Inserire socket processore"));
    socketProcessoreLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    socketProcessoreLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    slotMemoriaLineEditSchedaMadre=new QLineEdit;
    slotMemoriaLineEditSchedaMadre->setPlaceholderText(tr("Inserire slot memoria"));
    slotMemoriaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    slotMemoriaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLineEditSchedaMadre=new QLineEdit;
    tipologiaMemoriaLineEditSchedaMadre->setPlaceholderText(tr("Inserire tipologia memoria"));
    tipologiaMemoriaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    tipologiaMemoriaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    memoriaMassimaLineEditSchedaMadre=new QLineEdit;
    memoriaMassimaLineEditSchedaMadre->setPlaceholderText(tr("Inserire memoria massima"));
    memoriaMassimaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    memoriaMassimaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    ethernetLineEditSchedaMadre=new QLineEdit;
    ethernetLineEditSchedaMadre->setPlaceholderText(tr("Inserire ethernet"));
    ethernetLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    ethernetLineEditSchedaMadre->setMinimumSize(QSize(0,0));
}

void SchedaMadreAddWidget::createCheckBoxes(){
    supportoRAIDCheckBoxSchedaMadre=new QCheckBox(tr("Supporto ")+("RAID"));
    supportoRAIDCheckBoxSchedaMadre->setMaximumSize(QSize(110,30));
    supportoRAIDCheckBoxSchedaMadre->setMinimumSize(QSize(0,0));

    supportoCrossfireCheckBoxSchedaMadre=new QCheckBox(tr("Supporto ")+("Crossfire"));
    supportoCrossfireCheckBoxSchedaMadre->setMaximumSize(QSize(140,30));
    supportoCrossfireCheckBoxSchedaMadre->setMinimumSize(QSize(0,0));

    supportoSLICheckBoxSchedaMadre=new QCheckBox(tr("Supporto ")+("SLI"));
    supportoSLICheckBoxSchedaMadre->setMaximumSize(QSize(100,30));
    supportoSLICheckBoxSchedaMadre->setMinimumSize(QSize(0,0));
}

void SchedaMadreAddWidget::createSpinBoxes(){
    sata3GBsSpinBoxSchedaMadre=new QSpinBox;
    sata3GBsSpinBoxSchedaMadre->setMaximum(99);
    sata3GBsSpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    sata3GBsSpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    sata6GBsSpinBoxSchedaMadre=new QSpinBox;
    sata6GBsSpinBoxSchedaMadre->setMaximum(99);
    sata6GBsSpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    sata6GBsSpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    sataExpressSpinboxSchedaMadre=new QSpinBox;
    sataExpressSpinboxSchedaMadre->setMaximum(99);
    sataExpressSpinboxSchedaMadre->setMaximumSize(QSize(50,25));
    sataExpressSpinboxSchedaMadre->setMinimumSize(QSize(0,0));

    usb2SpinBoxSchedaMadre=new QSpinBox;
    usb2SpinBoxSchedaMadre->setMaximum(99);
    usb2SpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    usb2SpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    usb3SpinBoxSchedaMadre=new QSpinBox;
    usb3SpinBoxSchedaMadre->setMaximum(99);
    usb3SpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    usb3SpinBoxSchedaMadre->setMinimumSize(QSize(0,0));
}

void SchedaMadreAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxSchedaMadre=new QDoubleSpinBox;
    prezzoDoubleSpinBoxSchedaMadre->setSuffix(" €");
    prezzoDoubleSpinBoxSchedaMadre->setMaximum(9999.99);
    prezzoDoubleSpinBoxSchedaMadre->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxSchedaMadre->setMinimumSize(QSize(0,0));
}

QString SchedaMadreAddWidget::nomeSchedaMadreValue() const{
    return nomeLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::produttoreSchedaMadreValue() const{
    return produttoreLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::fattoreDiFormaSchedaMadreValue() const{
    return fattoreDiFormaLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::chipsetSchedaMadreValue() const{
    return chipsetLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::socketProcessoreSchedaMadreValue() const{
    return socketProcessoreLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::slotMemoriaSchedaMadreValue() const{
    return slotMemoriaLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::tipologiaMemoriaSchedaMadreValue() const{
    return tipologiaMemoriaLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::memoriaMassimaSchedaMadreValue() const{
    return memoriaMassimaLineEditSchedaMadre->text();
}

QString SchedaMadreAddWidget::ethernetSchedaMadreValue() const{
    return ethernetLineEditSchedaMadre->text();
}

bool SchedaMadreAddWidget::supportoRAIDSchedaMadreValue() const{
    return supportoRAIDCheckBoxSchedaMadre->isChecked();
}

bool SchedaMadreAddWidget::supportoCrossfireSchedaMadreValue() const{
    return supportoCrossfireCheckBoxSchedaMadre->isChecked();
}

bool SchedaMadreAddWidget::supportoSLISchedaMadreValue() const{
    return supportoSLICheckBoxSchedaMadre->isChecked();
}

int SchedaMadreAddWidget::sata3GBsSchedaMadreValue() const{
    return sata3GBsSpinBoxSchedaMadre->value();
}

int SchedaMadreAddWidget::sata6GBsSchedaMadreValue() const{
    return sata6GBsSpinBoxSchedaMadre->value();
}

int SchedaMadreAddWidget::sataExpressSchedaMadreValue() const{
    return sataExpressSpinboxSchedaMadre->value();
}

int SchedaMadreAddWidget::usb2SchedaMadreValue() const{
    return usb2SpinBoxSchedaMadre->value();
}

int SchedaMadreAddWidget::usb3SchedaMadreValue() const{
    return usb3SpinBoxSchedaMadre->value();
}

double SchedaMadreAddWidget::prezzoSchedaMadreValue() const{
    return prezzoDoubleSpinBoxSchedaMadre->value();
}

QLineEdit* SchedaMadreAddWidget::getNomeLineEditSchedaMadre() const{
    return nomeLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getProduttoreLineEditSchedaMadre() const{
    return produttoreLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getFattoreDiFormaLineEditSchedaMadre() const{
    return fattoreDiFormaLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getChipsetLineEditSchedaMadre() const{
    return chipsetLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getSocketProcessoreLineEditSchedaMadre() const{
    return socketProcessoreLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getSlotMemoriaLineEditSchedaMadre() const{
    return slotMemoriaLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getTipologiaMemoriaLineEditSchedaMadre() const{
    return tipologiaMemoriaLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getMemoriaMassimaLineEditSchedaMadre() const{
    return memoriaMassimaLineEditSchedaMadre;
}

QLineEdit* SchedaMadreAddWidget::getEthernetLineEditSchedaMadre() const{
    return ethernetLineEditSchedaMadre;
}

QCheckBox* SchedaMadreAddWidget::getSupportoRAIDCheckBoxSchedaMadre() const{
    return supportoRAIDCheckBoxSchedaMadre;
}

QCheckBox* SchedaMadreAddWidget::getSupportoCrossfireCheckBoxSchedaMadre() const{
    return supportoCrossfireCheckBoxSchedaMadre;
}

QCheckBox* SchedaMadreAddWidget::getSupportoSLICheckBoxSchedaMadre() const{
    return supportoSLICheckBoxSchedaMadre;
}

QSpinBox* SchedaMadreAddWidget::getSata3GBsSpinBoxSchedaMadre() const{
    return sata3GBsSpinBoxSchedaMadre;
}

QSpinBox* SchedaMadreAddWidget::getSata6GBsSpinBoxSchedaMadre() const{
    return sata6GBsSpinBoxSchedaMadre;
}

QSpinBox* SchedaMadreAddWidget::getSataExpressSpinboxSchedaMadre() const{
    return sataExpressSpinboxSchedaMadre;
}

QSpinBox* SchedaMadreAddWidget::getUsb2SpinBoxSchedaMadre() const{
    return usb2SpinBoxSchedaMadre;
}

QSpinBox* SchedaMadreAddWidget::getUsb3SpinBoxSchedaMadre() const{
    return usb3SpinBoxSchedaMadre;
}

QDoubleSpinBox* SchedaMadreAddWidget::getPrezzoDoubleSpinBoxSchedaMadre() const{
    return prezzoDoubleSpinBoxSchedaMadre;
}
