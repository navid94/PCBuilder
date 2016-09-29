#include "SistemaOperativoAddWidget.h"

#include <QLayout>
#include <QFont>

SistemaOperativoAddWidget::SistemaOperativoAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelSistemaOperativo,0,0,1,1);
    gridLayout->addWidget(nomeLineEditSistemaOperativo,0,1,1,1);
    gridLayout->addWidget(prezzoLabelSistemaOperativo,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxSistemaOperativo,1,1,1,1);
    gridLayout->addWidget(produttoreLabelSistemaOperativo,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditSistemaOperativo,2,1,1,1);
    gridLayout->addWidget(modalitaLabelSistemaOperativo,3,0,1,1);
    gridLayout->addWidget(modalitaLineEditSistemaOperativo,3,1,1,1);
    gridLayout->addWidget(memoriaMassimaSupportataLabelSistemaOperativo,4,0,1,1);
    gridLayout->addWidget(memoriaMassimaSupportataLineEditSistemaOperativo,4,1,1,1);
    setLayout(gridLayout);
}

void SistemaOperativoAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelSistemaOperativo=new QLabel(tr("Nome:"));
    nomeLabelSistemaOperativo->setFont(font_formLabel);
    nomeLabelSistemaOperativo->setMaximumSize(QSize(70,30));
    nomeLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    prezzoLabelSistemaOperativo=new QLabel(tr("Prezzo:"));
    prezzoLabelSistemaOperativo->setFont(font_formLabel);
    prezzoLabelSistemaOperativo->setMaximumSize(QSize(80,30));
    prezzoLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    produttoreLabelSistemaOperativo=new QLabel(tr("Produttore:"));
    produttoreLabelSistemaOperativo->setFont(font_formLabel);
    produttoreLabelSistemaOperativo->setMaximumSize(QSize(110,30));
    produttoreLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    modalitaLabelSistemaOperativo=new QLabel(tr("Modalità:"));
    modalitaLabelSistemaOperativo->setFont(font_formLabel);
    modalitaLabelSistemaOperativo->setMaximumSize(QSize(90,30));
    modalitaLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    memoriaMassimaSupportataLabelSistemaOperativo=new QLabel(tr("Memoria massima supportata:"));
    memoriaMassimaSupportataLabelSistemaOperativo->setFont(font_formLabel);
    memoriaMassimaSupportataLabelSistemaOperativo->setMaximumSize(QSize(180,50));
    memoriaMassimaSupportataLabelSistemaOperativo->setMinimumSize(QSize(0,0));
}

void SistemaOperativoAddWidget::createLineEdits(){
    nomeLineEditSistemaOperativo=new QLineEdit;
    nomeLineEditSistemaOperativo->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    nomeLineEditSistemaOperativo->setMinimumSize(QSize(0,0));

    produttoreLineEditSistemaOperativo=new QLineEdit;
    produttoreLineEditSistemaOperativo->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    produttoreLineEditSistemaOperativo->setMinimumSize(QSize(0,0));

    modalitaLineEditSistemaOperativo=new QLineEdit;
    modalitaLineEditSistemaOperativo->setPlaceholderText(tr("Inserire modalità"));
    modalitaLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    modalitaLineEditSistemaOperativo->setMinimumSize(QSize(0,0));

    memoriaMassimaSupportataLineEditSistemaOperativo=new QLineEdit;
    memoriaMassimaSupportataLineEditSistemaOperativo->setPlaceholderText(tr("Inserire memoria massima supportata"));
    memoriaMassimaSupportataLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    memoriaMassimaSupportataLineEditSistemaOperativo->setMinimumSize(QSize(0,0));
}

void SistemaOperativoAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxSistemaOperativo=new QDoubleSpinBox;
    prezzoDoubleSpinBoxSistemaOperativo->setSuffix(" €");
    prezzoDoubleSpinBoxSistemaOperativo->setMaximum(9999.99);
    prezzoDoubleSpinBoxSistemaOperativo->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxSistemaOperativo->setMinimumSize(QSize(0,0));
}

QString SistemaOperativoAddWidget::nomeSistemaOperativoValue() const{
    return nomeLineEditSistemaOperativo->text();
}

QString SistemaOperativoAddWidget::produttoreSistemaOperativoValue() const{
    return produttoreLineEditSistemaOperativo->text();
}

QString SistemaOperativoAddWidget::modalitaSistemaOperativoValue() const{
    return modalitaLineEditSistemaOperativo->text();
}

QString SistemaOperativoAddWidget::memoriaMassimaSupportataSistemaOperativoValue() const{
    return memoriaMassimaSupportataLineEditSistemaOperativo->text();
}

double SistemaOperativoAddWidget::prezzoSistemaOperativoValue() const{
    return prezzoDoubleSpinBoxSistemaOperativo->value();
}

QLineEdit* SistemaOperativoAddWidget::getNomeLineEditSistemaOperativo() const{
    return nomeLineEditSistemaOperativo;
}

QLineEdit* SistemaOperativoAddWidget::getProduttoreLineEditSistemaOperativo() const{
    return produttoreLineEditSistemaOperativo;
}

QLineEdit* SistemaOperativoAddWidget::getModalitaLineEditSistemaOperativo() const{
    return modalitaLineEditSistemaOperativo;
}

QLineEdit* SistemaOperativoAddWidget::getMemoriaMassimaSupportataLineEditSistemaOperativo() const{
    return memoriaMassimaSupportataLineEditSistemaOperativo;
}

QDoubleSpinBox* SistemaOperativoAddWidget::getPrezzoDoubleSpinBoxSistemaOperativo() const{
    return prezzoDoubleSpinBoxSistemaOperativo;
}
