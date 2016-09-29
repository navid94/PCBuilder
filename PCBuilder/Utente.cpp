#include "Utente.h"

Utente::Utente(PCBuilderController* input_controller):controller(input_controller){}

Utente::Utente(const Utente& u):controller(u.controller){}

PCBuilderController* Utente::get_controller() const{
    return controller;
}
