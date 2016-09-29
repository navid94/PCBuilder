#include "TastieraAddWidget.h"

#include <QLayout>
#include <QFont>

TastieraAddWidget::TastieraAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createCheckBoxes();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelTastiera,0,0,1,1);
    gridLayout->addWidget(nomeLineEditTastiera,0,1,1,1);
    gridLayout->addWidget(prezzoLabelTastiera,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxTastiera,1,1,1,1);
    gridLayout->addWidget(produttoreLabelTastiera,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditTastiera,2,1,1,1);
    gridLayout->addWidget(coloreLabelTastiera,3,0,1,1);
    gridLayout->addWidget(coloreLineEditTastiera,3,1,1,1);
    gridLayout->addWidget(connessioneLabelTastiera,4,0,1,1);
    gridLayout->addWidget(connessioneLineEditTastiera,4,1,1,1);
    gridLayout->addWidget(retroilluminazioneCheckBoxTastiera,5,1,1,1);
    gridLayout->addWidget(tipologiaLabelTastiera,6,0,1,1);
    gridLayout->addWidget(tipologiaLineEditTastiera,6,1,1,1);
    gridLayout->addWidget(tipologiaSwitchLabelTastiera,7,0,1,1);
    gridLayout->addWidget(tipologiaSwitchLineEditTastiera,7,1,1,1);
    setLayout(gridLayout);
}

void TastieraAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);


    nomeLabelTastiera=new QLabel(tr("Nome:"));
    nomeLabelTastiera->setFont(font_formLabel);
    nomeLabelTastiera->setMaximumSize(QSize(70,30));
    nomeLabelTastiera->setMinimumSize(QSize(0,0));

    prezzoLabelTastiera=new QLabel(tr("Prezzo:"));
    prezzoLabelTastiera->setFont(font_formLabel);
    prezzoLabelTastiera->setMaximumSize(QSize(80,30));
    prezzoLabelTastiera->setMinimumSize(QSize(0,0));

    produttoreLabelTastiera=new QLabel(tr("Produttore:"));
    produttoreLabelTastiera->setFont(font_formLabel);
    produttoreLabelTastiera->setMaximumSize(QSize(110,30));
    produttoreLabelTastiera->setMinimumSize(QSize(0,0));

    coloreLabelTastiera=new QLabel(tr("Colore:"));
    coloreLabelTastiera->setFont(font_formLabel);
    coloreLabelTastiera->setMaximumSize(QSize(70,30));
    coloreLabelTastiera->setMinimumSize(QSize(0,0));

    connessioneLabelTastiera=new QLabel(tr("Connessione:"));
    connessioneLabelTastiera->setFont(font_formLabel);
    connessioneLabelTastiera->setMaximumSize(QSize(130,30));
    connessioneLabelTastiera->setMinimumSize(QSize(0,0));

    tipologiaLabelTastiera=new QLabel(tr("Tipologia:"));
    tipologiaLabelTastiera->setFont(font_formLabel);
    tipologiaLabelTastiera->setMaximumSize(QSize(90,30));
    tipologiaLabelTastiera->setMinimumSize(QSize(0,0));

    tipologiaSwitchLabelTastiera=new QLabel(tr("Tipologia ")+("switch:"));
    tipologiaSwitchLabelTastiera->setFont(font_formLabel);
    tipologiaSwitchLabelTastiera->setMaximumSize(QSize(160,30));
    tipologiaSwitchLabelTastiera->setMinimumSize(QSize(0,0));
}

void TastieraAddWidget::createLineEdits(){
    nomeLineEditTastiera=new QLineEdit;
    nomeLineEditTastiera->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditTastiera->setMaximumSize(QSize(200,30));
    nomeLineEditTastiera->setMinimumSize(QSize(0,0));

    produttoreLineEditTastiera=new QLineEdit;
    produttoreLineEditTastiera->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditTastiera->setMaximumSize(QSize(200,30));
    produttoreLineEditTastiera->setMinimumSize(QSize(0,0));

    coloreLineEditTastiera=new QLineEdit;
    coloreLineEditTastiera->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditTastiera->setMaximumSize(QSize(200,30));
    coloreLineEditTastiera->setMinimumSize(QSize(0,0));

    connessioneLineEditTastiera=new QLineEdit;
    connessioneLineEditTastiera->setPlaceholderText(tr("Inserire connessione"));
    connessioneLineEditTastiera->setMaximumSize(QSize(200,30));
    connessioneLineEditTastiera->setMinimumSize(QSize(0,0));

    tipologiaLineEditTastiera=new QLineEdit;
    tipologiaLineEditTastiera->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditTastiera->setMaximumSize(QSize(200,30));
    tipologiaLineEditTastiera->setMinimumSize(QSize(0,0));

    tipologiaSwitchLineEditTastiera=new QLineEdit;
    tipologiaSwitchLineEditTastiera->setPlaceholderText(tr("Inserire tipologia switch"));
    tipologiaSwitchLineEditTastiera->setMaximumSize(QSize(200,30));
    tipologiaSwitchLineEditTastiera->setMinimumSize(QSize(0,0));
}

void TastieraAddWidget::createCheckBoxes(){
    retroilluminazioneCheckBoxTastiera=new QCheckBox(tr("Retroilluminazione"));
    retroilluminazioneCheckBoxTastiera->setMaximumSize(QSize(140,30));
    retroilluminazioneCheckBoxTastiera->setMinimumSize(QSize(0,0));
}

void TastieraAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxTastiera=new QDoubleSpinBox;
    prezzoDoubleSpinBoxTastiera->setSuffix(" €");
    prezzoDoubleSpinBoxTastiera->setMaximum(9999.99);
    prezzoDoubleSpinBoxTastiera->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxTastiera->setMinimumSize(QSize(0,0));
}

QString TastieraAddWidget::nomeTastieraValue() const{
    return nomeLineEditTastiera->text();
}

QString TastieraAddWidget::produttoreTastieraValue() const{
    return produttoreLineEditTastiera->text();
}

QString TastieraAddWidget::coloreTastieraValue() const{
    return coloreLineEditTastiera->text();
}

QString TastieraAddWidget::connessioneTastieraValue() const{
    return connessioneLineEditTastiera->text();
}

QString TastieraAddWidget::tipologiaTastieraValue() const{
    return tipologiaLineEditTastiera->text();
}

QString TastieraAddWidget::tipologiaSwitchTastieraValue() const{
    return tipologiaSwitchLineEditTastiera->text();
}

bool TastieraAddWidget::retroilluminazioneTastieraValue() const{
    return retroilluminazioneCheckBoxTastiera->isChecked();
}

double TastieraAddWidget::prezzoTastieraValue() const{
    return prezzoDoubleSpinBoxTastiera->value();
}

QLineEdit* TastieraAddWidget::getNomeLineEditTastiera() const{
    return nomeLineEditTastiera;
}

QLineEdit* TastieraAddWidget::getProduttoreLineEditTastiera() const{
    return produttoreLineEditTastiera;
}

QLineEdit* TastieraAddWidget::getColoreLineEditTastiera() const{
    return coloreLineEditTastiera;
}

QLineEdit* TastieraAddWidget::getConnessioneLineEditTastiera() const{
    return connessioneLineEditTastiera;
}

QLineEdit* TastieraAddWidget::getTipologiaLineEditTastiera() const{
    return tipologiaLineEditTastiera;
}

QLineEdit* TastieraAddWidget::getTipologiaSwitchLineEditTastiera() const{
    return tipologiaSwitchLineEditTastiera;
}

QCheckBox* TastieraAddWidget::getRetroilluminazioneCheckBoxTastiera() const{
    return retroilluminazioneCheckBoxTastiera;
}

QDoubleSpinBox* TastieraAddWidget::getPrezzoDoubleSpinBoxTastiera() const{
    return prezzoDoubleSpinBoxTastiera;
}
