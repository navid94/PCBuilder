#include "DBComponenti.h"

#include <QDomDocument>
#include <QTextStream>
#include <QFile>

void DBComponenti::aggiungi_componente(Componente* c){
    dbComponenti.aggiungi_elemento(c);
}


void DBComponenti::rimuovi_componente(Componente* c){

    c->deleteXMLComponente();
    dbComponenti.rimuovi_elemento(c);
}


Componente* DBComponenti::find_componente(const QString& nome) const{
    for (Container<Componente*>::iteratore it=dbComponenti.begin();it!=dbComponenti.end();it++)
    {
        if (dbComponenti[it]->getNome()==nome)
            return dbComponenti[it];
    }
    return 0;
}

const Container<Componente*>& DBComponenti::getDBComponenti() const{
    return dbComponenti;
}
