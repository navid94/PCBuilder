#include "AlimentatoreSpecsWidget.h"
#include <QLayout>
#include <QFont>

AlimentatoreSpecsWidget::AlimentatoreSpecsWidget(QWidget* parent):QWidget(parent){
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
    gridLayout->addWidget(wattaggioLabel,4,0,1,1);
    gridLayout->addWidget(wattaggioValueLabel,4,1,1,1);
    gridLayout->addWidget(modulareLabel,5,0,1,1);
    gridLayout->addWidget(modulareValueLabel,5,1,1,1);
    gridLayout->addWidget(certificazioneDiEfficienzaLabel,6,0,1,1);
    gridLayout->addWidget(certificazioneDiEfficienzaValueLabel,6,1,1,1);
    gridLayout->addWidget(efficienzaLabel,7,0,1,1);
    gridLayout->addWidget(efficienzaValueLabel,7,1,1,1);

    setLayout(gridLayout);
}

void AlimentatoreSpecsWidget::createLabels(){
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

    wattaggioLabel=new QLabel(tr("Wattaggio"));
    wattaggioLabel->setMinimumSize(QSize(0,0));
    wattaggioLabel->setFont(font_form);

    wattaggioValueLabel=new QLabel("");
    wattaggioValueLabel->setMinimumSize(QSize(0,0));
    wattaggioValueLabel->setFont(font_form);
    wattaggioValueLabel->setWordWrap(true);

    modulareLabel=new QLabel(tr("Modulare"));
    modulareLabel->setMinimumSize(QSize(0,0));
    modulareLabel->setFont(font_form);

    modulareValueLabel=new QLabel("");
    modulareValueLabel->setMinimumSize(QSize(0,0));
    modulareValueLabel->setFont(font_form);
    modulareValueLabel->setWordWrap(true);

    certificazioneDiEfficienzaLabel=new QLabel(tr("Certificazione di efficienza"));
    certificazioneDiEfficienzaLabel->setMinimumSize(QSize(0,0));
    certificazioneDiEfficienzaLabel->setFont(font_form);

    certificazioneDiEfficienzaValueLabel=new QLabel("");
    certificazioneDiEfficienzaValueLabel->setMinimumSize(QSize(0,0));
    certificazioneDiEfficienzaValueLabel->setFont(font_form);
    certificazioneDiEfficienzaValueLabel->setWordWrap(true);

    efficienzaLabel=new QLabel(tr("Efficienza"));
    efficienzaLabel->setMinimumSize(QSize(0,0));
    efficienzaLabel->setFont(font_form);

    efficienzaValueLabel=new QLabel("");
    efficienzaValueLabel->setMinimumSize(QSize(0,0));
    efficienzaValueLabel->setFont(font_form);
    efficienzaValueLabel->setWordWrap(true);
}

void AlimentatoreSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void AlimentatoreSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void AlimentatoreSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void AlimentatoreSpecsWidget::setTipologiaValueLabel(const QString& tipologia){
    tipologiaValueLabel->setText(tipologia);
}

void AlimentatoreSpecsWidget::setWattaggioValueLabel(const QString& wattaggio){
    wattaggioValueLabel->setText(wattaggio);
}

void AlimentatoreSpecsWidget::setModulareValueLabel(const QString& modulare){
    modulareValueLabel->setText(modulare);
}

void AlimentatoreSpecsWidget::setCertificazioneDiEfficienzaValueLabel(const QString& certificazioneDiEfficienza){
    certificazioneDiEfficienzaValueLabel->setText(certificazioneDiEfficienza);
}

void AlimentatoreSpecsWidget::setEfficienzaValueLabel(const QString& efficienza){
    efficienzaValueLabel->setText(efficienza);
}
