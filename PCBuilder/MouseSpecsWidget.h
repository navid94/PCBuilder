#ifndef MOUSESPECSWIDGET_H
#define MOUSESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class MouseSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* connessioneLabel;
    QLabel* connessioneValueLabel;
    QLabel* tipologiaTracciamentoLabel;
    QLabel* tipologiaTracciamentoValueLabel;
    QLabel* dpiMassimiLabel;
    QLabel* dpiMassimiValueLabel;
    QLabel* coloreLabel;
    QLabel* coloreValueLabel;
    QLabel* orientamentoDellaManoLabel;
    QLabel* orientamentoDellaManoValueLabel;
public:
    MouseSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setConnessioneValueLabel(const QString&);
    void setTipologiaTracciamentoValueLabel(const QString&);
    void setDpiMassimiValueLabel(const QString&);
    void setColoreValueLabel(const QString&);
    void setOrientamentoDellaManoValueLabel(const QString&);
};

#endif // MOUSESPECSWIDGET_H
