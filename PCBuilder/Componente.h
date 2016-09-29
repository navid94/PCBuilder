#ifndef COMPONENTE_H
#define COMPONENTE_H

#include "PCBuilderController.h"

#include <QString>

class Componente{
private:
    QString nome;
    double prezzo;
    QString produttore;
    PCBuilderController* controller;
public:
    Componente(const QString&, double, const QString&, PCBuilderController*);
    Componente(PCBuilderController*);
    virtual void saveXMLComponente() const =0;
    virtual void deleteXMLComponente() const =0;
    virtual void setAddWidget() const =0;
    virtual void clearAddWidget() const =0;
    virtual void addComponente() const =0;
    virtual void setSpecsWidget() const =0;
    virtual void updateConfigurazione() const=0;
    virtual Componente* clone() const =0;
    virtual ~Componente(){}
    virtual QString getType() const=0;
    virtual QString getNomeTipoComponente() const =0;
    QString getNome() const;

    double getPrezzo() const;
    QString getProduttore() const;
    PCBuilderController* getController() const;
};

#endif // COMPONENTE_H
