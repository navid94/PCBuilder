#ifndef DBUTENTI_H
#define DBUTENTI_H

#include "Utente.h"
#include "Container.h"
#include "PCBuilderController.h"
#include <QString>

class DBUtenti{
private:
    Container<Utente*> dbUtenti;
    PCBuilderController* controller;
public:
    DBUtenti(PCBuilderController*);
    void aggiungi_utente(Utente*);
    void rimuovi_utente(Utente*);
    Utente* find_utente(const QString&) const;
    void modifica_utente(const QString&,const QString&,const QString&, const QString&, const QString&, const QString&,
                         const QString&, const QString&, const QString&, const QString&);
};


#endif // DBUTENTI_H
