#include "Configurazione.h"

Configurazione::Configurazione(const QString& input_nome)
    :nome(input_nome),conf(new QVector<Componente*>){}

QString Configurazione::getNome() const{
    return nome;
}

QVector<Componente*>* Configurazione::getConf() const{
    return conf;
}

/*Alimentatore* Configurazione::getAlimentatore() const{
    return alimentatore;
}

Altoparlanti* Configurazione::getAltoparlanti() const{
    return altoparlanti;
}

Archiviazione* Configurazione::getArchiviazione() const{
    return archiviazione;
}

Case* Configurazione::getCase() const{
    return _case;
}

Cuffie* Configurazione::getCuffie() const{
    return cuffie;
}

DissipatoreProcessore* Configurazione::getDissipatoreProcessore() const{
    return dissipatoreProcessore;
}

Memoria* Configurazione::getMemoria() const{
    return memoria;
}

Monitor* Configurazione::getMonitor() const{
    return monitor;
}

Mouse* Configurazione::getMouse() const{
    return mouse;
}

Processore* Configurazione::getProcessore() const{
    return processore;
}

SchedaGrafica* Configurazione::getSchedaGrafica() const{
    return schedaGrafica;
}

SchedaMadre* Configurazione::getSchedaMadre() const{
    return schedaMadre;
}

SistemaOperativo* Configurazione::getSistemaOperativo() const{
    return sistemaOperativo;
}

Tastiera* Configurazione::getTastiera() const{
    return tastiera;
}

UnitaOttica* Configurazione::getUnitaOttica() const{
    return unitaOttica;
}
*/
