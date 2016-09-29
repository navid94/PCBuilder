#include "AlimentatoreAddWidget.h"
#include <QFont>
#include <QLayout>

AlimentatoreAddWidget::AlimentatoreAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelAlimentatore,0,0,1,1);
    gridLayout->addWidget(nomeLineEditAlimentatore,0,1,1,1);
    gridLayout->addWidget(prezzoLabelAlimentatore,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxAlimentatore,1,1,1,1);
    gridLayout->addWidget(produttoreLabelAlimentatore,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditAlimentatore,2,1,1,1);
    gridLayout->addWidget(tipologiaLabelAlimentatore,3,0,1,1);
    gridLayout->addWidget(tipologiaLineEditAlimentatore,3,1,1,1);
    gridLayout->addWidget(wattaggioLabelAlimentatore,4,0,1,1);
    gridLayout->addWidget(wattaggioLineEditAlimentatore,4,1,1,1);
    gridLayout->addWidget(modulareLabelAlimentatore,5,0,1,1);
    gridLayout->addWidget(modulareLineEditAlimentatore,5,1,1,1);
    gridLayout->addWidget(certificazioneEfficienzaLabelAlimentatore,6,0,1,1);
    gridLayout->addWidget(certificazioneEfficienzaLineEditAlimentatore,6,1,1,1);
    gridLayout->addWidget(efficienzaLabelAlimentatore,7,0,1,1);
    gridLayout->addWidget(efficienzaDoubleSpinBoxAlimentatore,7,1,1,1);
    setLayout(gridLayout);
}

void AlimentatoreAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelAlimentatore=new QLabel(tr("Nome:"));
    nomeLabelAlimentatore->setFont(font_formLabel);
    nomeLabelAlimentatore->setMaximumSize(QSize(70,30));
    nomeLabelAlimentatore->setMinimumSize(QSize(0,0));

    prezzoLabelAlimentatore=new QLabel(tr("Prezzo:"));
    prezzoLabelAlimentatore->setFont(font_formLabel);
    prezzoLabelAlimentatore->setMaximumSize(QSize(80,30));
    prezzoLabelAlimentatore->setMinimumSize(QSize(0,0));

    produttoreLabelAlimentatore=new QLabel(tr("Produttore:"));
    produttoreLabelAlimentatore->setFont(font_formLabel);
    produttoreLabelAlimentatore->setMaximumSize(QSize(110,30));
    produttoreLabelAlimentatore->setMinimumSize(QSize(0,0));

    tipologiaLabelAlimentatore=new QLabel(tr("Tipologia:"));
    tipologiaLabelAlimentatore->setFont(font_formLabel);
    tipologiaLabelAlimentatore->setMaximumSize(QSize(90,30));
    tipologiaLabelAlimentatore->setMinimumSize(QSize(0,0));

    wattaggioLabelAlimentatore=new QLabel(tr("Wattaggio:"));
    wattaggioLabelAlimentatore->setFont(font_formLabel);
    wattaggioLabelAlimentatore->setMaximumSize(QSize(110,30));
    wattaggioLabelAlimentatore->setMinimumSize(QSize(0,0));

    modulareLabelAlimentatore=new QLabel(tr("Modulare:"));
    modulareLabelAlimentatore->setFont(font_formLabel);
    modulareLabelAlimentatore->setMaximumSize(QSize(100,30));
    modulareLabelAlimentatore->setMinimumSize(QSize(0,0));

    certificazioneEfficienzaLabelAlimentatore=new QLabel(tr("Certificazione \nefficienza:"));
    certificazioneEfficienzaLabelAlimentatore->setFont(font_formLabel);
    certificazioneEfficienzaLabelAlimentatore->setMaximumSize(QSize(130,50));
    certificazioneEfficienzaLabelAlimentatore->setMinimumSize(QSize(0,0));

    efficienzaLabelAlimentatore=new QLabel(tr("Efficienza:"));
    efficienzaLabelAlimentatore->setFont(font_formLabel);
    efficienzaLabelAlimentatore->setMaximumSize(QSize(100,30));
    efficienzaLabelAlimentatore->setMinimumSize(QSize(0,0));
}

void AlimentatoreAddWidget::createLineEdits(){
    nomeLineEditAlimentatore=new QLineEdit;
    nomeLineEditAlimentatore->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditAlimentatore->setMaximumSize(QSize(200,30));
    nomeLineEditAlimentatore->setMinimumSize(QSize(0,0));

    produttoreLineEditAlimentatore=new QLineEdit;
    produttoreLineEditAlimentatore->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditAlimentatore->setMaximumSize(QSize(200,30));
    produttoreLineEditAlimentatore->setMinimumSize(QSize(0,0));

    tipologiaLineEditAlimentatore=new QLineEdit;
    tipologiaLineEditAlimentatore->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditAlimentatore->setMaximumSize(QSize(200,30));
    tipologiaLineEditAlimentatore->setMinimumSize(QSize(0,0));

    wattaggioLineEditAlimentatore=new QLineEdit;
    wattaggioLineEditAlimentatore->setPlaceholderText(tr("Inserire wattaggio"));
    wattaggioLineEditAlimentatore->setMaximumSize(QSize(200,30));
    wattaggioLineEditAlimentatore->setMinimumSize(QSize(0,0));

    modulareLineEditAlimentatore=new QLineEdit;
    modulareLineEditAlimentatore->setPlaceholderText(tr("Inserire modularità"));
    modulareLineEditAlimentatore->setMaximumSize(QSize(200,30));
    modulareLineEditAlimentatore->setMinimumSize(QSize(0,0));

    certificazioneEfficienzaLineEditAlimentatore=new QLineEdit;
    certificazioneEfficienzaLineEditAlimentatore->setPlaceholderText(tr("Inserire certificazione efficienza"));
    certificazioneEfficienzaLineEditAlimentatore->setMaximumSize(QSize(200,30));
    certificazioneEfficienzaLineEditAlimentatore->setMinimumSize(QSize(0,0));
}

void AlimentatoreAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxAlimentatore=new QDoubleSpinBox;
    prezzoDoubleSpinBoxAlimentatore->setSuffix(" €");
    prezzoDoubleSpinBoxAlimentatore->setMaximum(9999.99);
    prezzoDoubleSpinBoxAlimentatore->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxAlimentatore->setMinimumSize(QSize(0,0));

    efficienzaDoubleSpinBoxAlimentatore=new QDoubleSpinBox;
    efficienzaDoubleSpinBoxAlimentatore->setSuffix(" %");
    efficienzaDoubleSpinBoxAlimentatore->setMaximum(999.99);
    efficienzaDoubleSpinBoxAlimentatore->setMaximumSize(QSize(80,25));
    efficienzaDoubleSpinBoxAlimentatore->setMinimumSize(QSize(0,0));
}

QString AlimentatoreAddWidget::nomeAlimentatoreValue() const{
    return nomeLineEditAlimentatore->text();
}

QString AlimentatoreAddWidget::produttoreAlimentatoreValue() const{
    return produttoreLineEditAlimentatore->text();
}

QString AlimentatoreAddWidget::tipologiaAlimentatoreValue() const{
    return tipologiaLineEditAlimentatore->text();
}

QString AlimentatoreAddWidget::wattaggioAlimentatoreValue() const{
    return wattaggioLineEditAlimentatore->text();
}

QString AlimentatoreAddWidget::modulareAlimentatoreValue() const{
    return modulareLineEditAlimentatore->text();
}

QString AlimentatoreAddWidget::certificazioneEfficienzaAlimentatoreValue() const{
    return certificazioneEfficienzaLineEditAlimentatore->text();
}

double AlimentatoreAddWidget::efficienzaAlimentatoreValue() const{
    return efficienzaDoubleSpinBoxAlimentatore->value();
}

double AlimentatoreAddWidget::prezzoAlimentatoreValue() const{
    return prezzoDoubleSpinBoxAlimentatore->value();
}

QLineEdit* AlimentatoreAddWidget::getNomeLineEditAlimentatore() const{
    return nomeLineEditAlimentatore;
}

QLineEdit* AlimentatoreAddWidget::getProduttoreLineEditAlimentatore() const{
    return produttoreLineEditAlimentatore;
}

QLineEdit* AlimentatoreAddWidget::getTipologiaLineEditAlimentatore() const{
    return tipologiaLineEditAlimentatore;
}

QLineEdit* AlimentatoreAddWidget::getWattaggioLineEditAlimentatore() const{
    return wattaggioLineEditAlimentatore;
}

QLineEdit* AlimentatoreAddWidget::getModulareLineEditAlimentatore() const{
    return modulareLineEditAlimentatore;
}

QLineEdit* AlimentatoreAddWidget::getCertificazioneEfficienzaLineEditAlimentatore() const{
    return certificazioneEfficienzaLineEditAlimentatore;
}

QDoubleSpinBox* AlimentatoreAddWidget::getEfficienzaDoubleSpinBoxAlimentatore() const{
    return efficienzaDoubleSpinBoxAlimentatore;
}

QDoubleSpinBox* AlimentatoreAddWidget::getPrezzoDoubleSpinBoxAlimentatore() const{
    return prezzoDoubleSpinBoxAlimentatore;
}
