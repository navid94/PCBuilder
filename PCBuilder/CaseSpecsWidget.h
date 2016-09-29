#ifndef CASESPECSWIDGET_H
#define CASESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class CaseSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* tipologiaLabel;
    QLabel* tipologiaValueLabel;
    QLabel* coloreLabel;
    QLabel* coloreValueLabel;
    QLabel* alimentatoreInclusoLabel;
    QLabel* alimentatoreInclusoValueLabel;
    QLabel* compatibilitaSchedaMadreLabel;
    QLabel* compatibilitaSchedaMadreValueLabel;
    QLabel* lunghezzaMassimaSchedaGraficaLabel;
    QLabel* lunghezzaMassimaSchedaGraficaValueLabel;
    QLabel* slotInterni25Label;
    QLabel* slotInterni25ValueLabel;
    QLabel* slotInterni35Label;
    QLabel* slotInterni35ValueLabel;
    QLabel* dimensioniLabel;
    QLabel* dimensioniValueLabel;
public:
    CaseSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setTipologiaValueLabel(const QString&);
    void setColoreValueLabel(const QString&);
    void setAlimentatoreInclusoValueLabel(const QString&);
    void setCompatibilitaSchedaMadreValueLabel(const QString&);
    void setLunghezzaMassimaSchedaGraficaValueLabel(const QString&);
    void setSlotInterni25ValueLabel(const QString&);
    void setSlotInterni35ValueLabel(const QString&);
    void setDimensioniValueLabel(const QString&);
};

#endif // CASESPECSWIDGET_H
