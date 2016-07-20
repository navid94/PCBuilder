#ifndef DBUTENTI_H
#define DBUTENTI_H

#include "Utente.h"
#include "Container.h"
#include <QString>

class DBUtenti{
private:
    Container<Utente*> dbUtenti;
public:
    void aggiungi_utente(Utente*);
    void rimuovi_utente(Utente*);
    Utente* find_utente(const QString&) const;
    void modifica_utente(const QString&,const QString&,const QString&, const QString&, const QString&, const QString&,
                         const QString&, const QString&, const QString&, const QString&);
};


#endif // DBUTENTI_H
