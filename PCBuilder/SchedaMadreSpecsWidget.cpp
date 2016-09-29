#include "SchedaMadreSpecsWidget.h"
#include <QLayout>
#include <QFont>

SchedaMadreSpecsWidget::SchedaMadreSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(fattoreDiFormaLabel,3,0,1,1);
    gridLayout->addWidget(fattoreDiFormaValueLabel,3,1,1,1);
    gridLayout->addWidget(chipsetLabel,4,0,1,1);
    gridLayout->addWidget(chipsetValueLabel,4,1,1,1);
    gridLayout->addWidget(socketProcessoreLabel,5,0,1,1);
    gridLayout->addWidget(socketProcessoreValueLabel,5,1,1,1);
    gridLayout->addWidget(slotMemoriaLabel,6,0,1,1);
    gridLayout->addWidget(slotMemoriaValueLabel,6,1,1,1);
    gridLayout->addWidget(tipologiaMemoriaLabel,7,0,1,1);
    gridLayout->addWidget(tipologiaMemoriaValueLabel,7,1,1,1);
    gridLayout->addWidget(memoriaMassimaLabel,8,0,1,1);
    gridLayout->addWidget(memoriaMassimaValueLabel,8,1,1,1);
    gridLayout->addWidget(supportoRAIDLabel,9,0,1,1);
    gridLayout->addWidget(supportoRAIDValueLabel,9,1,1,1);
    gridLayout->addWidget(supportoCrossfireLabel,10,0,1,1);
    gridLayout->addWidget(supportoCrossfireValueLabel,10,1,1,1);
    gridLayout->addWidget(supportoSLILabel,11,0,1,1);
    gridLayout->addWidget(supportoSLIValueLabel,11,1,1,1);
    gridLayout->addWidget(ethernetLabel,12,0,1,1);
    gridLayout->addWidget(ethernetValueLabel,12,1,1,1);
    gridLayout->addWidget(sata3GBsLabel,13,0,1,1);
    gridLayout->addWidget(sata3GBsValueLabel,13,1,1,1);
    gridLayout->addWidget(sata6GBsLabel,14,0,1,1);
    gridLayout->addWidget(sata6GBsValueLabel,14,1,1,1);
    gridLayout->addWidget(sataExpressLabel,15,0,1,1);
    gridLayout->addWidget(sataExpressValueLabel,15,1,1,1);
    gridLayout->addWidget(usb2Label,16,0,1,1);
    gridLayout->addWidget(usb2ValueLabel,16,1,1,1);
    gridLayout->addWidget(usb3Label,17,0,1,1);
    gridLayout->addWidget(usb3ValueLabel,17,1,1,1);

    setLayout(gridLayout);
}

void SchedaMadreSpecsWidget::createLabels(){
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

    fattoreDiFormaLabel=new QLabel(tr("Fattore di forma"));
    fattoreDiFormaLabel->setMinimumSize(QSize(0,0));
    fattoreDiFormaLabel->setFont(font_form);

    fattoreDiFormaValueLabel=new QLabel("");
    fattoreDiFormaValueLabel->setMinimumSize(QSize(0,0));
    fattoreDiFormaValueLabel->setFont(font_form);
    fattoreDiFormaValueLabel->setWordWrap(true);

    chipsetLabel=new QLabel(tr("Chipset"));
    chipsetLabel->setMinimumSize(QSize(0,0));
    chipsetLabel->setFont(font_form);

    chipsetValueLabel=new QLabel("");
    chipsetValueLabel->setMinimumSize(QSize(0,0));
    chipsetValueLabel->setFont(font_form);
    nomeValueLabel->setWordWrap(true);

    socketProcessoreLabel=new QLabel(tr("Socket processore"));
    socketProcessoreLabel->setMinimumSize(QSize(0,0));
    socketProcessoreLabel->setFont(font_form);

    socketProcessoreValueLabel=new QLabel("");
    socketProcessoreValueLabel->setMinimumSize(QSize(0,0));
    socketProcessoreValueLabel->setFont(font_form);
    socketProcessoreValueLabel->setWordWrap(true);

    slotMemoriaLabel=new QLabel(tr("Slot memoria"));
    slotMemoriaLabel->setMinimumSize(QSize(0,0));
    slotMemoriaLabel->setFont(font_form);

    slotMemoriaValueLabel=new QLabel("");
    slotMemoriaValueLabel->setMinimumSize(QSize(0,0));
    slotMemoriaValueLabel->setFont(font_form);
    slotMemoriaValueLabel->setWordWrap(true);

    tipologiaMemoriaLabel=new QLabel(tr("Tipologia memoria"));
    tipologiaMemoriaLabel->setMinimumSize(QSize(0,0));
    tipologiaMemoriaLabel->setFont(font_form);

    tipologiaMemoriaValueLabel=new QLabel("");
    tipologiaMemoriaValueLabel->setMinimumSize(QSize(0,0));
    tipologiaMemoriaValueLabel->setFont(font_form);
    tipologiaMemoriaValueLabel->setWordWrap(true);

    memoriaMassimaLabel=new QLabel(tr("Memoria massima"));
    memoriaMassimaLabel->setMinimumSize(QSize(0,0));
    memoriaMassimaLabel->setFont(font_form);

    memoriaMassimaValueLabel=new QLabel("");
    memoriaMassimaValueLabel->setMinimumSize(QSize(0,0));
    memoriaMassimaValueLabel->setFont(font_form);
    memoriaMassimaValueLabel->setWordWrap(true);

    supportoRAIDLabel=new QLabel(tr("Supporto RAID"));
    supportoRAIDLabel->setMinimumSize(QSize(0,0));
    supportoRAIDLabel->setFont(font_form);

    supportoRAIDValueLabel=new QLabel("");
    supportoRAIDValueLabel->setMinimumSize(QSize(0,0));
    supportoRAIDValueLabel->setFont(font_form);
    supportoRAIDValueLabel->setWordWrap(true);

    supportoCrossfireLabel=new QLabel(tr("Supporto Crossfire"));
    supportoCrossfireLabel->setMinimumSize(QSize(0,0));
    supportoCrossfireLabel->setFont(font_form);

    supportoCrossfireValueLabel=new QLabel("");
    supportoCrossfireValueLabel->setMinimumSize(QSize(0,0));
    supportoCrossfireValueLabel->setFont(font_form);
    supportoCrossfireValueLabel->setWordWrap(true);

    supportoSLILabel=new QLabel(tr("Supporto SLI"));
    supportoSLILabel->setMinimumSize(QSize(0,0));
    supportoSLILabel->setFont(font_form);

    supportoSLIValueLabel=new QLabel("");
    supportoSLIValueLabel->setMinimumSize(QSize(0,0));
    supportoSLIValueLabel->setFont(font_form);
    supportoSLIValueLabel->setWordWrap(true);

    ethernetLabel=new QLabel(tr("Ethernet"));
    ethernetLabel->setMinimumSize(QSize(0,0));
    ethernetLabel->setFont(font_form);

    ethernetValueLabel=new QLabel("");
    ethernetValueLabel->setMinimumSize(QSize(0,0));
    ethernetValueLabel->setFont(font_form);
    ethernetValueLabel->setWordWrap(true);

    sata3GBsLabel=new QLabel(tr("SATA 3GB/s"));
    sata3GBsLabel->setMinimumSize(QSize(0,0));
    sata3GBsLabel->setFont(font_form);

    sata3GBsValueLabel=new QLabel("");
    sata3GBsValueLabel->setMinimumSize(QSize(0,0));
    sata3GBsValueLabel->setFont(font_form);
    sata3GBsValueLabel->setWordWrap(true);

    sata6GBsLabel=new QLabel(tr("SATA 6GB/s"));
    sata6GBsLabel->setMinimumSize(QSize(0,0));
    sata6GBsLabel->setFont(font_form);

    sata6GBsValueLabel=new QLabel("");
    sata6GBsValueLabel->setMinimumSize(QSize(0,0));
    sata6GBsValueLabel->setFont(font_form);
    sata6GBsValueLabel->setWordWrap(true);

    sataExpressLabel=new QLabel(tr("SATA Express"));
    sataExpressLabel->setMinimumSize(QSize(0,0));
    sataExpressLabel->setFont(font_form);

    sataExpressValueLabel=new QLabel("");
    sataExpressValueLabel->setMinimumSize(QSize(0,0));
    sataExpressValueLabel->setFont(font_form);
    sataExpressValueLabel->setWordWrap(true);

    usb2Label=new QLabel(tr("UBS 2.0"));
    usb2Label->setMinimumSize(QSize(0,0));
    usb2Label->setFont(font_form);

    usb2ValueLabel=new QLabel("");
    usb2ValueLabel->setMinimumSize(QSize(0,0));
    usb2ValueLabel->setFont(font_form);
    usb2ValueLabel->setWordWrap(true);

    usb3Label=new QLabel(tr("USB 3.0"));
    usb3Label->setMinimumSize(QSize(0,0));
    usb3Label->setFont(font_form);

    usb3ValueLabel=new QLabel("");
    usb3ValueLabel->setMinimumSize(QSize(0,0));
    usb3ValueLabel->setFont(font_form);
    usb3ValueLabel->setWordWrap(true);
}

void SchedaMadreSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void SchedaMadreSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void SchedaMadreSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void SchedaMadreSpecsWidget::setFattoreDiFormaValueLabel(const QString& fattoreDiForma){
    fattoreDiFormaValueLabel->setText(fattoreDiForma);
}

void SchedaMadreSpecsWidget::setChipsetValueLabel(const QString& chipset){
    chipsetValueLabel->setText(chipset);
}

void SchedaMadreSpecsWidget::setSocketProcessoreValueLabel(const QString& socketProcessore){
    socketProcessoreValueLabel->setText(socketProcessore);
}

void SchedaMadreSpecsWidget::setSlotMemoriaValueLabel(const QString& slotMemoria){
    slotMemoriaValueLabel->setText(slotMemoria);
}

void SchedaMadreSpecsWidget::setTipologiaMemoriaValueLabel(const QString& tipologiaMemoria){
    tipologiaMemoriaValueLabel->setText(tipologiaMemoria);
}

void SchedaMadreSpecsWidget::setMemoriaMassimaValueLabel(const QString& memoriaMassima){
    memoriaMassimaValueLabel->setText(memoriaMassima);
}

void SchedaMadreSpecsWidget::setSupportoRAIDValueLabel(const QString& supportoRAID){
    supportoRAIDValueLabel->setText(supportoRAID);
}

void SchedaMadreSpecsWidget::setSupportoCrossfireValueLabel(const QString& supportoCrossfire){
    supportoCrossfireValueLabel->setText(supportoCrossfire);
}

void SchedaMadreSpecsWidget::setSupportoSLIValueLabel(const QString& supportoSLI){
    supportoSLIValueLabel->setText(supportoSLI);
}

void SchedaMadreSpecsWidget::setEthernetValueLabel(const QString& ethernet){
    ethernetValueLabel->setText(ethernet);
}

void SchedaMadreSpecsWidget::setSata3GBsValueLabel(const QString& sata3GBs){
    sata3GBsValueLabel->setText(sata3GBs);
}

void SchedaMadreSpecsWidget::setSata6GBsValueLabel(const QString& sata6GBs){
    sata6GBsValueLabel->setText(sata6GBs);
}

void SchedaMadreSpecsWidget::setSataExpressValueLabel(const QString& sataExpress){
    sataExpressValueLabel->setText(sataExpress);
}

void SchedaMadreSpecsWidget::setUsb2ValueLabel(const QString& usb2){
    usb2ValueLabel->setText(usb2);
}

void SchedaMadreSpecsWidget::setUsb3ValueLabel(const QString& usb3){
    usb3ValueLabel->setText(usb3);
}
