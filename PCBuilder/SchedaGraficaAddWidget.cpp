#include "SchedaGraficaAddWidget.h"
#include <QFont>
#include <QLayout>

SchedaGraficaAddWidget::SchedaGraficaAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelSchedaGrafica,0,0,1,1);
    gridLayout->addWidget(nomeLineEditSchedaGrafica,0,1,1,1);
    gridLayout->addWidget(prezzoLabelSchedaGrafica,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxSchedaGrafica,1,1,1,1);
    gridLayout->addWidget(produttoreLabelSchedaGrafica,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditSchedaGrafica,2,1,1,1);
    gridLayout->addWidget(interfacciaLabelSchedaGrafica,3,0,1,1);
    gridLayout->addWidget(interfacciaLineEditSchedaGrafica,3,1,1,1);
    gridLayout->addWidget(chipsetLabelSchedaGrafica,4,0,1,1);
    gridLayout->addWidget(chipsetLineEditSchedaGrafica,4,1,1,1);
    gridLayout->addWidget(memoriaLabelSchedaGrafica,5,0,1,1);
    gridLayout->addWidget(memoriaLineEditSchedaGrafica,5,1,1,1);
    gridLayout->addWidget(tipologiaMemoriaLabelSchedaGrafica,6,0,1,1);
    gridLayout->addWidget(tipologiaMemoriaLineEditSchedaGrafica,6,1,1,1);
    gridLayout->addWidget(frequenzaCoreLabelSchedaGrafica,7,0,1,1);
    gridLayout->addWidget(frequenzaCoreLineEditSchedaGrafica,7,1,1,1);
    gridLayout->addWidget(tdpLabelSchedaGrafica,8,0,1,1);
    gridLayout->addWidget(tdpLineEditSchedaGrafica,8,1,1,1);
    gridLayout->addWidget(supportoSLILabelSchedaGrafica,9,0,1,1);
    gridLayout->addWidget(supportoSLILineEditSchedaGrafica,9,1,1,1);
    gridLayout->addWidget(supportoCrossfireLabelSchedaGrafica,10,0,1,1);
    gridLayout->addWidget(supportoCrossfireLineEditSchedaGrafica,10,1,1,1);
    gridLayout->addWidget(lunghezzaLabelSchedaGrafica,11,0,1,1);
    gridLayout->addWidget(lunghezzaLineEditSchedaGrafica,11,1,1,1);
    setLayout(gridLayout);
}

void SchedaGraficaAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelSchedaGrafica=new QLabel(tr("Nome:"));
    nomeLabelSchedaGrafica->setFont(font_formLabel);
    nomeLabelSchedaGrafica->setMaximumSize(QSize(70,30));
    nomeLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    prezzoLabelSchedaGrafica=new QLabel(tr("Prezzo:"));
    prezzoLabelSchedaGrafica->setFont(font_formLabel);
    prezzoLabelSchedaGrafica->setMaximumSize(QSize(80,30));
    prezzoLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    produttoreLabelSchedaGrafica=new QLabel(tr("Produttore:"));
    produttoreLabelSchedaGrafica->setFont(font_formLabel);
    produttoreLabelSchedaGrafica->setMaximumSize(QSize(110,30));
    produttoreLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    interfacciaLabelSchedaGrafica=new QLabel(tr("Interfaccia:"));
    interfacciaLabelSchedaGrafica->setFont(font_formLabel);
    interfacciaLabelSchedaGrafica->setMaximumSize(QSize(110,30));
    interfacciaLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    chipsetLabelSchedaGrafica=new QLabel("Chipset:");
    chipsetLabelSchedaGrafica->setFont(font_formLabel);
    chipsetLabelSchedaGrafica->setMaximumSize(QSize(80,30));
    chipsetLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    memoriaLabelSchedaGrafica=new QLabel(tr("Memoria:"));
    memoriaLabelSchedaGrafica->setFont(font_formLabel);
    memoriaLabelSchedaGrafica->setMaximumSize(QSize(90,30));
    memoriaLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLabelSchedaGrafica=new QLabel(tr("Tipologia \nmemoria:"));
    tipologiaMemoriaLabelSchedaGrafica->setFont(font_formLabel);
    tipologiaMemoriaLabelSchedaGrafica->setMaximumSize(QSize(90,50));
    tipologiaMemoriaLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    frequenzaCoreLabelSchedaGrafica=new QLabel(tr("Frequenza ")+("core:"));
    frequenzaCoreLabelSchedaGrafica->setFont(font_formLabel);
    frequenzaCoreLabelSchedaGrafica->setMaximumSize(QSize(160,30));
    frequenzaCoreLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    tdpLabelSchedaGrafica=new QLabel("TDP:");
    tdpLabelSchedaGrafica->setFont(font_formLabel);
    tdpLabelSchedaGrafica->setMaximumSize(QSize(50,30));
    tdpLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoSLILabelSchedaGrafica=new QLabel(tr("Supporto ")+("SLI:"));
    supportoSLILabelSchedaGrafica->setFont(font_formLabel);
    supportoSLILabelSchedaGrafica->setMaximumSize(QSize(130,30));
    supportoSLILabelSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoCrossfireLabelSchedaGrafica=new QLabel(tr("Supporto ")+("\nCrossfire:"));
    supportoCrossfireLabelSchedaGrafica->setFont(font_formLabel);
    supportoCrossfireLabelSchedaGrafica->setMaximumSize(QSize(90,50));
    supportoCrossfireLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    lunghezzaLabelSchedaGrafica=new QLabel(tr("Lunghezza:"));
    lunghezzaLabelSchedaGrafica->setFont(font_formLabel);
    lunghezzaLabelSchedaGrafica->setMaximumSize(QSize(110,30));
    lunghezzaLabelSchedaGrafica->setMinimumSize(QSize(0,0));
}

void SchedaGraficaAddWidget::createLineEdits(){
    nomeLineEditSchedaGrafica=new QLineEdit;
    nomeLineEditSchedaGrafica->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    nomeLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    produttoreLineEditSchedaGrafica=new QLineEdit;
    produttoreLineEditSchedaGrafica->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    produttoreLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    interfacciaLineEditSchedaGrafica=new QLineEdit;
    interfacciaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire interfaccia"));
    interfacciaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    interfacciaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    chipsetLineEditSchedaGrafica=new QLineEdit;
    chipsetLineEditSchedaGrafica->setPlaceholderText(tr("Inserire chipset"));
    chipsetLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    chipsetLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    memoriaLineEditSchedaGrafica=new QLineEdit;
    memoriaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire memoria"));
    memoriaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    memoriaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLineEditSchedaGrafica=new QLineEdit;
    tipologiaMemoriaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire tipologia memoria"));
    tipologiaMemoriaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    tipologiaMemoriaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    frequenzaCoreLineEditSchedaGrafica=new QLineEdit;
    frequenzaCoreLineEditSchedaGrafica->setPlaceholderText(tr("Inserire frequenza core"));
    frequenzaCoreLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    frequenzaCoreLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    tdpLineEditSchedaGrafica=new QLineEdit;
    tdpLineEditSchedaGrafica->setPlaceholderText(tr("Inserire TDP"));
    tdpLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    tdpLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoSLILineEditSchedaGrafica=new QLineEdit;
    supportoSLILineEditSchedaGrafica->setPlaceholderText(tr("Inserire supporto SLI"));
    supportoSLILineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    supportoSLILineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoCrossfireLineEditSchedaGrafica=new QLineEdit;
    nomeLineEditSchedaGrafica->setPlaceholderText(tr("Inserire supporto Crossfire"));
    supportoCrossfireLineEditSchedaGrafica->setPlaceholderText(tr(""));
    supportoCrossfireLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    supportoCrossfireLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    lunghezzaLineEditSchedaGrafica=new QLineEdit;
    lunghezzaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire lunghezza"));
    lunghezzaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    lunghezzaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));
}

void SchedaGraficaAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxSchedaGrafica=new QDoubleSpinBox;
    prezzoDoubleSpinBoxSchedaGrafica->setSuffix(" €");
    prezzoDoubleSpinBoxSchedaGrafica->setMaximum(9999.99);
    prezzoDoubleSpinBoxSchedaGrafica->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxSchedaGrafica->setMinimumSize(QSize(0,0));
}

QString SchedaGraficaAddWidget::nomeSchedaGraficaValue() const{
    return nomeLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::produttoreSchedaGraficaValue() const{
    return produttoreLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::interfacciaSchedaGraficaValue() const{
    return interfacciaLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::chipsetSchedaGraficaValue() const{
    return chipsetLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::memoriaSchedaGraficaValue() const{
    return memoriaLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::tipologiaMemoriaSchedaGraficaValue() const{
    return tipologiaMemoriaLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::frequenzaCoreSchedaGraficaValue() const{
    return frequenzaCoreLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::tdpSchedaGraficaValue() const{
    return tdpLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::supportoSLISchedaGraficaValue() const{
    return supportoSLILineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::supportoCrossfireSchedaGraficaValue() const{
    return supportoCrossfireLineEditSchedaGrafica->text();
}

QString SchedaGraficaAddWidget::lunghezzaSchedaGraficaValue() const{
    return lunghezzaLineEditSchedaGrafica->text();
}

double SchedaGraficaAddWidget::prezzoSchedaGraficaValue() const{
    return prezzoDoubleSpinBoxSchedaGrafica->value();
}

QLineEdit* SchedaGraficaAddWidget::getNomeLineEditSchedaGrafica() const{
    return nomeLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getProduttoreLineEditSchedaGrafica() const{
    return produttoreLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getInterfacciaLineEditSchedaGrafica() const{
    return interfacciaLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getChipsetLineEditSchedaGrafica() const{
    return chipsetLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getMemoriaLineEditSchedaGrafica() const{
    return memoriaLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getTipologiaMemoriaLineEditSchedaGrafica() const{
    return tipologiaMemoriaLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getFrequenzaCoreLineEditSchedaGrafica() const{
    return frequenzaCoreLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getTdpLineEditSchedaGrafica() const{
    return tdpLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getSupportoSLILineEditSchedaGrafica() const{
    return supportoSLILineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getSupportoCrossfireLineEditSchedaGrafica() const{
    return supportoCrossfireLineEditSchedaGrafica;
}

QLineEdit* SchedaGraficaAddWidget::getLunghezzaLineEditSchedaGrafica() const{
    return lunghezzaLineEditSchedaGrafica;
}

QDoubleSpinBox* SchedaGraficaAddWidget::getPrezzoDoubleSpinBoxSchedaGrafica() const{
    return prezzoDoubleSpinBoxSchedaGrafica;
}
