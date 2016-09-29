#ifndef MEMORIA_H
#define MEMORIA_H

#include "Componente.h"

class Memoria:public Componente{
private:
    QString velocita;
    QString capacita;
    QString tipologia;
    int latenza;
public:
    Memoria(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&, const QString&, int);
    Memoria(PCBuilderController*);
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

    QString getVelocita() const;
    QString getCapacita() const;
    QString getTipologia() const;
    int getLatenza() const;
};

#endif // MEMORIA_H
