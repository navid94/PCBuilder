#include "SistemaOperativoSpecsWidget.h"
#include <QLayout>
#include <QFont>

SistemaOperativoSpecsWidget::SistemaOperativoSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(modalitaLabel,3,0,1,1);
    gridLayout->addWidget(modalitaValueLabel,3,1,1,1);
    gridLayout->addWidget(memoriaMassimaSupportataLabel,4,0,1,1);
    gridLayout->addWidget(memoriaMassimaSupportataValueLabel,4,1,1,1);

    setLayout(gridLayout);
}

void SistemaOperativoSpecsWidget::createLabels(){
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

    modalitaLabel=new QLabel(tr("Modalità"));
    modalitaLabel->setMinimumSize(QSize(0,0));
    modalitaLabel->setFont(font_form);

    modalitaValueLabel=new QLabel("");
    modalitaValueLabel->setMinimumSize(QSize(0,0));
    modalitaValueLabel->setFont(font_form);
    modalitaValueLabel->setWordWrap(true);

    memoriaMassimaSupportataLabel=new QLabel(tr("Memoria massima supportata"));
    memoriaMassimaSupportataLabel->setMinimumSize(QSize(0,0));
    memoriaMassimaSupportataLabel->setFont(font_form);

    memoriaMassimaSupportataValueLabel=new QLabel("");
    memoriaMassimaSupportataValueLabel->setMinimumSize(QSize(0,0));
    memoriaMassimaSupportataValueLabel->setFont(font_form);
    memoriaMassimaSupportataValueLabel->setWordWrap(true);
}

void SistemaOperativoSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void SistemaOperativoSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void SistemaOperativoSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void SistemaOperativoSpecsWidget::setModalitaValueLabel(const QString& modalita){
    modalitaValueLabel->setText(modalita);
}

void SistemaOperativoSpecsWidget::setMemoriaMassimaSupportataValueLabel(const QString& memoriaMassimaSupportata){
    memoriaMassimaSupportataValueLabel->setText(memoriaMassimaSupportata);
}
