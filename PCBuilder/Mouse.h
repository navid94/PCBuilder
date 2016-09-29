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
    Mouse(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&, int, const QString&, const QString&);
    Mouse(PCBuilderController*);
    virtual void saveXMLComponente() const;
    virtual void deleteXMLComponente() const;
    virtual void setAddWidget() const;
    virtual void addComponente() const;
    virtual void setSpecsWidget() const;
    virtual void clearAddWidget() const;
    virtual void updateConfigurazione() const;
    virtual Componente* clone() const;
    virtual QString getNomeTipoComponente() const;
    virtual QString getType() const;

    QString getConnessione() const;
    QString getTipologiaTracciamento() const;
    int getDPIMassimi() const;
    QString getColore() const;
    QString getOrientamentoDellaMano() const;
};

#endif // MOUSE_H
