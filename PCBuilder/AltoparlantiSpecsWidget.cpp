#include "AltoparlantiSpecsWidget.h"
#include <QLayout>
#include <QFont>

AltoparlantiSpecsWidget::AltoparlantiSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(coloreLabel,3,0,1,1);
    gridLayout->addWidget(coloreValueLabel,3,1,1,1);
    gridLayout->addWidget(configurazioneLabel,4,0,1,1);
    gridLayout->addWidget(configurazioneValueLabel,4,1,1,1);
    gridLayout->addWidget(frequenzaDiRispostaLabel,5,0,1,1);
    gridLayout->addWidget(frequenzaDiRispostaValueLabel,5,1,1,1);
    gridLayout->addWidget(potenzaTotaleLabel,6,0,1,1);
    gridLayout->addWidget(potenzaTotaleValueLabel,6,1,1,1);
    gridLayout->addWidget(potenzeLabel,7,0,1,1);
    gridLayout->addWidget(potenzeValueLabel,7,1,1,1);

    setLayout(gridLayout);
}

void AltoparlantiSpecsWidget::createLabels(){
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

    coloreLabel=new QLabel(tr("Colore"));
    coloreLabel->setMinimumSize(QSize(0,0));
    coloreLabel->setFont(font_form);

    coloreValueLabel=new QLabel("");
    coloreValueLabel->setMinimumSize(QSize(0,0));
    coloreValueLabel->setFont(font_form);
    coloreValueLabel->setWordWrap(true);

    configurazioneLabel=new QLabel(tr("Configurazione"));
    configurazioneLabel->setMinimumSize(QSize(0,0));
    configurazioneLabel->setFont(font_form);

    configurazioneValueLabel=new QLabel("");
    configurazioneValueLabel->setMinimumSize(QSize(0,0));
    configurazioneValueLabel->setFont(font_form);
    configurazioneValueLabel->setWordWrap(true);

    frequenzaDiRispostaLabel=new QLabel(tr("Frequenza di risposta"));
    frequenzaDiRispostaLabel->setMinimumSize(QSize(0,0));
    frequenzaDiRispostaLabel->setFont(font_form);

    frequenzaDiRispostaValueLabel=new QLabel("");
    frequenzaDiRispostaValueLabel->setMinimumSize(QSize(0,0));
    frequenzaDiRispostaValueLabel->setFont(font_form);
    frequenzaDiRispostaValueLabel->setWordWrap(true);

    potenzaTotaleLabel=new QLabel(tr("Potenza totale"));
    potenzaTotaleLabel->setMinimumSize(QSize(0,0));
    potenzaTotaleLabel->setFont(font_form);

    potenzaTotaleValueLabel=new QLabel("");
    potenzaTotaleValueLabel->setMinimumSize(QSize(0,0));
    potenzaTotaleValueLabel->setFont(font_form);
    potenzaTotaleValueLabel->setWordWrap(true);

    potenzeLabel=new QLabel(tr("Potenze"));
    potenzeLabel->setMinimumSize(QSize(0,0));
    potenzeLabel->setFont(font_form);

    potenzeValueLabel=new QLabel("");
    potenzeValueLabel->setMinimumSize(QSize(0,0));
    potenzeValueLabel->setFont(font_form);
    potenzeValueLabel->setWordWrap(true);
}

void AltoparlantiSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void AltoparlantiSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void AltoparlantiSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void AltoparlantiSpecsWidget::setColoreValueLabel(const QString& colore){
    coloreValueLabel->setText(colore);
}

void AltoparlantiSpecsWidget::setConfigurazioneValueLabel(const QString& configurazione){
    configurazioneValueLabel->setText(configurazione);
}

void AltoparlantiSpecsWidget::setFrequenzaDiRispostaValueLabel(const QString& frequenzaDiRisposta){
    frequenzaDiRispostaValueLabel->setText(frequenzaDiRisposta);
}

void AltoparlantiSpecsWidget::setPotenzaTotaleValueLabel(const QString& potenzaTotale){
    potenzaTotaleValueLabel->setText(potenzaTotale);
}

void AltoparlantiSpecsWidget::setPotenzeValueLabel(const QString& potenze){
    potenzeValueLabel->setText(potenze);
}
