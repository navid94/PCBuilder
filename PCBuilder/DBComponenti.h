#ifndef DBCOMPONENTI_H
#define DBCOMPONENTI_H

#include "Componente.h"
#include "Container.h"
#include <QString>

class DBComponenti{
private:
   Container<Componente*> dbComponenti;
public:
    void aggiungi_componente(Componente*);
    void rimuovi_componente(Componente*);
    Componente* find_componente(const QString&) const;

    const Container<Componente*>& getDBComponenti() const;
};

#endif // DBCOMPONENTI_H
