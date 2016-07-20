#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <QString>
#include <QWidget>

class Componente{
private:
    QString nome;
    double prezzo;
    QString produttore;
public:
    Componente(const QString&, double, const QString&);
    virtual void saveXMLComponente()=0;
    virtual void deleteXMLComponente()=0;

    virtual ~Componente(){}
    virtual QString getType() const=0;
    QString getNome() const;
    double getPrezzo() const;
    QString getProduttore() const;
};

#endif // COMPONENTE_H
