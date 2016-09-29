#ifndef MONITORSPECSWIDGET_H
#define MONITORSPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class MonitorSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* risoluzioneRaccomandataLabel;
    QLabel* risoluzioneRaccomandataValueLabel;
    QLabel* widescreenLabel;
    QLabel* widescreenValueLabel;
    QLabel* formatoLabel;
    QLabel* formatoValueLabel;
    QLabel* angoloDiVisualizzazioneLabel;
    QLabel* angoloDiVisualizzazioneValueLabel;
    QLabel* coloriDelDisplayLabel;
    QLabel* coloriDelDisplayValueLabel;
    QLabel* luminositaLabel;
    QLabel* luminositaValueLabel;
    QLabel* rapportoDiContrastoLabel;
    QLabel* rapportoDiContrastoValueLabel;
    QLabel* tempoDiRispostaLabel;
    QLabel* tempoDiRispostaValueLabel;
    QLabel* tipologiaDelDisplayLabel;
    QLabel* tipologiaDelDisplayValueLabel;
    QLabel* altoparlantiIncorporatiLabel;
    QLabel* altoparlantiIncorporatiValueLabel;
    QLabel* frequenzaDiAggiornamentoLabel;
    QLabel* frequenzaDiAggiornamentoValueLabel;
public:
    MonitorSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setRisoluzioneRaccomandataValueLabel(const QString&);
    void setWidescreenValueLabel(const QString&);
    void setFormatoValueLabel(const QString&);
    void setAngoloDiVisualizzazioneValueLabel(const QString&);
    void setColoriDelDisplayValueLabel(const QString&);
    void setLuminositaValueLabel(const QString&);
    void setRapportoDiContrastoValueLabel(const QString&);
    void setTempoDiRispostaValueLabel(const QString&);
    void setTipologiaDelDisplayValueLabel(const QString&);
    void setAltoparlantiIncorporatiValueLabel(const QString&);
    void setFrequenzaDiAggiornamentoValueLabel(const QString&);
};

#endif // MONITORSPECSWIDGET_H
