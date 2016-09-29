#ifndef SCHEDAGRAFICAADDWIDGET_H
#define SCHEDAGRAFICAADDWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QString>

class SchedaGraficaAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelSchedaGrafica;
    QLabel* prezzoLabelSchedaGrafica;
    QLabel* produttoreLabelSchedaGrafica;
    QLabel* interfacciaLabelSchedaGrafica;
    QLabel* chipsetLabelSchedaGrafica;
    QLabel* memoriaLabelSchedaGrafica;
    QLabel* tipologiaMemoriaLabelSchedaGrafica;
    QLabel* frequenzaCoreLabelSchedaGrafica;
    QLabel* tdpLabelSchedaGrafica;
    QLabel* supportoSLILabelSchedaGrafica;
    QLabel* supportoCrossfireLabelSchedaGrafica;
    QLabel* lunghezzaLabelSchedaGrafica;
    QLineEdit* nomeLineEditSchedaGrafica;
    QLineEdit* produttoreLineEditSchedaGrafica;
    QLineEdit* interfacciaLineEditSchedaGrafica;
    QLineEdit* chipsetLineEditSchedaGrafica;
    QLineEdit* memoriaLineEditSchedaGrafica;
    QLineEdit* tipologiaMemoriaLineEditSchedaGrafica;
    QLineEdit* frequenzaCoreLineEditSchedaGrafica;
    QLineEdit* tdpLineEditSchedaGrafica;
    QLineEdit* supportoSLILineEditSchedaGrafica;
    QLineEdit* supportoCrossfireLineEditSchedaGrafica;
    QLineEdit* lunghezzaLineEditSchedaGrafica;
    QDoubleSpinBox* prezzoDoubleSpinBoxSchedaGrafica;
public:
    SchedaGraficaAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();

    QString nomeSchedaGraficaValue() const;
    QString produttoreSchedaGraficaValue() const;
    QString interfacciaSchedaGraficaValue() const;
    QString chipsetSchedaGraficaValue() const;
    QString memoriaSchedaGraficaValue() const;
    QString tipologiaMemoriaSchedaGraficaValue() const;
    QString frequenzaCoreSchedaGraficaValue() const;
    QString tdpSchedaGraficaValue() const;
    QString supportoSLISchedaGraficaValue() const;
    QString supportoCrossfireSchedaGraficaValue() const;
    QString lunghezzaSchedaGraficaValue() const;
    double prezzoSchedaGraficaValue() const;

    QLineEdit* getNomeLineEditSchedaGrafica() const;
    QLineEdit* getProduttoreLineEditSchedaGrafica() const;
    QLineEdit* getInterfacciaLineEditSchedaGrafica() const;
    QLineEdit* getChipsetLineEditSchedaGrafica() const;
    QLineEdit* getMemoriaLineEditSchedaGrafica() const;
    QLineEdit* getTipologiaMemoriaLineEditSchedaGrafica() const;
    QLineEdit* getFrequenzaCoreLineEditSchedaGrafica() const;
    QLineEdit* getTdpLineEditSchedaGrafica() const;
    QLineEdit* getSupportoSLILineEditSchedaGrafica() const;
    QLineEdit* getSupportoCrossfireLineEditSchedaGrafica() const;
    QLineEdit* getLunghezzaLineEditSchedaGrafica() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxSchedaGrafica() const;
};

#endif // SCHEDAGRAFICAADDWIDGET_H
