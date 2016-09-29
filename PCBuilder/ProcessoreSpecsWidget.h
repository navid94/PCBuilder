#ifndef PROCESSORESPECSWIDGET_H
#define PROCESSORESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class ProcessoreSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* socketLabel;
    QLabel* socketValueLabel;
    QLabel* larghezzaDatiLabel;
    QLabel* larghezzaDatiValueLabel;
    QLabel* frequenzaOperativaLabel;
    QLabel* frequenzaOperativaValueLabel;
    QLabel* frequenzaTurboLabel;
    QLabel* frequenzaTurboValueLabel;
    QLabel* numeroCoreLabel;
    QLabel* numeroCoreValueLabel;
    QLabel* l1CacheLabel;
    QLabel* l1CacheValueLabel;
    QLabel* l2CacheLabel;
    QLabel* l2CacheValueLabel;
    QLabel* l3CacheLabel;
    QLabel* l3CacheValueLabel;
    QLabel* litografiaLabel;
    QLabel* litografiaValueLabel;
    QLabel* tdpLabel;
    QLabel* tdpValueLabel;
    QLabel* includeDissipatoreLabel;
    QLabel* includeDissipatoreValueLabel;
    QLabel* hyperThreadingLabel;
    QLabel* hyperThreadingValueLabel;
    QLabel* graficaIntegrataLabel;
    QLabel* graficaIntegrataValueLabel;
public:
    ProcessoreSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setSocketValueLabel(const QString&);
    void setLarghezzaDatiValueLabel(const QString&);
    void setFrequenzaOperativaValueLabel(const QString&);
    void setFrequenzaTurboValueLabel(const QString&);
    void setNumeroCoreValueLabel(const QString&);
    void setL1CacheValueLabel(const QString&);
    void setL2CacheValueLabel(const QString&);
    void setL3CacheValueLabel(const QString&);
    void setLitografiaValueLabel(const QString&);
    void setTdpValueLabel(const QString&);
    void setIncludeDissipatoreValueLabel(const QString&);
    void setHyperThreadingValueLabel(const QString&);
    void setGraficaIntegrataValueLabel(const QString&);
};

#endif // PROCESSORESPECSWIDGET_H
