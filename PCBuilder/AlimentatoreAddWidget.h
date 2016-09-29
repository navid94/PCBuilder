#ifndef ALIMENTATOREADDWIDGET_H
#define ALIMENTATOREADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>

class AlimentatoreAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelAlimentatore;
    QLabel* prezzoLabelAlimentatore;
    QLabel* produttoreLabelAlimentatore;
    QLabel* tipologiaLabelAlimentatore;
    QLabel* wattaggioLabelAlimentatore;
    QLabel* modulareLabelAlimentatore;
    QLabel* certificazioneEfficienzaLabelAlimentatore;
    QLabel* efficienzaLabelAlimentatore;
    QLineEdit* nomeLineEditAlimentatore;
    QLineEdit* produttoreLineEditAlimentatore;
    QLineEdit* tipologiaLineEditAlimentatore;
    QLineEdit* wattaggioLineEditAlimentatore;
    QLineEdit* modulareLineEditAlimentatore;
    QLineEdit* certificazioneEfficienzaLineEditAlimentatore;
    QDoubleSpinBox* efficienzaDoubleSpinBoxAlimentatore;
    QDoubleSpinBox* prezzoDoubleSpinBoxAlimentatore;
public:
    AlimentatoreAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();

    QString nomeAlimentatoreValue() const;
    QString produttoreAlimentatoreValue() const;
    QString tipologiaAlimentatoreValue() const;
    QString wattaggioAlimentatoreValue() const;
    QString modulareAlimentatoreValue() const;
    QString certificazioneEfficienzaAlimentatoreValue() const;
    double efficienzaAlimentatoreValue() const;
    double prezzoAlimentatoreValue() const;

    QLineEdit* getNomeLineEditAlimentatore() const;
    QLineEdit* getProduttoreLineEditAlimentatore() const;
    QLineEdit* getTipologiaLineEditAlimentatore() const;
    QLineEdit* getWattaggioLineEditAlimentatore() const;
    QLineEdit* getModulareLineEditAlimentatore() const;
    QLineEdit* getCertificazioneEfficienzaLineEditAlimentatore() const;
    QDoubleSpinBox* getEfficienzaDoubleSpinBoxAlimentatore() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxAlimentatore() const;
};

#endif // ALIMENTATOREADDWIDGET_H
