#ifndef PROFILO_H
#define PROFILO_H

#include <QString>
#include <QDate>

class Profilo{
private:
    QString Nome;
    QString Cognome;
    QString Email;
    QDate DataNascita;
public:
    Profilo(const QString&,const QString&,const QString&,const QString&,const QString&,const QString&);
    QString getNome() const;
    QString getCognome() const;
    QString getEmail() const;
    QString getDataNascita() const;

    void setNome(const QString&);
    void setCognome(const QString&);
    void setEmail(const QString&);
    void setGiornoNascita(const QString&);
    void setMeseNascita(const QString&);
    void setAnnoNascita(const QString&);

};

#endif // PROFILO_H
