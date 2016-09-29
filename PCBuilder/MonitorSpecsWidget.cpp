#include "MonitorSpecsWidget.h"
#include <QLayout>
#include <QFont>

MonitorSpecsWidget::MonitorSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(risoluzioneRaccomandataLabel,3,0,1,1);
    gridLayout->addWidget(risoluzioneRaccomandataValueLabel,3,1,1,1);
    gridLayout->addWidget(widescreenLabel,4,0,1,1);
    gridLayout->addWidget(widescreenValueLabel,4,1,1,1);
    gridLayout->addWidget(formatoLabel,5,0,1,1);
    gridLayout->addWidget(formatoValueLabel,5,1,1,1);
    gridLayout->addWidget(angoloDiVisualizzazioneLabel,6,0,1,1);
    gridLayout->addWidget(angoloDiVisualizzazioneValueLabel,6,1,1,1);
    gridLayout->addWidget(coloriDelDisplayLabel,7,0,1,1);
    gridLayout->addWidget(coloriDelDisplayValueLabel,7,1,1,1);
    gridLayout->addWidget(luminositaLabel,8,0,1,1);
    gridLayout->addWidget(luminositaValueLabel,8,1,1,1);
    gridLayout->addWidget(rapportoDiContrastoLabel,9,0,1,1);
    gridLayout->addWidget(rapportoDiContrastoValueLabel,9,1,1,1);
    gridLayout->addWidget(tempoDiRispostaLabel,10,0,1,1);
    gridLayout->addWidget(tempoDiRispostaValueLabel,10,1,1,1);
    gridLayout->addWidget(tipologiaDelDisplayLabel,11,0,1,1);
    gridLayout->addWidget(tipologiaDelDisplayValueLabel,11,1,1,1);
    gridLayout->addWidget(altoparlantiIncorporatiLabel,12,0,1,1);
    gridLayout->addWidget(altoparlantiIncorporatiValueLabel,12,1,1,1);
    gridLayout->addWidget(frequenzaDiAggiornamentoLabel,13,0,1,1);
    gridLayout->addWidget(frequenzaDiAggiornamentoValueLabel,13,1,1,1);

    setLayout(gridLayout);
}

void MonitorSpecsWidget::createLabels(){
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

    risoluzioneRaccomandataLabel=new QLabel(tr("Risoluzione raccomandata"));
    risoluzioneRaccomandataLabel->setMinimumSize(QSize(0,0));
    risoluzioneRaccomandataLabel->setFont(font_form);

    risoluzioneRaccomandataValueLabel=new QLabel("");
    risoluzioneRaccomandataValueLabel->setMinimumSize(QSize(0,0));
    risoluzioneRaccomandataValueLabel->setFont(font_form);
    risoluzioneRaccomandataValueLabel->setWordWrap(true);

    widescreenLabel=new QLabel(tr("Widescreen"));
    widescreenLabel->setMinimumSize(QSize(0,0));
    widescreenLabel->setFont(font_form);

    widescreenValueLabel=new QLabel("");
    widescreenValueLabel->setMinimumSize(QSize(0,0));
    widescreenValueLabel->setFont(font_form);
    widescreenValueLabel->setWordWrap(true);

    formatoLabel=new QLabel(tr("Formato"));
    formatoLabel->setMinimumSize(QSize(0,0));
    formatoLabel->setFont(font_form);

    formatoValueLabel=new QLabel("");
    formatoValueLabel->setMinimumSize(QSize(0,0));
    formatoValueLabel->setFont(font_form);
    formatoValueLabel->setWordWrap(true);

    angoloDiVisualizzazioneLabel=new QLabel(tr("Angolo di visualizzazione"));
    angoloDiVisualizzazioneLabel->setMinimumSize(QSize(0,0));
    angoloDiVisualizzazioneLabel->setFont(font_form);

    angoloDiVisualizzazioneValueLabel=new QLabel("");
    angoloDiVisualizzazioneValueLabel->setMinimumSize(QSize(0,0));
    angoloDiVisualizzazioneValueLabel->setFont(font_form);
    angoloDiVisualizzazioneValueLabel->setWordWrap(true);

    coloriDelDisplayLabel=new QLabel(tr("Colori del display"));
    coloriDelDisplayLabel->setMinimumSize(QSize(0,0));
    coloriDelDisplayLabel->setFont(font_form);

    coloriDelDisplayValueLabel=new QLabel("");
    coloriDelDisplayValueLabel->setMinimumSize(QSize(0,0));
    coloriDelDisplayValueLabel->setFont(font_form);
    coloriDelDisplayValueLabel->setWordWrap(true);

    luminositaLabel=new QLabel(tr("Luminosità"));
    luminositaLabel->setMinimumSize(QSize(0,0));
    luminositaLabel->setFont(font_form);

    luminositaValueLabel=new QLabel("");
    luminositaValueLabel->setMinimumSize(QSize(0,0));
    luminositaValueLabel->setFont(font_form);
    luminositaValueLabel->setWordWrap(true);

    rapportoDiContrastoLabel=new QLabel(tr("Rapporto di contrasto"));
    rapportoDiContrastoLabel->setMinimumSize(QSize(0,0));
    rapportoDiContrastoLabel->setFont(font_form);

    rapportoDiContrastoValueLabel=new QLabel("");
    rapportoDiContrastoValueLabel->setMinimumSize(QSize(0,0));
    rapportoDiContrastoValueLabel->setFont(font_form);
    rapportoDiContrastoValueLabel->setWordWrap(true);

    tempoDiRispostaLabel=new QLabel(tr("Tempo di risposta"));
    tempoDiRispostaLabel->setMinimumSize(QSize(0,0));
    tempoDiRispostaLabel->setFont(font_form);

    tempoDiRispostaValueLabel=new QLabel("");
    tempoDiRispostaValueLabel->setMinimumSize(QSize(0,0));
    tempoDiRispostaValueLabel->setFont(font_form);
    tempoDiRispostaValueLabel->setWordWrap(true);

    tipologiaDelDisplayLabel=new QLabel(tr("Tipologia del display"));
    tipologiaDelDisplayLabel->setMinimumSize(QSize(0,0));
    tipologiaDelDisplayLabel->setFont(font_form);

    tipologiaDelDisplayValueLabel=new QLabel("");
    tipologiaDelDisplayValueLabel->setMinimumSize(QSize(0,0));
    tipologiaDelDisplayValueLabel->setFont(font_form);
    tipologiaDelDisplayValueLabel->setWordWrap(true);

    altoparlantiIncorporatiLabel=new QLabel(tr("Altoparlanti incorporati"));
    altoparlantiIncorporatiLabel->setMinimumSize(QSize(0,0));
    altoparlantiIncorporatiLabel->setFont(font_form);

    altoparlantiIncorporatiValueLabel=new QLabel("");
    altoparlantiIncorporatiValueLabel->setMinimumSize(QSize(0,0));
    altoparlantiIncorporatiValueLabel->setFont(font_form);
    altoparlantiIncorporatiValueLabel->setWordWrap(true);

    frequenzaDiAggiornamentoLabel=new QLabel(tr("Frequenza di aggiornamento"));
    frequenzaDiAggiornamentoLabel->setMinimumSize(QSize(0,0));
    frequenzaDiAggiornamentoLabel->setFont(font_form);

    frequenzaDiAggiornamentoValueLabel=new QLabel("");
    frequenzaDiAggiornamentoValueLabel->setMinimumSize(QSize(0,0));
    frequenzaDiAggiornamentoValueLabel->setFont(font_form);
    frequenzaDiAggiornamentoValueLabel->setWordWrap(true);
}

void MonitorSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void MonitorSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void MonitorSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void MonitorSpecsWidget::setRisoluzioneRaccomandataValueLabel(const QString& risoluzioneRaccomandata){
    risoluzioneRaccomandataValueLabel->setText(risoluzioneRaccomandata);
}

void MonitorSpecsWidget::setWidescreenValueLabel(const QString& widescreen){
    widescreenValueLabel->setText(widescreen);
}

void MonitorSpecsWidget::setFormatoValueLabel(const QString& formato){
    formatoValueLabel->setText(formato);
}

void MonitorSpecsWidget::setAngoloDiVisualizzazioneValueLabel(const QString& angoloDiVisualizzazione){
    angoloDiVisualizzazioneValueLabel->setText(angoloDiVisualizzazione);
}

void MonitorSpecsWidget::setColoriDelDisplayValueLabel(const QString& coloriDelDisplay){
    coloriDelDisplayValueLabel->setText(coloriDelDisplay);
}

void MonitorSpecsWidget::setLuminositaValueLabel(const QString& luminosita){
    luminositaValueLabel->setText(luminosita);
}

void MonitorSpecsWidget::setRapportoDiContrastoValueLabel(const QString& rapportoDiContrasto){
    rapportoDiContrastoValueLabel->setText(rapportoDiContrasto);
}

void MonitorSpecsWidget::setTempoDiRispostaValueLabel(const QString& tempoDiRisposta){
    tempoDiRispostaValueLabel->setText(tempoDiRisposta);
}

void MonitorSpecsWidget::setTipologiaDelDisplayValueLabel(const QString& tipologiaDelDisplay){
    tipologiaDelDisplayValueLabel->setText(tipologiaDelDisplay);
}

void MonitorSpecsWidget::setAltoparlantiIncorporatiValueLabel(const QString& altoparlantiIncorporati){
    altoparlantiIncorporatiValueLabel->setText(altoparlantiIncorporati);
}

void MonitorSpecsWidget::setFrequenzaDiAggiornamentoValueLabel(const QString& frequenzaDiAggiornamento){
    frequenzaDiAggiornamentoValueLabel->setText(frequenzaDiAggiornamento);
}
