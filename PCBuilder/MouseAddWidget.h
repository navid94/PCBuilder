#ifndef MOUSEADDWIDGET_H
#define MOUSEADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>

class MouseAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelMouse;
    QLabel* prezzoLabelMouse;
    QLabel* produttoreLabelMouse;
    QLabel* connessioneLabelMouse;
    QLabel* tipologiaTracciamentoLabelMouse;
    QLabel* dpiMassimiLabelMouse;
    QLabel* coloreLabelMouse;
    QLabel* orientamentoDellaManoLabelMouse;
    QLineEdit* nomeLineEditMouse;
    QLineEdit* produttoreLineEditMouse;
    QLineEdit* connessioneLineEditMouse;
    QLineEdit* tipologiaTracciamentoLineEditMouse;
    QLineEdit* coloreLineEditMouse;
    QLineEdit* orientamentoDellaManoLineEditMouse;
    QSpinBox* dpiMassimiSpinBoxMouse;
    QDoubleSpinBox* prezzoDoubleSpinBoxMouse;
public:
    MouseAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();
    void createSpinBoxes();

    QString nomeMouseValue() const;
    QString produttoreMouseValue() const;
    QString connessioneMouseValue() const;
    QString tipologiaTracciamentoMouseValue() const;
    QString coloreMouseValue() const;
    QString orientamentoDellaManoMouseValue() const;
    int dpiMassimiMouseValue() const;
    double prezzoMouseValue() const;

    QLineEdit* getNomeLineEditMouse() const;
    QLineEdit* getProduttoreLineEditMouse() const;
    QLineEdit* getConnessioneLineEditMouse() const;
    QLineEdit* getTipologiaTracciamentoLineEditMouse() const;
    QLineEdit* getColoreLineEditMouse() const;
    QLineEdit* getOrientamentoDellaManoLineEditMouse() const;
    QSpinBox* getDpiMassimiSpinBoxMouse() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxMouse() const;
};

#endif // MOUSEADDWIDGET_H
