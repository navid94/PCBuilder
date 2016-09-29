#ifndef UNITAOTTICAADDWIDGET_H
#define UNITAOTTICAADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>

class UnitaOtticaAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelUnitaOttica;
    QLabel* prezzoLabelUnitaOttica;
    QLabel* produttoreLabelUnitaOttica;
    QLabel* fattoreDiFormaLabelUnitaOttica;
    QLabel* interfacciaLabelUnitaOttica;
    QLabel* cacheLabelUnitaOttica;
    QLabel* velocitaLabelUnitaOttica;
    QLineEdit* nomeLineEditUnitaOttica;
    QLineEdit* produttoreLineEditUnitaOttica;
    QLineEdit* fattoreDiFormaLineEditUnitaOttica;
    QLineEdit* interfacciaLineEditUnitaOttica;
    QLineEdit* cacheLineEditUnitaOttica;
    QLineEdit* velocitaLineEditUnitaOttica;
    QDoubleSpinBox* prezzoDoubleSpinBoxUnitaOttica;
public:
    UnitaOtticaAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();

    QString nomeUnitaOtticaValue() const;
    QString produttoreUnitaOtticaValue() const;
    QString fattoreDiFormaUnitaOtticaValue() const;
    QString interfacciaUnitaOtticaValue() const;
    QString cacheUnitaOtticaValue() const;
    QString velocitaUnitaOtticaValue() const;
    double prezzoUnitaOtticaValue() const;

    QLineEdit* getNomeLineEditUnitaOttica() const;
    QLineEdit* getProduttoreLineEditUnitaOttica() const;
    QLineEdit* getFattoreDiFormaLineEditUnitaOttica() const;
    QLineEdit* getInterfacciaLineEditUnitaOttica() const;
    QLineEdit* getCacheLineEditUnitaOttica() const;
    QLineEdit* getVelocitaLineEditUnitaOttica() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxUnitaOttica() const;
};

#endif // UNITAOTTICAADDWIDGET_H
