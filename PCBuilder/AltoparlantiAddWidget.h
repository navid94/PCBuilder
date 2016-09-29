#ifndef ALTOPARLANTIADDWIDGET_H
#define ALTOPARLANTIADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>

class AltoparlantiAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelAltoparlanti;
    QLabel* prezzoLabelAltoparlanti;
    QLabel* produttoreLabelAltoparlanti;
    QLabel* coloreLabelAltoparlanti;
    QLabel* configurazioneLabelAltoparlanti;
    QLabel* frequenzaDiRispostaLabelAltoparlanti;
    QLabel* potenzaTotaleLabelAltoparlanti;
    QLabel* potenzeLabelAltoparlanti;
    QLineEdit* nomeLineEditAltoparlanti;
    QLineEdit* produttoreLineEditAltoparlanti;
    QLineEdit* coloreLineEditAltoparlanti;
    QLineEdit* configurazioneLineEditAltoparlanti;
    QLineEdit* frequenzaDiRispostaLineEditAltoparlanti;
    QLineEdit* potenzaTotaleLineEditAltoparlanti;
    QLineEdit* potenzeLineEditAltoparlanti;
    QDoubleSpinBox* prezzoDoubleSpinBoxAltoparlanti;
public:
    AltoparlantiAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();

    QString nomeAltoparlantiValue() const;
    QString produttoreAltoparlantiValue() const;
    QString coloreAltoparlantiValue() const;
    QString configurazioneAltoparlantiValue() const;
    QString frequenzaDiRispostaAltoparlantiValue() const;
    QString potenzaTotaleAltoparlantiValue() const;
    QString potenzeAltoparlantiValue() const;
    double prezzoAltoparlantiValue() const;

    QLineEdit* getNomeLineEditAltoparlanti() const;
    QLineEdit* getProduttoreLineEditAltoparlanti() const;
    QLineEdit* getColoreLineEditAltoparlanti() const;
    QLineEdit* getConfigurazioneLineEditAltoparlanti() const;
    QLineEdit* getFrequenzaDiRispostaLineEditAltoparlanti() const;
    QLineEdit* getPotenzaTotaleLineEditAltoparlanti() const;
    QLineEdit* getPotenzeLineEditAltoparlanti() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxAltoparlanti() const;
};

#endif // ALTOPARLANTIADDWIDGET_H
