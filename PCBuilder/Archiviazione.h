#ifndef ARCHIVIAZIONE_H
#define ARCHIVIAZIONE_H

#include "Componente.h"

class Archiviazione:public Componente{
private:
    QString tipologia;
    QString capacita;
    QString interfaccia;
    QString cache;
    QString fattoreDiForma;
    QString rpm;
public:
    Archiviazione(const QString&, double, const QString&, const QString&, const QString&,
                  const QString&, const QString&, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getTipologia() const;
    QString getCapacita() const;
    QString getInterfaccia() const;
    QString getCache() const;
    QString getFattoreDiForma() const;
    QString getRpm() const;
};

#endif // ARCHIVIAZIONE_H
