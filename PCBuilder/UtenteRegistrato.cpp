#include "UtenteRegistrato.h"

UtenteRegistrato::UtenteRegistrato(PCBuilderController* input_controller,const Login& input_id,const Profilo& input_pf):
    Utente(input_controller),id(input_id),pf(input_pf),configurazioni(new QVector<Configurazione*>){}

UtenteRegistrato::~UtenteRegistrato(){
    delete configurazioni;
    configurazioni=0;
}

void UtenteRegistrato::showIndex() const{
    get_controller()->set_IndexUtenteRegistrato();
}

Login* UtenteRegistrato::get_Login() const{
    return const_cast<Login*>(&id);
}

Profilo* UtenteRegistrato::get_Profilo() const{
    return const_cast<Profilo*>(&pf);
}

QString UtenteRegistrato::get_type() const{
    return "UtenteRegistrato";
}

QVector<Configurazione*>* UtenteRegistrato::getConfigurazioni() const{
    return configurazioni;
}
