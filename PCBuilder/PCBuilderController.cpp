#include "PCBuilderController.h"
#include "Utente.h"
#include "DBUtenti.h"
#include "UtenteRegistrato.h"
#include "UtenteNonRegistrato.h"
#include "UtentePremium.h"
#include "Memoria.h"
#include "SchedaGrafica.h"
#include "SchedaMadre.h"
#include "Processore.h"
#include "Archiviazione.h"
#include "Alimentatore.h"
#include "DissipatoreProcessore.h"
#include "Case.h"
#include "UnitaOttica.h"
#include "Monitor.h"
#include "SistemaOperativo.h"
#include "Mouse.h"
#include "Tastiera.h"
#include "Cuffie.h"
#include "Altoparlanti.h"


#include <QMessageBox>
#include <QRegExp>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <typeinfo>
#include <QInputDialog>

#include <iostream>
using namespace std;



PCBuilderController::PCBuilderController(){
    dbusers=new DBUtenti;
    mw=new MainWindow(this);
    connect(mw,SIGNAL(closeMainWindow()),this,SLOT(close_MainWindow()));
    dbcomponents=new DBComponenti;
    load_DBUtenti();
    load_DBComponenti();
    u=new UtenteNonRegistrato(this);
}

PCBuilderController::~PCBuilderController(){
    delete mw;
    mw=0;
    delete u;
    u=0;
    delete dbusers;
    dbusers=0;
    delete dbcomponents;
    dbcomponents=0;
    delete comp;
    comp=0;
}

Utente* PCBuilderController::getUser() const{
    return u;
}

void PCBuilderController::load_DBUtenti(){
    QString filename="Utenti.xml";
    if (QFile::exists(filename))
    {
        QFile file(filename);
        QDomDocument doc("Utenti");
        file.open(QIODevice::ReadOnly);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode utente=root.firstChildElement();

        while (!utente.isNull())
        {
            QDomNode username_node=utente.firstChildElement();
            QString username=username_node.firstChild().nodeValue();
            QDomNode tipo_account_node=username_node.nextSiblingElement();
            QString tipo_account=tipo_account_node.firstChild().nodeValue();
            QDomNode email_node=tipo_account_node.nextSiblingElement();
            QString email=email_node.firstChild().nodeValue();
            QDomNode nome_node=email_node.nextSiblingElement();
            QString nome=nome_node.firstChild().nodeValue();
            QDomNode cognome_node=nome_node.nextSiblingElement();
            QString cognome=cognome_node.firstChild().nodeValue();
            QDomNode password_node=cognome_node.nextSiblingElement();
            QString password=password_node.firstChild().nodeValue();
            QDomNode data_nascita_node=password_node.nextSiblingElement();
            QString data_nascita=data_nascita_node.firstChild().nodeValue();

            QDate date=QDate::fromString(data_nascita,"dd/MM/yyyy");
            Profilo pf(nome,cognome,email,QString::number(date.day()),QString::number(date.month()),QString::number(date.year()));
            Login id(username,password);
            if (tipo_account=="UtenteRegistrato")
                u=new UtenteRegistrato(this,id,pf);
            else
            {
                if (tipo_account=="UtentePremium")
                {
                    u=new UtentePremium(this,id,pf);
                }
            }
            dbusers->aggiungi_utente(u);
            utente=utente.nextSiblingElement();
        }
        file.close();
    }
}

bool PCBuilderController::email_validation(const QString& input_email) const{
    QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailREX.setCaseSensitivity(Qt::CaseInsensitive);
    mailREX.setPatternSyntax(QRegExp::RegExp);
    if (mailREX.exactMatch(input_email))
        return true;
    else
        return false;
}

void PCBuilderController::saveXMLUtenti(Utente* user) const{
    QString filename="Utenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Utenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode utente=doc.createElement("Utente");
        root.appendChild(utente);

        QDomNode username=doc.createElement("Username");
        username.appendChild(doc.createTextNode(user->get_Login()->getUsername()));

        QDomNode tipo_account=doc.createElement("Tipo_account");
        if (user->get_type()=="UtenteRegistrato")
            tipo_account.appendChild(doc.createTextNode("UtenteRegistrato"));
        else
        {
            if (user->get_type()=="UtentePremium")
                tipo_account.appendChild(doc.createTextNode("UtentePremium"));
        }

        QDomNode email=doc.createElement("Email");
        email.appendChild(doc.createTextNode(user->get_Profilo()->getEmail()));

        QDomNode nome=doc.createElement("Nome");
        nome.appendChild(doc.createTextNode(user->get_Profilo()->getNome()));

        QDomNode cognome=doc.createElement("Cognome");
        cognome.appendChild(doc.createTextNode(user->get_Profilo()->getCognome()));

        QDomNode password=doc.createElement("Password");
        password.appendChild(doc.createTextNode(user->get_Login()->getPassword()));

        QDomNode data_nascita=doc.createElement("Data_nascita");
        data_nascita.appendChild(doc.createTextNode(user->get_Profilo()->getDataNascita()));

        utente.appendChild(username);
        utente.appendChild(tipo_account);
        utente.appendChild(email);
        utente.appendChild(nome);
        utente.appendChild(cognome);
        utente.appendChild(password);
        utente.appendChild(data_nascita);

        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
    else
    {
        QDomDocument doc("Utenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomProcessingInstruction header=doc.createProcessingInstruction("xml","version='1.0' encoding='UTF-8'");
        doc.appendChild(header);
        QDomNode utenti=doc.createElement("Utenti");
        doc.appendChild(utenti);
        QDomNode utente=doc.createElement("Utente");
        utenti.appendChild(utente);

        QDomNode username=doc.createElement("Username");
        username.appendChild(doc.createTextNode(user->get_Login()->getUsername()));

        QDomNode tipo_account=doc.createElement("Tipo_account");
        if (user->get_type()=="UtenteRegistrato")
            tipo_account.appendChild(doc.createTextNode("UtenteRegistrato"));
        else
        {
            if (user->get_type()=="UtentePremium")
                tipo_account.appendChild(doc.createTextNode("UtentePremium"));
        }

        QDomNode email=doc.createElement("Email");
        email.appendChild(doc.createTextNode(user->get_Profilo()->getEmail()));

        QDomNode nome=doc.createElement("Nome");
        nome.appendChild(doc.createTextNode(user->get_Profilo()->getNome()));

        QDomNode cognome=doc.createElement("Cognome");
        cognome.appendChild(doc.createTextNode(user->get_Profilo()->getCognome()));

        QDomNode password=doc.createElement("Password");
        password.appendChild(doc.createTextNode(user->get_Login()->getPassword()));

        QDomNode data_nascita=doc.createElement("Data_nascita");
        data_nascita.appendChild(doc.createTextNode(user->get_Profilo()->getDataNascita()));


        utente.appendChild(username);
        utente.appendChild(tipo_account);
        utente.appendChild(email);
        utente.appendChild(nome);
        utente.appendChild(cognome);
        utente.appendChild(password);
        utente.appendChild(data_nascita);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void PCBuilderController::eseguiRegistrazione(const QString& input_username,const QString& input_password,
                                              const QString& input_email,const QString& input_nome,const QString& input_cognome,
                                              const QString& input_giornonascita,const QString& input_mesenascita,const QString& input_annonascita){

    QString confermapassword=mw->get_RegistrazioneUtentePCBuilder()->confermapasswordValue();

    if (input_username=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un username"),QMessageBox::Ok);
    else
    {
        if (input_email=="")
            QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire una email"),QMessageBox::Ok);
        else
        {
            if (input_nome=="")
                QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
            else
            {
                if (input_cognome=="")
                    QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un cognome"),QMessageBox::Ok);
                else
                {
                    if (input_password=="")
                        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire una password"),QMessageBox::Ok);
                    else
                    {
                        if (confermapassword=="")
                            QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire la conferma della password"),QMessageBox::Ok);
                        else
                        {
                            if (confermapassword!=input_password)
                                QMessageBox::warning(mw,"PCBuilder",tr("La conferma della password inserita è errata"),QMessageBox::Ok);
                            else
                            {
                                if (input_giornonascita=="" || input_mesenascita=="" || input_annonascita=="")
                                    QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire una data di nascita valida"),QMessageBox::Ok);
                                else
                                {
                                    if (!email_validation(input_email))
                                        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire una email valida"),QMessageBox::Ok);
                                    else
                                    {

                                        if (dbusers->find_utente(input_username))
                                            QMessageBox::warning(mw,"PCBuilder",tr("Username inserito è già occupato"),QMessageBox::Ok);
                                        else
                                        {
                                            Profilo pf(input_nome,input_cognome,input_email,input_giornonascita,input_mesenascita,input_annonascita);
                                            Login id(input_username,input_password);
                                            u=new UtenteRegistrato(this,id,pf);
                                            dbusers->aggiungi_utente(u);
                                            QMessageBox::information(mw,tr("PCBuilder"),tr("La registrazione è avvenuta con successo, ora è possibile eseguire l'accesso"),QMessageBox::Ok);
                                            saveXMLUtenti(u);
                                            u=new UtenteNonRegistrato(this);
                                            mw->openIndexUtenteNonRegistratoPCBuilder();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void PCBuilderController::registrati(){
    eseguiRegistrazione(mw->get_RegistrazioneUtentePCBuilder()->usernameValue(),mw->get_RegistrazioneUtentePCBuilder()->passwordValue(),
                        mw->get_RegistrazioneUtentePCBuilder()->emailValue(),mw->get_RegistrazioneUtentePCBuilder()->nomeValue(),
                        mw->get_RegistrazioneUtentePCBuilder()->cognomeValue(),mw->get_RegistrazioneUtentePCBuilder()->giornonascitaValue(),
                        mw->get_RegistrazioneUtentePCBuilder()->mesenascitaValue(),mw->get_RegistrazioneUtentePCBuilder()->annonascitaValue());
}

MainWindow* PCBuilderController::get_MainWindow() const{
    return mw;
}

void PCBuilderController::accedi(){
    QString username=mw->get_IndexUtenteNonRegistratoPCBuilder()->usernameValue();
    QString password=mw->get_IndexUtenteNonRegistratoPCBuilder()->passwordValue();
    u=dbusers->find_utente(username);
    if (!u)
        QMessageBox::warning(mw,"PCBuilder",tr("L'username inserito non è registrato nel nostro sistema"),QMessageBox::Ok);
    else
    {
        if (u->get_Login()->getPassword()!=password)
            QMessageBox::warning(mw,"PCBuilder",tr("La password inserita è errata"),QMessageBox::Ok);
        else
        {
            QMessageBox::information(mw,tr("PCBuilder"),tr("Accesso eseguito correttamente"),QMessageBox::Ok);
            u->showIndex();
        }
    }
}


void PCBuilderController::callShowIndex(){
    u->showIndex();
}

void PCBuilderController::set_IndexUtenteNonRegistrato(){
    mw->openIndexUtenteNonRegistratoPCBuilder();
}

void PCBuilderController::set_IndexUtenteRegistrato(){
    mw->openIndexUtenteRegistratoPCBuilder();
}

void PCBuilderController::set_IndexUtentePremium(){
    mw->openIndexUtentePremiumPCBuilder();
}

void PCBuilderController::build_PartsListPCBuilder(){

}

void PCBuilderController::callModificaUtenti(){
    QString utente=mw->get_GestisciUtentiPCBuilder()->username_utentemodificaValue();
    QString username=mw->get_GestisciUtentiPCBuilder()->usernameValue();
    QString email=mw->get_GestisciUtentiPCBuilder()->emailValue();
    QString nome=mw->get_GestisciUtentiPCBuilder()->nomeValue();
    QString cognome=mw->get_GestisciUtentiPCBuilder()->cognomeValue();
    QString password=mw->get_GestisciUtentiPCBuilder()->passwordValue();
    QString tipo_account=mw->get_GestisciUtentiPCBuilder()->tipoaccountValue();
    QString giornonascita=mw->get_GestisciUtentiPCBuilder()->giornonascitaValue();
    QString mesenascita=mw->get_GestisciUtentiPCBuilder()->mesenascitaValue();
    QString annonascita=mw->get_GestisciUtentiPCBuilder()->annonascitaValue();

    if (!dbusers->find_utente(utente))
        QMessageBox::warning(mw,"PCBuilder",tr("L'username inserito non è registrato nel sistema"),QMessageBox::Ok);
    else
    {
        if (email!="" && !email_validation(email))
            QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire una email valida"),QMessageBox::Ok);
        else
        {
            if (dbusers->find_utente(username))
                QMessageBox::warning(mw,"PCBuilder",tr("Username inserito è già occupato"),QMessageBox::Ok);
            else
            {
                dbusers->modifica_utente(utente,username,email,nome,cognome,password,tipo_account,giornonascita,
                                         mesenascita,annonascita);
                QMessageBox::information(mw,tr("PCBuilder"),tr("La modifica è avvenuta con successo"),QMessageBox::Ok);
            }
        }
    }
}

void PCBuilderController::callRimuoviUtente(){
    QString utente=mw->get_GestisciUtentiPCBuilder()->username_utenterimuovereValue();
    u=dbusers->find_utente(utente);
    if (!u)
        QMessageBox::warning(mw,"PCBuilder",tr("L'username inserito non è registrato nel sistema"),QMessageBox::Ok);
    else
    {
        dbusers->rimuovi_utente(u);
        QMessageBox::information(mw,tr("PCBuilder"),tr("La rimozione è avvenuta con successo"),QMessageBox::Ok);
    }
    u=new UtenteNonRegistrato(this);
}

void PCBuilderController::aggiungi_componente(){
    QString tipo_componente=mw->get_GestisciComponentiPCBuilder()->tipo_componenteAggiungiValue();

    if (tipo_componente=="Memoria")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeMemoriaValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreMemoriaValue();
        QString velocita=mw->get_GestisciComponentiPCBuilder()->velocitaMemoriaValue();
        QString capacita=mw->get_GestisciComponentiPCBuilder()->capacitaMemoriaValue();
        QString tipologia=mw->get_GestisciComponentiPCBuilder()->tipologiaMemoriaValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoMemoriaValue();
        int latenza=mw->get_GestisciComponentiPCBuilder()->latenzaMemoriaValue();
        eseguiAggiuntaMemoria(nome,produttore,velocita,capacita,tipologia,prezzo,latenza);
    }
    if (tipo_componente=="Scheda grafica")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeSchedaGraficaValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreSchedaGraficaValue();
        QString interfaccia=mw->get_GestisciComponentiPCBuilder()->interfacciaSchedaGraficaValue();
        QString chipset=mw->get_GestisciComponentiPCBuilder()->chipsetSchedaGraficaValue();
        QString memoria=mw->get_GestisciComponentiPCBuilder()->memoriaSchedaGraficaValue();
        QString tipologiaMemoria=mw->get_GestisciComponentiPCBuilder()->tipologiaMemoriaSchedaGraficaValue();
        QString frequenzaCore=mw->get_GestisciComponentiPCBuilder()->frequenzaCoreSchedaGraficaValue();
        QString tdp=mw->get_GestisciComponentiPCBuilder()->tdpSchedaGraficaValue();
        QString supportoSLI=mw->get_GestisciComponentiPCBuilder()->supportoSLISchedaGraficaValue();
        QString supportoCrossfire=mw->get_GestisciComponentiPCBuilder()->supportoCrossfireSchedaGraficaValue();
        QString lunghezza=mw->get_GestisciComponentiPCBuilder()->lunghezzaSchedaGraficaValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoSchedaGraficaValue();
        eseguiAggiuntaSchedaGrafica(nome,produttore,interfaccia,chipset,memoria,tipologiaMemoria,frequenzaCore,tdp,
                                    supportoSLI,supportoCrossfire,lunghezza,prezzo);
    }
    if (tipo_componente=="Scheda madre")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeSchedaMadreValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreSchedaMadreValue();
        QString fattoreDiForma=mw->get_GestisciComponentiPCBuilder()->fattoreDiFormaSchedaMadreValue();
        QString chipset=mw->get_GestisciComponentiPCBuilder()->chipsetSchedaMadreValue();
        QString socketProcessore=mw->get_GestisciComponentiPCBuilder()->socketProcessoreSchedaMadreValue();
        QString slotMemoria=mw->get_GestisciComponentiPCBuilder()->slotMemoriaSchedaMadreValue();
        QString tipologiaMemoria=mw->get_GestisciComponentiPCBuilder()->tipologiaMemoriaSchedaMadreValue();
        QString memoriaMassima=mw->get_GestisciComponentiPCBuilder()->memoriaMassimaSchedaMadreValue();
        QString ethernet=mw->get_GestisciComponentiPCBuilder()->ethernetSchedaMadreValue();
        bool supportoRAID=mw->get_GestisciComponentiPCBuilder()->supportoRAIDSchedaMadreValue();
        bool supportoCrossfire=mw->get_GestisciComponentiPCBuilder()->supportoCrossfireSchedaMadreValue();
        bool supportoSLI=mw->get_GestisciComponentiPCBuilder()->supportoSLISchedaMadreValue();
        int sata3GBs=mw->get_GestisciComponentiPCBuilder()->sata3GBsSchedaMadreValue();
        int sata6GBs=mw->get_GestisciComponentiPCBuilder()->sata6GBsSchedaMadreValue();
        int sataExpress=mw->get_GestisciComponentiPCBuilder()->sataExpressSchedaMadreValue();
        int usb2=mw->get_GestisciComponentiPCBuilder()->usb2SchedaMadreValue();
        int usb3=mw->get_GestisciComponentiPCBuilder()->usb3SchedaMadreValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoSchedaMadreValue();
        eseguiAggiuntaSchedaMadre(nome,produttore,fattoreDiForma,chipset,socketProcessore,slotMemoria,tipologiaMemoria,
                                  memoriaMassima,ethernet,supportoRAID,supportoCrossfire,supportoSLI,sata3GBs,sata6GBs,
                                  sataExpress,usb2,usb3,prezzo);
    }
    if (tipo_componente=="Processore")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeProcessoreValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreProcessoreValue();
        QString socket=mw->get_GestisciComponentiPCBuilder()->socketProcessoreValue();
        QString larghezzaDati=mw->get_GestisciComponentiPCBuilder()->larghezzaDatiProcessoreValue();
        QString frequenzaOperativa=mw->get_GestisciComponentiPCBuilder()->frequenzaOperativaProcessoreValue();
        QString frequenzaTurbo=mw->get_GestisciComponentiPCBuilder()->frequenzaTurboProcessoreValue();
        QString l1Cache=mw->get_GestisciComponentiPCBuilder()->l1CacheProcessoreValue();
        QString l2Cache=mw->get_GestisciComponentiPCBuilder()->l2CacheProcessoreValue();
        QString l3Cache=mw->get_GestisciComponentiPCBuilder()->l3CacheProcessoreValue();
        QString litografia=mw->get_GestisciComponentiPCBuilder()->litografiaProcessoreValue();
        QString tdp=mw->get_GestisciComponentiPCBuilder()->tdpProcessoreValue();
        QString graficaIntegrata=mw->get_GestisciComponentiPCBuilder()->graficaIntegrataProcessoreValue();
        bool includeDissipatore=mw->get_GestisciComponentiPCBuilder()->includeDissipatoreProcessoreValue();
        bool hyperThreading=mw->get_GestisciComponentiPCBuilder()->hyperThreadingProcessoreValue();
        int numeroCore=mw->get_GestisciComponentiPCBuilder()->numeroCoreProcessoreValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoProcessoreValue();
        eseguiAggiuntaProcessore(nome,produttore,socket,larghezzaDati,frequenzaOperativa,frequenzaTurbo,l1Cache,l2Cache,l3Cache,
                                 litografia,tdp,graficaIntegrata,includeDissipatore,hyperThreading,numeroCore,prezzo);
    }
    if (tipo_componente=="Archiviazione")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeArchiviazioneValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreArchiviazioneValue();
        QString tipologia=mw->get_GestisciComponentiPCBuilder()->tipologiaArchiviazioneValue();
        QString capacita=mw->get_GestisciComponentiPCBuilder()->capacitaArchiviazioneValue();
        QString interfaccia=mw->get_GestisciComponentiPCBuilder()->interfacciaArchiviazioneValue();
        QString cache=mw->get_GestisciComponentiPCBuilder()->cacheArchiviazioneValue();
        QString fattoreDiForma=mw->get_GestisciComponentiPCBuilder()->fattoreDiFormaArchiviazioneValue();
        QString rpm=mw->get_GestisciComponentiPCBuilder()->rpmArchiviazioneValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoArchiviazioneValue();
        eseguiAggiuntaArchiviazione(nome,produttore,tipologia,capacita,interfaccia,cache,fattoreDiForma,rpm,prezzo);
    }
    if (tipo_componente=="Alimentatore")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeAlimentatoreValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreAlimentatoreValue();
        QString tipologia=mw->get_GestisciComponentiPCBuilder()->tipologiaAlimentatoreValue();
        QString wattaggio=mw->get_GestisciComponentiPCBuilder()->wattaggioAlimentatoreValue();
        QString modulare=mw->get_GestisciComponentiPCBuilder()->modulareAlimentatoreValue();
        QString certificazioneEfficienza=mw->get_GestisciComponentiPCBuilder()->certificazioneEfficienzaAlimentatoreValue();
        double efficienza=mw->get_GestisciComponentiPCBuilder()->efficienzaAlimentatoreValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoAlimentatoreValue();
        eseguiAggiuntaAlimentatore(nome,produttore,tipologia,wattaggio,modulare,certificazioneEfficienza,efficienza,prezzo);
    }
    if (tipo_componente=="Dissipatore processore")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeDissipatoreProcessoreValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreDissipatoreProcessoreValue();
        QString socketSupportati=mw->get_GestisciComponentiPCBuilder()->socketSupportatiDissipatoreProcessoreValue();
        QString rpmVentola=mw->get_GestisciComponentiPCBuilder()->rpmVentolaDissipatoreProcessoreValue();
        QString altezza=mw->get_GestisciComponentiPCBuilder()->altezzaDissipatoreProcessoreValue();
        QString altezzaRadiatore=mw->get_GestisciComponentiPCBuilder()->altezzaRadiatoreDissipatoreProcessoreValue();
        QString livelloRumore=mw->get_GestisciComponentiPCBuilder()->livelloRumoreDissipatoreProcessoreValue();
        bool raffreddamentoALiquido=mw->get_GestisciComponentiPCBuilder()->raffreddamentoALiquidoDissipatoreProcessoreValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoDissipatoreProcessoreValue();
        eseguiAggiuntaDissipatoreProcessore(nome,produttore,socketSupportati,rpmVentola,altezza,altezzaRadiatore,livelloRumore,
                                            raffreddamentoALiquido,prezzo);
    }
    if (tipo_componente=="Case")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeCaseValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreCaseValue();
        QString tipologia=mw->get_GestisciComponentiPCBuilder()->tipologiaCaseValue();
        QString colore=mw->get_GestisciComponentiPCBuilder()->coloreCaseValue();
        QString compatibilitaSchedaMadre=mw->get_GestisciComponentiPCBuilder()->compatibilitaSchedaMadreCaseValue();
        QString lunghezzaMassimaSchedaGrafica=mw->get_GestisciComponentiPCBuilder()->lunghezzaMassimaSchedaGraficaCaseValue();
        QString dimensioni=mw->get_GestisciComponentiPCBuilder()->dimensioniCaseValue();
        bool alimentatoreIncluso=mw->get_GestisciComponentiPCBuilder()->alimentatoreInclusoCaseValue();
        int slotInterni25=mw->get_GestisciComponentiPCBuilder()->slotInterni25CaseValue();
        int slotInterni35=mw->get_GestisciComponentiPCBuilder()->slotInterni35CaseValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoCaseValue();
        eseguiAggiuntaCase(nome,produttore,tipologia,colore,compatibilitaSchedaMadre,lunghezzaMassimaSchedaGrafica,dimensioni,
                           alimentatoreIncluso,slotInterni25,slotInterni35,prezzo);
    }
    if (tipo_componente=="Unità ottica")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeUnitaOtticaValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreUnitaOtticaValue();
        QString fattoreDiForma=mw->get_GestisciComponentiPCBuilder()->fattoreDiFormaUnitaOtticaValue();
        QString interfaccia=mw->get_GestisciComponentiPCBuilder()->interfacciaUnitaOtticaValue();
        QString cache=mw->get_GestisciComponentiPCBuilder()->cacheUnitaOtticaValue();
        QString velocita=mw->get_GestisciComponentiPCBuilder()->velocitaUnitaOtticaValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoUnitaOtticaValue();
        eseguiAggiuntaUnitaOttica(nome,produttore,fattoreDiForma,interfaccia,cache,velocita,prezzo);
    }
    if (tipo_componente=="Monitor")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeMonitorValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreMonitorValue();
        QString risoluzioneRaccomandata=mw->get_GestisciComponentiPCBuilder()->risoluzioneRaccomandataMonitorValue();
        QString formato=mw->get_GestisciComponentiPCBuilder()->formatoMonitorValue();
        QString angoloDiVisualizzazione=mw->get_GestisciComponentiPCBuilder()->angoloDiVisualizzazioneMonitorValue();
        QString coloriDelDisplay=mw->get_GestisciComponentiPCBuilder()->coloriDelDisplayMonitorValue();
        QString luminosita=mw->get_GestisciComponentiPCBuilder()->luminositaMonitorValue();
        QString rapportoDiContrasto=mw->get_GestisciComponentiPCBuilder()->rapportoDiContrastoMonitorValue();
        QString tempoDiRisposta=mw->get_GestisciComponentiPCBuilder()->tempoDiRispostaMonitorValue();
        QString tipologiaDisplay=mw->get_GestisciComponentiPCBuilder()->tipologiaDisplayMonitorValue();
        QString frequenzaDiAggiornamento=mw->get_GestisciComponentiPCBuilder()->frequenzaDiAggiornamentoMonitorValue();
        bool altoparlantiIncorporati=mw->get_GestisciComponentiPCBuilder()->altoparlantiIncorporatiMonitorValue();
        bool widescreen=mw->get_GestisciComponentiPCBuilder()->widescreenMonitorValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoMonitorValue();
        eseguiAggiuntaMonitor(nome,produttore,risoluzioneRaccomandata,formato,angoloDiVisualizzazione,coloriDelDisplay,
                              luminosita,rapportoDiContrasto,tempoDiRisposta,tipologiaDisplay,frequenzaDiAggiornamento,
                              altoparlantiIncorporati,widescreen,prezzo);
    }
    if (tipo_componente=="Sistema operativo")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeSistemaOperativoValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreSistemaOperativoValue();
        QString modalita=mw->get_GestisciComponentiPCBuilder()->modalitaSistemaOperativoValue();
        QString memoriaMassimaSupportata=mw->get_GestisciComponentiPCBuilder()->memoriaMassimaSupportataSistemaOperativoValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoSistemaOperativoValue();
        eseguiAggiuntaSistemaOperativo(nome,produttore,modalita,memoriaMassimaSupportata,prezzo);
    }
    if (tipo_componente=="Mouse")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeMouseValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreMouseValue();
        QString connessione=mw->get_GestisciComponentiPCBuilder()->connessioneMouseValue();
        QString tipologiaTracciamento=mw->get_GestisciComponentiPCBuilder()->tipologiaTracciamentoMouseValue();
        QString colore=mw->get_GestisciComponentiPCBuilder()->coloreMouseValue();
        QString orientamentoDellaMano=mw->get_GestisciComponentiPCBuilder()->orientamentoDellaManoMouseValue();
        int dpiMassimi=mw->get_GestisciComponentiPCBuilder()->dpiMassimiMouseValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoMouseValue();
        eseguiAggiuntaMouse(nome,produttore,connessione,tipologiaTracciamento,colore,orientamentoDellaMano,dpiMassimi,prezzo);
    }
    if (tipo_componente=="Tastiera")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeTastieraValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreTastieraValue();
        QString colore=mw->get_GestisciComponentiPCBuilder()->coloreTastieraValue();
        QString connessione=mw->get_GestisciComponentiPCBuilder()->connessioneTastieraValue();
        QString tipologia=mw->get_GestisciComponentiPCBuilder()->tipologiaTastieraValue();
        QString tipologiaSwitch=mw->get_GestisciComponentiPCBuilder()->tipologiaSwitchTastieraValue();
        bool retroilluminazione=mw->get_GestisciComponentiPCBuilder()->retroilluminazioneTastieraValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoTastieraValue();
        eseguiAggiuntaTastiera(nome,produttore,colore,connessione,tipologia,tipologiaSwitch,retroilluminazione,prezzo);
    }
    if (tipo_componente=="Cuffie")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeCuffieValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreCuffieValue();
        QString tipologia=mw->get_GestisciComponentiPCBuilder()->tipologiaCuffieValue();
        QString sistemaAcustico=mw->get_GestisciComponentiPCBuilder()->sistemaAcusticoCuffieValue();
        QString colore=mw->get_GestisciComponentiPCBuilder()->coloreCuffieValue();
        QString canali=mw->get_GestisciComponentiPCBuilder()->canaliCuffieValue();
        QString impedenza=mw->get_GestisciComponentiPCBuilder()->impedenzaCuffieValue();
        QString frequenzaDiRisposta=mw->get_GestisciComponentiPCBuilder()->frequenzaDiRispostaCuffieValue();
        QString connessione=mw->get_GestisciComponentiPCBuilder()->connessioneCuffieValue();
        QString connettore=mw->get_GestisciComponentiPCBuilder()->connettoreCuffieValue();
        bool microfono=mw->get_GestisciComponentiPCBuilder()->microfonoCuffieValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoCuffieValue();
        eseguiAggiuntaCuffie(nome,produttore,tipologia,sistemaAcustico,colore,canali,impedenza,frequenzaDiRisposta,connessione,
                             connettore,microfono,prezzo);
    }
    if (tipo_componente=="Altoparlanti")
    {
        QString nome=mw->get_GestisciComponentiPCBuilder()->nomeAltoparlantiValue();
        QString produttore=mw->get_GestisciComponentiPCBuilder()->produttoreAltoparlantiValue();
        QString colore=mw->get_GestisciComponentiPCBuilder()->coloreAltoparlantiValue();
        QString configurazione=mw->get_GestisciComponentiPCBuilder()->configurazioneAltoparlantiValue();
        QString frequenzaDiRisposta=mw->get_GestisciComponentiPCBuilder()->frequenzaDiRispostaAltoparlantiValue();
        QString potenzaTotale=mw->get_GestisciComponentiPCBuilder()->potenzaTotaleAltoparlantiValue();
        QString potenze=mw->get_GestisciComponentiPCBuilder()->potenzeAltoparlantiValue();
        double prezzo=mw->get_GestisciComponentiPCBuilder()->prezzoAltoparlantiValue();
        eseguiAggiuntaAltoparlanti(nome,produttore,colore,configurazione,frequenzaDiRisposta,potenzaTotale,potenze,prezzo);
    }
    mw->get_GestisciComponentiPCBuilder()->clearForms();
}

void PCBuilderController::eseguiAggiuntaMemoria(const QString& nome, const QString& produttore, const QString& velocita,
                                                const QString& capacita, const QString& tipologia, double prezzo, int latenza){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Memoria(nome,prezzo,produttore,velocita,capacita,tipologia,latenza);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaSchedaGrafica(const QString& nome, const QString& produttore, const QString& interfaccia,
                                                      const QString& chipset, const QString& memoria, const QString& tipologiaMemoria,
                                                      const QString& frequenzaCore, const QString& tdp, const QString& supportoSLI,
                                                      const QString& supportoCrossfire, const QString& lunghezza, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new SchedaGrafica(nome,prezzo,produttore,interfaccia,chipset,memoria,tipologiaMemoria,frequenzaCore,tdp,
                                   supportoSLI,supportoCrossfire,lunghezza);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaSchedaMadre(const QString& nome, const QString& produttore, const QString& fattoreDiForma,
                                                    const QString& chipset, const QString& socketProcessore, const QString& slotMemoria,
                                                    const QString& tipologiaMemoria, const QString& memoriaMassima, const QString& ethernet,
                                                    bool supportoRAID, bool supportoCrossfire, bool supportoSLI, int sata3GBs, int sata6GBs,
                                                    int sataExpress, int usb2, int usb3, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new SchedaMadre(nome,prezzo,produttore,fattoreDiForma,chipset,socketProcessore,slotMemoria,tipologiaMemoria,
                                 memoriaMassima,supportoRAID,supportoCrossfire,supportoSLI,ethernet,sata3GBs,sata6GBs,
                                 sataExpress,usb2,usb3);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaProcessore(const QString& nome, const QString& produttore, const QString& socket,
                                                   const QString& larghezzaDati, const QString& frequenzaOperativa, const QString& frequenzaTurbo,
                                                   const QString& l1Cache, const QString& l2Cache, const QString& l3Cache, const QString& litografia,
                                                   const QString& tdp, const QString& graficaIntegrata, bool includeDissipatore, bool hyperThreading,
                                                   int numeroCore, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Processore(nome,prezzo,produttore,socket,larghezzaDati,frequenzaOperativa,frequenzaTurbo,numeroCore,
                                l1Cache,l2Cache,l3Cache,litografia,tdp,includeDissipatore,hyperThreading,graficaIntegrata);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaArchiviazione(const QString& nome, const QString& produttore, const QString& tipologia,
                                                      const QString& capacita, const QString& interfaccia, const QString& cache,
                                                      const QString& fattoreDiForma, const QString& rpm, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Archiviazione(nome,prezzo,produttore,tipologia,capacita,interfaccia,cache,fattoreDiForma,rpm);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaAlimentatore(const QString& nome, const QString& produttore, const QString& tipologia,
                                                     const QString& wattaggio, const QString& modulare, const QString& certificazioneEfficienza,
                                                     double efficienza, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Alimentatore(nome,prezzo,produttore,tipologia,wattaggio,modulare,certificazioneEfficienza,efficienza);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaDissipatoreProcessore(const QString& nome, const QString& produttore, const QString& socketSupportati,
                                                              const QString& rpmVentola, const QString& altezza, const QString& altezzaRadiatore,
                                                              const QString& livelloRumore, bool raffreddamentoALiquido, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new DissipatoreProcessore(nome,prezzo,produttore,socketSupportati,raffreddamentoALiquido,rpmVentola,altezza,
                                           livelloRumore,altezzaRadiatore);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaCase(const QString& nome, const QString& produttore, const QString& tipologia,
                                             const QString& colore, const QString& compatibilitaSchedaMadre,
                                             const QString& lunghezzaMassimaSchedaGrafica, const QString& dimensioni,
                                             bool alimentatoreIncluso, int slotInterni25, int slotInterni35, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Case(nome,prezzo,produttore,tipologia,colore,alimentatoreIncluso,slotInterni25,slotInterni35,compatibilitaSchedaMadre,
                          lunghezzaMassimaSchedaGrafica,dimensioni);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaUnitaOttica(const QString& nome, const QString& produttore, const QString& fattoreDiForma,
                                                    const QString& interfaccia, const QString& cache, const QString& velocita, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new UnitaOttica(nome,prezzo,produttore,fattoreDiForma,interfaccia,cache,velocita);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaMonitor(const QString& nome, const QString& produttore, const QString& risoluzioneRaccomandata,
                                                const QString& formato, const QString& angoloDiVisualizzazione, const QString& coloriDelDisplay,
                                                const QString& luminosita, const QString& rapportoDiContrasto, const QString& tempoDiRisposta,
                                                const QString& tipologiaDisplay, const QString& frequenzaDiAggiornamento, bool altoparlantiIncorporati,
                                                bool widescreen, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Monitor(nome,prezzo,produttore,risoluzioneRaccomandata,widescreen,formato,angoloDiVisualizzazione,
                             coloriDelDisplay,luminosita,rapportoDiContrasto,tempoDiRisposta,tipologiaDisplay,altoparlantiIncorporati,
                             frequenzaDiAggiornamento);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaSistemaOperativo(const QString& nome, const QString& produttore, const QString& modalita,
                                                         const QString& memoriaMassimaSupportata, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new SistemaOperativo(nome,prezzo,produttore,modalita,memoriaMassimaSupportata);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaMouse(const QString& nome, const QString& produttore, const QString& connessione, const QString& tipologiaTracciamento,
                                              const QString& colore, const QString& orientamentoDellaMano, int dpiMassimi, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Mouse(nome,prezzo,produttore,connessione,tipologiaTracciamento,dpiMassimi,colore,orientamentoDellaMano);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaTastiera(const QString& nome, const QString& produttore, const QString& colore, const QString& connessione,
                                                 const QString& tipologia, const QString& tipologiaSwitch, bool retroilluminazione, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Tastiera(nome,prezzo,produttore,colore,retroilluminazione,connessione,tipologia,tipologiaSwitch);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaCuffie(const QString& nome, const QString& produttore, const QString& tipologia, const QString& sistemaAcustico,
                                               const QString& colore, const QString& canali, const QString& impedenza, const QString& frequenzaDiRisposta,
                                               const QString& connessione, const QString& connettore, bool microfono, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Cuffie(nome,prezzo,produttore,tipologia,sistemaAcustico,colore,microfono,canali,impedenza,
                            frequenzaDiRisposta,connessione,connettore);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::eseguiAggiuntaAltoparlanti(const QString& nome, const QString& produttore, const QString& colore, const QString& configurazione,
                                                     const QString& frequenzaDiRisposta, const QString& potenzaTotale, const QString& potenze, double prezzo){
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
        {
            comp=new Altoparlanti(nome,prezzo,produttore,colore,configurazione,frequenzaDiRisposta,potenzaTotale,potenze);
            dbcomponents->aggiungi_componente(comp);
            comp->saveXMLComponente();
            QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::callRimuoviComponente(){
    QString componente=mw->get_GestisciComponentiPCBuilder()->rimuoviComponenteValue();
    Componente* c=dbcomponents->find_componente(componente);
    if (!c)
        QMessageBox::warning(mw,"PCBuilder",tr("Il componente inserito non è registrato nel sistema"),QMessageBox::Ok);
    else
    {
        dbcomponents->rimuovi_componente(c);
        mw->get_GestisciComponentiPCBuilder()->getRimuoviComponenteLineEdit()->clear();
        QMessageBox::information(mw,tr("PCBuilder"),tr("La rimozione è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::load_DBComponenti(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QFile file(filename);
        QDomDocument doc("Componenti");
        file.open(QIODevice::ReadOnly);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode componente_node=root.firstChildElement();

        while (!componente_node.isNull())
        {
            Componente* componente;

            if (componente_node.nodeName()=="Alimentatore")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode tipologia_node=produttore_node.nextSiblingElement();
                QString tipologia=tipologia_node.firstChild().nodeValue();
                QDomNode wattaggio_node=tipologia_node.nextSiblingElement();
                QString wattaggio=wattaggio_node.firstChild().nodeValue();
                QDomNode modulare_node=wattaggio_node.nextSiblingElement();
                QString modulare=modulare_node.firstChild().nodeValue();
                QDomNode certificazioneEfficienza_node=modulare_node.nextSiblingElement();
                QString certificazioneEfficienza=certificazioneEfficienza_node.firstChild().nodeValue();
                QDomNode efficienza_node=certificazioneEfficienza_node.nextSiblingElement();
                double efficienza=efficienza_node.firstChild().nodeValue().toDouble();

                componente=new Alimentatore(nome,prezzo,produttore,tipologia,wattaggio,modulare,certificazioneEfficienza,efficienza);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Altoparlanti")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode colore_node=produttore_node.nextSiblingElement();
                QString colore=colore_node.firstChild().nodeValue();
                QDomNode configurazione_node=colore_node.nextSiblingElement();
                QString configurazione=configurazione_node.firstChild().nodeValue();
                QDomNode frequenzaDiRisposta_node=configurazione_node.nextSiblingElement();
                QString frequenzaDiRisposta=frequenzaDiRisposta_node.firstChild().nodeValue();
                QDomNode potenzaTotale_node=frequenzaDiRisposta_node.nextSiblingElement();
                QString potenzaTotale=potenzaTotale_node.firstChild().nodeValue();
                QDomNode potenze_node=potenzaTotale_node.nextSiblingElement();
                QString potenze=potenze_node.firstChild().nodeValue();

                componente=new Altoparlanti(nome,prezzo,produttore,colore,configurazione,frequenzaDiRisposta,potenzaTotale,potenze);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Archiviazione")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode tipologia_node=produttore_node.nextSiblingElement();
                QString tipologia=tipologia_node.firstChild().nodeValue();
                QDomNode capacita_node=tipologia_node.nextSiblingElement();
                QString capacita=capacita_node.firstChild().nodeValue();
                QDomNode interfaccia_node=capacita_node.nextSiblingElement();
                QString interfaccia=interfaccia_node.firstChild().nodeValue();
                QDomNode cache_node=interfaccia_node.nextSiblingElement();
                QString cache=cache_node.firstChild().nodeValue();
                QDomNode fattoreDiForma_node=cache_node.nextSiblingElement();
                QString fattoreDiForma=fattoreDiForma_node.firstChild().nodeValue();
                QDomNode rpm_node=fattoreDiForma_node.nextSiblingElement();
                QString rpm=rpm_node.firstChild().nodeValue();

                componente=new Archiviazione(nome,prezzo,produttore,tipologia,capacita,interfaccia,cache,fattoreDiForma,rpm);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Case")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode tipologia_node=produttore_node.nextSiblingElement();
                QString tipologia=tipologia_node.firstChild().nodeValue();
                QDomNode colore_node=tipologia_node.nextSiblingElement();
                QString colore=colore_node.firstChild().nodeValue();
                QDomNode alimentatoreIncluso_node=colore_node.nextSiblingElement();
                bool alimentatoreIncluso=alimentatoreIncluso_node.firstChild().nodeValue().toInt();
                QDomNode slotInterni25_node=alimentatoreIncluso_node.nextSiblingElement();
                int slotInterni25=slotInterni25_node.firstChild().nodeValue().toInt();
                QDomNode slotInterni35_node=slotInterni25_node.nextSiblingElement();
                int slotInterni35=slotInterni35_node.firstChild().nodeValue().toInt();
                QDomNode compatibilitaSchedaMadre_node=slotInterni35_node.nextSiblingElement();
                QString compatibilitaSchedaMadre=compatibilitaSchedaMadre_node.firstChild().nodeValue();
                QDomNode lunghezzaMassimaSchedaGrafica_node=compatibilitaSchedaMadre_node.nextSiblingElement();
                QString lunghezzaMassimaSchedaGrafica=lunghezzaMassimaSchedaGrafica_node.firstChild().nodeValue();
                QDomNode dimensioni_node=lunghezzaMassimaSchedaGrafica_node.nextSiblingElement();
                QString dimensioni=dimensioni_node.firstChild().nodeValue();

                componente=new Case(nome,prezzo,produttore,tipologia,colore,alimentatoreIncluso,slotInterni25,slotInterni35,
                                    compatibilitaSchedaMadre,lunghezzaMassimaSchedaGrafica,dimensioni);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Cuffie")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode tipologia_node=produttore_node.nextSiblingElement();
                QString tipologia=tipologia_node.firstChild().nodeValue();
                QDomNode sistemaAcustico_node=tipologia_node.nextSiblingElement();
                QString sistemaAcustico=sistemaAcustico_node.firstChild().nodeValue();
                QDomNode colore_node=sistemaAcustico_node.nextSiblingElement();
                QString colore=colore_node.firstChild().nodeValue();
                QDomNode microfono_node=colore_node.nextSiblingElement();
                bool microfono=microfono_node.firstChild().nodeValue().toInt();
                QDomNode canali_node=microfono_node.nextSiblingElement();
                QString canali=canali_node.firstChild().nodeValue();
                QDomNode impedenza_node=canali_node.nextSiblingElement();
                QString impedenza=impedenza_node.firstChild().nodeValue();
                QDomNode frequenzaDiRisposta_node=impedenza_node.nextSiblingElement();
                QString frequenzaDiRisposta=frequenzaDiRisposta_node.firstChild().nodeValue();
                QDomNode connessione_node=frequenzaDiRisposta_node.nextSiblingElement();
                QString connessione=connessione_node.firstChild().nodeValue();
                QDomNode connettore_node=connessione_node.nextSiblingElement();
                QString connettore=connettore_node.firstChild().nodeValue();

                componente=new Cuffie(nome,prezzo,produttore,tipologia,sistemaAcustico,colore,microfono,canali,impedenza,frequenzaDiRisposta,
                                      connessione,connettore);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="DissipatoreProcessore")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode socketSupportati_node=produttore_node.nextSiblingElement();
                QString socketSupportati=socketSupportati_node.firstChild().nodeValue();
                QDomNode raffreddamentoALiquido_node=socketSupportati_node.nextSiblingElement();
                bool raffreddamentoALiquido=raffreddamentoALiquido_node.firstChild().nodeValue().toInt();
                QDomNode rpmVentola_node=raffreddamentoALiquido_node.nextSiblingElement();
                QString rpmVentola=rpmVentola_node.firstChild().nodeValue();
                QDomNode altezza_node=rpmVentola_node.nextSiblingElement();
                QString altezza=altezza_node.firstChild().nodeValue();
                QDomNode livelloRumore_node=altezza_node.nextSiblingElement();
                QString livelloRumore=livelloRumore_node.firstChild().nodeValue();
                QDomNode altezzaRadiatore_node=livelloRumore_node.nextSiblingElement();
                QString altezzaRadiatore=altezzaRadiatore_node.firstChild().nodeValue();

                componente=new DissipatoreProcessore(nome,prezzo,produttore,socketSupportati,raffreddamentoALiquido,rpmVentola,altezza,
                                                     livelloRumore,altezzaRadiatore);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Memoria")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode velocita_node=produttore_node.nextSiblingElement();
                QString velocita=velocita_node.firstChild().nodeValue();
                QDomNode capacita_node=velocita_node.nextSiblingElement();
                QString capacita=capacita_node.firstChild().nodeValue();
                QDomNode tipologia_node=capacita_node.nextSiblingElement();
                QString tipologia=tipologia_node.firstChild().nodeValue();
                QDomNode latenza_node=tipologia_node.nextSiblingElement();
                int latenza=latenza_node.firstChild().nodeValue().toInt();

                componente=new Memoria(nome,prezzo,produttore,velocita,capacita,tipologia,latenza);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Monitor")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode risoluzioneRaccomandata_node=produttore_node.nextSiblingElement();
                QString risoluzioneRaccomandata=risoluzioneRaccomandata_node.firstChild().nodeValue();
                QDomNode widescreen_node=risoluzioneRaccomandata_node.nextSiblingElement();
                bool widescreen=widescreen_node.firstChild().nodeValue().toInt();
                QDomNode formato_node=widescreen_node.nextSiblingElement();
                QString formato=formato_node.firstChild().nodeValue();
                QDomNode angoloDiVisualizzazione_node=formato_node.nextSiblingElement();
                QString angoloDiVisualizzazione=angoloDiVisualizzazione_node.firstChild().nodeValue();
                QDomNode coloriDelDisplay_node=angoloDiVisualizzazione_node.nextSiblingElement();
                QString coloriDelDisplay=coloriDelDisplay_node.firstChild().nodeValue();
                QDomNode luminosita_node=coloriDelDisplay_node.nextSiblingElement();
                QString luminosita=luminosita_node.firstChild().nodeValue();
                QDomNode rapportoDiContrasto_node=luminosita_node.nextSiblingElement();
                QString rapportoDiContrasto=rapportoDiContrasto_node.firstChild().nodeValue();
                QDomNode tempoDiRisposta_node=rapportoDiContrasto_node.nextSiblingElement();
                QString tempoDiRisposta=tempoDiRisposta_node.firstChild().nodeValue();
                QDomNode tipologiaDisplay_node=tempoDiRisposta_node.nextSiblingElement();
                QString tipologiaDisplay=tipologiaDisplay_node.firstChild().nodeValue();
                QDomNode altoparlantiIncorporati_node=tipologiaDisplay_node.nextSiblingElement();
                bool altoparlantiIncorporati=altoparlantiIncorporati_node.firstChild().nodeValue().toInt();
                QDomNode frequenzaDiAggiornamento_node=altoparlantiIncorporati_node.nextSiblingElement();
                QString frequenzaDiAggiornamento=frequenzaDiAggiornamento_node.firstChild().nodeValue();

                componente=new Monitor(nome,prezzo,produttore,risoluzioneRaccomandata,widescreen,formato,angoloDiVisualizzazione,
                                       coloriDelDisplay,luminosita,rapportoDiContrasto,tempoDiRisposta,tipologiaDisplay,altoparlantiIncorporati,
                                       frequenzaDiAggiornamento);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Mouse")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode connessione_node=produttore_node.nextSiblingElement();
                QString connessione=connessione_node.firstChild().nodeValue();
                QDomNode tipologiaTracciamento_node=connessione_node.nextSiblingElement();
                QString tipologiaTracciamento=tipologiaTracciamento_node.firstChild().nodeValue();
                QDomNode DPIMassimi_node=tipologiaTracciamento_node.nextSiblingElement();
                int DPIMassimi=DPIMassimi_node.firstChild().nodeValue().toInt();
                QDomNode colore_node=DPIMassimi_node.nextSiblingElement();
                QString colore=colore_node.firstChild().nodeValue();
                QDomNode orientamentoDellaMano_node=colore_node.nextSiblingElement();
                QString orientamentoDellaMano=orientamentoDellaMano_node.firstChild().nodeValue();

                componente=new Mouse(nome,prezzo,produttore,connessione,tipologiaTracciamento,DPIMassimi,colore,orientamentoDellaMano);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Processore")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode socket_node=produttore_node.nextSiblingElement();
                QString socket=socket_node.firstChild().nodeValue();
                QDomNode larghezzaDati_node=socket_node.nextSiblingElement();
                QString larghezzaDati=larghezzaDati_node.firstChild().nodeValue();
                QDomNode frequenzaOperativa_node=larghezzaDati_node.nextSiblingElement();
                QString frequenzaOperativa=frequenzaOperativa_node.firstChild().nodeValue();
                QDomNode frequenzaTurbo_node=frequenzaOperativa_node.nextSiblingElement();
                QString frequenzaTurbo=frequenzaTurbo_node.firstChild().nodeValue();
                QDomNode numeroCore_node=frequenzaTurbo_node.nextSiblingElement();
                int numeroCore=numeroCore_node.firstChild().nodeValue().toInt();
                QDomNode l1Cache_node=numeroCore_node.nextSiblingElement();
                QString l1Cache=l1Cache_node.firstChild().nodeValue();
                QDomNode l2Cache_node=l1Cache_node.nextSiblingElement();
                QString l2Cache=l2Cache_node.firstChild().nodeValue();
                QDomNode l3Cache_node=l2Cache_node.nextSiblingElement();
                QString l3Cache=l3Cache_node.firstChild().nodeValue();
                QDomNode litografia_node=l3Cache_node.nextSiblingElement();
                QString litografia=litografia_node.firstChild().nodeValue();
                QDomNode tdp_node=litografia_node.nextSiblingElement();
                QString tdp=tdp_node.firstChild().nodeValue();
                QDomNode includeDissipatore_node=tdp_node.nextSiblingElement();
                bool includeDissipatore=includeDissipatore_node.firstChild().nodeValue().toInt();
                QDomNode hyperThreading_node=includeDissipatore_node.nextSiblingElement();
                bool hyperThreading=hyperThreading_node.firstChild().nodeValue().toInt();
                QDomNode graficaIntegrata_node=hyperThreading_node.nextSiblingElement();
                QString graficaIntegrata=graficaIntegrata_node.firstChild().nodeValue();

                componente=new Processore(nome,prezzo,produttore,socket,larghezzaDati,frequenzaOperativa,frequenzaTurbo,numeroCore,
                                          l1Cache,l2Cache,l3Cache,litografia,tdp,includeDissipatore,hyperThreading,graficaIntegrata);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="SchedaGrafica")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode interfaccia_node=produttore_node.nextSiblingElement();
                QString interfaccia=interfaccia_node.firstChild().nodeValue();
                QDomNode chipset_node=interfaccia_node.nextSiblingElement();
                QString chipset=chipset_node.firstChild().nodeValue();
                QDomNode memoria_node=chipset_node.nextSiblingElement();
                QString memoria=memoria_node.firstChild().nodeValue();
                QDomNode tipologiaMemoria_node=memoria_node.nextSiblingElement();
                QString tipologiaMemoria=tipologiaMemoria_node.firstChild().nodeValue();
                QDomNode frequenzaCore_node=tipologiaMemoria_node.nextSiblingElement();
                QString frequenzaCore=frequenzaCore_node.firstChild().nodeValue();
                QDomNode tdp_node=frequenzaCore_node.nextSiblingElement();
                QString tdp=tdp_node.firstChild().nodeValue();
                QDomNode supportoSLI_node=tdp_node.nextSiblingElement();
                QString supportoSLI=supportoSLI_node.firstChild().nodeValue();
                QDomNode supportoCrossfire_node=supportoSLI_node.nextSiblingElement();
                QString supportoCrossfire=supportoCrossfire_node.firstChild().nodeValue();
                QDomNode lunghezza_node=supportoCrossfire_node.nextSiblingElement();
                QString lunghezza=lunghezza_node.firstChild().nodeValue();

                componente=new SchedaGrafica(nome,prezzo,produttore,interfaccia,chipset,memoria,tipologiaMemoria,frequenzaCore,tdp,
                                             supportoSLI,supportoCrossfire,lunghezza);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="SchedaMadre")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode fattoreDiForma_node=produttore_node.nextSiblingElement();
                QString fattoreDiForma=fattoreDiForma_node.firstChild().nodeValue();
                QDomNode chipset_node=fattoreDiForma_node.nextSiblingElement();
                QString chipset=chipset_node.firstChild().nodeValue();
                QDomNode socketProcessore_node=chipset_node.nextSiblingElement();
                QString socketProcessore=socketProcessore_node.firstChild().nodeValue();
                QDomNode slotMemoria_node=socketProcessore_node.nextSiblingElement();
                QString slotMemoria=slotMemoria_node.firstChild().nodeValue();
                QDomNode tipologiaMemoria_node=slotMemoria_node.nextSiblingElement();
                QString tipologiaMemoria=tipologiaMemoria_node.firstChild().nodeValue();
                QDomNode memoriaMassima_node=tipologiaMemoria_node.nextSiblingElement();
                QString memoriaMassima=memoriaMassima_node.firstChild().nodeValue();
                QDomNode supportoRAID_node=memoriaMassima_node.nextSiblingElement();
                bool supportoRAID=supportoRAID_node.firstChild().nodeValue().toInt();
                QDomNode supportoCrossfire_node=supportoRAID_node.nextSiblingElement();
                bool supportoCrossfire=supportoCrossfire_node.firstChild().nodeValue().toInt();
                QDomNode supportoSLI_node=supportoCrossfire_node.nextSiblingElement();
                bool supportoSLI=supportoSLI_node.firstChild().nodeValue().toInt();
                QDomNode ethernet_node=supportoSLI_node.nextSiblingElement();
                QString ethernet=ethernet_node.firstChild().nodeValue();
                QDomNode sata3GBs_node=ethernet_node.nextSiblingElement();
                int sata3GBs=sata3GBs_node.firstChild().nodeValue().toInt();
                QDomNode sata6GBs_node=sata3GBs_node.nextSiblingElement();
                int sata6GBs=sata6GBs_node.firstChild().nodeValue().toInt();
                QDomNode sataExpress_node=sata6GBs_node.nextSiblingElement();
                int sataExpress=sataExpress_node.firstChild().nodeValue().toInt();
                QDomNode usb2_node=sataExpress_node.nextSiblingElement();
                int usb2=usb2_node.firstChild().nodeValue().toInt();
                QDomNode usb3_node=usb2_node.nextSiblingElement();
                int usb3=usb3_node.firstChild().nodeValue().toInt();

                componente=new SchedaMadre(nome,prezzo,produttore,fattoreDiForma,chipset,socketProcessore,slotMemoria,tipologiaMemoria,
                                           memoriaMassima,supportoRAID,supportoCrossfire,supportoSLI,ethernet,sata3GBs,sata6GBs,sataExpress,
                                           usb2,usb3);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="SistemaOperativo")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode modalita_node=produttore_node.nextSiblingElement();
                QString modalita=modalita_node.firstChild().nodeValue();
                QDomNode memoriaMassimaSupportata_node=modalita_node.nextSiblingElement();
                QString memoriaMassimaSupportata=memoriaMassimaSupportata_node.firstChild().nodeValue();

                componente=new SistemaOperativo(nome,prezzo,produttore,modalita,memoriaMassimaSupportata);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="Tastiera")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode colore_node=produttore_node.nextSiblingElement();
                QString colore=colore_node.firstChild().nodeValue();
                QDomNode retroilluminazione_node=colore_node.nextSiblingElement();
                bool retroilluminazione=retroilluminazione_node.firstChild().nodeValue().toInt();
                QDomNode connessione_node=retroilluminazione_node.nextSiblingElement();
                QString connessione=connessione_node.firstChild().nodeValue();
                QDomNode tipologia_node=connessione_node.nextSiblingElement();
                QString tipologia=tipologia_node.firstChild().nodeValue();
                QDomNode tipologiaSwitch_node=tipologia_node.nextSiblingElement();
                QString tipologiaSwitch=tipologiaSwitch_node.firstChild().nodeValue();

                componente=new Tastiera(nome,prezzo,produttore,colore,retroilluminazione,connessione,tipologia,tipologiaSwitch);
                dbcomponents->aggiungi_componente(componente);
            }

            if (componente_node.nodeName()=="UnitaOttica")
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();
                QDomNode fattoreDiForma_node=produttore_node.nextSiblingElement();
                QString fattoreDiForma=fattoreDiForma_node.firstChild().nodeValue();
                QDomNode interfaccia_node=fattoreDiForma_node.nextSiblingElement();
                QString interfaccia=interfaccia_node.firstChild().nodeValue();
                QDomNode cache_node=interfaccia_node.nextSiblingElement();
                QString cache=cache_node.firstChild().nodeValue();
                QDomNode velocita_node=cache_node.nextSiblingElement();
                QString velocita=velocita_node.firstChild().nodeValue();

                componente=new UnitaOttica(nome,prezzo,produttore,fattoreDiForma,interfaccia,cache,velocita);
                dbcomponents->aggiungi_componente(componente);
            }

            componente_node=componente_node.nextSiblingElement();
        }
        file.close();
    }
}

void PCBuilderController::modificaProfiloUtente(){
    QString utente=u->get_Login()->getUsername();
    QString username="";
    QString email=mw->get_ModificaProfiloUtentePCBuilder()->emailValue();
    QString nome=mw->get_ModificaProfiloUtentePCBuilder()->nomeValue();
    QString cognome=mw->get_ModificaProfiloUtentePCBuilder()->cognomeValue();
    QString password=mw->get_ModificaProfiloUtentePCBuilder()->nuovaPasswordValue();
    QString confermaPassword=mw->get_ModificaProfiloUtentePCBuilder()->confermaNuovaPasswordValue();
    QString tipo_account="";
    QString giornonascita=mw->get_ModificaProfiloUtentePCBuilder()->giornoNascitaValue();
    QString mesenascita=mw->get_ModificaProfiloUtentePCBuilder()->meseNascitaValue();
    QString annonascita=mw->get_ModificaProfiloUtentePCBuilder()->annoNascitaValue();

    if (email!="" && !email_validation(email))
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire una email valida"),QMessageBox::Ok);
    else
    {
        if (password!=confermaPassword)
            QMessageBox::warning(mw,"PCBuilder",tr("La conferma della password è errata"),QMessageBox::Ok);
        else
        {
            dbusers->modifica_utente(utente,username,email,nome,cognome,password,tipo_account,giornonascita,
                mesenascita,annonascita);
            QMessageBox::information(mw,tr("PCBuilder"),tr("La modifica è avvenuta con successo"),QMessageBox::Ok);
        }
    }
}

void PCBuilderController::logout(){
    u=new UtenteNonRegistrato(this);
    mw->openIndexUtenteNonRegistratoPCBuilder();
}

void PCBuilderController::deleteAccount(){
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(mw,"PCBuilder",tr("Sei sicuro di voler eliminare l'account?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        dbusers->rimuovi_utente(u);
        mw->openIndexUtenteNonRegistratoPCBuilder();
    }
}

void PCBuilderController::upgradeAccount(){
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(mw,"PCBuilder",tr("Ti verranno addebitati 5 euro, vuoi procedere?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        dbusers->modifica_utente(u->get_Login()->getUsername(),"","","","","","UtentePremium","","","");
        u=dbusers->find_utente(u->get_Login()->getUsername());
        u=new UtentePremium(this,*(u->get_Login()),*(u->get_Profilo()));
        mw->openIndexUtentePremiumPCBuilder();
    }
}

QString PCBuilderController::getUserType() const{
    return u->get_type();
}

void PCBuilderController::close_MainWindow(){
    delete mw;
}

void PCBuilderController::close_LoginPopUpPCBuilder(){
    delete mw->get_LoginPopUpPCBuilder();
}

/*void PCBuilderController::saveConfigurazione(){
    if (u->get_type()=="UtenteNonRegistrato")
    {
        mw->openLoginPopUpPCBuilder();
    }
    else
    {
        QString processoreNome=mw->get_CreaConfPCBuilder()->getProcessoreNomeLabel()->text();
        QString dissipatoreProcessoreNome=mw->get_CreaConfPCBuilder()->getDissipatoreProcessoreNomeLabel()->text();
        QString schedaMadreNome=mw->get_CreaConfPCBuilder()->getSchedaMadreNomeLabel()->text();
        QString memoriaNome=mw->get_CreaConfPCBuilder()->getMemoriaNomeLabel()->text();
        QString archiviazioneNome=mw->get_CreaConfPCBuilder()->getArchiviazioneNomeLabel()->text();
        QString schedaGraficaNome=mw->get_CreaConfPCBuilder()->getSchedaGraficaNomeLabel()->text();
        QString caseNome=mw->get_CreaConfPCBuilder()->getCaseNomeLabel()->text();
        QString alimentatoreNome=mw->get_CreaConfPCBuilder()->getAlimentatoreNomeLabel()->text();
        QString unitaOtticaNome=mw->get_CreaConfPCBuilder()->getUnitaOtticaNomeLabel()->text();
        QString sistemaOperativoNome=mw->get_CreaConfPCBuilder()->getSistemaOperativoNomeLabel()->text();
        QString monitorNome=mw->get_CreaConfPCBuilder()->getMonitorNomeLabel()->text();
        QString mouseNome=mw->get_CreaConfPCBuilder()->getMouseNomeLabel()->text();
        QString tastieraNome=mw->get_CreaConfPCBuilder()->getTastieraNomeLabel()->text();
        QString cuffieNome=mw->get_CreaConfPCBuilder()->getCuffieNomeLabel()->text();
        QString altoparlantiNome=mw->get_CreaConfPCBuilder()->getAltoparlantiNomeLabel()->text();

        Processore* processore=0;
        DissipatoreProcessore* dissipatoreProcessore=0;
        SchedaMadre* schedaMadre=0;
        Memoria* memoria=0;
        Archiviazione* archiviazione=0;
        SchedaGrafica* schedaGrafica=0;
        Case* _case=0;
        Alimentatore* alimentatore=0;
        UnitaOttica* unitaOttica=0;
        SistemaOperativo* sistemaOperativo=0;
        Monitor* monitor=0;
        Mouse* mouse=0;
        Tastiera* tastiera=0;
        Cuffie* cuffie=0;
        Altoparlanti* altoparlanti=0;

        if (processoreNome!="")
        {
            processore=dynamic_cast<Processore*>(dbcomponents->find_componente(processoreNome));
        }
        if (dissipatoreProcessoreNome!="")
        {
            dissipatoreProcessore=dynamic_cast<DissipatoreProcessore*>(dbcomponents->find_componente(dissipatoreProcessoreNome));
        }
        if (schedaMadreNome!="")
        {
            schedaMadre=dynamic_cast<SchedaMadre*>(dbcomponents->find_componente(schedaMadreNome));
        }
        if (memoriaNome!="")
        {
            memoria=dynamic_cast<Memoria*>(dbcomponents->find_componente(memoriaNome));
        }
        if (archiviazioneNome!="")
        {
            archiviazione=dynamic_cast<Archiviazione*>(dbcomponents->find_componente(archiviazioneNome));
        }
        if (schedaGraficaNome!="")
        {
            schedaGrafica=dynamic_cast<SchedaGrafica*>(dbcomponents->find_componente(schedaGraficaNome));
        }
        if (caseNome!="")
        {
            _case=dynamic_cast<Case*>(dbcomponents->find_componente(caseNome));
        }
        if (alimentatoreNome!="")
        {
            alimentatore=dynamic_cast<Alimentatore*>(dbcomponents->find_componente(alimentatoreNome));
        }
        if (unitaOtticaNome!="")
        {
            unitaOttica=dynamic_cast<UnitaOttica*>(dbcomponents->find_componente(unitaOtticaNome));
        }
        if (sistemaOperativoNome!="")
        {
            sistemaOperativo=dynamic_cast<SistemaOperativo*>(dbcomponents->find_componente(sistemaOperativoNome));
        }
        if (monitorNome!="")
        {
            monitor=dynamic_cast<Monitor*>(dbcomponents->find_componente(monitorNome));
        }
        if (mouseNome!="")
        {
            mouse=dynamic_cast<Mouse*>(dbcomponents->find_componente(mouseNome));
        }
        if (tastieraNome!="")
        {
            tastiera=dynamic_cast<Tastiera*>(dbcomponents->find_componente(tastieraNome));
        }
        if (cuffieNome!="")
        {
            cuffie=dynamic_cast<Cuffie*>(dbcomponents->find_componente(cuffieNome));
        }
        if (altoparlantiNome!="")
        {
            altoparlanti=dynamic_cast<Altoparlanti*>(dbcomponents->find_componente(altoparlantiNome));
        }

        QString nomeConfigurazione;
        Configurazione* conf=0;
        bool trovato=false;
        bool ok;
        nomeConfigurazione=QInputDialog::getText(mw->get_CreaConfPCBuilder(),tr("PCBuilder"),tr("Nome configurazione:"),QLineEdit::Normal,"",&ok);
        if (ok)
        {
            if (nomeConfigurazione.isEmpty())
                QMessageBox::warning(mw->get_CreaConfPCBuilder(),"PCBuilder",tr("E' necessario fornire un nome alla configurazione"),QMessageBox::Ok);
            else
            {
                int i=0;
                while (i<(u->getConfigurazioni()->size()))
                {
                    if ((u->getConfigurazioni())->at(i)->getNome()==nomeConfigurazione)
                        trovato=true;
                    i++;
                }
                conf=new Configurazione(nomeConfigurazione,alimentatore,altoparlanti,archiviazione,_case,cuffie,
                        dissipatoreProcessore,memoria,monitor,mouse,processore,schedaGrafica,schedaMadre,
                        sistemaOperativo,tastiera,unitaOttica);
                if (!trovato)
                {
                    u->getConfigurazioni()->append(conf);
                    QMessageBox::information(mw->get_CreaConfPCBuilder(),tr("PCBuilder"),tr("Configurazione salvata correttamente"),QMessageBox::Ok);
                }
                else
                {
                    QMessageBox::StandardButton reply;
                    reply=QMessageBox::question(mw->get_CreaConfPCBuilder(),tr("PCBuilder"),tr("Sei sicuro di voler sovrascrivere la configurazione precedente?"),
                        QMessageBox::Yes|QMessageBox::No);
                    if (reply==QMessageBox::Yes)
                    {
                        u->getConfigurazioni()->replace(i,conf);
                        QMessageBox::information(mw->get_CreaConfPCBuilder(),tr("PCBuilder"),tr("Configurazione salvata correttamente"),QMessageBox::Ok);
                    }
                }
            }
        }
    }
}
*/

/*void PCBuilderController::eseguiAccessoPopUp(){
    QString username=mw->get_LoginPopUpPCBuilder()->usernameValue();
    QString password=mw->get_LoginPopUpPCBuilder()->passwordValue();
    u=dbusers->find_utente(username);
    if (!u)
    {
        QMessageBox::warning(mw->get_LoginPopUpPCBuilder(),"PCBuilder",tr("L'username inserito non è registrato nel nostro sistema"),QMessageBox::Ok);
    }
    else
    {
        if (u->get_Login()->getPassword()!=password)
        {
            QMessageBox::warning(mw->get_LoginPopUpPCBuilder(),"PCBuilder",tr("La password inserita è errata"),QMessageBox::Ok);
        }
        else
        {
            QMessageBox::information(mw->get_LoginPopUpPCBuilder(),tr("PCBuilder"),tr("Accesso eseguito correttamente"),QMessageBox::Ok);
            mw->get_LoginPopUpPCBuilder()->close();
            saveConfigurazione();
        }
    }
}
*/
/*void PCBuilderController::editConfigurazione(const QString& nomeConfigurazione){
    Configurazione* config=0;
    cout<<QString::number(u->getConfigurazioni()->size()).toStdString();
    for (int i=0;i<(u->getConfigurazioni()->size());i++)
    {
        if ((u->getConfigurazioni())[i].at(i)->getNome()==nomeConfigurazione)
            config=(u->getConfigurazioni())[i].at(i);
    }
    mw->openCreaConfPCBuilder();
    if (config->getAlimentatore()!=0)
    {
        mw->get_CreaConfPCBuilder()->setAlimentatorePrezzoLabel("€ "+(QString::number(config->getAlimentatore()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiAlimentatorePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiAlimentatorePushButton());
        mw->get_CreaConfPCBuilder()->getAlimentatoreNomeLabel()->setText(config->getAlimentatore()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getAlimentatoreNomeLabel(),8,1,1,1);
    }
    if (config->getAltoparlanti()!=0)
    {
        mw->get_CreaConfPCBuilder()->setAltoparlantiPrezzoLabel("€ "+(QString::number(config->getAltoparlanti()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiAltoparlantiPushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiAltoparlantiPushButton());
        mw->get_CreaConfPCBuilder()->getAltoparlantiNomeLabel()->setText(config->getAltoparlanti()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getAltoparlantiNomeLabel(),15,1,1,1);
    }
    if (config->getArchiviazione()!=0)
    {
        mw->get_CreaConfPCBuilder()->setArchiviazionePrezzoLabel("€ "+(QString::number(config->getArchiviazione()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiArchiviazionePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiArchiviazionePushButton());
        mw->get_CreaConfPCBuilder()->getArchiviazioneNomeLabel()->setText(config->getArchiviazione()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getArchiviazioneNomeLabel(),5,1,1,1);
    }
    if (config->getCase()!=0)
    {
        mw->get_CreaConfPCBuilder()->setCasePrezzoLabel("€ "+(QString::number(config->getCase()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiCasePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiCasePushButton());
        mw->get_CreaConfPCBuilder()->getCaseNomeLabel()->setText(config->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getCaseNomeLabel(),7,1,1,1);
    }
    if (config->getCuffie()!=0)
    {
        mw->get_CreaConfPCBuilder()->setCuffiePrezzoLabel("€ "+(QString::number(config->getCuffie()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiCuffiePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiCuffiePushButton());
        mw->get_CreaConfPCBuilder()->getCuffieNomeLabel()->setText(config->getCuffie()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getCuffieNomeLabel(),14,1,1,1);
    }
    if (config->getDissipatoreProcessore()!=0)
    {
        mw->get_CreaConfPCBuilder()->setDissipatoreProcessorePrezzoLabel("€ "+(QString::number(config->getDissipatoreProcessore()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiDissipatoreProcessorePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiDissipatoreProcessorePushButton());
        mw->get_CreaConfPCBuilder()->getDissipatoreProcessoreNomeLabel()->setText(config->getDissipatoreProcessore()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getDissipatoreProcessoreNomeLabel(),2,1,1,1);
    }
    if (config->getMemoria()!=0)
    {
        mw->get_CreaConfPCBuilder()->setMemoriaPrezzoLabel("€ "+(QString::number(config->getMemoria()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiMemoriaPushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiMemoriaPushButton());
        mw->get_CreaConfPCBuilder()->getMemoriaNomeLabel()->setText(config->getMemoria()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getMemoriaNomeLabel(),4,1,1,1);
    }
    if (config->getMonitor()!=0)
    {
        mw->get_CreaConfPCBuilder()->setMonitorPrezzoLabel("€ "+(QString::number(config->getMonitor()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiMonitorPushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiMonitorPushButton());
        mw->get_CreaConfPCBuilder()->getMonitorNomeLabel()->setText(config->getMonitor()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getMonitorNomeLabel(),11,1,1,1);
    }
    if (config->getMouse()!=0)
    {
        mw->get_CreaConfPCBuilder()->setMousePrezzoLabel("€ "+(QString::number(config->getMouse()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiMousePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiMousePushButton());
        mw->get_CreaConfPCBuilder()->getMouseNomeLabel()->setText(config->getMouse()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getMouseNomeLabel(),12,1,1,1);
    }
    if (config->getProcessore()!=0)
    {
        mw->get_CreaConfPCBuilder()->setProcessorePrezzoLabel("€ "+(QString::number(config->getProcessore()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiProcessorePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiProcessorePushButton());
        mw->get_CreaConfPCBuilder()->getProcessoreNomeLabel()->setText(config->getProcessore()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getProcessoreNomeLabel(),1,1,1,1);
    }
    if (config->getSchedaGrafica()!=0)
    {
        mw->get_CreaConfPCBuilder()->setSchedaGraficaPrezzoLabel("€ "+(QString::number(config->getSchedaGrafica()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiSchedaGraficaPushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiSchedaGraficaPushButton());
        mw->get_CreaConfPCBuilder()->getSchedaGraficaNomeLabel()->setText(config->getSchedaGrafica()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getSchedaGraficaNomeLabel(),6,1,1,1);
    }
    if (config->getSchedaMadre()!=0)
    {
        mw->get_CreaConfPCBuilder()->setSchedaMadrePrezzoLabel("€ "+(QString::number(config->getSchedaMadre()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiSchedaMadrePushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiSchedaMadrePushButton());
        mw->get_CreaConfPCBuilder()->getSchedaMadreNomeLabel()->setText(config->getSchedaMadre()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getSchedaMadreNomeLabel(),3,1,1,1);
    }
    if (config->getSistemaOperativo()!=0)
    {
        mw->get_CreaConfPCBuilder()->setSistemaOperativoPrezzoLabel("€ "+(QString::number(config->getSistemaOperativo()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiSistemaOperativoPushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiSistemaOperativoPushButton());
        mw->get_CreaConfPCBuilder()->getSistemaOperativoNomeLabel()->setText(config->getSistemaOperativo()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getSistemaOperativoNomeLabel(),10,1,1,1);
    }
    if (config->getTastiera()!=0)
    {
        mw->get_CreaConfPCBuilder()->setTastieraPrezzoLabel("€ "+(QString::number(config->getTastiera()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiTastieraPushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiTastieraPushButton());
        mw->get_CreaConfPCBuilder()->getTastieraNomeLabel()->setText(config->getTastiera()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getTastieraNomeLabel(),13,1,1,1);
    }
    if (config->getUnitaOttica()!=0)
    {
        mw->get_CreaConfPCBuilder()->setUnitaOtticaPrezzoLabel("€ "+(QString::number(config->getUnitaOttica()->getPrezzo())));
        mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiUnitaOtticaPushButton());
        delete (mw->get_CreaConfPCBuilder()->getAggiungiUnitaOtticaPushButton());
        mw->get_CreaConfPCBuilder()->getUnitaOtticaNomeLabel()->setText(config->getUnitaOttica()->getNome());
        mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getUnitaOtticaNomeLabel(),9,1,1,1);
    }
    mw->get_CreaConfPCBuilder()->updateTotalePrezzo();
}
*/

DBComponenti* PCBuilderController::getDBComponents() const{
    return dbcomponents;
}

QMap<QString,QString> PCBuilderController::getComponentSpecs(const QString& nomeComponente) const{
    QMap<QString,QString> specs;
    Componente* c=dbcomponents->find_componente(nomeComponente);
    specs.insert("Nome",c->getNome());
    specs.insert("Produttore",c->getProduttore());
    specs.insert("Prezzo","€ "+(QString::number(c->getPrezzo())));
    if (c->getType()=="Alimentatore")
    {
        Alimentatore* alimentatore=dynamic_cast<Alimentatore*>(c);
        specs.insert("Tipologia",alimentatore->getTipologia());
        specs.insert("Wattaggio",alimentatore->getWattaggio());
        specs.insert("Modulare",alimentatore->getModulare());
        specs.insert("Certificazione di efficienza",alimentatore->getCertificazioneEfficienza());
        specs.insert("Efficienza",QString::number(alimentatore->getEfficienza()));

    }
    if (c->getType()=="Altoparlante")
    {
        Altoparlanti* altoparlanti=dynamic_cast<Altoparlanti*>(c);
        specs.insert("Colore",altoparlanti->getColore());
        specs.insert("Configurazione",altoparlanti->getConfigurazione());
        specs.insert("Frequenza di risposta",altoparlanti->getFrequenzaDiRisposta());
        specs.insert("Potenza totale",altoparlanti->getPotenzaTotale());
        specs.insert("Potenze",altoparlanti->getPotenze());
    }
    if (c->getType()=="Archiviazione")
    {
        Archiviazione* archiviazione=dynamic_cast<Archiviazione*>(c);
        specs.insert("Tipologia",archiviazione->getTipologia());
        specs.insert("Capacità",archiviazione->getCapacita());
        specs.insert("Interfaccia",archiviazione->getInterfaccia());
        specs.insert("Cache",archiviazione->getCache());
        specs.insert("Fattore di forma",archiviazione->getFattoreDiForma());
        specs.insert("RPM",archiviazione->getRpm());
    }
    if (c->getType()=="Case")
    {
        Case* _case=dynamic_cast<Case*>(c);
        specs.insert("Tipologia",_case->getTipologia());
        specs.insert("Colore",_case->getColore());
        specs.insert("Alimentatore incluso",_case->getAlimentatoreIncluso()? "SI":"NO");
        specs.insert("Compatibilità scheda madre",_case->getCompatibilitaSchedaMadre());
        specs.insert("Lunghezza massima scheda grafica",_case->getLunghezzaMassimaSchedaGrafica());
        specs.insert("Slot interni 2.5''",QString::number(_case->getSlotInterni25()));
        specs.insert("Slot interni 3.5''",QString::number(_case->getSlotInterni35()));
        specs.insert("Dimensioni",_case->getDimensioni());
    }
    if (c->getType()=="Cuffie")
    {
        Cuffie* cuffie=dynamic_cast<Cuffie*>(c);
        specs.insert("Tipologia",cuffie->getTipologia());
        specs.insert("Sistema acustico",cuffie->getSistemaAcustico());
        specs.insert("Colore",cuffie->getColore());
        specs.insert("Microfono",cuffie->getMicrofono()? "SI":"NO");
        specs.insert("Canali",cuffie->getCanali());
        specs.insert("Impedenza",cuffie->getImpedenza());
        specs.insert("Frequenza di risposta",cuffie->getFrequenzaDiRisposta());
        specs.insert("Connessione",cuffie->getConnessione());
        specs.insert("Connettore",cuffie->getConnettore());
    }
    if (c->getType()=="DissipatoreProcessore")
    {
        DissipatoreProcessore* dissipatoreProcessore=dynamic_cast<DissipatoreProcessore*>(c);
        specs.insert("Socket supportati",dissipatoreProcessore->getSocketSupportati());
        specs.insert("Raffreddamento a liquido",dissipatoreProcessore->getRaffreddamentoALiquido()? "SI":"NO");
        specs.insert("RPM ventola",dissipatoreProcessore->getRpmVentola());
        specs.insert("Altezza",dissipatoreProcessore->getAltezza());
        specs.insert("Altezza radiatore",dissipatoreProcessore->getAltezzaRadiatore());
        specs.insert("Livello rumore",dissipatoreProcessore->getLivelloRumore());
    }
    if (c->getType()=="Memoria")
    {
        Memoria* memoria=dynamic_cast<Memoria*>(c);
        specs.insert("Tipologia",memoria->getTipologia());
        specs.insert("Capacità",memoria->getCapacita());
        specs.insert("Velocità",memoria->getVelocita());
        specs.insert("Latenza",QString::number(memoria->getLatenza()));
    }
    if (c->getType()=="Monitor")
    {
        Monitor* monitor=dynamic_cast<Monitor*>(c);
        specs.insert("Risoluzione raccomandata",monitor->getRisoluzioneRaccomandata());
        specs.insert("Widescreen",monitor->getWidescreen()? "SI":"NO");
        specs.insert("Formato",monitor->getFormato());
        specs.insert("Angolo di visualizzazione",monitor->getAngoloDiVisualizzazione());
        specs.insert("Colori del display",monitor->getColoriDelDisplay());
        specs.insert("Luminosità",monitor->getLuminosita());
        specs.insert("Rapporto di contrasto",monitor->getRapportoDiContrasto());
        specs.insert("Tempo di risposta",monitor->getTempoDiRisposta());
        specs.insert("Tipologia del display",monitor->getTipologiaDisplay());
        specs.insert("Altoparlanti incorporati",monitor->getAltoparlantiIncorporati()? "SI":"NO");
        specs.insert("Frequenza di aggiornamento",monitor->getFrequenzaDiAggiornamento());
    }
    if (c->getType()=="Mouse")
    {
        Mouse* mouse=dynamic_cast<Mouse*>(c);
        specs.insert("Connessione",mouse->getConnessione());
        specs.insert("Tipologia tracciamento",mouse->getTipologiaTracciamento());
        specs.insert("DPI massimi",QString::number(mouse->getDPIMassimi()));
        specs.insert("Colore",mouse->getColore());
        specs.insert("Orientamento della mano",mouse->getOrientamentoDellaMano());
    }
    if (c->getType()=="Processore")
    {
        Processore* processore=dynamic_cast<Processore*>(c);
        specs.insert("Socket",processore->getSocket());
        specs.insert("Larghezza dati",processore->getLarghezzaDati());
        specs.insert("Frequenza operativa",processore->getFrequenzaOperativa());
        specs.insert("Frequenza turbo",processore->getFrequenzaTurbo());
        specs.insert("Numero core",QString::number(processore->getNumeroCore()));
        specs.insert("L1 cache",processore->getL1Cache());
        specs.insert("L2 cache",processore->getL2Cache());
        specs.insert("L3 cache",processore->getL3Cache());
        specs.insert("Litografia",processore->getLitografia());
        specs.insert("TDP",processore->getTdp());
        specs.insert("Include dissipatore",processore->getIncludeDissipatore()? "SI":"NO");
        specs.insert("Hyper-Threading",processore->getHyperThreading()? "SI":"NO");
        specs.insert("Grafica integrata",processore->getGraficaIntegrata());
    }
    if (c->getType()=="SchedaGrafica")
    {
        SchedaGrafica* schedaGrafica=dynamic_cast<SchedaGrafica*>(c);
        specs.insert("Interfaccia",schedaGrafica->getInterfaccia());
        specs.insert("Chipset",schedaGrafica->getChipset());
        specs.insert("Memoria",schedaGrafica->getMemoria());
        specs.insert("Tipologia memoria",schedaGrafica->getTipologiaMemoria());
        specs.insert("Frequenza core",schedaGrafica->getFrequenzaCore());
        specs.insert("TDP",schedaGrafica->getTdp());
        specs.insert("Supporto SLI",schedaGrafica->getSupportoSLI());
        specs.insert("Supporto Crossfire",schedaGrafica->getSupportoCrossfire());
        specs.insert("Lunghezza",schedaGrafica->getLunghezza());
    }
    if (c->getType()=="SchedaMadre")
    {
        SchedaMadre* schedaMadre=dynamic_cast<SchedaMadre*>(c);
        specs.insert("Fattore di forma",schedaMadre->getFattoreDiForma());
        specs.insert("Chipset",schedaMadre->getChipset());
        specs.insert("Socket processore",schedaMadre->getSocketProcessore());
        specs.insert("Slot memoria",schedaMadre->getSlotMemoria());
        specs.insert("Tipologia memoria",schedaMadre->getSlotMemoria());
        specs.insert("Memoria massima",schedaMadre->getMemoriaMassima());
        specs.insert("Supporto RAID",schedaMadre->getSupportoRAID()? "SI":"NO");
        specs.insert("Supporto Crossfire",schedaMadre->getSupportoCrossfire()? "SI":"NO");
        specs.insert("Supporto SLI",schedaMadre->getSupportoSLI()? "SI":"NO");
        specs.insert("Ethernet",schedaMadre->getEthernet());
        specs.insert("SATA 3GB/s",QString::number(schedaMadre->getSata3GBs()));
        specs.insert("SATA 6GB/s",QString::number(schedaMadre->getSata6GBs()));
        specs.insert("SATA Express",QString::number(schedaMadre->getSataExpress()));
        specs.insert("UBS 2.0",QString::number(schedaMadre->getUsb2()));
        specs.insert("USB 3.0",QString::number(schedaMadre->getUsb3()));
    }
    if (c->getType()=="SistemaOperativo")
    {
        SistemaOperativo* sistemaOperativo=dynamic_cast<SistemaOperativo*>(c);
        specs.insert("Modalità",sistemaOperativo->getModalita());
        specs.insert("Memoria massima supportata",sistemaOperativo->getMemoriaMassimaSupportata());
    }
    if (c->getType()=="Tastiera")
    {
        Tastiera* tastiera=dynamic_cast<Tastiera*>(c);
        specs.insert("Colore",tastiera->getColore());
        specs.insert("Retroilluminazione",tastiera->getRetroilluminazione()? "SI":"NO");
        specs.insert("Connessione",tastiera->getConnessione());
        specs.insert("Tipologia",tastiera->getTipologia());
        specs.insert("Tipologia switch",tastiera->getTipologiaSwitch());
    }
    if (c->getType()=="UnitaOttica")
    {
        UnitaOttica* unitaOttica=dynamic_cast<UnitaOttica*>(c);
        specs.insert("Fattore di forma",unitaOttica->getFattoreDiForma());
        specs.insert("Interfaccia",unitaOttica->getInterfaccia());
        specs.insert("Cache",unitaOttica->getCache());
        specs.insert("Velocità",unitaOttica->getVelocita());
    }
    return specs;
}
