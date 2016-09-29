#ifndef SCHEDAMADREADDWIDGET_H
#define SCHEDAMADREADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>

class SchedaMadreAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelSchedaMadre;
    QLabel* prezzoLabelSchedaMadre;
    QLabel* produttoreLabelSchedaMadre;
    QLabel* fattoreDiFormaLabelSchedaMadre;
    QLabel* chipsetLabelSchedaMadre;
    QLabel* socketProcessoreLabelSchedaMadre;
    QLabel* slotMemoriaLabelSchedaMadre;
    QLabel* tipologiaMemoriaLabelSchedaMadre;
    QLabel* memoriaMassimaLabelSchedaMadre;
    QLabel* ethernetLabelSchedaMadre;
    QLabel* sata3GBsLabelSchedaMadre;
    QLabel* sata6GBsLabelSchedaMadre;
    QLabel* sataExpressLabelSchedaMadre;
    QLabel* usb2LabelSchedaMadre;
    QLabel* usb3LabelSchedaMadre;
    QLineEdit* nomeLineEditSchedaMadre;
    QLineEdit* produttoreLineEditSchedaMadre;
    QLineEdit* fattoreDiFormaLineEditSchedaMadre;
    QLineEdit* chipsetLineEditSchedaMadre;
    QLineEdit* socketProcessoreLineEditSchedaMadre;
    QLineEdit* slotMemoriaLineEditSchedaMadre;
    QLineEdit* tipologiaMemoriaLineEditSchedaMadre;
    QLineEdit* memoriaMassimaLineEditSchedaMadre;
    QLineEdit* ethernetLineEditSchedaMadre;
    QCheckBox* supportoRAIDCheckBoxSchedaMadre;
    QCheckBox* supportoCrossfireCheckBoxSchedaMadre;
    QCheckBox* supportoSLICheckBoxSchedaMadre;
    QSpinBox* sata3GBsSpinBoxSchedaMadre;
    QSpinBox* sata6GBsSpinBoxSchedaMadre;
    QSpinBox* sataExpressSpinboxSchedaMadre;
    QSpinBox* usb2SpinBoxSchedaMadre;
    QSpinBox* usb3SpinBoxSchedaMadre;
    QDoubleSpinBox* prezzoDoubleSpinBoxSchedaMadre;
public:
    SchedaMadreAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createSpinBoxes();
    void createDoubleSpinBoxes();
    void createCheckBoxes();

    QString nomeSchedaMadreValue() const;
    QString produttoreSchedaMadreValue() const;
    QString fattoreDiFormaSchedaMadreValue() const;
    QString chipsetSchedaMadreValue() const;
    QString socketProcessoreSchedaMadreValue() const;
    QString slotMemoriaSchedaMadreValue() const;
    QString tipologiaMemoriaSchedaMadreValue() const;
    QString memoriaMassimaSchedaMadreValue() const;
    QString ethernetSchedaMadreValue() const;
    bool supportoRAIDSchedaMadreValue() const;
    bool supportoCrossfireSchedaMadreValue() const;
    bool supportoSLISchedaMadreValue() const;
    int sata3GBsSchedaMadreValue() const;
    int sata6GBsSchedaMadreValue() const;
    int sataExpressSchedaMadreValue() const;
    int usb2SchedaMadreValue() const;
    int usb3SchedaMadreValue() const;
    double prezzoSchedaMadreValue() const;

    QLineEdit* getNomeLineEditSchedaMadre() const;
    QLineEdit* getProduttoreLineEditSchedaMadre() const;
    QLineEdit* getFattoreDiFormaLineEditSchedaMadre() const;
    QLineEdit* getChipsetLineEditSchedaMadre() const;
    QLineEdit* getSocketProcessoreLineEditSchedaMadre() const;
    QLineEdit* getSlotMemoriaLineEditSchedaMadre() const;
    QLineEdit* getTipologiaMemoriaLineEditSchedaMadre() const;
    QLineEdit* getMemoriaMassimaLineEditSchedaMadre() const;
    QLineEdit* getEthernetLineEditSchedaMadre() const;
    QCheckBox* getSupportoRAIDCheckBoxSchedaMadre() const;
    QCheckBox* getSupportoCrossfireCheckBoxSchedaMadre() const;
    QCheckBox* getSupportoSLICheckBoxSchedaMadre() const;
    QSpinBox* getSata3GBsSpinBoxSchedaMadre() const;
    QSpinBox* getSata6GBsSpinBoxSchedaMadre() const;
    QSpinBox* getSataExpressSpinboxSchedaMadre() const;
    QSpinBox* getUsb2SpinBoxSchedaMadre() const;
    QSpinBox* getUsb3SpinBoxSchedaMadre() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxSchedaMadre() const;
};

#endif // SCHEDAMADREADDWIDGET_H
