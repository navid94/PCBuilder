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
    DissipatoreProcessore(const QString&, double, const QString&, const QString&, bool,
                          const QString&, const QString&, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getSocketSupportati() const;
    bool getRaffreddamentoALiquido() const;
    QString getRpmVentola() const;
    QString getAltezza() const;
    QString getLivelloRumore() const;
    QString getAltezzaRadiatore() const;
};

#endif // DISSIPATOREPROCESSORE_H
