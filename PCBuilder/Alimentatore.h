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
    Alimentatore(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&,
                 const QString&, const QString&, double);
    Alimentatore(PCBuilderController*);
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
    QString getTipologia() const;
    QString getWattaggio() const;
    QString getModulare() const;
    QString getCertificazioneEfficienza() const;
    double getEfficienza() const;

};

#endif // ALIMENTATORE_H
