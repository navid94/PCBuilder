#include "MonitorAddWidget.h"

#include <QLayout>
#include <QFont>

MonitorAddWidget::MonitorAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createCheckBoxes();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelMonitor,0,0,1,1);
    gridLayout->addWidget(nomeLineEditMonitor,0,1,1,1);
    gridLayout->addWidget(prezzoLabelMonitor,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxMonitor,1,1,1,1);
    gridLayout->addWidget(produttoreLabelMonitor,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditMonitor,2,1,1,1);
    gridLayout->addWidget(risoluzioneRaccomandataLabelMonitor,3,0,1,1);
    gridLayout->addWidget(risoluzioneRaccomandataLineEditMonitor,3,1,1,1);
    gridLayout->addWidget(formatoLabelMonitor,4,0,1,1);
    gridLayout->addWidget(formatoLineEditMonitor,4,1,1,1);
    gridLayout->addWidget(angoloDiVisualizzazioneLabelMonitor,5,0,1,1);
    gridLayout->addWidget(angoloDiVisualizzazioneLineEditMonitor,5,1,1,1);
    gridLayout->addWidget(coloriDelDisplayLabelMonitor,6,0,1,1);
    gridLayout->addWidget(coloriDelDisplayLineEditMonitor,6,1,1,1);
    gridLayout->addWidget(luminositaLabelMonitor,7,0,1,1);
    gridLayout->addWidget(luminositaLineEditMonitor,7,1,1,1);
    gridLayout->addWidget(rapportoDiContrastoLabelMonitor,8,0,1,1);
    gridLayout->addWidget(rapportoDiContrastoLineEditMonitor,8,1,1,1);
    gridLayout->addWidget(altoparlantiIncorporatiCheckBoxMonitor,9,1,1,1);
    gridLayout->addWidget(widescreenCheckBoxMonitor,10,1,1,1);
    gridLayout->addWidget(tempoDiRispostaLabelMonitor,11,0,1,1);
    gridLayout->addWidget(tempoDiRispostaLineEditMonitor,11,1,1,1);
    gridLayout->addWidget(tipologiaDisplayLabelMonitor,12,0,1,1);
    gridLayout->addWidget(tipologiaDisplayLineEditMonitor,12,1,1,1);
    gridLayout->addWidget(frequenzaDiAggiornamentoLabelMonitor,13,0,1,1);
    gridLayout->addWidget(frequenzaDiAggiornamentoLineEditMonitor,13,1,1,1);
    setLayout(gridLayout);
}

void MonitorAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelMonitor=new QLabel(tr("Nome:"));
    nomeLabelMonitor->setFont(font_formLabel);
    nomeLabelMonitor->setMaximumSize(QSize(70,30));
    nomeLabelMonitor->setMinimumSize(QSize(0,0));

    prezzoLabelMonitor=new QLabel(tr("Prezzo:"));
    prezzoLabelMonitor->setFont(font_formLabel);
    prezzoLabelMonitor->setMaximumSize(QSize(80,30));
    prezzoLabelMonitor->setMinimumSize(QSize(0,0));

    produttoreLabelMonitor=new QLabel(tr("Produttore:"));
    produttoreLabelMonitor->setFont(font_formLabel);
    produttoreLabelMonitor->setMaximumSize(QSize(110,30));
    produttoreLabelMonitor->setMinimumSize(QSize(0,0));

    risoluzioneRaccomandataLabelMonitor=new QLabel(tr("Risoluzione \nraccomandata:"));
    risoluzioneRaccomandataLabelMonitor->setFont(font_formLabel);
    risoluzioneRaccomandataLabelMonitor->setMaximumSize(QSize(150,50));
    risoluzioneRaccomandataLabelMonitor->setMinimumSize(QSize(0,0));

    formatoLabelMonitor=new QLabel(tr("Formato:"));
    formatoLabelMonitor->setFont(font_formLabel);
    formatoLabelMonitor->setMaximumSize(QSize(90,30));
    formatoLabelMonitor->setMinimumSize(QSize(0,0));

    angoloDiVisualizzazioneLabelMonitor=new QLabel(tr("Angolo di \nvisualizzazione:"));
    angoloDiVisualizzazioneLabelMonitor->setFont(font_formLabel);
    angoloDiVisualizzazioneLabelMonitor->setMaximumSize(QSize(150,50));
    angoloDiVisualizzazioneLabelMonitor->setMinimumSize(QSize(0,0));

    coloriDelDisplayLabelMonitor=new QLabel(tr("Colori del ")+("display:"));
    coloriDelDisplayLabelMonitor->setFont(font_formLabel);
    coloriDelDisplayLabelMonitor->setMaximumSize(QSize(170,30));
    coloriDelDisplayLabelMonitor->setMinimumSize(QSize(0,0));

    luminositaLabelMonitor=new QLabel(tr("Luminosità:"));
    luminositaLabelMonitor->setFont(font_formLabel);
    luminositaLabelMonitor->setMaximumSize(QSize(110,30));
    luminositaLabelMonitor->setMinimumSize(QSize(0,0));

    rapportoDiContrastoLabelMonitor=new QLabel(tr("Rapporto di \ncontrasto:"));
    rapportoDiContrastoLabelMonitor->setFont(font_formLabel);
    rapportoDiContrastoLabelMonitor->setMaximumSize(QSize(120,50));
    rapportoDiContrastoLabelMonitor->setMinimumSize(QSize(0,0));

    tempoDiRispostaLabelMonitor=new QLabel(tr("Tempo di risposta:"));
    tempoDiRispostaLabelMonitor->setFont(font_formLabel);
    tempoDiRispostaLabelMonitor->setMaximumSize(QSize(200,30));
    tempoDiRispostaLabelMonitor->setMinimumSize(QSize(0,0));

    tipologiaDisplayLabelMonitor=new QLabel(tr("Tipologia ")+("display:"));
    tipologiaDisplayLabelMonitor->setFont(font_formLabel);
    tipologiaDisplayLabelMonitor->setMaximumSize(QSize(170,30));
    tipologiaDisplayLabelMonitor->setMinimumSize(QSize(0,0));

    frequenzaDiAggiornamentoLabelMonitor=new QLabel(tr("Frequenza di \naggiornamento:"));
    frequenzaDiAggiornamentoLabelMonitor->setFont(font_formLabel);
    frequenzaDiAggiornamentoLabelMonitor->setMaximumSize(QSize(150,50));
    frequenzaDiAggiornamentoLabelMonitor->setMinimumSize(QSize(0,0));
}

void MonitorAddWidget::createLineEdits(){
    nomeLineEditMonitor=new QLineEdit;
    nomeLineEditMonitor->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditMonitor->setMaximumSize(QSize(200,30));
    nomeLineEditMonitor->setMinimumSize(QSize(0,0));

    produttoreLineEditMonitor=new QLineEdit;
    produttoreLineEditMonitor->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditMonitor->setMaximumSize(QSize(200,30));
    produttoreLineEditMonitor->setMinimumSize(QSize(0,0));

    risoluzioneRaccomandataLineEditMonitor=new QLineEdit;
    risoluzioneRaccomandataLineEditMonitor->setPlaceholderText(tr("Inserire risoluzione raccomandata"));
    risoluzioneRaccomandataLineEditMonitor->setMaximumSize(QSize(200,30));
    risoluzioneRaccomandataLineEditMonitor->setMinimumSize(QSize(0,0));

    formatoLineEditMonitor=new QLineEdit;
    formatoLineEditMonitor->setPlaceholderText(tr("Inserire formato"));
    formatoLineEditMonitor->setPlaceholderText(tr("Inserire formato"));
    formatoLineEditMonitor->setMaximumSize(QSize(200,30));
    formatoLineEditMonitor->setMinimumSize(QSize(0,0));

    angoloDiVisualizzazioneLineEditMonitor=new QLineEdit;
    angoloDiVisualizzazioneLineEditMonitor->setPlaceholderText(tr("Inserire angolo di visualizzazione"));
    angoloDiVisualizzazioneLineEditMonitor->setMaximumSize(QSize(200,30));
    angoloDiVisualizzazioneLineEditMonitor->setMinimumSize(QSize(0,0));

    coloriDelDisplayLineEditMonitor=new QLineEdit;
    coloriDelDisplayLineEditMonitor->setPlaceholderText(tr("Inserire colori del display"));
    coloriDelDisplayLineEditMonitor->setMaximumSize(QSize(200,30));
    coloriDelDisplayLineEditMonitor->setMinimumSize(QSize(0,0));

    luminositaLineEditMonitor=new QLineEdit;
    luminositaLineEditMonitor->setPlaceholderText(tr("Inserire luminosità"));
    luminositaLineEditMonitor->setMaximumSize(QSize(200,30));
    luminositaLineEditMonitor->setMinimumSize(QSize(0,0));

    rapportoDiContrastoLineEditMonitor=new QLineEdit;
    rapportoDiContrastoLineEditMonitor->setPlaceholderText(tr("Inserire rapporto di contrasto"));
    rapportoDiContrastoLineEditMonitor->setMaximumSize(QSize(200,30));
    rapportoDiContrastoLineEditMonitor->setMinimumSize(QSize(0,0));

    tempoDiRispostaLineEditMonitor=new QLineEdit;
    tempoDiRispostaLineEditMonitor->setPlaceholderText(tr("Inserire tempo di risposta"));
    tempoDiRispostaLineEditMonitor->setMaximumSize(QSize(200,30));
    tempoDiRispostaLineEditMonitor->setMinimumSize(QSize(0,0));

    tipologiaDisplayLineEditMonitor=new QLineEdit;
    tipologiaDisplayLineEditMonitor->setPlaceholderText(tr("Inserire tipologia display"));
    tipologiaDisplayLineEditMonitor->setMaximumSize(QSize(200,30));
    tipologiaDisplayLineEditMonitor->setMinimumSize(QSize(0,0));

    frequenzaDiAggiornamentoLineEditMonitor=new QLineEdit;
    frequenzaDiAggiornamentoLineEditMonitor->setPlaceholderText(tr("Inserire frequenza di aggiornamento"));
    frequenzaDiAggiornamentoLineEditMonitor->setMaximumSize(QSize(200,30));
    frequenzaDiAggiornamentoLineEditMonitor->setMinimumSize(QSize(0,0));
}

void MonitorAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxMonitor=new QDoubleSpinBox;
    prezzoDoubleSpinBoxMonitor->setSuffix(" €");
    prezzoDoubleSpinBoxMonitor->setMaximum(9999.99);
    prezzoDoubleSpinBoxMonitor->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxMonitor->setMinimumSize(QSize(0,0));
}

void MonitorAddWidget::createCheckBoxes(){
    altoparlantiIncorporatiCheckBoxMonitor=new QCheckBox(tr("Altoparlanti incorporati"));
    altoparlantiIncorporatiCheckBoxMonitor->setMaximumSize(QSize(160,30));
    altoparlantiIncorporatiCheckBoxMonitor->setMinimumSize(QSize(0,0));

    widescreenCheckBoxMonitor=new QCheckBox("Widescreen");
    widescreenCheckBoxMonitor->setMaximumSize(QSize(90,30));
    widescreenCheckBoxMonitor->setMinimumSize(QSize(0,0));
}

QString MonitorAddWidget::nomeMonitorValue() const{
    return nomeLineEditMonitor->text();
}

QString MonitorAddWidget::produttoreMonitorValue() const{
    return produttoreLineEditMonitor->text();
}

QString MonitorAddWidget::risoluzioneRaccomandataMonitorValue() const{
    return risoluzioneRaccomandataLineEditMonitor->text();
}

QString MonitorAddWidget::formatoMonitorValue() const{
    return formatoLineEditMonitor->text();
}

QString MonitorAddWidget::angoloDiVisualizzazioneMonitorValue() const{
    return angoloDiVisualizzazioneLineEditMonitor->text();
}

QString MonitorAddWidget::coloriDelDisplayMonitorValue() const{
    return coloriDelDisplayLineEditMonitor->text();
}

QString MonitorAddWidget::luminositaMonitorValue() const{
    return luminositaLineEditMonitor->text();
}

QString MonitorAddWidget::rapportoDiContrastoMonitorValue() const{
    return rapportoDiContrastoLineEditMonitor->text();
}

QString MonitorAddWidget::tempoDiRispostaMonitorValue() const{
    return tempoDiRispostaLineEditMonitor->text();
}

QString MonitorAddWidget::tipologiaDisplayMonitorValue() const{
    return tipologiaDisplayLineEditMonitor->text();
}

QString MonitorAddWidget::frequenzaDiAggiornamentoMonitorValue() const{
    return frequenzaDiAggiornamentoLineEditMonitor->text();
}

bool MonitorAddWidget::altoparlantiIncorporatiMonitorValue() const{
    return altoparlantiIncorporatiCheckBoxMonitor->isChecked();
}

bool MonitorAddWidget::widescreenMonitorValue() const{
    return widescreenCheckBoxMonitor->isChecked();
}

double MonitorAddWidget::prezzoMonitorValue() const{
    return prezzoDoubleSpinBoxMonitor->value();
}

QLineEdit* MonitorAddWidget::getNomeLineEditMonitor() const{
    return nomeLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getProduttoreLineEditMonitor() const{
    return produttoreLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getRisoluzioneRaccomandataLineEditMonitor() const{
    return risoluzioneRaccomandataLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getFormatoLineEditMonitor() const{
    return formatoLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getAngoloDiVisualizzazioneLineEditMonitor() const{
    return angoloDiVisualizzazioneLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getColoriDelDisplayLineEditMonitor() const{
    return coloriDelDisplayLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getLuminositaLineEditMonitor() const{
    return luminositaLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getRapportoDiContrastoLineEditMonitor() const{
    return rapportoDiContrastoLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getTempoDiRispostaLineEditMonitor() const{
    return tempoDiRispostaLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getTipologiaDisplayLineEditMonitor() const{
    return tipologiaDisplayLineEditMonitor;
}
QLineEdit* MonitorAddWidget::getFrequenzaDiAggiornamentoLineEditMonitor() const{
    return frequenzaDiAggiornamentoLineEditMonitor;
}
QCheckBox* MonitorAddWidget::getAltoparlantiIncorporatiCheckBoxMonitor() const{
    return altoparlantiIncorporatiCheckBoxMonitor;
}
QCheckBox* MonitorAddWidget::getWidescreenCheckBoxMonitor() const{
    return widescreenCheckBoxMonitor;
}
QDoubleSpinBox* MonitorAddWidget::getPrezzoDoubleSpinBoxMonitor() const{
    return prezzoDoubleSpinBoxMonitor;
}
