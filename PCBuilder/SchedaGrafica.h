#ifndef SCHEDAGRAFICA_H
#define SCHEDAGRAFICA_H

#include "Componente.h"

class SchedaGrafica:public Componente{
private:
    QString interfaccia;
    QString chipset;
    QString memoria;
    QString tipologiaMemoria;
    QString frequenzaCore;
    QString tdp;
    QString supportoSLI;
    QString supportoCrossfire;
    QString lunghezza;
public:
    SchedaGrafica(const QString&, double, const QString&, const QString&, const QString&,
                   const QString&, const QString&, const QString&, const QString&, const QString&,
                   const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getInterfaccia() const;
    QString getChipset() const;
    QString getMemoria() const;
    QString getTipologiaMemoria() const;
    QString getFrequenzaCore() const;
    QString getTdp() const;
    QString getSupportoSLI() const;
    QString getSupportoCrossfire() const;
    QString getLunghezza() const;
};

#endif // SCHEDAGRAFICA_H
