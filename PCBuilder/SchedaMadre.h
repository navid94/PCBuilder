#ifndef SCHEDAMADRE_H
#define SCHEDAMADRE_H

#include "Componente.h"

class SchedaMadre:public Componente{
private:
    QString fattoreDiForma;
    QString chipset;
    QString socketProcessore;
    QString slotMemoria;
    QString tipologiaMemoria;
    QString memoriaMassima;
    bool supportoRAID;
    bool supportoCrossfire;
    bool supportoSLI;
    QString ethernet;
    int sata3GBs;
    int sata6GBs;
    int sataExpress;
    int usb2;
    int usb3;
public:
    SchedaMadre(const QString&, double, const QString&, const QString&, const QString&, const QString&,
                 const QString&, const QString&, const QString&, bool, bool, bool, const QString&, int,
                 int, int, int, int);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getFattoreDiForma() const;
    QString getChipset() const;
    QString getSocketProcessore() const;
    QString getSlotMemoria() const;
    QString getTipologiaMemoria() const;
    QString getMemoriaMassima() const;
    bool getSupportoRAID() const;
    bool getSupportoCrossfire() const;
    bool getSupportoSLI() const;
    QString getEthernet() const;
    int getSata3GBs() const;
    int getSata6GBs() const;
    int getSataExpress() const;
    int getUsb2() const;
    int getUsb3() const;
};

#endif // SCHEDAMADRE_H
