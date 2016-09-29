#include "UnitaOtticaAddWidget.h"
#include <QLayout>
#include <QFont>

UnitaOtticaAddWidget::UnitaOtticaAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelUnitaOttica,0,0,1,1);
    gridLayout->addWidget(nomeLineEditUnitaOttica,0,1,1,1);
    gridLayout->addWidget(prezzoLabelUnitaOttica,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxUnitaOttica,1,1,1,1);
    gridLayout->addWidget(produttoreLabelUnitaOttica,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditUnitaOttica,2,1,1,1);
    gridLayout->addWidget(fattoreDiFormaLabelUnitaOttica,3,0,1,1);
    gridLayout->addWidget(fattoreDiFormaLineEditUnitaOttica,3,1,1,1);
    gridLayout->addWidget(interfacciaLabelUnitaOttica,4,0,1,1);
    gridLayout->addWidget(interfacciaLineEditUnitaOttica,4,1,1,1);
    gridLayout->addWidget(cacheLabelUnitaOttica,5,0,1,1);
    gridLayout->addWidget(cacheLineEditUnitaOttica,5,1,1,1);
    gridLayout->addWidget(velocitaLabelUnitaOttica,6,0,1,1);
    gridLayout->addWidget(velocitaLineEditUnitaOttica,6,1,1,1);
    setLayout(gridLayout);
}

void UnitaOtticaAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelUnitaOttica=new QLabel(tr("Nome:"));
    nomeLabelUnitaOttica->setFont(font_formLabel);
    nomeLabelUnitaOttica->setMaximumSize(QSize(70,30));
    nomeLabelUnitaOttica->setMinimumSize(QSize(0,0));

    prezzoLabelUnitaOttica=new QLabel(tr("Prezzo:"));
    prezzoLabelUnitaOttica->setFont(font_formLabel);
    prezzoLabelUnitaOttica->setMaximumSize(QSize(80,30));
    prezzoLabelUnitaOttica->setMinimumSize(QSize(0,0));

    produttoreLabelUnitaOttica=new QLabel(tr("Produttore:"));
    produttoreLabelUnitaOttica->setFont(font_formLabel);
    produttoreLabelUnitaOttica->setMaximumSize(QSize(110,30));
    produttoreLabelUnitaOttica->setMinimumSize(QSize(0,0));

    fattoreDiFormaLabelUnitaOttica=new QLabel(tr("Fattore di forma:"));
    fattoreDiFormaLabelUnitaOttica->setFont(font_formLabel);
    fattoreDiFormaLabelUnitaOttica->setMaximumSize(QSize(160,30));
    fattoreDiFormaLabelUnitaOttica->setMinimumSize(QSize(0,0));

    interfacciaLabelUnitaOttica=new QLabel(tr("Interfaccia:"));
    interfacciaLabelUnitaOttica->setFont(font_formLabel);
    interfacciaLabelUnitaOttica->setMaximumSize(QSize(110,30));
    interfacciaLabelUnitaOttica->setMinimumSize(QSize(0,0));

    cacheLabelUnitaOttica=new QLabel("Cache:");
    cacheLabelUnitaOttica->setFont(font_formLabel);
    cacheLabelUnitaOttica->setMaximumSize(QSize(70,30));
    cacheLabelUnitaOttica->setMinimumSize(QSize(0,0));

    velocitaLabelUnitaOttica=new QLabel(tr("Velocità:"));
    velocitaLabelUnitaOttica->setFont(font_formLabel);
    velocitaLabelUnitaOttica->setMaximumSize(QSize(90,30));
    velocitaLabelUnitaOttica->setMinimumSize(QSize(0,0));
}

void UnitaOtticaAddWidget::createLineEdits(){
    nomeLineEditUnitaOttica=new QLineEdit;
    nomeLineEditUnitaOttica->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    nomeLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    produttoreLineEditUnitaOttica=new QLineEdit;
    produttoreLineEditUnitaOttica->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    produttoreLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    fattoreDiFormaLineEditUnitaOttica=new QLineEdit;
    fattoreDiFormaLineEditUnitaOttica->setPlaceholderText(tr("Inserire fattore di forma"));
    fattoreDiFormaLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    fattoreDiFormaLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    interfacciaLineEditUnitaOttica=new QLineEdit;
    interfacciaLineEditUnitaOttica->setPlaceholderText(tr("Inserire interfaccia"));
    interfacciaLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    interfacciaLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    cacheLineEditUnitaOttica=new QLineEdit;
    cacheLineEditUnitaOttica->setPlaceholderText(tr("Inserire cache"));
    cacheLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    cacheLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    velocitaLineEditUnitaOttica=new QLineEdit;
    velocitaLineEditUnitaOttica->setPlaceholderText(tr("Inserire velocita"));
    velocitaLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    velocitaLineEditUnitaOttica->setMinimumSize(QSize(0,0));
}

void UnitaOtticaAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxUnitaOttica=new QDoubleSpinBox;
    prezzoDoubleSpinBoxUnitaOttica->setSuffix(" €");
    prezzoDoubleSpinBoxUnitaOttica->setMaximum(9999.99);
    prezzoDoubleSpinBoxUnitaOttica->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxUnitaOttica->setMinimumSize(QSize(0,0));
}

QString UnitaOtticaAddWidget::nomeUnitaOtticaValue() const{
    return nomeLineEditUnitaOttica->text();
}

QString UnitaOtticaAddWidget::produttoreUnitaOtticaValue() const{
    return produttoreLineEditUnitaOttica->text();
}

QString UnitaOtticaAddWidget::fattoreDiFormaUnitaOtticaValue() const{
    return fattoreDiFormaLineEditUnitaOttica->text();
}

QString UnitaOtticaAddWidget::interfacciaUnitaOtticaValue() const{
    return interfacciaLineEditUnitaOttica->text();
}

QString UnitaOtticaAddWidget::cacheUnitaOtticaValue() const{
    return cacheLineEditUnitaOttica->text();
}

QString UnitaOtticaAddWidget::velocitaUnitaOtticaValue() const{
    return velocitaLineEditUnitaOttica->text();
}

double UnitaOtticaAddWidget::prezzoUnitaOtticaValue() const{
    return prezzoDoubleSpinBoxUnitaOttica->value();
}

QLineEdit* UnitaOtticaAddWidget::getNomeLineEditUnitaOttica() const{
    return nomeLineEditUnitaOttica;
}

QLineEdit* UnitaOtticaAddWidget::getProduttoreLineEditUnitaOttica() const{
    return produttoreLineEditUnitaOttica;
}

QLineEdit* UnitaOtticaAddWidget::getFattoreDiFormaLineEditUnitaOttica() const{
    return fattoreDiFormaLineEditUnitaOttica;
}

QLineEdit* UnitaOtticaAddWidget::getInterfacciaLineEditUnitaOttica() const{
    return interfacciaLineEditUnitaOttica;
}

QLineEdit* UnitaOtticaAddWidget::getCacheLineEditUnitaOttica() const{
    return cacheLineEditUnitaOttica;
}

QLineEdit* UnitaOtticaAddWidget::getVelocitaLineEditUnitaOttica() const{
    return velocitaLineEditUnitaOttica;
}

QDoubleSpinBox* UnitaOtticaAddWidget::getPrezzoDoubleSpinBoxUnitaOttica() const{
    return prezzoDoubleSpinBoxUnitaOttica;
}
