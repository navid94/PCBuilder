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
    UnitaOttica(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&, const QString&, const QString&);
    UnitaOttica(PCBuilderController*);
    virtual void saveXMLComponente() const;
    virtual void deleteXMLComponente() const;
    virtual void setAddWidget() const;
    virtual void addComponente() const;
    virtual void clearAddWidget() const;
    virtual void setSpecsWidget() const;
    virtual Componente* clone() const;
    virtual void updateConfigurazione() const;
    virtual QString getNomeTipoComponente() const;
    virtual QString getType() const;

    QString getFattoreDiForma() const;
    QString getInterfaccia() const;
    QString getCache() const;
    QString getVelocita() const;
};

#endif // UNITAOTTICA_H
