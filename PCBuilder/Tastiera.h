#ifndef TASTIERA_H
#define TASTIERA_H

#include "Componente.h"

class Tastiera:public Componente{
private:
    QString colore;
    bool retroilluminazione;
    QString connessione;
    QString tipologia;
    QString tipologiaSwitch;
public:
    Tastiera(const QString&, double, const QString&, const QString&, bool, const QString&, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getColore() const;
    bool getRetroilluminazione() const;
    QString getConnessione() const;
    QString getTipologia() const;
    QString getTipologiaSwitch() const;
};

#endif // TASTIERA_H
