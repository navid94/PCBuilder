#include "Utente.h"

Utente::Utente(PCBuilderController* input_controller):controller(input_controller){}

PCBuilderController* Utente::get_controller() const{
    return controller;
}

Utente::~Utente(){
    delete controller;
}
