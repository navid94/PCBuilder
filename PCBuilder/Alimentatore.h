#ifndef ALIMENTATORE_H
#define ALIMENTATORE_H

#include "Componente.h"

class Alimentatore:public Componente{
private:
    QString tipologia;
    QString wattaggio;
    QString modulare;
    QString certificazioneEfficienza;
    double efficienza;

public:
    Alimentatore(const QString&, double, const QString&, const QString&, const QString&,
                 const QString&, const QString&, double);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;
    QString getTipologia() const;
    QString getWattaggio() const;
    QString getModulare() const;
    QString getCertificazioneEfficienza() const;
    double getEfficienza() const;
};

#endif // ALIMENTATORE_H
