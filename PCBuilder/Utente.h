#ifndef UTENTE_H
#define UTENTE_H

#include "Configurazione.h"
#include "PCBuilderController.h"
#include "Login.h"
#include "Profilo.h"
#include "Configurazione.h"


class Utente{
private:
    PCBuilderController* controller;
public:
    Utente(PCBuilderController*);
    Utente(const Utente&);
    virtual void showIndex() const =0;
    PCBuilderController* get_controller() const;
    virtual Login* get_Login() const =0;
    virtual Profilo* get_Profilo() const =0;
    virtual ~Utente(){}
    virtual QString get_type() const =0;
    virtual QVector<Configurazione*>* getConfigurazioni() const =0;
    virtual Utente* clone() const=0;
};

#endif // UTENTE_H
