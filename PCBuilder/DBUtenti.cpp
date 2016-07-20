#include "DBUtenti.h"
#include "UtenteRegistrato.h"
#include "UtentePremium.h"

#include <QDomDocument>
#include <QTextStream>
#include <QFile>
#include <iostream>
using namespace std;

void DBUtenti::aggiungi_utente(Utente* u){
    dbUtenti.aggiungi_elemento(u);
}

void DBUtenti::rimuovi_utente(Utente* u){

    QString filename="Utenti.xml";
    if (QFile::exists(filename))
    {
        QFile file(filename);
        QDomDocument doc("Utenti");
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode utente_node=root.firstChildElement();
        QDomNode username_node;
        QDomNode tipoaccount_node;
        QDomNode email_node;
        QDomNode nome_node;
        QDomNode cognome_node;
        QDomNode password_node;
        QDomNode datanascita_node;
        bool trovato=false;
        while (!utente_node.isNull() && !trovato)
        {
            username_node=utente_node.firstChildElement();

            QString username_value=username_node.firstChild().nodeValue();
            if (username_value!=u->get_Login()->getUsername())
                utente_node=utente_node.nextSiblingElement();
            else
            {
                tipoaccount_node=username_node.nextSiblingElement();
                email_node=tipoaccount_node.nextSiblingElement();
                nome_node=email_node.nextSiblingElement();
                cognome_node=nome_node.nextSiblingElement();
                password_node=cognome_node.nextSiblingElement();
                datanascita_node=password_node.nextSiblingElement();
                trovato=true;
            }
        }
        utente_node.removeChild(username_node);
        utente_node.removeChild(tipoaccount_node);
        utente_node.removeChild(email_node);
        utente_node.removeChild(nome_node);
        utente_node.removeChild(cognome_node);
        utente_node.removeChild(password_node);
        utente_node.removeChild(datanascita_node);
        root.removeChild(utente_node);

        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
    dbUtenti.rimuovi_elemento(u);
}


Utente* DBUtenti::find_utente(const QString& username) const{
    for (Container<Utente*>::iteratore it=dbUtenti.begin(); it!=dbUtenti.end(); it++)
    {
        if (dbUtenti[it]->get_Login()->getUsername()==username)
            return dbUtenti[it];
    }
    return 0;
}

void DBUtenti::modifica_utente(const QString& utente, const QString& username, const QString& email, const QString& nome,
                               const QString& cognome, const QString& password, const QString& tipo_account,
                               const QString& giorno_nascita, const QString& mese_nascita, const QString& anno_nascita){
    Utente* user=find_utente(utente);

    QString filename="Utenti.xml";
    if (QFile::exists(filename))
    {
        QFile file(filename);
        QDomDocument doc("Utenti");
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode utente_node=root.firstChildElement();
        QDomNode username_node;
        QDomNode tipoaccount_node;
        QDomNode email_node;
        QDomNode nome_node;
        QDomNode cognome_node;
        QDomNode password_node;
        QDomNode datanascita_node;
        bool trovato=false;
        while (!utente_node.isNull() && !trovato)
        {
            username_node=utente_node.firstChildElement();

            QString username_value=username_node.firstChild().nodeValue();
            if (username_value!=utente)
                utente_node=utente_node.nextSiblingElement();
            else
            {
                tipoaccount_node=username_node.nextSiblingElement();
                email_node=tipoaccount_node.nextSiblingElement();
                nome_node=email_node.nextSiblingElement();
                cognome_node=nome_node.nextSiblingElement();
                password_node=cognome_node.nextSiblingElement();
                datanascita_node=password_node.nextSiblingElement();
                trovato=true;
            }
        }

        if (username!="")
        {
            user->get_Login()->setUsername(username);
            username_node.firstChild().setNodeValue(username);
        }
        if (email!="")
        {
            user->get_Profilo()->setEmail(email);
            email_node.firstChild().setNodeValue(email);
        }
        if (nome!="")
        {
            user->get_Profilo()->setNome(nome);
            nome_node.firstChild().setNodeValue(nome);
        }
        if (cognome!="")
        {
            user->get_Profilo()->setCognome(cognome);
            cognome_node.firstChild().setNodeValue(cognome);
        }
        if (password!="")
        {
            user->get_Login()->setPassword(password);
            password_node.firstChild().setNodeValue(password);
        }
        if (giorno_nascita!="")
        {
            user->get_Profilo()->setGiornoNascita(giorno_nascita);
            datanascita_node.firstChild().setNodeValue(user->get_Profilo()->getDataNascita());
        }

        if (mese_nascita!="")
        {
            user->get_Profilo()->setMeseNascita(mese_nascita);
            datanascita_node.firstChild().setNodeValue(user->get_Profilo()->getDataNascita());
        }
        if (anno_nascita!="")
        {
            user->get_Profilo()->setAnnoNascita(anno_nascita);
            datanascita_node.firstChild().setNodeValue(user->get_Profilo()->getDataNascita());
        }

        if (tipo_account!="")
            tipoaccount_node.firstChild().setNodeValue(tipo_account);

        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}
