#ifndef MOUSE_H
#define MOUSE_H

#include "Componente.h"

class Mouse:public Componente{
private:
    QString connessione;
    QString tipologiaTracciamento;
    int DPIMassimi;
    QString colore;
    QString orientamentoDellaMano;
public:
    Mouse(const QString&, double, const QString&, const QString&, const QString&, int, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getConnessione() const;
    QString getTipologiaTracciamento() const;
    int getDPIMassimi() const;
    QString getColore() const;
    QString getOrientamentoDellaMano() const;
};

#endif // MOUSE_H
