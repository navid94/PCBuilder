#ifndef ALTOPARLANTI_H
#define ALTOPARLANTI_H

#include "Componente.h"

class Altoparlanti:public Componente{
private:
    QString colore;
    QString configurazione;
    QString frequenzaDiRisposta;
    QString potenzaTotale;
    QString potenze;
public:
    Altoparlanti(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&, const QString&, const QString&, const QString&);
    Altoparlanti(PCBuilderController*);
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

    QString getColore() const;
    QString getConfigurazione() const;
    QString getFrequenzaDiRisposta() const;
    QString getPotenzaTotale() const;
    QString getPotenze() const;
};

#endif // ALTOPARLANTI_H
