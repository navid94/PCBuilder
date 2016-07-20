#include "Componente.h"

Componente::Componente(const QString& input_nome, double input_prezzo, const QString& input_produttore):
    nome(input_nome), prezzo(input_prezzo), produttore(input_produttore){}

QString Componente::getNome() const{
    return nome;
}

double Componente::getPrezzo() const{
    return prezzo;
}

QString Componente::getProduttore() const{
    return produttore;
}
