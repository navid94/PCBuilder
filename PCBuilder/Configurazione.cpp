#include "Configurazione.h"

Configurazione::Configurazione(const QString& input_nome)
    :nome(input_nome){}

void Configurazione::aggiungiComponente(Componente* comp){
    conf.push_back(comp);
}

QString Configurazione::getNome() const{
    return nome;
}

QVector<Componente*> Configurazione::getConf() const{
    return conf;
}

double Configurazione::getPrezzoTotale() const{
    double tot=0;
    for (QVector<Componente*>::const_iterator it=conf.begin();it!=conf.end();it++)
    {
        tot=tot+(*it)->getPrezzo();
    }
    return tot;
}

void Configurazione::setNome(const QString& nomeConfigurazione){
    nome=nomeConfigurazione;
}

Configurazione* Configurazione::clone() const{
    return new Configurazione(*this);
}
