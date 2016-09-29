#ifndef PROCESSOREADDWIDGET_H
#define PROCESSOREADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>

class ProcessoreAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelProcessore;
    QLabel* prezzoLabelProcessore;
    QLabel* produttoreLabelProcessore;
    QLabel* socketLabelProcessore;
    QLabel* larghezzaDatiLabelProcessore;
    QLabel* frequenzaOperativaLabelProcessore;
    QLabel* frequenzaTurboLabelProcessore;
    QLabel* numeroCoreLabelProcessore;
    QLabel* l1CacheLabelProcessore;
    QLabel* l2CacheLabelProcessore;
    QLabel* l3CacheLabelProcessore;
    QLabel* litografiaLabelProcessore;
    QLabel* tdpLabelProcessore;
    QLabel* graficaIntegrataLabelProcessore;
    QLineEdit* nomeLineEditProcessore;
    QLineEdit* produttoreLineEditProcessore;
    QLineEdit* socketLineEditProcessore;
    QLineEdit* larghezzaDatiLineEditProcessore;
    QLineEdit* frequenzaOperativaLineEditProcessore;
    QLineEdit* frequenzaTurboLineEditProcessore;
    QLineEdit* l1CacheLineEditProcessore;
    QLineEdit* l2CacheLineEditProcessore;
    QLineEdit* l3CacheLineEditProcessore;
    QLineEdit* litografiaLineEditProcessore;
    QLineEdit* tdpLineEditProcessore;
    QLineEdit* graficaIntegrataLineEditProcessore;
    QCheckBox* includeDissipatoreCheckBoxProcessore;
    QCheckBox* hyperThreadingCheckBoxProcessore;
    QSpinBox* numeroCoreSpinBoxProcessore;
    QDoubleSpinBox* prezzoDoubleSpinBoxProcessore;
public:
    ProcessoreAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createSpinBoxes();
    void createDoubleSpinBoxes();
    void createCheckBoxes();

    QString nomeProcessoreValue() const;
    QString produttoreProcessoreValue() const;
    QString socketProcessoreValue() const;
    QString larghezzaDatiProcessoreValue() const;
    QString frequenzaOperativaProcessoreValue() const;
    QString frequenzaTurboProcessoreValue() const;
    QString l1CacheProcessoreValue() const;
    QString l2CacheProcessoreValue() const;
    QString l3CacheProcessoreValue() const;
    QString litografiaProcessoreValue() const;
    QString tdpProcessoreValue() const;
    QString graficaIntegrataProcessoreValue() const;
    bool includeDissipatoreProcessoreValue() const;
    bool hyperThreadingProcessoreValue() const;
    int numeroCoreProcessoreValue() const;
    double prezzoProcessoreValue() const;

    QLineEdit* getNomeLineEditProcessore() const;
    QLineEdit* getProduttoreLineEditProcessore() const;
    QLineEdit* getSocketLineEditProcessore() const;
    QLineEdit* getLarghezzaDatiLineEditProcessore() const;
    QLineEdit* getFrequenzaOperativaLineEditProcessore() const;
    QLineEdit* getFrequenzaTurboLineEditProcessore() const;
    QLineEdit* getL1CacheLineEditProcessore() const;
    QLineEdit* getL2CacheLineEditProcessore() const;
    QLineEdit* getL3CacheLineEditProcessore() const;
    QLineEdit* getLitografiaLineEditProcessore() const;
    QLineEdit* getTdpLineEditProcessore() const;
    QLineEdit* getGraficaIntegrataLineEditProcessore() const;
    QCheckBox* getIncludeDissipatoreCheckBoxProcessore() const;
    QCheckBox* getHyperThreadingCheckBoxProcessore() const;
    QSpinBox* getNumeroCoreSpinBoxProcessore() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxProcessore() const;
};

#endif // PROCESSOREADDWIDGET_H
