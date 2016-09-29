#ifndef SISTEMAOPERATIVO_H
#define SISTEMAOPERATIVO_H

#include "Componente.h"

class SistemaOperativo:public Componente{
private:
    QString modalita;
    QString memoriaMassimaSupportata;
public:
    SistemaOperativo(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&);
    SistemaOperativo(PCBuilderController*);
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

    QString getModalita() const;
    QString getMemoriaMassimaSupportata() const;
};

#endif // SISTEMAOPERATIVO_H
