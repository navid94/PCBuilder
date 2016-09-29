#ifndef DISSIPATOREPROCESSORE_H
#define DISSIPATOREPROCESSORE_H

#include "Componente.h"

class DissipatoreProcessore:public Componente{
private:
    QString socketSupportati;
    bool raffreddamentoALiquido;
    QString rpmVentola;
    QString altezza;
    QString livelloRumore;
    QString altezzaRadiatore;
public:
    DissipatoreProcessore(const QString&, double, const QString&, PCBuilderController*, const QString&, bool,
                          const QString&, const QString&, const QString&, const QString&);
    DissipatoreProcessore(PCBuilderController*);
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

    QString getSocketSupportati() const;
    bool getRaffreddamentoALiquido() const;
    QString getRpmVentola() const;
    QString getAltezza() const;
    QString getLivelloRumore() const;
    QString getAltezzaRadiatore() const;
};

#endif // DISSIPATOREPROCESSORE_H
