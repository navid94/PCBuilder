#ifndef SCHEDAMADRESPECSWIDGET_H
#define SCHEDAMADRESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class SchedaMadreSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* fattoreDiFormaLabel;
    QLabel* fattoreDiFormaValueLabel;
    QLabel* chipsetLabel;
    QLabel* chipsetValueLabel;
    QLabel* socketProcessoreLabel;
    QLabel* socketProcessoreValueLabel;
    QLabel* slotMemoriaLabel;
    QLabel* slotMemoriaValueLabel;
    QLabel* tipologiaMemoriaLabel;
    QLabel* tipologiaMemoriaValueLabel;
    QLabel* memoriaMassimaLabel;
    QLabel* memoriaMassimaValueLabel;
    QLabel* supportoRAIDLabel;
    QLabel* supportoRAIDValueLabel;
    QLabel* supportoCrossfireLabel;
    QLabel* supportoCrossfireValueLabel;
    QLabel* supportoSLILabel;
    QLabel* supportoSLIValueLabel;
    QLabel* ethernetLabel;
    QLabel* ethernetValueLabel;
    QLabel* sata3GBsLabel;
    QLabel* sata3GBsValueLabel;
    QLabel* sata6GBsLabel;
    QLabel* sata6GBsValueLabel;
    QLabel* sataExpressLabel;
    QLabel* sataExpressValueLabel;
    QLabel* usb2Label;
    QLabel* usb2ValueLabel;
    QLabel* usb3Label;
    QLabel* usb3ValueLabel;
public:
    SchedaMadreSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setFattoreDiFormaValueLabel(const QString&);
    void setChipsetValueLabel(const QString&);
    void setSocketProcessoreValueLabel(const QString&);
    void setSlotMemoriaValueLabel(const QString&);
    void setTipologiaMemoriaValueLabel(const QString&);
    void setMemoriaMassimaValueLabel(const QString&);
    void setSupportoRAIDValueLabel(const QString&);
    void setSupportoCrossfireValueLabel(const QString&);
    void setSupportoSLIValueLabel(const QString&);
    void setEthernetValueLabel(const QString&);
    void setSata3GBsValueLabel(const QString&);
    void setSata6GBsValueLabel(const QString&);
    void setSataExpressValueLabel(const QString&);
    void setUsb2ValueLabel(const QString&);
    void setUsb3ValueLabel(const QString&);
};

#endif // SCHEDAMADRESPECSWIDGET_H
