#include "UtenteNonRegistrato.h"

UtenteNonRegistrato::UtenteNonRegistrato(PCBuilderController* input_controller):Utente(input_controller){}

void UtenteNonRegistrato::showIndex() const{
    get_controller()->set_IndexUtenteNonRegistrato();
}

Login* UtenteNonRegistrato::get_Login() const{
    return 0;
}

Profilo* UtenteNonRegistrato::get_Profilo() const{
    return 0;
}

QString UtenteNonRegistrato::get_type() const{
    return "UtenteNonRegistrato";
}

QVector<Configurazione*>* UtenteNonRegistrato::getConfigurazioni() const{
    return 0;
}

Utente* UtenteNonRegistrato::clone() const{
    return new UtenteNonRegistrato(*this);
}
