#include "CaseAddWidget.h"
#include <QLayout>
#include <QFont>

CaseAddWidget::CaseAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createCheckBoxes();
    createDoubleSpinBoxes();
    createSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelCase,0,0,1,1);
    gridLayout->addWidget(nomeLineEditCase,0,1,1,1);
    gridLayout->addWidget(prezzoLabelCase,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxCase,1,1,1,1);
    gridLayout->addWidget(produttoreLabelCase,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditCase,2,1,1,1);
    gridLayout->addWidget(tipologiaLabelCase,3,0,1,1);
    gridLayout->addWidget(tipologiaLineEditCase,3,1,1,1);
    gridLayout->addWidget(coloreLabelCase,4,0,1,1);
    gridLayout->addWidget(coloreLineEditCase,4,1,1,1);
    gridLayout->addWidget(alimentatoreInclusoCheckBoxCase,5,1,1,1);
    gridLayout->addWidget(slotInterni25LabelCase,6,0,1,1);
    gridLayout->addWidget(slotInterni25SpinBoxCase,6,1,1,1);
    gridLayout->addWidget(slotInterni35LabelCase,7,0,1,1);
    gridLayout->addWidget(slotInterni35SpinBoxCase,7,1,1,1);
    gridLayout->addWidget(compatibilitaSchedaMadreLabelCase,8,0,1,1);
    gridLayout->addWidget(compatibilitaSchedaMadreLineEditCase,8,1,1,1);
    gridLayout->addWidget(lunghezzaMassimaSchedaGraficaLabelCase,9,0,1,1);
    gridLayout->addWidget(lunghezzaMassimaSchedaGraficaLineEditCase,9,1,1,1);
    gridLayout->addWidget(dimensioniLabelCase,10,0,1,1);
    gridLayout->addWidget(dimensioniLineEditCase,10,1,1,1);
    setLayout(gridLayout);
}

void CaseAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelCase=new QLabel(tr("Nome:"));
    nomeLabelCase->setFont(font_formLabel);
    nomeLabelCase->setMaximumSize(QSize(70,30));
    nomeLabelCase->setMinimumSize(QSize(0,0));

    prezzoLabelCase=new QLabel(tr("Prezzo:"));
    prezzoLabelCase->setFont(font_formLabel);
    prezzoLabelCase->setMaximumSize(QSize(80,30));
    prezzoLabelCase->setMinimumSize(QSize(0,0));

    produttoreLabelCase=new QLabel(tr("Produttore:"));
    produttoreLabelCase->setFont(font_formLabel);
    produttoreLabelCase->setMaximumSize(QSize(110,30));
    produttoreLabelCase->setMinimumSize(QSize(0,0));

    tipologiaLabelCase=new QLabel(tr("Tipologia:"));
    tipologiaLabelCase->setFont(font_formLabel);
    tipologiaLabelCase->setMaximumSize(QSize(90,30));
    tipologiaLabelCase->setMinimumSize(QSize(0,0));

    coloreLabelCase=new QLabel(tr("Colore:"));
    coloreLabelCase->setFont(font_formLabel);
    coloreLabelCase->setMaximumSize(QSize(70,30));
    coloreLabelCase->setMinimumSize(QSize(0,0));

    slotInterni25LabelCase=new QLabel("Slot "+(tr("interni 2.5:")));
    slotInterni25LabelCase->setFont(font_formLabel);
    slotInterni25LabelCase->setMaximumSize(QSize(160,30));
    slotInterni25LabelCase->setMinimumSize(QSize(0,0));

    slotInterni35LabelCase=new QLabel("Slot "+(tr("interni 3.5:")));
    slotInterni35LabelCase->setFont(font_formLabel);
    slotInterni35LabelCase->setMaximumSize(QSize(160,30));
    slotInterni35LabelCase->setMinimumSize(QSize(0,0));

    compatibilitaSchedaMadreLabelCase=new QLabel(tr("Compatibilità \nscheda madre:"));
    compatibilitaSchedaMadreLabelCase->setFont(font_formLabel);
    compatibilitaSchedaMadreLabelCase->setMaximumSize(QSize(140,50));
    compatibilitaSchedaMadreLabelCase->setMinimumSize(QSize(0,0));

    lunghezzaMassimaSchedaGraficaLabelCase=new QLabel(tr("Lunghezza massima \nscheda grafica:"));
    lunghezzaMassimaSchedaGraficaLabelCase->setFont(font_formLabel);
    lunghezzaMassimaSchedaGraficaLabelCase->setMaximumSize(QSize(200,50));
    lunghezzaMassimaSchedaGraficaLabelCase->setMinimumSize(QSize(0,0));

    dimensioniLabelCase=new QLabel(tr("Dimensioni:"));
    dimensioniLabelCase->setFont(font_formLabel);
    dimensioniLabelCase->setMaximumSize(QSize(120,30));
    dimensioniLabelCase->setMinimumSize(QSize(0,0));
}

void CaseAddWidget::createLineEdits(){
    nomeLineEditCase=new QLineEdit;
    nomeLineEditCase->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditCase->setMaximumSize(QSize(200,30));
    nomeLineEditCase->setMinimumSize(QSize(0,0));

    produttoreLineEditCase=new QLineEdit;
    produttoreLineEditCase->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditCase->setMaximumSize(QSize(200,30));
    produttoreLineEditCase->setMinimumSize(QSize(0,0));

    tipologiaLineEditCase=new QLineEdit;
    tipologiaLineEditCase->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditCase->setMaximumSize(QSize(200,30));
    tipologiaLineEditCase->setMinimumSize(QSize(0,0));

    coloreLineEditCase=new QLineEdit;
    coloreLineEditCase->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditCase->setMaximumSize(QSize(200,30));
    coloreLineEditCase->setMinimumSize(QSize(0,0));

    compatibilitaSchedaMadreLineEditCase=new QLineEdit;
    compatibilitaSchedaMadreLineEditCase->setPlaceholderText(tr("Inserire compatibilità scheda madre"));
    compatibilitaSchedaMadreLineEditCase->setMaximumSize(QSize(200,30));
    compatibilitaSchedaMadreLineEditCase->setMinimumSize(QSize(0,0));

    lunghezzaMassimaSchedaGraficaLineEditCase=new QLineEdit;
    lunghezzaMassimaSchedaGraficaLineEditCase->setPlaceholderText(tr("Inserire lunghezza massima scheda grafica"));
    lunghezzaMassimaSchedaGraficaLineEditCase->setMaximumSize(QSize(200,30));
    lunghezzaMassimaSchedaGraficaLineEditCase->setMinimumSize(QSize(0,0));

    dimensioniLineEditCase=new QLineEdit;
    dimensioniLineEditCase->setPlaceholderText(tr("Inserire dimensioni"));
    dimensioniLineEditCase->setMaximumSize(QSize(200,30));
    dimensioniLineEditCase->setMinimumSize(QSize(0,0));
}

void CaseAddWidget::createCheckBoxes(){
    alimentatoreInclusoCheckBoxCase=new QCheckBox(tr("Alimentatore incluso"));
    alimentatoreInclusoCheckBoxCase->setMaximumSize(QSize(150,30));
    alimentatoreInclusoCheckBoxCase->setMinimumSize(QSize(0,0));
}

void CaseAddWidget::createSpinBoxes(){
    slotInterni25SpinBoxCase=new QSpinBox;
    slotInterni25SpinBoxCase->setMaximum(99);
    slotInterni25SpinBoxCase->setMaximumSize(QSize(50,25));
    slotInterni25SpinBoxCase->setMinimumSize(0,0);

    slotInterni35SpinBoxCase=new QSpinBox;
    slotInterni35SpinBoxCase->setMaximum(99);
    slotInterni35SpinBoxCase->setMaximumSize(QSize(50,25));
    slotInterni35SpinBoxCase->setMinimumSize(QSize(0,0));
}

void CaseAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxCase=new QDoubleSpinBox;
    prezzoDoubleSpinBoxCase->setSuffix(" €");
    prezzoDoubleSpinBoxCase->setMaximum(9999.99);
    prezzoDoubleSpinBoxCase->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxCase->setMinimumSize(QSize(0,0));
}

QString CaseAddWidget::nomeCaseValue() const{
    return nomeLineEditCase->text();
}

QString CaseAddWidget::produttoreCaseValue() const{
    return produttoreLineEditCase->text();
}

QString CaseAddWidget::tipologiaCaseValue() const{
    return tipologiaLineEditCase->text();
}

QString CaseAddWidget::coloreCaseValue() const{
    return coloreLineEditCase->text();
}

QString CaseAddWidget::compatibilitaSchedaMadreCaseValue() const{
    return compatibilitaSchedaMadreLineEditCase->text();
}

QString CaseAddWidget::lunghezzaMassimaSchedaGraficaCaseValue() const{
    return lunghezzaMassimaSchedaGraficaLineEditCase->text();
}

QString CaseAddWidget::dimensioniCaseValue() const{
    return dimensioniLineEditCase->text();
}

bool CaseAddWidget::alimentatoreInclusoCaseValue() const{
    return alimentatoreInclusoCheckBoxCase->isChecked();
}

int CaseAddWidget::slotInterni25CaseValue() const{
    return slotInterni25SpinBoxCase->value();
}

int CaseAddWidget::slotInterni35CaseValue() const{
    return slotInterni35SpinBoxCase->value();
}

double CaseAddWidget::prezzoCaseValue() const{
    return prezzoDoubleSpinBoxCase->value();
}

QLineEdit* CaseAddWidget::getNomeLineEditCase() const{
    return nomeLineEditCase;
}

QLineEdit* CaseAddWidget::getProduttoreLineEditCase() const{
    return produttoreLineEditCase;
}

QLineEdit* CaseAddWidget::getTipologiaLineEditCase() const{
    return tipologiaLineEditCase;
}

QLineEdit* CaseAddWidget::getColoreLineEditCase() const{
    return coloreLineEditCase;
}

QLineEdit* CaseAddWidget::getCompatibilitaSchedaMadreLineEditCase() const{
    return compatibilitaSchedaMadreLineEditCase;
}

QLineEdit* CaseAddWidget::getLunghezzaMassimaSchedaGraficaLineEditCase() const{
    return lunghezzaMassimaSchedaGraficaLineEditCase;
}

QLineEdit* CaseAddWidget::getDimensioniLineEditCase() const{
    return dimensioniLineEditCase;
}

QCheckBox* CaseAddWidget::getAlimentatoreInclusoCheckBoxCase() const{
    return alimentatoreInclusoCheckBoxCase;
}

QSpinBox* CaseAddWidget::getSlotInterni25SpinBoxCase() const{
    return slotInterni25SpinBoxCase;
}

QSpinBox* CaseAddWidget::getSlotInterni35SpinBoxCase() const{
    return slotInterni35SpinBoxCase;
}

QDoubleSpinBox* CaseAddWidget::getPrezzoDoubleSpinBoxCase() const{
    return prezzoDoubleSpinBoxCase;
}
