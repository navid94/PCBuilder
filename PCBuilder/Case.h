#ifndef CASE_H
#define CASE_H

#include "Componente.h"

class Case:public Componente{
private:
    QString tipologia;
    QString colore;
    bool alimentatoreIncluso;
    int slotInterni25;
    int slotInterni35;
    QString compatibilitaSchedaMadre;
    QString lunghezzaMassimaSchedaGrafica;
    QString dimensioni;
public:
    Case(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&, bool, int, int, const QString&,
         const QString&, const QString&);
    Case(PCBuilderController*);
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

    QString getTipologia() const;
    QString getColore() const;
    bool getAlimentatoreIncluso() const;
    int getSlotInterni25() const;
    int getSlotInterni35() const;
    QString getCompatibilitaSchedaMadre() const;
    QString getLunghezzaMassimaSchedaGrafica() const;
    QString getDimensioni() const;
};

#endif // CASE_H
