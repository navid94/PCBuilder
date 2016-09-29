#ifndef ALTOPARLANTISPECSWIDGET_H
#define ALTOPARLANTISPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class AltoparlantiSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* coloreLabel;
    QLabel* coloreValueLabel;
    QLabel* configurazioneLabel;
    QLabel* configurazioneValueLabel;
    QLabel* frequenzaDiRispostaLabel;
    QLabel* frequenzaDiRispostaValueLabel;
    QLabel* potenzaTotaleLabel;
    QLabel* potenzaTotaleValueLabel;
    QLabel* potenzeLabel;
    QLabel* potenzeValueLabel;
public:
    AltoparlantiSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setColoreValueLabel(const QString&);
    void setConfigurazioneValueLabel(const QString&);
    void setFrequenzaDiRispostaValueLabel(const QString&);
    void setPotenzaTotaleValueLabel(const QString&);
    void setPotenzeValueLabel(const QString&);
};

#endif // ALTOPARLANTISPECSWIDGET_H
