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
    SchedaMadre(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&, const QString&,
                 const QString&, const QString&, const QString&, bool, bool, bool, const QString&, int,
                 int, int, int, int);
    SchedaMadre(PCBuilderController*);
    virtual void saveXMLComponente() const;
    virtual void deleteXMLComponente() const;
    virtual void setAddWidget() const;
    virtual void addComponente() const;
    virtual void setSpecsWidget() const;
    virtual Componente* clone() const;
    virtual void clearAddWidget() const;
    virtual void updateConfigurazione() const;
    virtual QString getNomeTipoComponente() const;
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
