#include "MemoriaAddWidget.h"
#include <QLayout>
#include <QFont>

MemoriaAddWidget::MemoriaAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();
    createSpinBoxes();
    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelMemoria,0,0,1,1);
    gridLayout->addWidget(nomeLineEditMemoria,0,1,1,1);
    gridLayout->addWidget(prezzoLabelMemoria,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxMemoria,1,1,1,1);
    gridLayout->addWidget(produttoreLabelMemoria,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditMemoria,2,1,1,1);
    gridLayout->addWidget(latenzaLabelMemoria,3,0,1,1);
    gridLayout->addWidget(latenzaSpinBoxMemoria,3,1,1,1);
    gridLayout->addWidget(velocitaLabelMemoria,4,0,1,1);
    gridLayout->addWidget(velocitaLineEditMemoria,4,1,1,1);
    gridLayout->addWidget(capacitaLabelMemoria,5,0,1,1);
    gridLayout->addWidget(capacitaLineEditMemoria,5,1,1,1);
    gridLayout->addWidget(tipologiaLabelMemoria,6,0,1,1);
    gridLayout->addWidget(tipologiaLineEditMemoria,6,1,1,1);
    setLayout(gridLayout);
}

void MemoriaAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelMemoria=new QLabel(tr("Nome:"));
    nomeLabelMemoria->setFont(font_formLabel);
    nomeLabelMemoria->setMaximumSize(QSize(70,30));
    nomeLabelMemoria->setMinimumSize(QSize(0,0));

    prezzoLabelMemoria=new QLabel(tr("Prezzo:"));
    prezzoLabelMemoria->setFont(font_formLabel);
    prezzoLabelMemoria->setMaximumSize(QSize(80,30));
    prezzoLabelMemoria->setMinimumSize(QSize(0,0));


    produttoreLabelMemoria=new QLabel(tr("Produttore"));
    produttoreLabelMemoria->setFont(font_formLabel);
    produttoreLabelMemoria->setMaximumSize(QSize(110,30));
    produttoreLabelMemoria->setMinimumSize(QSize(0,0));


    velocitaLabelMemoria=new QLabel(tr("Velocità:"));
    velocitaLabelMemoria->setFont(font_formLabel);
    velocitaLabelMemoria->setMaximumSize(QSize(90,30));
    velocitaLabelMemoria->setMinimumSize(QSize(0,0));


    capacitaLabelMemoria=new QLabel(tr("Capacità:"));
    capacitaLabelMemoria->setFont(font_formLabel);
    capacitaLabelMemoria->setMaximumSize(QSize(90,30));
    capacitaLabelMemoria->setMinimumSize(QSize(0,0));

    tipologiaLabelMemoria=new QLabel(tr("Tipologia:"));
    tipologiaLabelMemoria->setFont(font_formLabel);
    tipologiaLabelMemoria->setMaximumSize(QSize(90,30));
    tipologiaLabelMemoria->setMinimumSize(QSize(0,0));

    latenzaLabelMemoria=new QLabel(tr("Latenza:"));
    latenzaLabelMemoria->setFont(font_formLabel);
    latenzaLabelMemoria->setMaximumSize(QSize(80,30));
    latenzaLabelMemoria->setMinimumSize(QSize(0,0));
}

void MemoriaAddWidget::createLineEdits(){
    nomeLineEditMemoria=new QLineEdit;
    nomeLineEditMemoria->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditMemoria->setMaximumSize(QSize(200,30));
    nomeLineEditMemoria->setMinimumSize(QSize(0,0));

    produttoreLineEditMemoria=new QLineEdit;
    produttoreLineEditMemoria->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditMemoria->setMaximumSize(QSize(200,30));
    produttoreLineEditMemoria->setMinimumSize(QSize(0,0));

    velocitaLineEditMemoria=new QLineEdit;
    velocitaLineEditMemoria->setPlaceholderText(tr("Inserire velocita"));
    velocitaLineEditMemoria->setMaximumSize(QSize(200,30));
    velocitaLineEditMemoria->setMinimumSize(QSize(0,0));

    capacitaLineEditMemoria=new QLineEdit;
    capacitaLineEditMemoria->setPlaceholderText(tr("Inserire capacità"));
    capacitaLineEditMemoria->setMaximumSize(QSize(200,30));
    capacitaLineEditMemoria->setMinimumSize(QSize(0,0));

    tipologiaLineEditMemoria=new QLineEdit;
    tipologiaLineEditMemoria->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditMemoria->setMaximumSize(QSize(200,30));
    tipologiaLineEditMemoria->setMinimumSize(QSize(0,0));
}

void MemoriaAddWidget::createSpinBoxes(){
    latenzaSpinBoxMemoria=new QSpinBox;
    latenzaSpinBoxMemoria->setMaximum(99);
    latenzaSpinBoxMemoria->setMaximumSize(QSize(50,25));
    latenzaSpinBoxMemoria->setMinimumSize(QSize(0,0));
}

void MemoriaAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxMemoria=new QDoubleSpinBox;
    prezzoDoubleSpinBoxMemoria->setSuffix(" €");
    prezzoDoubleSpinBoxMemoria->setMaximum(9999.99);
    prezzoDoubleSpinBoxMemoria->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxMemoria->setMinimumSize(QSize(0,0));
}

QString MemoriaAddWidget::nomeMemoriaValue() const{
    return nomeLineEditMemoria->text();
}

QString MemoriaAddWidget::produttoreMemoriaValue() const{
    return produttoreLineEditMemoria->text();
}

QString MemoriaAddWidget::velocitaMemoriaValue() const{
    return velocitaLineEditMemoria->text();
}

QString MemoriaAddWidget::capacitaMemoriaValue() const{
    return capacitaLineEditMemoria->text();
}

QString MemoriaAddWidget::tipologiaMemoriaValue() const{
    return tipologiaLineEditMemoria->text();
}

double MemoriaAddWidget::prezzoMemoriaValue() const{
    return prezzoDoubleSpinBoxMemoria->value();
}

int MemoriaAddWidget::latenzaMemoriaValue() const{
    return latenzaSpinBoxMemoria->value();
}

QLineEdit* MemoriaAddWidget::getNomeLineEditMemoria() const{
    return nomeLineEditMemoria;
}

QLineEdit* MemoriaAddWidget::getProduttoreLineEditMemoria() const{
    return produttoreLineEditMemoria;
}

QDoubleSpinBox* MemoriaAddWidget::getPrezzoDoubleSpinBoxMemoria() const{
    return prezzoDoubleSpinBoxMemoria;
}

QLineEdit* MemoriaAddWidget::getVelocitaLineEditMemoria() const{
    return velocitaLineEditMemoria;
}

QLineEdit* MemoriaAddWidget::getCapacitaLineEditMemoria() const{
    return capacitaLineEditMemoria;
}

QLineEdit* MemoriaAddWidget::getTipologiaLineEditMemoria() const{
    return tipologiaLineEditMemoria;
}

QSpinBox* MemoriaAddWidget::getLatenzaSpinBoxMemoria() const{
    return latenzaSpinBoxMemoria;
}

