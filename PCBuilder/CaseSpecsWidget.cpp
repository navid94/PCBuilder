#include "CaseSpecsWidget.h"
#include <QLayout>
#include <QFont>

CaseSpecsWidget::CaseSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(tipologiaLabel,3,0,1,1);
    gridLayout->addWidget(tipologiaValueLabel,3,1,1,1);
    gridLayout->addWidget(coloreLabel,4,0,1,1);
    gridLayout->addWidget(coloreValueLabel,4,1,1,1);
    gridLayout->addWidget(alimentatoreInclusoLabel,5,0,1,1);
    gridLayout->addWidget(alimentatoreInclusoValueLabel,5,1,1,1);
    gridLayout->addWidget(compatibilitaSchedaMadreLabel,6,0,1,1);
    gridLayout->addWidget(compatibilitaSchedaMadreValueLabel,6,1,1,1);
    gridLayout->addWidget(lunghezzaMassimaSchedaGraficaLabel,7,0,1,1);
    gridLayout->addWidget(lunghezzaMassimaSchedaGraficaValueLabel,7,1,1,1);
    gridLayout->addWidget(slotInterni25Label,8,0,1,1);
    gridLayout->addWidget(slotInterni25ValueLabel,8,1,1,1);
    gridLayout->addWidget(slotInterni35Label,9,0,1,1);
    gridLayout->addWidget(slotInterni35ValueLabel,9,1,1,1);
    gridLayout->addWidget(dimensioniLabel,10,0,1,1);
    gridLayout->addWidget(dimensioniValueLabel,10,1,1,1);

    setLayout(gridLayout);
}

void CaseSpecsWidget::createLabels(){
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

    tipologiaLabel=new QLabel(tr("Tipologia"));
    tipologiaLabel->setMinimumSize(QSize(0,0));
    tipologiaLabel->setFont(font_form);

    tipologiaValueLabel=new QLabel("");
    tipologiaValueLabel->setMinimumSize(QSize(0,0));
    tipologiaValueLabel->setFont(font_form);
    tipologiaValueLabel->setWordWrap(true);

    coloreLabel=new QLabel(tr("Colore"));
    coloreLabel->setMinimumSize(QSize(0,0));
    coloreLabel->setFont(font_form);

    coloreValueLabel=new QLabel("");
    coloreValueLabel->setMinimumSize(QSize(0,0));
    coloreValueLabel->setFont(font_form);
    coloreValueLabel->setWordWrap(true);

    alimentatoreInclusoLabel=new QLabel(tr("Alimentatore incluso"));
    alimentatoreInclusoLabel->setMinimumSize(QSize(0,0));
    alimentatoreInclusoLabel->setFont(font_form);

    alimentatoreInclusoValueLabel=new QLabel("");
    alimentatoreInclusoValueLabel->setMinimumSize(QSize(0,0));
    alimentatoreInclusoValueLabel->setFont(font_form);
    alimentatoreInclusoValueLabel->setWordWrap(true);

    compatibilitaSchedaMadreLabel=new QLabel(tr("Compatibilità scheda madre"));
    compatibilitaSchedaMadreLabel->setMinimumSize(QSize(0,0));
    compatibilitaSchedaMadreLabel->setFont(font_form);

    compatibilitaSchedaMadreValueLabel=new QLabel("");
    compatibilitaSchedaMadreValueLabel->setMinimumSize(QSize(0,0));
    compatibilitaSchedaMadreValueLabel->setFont(font_form);
    compatibilitaSchedaMadreValueLabel->setWordWrap(true);

    lunghezzaMassimaSchedaGraficaLabel=new QLabel(tr("Lunghezza massima scheda grafica"));
    lunghezzaMassimaSchedaGraficaLabel->setMinimumSize(QSize(0,0));
    lunghezzaMassimaSchedaGraficaLabel->setFont(font_form);

    lunghezzaMassimaSchedaGraficaValueLabel=new QLabel("");
    lunghezzaMassimaSchedaGraficaValueLabel->setMinimumSize(QSize(0,0));
    lunghezzaMassimaSchedaGraficaValueLabel->setFont(font_form);
    lunghezzaMassimaSchedaGraficaValueLabel->setWordWrap(true);

    slotInterni25Label=new QLabel(tr("Slot interni 2.5"));
    slotInterni25Label->setMinimumSize(QSize(0,0));
    slotInterni25Label->setFont(font_form);

    slotInterni25ValueLabel=new QLabel("");
    slotInterni25ValueLabel->setMinimumSize(QSize(0,0));
    slotInterni25ValueLabel->setFont(font_form);
    slotInterni25ValueLabel->setWordWrap(true);

    slotInterni35Label=new QLabel(tr("Slot interni 2.5"));
    slotInterni35Label->setMinimumSize(QSize(0,0));
    slotInterni35Label->setFont(font_form);

    slotInterni35ValueLabel=new QLabel("");
    slotInterni35ValueLabel->setMinimumSize(QSize(0,0));
    slotInterni35ValueLabel->setFont(font_form);
    slotInterni35ValueLabel->setWordWrap(true);

    dimensioniLabel=new QLabel(tr("Dimensioni"));
    dimensioniLabel->setMinimumSize(QSize(0,0));
    dimensioniLabel->setFont(font_form);

    dimensioniValueLabel=new QLabel("");
    dimensioniValueLabel->setMinimumSize(QSize(0,0));
    dimensioniValueLabel->setFont(font_form);
    dimensioniValueLabel->setWordWrap(true);
}

void CaseSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void CaseSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void CaseSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void CaseSpecsWidget::setTipologiaValueLabel(const QString& tipologia){
    tipologiaValueLabel->setText(tipologia);
}

void CaseSpecsWidget::setColoreValueLabel(const QString& colore){
    coloreValueLabel->setText(colore);
}

void CaseSpecsWidget::setAlimentatoreInclusoValueLabel(const QString& alimentatoreIncluso){
    alimentatoreInclusoValueLabel->setText(alimentatoreIncluso);
}

void CaseSpecsWidget::setCompatibilitaSchedaMadreValueLabel(const QString& compatibilitaSchedaMadre){
    compatibilitaSchedaMadreValueLabel->setText(compatibilitaSchedaMadre);
}

void CaseSpecsWidget::setLunghezzaMassimaSchedaGraficaValueLabel(const QString& lunghezzaMassimaSchedaGrafica){
    lunghezzaMassimaSchedaGraficaValueLabel->setText(lunghezzaMassimaSchedaGrafica);
}

void CaseSpecsWidget::setSlotInterni25ValueLabel(const QString& slotInterni25){
    slotInterni25ValueLabel->setText(slotInterni25);
}

void CaseSpecsWidget::setSlotInterni35ValueLabel(const QString& slotInterni35){
    slotInterni35ValueLabel->setText(slotInterni35);
}

void CaseSpecsWidget::setDimensioniValueLabel(const QString& dimensioni){
    dimensioniValueLabel->setText(dimensioni);
}
