#include "Profilo.h"

QString Profilo::getNome() const{
    return Nome;
}

QString Profilo::getCognome() const{
    return Cognome;
}

QString Profilo::getEmail() const{
    return Email;
}

QString Profilo::getDataNascita() const{
    return DataNascita.toString("dd/MM/yyyy");
}

Profilo::Profilo(const QString& input_Nome, const QString& input_Cognome, const QString& input_Email,
                 const QString& input_giornoDataNascita, const QString& input_meseDataNascita, const QString& input_annoDataNascita):
    Nome(input_Nome),Cognome(input_Cognome),Email(input_Email){
    DataNascita.setDate(input_annoDataNascita.toInt(),input_meseDataNascita.toInt(),input_giornoDataNascita.toInt());
}

void Profilo::setNome(const QString& input_nome){
    Nome=input_nome;
}

void Profilo::setCognome(const QString& input_cognome){
    Cognome=input_cognome;
}

void Profilo::setEmail(const QString& input_email){
    Email=input_email;
}

void Profilo::setGiornoNascita(const QString& input_giorno){
    int old_mese=DataNascita.month();
    int old_anno=DataNascita.year();
    DataNascita.setDate(old_anno,old_mese,input_giorno.toInt());
}

void Profilo::setMeseNascita(const QString& input_mese){
    int old_giorno=DataNascita.day();
    int old_anno=DataNascita.year();
    DataNascita.setDate(old_anno,input_mese.toInt(),old_giorno);
}

void Profilo::setAnnoNascita(const QString& input_anno){
    int old_giorno=DataNascita.day();
    int old_mese=DataNascita.month();
    DataNascita.setDate(input_anno.toInt(),old_mese,old_giorno);
}
