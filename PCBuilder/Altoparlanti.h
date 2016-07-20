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
    Altoparlanti(const QString&, double, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getColore() const;
    QString getConfigurazione() const;
    QString getFrequenzaDiRisposta() const;
    QString getPotenzaTotale() const;
    QString getPotenze() const;
};

#endif // ALTOPARLANTI_H
