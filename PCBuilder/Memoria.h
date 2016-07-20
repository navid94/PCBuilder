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
    Memoria(const QString&, double, const QString&, const QString&, const QString&, const QString&, int);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getVelocita() const;
    QString getCapacita() const;
    QString getTipologia() const;
    int getLatenza() const;
};

#endif // MEMORIA_H
