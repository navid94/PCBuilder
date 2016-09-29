#include "UtenteRegistrato.h"

UtenteRegistrato::UtenteRegistrato(PCBuilderController* input_controller,const Login& input_id,const Profilo& input_pf):
    Utente(input_controller),id(input_id),pf(input_pf),configurazioni(new QVector<Configurazione*>){}

UtenteRegistrato::UtenteRegistrato(PCBuilderController* input_controller, const Login& input_id, const Profilo& input_pf,
                                   const QVector<Configurazione *>& input_configurazioni):
    Utente(input_controller),id(input_id),pf(input_pf), configurazioni(new QVector<Configurazione*>(input_configurazioni)){}

UtenteRegistrato::~UtenteRegistrato(){
    delete configurazioni;
    configurazioni=0;
}

UtenteRegistrato::UtenteRegistrato(const UtenteRegistrato& u):Utente(u),id(u.id),pf(u.pf),configurazioni(new QVector<Configurazione*>(*(u.configurazioni))){}

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

Utente* UtenteRegistrato::clone() const{
    return new UtenteRegistrato(*this);
}
