#ifndef PROCESSORE_H
#define PROCESSORE_H

#include "Componente.h"

class Processore:public Componente{
private:
    QString socket;
    QString larghezzaDati;
    QString frequenzaOperativa;
    QString frequenzaTurbo;
    int numeroCore;
    QString l1Cache;
    QString l2Cache;
    QString l3Cache;
    QString litografia;
    QString tdp;
    bool includeDissipatore;
    bool hyperThreading;
    QString graficaIntegrata;
public:
    Processore(const QString&, double, const QString&, const QString&, const QString&, const QString&, const QString&,
               int, const QString&, const QString&, const QString&, const QString&, const QString&, bool,
                bool, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getSocket() const;
    QString getLarghezzaDati() const;
    QString getFrequenzaOperativa() const;
    QString getFrequenzaTurbo() const;
    int getNumeroCore() const;
    QString getL1Cache() const;
    QString getL2Cache() const;
    QString getL3Cache() const;
    QString getLitografia() const;
    QString getTdp() const;
    bool getIncludeDissipatore() const;
    bool getHyperThreading() const;
    QString getGraficaIntegrata() const;
};

#endif // PROCESSORE_H
