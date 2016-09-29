#ifndef MONITORADDWIDGET_H
#define MONITORADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>

class MonitorAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelMonitor;
    QLabel* prezzoLabelMonitor;
    QLabel* produttoreLabelMonitor;
    QLabel* risoluzioneRaccomandataLabelMonitor;
    QLabel* formatoLabelMonitor;
    QLabel* angoloDiVisualizzazioneLabelMonitor;
    QLabel* coloriDelDisplayLabelMonitor;
    QLabel* luminositaLabelMonitor;
    QLabel* rapportoDiContrastoLabelMonitor;
    QLabel* tempoDiRispostaLabelMonitor;
    QLabel* tipologiaDisplayLabelMonitor;
    QLabel* frequenzaDiAggiornamentoLabelMonitor;
    QLineEdit* nomeLineEditMonitor;
    QLineEdit* produttoreLineEditMonitor;
    QLineEdit* risoluzioneRaccomandataLineEditMonitor;
    QLineEdit* formatoLineEditMonitor;
    QLineEdit* angoloDiVisualizzazioneLineEditMonitor;
    QLineEdit* coloriDelDisplayLineEditMonitor;
    QLineEdit* luminositaLineEditMonitor;
    QLineEdit* rapportoDiContrastoLineEditMonitor;
    QLineEdit* tempoDiRispostaLineEditMonitor;
    QLineEdit* tipologiaDisplayLineEditMonitor;
    QLineEdit* frequenzaDiAggiornamentoLineEditMonitor;
    QCheckBox* altoparlantiIncorporatiCheckBoxMonitor;
    QCheckBox* widescreenCheckBoxMonitor;
    QDoubleSpinBox* prezzoDoubleSpinBoxMonitor;
public:
    MonitorAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();
    void createCheckBoxes();

    QString nomeMonitorValue() const;
    QString produttoreMonitorValue() const;
    QString risoluzioneRaccomandataMonitorValue() const;
    QString formatoMonitorValue() const;
    QString angoloDiVisualizzazioneMonitorValue() const;
    QString coloriDelDisplayMonitorValue() const;
    QString luminositaMonitorValue() const;
    QString rapportoDiContrastoMonitorValue() const;
    QString tempoDiRispostaMonitorValue() const;
    QString tipologiaDisplayMonitorValue() const;
    QString frequenzaDiAggiornamentoMonitorValue() const;
    bool altoparlantiIncorporatiMonitorValue() const;
    bool widescreenMonitorValue() const;
    double prezzoMonitorValue() const;

    QLineEdit* getNomeLineEditMonitor() const;
    QLineEdit* getProduttoreLineEditMonitor() const;
    QLineEdit* getRisoluzioneRaccomandataLineEditMonitor() const;
    QLineEdit* getFormatoLineEditMonitor() const;
    QLineEdit* getAngoloDiVisualizzazioneLineEditMonitor() const;
    QLineEdit* getColoriDelDisplayLineEditMonitor() const;
    QLineEdit* getLuminositaLineEditMonitor() const;
    QLineEdit* getRapportoDiContrastoLineEditMonitor() const;
    QLineEdit* getTempoDiRispostaLineEditMonitor() const;
    QLineEdit* getTipologiaDisplayLineEditMonitor() const;
    QLineEdit* getFrequenzaDiAggiornamentoLineEditMonitor() const;
    QCheckBox* getAltoparlantiIncorporatiCheckBoxMonitor() const;
    QCheckBox* getWidescreenCheckBoxMonitor() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxMonitor() const;
};

#endif // MONITORADDWIDGET_H
