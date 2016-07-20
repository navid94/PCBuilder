#ifndef UNITAOTTICA_H
#define UNITAOTTICA_H

#include "Componente.h"

class UnitaOttica:public Componente{
private:
    QString fattoreDiForma;
    QString interfaccia;
    QString cache;
    QString velocita;
public:
    UnitaOttica(const QString&, double, const QString&, const QString&, const QString&, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getFattoreDiForma() const;
    QString getInterfaccia() const;
    QString getCache() const;
    QString getVelocita() const;
};

#endif // UNITAOTTICA_H
