#include "UnitaOtticaSpecsWidget.h"
#include <QLayout>
#include <QFont>

UnitaOtticaSpecsWidget::UnitaOtticaSpecsWidget(QWidget* parent):QWidget(parent){
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
    gridLayout->addWidget(interfacciaLabel,4,0,1,1);
    gridLayout->addWidget(interfacciaValueLabel,4,1,1,1);
    gridLayout->addWidget(cacheLabel,5,0,1,1);
    gridLayout->addWidget(cacheValueLabel,5,1,1,1);
    gridLayout->addWidget(velocitaLabel,6,0,1,1);
    gridLayout->addWidget(velocitaValueLabel,6,1,1,1);

    setLayout(gridLayout);
}

void UnitaOtticaSpecsWidget::createLabels(){
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

    velocitaLabel=new QLabel(tr("Velocità"));
    velocitaLabel->setMinimumSize(QSize(0,0));
    velocitaLabel->setFont(font_form);

    velocitaValueLabel=new QLabel("");
    velocitaValueLabel->setMinimumSize(QSize(0,0));
    velocitaValueLabel->setFont(font_form);
    velocitaValueLabel->setWordWrap(true);
}

void UnitaOtticaSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void UnitaOtticaSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void UnitaOtticaSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void UnitaOtticaSpecsWidget::setFattoreDiFormaValueLabel(const QString& fattoreDiForma){
    fattoreDiFormaValueLabel->setText(fattoreDiForma);
}

void UnitaOtticaSpecsWidget::setInterfacciaValueLabel(const QString& interfaccia){
    interfacciaValueLabel->setText(interfaccia);
}

void UnitaOtticaSpecsWidget::setCacheValueLabel(const QString& cache){
    cacheValueLabel->setText(cache);
}

void UnitaOtticaSpecsWidget::setVelocitaValueLabel(const QString& velocita){
    velocitaValueLabel->setText(velocita);
}
