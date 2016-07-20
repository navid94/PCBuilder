#ifndef CONFIGURAZIONE_H
#define CONFIGURAZIONE_H

#include "Alimentatore.h"
#include "Altoparlanti.h"
#include "Archiviazione.h"
#include "Case.h"
#include "Cuffie.h"
#include "DissipatoreProcessore.h"
#include "Memoria.h"
#include "Monitor.h"
#include "Mouse.h"
#include "Processore.h"
#include "SchedaGrafica.h"
#include "SchedaMadre.h"
#include "SistemaOperativo.h"
#include "Tastiera.h"
#include "UnitaOttica.h"

#include <QString>
#include <QVector>

class Configurazione{
private:
    QString nome;
    QVector<Componente*>* conf;
public:
    Configurazione(const QString&);
    QString getNome() const;
    QVector<Componente*>* getConf() const;
    /*Alimentatore* getAlimentatore() const;
    Altoparlanti* getAltoparlanti() const;
    Archiviazione* getArchiviazione() const;
    Case* getCase() const;
    Cuffie* getCuffie() const;
    DissipatoreProcessore*getDissipatoreProcessore() const;
    Memoria* getMemoria() const;
    Monitor* getMonitor() const;
    Mouse* getMouse() const;
    Processore* getProcessore() const;
    SchedaGrafica* getSchedaGrafica() const;
    SchedaMadre* getSchedaMadre() const;
    SistemaOperativo* getSistemaOperativo() const;
    Tastiera* getTastiera() const;
    UnitaOttica* getUnitaOttica() const;
    */
};

#endif // CONFIGURAZIONE_H
