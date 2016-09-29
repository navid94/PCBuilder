#ifndef UTENTEPREMIUM_H
#define UTENTEPREMIUM_H

#include "UtenteRegistrato.h"

class UtentePremium:public UtenteRegistrato{
private:

public:
    UtentePremium(PCBuilderController*,const Login&,const Profilo&);
    UtentePremium(PCBuilderController*,const Login&,const Profilo&, const QVector<Configurazione*>&);
    virtual ~UtentePremium(){}
    virtual void showIndex() const;
    virtual QString get_type() const;
    virtual Utente* clone() const;
};

#endif // UTENTEPREMIUM_H
