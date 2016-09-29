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
    Archiviazione(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&,
                  const QString&, const QString&, const QString&, const QString&);
    Archiviazione(PCBuilderController*);
    virtual void saveXMLComponente() const;
    virtual void deleteXMLComponente() const;
    virtual void setAddWidget() const;
    virtual void clearAddWidget() const;
    virtual void addComponente() const;
    virtual void setSpecsWidget() const;
    virtual Componente* clone() const;
    virtual void updateConfigurazione() const;
    virtual QString getNomeTipoComponente() const;
    virtual QString getType() const;

    QString getTipologia() const;
    QString getCapacita() const;
    QString getInterfaccia() const;
    QString getCache() const;
    QString getFattoreDiForma() const;
    QString getRpm() const;
};

#endif // ARCHIVIAZIONE_H
