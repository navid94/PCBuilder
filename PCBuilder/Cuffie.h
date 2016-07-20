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
    Cuffie(const QString&, double, const QString&, const QString&, const QString&, const QString&, bool,
           const QString&, const QString&, const QString&, const QString&, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
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
