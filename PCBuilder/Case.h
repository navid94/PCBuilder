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
    Case(const QString&, double, const QString&, const QString&, const QString&, bool, int, int, const QString&,
         const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
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
