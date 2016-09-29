#include "UtentePremium.h"

UtentePremium::UtentePremium(PCBuilderController* input_controller, const Login& input_login, const Profilo& input_profilo):
    UtenteRegistrato(input_controller,input_login,input_profilo){}

UtentePremium::UtentePremium(PCBuilderController* input_controller, const Login& input_login, const Profilo& input_profilo,
                             const QVector<Configurazione*>& input_configurazione):
    UtenteRegistrato(input_controller,input_login,input_profilo,input_configurazione){}

void UtentePremium::showIndex() const{
    get_controller()->set_IndexUtentePremium();
}

QString UtentePremium::get_type() const{
    return "UtentePremium";
}

Utente* UtentePremium::clone() const{
    return new UtentePremium(*this);
}
