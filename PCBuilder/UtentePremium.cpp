#include "UtentePremium.h"

UtentePremium::UtentePremium(PCBuilderController* input_controller, const Login& input_login, const Profilo& input_profilo):
    UtenteRegistrato(input_controller,input_login,input_profilo){}

void UtentePremium::showIndex() const{
    get_controller()->set_IndexUtentePremium();
}

QString UtentePremium::get_type() const{
    return "UtentePremium";
}
