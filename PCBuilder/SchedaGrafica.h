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
    SchedaGrafica(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&,
                   const QString&, const QString&, const QString&, const QString&, const QString&,
                   const QString&, const QString&);
    SchedaGrafica(PCBuilderController*);
    virtual void saveXMLComponente() const;
    virtual void deleteXMLComponente() const;
    virtual void setAddWidget() const;
    virtual void addComponente() const;
    virtual void clearAddWidget() const;
    virtual void setSpecsWidget() const;
    virtual void updateConfigurazione() const;
    virtual Componente* clone() const;
    virtual QString getNomeTipoComponente() const;
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
