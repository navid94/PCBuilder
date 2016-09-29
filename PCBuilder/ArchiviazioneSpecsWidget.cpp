#include "ArchiviazioneSpecsWidget.h"
#include <QLayout>
#include <QFont>

ArchiviazioneSpecsWidget::ArchiviazioneSpecsWidget(QWidget* parent):QWidget(parent){
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
    gridLayout->addWidget(interfacciaLabel,5,0,1,1);
    gridLayout->addWidget(interfacciaValueLabel,5,1,1,1);
    gridLayout->addWidget(cacheLabel,6,0,1,1);
    gridLayout->addWidget(cacheValueLabel,6,1,1,1);
    gridLayout->addWidget(fattoreDiFormaLabel,7,0,1,1);
    gridLayout->addWidget(fattoreDiFormaValueLabel,7,1,1,1);
    gridLayout->addWidget(rpmLabel,8,0,1,1);
    gridLayout->addWidget(rpmValueLabel,8,1,1,1);

    setLayout(gridLayout);
}

void ArchiviazioneSpecsWidget::createLabels(){
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

    interfacciaLabel=new QLabel(tr("Interfaccia"));
    interfacciaLabel->setMinimumSize(QSize(0,0));
    interfacciaLabel->setFont(font_form);

    interfacciaValueLabel=new QLabel("");
    interfacciaValueLabel->setMinimumSize(QSize(0,0));
    interfacciaValueLabel->setFont(font_form);
    interfacciaValueLabel->setWordWrap(true);

    cacheLabel=new QLabel(tr("Cache"));
    cacheLabel->setMinimumSize(QSize(0,0));
    cacheLabel->setFont(font_form);

    cacheValueLabel=new QLabel("");
    cacheValueLabel->setMinimumSize(QSize(0,0));
    cacheValueLabel->setFont(font_form);
    cacheValueLabel->setWordWrap(true);

    fattoreDiFormaLabel=new QLabel(tr("Fattore di forma"));
    fattoreDiFormaLabel->setMinimumSize(QSize(0,0));
    fattoreDiFormaLabel->setFont(font_form);

    fattoreDiFormaValueLabel=new QLabel("");
    fattoreDiFormaValueLabel->setMinimumSize(QSize(0,0));
    fattoreDiFormaValueLabel->setFont(font_form);
    fattoreDiFormaValueLabel->setWordWrap(true);

    rpmLabel=new QLabel(tr("RPM"));
    rpmLabel->setMinimumSize(QSize(0,0));
    rpmLabel->setFont(font_form);

    rpmValueLabel=new QLabel("");
    rpmValueLabel->setMinimumSize(QSize(0,0));
    rpmValueLabel->setFont(font_form);
    rpmValueLabel->setWordWrap(true);
}

void ArchiviazioneSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void ArchiviazioneSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void ArchiviazioneSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void ArchiviazioneSpecsWidget::setTipologiaValueLabel(const QString& tipologia){
    tipologiaValueLabel->setText(tipologia);
}

void ArchiviazioneSpecsWidget::setCapacitaValueLabel(const QString& capacita){
    capacitaValueLabel->setText(capacita);
}

void ArchiviazioneSpecsWidget::setInterfacciaValueLabel(const QString& interfaccia){
    interfacciaValueLabel->setText(interfaccia);
}

void ArchiviazioneSpecsWidget::setCacheValueLabel(const QString& cache){
    cacheValueLabel->setText(cache);
}

void ArchiviazioneSpecsWidget::setFattoreDiFormaValueLabel(const QString& fattoreDiForma){
    fattoreDiFormaValueLabel->setText(fattoreDiForma);
}

void ArchiviazioneSpecsWidget::setRpmValueLabel(const QString& rpm){
    rpmValueLabel->setText(rpm);
}
