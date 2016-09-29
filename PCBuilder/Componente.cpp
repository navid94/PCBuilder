#include "Componente.h"

Componente::Componente(const QString& input_nome, double input_prezzo, const QString& input_produttore,
                       PCBuilderController* input_controller):nome(input_nome), prezzo(input_prezzo),
    produttore(input_produttore),controller(input_controller){}

Componente::Componente(PCBuilderController* input_controller):controller(input_controller){}

QString Componente::getNome() const{
    return nome;
}

double Componente::getPrezzo() const{
    return prezzo;
}

QString Componente::getProduttore() const{
    return produttore;
}

PCBuilderController* Componente::getController() const{
    return controller;
}
