#ifndef CONFIGURAZIONE_H
#define CONFIGURAZIONE_H

#include "Componente.h"

#include <QString>
#include <QVector>

class Configurazione{
private:
    QString nome;
    QVector<Componente*> conf;
public:
    Configurazione(){}
    Configurazione(const QString&);
    void aggiungiComponente(Componente*);
    double getPrezzoTotale() const;
    QString getNome() const;
    QVector<Componente*> getConf() const;
    void setNome(const QString&);
    Configurazione* clone() const;
};

#endif // CONFIGURAZIONE_H
