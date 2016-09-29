#ifndef CASEADDWIDGET_H
#define CASEADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QCheckBox>

class CaseAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelCase;
    QLabel* prezzoLabelCase;
    QLabel* produttoreLabelCase;
    QLabel* tipologiaLabelCase;
    QLabel* coloreLabelCase;
    QLabel* slotInterni25LabelCase;
    QLabel* slotInterni35LabelCase;
    QLabel* compatibilitaSchedaMadreLabelCase;
    QLabel* lunghezzaMassimaSchedaGraficaLabelCase;
    QLabel* dimensioniLabelCase;
    QLineEdit* nomeLineEditCase;
    QLineEdit* produttoreLineEditCase;
    QLineEdit* tipologiaLineEditCase;
    QLineEdit* coloreLineEditCase;
    QLineEdit* compatibilitaSchedaMadreLineEditCase;
    QLineEdit* lunghezzaMassimaSchedaGraficaLineEditCase;
    QLineEdit* dimensioniLineEditCase;
    QCheckBox* alimentatoreInclusoCheckBoxCase;
    QSpinBox* slotInterni25SpinBoxCase;
    QSpinBox* slotInterni35SpinBoxCase;
    QDoubleSpinBox* prezzoDoubleSpinBoxCase;
public:
    CaseAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createCheckBoxes();
    void createSpinBoxes();
    void createDoubleSpinBoxes();

    QString nomeCaseValue() const;
    QString produttoreCaseValue() const;
    QString tipologiaCaseValue() const;
    QString coloreCaseValue() const;
    QString compatibilitaSchedaMadreCaseValue() const;
    QString lunghezzaMassimaSchedaGraficaCaseValue() const;
    QString dimensioniCaseValue() const;
    bool alimentatoreInclusoCaseValue() const;
    int slotInterni25CaseValue() const;
    int slotInterni35CaseValue() const;
    double prezzoCaseValue() const;

    QLineEdit* getNomeLineEditCase() const;
    QLineEdit* getProduttoreLineEditCase() const;
    QLineEdit* getTipologiaLineEditCase() const;
    QLineEdit* getColoreLineEditCase() const;
    QLineEdit* getCompatibilitaSchedaMadreLineEditCase() const;
    QLineEdit* getLunghezzaMassimaSchedaGraficaLineEditCase() const;
    QLineEdit* getDimensioniLineEditCase() const;
    QCheckBox* getAlimentatoreInclusoCheckBoxCase() const;
    QSpinBox* getSlotInterni25SpinBoxCase() const;
    QSpinBox* getSlotInterni35SpinBoxCase() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxCase() const;
};

#endif // CASEADDWIDGET_H
