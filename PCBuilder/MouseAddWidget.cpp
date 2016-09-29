#include "MouseAddWidget.h"

#include <QLayout>
#include <QFont>

MouseAddWidget::MouseAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();
    createSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelMouse,0,0,1,1);
    gridLayout->addWidget(nomeLineEditMouse,0,1,1,1);
    gridLayout->addWidget(prezzoLabelMouse,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxMouse,1,1,1,1);
    gridLayout->addWidget(produttoreLabelMouse,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditMouse,2,1,1,1);
    gridLayout->addWidget(connessioneLabelMouse,3,0,1,1);
    gridLayout->addWidget(connessioneLineEditMouse,3,1,1,1);
    gridLayout->addWidget(tipologiaTracciamentoLabelMouse,4,0,1,1);
    gridLayout->addWidget(tipologiaTracciamentoLineEditMouse,4,1,1,1);
    gridLayout->addWidget(dpiMassimiLabelMouse,5,0,1,1);
    gridLayout->addWidget(dpiMassimiSpinBoxMouse,5,1,1,1);
    gridLayout->addWidget(coloreLabelMouse,6,0,1,1);
    gridLayout->addWidget(coloreLineEditMouse,6,1,1,1);
    gridLayout->addWidget(orientamentoDellaManoLabelMouse,7,0,1,1);
    gridLayout->addWidget(orientamentoDellaManoLineEditMouse,7,1,1,1);
    setLayout(gridLayout);
}

void MouseAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelMouse=new QLabel(tr("Nome:"));
    nomeLabelMouse->setFont(font_formLabel);
    nomeLabelMouse->setMaximumSize(QSize(70,30));
    nomeLabelMouse->setMinimumSize(QSize(0,0));

    prezzoLabelMouse=new QLabel(tr("Prezzo:"));
    prezzoLabelMouse->setFont(font_formLabel);
    prezzoLabelMouse->setMaximumSize(QSize(80,30));
    prezzoLabelMouse->setMinimumSize(QSize(0,0));

    produttoreLabelMouse=new QLabel(tr("Produttore:"));
    produttoreLabelMouse->setFont(font_formLabel);
    produttoreLabelMouse->setMaximumSize(QSize(110,30));
    produttoreLabelMouse->setMinimumSize(QSize(0,0));

    connessioneLabelMouse=new QLabel(tr("Connessione:"));
    connessioneLabelMouse->setFont(font_formLabel);
    connessioneLabelMouse->setMaximumSize(QSize(130,30));
    connessioneLabelMouse->setMinimumSize(QSize(0,0));

    tipologiaTracciamentoLabelMouse=new QLabel(tr("Tipologia tracciamento:"));
    tipologiaTracciamentoLabelMouse->setFont(font_formLabel);
    tipologiaTracciamentoLabelMouse->setMaximumSize(QSize(230,30));
    tipologiaTracciamentoLabelMouse->setMinimumSize(QSize(0,0));

    dpiMassimiLabelMouse=new QLabel("DPI "+(tr("massimi:")));
    dpiMassimiLabelMouse->setFont(font_formLabel);
    dpiMassimiLabelMouse->setMaximumSize(QSize(130,30));
    dpiMassimiLabelMouse->setMinimumSize(QSize(0,0));

    coloreLabelMouse=new QLabel(tr("Colore:"));
    coloreLabelMouse->setFont(font_formLabel);
    coloreLabelMouse->setMaximumSize(QSize(70,30));
    coloreLabelMouse->setMinimumSize(QSize(0,0));

    orientamentoDellaManoLabelMouse=new QLabel(tr("Orientamento della mano:"));
    orientamentoDellaManoLabelMouse->setFont(font_formLabel);
    orientamentoDellaManoLabelMouse->setMaximumSize(QSize(140,50));
    orientamentoDellaManoLabelMouse->setMinimumSize(QSize(0,0));
}

void MouseAddWidget::createLineEdits(){
    nomeLineEditMouse=new QLineEdit;
    nomeLineEditMouse->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditMouse->setMaximumSize(QSize(200,30));
    nomeLineEditMouse->setMinimumSize(QSize(0,0));

    produttoreLineEditMouse=new QLineEdit;
    produttoreLineEditMouse->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditMouse->setMaximumSize(QSize(200,30));
    produttoreLineEditMouse->setMinimumSize(QSize(0,0));

    connessioneLineEditMouse=new QLineEdit;
    connessioneLineEditMouse->setPlaceholderText(tr("Inserire connessione"));
    connessioneLineEditMouse->setMaximumSize(QSize(200,30));
    connessioneLineEditMouse->setMinimumSize(QSize(0,0));

    tipologiaTracciamentoLineEditMouse=new QLineEdit;
    tipologiaTracciamentoLineEditMouse->setPlaceholderText(tr("Inserire tipologia tracciamento"));
    tipologiaTracciamentoLineEditMouse->setMaximumSize(QSize(200,30));
    tipologiaTracciamentoLineEditMouse->setMinimumSize(QSize(0,0));

    coloreLineEditMouse=new QLineEdit;
    coloreLineEditMouse->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditMouse->setMaximumSize(QSize(200,30));
    coloreLineEditMouse->setMinimumSize(QSize(0,0));

    orientamentoDellaManoLineEditMouse=new QLineEdit;
    orientamentoDellaManoLineEditMouse->setPlaceholderText(tr("Inserire orientamento della mano"));
    orientamentoDellaManoLineEditMouse->setMaximumSize(QSize(200,30));
    orientamentoDellaManoLineEditMouse->setMinimumSize(QSize(0,0));
}

void MouseAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxMouse=new QDoubleSpinBox;
    prezzoDoubleSpinBoxMouse->setSuffix(" €");
    prezzoDoubleSpinBoxMouse->setMaximum(9999.99);
    prezzoDoubleSpinBoxMouse->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxMouse->setMinimumSize(QSize(0,0));
}

void MouseAddWidget::createSpinBoxes(){
    dpiMassimiSpinBoxMouse=new QSpinBox;
    dpiMassimiSpinBoxMouse->setMaximum(99999);
    dpiMassimiSpinBoxMouse->setMaximumSize(QSize(70,25));
    dpiMassimiSpinBoxMouse->setMinimumSize(QSize(0,0));
}

QString MouseAddWidget::nomeMouseValue() const{
    return nomeLineEditMouse->text();
}

QString MouseAddWidget::produttoreMouseValue() const{
    return produttoreLineEditMouse->text();
}

QString MouseAddWidget::connessioneMouseValue() const{
    return connessioneLineEditMouse->text();
}

QString MouseAddWidget::tipologiaTracciamentoMouseValue() const{
    return tipologiaTracciamentoLineEditMouse->text();
}

QString MouseAddWidget::coloreMouseValue() const{
    return coloreLineEditMouse->text();
}

QString MouseAddWidget::orientamentoDellaManoMouseValue() const{
    return orientamentoDellaManoLineEditMouse->text();
}

int MouseAddWidget::dpiMassimiMouseValue() const{
    return dpiMassimiSpinBoxMouse->value();
}

double MouseAddWidget::prezzoMouseValue() const{
    return prezzoDoubleSpinBoxMouse->value();
}

QLineEdit* MouseAddWidget::getNomeLineEditMouse() const{
    return nomeLineEditMouse;
}

QLineEdit* MouseAddWidget::getProduttoreLineEditMouse() const{
    return produttoreLineEditMouse;
}

QLineEdit* MouseAddWidget::getConnessioneLineEditMouse() const{
    return connessioneLineEditMouse;
}

QLineEdit* MouseAddWidget::getTipologiaTracciamentoLineEditMouse() const{
    return tipologiaTracciamentoLineEditMouse;
}

QLineEdit* MouseAddWidget::getColoreLineEditMouse() const{
    return coloreLineEditMouse;
}

QLineEdit* MouseAddWidget::getOrientamentoDellaManoLineEditMouse() const{
    return orientamentoDellaManoLineEditMouse;
}

QSpinBox* MouseAddWidget::getDpiMassimiSpinBoxMouse() const{
    return dpiMassimiSpinBoxMouse;
}

QDoubleSpinBox* MouseAddWidget::getPrezzoDoubleSpinBoxMouse() const{
    return prezzoDoubleSpinBoxMouse;
}
