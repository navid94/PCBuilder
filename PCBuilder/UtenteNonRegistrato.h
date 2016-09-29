#ifndef UTENTENONREGISTRATO_H
#define UTENTENONREGISTRATO_H

#include "Utente.h"



class UtenteNonRegistrato:public Utente{
private:

public:
    virtual void showIndex() const;
    UtenteNonRegistrato(PCBuilderController*);
    virtual ~UtenteNonRegistrato(){}
    virtual Login* get_Login() const;
    virtual Profilo* get_Profilo() const;
    virtual QString get_type() const;
    virtual QVector<Configurazione*>* getConfigurazioni() const;
    virtual Utente* clone() const;
};


#endif // UTENTENONREGISTRATO_H
