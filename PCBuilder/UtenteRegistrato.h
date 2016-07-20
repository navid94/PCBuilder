#ifndef UTENTEREGISTRATO_H
#define UTENTEREGISTRATO_H

#include "Utente.h"
#include "Profilo.h"
#include "Configurazione.h"
#include <QVector>

class UtenteRegistrato:public Utente{
private:
    Login id;
    Profilo pf;
    QVector<Configurazione*>* configurazioni;

public:
    UtenteRegistrato(PCBuilderController*,const Login&,const Profilo&);
    virtual void showIndex() const;
    virtual Login* get_Login() const;
    virtual Profilo* get_Profilo() const;
    virtual ~UtenteRegistrato();
    virtual QString get_type() const;
    virtual QVector<Configurazione*>* getConfigurazioni() const;
};

#endif // UTENTEREGISTRATO_H
