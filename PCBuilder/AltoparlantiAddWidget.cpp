#include "AltoparlantiAddWidget.h"

#include <QLayout>
#include <QFont>

AltoparlantiAddWidget::AltoparlantiAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelAltoparlanti,0,0,1,1);
    gridLayout->addWidget(nomeLineEditAltoparlanti,0,1,1,1);
    gridLayout->addWidget(prezzoLabelAltoparlanti,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxAltoparlanti,1,1,1,1);
    gridLayout->addWidget(produttoreLabelAltoparlanti,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditAltoparlanti,2,1,1,1);
    gridLayout->addWidget(coloreLabelAltoparlanti,3,0,1,1);
    gridLayout->addWidget(coloreLineEditAltoparlanti,3,1,1,1);
    gridLayout->addWidget(configurazioneLabelAltoparlanti,4,0,1,1);
    gridLayout->addWidget(configurazioneLineEditAltoparlanti,4,1,1,1);
    gridLayout->addWidget(frequenzaDiRispostaLabelAltoparlanti,5,0,1,1);
    gridLayout->addWidget(frequenzaDiRispostaLineEditAltoparlanti,5,1,1,1);
    gridLayout->addWidget(potenzaTotaleLabelAltoparlanti,6,0,1,1);
    gridLayout->addWidget(potenzaTotaleLineEditAltoparlanti,6,1,1,1);
    gridLayout->addWidget(potenzeLabelAltoparlanti,7,0,1,1);
    gridLayout->addWidget(potenzeLineEditAltoparlanti,7,1,1,1);
    setLayout(gridLayout);
}

void AltoparlantiAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelAltoparlanti=new QLabel(tr("Nome:"));
    nomeLabelAltoparlanti->setFont(font_formLabel);
    nomeLabelAltoparlanti->setMaximumSize(QSize(70,30));
    nomeLabelAltoparlanti->setMinimumSize(QSize(0,0));

    prezzoLabelAltoparlanti=new QLabel(tr("Prezzo:"));
    prezzoLabelAltoparlanti->setFont(font_formLabel);
    prezzoLabelAltoparlanti->setMaximumSize(QSize(80,30));
    prezzoLabelAltoparlanti->setMinimumSize(QSize(0,0));

    produttoreLabelAltoparlanti=new QLabel(tr("Produttore:"));
    produttoreLabelAltoparlanti->setFont(font_formLabel);
    produttoreLabelAltoparlanti->setMaximumSize(QSize(110,30));
    produttoreLabelAltoparlanti->setMinimumSize(QSize(0,0));

    coloreLabelAltoparlanti=new QLabel(tr("Colore:"));
    coloreLabelAltoparlanti->setFont(font_formLabel);
    coloreLabelAltoparlanti->setMaximumSize(QSize(70,30));
    coloreLabelAltoparlanti->setMinimumSize(QSize(0,0));

    configurazioneLabelAltoparlanti=new QLabel(tr("Configurazione:"));
    configurazioneLabelAltoparlanti->setFont(font_formLabel);
    configurazioneLabelAltoparlanti->setMaximumSize(QSize(150,30));
    configurazioneLabelAltoparlanti->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLabelAltoparlanti=new QLabel(tr("Frequenza di \nrisposta:"));
    frequenzaDiRispostaLabelAltoparlanti->setFont(font_formLabel);
    frequenzaDiRispostaLabelAltoparlanti->setMaximumSize(QSize(120,50));
    frequenzaDiRispostaLabelAltoparlanti->setMinimumSize(QSize(0,0));

    potenzaTotaleLabelAltoparlanti=new QLabel(tr("Potenza totale:"));
    potenzaTotaleLabelAltoparlanti->setFont(font_formLabel);
    potenzaTotaleLabelAltoparlanti->setMaximumSize(QSize(150,30));
    potenzaTotaleLabelAltoparlanti->setMinimumSize(QSize(0,0));

    potenzeLabelAltoparlanti=new QLabel(tr("Potenze:"));
    potenzeLabelAltoparlanti->setFont(font_formLabel);
    potenzeLabelAltoparlanti->setMaximumSize(QSize(90,30));
    potenzeLabelAltoparlanti->setMinimumSize(QSize(0,0));
}

void AltoparlantiAddWidget::createLineEdits(){
    nomeLineEditAltoparlanti=new QLineEdit;
    nomeLineEditAltoparlanti->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    nomeLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    produttoreLineEditAltoparlanti=new QLineEdit;
    produttoreLineEditAltoparlanti->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    produttoreLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    coloreLineEditAltoparlanti=new QLineEdit;
    coloreLineEditAltoparlanti->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    coloreLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    configurazioneLineEditAltoparlanti=new QLineEdit;
    configurazioneLineEditAltoparlanti->setPlaceholderText(tr("Inserire configurazione"));
    configurazioneLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    configurazioneLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLineEditAltoparlanti=new QLineEdit;
    frequenzaDiRispostaLineEditAltoparlanti->setPlaceholderText(tr("Inserire frequenza di risposta"));
    frequenzaDiRispostaLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    frequenzaDiRispostaLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    potenzaTotaleLineEditAltoparlanti=new QLineEdit;
    potenzaTotaleLineEditAltoparlanti->setPlaceholderText(tr("Inserire potenza totale"));
    potenzaTotaleLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    potenzaTotaleLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    potenzeLineEditAltoparlanti=new QLineEdit;
    potenzeLineEditAltoparlanti->setPlaceholderText(tr("Inserire potenze"));
    potenzeLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    potenzeLineEditAltoparlanti->setMinimumSize(QSize(0,0));
}

void AltoparlantiAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxAltoparlanti=new QDoubleSpinBox;
    prezzoDoubleSpinBoxAltoparlanti->setSuffix(" €");
    prezzoDoubleSpinBoxAltoparlanti->setMaximum(9999.99);
    prezzoDoubleSpinBoxAltoparlanti->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxAltoparlanti->setMinimumSize(QSize(0,0));
}

QString AltoparlantiAddWidget::nomeAltoparlantiValue() const{
    return nomeLineEditAltoparlanti->text();
}

QString AltoparlantiAddWidget::produttoreAltoparlantiValue() const{
    return produttoreLineEditAltoparlanti->text();
}

QString AltoparlantiAddWidget::coloreAltoparlantiValue() const{
    return coloreLineEditAltoparlanti->text();
}

QString AltoparlantiAddWidget::configurazioneAltoparlantiValue() const{
    return configurazioneLineEditAltoparlanti->text();
}

QString AltoparlantiAddWidget::frequenzaDiRispostaAltoparlantiValue() const{
    return frequenzaDiRispostaLineEditAltoparlanti->text();
}

QString AltoparlantiAddWidget::potenzaTotaleAltoparlantiValue() const{
    return potenzaTotaleLineEditAltoparlanti->text();
}

QString AltoparlantiAddWidget::potenzeAltoparlantiValue() const{
    return potenzeLineEditAltoparlanti->text();
}

double AltoparlantiAddWidget::prezzoAltoparlantiValue() const{
    return prezzoDoubleSpinBoxAltoparlanti->value();
}

QLineEdit* AltoparlantiAddWidget::getNomeLineEditAltoparlanti() const{
    return nomeLineEditAltoparlanti;
}

QLineEdit* AltoparlantiAddWidget::getProduttoreLineEditAltoparlanti() const{
    return produttoreLineEditAltoparlanti;
}

QLineEdit* AltoparlantiAddWidget::getColoreLineEditAltoparlanti() const{
    return configurazioneLineEditAltoparlanti;
}

QLineEdit* AltoparlantiAddWidget::getConfigurazioneLineEditAltoparlanti() const{
    return configurazioneLineEditAltoparlanti;
}

QLineEdit* AltoparlantiAddWidget::getFrequenzaDiRispostaLineEditAltoparlanti() const{
    return frequenzaDiRispostaLineEditAltoparlanti;
}

QLineEdit* AltoparlantiAddWidget::getPotenzaTotaleLineEditAltoparlanti() const{
    return potenzaTotaleLineEditAltoparlanti;
}

QLineEdit* AltoparlantiAddWidget::getPotenzeLineEditAltoparlanti() const{
    return potenzeLineEditAltoparlanti;
}

QDoubleSpinBox* AltoparlantiAddWidget::getPrezzoDoubleSpinBoxAltoparlanti() const{
    return prezzoDoubleSpinBoxAltoparlanti;
}
