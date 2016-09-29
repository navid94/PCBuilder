#ifndef MEMORIAADDWIDGET_H
#define MEMORIAADDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QString>

class MemoriaAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelMemoria;
    QLabel* prezzoLabelMemoria;
    QLabel* produttoreLabelMemoria;
    QLabel* velocitaLabelMemoria;
    QLabel* capacitaLabelMemoria;
    QLabel* tipologiaLabelMemoria;
    QLabel* latenzaLabelMemoria;
    QLineEdit* nomeLineEditMemoria;
    QLineEdit* produttoreLineEditMemoria;
    QLineEdit* velocitaLineEditMemoria;
    QLineEdit* capacitaLineEditMemoria;
    QLineEdit* tipologiaLineEditMemoria;
    QDoubleSpinBox* prezzoDoubleSpinBoxMemoria;
    QSpinBox* latenzaSpinBoxMemoria;
public:
    MemoriaAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createSpinBoxes();
    void createDoubleSpinBoxes();

    QString nomeMemoriaValue() const;
    QString produttoreMemoriaValue() const;
    QString velocitaMemoriaValue() const;
    QString capacitaMemoriaValue() const;
    QString tipologiaMemoriaValue() const;
    double prezzoMemoriaValue() const;
    int latenzaMemoriaValue() const;

    QLineEdit* getNomeLineEditMemoria() const;
    QLineEdit* getProduttoreLineEditMemoria() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxMemoria() const;
    QLineEdit* getVelocitaLineEditMemoria() const;
    QLineEdit* getCapacitaLineEditMemoria() const;
    QLineEdit* getTipologiaLineEditMemoria() const;
    QSpinBox* getLatenzaSpinBoxMemoria() const;
};

#endif // MEMORIAADDWIDGET_H
