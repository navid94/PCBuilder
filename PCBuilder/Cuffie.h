#ifndef CUFFIE_H
#define CUFFIE_H

#include "Componente.h"

class Cuffie:public Componente{
private:
    QString tipologia;
    QString sistemaAcustico;
    QString colore;
    bool microfono;
    QString canali;
    QString impedenza;
    QString frequenzaDiRisposta;
    QString connessione;
    QString connettore;
public:
    Cuffie(const QString&, double, const QString&, PCBuilderController*, const QString&, const QString&, const QString&, bool,
           const QString&, const QString&, const QString&, const QString&, const QString&);
    Cuffie(PCBuilderController*);
    virtual void saveXMLComponente() const;
    virtual void deleteXMLComponente() const;
    virtual void setAddWidget() const;
    virtual void clearAddWidget() const;
    virtual void addComponente() const;
    virtual void setSpecsWidget() const;
    virtual Componente* clone() const;
    virtual void updateConfigurazione() const;
    virtual QString getNomeTipoComponente() const;
    virtual QString getType() const;

    QString getTipologia() const;
    QString getSistemaAcustico() const;
    QString getColore() const;
    bool getMicrofono() const;
    QString getCanali() const;
    QString getImpedenza() const;
    QString getFrequenzaDiRisposta() const;
    QString getConnessione() const;
    QString getConnettore() const;
};

#endif // CUFFIE_H
