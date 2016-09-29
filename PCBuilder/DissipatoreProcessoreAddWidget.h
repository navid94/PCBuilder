#ifndef DISSIPATOREPROCESSOREADDWIDGET_H
#define DISSIPATOREPROCESSOREADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleSpinBox>

class DissipatoreProcessoreAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelDissipatoreProcessore;
    QLabel* prezzoLabelDissipatoreProcessore;
    QLabel* produttoreLabelDissipatoreProcessore;
    QLabel* socketSupportatiLabelDissipatoreProcessore;
    QLabel* rpmVentolaLabelDissipatoreProcessore;
    QLabel* altezzaLabelDissipatoreProcessore;
    QLabel* altezzaRadiatoreLabelDissipatoreProcessore;
    QLabel* livelloRumoreLabelDissipatoreProcessore;
    QLineEdit* nomeLineEditDissipatoreProcessore;
    QLineEdit* produttoreLineEditDissipatoreProcessore;
    QLineEdit* socketSupportatiLineEditDissipatoreProcessore;
    QLineEdit* rpmVentolaLineEditDissipatoreProcessore;
    QLineEdit* altezzaLineEditDissipatoreProcessore;
    QLineEdit* altezzaRadiatoreLineEditDissipatoreProcessore;
    QLineEdit* livelloRumoreLineEditDissipatoreProcessore;
    QCheckBox* raffreddamentoALiquidoCheckBoxDissipatoreProcessore;
    QDoubleSpinBox* prezzoDoubleSpinBoxDissipatoreProcessore;
public:
    DissipatoreProcessoreAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createCheckBoxes();
    void createDoubleSpinBoxes();

    QString nomeDissipatoreProcessoreValue() const;
    QString produttoreDissipatoreProcessoreValue() const;
    QString socketSupportatiDissipatoreProcessoreValue() const;
    QString rpmVentolaDissipatoreProcessoreValue() const;
    QString altezzaDissipatoreProcessoreValue() const;
    QString altezzaRadiatoreDissipatoreProcessoreValue() const;
    QString livelloRumoreDissipatoreProcessoreValue() const;
    bool raffreddamentoALiquidoDissipatoreProcessoreValue() const;
    double prezzoDissipatoreProcessoreValue() const;

    QLineEdit* getNomeLineEditDissipatoreProcessore() const;
    QLineEdit* getProduttoreLineEditDissipatoreProcessore() const;
    QLineEdit* getSocketSupportatiLineEditDissipatoreProcessore() const;
    QLineEdit* getRpmVentolaLineEditDissipatoreProcessore() const;
    QLineEdit* getAltezzaLineEditDissipatoreProcessore() const;
    QLineEdit* getAltezzaRadiatoreLineEditDissipatoreProcessore() const;
    QLineEdit* getLivelloRumoreLineEditDissipatoreProcessore() const;
    QCheckBox* getRaffreddamentoALiquidoCheckBoxDissipatoreProcessore() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxDissipatoreProcessore() const;
};

#endif // DISSIPATOREPROCESSOREADDWIDGET_H
