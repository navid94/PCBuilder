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
    Tastiera(const QString&, double, const QString&, PCBuilderController*, const QString&, bool, const QString&, const QString&, const QString&);
    Tastiera(PCBuilderController*);
    virtual void saveXMLComponente() const;
    virtual void deleteXMLComponente() const;
    virtual void setAddWidget() const;
    virtual void addComponente() const;
    virtual void clearAddWidget() const;
    virtual Componente* clone() const;
    virtual void setSpecsWidget() const;
    virtual void updateConfigurazione() const;
    virtual QString getNomeTipoComponente() const;
    virtual QString getType() const;

    QString getColore() const;
    bool getRetroilluminazione() const;
    QString getConnessione() const;
    QString getTipologia() const;
    QString getTipologiaSwitch() const;
};

#endif // TASTIERA_H
