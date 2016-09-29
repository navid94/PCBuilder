#include "MouseSpecsWidget.h"
#include <QLayout>
#include <QFont>

MouseSpecsWidget::MouseSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(connessioneLabel,3,0,1,1);
    gridLayout->addWidget(connessioneValueLabel,3,1,1,1);
    gridLayout->addWidget(tipologiaTracciamentoLabel,4,0,1,1);
    gridLayout->addWidget(tipologiaTracciamentoValueLabel,4,1,1,1);
    gridLayout->addWidget(dpiMassimiLabel,5,0,1,1);
    gridLayout->addWidget(dpiMassimiValueLabel,5,1,1,1);
    gridLayout->addWidget(coloreLabel,6,0,1,1);
    gridLayout->addWidget(coloreValueLabel,6,1,1,1);
    gridLayout->addWidget(orientamentoDellaManoLabel,7,0,1,1);
    gridLayout->addWidget(orientamentoDellaManoValueLabel,7,1,1,1);

    setLayout(gridLayout);
}

void MouseSpecsWidget::createLabels(){
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

    connessioneLabel=new QLabel(tr("Connessione"));
    connessioneLabel->setMinimumSize(QSize(0,0));
    connessioneLabel->setFont(font_form);

    connessioneValueLabel=new QLabel("");
    connessioneValueLabel->setMinimumSize(QSize(0,0));
    connessioneValueLabel->setFont(font_form);
    connessioneValueLabel->setWordWrap(true);

    tipologiaTracciamentoLabel=new QLabel(tr("Tipologia tracciamento"));
    tipologiaTracciamentoLabel->setMinimumSize(QSize(0,0));
    tipologiaTracciamentoLabel->setFont(font_form);

    tipologiaTracciamentoValueLabel=new QLabel("");
    tipologiaTracciamentoValueLabel->setMinimumSize(QSize(0,0));
    tipologiaTracciamentoValueLabel->setFont(font_form);
    tipologiaTracciamentoValueLabel->setWordWrap(true);

    dpiMassimiLabel=new QLabel(tr("DPI massimi"));
    dpiMassimiLabel->setMinimumSize(QSize(0,0));
    dpiMassimiLabel->setFont(font_form);

    dpiMassimiValueLabel=new QLabel("");
    dpiMassimiValueLabel->setMinimumSize(QSize(0,0));
    dpiMassimiValueLabel->setFont(font_form);
    dpiMassimiValueLabel->setWordWrap(true);

    coloreLabel=new QLabel(tr("Colore"));
    coloreLabel->setMinimumSize(QSize(0,0));
    coloreLabel->setFont(font_form);

    coloreValueLabel=new QLabel("");
    coloreValueLabel->setMinimumSize(QSize(0,0));
    coloreValueLabel->setFont(font_form);
    coloreValueLabel->setWordWrap(true);

    orientamentoDellaManoLabel=new QLabel(tr("Orientamento della mano"));
    orientamentoDellaManoLabel->setMinimumSize(QSize(0,0));
    orientamentoDellaManoLabel->setFont(font_form);

    orientamentoDellaManoValueLabel=new QLabel("");
    orientamentoDellaManoValueLabel->setMinimumSize(QSize(0,0));
    orientamentoDellaManoValueLabel->setFont(font_form);
    orientamentoDellaManoValueLabel->setWordWrap(true);
}

void MouseSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void MouseSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void MouseSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void MouseSpecsWidget::setConnessioneValueLabel(const QString& connessione){
    connessioneValueLabel->setText(connessione);
}

void MouseSpecsWidget::setTipologiaTracciamentoValueLabel(const QString& tipologiaTracciamento){
    tipologiaTracciamentoValueLabel->setText(tipologiaTracciamento);
}

void MouseSpecsWidget::setDpiMassimiValueLabel(const QString& dpiMassimi){
    dpiMassimiValueLabel->setText(dpiMassimi);
}

void MouseSpecsWidget::setColoreValueLabel(const QString& colore){
    coloreValueLabel->setText(colore);
}

void MouseSpecsWidget::setOrientamentoDellaManoValueLabel(const QString& orientamentoDellaMano){
    orientamentoDellaManoValueLabel->setText(orientamentoDellaMano);
}
