#ifndef UTENTEPREMIUM_H
#define UTENTEPREMIUM_H

#include "UtenteRegistrato.h"

class UtentePremium:public UtenteRegistrato{
private:

public:
    UtentePremium(PCBuilderController*,const Login&,const Profilo&);
    virtual ~UtentePremium(){}
    virtual void showIndex() const;
    virtual QString get_type() const;
};

#endif // UTENTEPREMIUM_H
