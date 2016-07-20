#ifndef SISTEMAOPERATIVO_H
#define SISTEMAOPERATIVO_H

#include "Componente.h"

class SistemaOperativo:public Componente{
private:
    QString modalita;
    QString memoriaMassimaSupportata;
public:
    SistemaOperativo(const QString&, double, const QString&, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getModalita() const;
    QString getMemoriaMassimaSupportata() const;
};

#endif // SISTEMAOPERATIVO_H
