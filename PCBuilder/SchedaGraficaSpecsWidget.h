#ifndef SCHEDAGRAFICASPECSWIDGET_H
#define SCHEDAGRAFICASPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class SchedaGraficaSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* interfacciaLabel;
    QLabel* interfacciaValueLabel;
    QLabel* chipsetLabel;
    QLabel* chipsetValueLabel;
    QLabel* memoriaLabel;
    QLabel* memoriaValueLabel;
    QLabel* tipologiaMemoriaLabel;
    QLabel* tipologiaMemoriaValueLabel;
    QLabel* frequenzaCoreLabel;
    QLabel* frequenzaCoreValueLabel;
    QLabel* tdpLabel;
    QLabel* tdpValueLabel;
    QLabel* supportoSLILabel;
    QLabel* supportoSLIValueLabel;
    QLabel* supportoCrossfireLabel;
    QLabel* supportoCrossfireValueLabel;
    QLabel* lunghezzaLabel;
    QLabel* lunghezzaValueLabel;
public:
    SchedaGraficaSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setInterfacciaValueLabel(const QString&);
    void setChipsetValueLabel(const QString&);
    void setMemoriaValueLabel(const QString&);
    void setTipologiaMemoriaValueLabel(const QString&);
    void setFrequenzaCoreValueLabel(const QString&);
    void setTdpValueLabel(const QString&);
    void setSupportoSLIValueLabel(const QString&);
    void setSupportoCrossfireValueLabel(const QString&);
    void setLunghezzaValueLabel(const QString&);
};

#endif // SCHEDAGRAFICASPECSWIDGET_H
