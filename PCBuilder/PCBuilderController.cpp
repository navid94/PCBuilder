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
#include "DBComponenti.h"
#include "Componente.h"
#include "Container.h"
#include "Configurazione.h"

#include <QMessageBox>
#include <QRegExp>
#include <QFile>
#include <QDomDocument>
#include <QTextStream>
#include <typeinfo>
#include <QInputDialog>
#include <QLayoutItem>

#include <iostream>
using namespace std;



PCBuilderController::PCBuilderController(){
    dbusers=new DBUtenti(this);
    mw=new MainWindow(this);
    connect(mw,SIGNAL(closeMainWindow()),this,SLOT(close_MainWindow()));
    dbcomponents=new DBComponenti;
    load_DBComponenti();
    load_DBUtenti();
    u=new UtenteNonRegistrato(this);
    conf=0;
    comp=0;
    confTemp=0;
}

PCBuilderController::~PCBuilderController(){
    delete mw;
    mw=0;
    delete u;
    u=0;
    delete dbUser;
    dbUser=0;
    delete dbusers;
    dbusers=0;
    delete dbcomponents;
    dbcomponents=0;
    delete comp;
    comp=0;
    delete conf;
    conf=0;
    delete confTemp;
    confTemp=0;
    delete dbComp;
    dbComp=0;
}

Utente* PCBuilderController::getUser() const{
    return u;
}

DBUtenti* PCBuilderController::getDBUtenti() const{
    return dbusers;
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
                dbUser=new UtenteRegistrato(this,id,pf);
            else
            {
                if (tipo_account=="UtentePremium")
                {
                    dbUser=new UtentePremium(this,id,pf);
                }
            }
            dbusers->aggiungi_utente(dbUser);
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

                                            dbUser=new UtenteRegistrato(this,id,pf);
                                            dbusers->aggiungi_utente(dbUser);
                                            QMessageBox::information(mw,tr("PCBuilder"),tr("La registrazione è avvenuta con successo, ora è possibile eseguire l'accesso"),QMessageBox::Ok);
                                            saveXMLUtenti(dbUser);
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
    if (u)
        delete u;
    u=dbusers->find_utente(username);
    if (!u)
    {
        QMessageBox::warning(mw,"PCBuilder",tr("L'username inserito non è registrato nel nostro sistema"),QMessageBox::Ok);
        u=new UtenteNonRegistrato(this);
    }
    else
    {
        if (u->get_Login()->getPassword()!=password)
        {
            QMessageBox::warning(mw,"PCBuilder",tr("La password inserita è errata"),QMessageBox::Ok);
            u=new UtenteNonRegistrato(this);
        }
        else
        {
            QMessageBox::information(mw,tr("PCBuilder"),tr("Accesso eseguito correttamente"),QMessageBox::Ok);
            u=(dbusers->find_utente(username))->clone();
            u->showIndex();
        }
    }
}


void PCBuilderController::callShowIndex(){
    if (confTemp)
    {
        delete confTemp;
        confTemp=0;
    }
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
    if (u)
    {
        delete u;
        u=0;
    }
    u=dbusers->find_utente(utente);
    if (!u)
        QMessageBox::warning(mw,"PCBuilder",tr("L'username inserito non è registrato nel sistema"),QMessageBox::Ok);
    else
    {
        dbusers->rimuovi_utente(u);
        mw->get_GestisciUtentiPCBuilder()->get_username_utenterimuovereLineEdit()->clear();
        QMessageBox::information(mw,tr("PCBuilder"),tr("La rimozione è avvenuta con successo"),QMessageBox::Ok);
    }

    u=new UtenteNonRegistrato(this);
}

bool PCBuilderController::validateComponenteAdd(const QString& nome) const{
    if (nome=="")
        QMessageBox::warning(mw,"PCBuilder",tr("E' necessario inserire un nome"),QMessageBox::Ok);
    else
    {
        if (dbcomponents->find_componente(nome))
            QMessageBox::warning(mw,"PCBuilder",tr("Il nome inserito è già occupato"),QMessageBox::Ok);
        else
            return true;
    }
    return false;
}

void PCBuilderController::aggiungi_componente(){
    QString componente=mw->get_GestisciComponentiPCBuilder()->tipo_componenteAggiungiValue();
    Componente* componentInstance=0;
    if (componente=="Memoria")
    {
        componentInstance=new Memoria(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Scheda grafica")
    {
        componentInstance=new SchedaGrafica(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Scheda madre")
    {
        componentInstance=new SchedaMadre(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Processore")
    {
        componentInstance=new Processore(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Archiviazione")
    {
        componentInstance=new Archiviazione(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Alimentatore")
    {
        componentInstance=new Alimentatore(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Dissipatore processore")
    {
        componentInstance=new DissipatoreProcessore(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Case")
    {
        componentInstance=new Case(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Unità ottica")
    {
        componentInstance=new UnitaOttica(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Monitor")
    {
        componentInstance=new Monitor(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Sistema operativo")
    {
        componentInstance=new SistemaOperativo(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Mouse")
    {
        componentInstance=new Mouse(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Tastiera")
    {
        componentInstance=new Tastiera(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Cuffie")
    {
        componentInstance=new Cuffie(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componente=="Altoparlanti")
    {
        componentInstance=new Altoparlanti(this);
        componentInstance->addComponente();
        componentInstance->clearAddWidget();
    }
    if (componentInstance)
        delete componentInstance;
}


void PCBuilderController::eseguiAggiuntaMemoria(){
    QString nome=memoriaAddWidget->nomeMemoriaValue();
    QString produttore=memoriaAddWidget->produttoreMemoriaValue();
    QString velocita=memoriaAddWidget->velocitaMemoriaValue();
    QString capacita=memoriaAddWidget->capacitaMemoriaValue();
    QString tipologia=memoriaAddWidget->tipologiaMemoriaValue();
    double prezzo=memoriaAddWidget->prezzoMemoriaValue();
    int latenza=memoriaAddWidget->latenzaMemoriaValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Memoria(nome,prezzo,produttore,this,velocita,capacita,tipologia,latenza);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaSchedaGrafica(){
    QString nome=schedaGraficaAddWidget->nomeSchedaGraficaValue();
    QString produttore=schedaGraficaAddWidget->produttoreSchedaGraficaValue();
    QString interfaccia=schedaGraficaAddWidget->interfacciaSchedaGraficaValue();
    QString chipset=schedaGraficaAddWidget->chipsetSchedaGraficaValue();
    QString memoria=schedaGraficaAddWidget->memoriaSchedaGraficaValue();
    QString tipologiaMemoria=schedaGraficaAddWidget->tipologiaMemoriaSchedaGraficaValue();
    QString frequenzaCore=schedaGraficaAddWidget->frequenzaCoreSchedaGraficaValue();
    QString tdp=schedaGraficaAddWidget->tdpSchedaGraficaValue();
    QString supportoSLI=schedaGraficaAddWidget->supportoSLISchedaGraficaValue();
    QString supportoCrossfire=schedaGraficaAddWidget->supportoCrossfireSchedaGraficaValue();
    QString lunghezza=schedaGraficaAddWidget->lunghezzaSchedaGraficaValue();
    double prezzo=schedaGraficaAddWidget->prezzoSchedaGraficaValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new SchedaGrafica(nome,prezzo,produttore,this,interfaccia,chipset,memoria,tipologiaMemoria,frequenzaCore,tdp,
                               supportoSLI,supportoCrossfire,lunghezza);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaSchedaMadre(){
    QString nome=schedaMadreAddWidget->nomeSchedaMadreValue();
    QString produttore=schedaMadreAddWidget->produttoreSchedaMadreValue();
    QString fattoreDiForma=schedaMadreAddWidget->fattoreDiFormaSchedaMadreValue();
    QString chipset=schedaMadreAddWidget->chipsetSchedaMadreValue();
    QString socketProcessore=schedaMadreAddWidget->socketProcessoreSchedaMadreValue();
    QString slotMemoria=schedaMadreAddWidget->slotMemoriaSchedaMadreValue();
    QString tipologiaMemoria=schedaMadreAddWidget->tipologiaMemoriaSchedaMadreValue();
    QString memoriaMassima=schedaMadreAddWidget->memoriaMassimaSchedaMadreValue();
    QString ethernet=schedaMadreAddWidget->ethernetSchedaMadreValue();
    bool supportoRAID=schedaMadreAddWidget->supportoRAIDSchedaMadreValue();
    bool supportoCrossfire=schedaMadreAddWidget->supportoCrossfireSchedaMadreValue();
    bool supportoSLI=schedaMadreAddWidget->supportoSLISchedaMadreValue();
    int sata3GBs=schedaMadreAddWidget->sata3GBsSchedaMadreValue();
    int sata6GBs=schedaMadreAddWidget->sata6GBsSchedaMadreValue();
    int sataExpress=schedaMadreAddWidget->sataExpressSchedaMadreValue();
    int usb2=schedaMadreAddWidget->usb2SchedaMadreValue();
    int usb3=schedaMadreAddWidget->usb3SchedaMadreValue();
    double prezzo=schedaMadreAddWidget->prezzoSchedaMadreValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new SchedaMadre(nome,prezzo,produttore,this,fattoreDiForma,chipset,socketProcessore,slotMemoria,tipologiaMemoria,
                    memoriaMassima,supportoRAID,supportoCrossfire,supportoSLI,ethernet,sata3GBs,sata6GBs,
                    sataExpress,usb2,usb3);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaProcessore(){
    QString nome=processoreAddWidget->nomeProcessoreValue();
    QString produttore=processoreAddWidget->produttoreProcessoreValue();
    QString socket=processoreAddWidget->socketProcessoreValue();
    QString larghezzaDati=processoreAddWidget->larghezzaDatiProcessoreValue();
    QString frequenzaOperativa=processoreAddWidget->frequenzaOperativaProcessoreValue();
    QString frequenzaTurbo=processoreAddWidget->frequenzaTurboProcessoreValue();
    QString l1Cache=processoreAddWidget->l1CacheProcessoreValue();
    QString l2Cache=processoreAddWidget->l2CacheProcessoreValue();
    QString l3Cache=processoreAddWidget->l3CacheProcessoreValue();
    QString litografia=processoreAddWidget->litografiaProcessoreValue();
    QString tdp=processoreAddWidget->tdpProcessoreValue();
    QString graficaIntegrata=processoreAddWidget->graficaIntegrataProcessoreValue();
    bool includeDissipatore=processoreAddWidget->includeDissipatoreProcessoreValue();
    bool hyperThreading=processoreAddWidget->hyperThreadingProcessoreValue();
    int numeroCore=processoreAddWidget->numeroCoreProcessoreValue();
    double prezzo=processoreAddWidget->prezzoProcessoreValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Processore(nome,prezzo,produttore,this,socket,larghezzaDati,frequenzaOperativa,frequenzaTurbo,numeroCore,
                l1Cache,l2Cache,l3Cache,litografia,tdp,includeDissipatore,hyperThreading,graficaIntegrata);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaArchiviazione(){
    QString nome=archiviazioneAddWidget->nomeArchiviazioneValue();
    QString produttore=archiviazioneAddWidget->produttoreArchiviazioneValue();
    QString tipologia=archiviazioneAddWidget->tipologiaArchiviazioneValue();
    QString capacita=archiviazioneAddWidget->capacitaArchiviazioneValue();
    QString interfaccia=archiviazioneAddWidget->interfacciaArchiviazioneValue();
    QString cache=archiviazioneAddWidget->cacheArchiviazioneValue();
    QString fattoreDiForma=archiviazioneAddWidget->fattoreDiFormaArchiviazioneValue();
    QString rpm=archiviazioneAddWidget->rpmArchiviazioneValue();
    double prezzo=archiviazioneAddWidget->prezzoArchiviazioneValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Archiviazione(nome,prezzo,produttore,this,tipologia,capacita,interfaccia,cache,fattoreDiForma,rpm);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaAlimentatore(){
    QString nome=alimentatoreAddWidget->nomeAlimentatoreValue();
    QString produttore=alimentatoreAddWidget->produttoreAlimentatoreValue();
    QString tipologia=alimentatoreAddWidget->tipologiaAlimentatoreValue();
    QString wattaggio=alimentatoreAddWidget->wattaggioAlimentatoreValue();
    QString modulare=alimentatoreAddWidget->modulareAlimentatoreValue();
    QString certificazioneEfficienza=alimentatoreAddWidget->certificazioneEfficienzaAlimentatoreValue();
    double efficienza=alimentatoreAddWidget->efficienzaAlimentatoreValue();
    double prezzo=alimentatoreAddWidget->prezzoAlimentatoreValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Alimentatore(nome,prezzo,produttore,this,tipologia,wattaggio,modulare,certificazioneEfficienza,efficienza);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaDissipatoreProcessore(){
    QString nome=dissipatoreProcessoreAddWidget->nomeDissipatoreProcessoreValue();
    QString produttore=dissipatoreProcessoreAddWidget->produttoreDissipatoreProcessoreValue();
    QString socketSupportati=dissipatoreProcessoreAddWidget->socketSupportatiDissipatoreProcessoreValue();
    QString rpmVentola=dissipatoreProcessoreAddWidget->rpmVentolaDissipatoreProcessoreValue();
    QString altezza=dissipatoreProcessoreAddWidget->altezzaDissipatoreProcessoreValue();
    QString altezzaRadiatore=dissipatoreProcessoreAddWidget->altezzaRadiatoreDissipatoreProcessoreValue();
    QString livelloRumore=dissipatoreProcessoreAddWidget->livelloRumoreDissipatoreProcessoreValue();
    bool raffreddamentoALiquido=dissipatoreProcessoreAddWidget->raffreddamentoALiquidoDissipatoreProcessoreValue();
    double prezzo=dissipatoreProcessoreAddWidget->prezzoDissipatoreProcessoreValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new DissipatoreProcessore(nome,prezzo,produttore,this,socketSupportati,raffreddamentoALiquido,rpmVentola,altezza,
                livelloRumore,altezzaRadiatore);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaCase(){
    QString nome=caseAddWidget->nomeCaseValue();
    QString produttore=caseAddWidget->produttoreCaseValue();
    QString tipologia=caseAddWidget->tipologiaCaseValue();
    QString colore=caseAddWidget->coloreCaseValue();
    QString compatibilitaSchedaMadre=caseAddWidget->compatibilitaSchedaMadreCaseValue();
    QString lunghezzaMassimaSchedaGrafica=caseAddWidget->lunghezzaMassimaSchedaGraficaCaseValue();
    QString dimensioni=caseAddWidget->dimensioniCaseValue();
    bool alimentatoreIncluso=caseAddWidget->alimentatoreInclusoCaseValue();
    int slotInterni25=caseAddWidget->slotInterni25CaseValue();
    int slotInterni35=caseAddWidget->slotInterni35CaseValue();
    double prezzo=caseAddWidget->prezzoCaseValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Case(nome,prezzo,produttore,this,tipologia,colore,alimentatoreIncluso,slotInterni25,slotInterni35,compatibilitaSchedaMadre,
                lunghezzaMassimaSchedaGrafica,dimensioni);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaUnitaOttica(){
    QString nome=unitaOtticaAddWidget->nomeUnitaOtticaValue();
    QString produttore=unitaOtticaAddWidget->produttoreUnitaOtticaValue();
    QString fattoreDiForma=unitaOtticaAddWidget->fattoreDiFormaUnitaOtticaValue();
    QString interfaccia=unitaOtticaAddWidget->interfacciaUnitaOtticaValue();
    QString cache=unitaOtticaAddWidget->cacheUnitaOtticaValue();
    QString velocita=unitaOtticaAddWidget->velocitaUnitaOtticaValue();
    double prezzo=unitaOtticaAddWidget->prezzoUnitaOtticaValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new UnitaOttica(nome,prezzo,produttore,this,fattoreDiForma,interfaccia,cache,velocita);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaMonitor(){
    QString nome=monitorAddWidget->nomeMonitorValue();
    QString produttore=monitorAddWidget->produttoreMonitorValue();
    QString risoluzioneRaccomandata=monitorAddWidget->risoluzioneRaccomandataMonitorValue();
    QString formato=monitorAddWidget->formatoMonitorValue();
    QString angoloDiVisualizzazione=monitorAddWidget->angoloDiVisualizzazioneMonitorValue();
    QString coloriDelDisplay=monitorAddWidget->coloriDelDisplayMonitorValue();
    QString luminosita=monitorAddWidget->luminositaMonitorValue();
    QString rapportoDiContrasto=monitorAddWidget->rapportoDiContrastoMonitorValue();
    QString tempoDiRisposta=monitorAddWidget->tempoDiRispostaMonitorValue();
    QString tipologiaDisplay=monitorAddWidget->tipologiaDisplayMonitorValue();
    QString frequenzaDiAggiornamento=monitorAddWidget->frequenzaDiAggiornamentoMonitorValue();
    bool altoparlantiIncorporati=monitorAddWidget->altoparlantiIncorporatiMonitorValue();
    bool widescreen=monitorAddWidget->widescreenMonitorValue();
    double prezzo=monitorAddWidget->prezzoMonitorValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Monitor(nome,prezzo,produttore,this,risoluzioneRaccomandata,widescreen,formato,angoloDiVisualizzazione,
                coloriDelDisplay,luminosita,rapportoDiContrasto,tempoDiRisposta,tipologiaDisplay,altoparlantiIncorporati,
                frequenzaDiAggiornamento);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaSistemaOperativo(){
    QString nome=sistemaOperativoAddWidget->nomeSistemaOperativoValue();
    QString produttore=sistemaOperativoAddWidget->produttoreSistemaOperativoValue();
    QString modalita=sistemaOperativoAddWidget->modalitaSistemaOperativoValue();
    QString memoriaMassimaSupportata=sistemaOperativoAddWidget->memoriaMassimaSupportataSistemaOperativoValue();
    double prezzo=sistemaOperativoAddWidget->prezzoSistemaOperativoValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new SistemaOperativo(nome,prezzo,produttore,this,modalita,memoriaMassimaSupportata);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaMouse(){
    QString nome=mouseAddWidget->nomeMouseValue();
    QString produttore=mouseAddWidget->produttoreMouseValue();
    QString connessione=mouseAddWidget->connessioneMouseValue();
    QString tipologiaTracciamento=mouseAddWidget->tipologiaTracciamentoMouseValue();
    QString colore=mouseAddWidget->coloreMouseValue();
    QString orientamentoDellaMano=mouseAddWidget->orientamentoDellaManoMouseValue();
    int dpiMassimi=mouseAddWidget->dpiMassimiMouseValue();
    double prezzo=mouseAddWidget->prezzoMouseValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Mouse(nome,prezzo,produttore,this,connessione,tipologiaTracciamento,dpiMassimi,colore,orientamentoDellaMano);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaTastiera(){
    QString nome=tastieraAddWidget->nomeTastieraValue();
    QString produttore=tastieraAddWidget->produttoreTastieraValue();
    QString colore=tastieraAddWidget->coloreTastieraValue();
    QString connessione=tastieraAddWidget->connessioneTastieraValue();
    QString tipologia=tastieraAddWidget->tipologiaTastieraValue();
    QString tipologiaSwitch=tastieraAddWidget->tipologiaSwitchTastieraValue();
    bool retroilluminazione=tastieraAddWidget->retroilluminazioneTastieraValue();
    double prezzo=tastieraAddWidget->prezzoTastieraValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Tastiera(nome,prezzo,produttore,this,colore,retroilluminazione,connessione,tipologia,tipologiaSwitch);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaCuffie(){
    QString nome=cuffieAddWidget->nomeCuffieValue();
    QString produttore=cuffieAddWidget->produttoreCuffieValue();
    QString tipologia=cuffieAddWidget->tipologiaCuffieValue();
    QString sistemaAcustico=cuffieAddWidget->sistemaAcusticoCuffieValue();
    QString colore=cuffieAddWidget->coloreCuffieValue();
    QString canali=cuffieAddWidget->canaliCuffieValue();
    QString impedenza=cuffieAddWidget->impedenzaCuffieValue();
    QString frequenzaDiRisposta=cuffieAddWidget->frequenzaDiRispostaCuffieValue();
    QString connessione=cuffieAddWidget->connessioneCuffieValue();
    QString connettore=cuffieAddWidget->connettoreCuffieValue();
    bool microfono=cuffieAddWidget->microfonoCuffieValue();
    double prezzo=cuffieAddWidget->prezzoCuffieValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Cuffie(nome,prezzo,produttore,this,tipologia,sistemaAcustico,colore,microfono,canali,impedenza,
                frequenzaDiRisposta,connessione,connettore);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}

void PCBuilderController::eseguiAggiuntaAltoparlanti(){
    QString nome=altoparlantiAddWidget->nomeAltoparlantiValue();
    QString produttore=altoparlantiAddWidget->produttoreAltoparlantiValue();
    QString colore=altoparlantiAddWidget->coloreAltoparlantiValue();
    QString configurazione=altoparlantiAddWidget->configurazioneAltoparlantiValue();
    QString frequenzaDiRisposta=altoparlantiAddWidget->frequenzaDiRispostaAltoparlantiValue();
    QString potenzaTotale=altoparlantiAddWidget->potenzaTotaleAltoparlantiValue();
    QString potenze=altoparlantiAddWidget->potenzeAltoparlantiValue();
    double prezzo=altoparlantiAddWidget->prezzoAltoparlantiValue();

    if (this->validateComponenteAdd(nome))
    {
        dbComp=new Altoparlanti(nome,prezzo,produttore,this,colore,configurazione,frequenzaDiRisposta,potenzaTotale,potenze);
        dbcomponents->aggiungi_componente(dbComp);
        dbComp->saveXMLComponente();
        QMessageBox::information(mw,tr("PCBuilder"),tr("L'aggiunta' è avvenuta con successo"),QMessageBox::Ok);
    }
}


void PCBuilderController::callRimuoviComponente(){
    QString componente=mw->get_GestisciComponentiPCBuilder()->rimuoviComponenteValue();

    if (comp)
    {
        delete comp;
        comp=0;
    }
    comp=dbcomponents->find_componente(componente);
    if (!comp)
        QMessageBox::warning(mw,"PCBuilder",tr("Il componente inserito non è registrato nel sistema"),QMessageBox::Ok);
    else
    {
        dbcomponents->rimuovi_componente(comp);
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

                dbComp=new Alimentatore(nome,prezzo,produttore,this,tipologia,wattaggio,modulare,certificazioneEfficienza,efficienza);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Altoparlanti(nome,prezzo,produttore,this,colore,configurazione,frequenzaDiRisposta,potenzaTotale,potenze);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Archiviazione(nome,prezzo,produttore,this,tipologia,capacita,interfaccia,cache,fattoreDiForma,rpm);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Case(nome,prezzo,produttore,this,tipologia,colore,alimentatoreIncluso,slotInterni25,slotInterni35,
                                    compatibilitaSchedaMadre,lunghezzaMassimaSchedaGrafica,dimensioni);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Cuffie(nome,prezzo,produttore,this,tipologia,sistemaAcustico,colore,microfono,canali,impedenza,frequenzaDiRisposta,
                                      connessione,connettore);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new DissipatoreProcessore(nome,prezzo,produttore,this,socketSupportati,raffreddamentoALiquido,rpmVentola,altezza,
                                                     livelloRumore,altezzaRadiatore);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Memoria(nome,prezzo,produttore,this, velocita,capacita,tipologia,latenza);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Monitor(nome,prezzo,produttore,this,risoluzioneRaccomandata,widescreen,formato,angoloDiVisualizzazione,
                                       coloriDelDisplay,luminosita,rapportoDiContrasto,tempoDiRisposta,tipologiaDisplay,altoparlantiIncorporati,
                                       frequenzaDiAggiornamento);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Mouse(nome,prezzo,produttore,this,connessione,tipologiaTracciamento,DPIMassimi,colore,orientamentoDellaMano);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Processore(nome,prezzo,produttore,this,socket,larghezzaDati,frequenzaOperativa,frequenzaTurbo,numeroCore,
                                          l1Cache,l2Cache,l3Cache,litografia,tdp,includeDissipatore,hyperThreading,graficaIntegrata);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new SchedaGrafica(nome,prezzo,produttore,this,interfaccia,chipset,memoria,tipologiaMemoria,frequenzaCore,tdp,
                                             supportoSLI,supportoCrossfire,lunghezza);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new SchedaMadre(nome,prezzo,produttore,this,fattoreDiForma,chipset,socketProcessore,slotMemoria,tipologiaMemoria,
                                           memoriaMassima,supportoRAID,supportoCrossfire,supportoSLI,ethernet,sata3GBs,sata6GBs,sataExpress,
                                           usb2,usb3);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new SistemaOperativo(nome,prezzo,produttore,this,modalita,memoriaMassimaSupportata);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new Tastiera(nome,prezzo,produttore,this,colore,retroilluminazione,connessione,tipologia,tipologiaSwitch);
                dbcomponents->aggiungi_componente(dbComp);
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

                dbComp=new UnitaOttica(nome,prezzo,produttore,this,fattoreDiForma,interfaccia,cache,velocita);
                dbcomponents->aggiungi_componente(dbComp);
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
    if (u)
    {
        delete u;
        u=0;
    }

    u=new UtenteNonRegistrato(this);
    mw->openIndexUtenteNonRegistratoPCBuilder();
}

void PCBuilderController::deleteAccount(){
    QMessageBox::StandardButton reply;
    reply=QMessageBox::question(mw,"PCBuilder",tr("Sei sicuro di voler eliminare l'account?"),QMessageBox::Yes|QMessageBox::No);
    if (reply==QMessageBox::Yes)
    {
        u=dbusers->find_utente(u->get_Login()->getUsername());
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
        u=(dbusers->find_utente(u->get_Login()->getUsername()))->clone();
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

void PCBuilderController::saveConfigurazione(){
    if (u->get_type()=="UtenteNonRegistrato")
    {
        mw->openLoginPopUpPCBuilder();
    }
    else
    {
        QString nomeConfigurazione;
        bool ok;
        bool trovato=false;
        nomeConfigurazione=QInputDialog::getText(mw->get_CreaConfPCBuilder(),tr("PCBuilder"),tr("Nome configurazione:"),QLineEdit::Normal,"",&ok);
        if (ok)
        {
            if (nomeConfigurazione.isEmpty())
                QMessageBox::warning(mw->get_CreaConfPCBuilder(),"PCBuilder",tr("E' necessario fornire un nome alla configurazione"),QMessageBox::Ok);
            else
            {
                int i=0;
                while (!trovato && (i<(u->getConfigurazioni()->size())))
                {
                    if ((u->getConfigurazioni())->at(i)->getNome()==nomeConfigurazione)
                        trovato=true;
                    else
                        i++;
                }
                if (!confTemp)
                    conf=new Configurazione(nomeConfigurazione);
                else
                {
                    conf=confTemp->clone();
                    conf->setNome(nomeConfigurazione);
                }
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


void PCBuilderController::eseguiAccessoPopUp(){
    QString username=mw->get_LoginPopUpPCBuilder()->usernameValue();
    QString password=mw->get_LoginPopUpPCBuilder()->passwordValue();
    if (u)
        delete u;
    u=(dbusers->find_utente(username))->clone();
    if (!u)
    {
        u=new UtenteNonRegistrato(this);
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

void PCBuilderController::populateConfigurazioneList() const{

    QFont font_form;
    font_form.setPointSize(14);

    for (int i=0;i<(u->getConfigurazioni()->size());i++)
    {
        QString nomeConfigurazione=u->getConfigurazioni()->at(i)->getNome();
        QLabel* nomeConfigurazioneLabel=new QLabel(nomeConfigurazione);
        nomeConfigurazioneLabel->setFont(font_form);
        nomeConfigurazioneLabel->setMinimumSize(QSize(0,0));
        mw->get_LeMieConfigurazioniPCBuilder()->getGridLayout()->addWidget(nomeConfigurazioneLabel,i+1,0,1,1);

        QPushButton* visualizzaPushButton=new QPushButton(tr("Visualizza"));
        visualizzaPushButton->setMaximumSize(QSize(150,30));
        visualizzaPushButton->setMinimumSize(QSize(0,0));
        mw->get_LeMieConfigurazioniPCBuilder()->getViewSignalMapper()->setMapping(visualizzaPushButton,nomeConfigurazione);
        connect(visualizzaPushButton,SIGNAL(clicked()),mw->get_LeMieConfigurazioniPCBuilder()->getViewSignalMapper(),SLOT(map()));
        mw->get_LeMieConfigurazioniPCBuilder()->getGridLayout()->addWidget(visualizzaPushButton,i+1,1,1,1);

        QPushButton* modificaPushButton=new QPushButton(tr("Modifica"));
        modificaPushButton->setMaximumSize(QSize(150,30));
        modificaPushButton->setMinimumSize(QSize(0,0));
        mw->get_LeMieConfigurazioniPCBuilder()->getEditSignalMapper()->setMapping(modificaPushButton,nomeConfigurazione);
        connect(modificaPushButton,SIGNAL(clicked()),mw->get_LeMieConfigurazioniPCBuilder()->getEditSignalMapper(),SLOT(map()));
        mw->get_LeMieConfigurazioniPCBuilder()->getGridLayout()->addWidget(modificaPushButton,i+1,2,1,1);

    }
}

DBComponenti* PCBuilderController::getDBComponents() const{
    return dbcomponents;
}

void PCBuilderController::clearLayout(QLayout* layout){
    QLayoutItem* item;
    while ((item = layout->takeAt(0))!=0)
    {
        layout->removeWidget(item->widget());
        delete item->widget();
        delete item;
    }
}

void PCBuilderController::createAlimentatoreAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    alimentatoreAddWidget=new AlimentatoreAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(alimentatoreAddWidget);
}

void PCBuilderController::createAltoparlantiAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    altoparlantiAddWidget=new AltoparlantiAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(altoparlantiAddWidget);
}

void PCBuilderController::createArchiviazioneAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    archiviazioneAddWidget=new ArchiviazioneAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(archiviazioneAddWidget);
}

void PCBuilderController::createCaseAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    caseAddWidget=new CaseAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(caseAddWidget);
}

void PCBuilderController::createCuffieAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    cuffieAddWidget=new CuffieAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(cuffieAddWidget);
}

void PCBuilderController::createDissipatoreProcessoreAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    dissipatoreProcessoreAddWidget=new DissipatoreProcessoreAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(dissipatoreProcessoreAddWidget);
}

void PCBuilderController::createMemoriaAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    memoriaAddWidget=new MemoriaAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(memoriaAddWidget);
}

void PCBuilderController::createMonitorAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    monitorAddWidget=new MonitorAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(monitorAddWidget);
}

void PCBuilderController::createMouseAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    mouseAddWidget=new MouseAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(mouseAddWidget);
}

void PCBuilderController::createProcessoreAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    processoreAddWidget=new ProcessoreAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(processoreAddWidget);
}

void PCBuilderController::createSchedaGraficaAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    schedaGraficaAddWidget=new SchedaGraficaAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(schedaGraficaAddWidget);
}

void PCBuilderController::createSchedaMadreAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    schedaMadreAddWidget=new SchedaMadreAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(schedaMadreAddWidget);
}

void PCBuilderController::createSistemaOperativoAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    sistemaOperativoAddWidget=new SistemaOperativoAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(sistemaOperativoAddWidget);
}

void PCBuilderController::createTastieraAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    tastieraAddWidget=new TastieraAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(tastieraAddWidget);
}

void PCBuilderController::createUnitaOtticaAdd(){
    this->clearLayout(mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3());
    unitaOtticaAddWidget=new UnitaOtticaAddWidget;
    mw->get_GestisciComponentiPCBuilder()->getHorizontalLayout3()->addWidget(unitaOtticaAddWidget);
}

void PCBuilderController::callSetAddWidget(const QString& componente){
    Componente* componentInstance;
    if (componente=="Memoria")
    {
        componentInstance=new Memoria(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Scheda grafica")
    {
        componentInstance=new SchedaGrafica(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Scheda madre")
    {
        componentInstance=new SchedaMadre(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Processore")
    {
        componentInstance=new Processore(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Archiviazione")
    {
        componentInstance=new Archiviazione(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Alimentatore")
    {
        componentInstance=new Alimentatore(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Dissipatore processore")
    {
        componentInstance=new DissipatoreProcessore(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Case")
    {
        componentInstance=new Case(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Unità ottica")
    {
        componentInstance=new UnitaOttica(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Monitor")
    {
        componentInstance=new Monitor(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Sistema operativo")
    {
        componentInstance=new SistemaOperativo(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Mouse")
    {
        componentInstance=new Mouse(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Tastiera")
    {
        componentInstance=new Tastiera(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Cuffie")
    {
        componentInstance=new Cuffie(this);
        componentInstance->setAddWidget();
    }
    if (componente=="Altoparlanti")
    {
        componentInstance=new Altoparlanti(this);
        componentInstance->setAddWidget();
    }
    delete componentInstance;
}

void PCBuilderController::createAlimentatoreSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& tipologia,
                                                  const QString& wattaggio, const QString& modulare, const QString& certificazioneEfficienza, double efficienza){
    alimentatoreSpecsWidget=new AlimentatoreSpecsWidget;
    alimentatoreSpecsWidget->setNomeValueLabel(nome);
    alimentatoreSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    alimentatoreSpecsWidget->setProduttoreValueLabel(produttore);
    alimentatoreSpecsWidget->setTipologiaValueLabel(tipologia);
    alimentatoreSpecsWidget->setWattaggioValueLabel(wattaggio);
    alimentatoreSpecsWidget->setModulareValueLabel(modulare);
    alimentatoreSpecsWidget->setCertificazioneDiEfficienzaValueLabel(certificazioneEfficienza);
    alimentatoreSpecsWidget->setEfficienzaValueLabel(QString::number(efficienza));
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(alimentatoreSpecsWidget);
}

void PCBuilderController::createAltoparlantiSpecs(const QString& nome, double prezzo, const QString& produttore,
                                                  const QString& colore, const QString& configurazione, const QString& frequenzaDiRisposta,
                                                  const QString& potenzaTotale, const QString& potenze){
    altoparlantiSpecsWidget=new AltoparlantiSpecsWidget;
    altoparlantiSpecsWidget->setNomeValueLabel(nome);
    altoparlantiSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    altoparlantiSpecsWidget->setProduttoreValueLabel(produttore);
    altoparlantiSpecsWidget->setColoreValueLabel(colore);
    altoparlantiSpecsWidget->setConfigurazioneValueLabel(configurazione);
    altoparlantiSpecsWidget->setFrequenzaDiRispostaValueLabel(frequenzaDiRisposta);
    altoparlantiSpecsWidget->setPotenzaTotaleValueLabel(potenzaTotale);
    altoparlantiSpecsWidget->setPotenzeValueLabel(potenze);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(altoparlantiSpecsWidget);
}

void PCBuilderController::createArchiviazioneSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& tipologia,
                                                   const QString& capacita, const QString& interfaccia, const QString& cache, const QString& fattoreDiForma, const QString& rpm){
    archiviazioneSpecsWidget=new ArchiviazioneSpecsWidget;
    archiviazioneSpecsWidget->setNomeValueLabel(nome);
    archiviazioneSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    archiviazioneSpecsWidget->setProduttoreValueLabel(produttore);
    archiviazioneSpecsWidget->setTipologiaValueLabel(tipologia);
    archiviazioneSpecsWidget->setCapacitaValueLabel(capacita);
    archiviazioneSpecsWidget->setInterfacciaValueLabel(interfaccia);
    archiviazioneSpecsWidget->setCacheValueLabel(cache);
    archiviazioneSpecsWidget->setFattoreDiFormaValueLabel(fattoreDiForma);
    archiviazioneSpecsWidget->setRpmValueLabel(rpm);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(archiviazioneSpecsWidget);
}

void PCBuilderController::createCaseSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& tipologia,
                                          const QString& colore, bool alimentatoreIncluso, int slotInterni25, int slotInterni35,
                                          const QString& compatibilitaSchedaMadre, const QString& lunghezzaMassimaSchedaGrafica, const QString& dimensioni){
    caseSpecsWidget=new CaseSpecsWidget;
    caseSpecsWidget->setNomeValueLabel(nome);
    caseSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    caseSpecsWidget->setProduttoreValueLabel(produttore);
    caseSpecsWidget->setTipologiaValueLabel(tipologia);
    caseSpecsWidget->setColoreValueLabel(colore);
    caseSpecsWidget->setAlimentatoreInclusoValueLabel(alimentatoreIncluso ? "SI":"NO");
    caseSpecsWidget->setSlotInterni25ValueLabel(QString::number(slotInterni25));
    caseSpecsWidget->setSlotInterni35ValueLabel(QString::number(slotInterni35));
    caseSpecsWidget->setCompatibilitaSchedaMadreValueLabel(compatibilitaSchedaMadre);
    caseSpecsWidget->setLunghezzaMassimaSchedaGraficaValueLabel(lunghezzaMassimaSchedaGrafica);
    caseSpecsWidget->setDimensioniValueLabel(dimensioni);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(caseSpecsWidget);
}

void PCBuilderController::createCuffieSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& tipologia, const QString& sistemaAcustico,
                                            const QString& colore, bool microfono, const QString& canali, const QString& impedenza, const QString& frequenzaDiRisposta,
                                            const QString& connessione, const QString& connettore){
    cuffieSpecsWidget=new CuffieSpecsWidget;
    cuffieSpecsWidget->setNomeValueLabel(nome);
    cuffieSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    cuffieSpecsWidget->setProduttoreValueLabel(produttore);
    cuffieSpecsWidget->setTipologiaValueLabel(tipologia);
    cuffieSpecsWidget->setSistemaAcusticoValueLabel(sistemaAcustico);
    cuffieSpecsWidget->setColoreValueLabel(colore);
    cuffieSpecsWidget->setMicrofonoValueLabel(microfono ? "SI":"NO");
    cuffieSpecsWidget->setCanaliValueLabel(canali);
    cuffieSpecsWidget->setImpedenzaValueLabel(impedenza);
    cuffieSpecsWidget->setFrequenzaDiRispostaValueLabel(frequenzaDiRisposta);
    cuffieSpecsWidget->setConnessioneValueLabel(connessione);
    cuffieSpecsWidget->setConnettoreValueLabel(connettore);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(cuffieSpecsWidget);
}

void PCBuilderController::createDissipatoreProcessoreSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& socketSupportati,
                                                           bool raffreddamentoALiquido, const QString& rpmVentola, const QString& altezza, const QString& livelloRumore,
                                                           const QString& altezzaRadiatore){
    dissipatoreProcessoreSpecsWidget=new DissipatoreProcessoreSpecsWidget;
    dissipatoreProcessoreSpecsWidget->setNomeValueLabel(nome);
    dissipatoreProcessoreSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    dissipatoreProcessoreSpecsWidget->setProduttoreValueLabel(produttore);
    dissipatoreProcessoreSpecsWidget->setSocketSupportatiValueLabel(socketSupportati);
    dissipatoreProcessoreSpecsWidget->setRaffreddamentoALiquidoValueLabel(raffreddamentoALiquido ? "SI":"NO");
    dissipatoreProcessoreSpecsWidget->setRpmVentolaValueLabel(rpmVentola);
    dissipatoreProcessoreSpecsWidget->setAltezzaValueLabel(altezza);
    dissipatoreProcessoreSpecsWidget->setLivelloRumoreValueLabel(livelloRumore);
    dissipatoreProcessoreSpecsWidget->setAltezzaRadiatoreValueLabel(altezzaRadiatore);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(dissipatoreProcessoreSpecsWidget);
}

void PCBuilderController::createMemoriaSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& velocita,
                                             const QString& capacita, const QString& tipologia, int latenza){
    memoriaSpecsWidget=new MemoriaSpecsWidget;
    memoriaSpecsWidget->setNomeValueLabel(nome);
    memoriaSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    memoriaSpecsWidget->setProduttoreValueLabel(produttore);
    memoriaSpecsWidget->setVelocitaValueLabel(velocita);
    memoriaSpecsWidget->setCapacitaValueLabel(capacita);
    memoriaSpecsWidget->setTipologiaValueLabel(tipologia);
    memoriaSpecsWidget->setLatenzaValueLabel(QString::number(latenza));
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(memoriaSpecsWidget);
}

void PCBuilderController::createMonitorSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& risoluzioneRaccomandata,
                                             bool widescreen, const QString& formato, const QString& angoloDiVisualizzazione, const QString& coloriDelDisplay,
                                             const QString& luminosita, const QString& rapportoDiConstrasto, const QString& tempoDiRisposta, const QString& tipologiaDisplay, bool altoparlantiIncorporati, const QString& frequenzaDiAggiornamento){
    monitorSpecsWidget=new MonitorSpecsWidget;
    monitorSpecsWidget->setNomeValueLabel(nome);
    monitorSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    monitorSpecsWidget->setProduttoreValueLabel(produttore);
    monitorSpecsWidget->setRisoluzioneRaccomandataValueLabel(risoluzioneRaccomandata);
    monitorSpecsWidget->setWidescreenValueLabel(widescreen ? "SI":"NO");
    monitorSpecsWidget->setFormatoValueLabel(formato);
    monitorSpecsWidget->setAngoloDiVisualizzazioneValueLabel(angoloDiVisualizzazione);
    monitorSpecsWidget->setColoriDelDisplayValueLabel(coloriDelDisplay);
    monitorSpecsWidget->setLuminositaValueLabel(luminosita);
    monitorSpecsWidget->setRapportoDiContrastoValueLabel(rapportoDiConstrasto);
    monitorSpecsWidget->setTempoDiRispostaValueLabel(tempoDiRisposta);
    monitorSpecsWidget->setTipologiaDelDisplayValueLabel(tipologiaDisplay);
    monitorSpecsWidget->setAltoparlantiIncorporatiValueLabel(altoparlantiIncorporati ? "SI":"NO");
    monitorSpecsWidget->setFrequenzaDiAggiornamentoValueLabel(frequenzaDiAggiornamento);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(monitorSpecsWidget);
}

void PCBuilderController::createMouseSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& connessione,
                                           const QString& tipologiaTracciamento, int DPIMassimi, const QString& colore, const QString& orientamentoDellaMano){
    mouseSpecsWidget=new MouseSpecsWidget;
    mouseSpecsWidget->setNomeValueLabel(nome);
    mouseSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    mouseSpecsWidget->setProduttoreValueLabel(produttore);
    mouseSpecsWidget->setConnessioneValueLabel(connessione);
    mouseSpecsWidget->setTipologiaTracciamentoValueLabel(tipologiaTracciamento);
    mouseSpecsWidget->setDpiMassimiValueLabel(QString::number(DPIMassimi));
    mouseSpecsWidget->setColoreValueLabel(colore);
    mouseSpecsWidget->setOrientamentoDellaManoValueLabel(orientamentoDellaMano);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(mouseSpecsWidget);
}

void PCBuilderController::createProcessoreSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& socket, const QString& larghezzaDati,
                                                const QString& frequenzaOperativa, const QString& frequenzaTurbo, int numeroCore, const QString& l1Cache, const QString& l2Cache,
                                                const QString& l3Cache, const QString& litografia, const QString& tdp, bool includeDissipatore, bool hyperThreading, const QString& graficaIntegrata){
    processoreSpecsWidget=new ProcessoreSpecsWidget;
    processoreSpecsWidget->setNomeValueLabel(nome);
    processoreSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    processoreSpecsWidget->setProduttoreValueLabel(produttore);
    processoreSpecsWidget->setSocketValueLabel(socket);
    processoreSpecsWidget->setLarghezzaDatiValueLabel(larghezzaDati);
    processoreSpecsWidget->setFrequenzaOperativaValueLabel(frequenzaOperativa);
    processoreSpecsWidget->setFrequenzaTurboValueLabel(frequenzaTurbo);
    processoreSpecsWidget->setNumeroCoreValueLabel(QString::number(numeroCore));
    processoreSpecsWidget->setL1CacheValueLabel(l1Cache);
    processoreSpecsWidget->setL2CacheValueLabel(l2Cache);
    processoreSpecsWidget->setL3CacheValueLabel(l3Cache);
    processoreSpecsWidget->setLitografiaValueLabel(litografia);
    processoreSpecsWidget->setTdpValueLabel(tdp);
    processoreSpecsWidget->setIncludeDissipatoreValueLabel(includeDissipatore ? "SI":"NO");
    processoreSpecsWidget->setHyperThreadingValueLabel(hyperThreading ? "SI":"NO");
    processoreSpecsWidget->setGraficaIntegrataValueLabel(graficaIntegrata);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(processoreSpecsWidget);
}

void PCBuilderController::createSchedaGraficaSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& interfaccia, const QString& chipset,
                                                   const QString& memoria, const QString& tipologiaMemoria, const QString& frequenzaCore, const QString& tdp, const QString& supportoSLI,
                                                   const QString& supportoCrossfire, const QString& lunghezza){
    schedaGraficaSpecsWidget=new SchedaGraficaSpecsWidget;
    schedaGraficaSpecsWidget->setNomeValueLabel(nome);
    schedaGraficaSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    schedaGraficaSpecsWidget->setProduttoreValueLabel(produttore);
    schedaGraficaSpecsWidget->setInterfacciaValueLabel(interfaccia);
    schedaGraficaSpecsWidget->setChipsetValueLabel(chipset);
    schedaGraficaSpecsWidget->setMemoriaValueLabel(memoria);
    schedaGraficaSpecsWidget->setTipologiaMemoriaValueLabel(tipologiaMemoria);
    schedaGraficaSpecsWidget->setFrequenzaCoreValueLabel(frequenzaCore);
    schedaGraficaSpecsWidget->setTdpValueLabel(tdp);
    schedaGraficaSpecsWidget->setSupportoSLIValueLabel(supportoSLI);
    schedaGraficaSpecsWidget->setSupportoCrossfireValueLabel(supportoCrossfire);
    schedaGraficaSpecsWidget->setLunghezzaValueLabel(lunghezza);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(schedaGraficaSpecsWidget);
}

void PCBuilderController::createSchedaMadreSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& fattoreDiForma, const QString& chipset,
                                                 const QString& socketProcessore, const QString& slotMemoria, const QString& tipologiaMemoria, const QString& memoriaMassima,
                                                 bool supportoRAID, bool supportoCrossfire, bool supportoSLI, const QString& ethernet, int sata3GBs, int sata6GBs, int sataExpress, int usb2, int usb3){
    schedaMadreSpecsWidget=new SchedaMadreSpecsWidget;
    schedaMadreSpecsWidget->setNomeValueLabel(nome);
    schedaMadreSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    schedaMadreSpecsWidget->setProduttoreValueLabel(produttore);
    schedaMadreSpecsWidget->setFattoreDiFormaValueLabel(fattoreDiForma);
    schedaMadreSpecsWidget->setChipsetValueLabel(chipset);
    schedaMadreSpecsWidget->setSocketProcessoreValueLabel(socketProcessore);
    schedaMadreSpecsWidget->setSlotMemoriaValueLabel(slotMemoria);
    schedaMadreSpecsWidget->setTipologiaMemoriaValueLabel(tipologiaMemoria);
    schedaMadreSpecsWidget->setMemoriaMassimaValueLabel(memoriaMassima);
    schedaMadreSpecsWidget->setSupportoRAIDValueLabel(supportoRAID ? "SI":"NO");
    schedaMadreSpecsWidget->setSupportoCrossfireValueLabel(supportoCrossfire ? "SI":"NO");
    schedaMadreSpecsWidget->setSupportoSLIValueLabel(supportoSLI ? "SI":"NO");
    schedaMadreSpecsWidget->setEthernetValueLabel(ethernet);
    schedaMadreSpecsWidget->setSata3GBsValueLabel(QString::number(sata3GBs));
    schedaMadreSpecsWidget->setSata6GBsValueLabel(QString::number(sata6GBs));
    schedaMadreSpecsWidget->setSataExpressValueLabel(QString::number(sataExpress));
    schedaMadreSpecsWidget->setUsb2ValueLabel(QString::number(usb2));
    schedaMadreSpecsWidget->setUsb3ValueLabel(QString::number(usb3));
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(schedaMadreSpecsWidget);
}

void PCBuilderController::createSistemaOperativoSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& modalita, const QString& memoriaMassimaSupportata){
    sistemaOperativoSpecsWidget=new SistemaOperativoSpecsWidget;
    sistemaOperativoSpecsWidget->setNomeValueLabel(nome);
    sistemaOperativoSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    sistemaOperativoSpecsWidget->setProduttoreValueLabel(produttore);
    sistemaOperativoSpecsWidget->setModalitaValueLabel(modalita);
    sistemaOperativoSpecsWidget->setMemoriaMassimaSupportataValueLabel(memoriaMassimaSupportata);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(sistemaOperativoSpecsWidget);
}

void PCBuilderController::createTastieraSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& colore,
                                              bool retroilluminazione, const QString& connessione, const QString& tipologia, const QString& tipologiaSwitch){
    tastieraSpecsWidget=new TastieraSpecsWidget;
    tastieraSpecsWidget->setNomeValueLabel(nome);
    tastieraSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    tastieraSpecsWidget->setProduttoreValueLabel(produttore);
    tastieraSpecsWidget->setColoreValueLabel(colore);
    tastieraSpecsWidget->setRetroilluminazioneValueLabel(retroilluminazione ? "SI":"NO");
    tastieraSpecsWidget->setConnessioneValueLabel(connessione);
    tastieraSpecsWidget->setTipologiaValueLabel(tipologia);
    tastieraSpecsWidget->setTipologiaSwitchValueLabel(tipologiaSwitch);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(tastieraSpecsWidget);
}

void PCBuilderController::createUnitaOtticaSpecs(const QString& nome, double prezzo, const QString& produttore, const QString& fattoreDiForma,
                                                 const QString& interfaccia, const QString& cache, const QString& velocita){
    unitaOtticaSpecsWidget=new UnitaOtticaSpecsWidget;
    unitaOtticaSpecsWidget->setNomeValueLabel(nome);
    unitaOtticaSpecsWidget->setPrezzoValueLabel(QString::number(prezzo));
    unitaOtticaSpecsWidget->setProduttoreValueLabel(produttore);
    unitaOtticaSpecsWidget->setFattoreDiFormaValueLabel(fattoreDiForma);
    unitaOtticaSpecsWidget->setInterfacciaValueLabel(interfaccia);
    unitaOtticaSpecsWidget->setCacheValueLabel(cache);
    unitaOtticaSpecsWidget->setVelocitaValueLabel(velocita);
    mw->get_SpecificheComponentePCBuilder()->getVerticalLayout1()->addWidget(unitaOtticaSpecsWidget);
}

void PCBuilderController::callSetSpecsWidget(const QString& nomeComponente){
    Componente* c=dbcomponents->find_componente(nomeComponente);
    c->setSpecsWidget();
}

void PCBuilderController::populatePartsList(const QString& componente){
    for (Container<Componente*>::iteratore it=(dbcomponents->getDBComponenti().begin());it!=(dbcomponents->getDBComponenti().end());it++)
    {
        if (dbcomponents->getDBComponenti()[it]->getType()==componente)
        {
            mw->get_PartsListPCBuilder()->addComponent(dbcomponents->getDBComponenti()[it]->getNome(),
                                                             dbcomponents->getDBComponenti()[it]->getProduttore(),
                                                             dbcomponents->getDBComponenti()[it]->getPrezzo());
        }
    }
}


void PCBuilderController::updateConfigurazioneAlimentatore(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setAlimentatorePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiAlimentatorePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiAlimentatorePushButton());
    mw->get_CreaConfPCBuilder()->getAlimentatoreNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getAlimentatoreNomeLabel(),8,1,1,1);
}

void PCBuilderController::updateConfigurazioneAltoparlanti(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setAltoparlantiPrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiAltoparlantiPushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiAltoparlantiPushButton());
    mw->get_CreaConfPCBuilder()->getAltoparlantiNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getAltoparlantiNomeLabel(),15,1,1,1);
}

void PCBuilderController::updateConfigurazioneArchiviazione(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setArchiviazionePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiArchiviazionePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiArchiviazionePushButton());
    mw->get_CreaConfPCBuilder()->getArchiviazioneNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getArchiviazioneNomeLabel(),5,1,1,1);
}

void PCBuilderController::updateConfigurazioneCase(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setCasePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiCasePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiCasePushButton());
    mw->get_CreaConfPCBuilder()->getCaseNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getCaseNomeLabel(),7,1,1,1);
}

void PCBuilderController::updateConfigurazioneCuffie(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setCuffiePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiCuffiePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiCuffiePushButton());
    mw->get_CreaConfPCBuilder()->getCuffieNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getCuffieNomeLabel(),14,1,1,1);
}

void PCBuilderController::updateConfigurazioneDissipatoreProcessore(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setDissipatoreProcessorePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiDissipatoreProcessorePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiDissipatoreProcessorePushButton());
    mw->get_CreaConfPCBuilder()->getDissipatoreProcessoreNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getDissipatoreProcessoreNomeLabel(),2,1,1,1);
}

void PCBuilderController::updateConfigurazioneMemoria(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setMemoriaPrezzoLabel("€ "+ (QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiMemoriaPushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiMemoriaPushButton());
    mw->get_CreaConfPCBuilder()->getMemoriaNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getMemoriaNomeLabel(),4,1,1,1);
}

void PCBuilderController::updateConfigurazioneMonitor(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setMonitorPrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiMonitorPushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiMonitorPushButton());
    mw->get_CreaConfPCBuilder()->getMonitorNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getMonitorNomeLabel(),11,1,1,1);
}

void PCBuilderController::updateConfigurazioneMouse(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setMousePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiMousePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiMousePushButton());
    mw->get_CreaConfPCBuilder()->getMouseNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getMouseNomeLabel(),12,1,1,1);
}

void PCBuilderController::updateConfigurazioneProcessore(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setProcessorePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiProcessorePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiProcessorePushButton());
    mw->get_CreaConfPCBuilder()->getProcessoreNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getProcessoreNomeLabel(),1,1,1,1);
}

void PCBuilderController::updateConfigurazioneSchedaGrafica(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setSchedaGraficaPrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiSchedaGraficaPushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiSchedaGraficaPushButton());
    mw->get_CreaConfPCBuilder()->getSchedaGraficaNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getSchedaGraficaNomeLabel(),6,1,1,1);
}

void PCBuilderController::updateConfigurazioneSchedaMadre(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setSchedaMadrePrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiSchedaMadrePushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiSchedaMadrePushButton());
    mw->get_CreaConfPCBuilder()->getSchedaMadreNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getSchedaMadreNomeLabel(),3,1,1,1);
}

void PCBuilderController::updateConfigurazioneSistemaOperativo(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setSistemaOperativoPrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiSistemaOperativoPushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiSistemaOperativoPushButton());
    mw->get_CreaConfPCBuilder()->getSistemaOperativoNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getSistemaOperativoNomeLabel(),10,1,1,1);
}

void PCBuilderController::updateConfigurazioneTastiera(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setTastieraPrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiTastieraPushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiTastieraPushButton());
    mw->get_CreaConfPCBuilder()->getTastieraNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getTastieraNomeLabel(),13,1,1,1);
}

void PCBuilderController::updateConfigurazioneUnitaOttica(const QString& nome, double prezzo){
    mw->get_CreaConfPCBuilder()->setUnitaOtticaPrezzoLabel("€ "+(QString::number(prezzo)));
    mw->get_CreaConfPCBuilder()->getGridLayout()->removeWidget(mw->get_CreaConfPCBuilder()->getAggiungiUnitaOtticaPushButton());
    delete (mw->get_CreaConfPCBuilder()->getAggiungiUnitaOtticaPushButton());
    mw->get_CreaConfPCBuilder()->getUnitaOtticaNomeLabel()->setText(nome);
    mw->get_CreaConfPCBuilder()->getGridLayout()->addWidget(mw->get_CreaConfPCBuilder()->getUnitaOtticaNomeLabel(),9,1,1,1);
}

Configurazione* PCBuilderController::getConfigurazione() const{
    return conf;
}

void PCBuilderController::updatePrezzoTotaleConfigurazione(double totale) const{
    mw->get_CreaConfPCBuilder()->setPrezzoTotaleLabel(QString::number(totale));
}

void PCBuilderController::updateConfigurazione(const QString& nomeComponente){
    Componente* componente=dbcomponents->find_componente(nomeComponente);
    componente->updateConfigurazione();
    if (!confTemp)
        confTemp=new Configurazione;
    confTemp->aggiungiComponente(componente);
    this->updatePrezzoTotaleConfigurazione(confTemp->getPrezzoTotale());
    if (mw->get_PartsListPCBuilder())
    {
        mw->get_stackedWidget()->removeWidget(mw->get_PartsListPCBuilder());
        delete (mw->get_PartsListPCBuilder());
        mw->set_PartsListPCBuilder(0);
        mw->get_stackedWidget()->setCurrentWidget(mw->get_CreaConfPCBuilder());
    }
}

void PCBuilderController::createConfigurazioneView(const QString& nomeConfigurazione) const{
    Configurazione* configurazione;

    for (QVector<Configurazione*>::const_iterator it=u->getConfigurazioni()->begin();it!=u->getConfigurazioni()->end();it++)
    {
        if ((*it)->getNome()==nomeConfigurazione)
            configurazione=(*it);
    }
    mw->get_ConfigurazionePCBuilder()->setNomeConfigurazioneValueLabel(configurazione->getNome());

    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    QVector<Componente*> config=configurazione->getConf();
    for (int i=0;i<(config.size());i++)
    {
        QLabel* componenteLabel=new QLabel(config.at(i)->getNomeTipoComponente());
        componenteLabel->setFont(font_formLabel);
        mw->get_ConfigurazionePCBuilder()->getGridLayout()->addWidget(componenteLabel,i,0,1,1);
        QLabel* nomeComponenteLabel=new QLabel(config.at(i)->getNome());
        nomeComponenteLabel->setFont(font_formLabel);
        nomeComponenteLabel->setWordWrap(true);
        mw->get_ConfigurazionePCBuilder()->getGridLayout()->addWidget(nomeComponenteLabel,i,1,1,1);
        QLabel* prezzoComponenteLabel=new QLabel("€ "+QString::number(config.at(i)->getPrezzo()));
        prezzoComponenteLabel->setFont(font_formLabel);
        mw->get_ConfigurazionePCBuilder()->getGridLayout()->addWidget(prezzoComponenteLabel,i,2,1,1);
    }
    mw->get_ConfigurazionePCBuilder()->setPrezzoTotaleLabel(QString::number(configurazione->getPrezzoTotale()));
}

void PCBuilderController::editConfigurazione(const QString& nomeConfigurazione){
    Configurazione* configurazione;
    for (QVector<Configurazione*>::const_iterator it=u->getConfigurazioni()->begin();it!=u->getConfigurazioni()->end();it++)
    {
        if ((*it)->getNome()==nomeConfigurazione)
            configurazione=(*it);
    }
    mw->openCreaConfPCBuilder();
    QVector<Componente*> config=configurazione->getConf();
    for (int i=0; i<(config.size());i++)
    {
        this->updateConfigurazione(config.at(i)->getNome());
    }
}

void PCBuilderController::resetConfigurazione(){
    mw->get_stackedWidget()->removeWidget(mw->get_CreaConfPCBuilder());
    delete mw->get_CreaConfPCBuilder();
    mw->set_CreaConfPCBuilder(0);
    delete confTemp;
    confTemp=0;
    mw->openCreaConfPCBuilder();
}


void PCBuilderController::clearAlimentatoreAdd() const{
    alimentatoreAddWidget->getNomeLineEditAlimentatore()->clear();
    alimentatoreAddWidget->getProduttoreLineEditAlimentatore()->clear();
    alimentatoreAddWidget->getTipologiaLineEditAlimentatore()->clear();
    alimentatoreAddWidget->getWattaggioLineEditAlimentatore()->clear();
    alimentatoreAddWidget->getModulareLineEditAlimentatore()->clear();
    alimentatoreAddWidget->getCertificazioneEfficienzaLineEditAlimentatore()->clear();
    alimentatoreAddWidget->getEfficienzaDoubleSpinBoxAlimentatore()->clear();
    alimentatoreAddWidget->getPrezzoDoubleSpinBoxAlimentatore()->clear();
}

void PCBuilderController::clearAltoparlantiAdd() const{
    altoparlantiAddWidget->getNomeLineEditAltoparlanti()->clear();
    altoparlantiAddWidget->getProduttoreLineEditAltoparlanti()->clear();
    altoparlantiAddWidget->getColoreLineEditAltoparlanti()->clear();
    altoparlantiAddWidget->getConfigurazioneLineEditAltoparlanti()->clear();
    altoparlantiAddWidget->getFrequenzaDiRispostaLineEditAltoparlanti()->clear();
    altoparlantiAddWidget->getPotenzaTotaleLineEditAltoparlanti()->clear();
    altoparlantiAddWidget->getPotenzeLineEditAltoparlanti()->clear();
    altoparlantiAddWidget->getPrezzoDoubleSpinBoxAltoparlanti()->clear();
}

void PCBuilderController::clearArchiviazioneAdd() const{
    archiviazioneAddWidget->getNomeLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getProduttoreLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getTipologiaLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getCapacitaLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getInterfacciaLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getCacheLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getFattoreDiFormaLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getRpmLineEditArchiviazione()->clear();
    archiviazioneAddWidget->getPrezzoDoubleSpinBoxArchiviazione()->clear();
}

void PCBuilderController::clearCaseAdd() const{
    caseAddWidget->getNomeLineEditCase()->clear();
    caseAddWidget->getProduttoreLineEditCase()->clear();
    caseAddWidget->getTipologiaLineEditCase()->clear();
    caseAddWidget->getColoreLineEditCase()->clear();
    caseAddWidget->getCompatibilitaSchedaMadreLineEditCase()->clear();
    caseAddWidget->getLunghezzaMassimaSchedaGraficaLineEditCase()->clear();
    caseAddWidget->getDimensioniLineEditCase()->clear();
    caseAddWidget->getAlimentatoreInclusoCheckBoxCase()->setCheckState(Qt::Unchecked);
    caseAddWidget->getSlotInterni25SpinBoxCase()->clear();
    caseAddWidget->getSlotInterni35SpinBoxCase()->clear();
    caseAddWidget->getPrezzoDoubleSpinBoxCase()->clear();
}

void PCBuilderController::clearCuffieAdd() const{
    cuffieAddWidget->getNomeLineEditCuffie()->clear();
    cuffieAddWidget->getProduttoreLineEditCuffie()->clear();
    cuffieAddWidget->getTipologiaLineEditCuffie()->clear();
    cuffieAddWidget->getSistemaAcusticoLineEditCuffie()->clear();
    cuffieAddWidget->getColoreLineEditCuffie()->clear();
    cuffieAddWidget->getCanaliLineEditCuffie()->clear();
    cuffieAddWidget->getImpedenzaLineEditCuffie()->clear();
    cuffieAddWidget->getFrequenzaDiRispostaLineEditCuffie()->clear();
    cuffieAddWidget->getConnessioneLineEditCuffie()->clear();
    cuffieAddWidget->getConnettoreLineEditCuffie()->clear();
    cuffieAddWidget->getMicrofonoCheckBoxCuffie()->setCheckState(Qt::Unchecked);
    cuffieAddWidget->getPrezzoDoubleSpinBoxCuffie()->clear();
}

void PCBuilderController::clearDissipatoreProcessoreAdd() const{
    dissipatoreProcessoreAddWidget->getNomeLineEditDissipatoreProcessore()->clear();
    dissipatoreProcessoreAddWidget->getProduttoreLineEditDissipatoreProcessore()->clear();
    dissipatoreProcessoreAddWidget->getSocketSupportatiLineEditDissipatoreProcessore()->clear();
    dissipatoreProcessoreAddWidget->getRpmVentolaLineEditDissipatoreProcessore()->clear();
    dissipatoreProcessoreAddWidget->getAltezzaLineEditDissipatoreProcessore()->clear();
    dissipatoreProcessoreAddWidget->getAltezzaRadiatoreLineEditDissipatoreProcessore()->clear();
    dissipatoreProcessoreAddWidget->getLivelloRumoreLineEditDissipatoreProcessore()->clear();
    dissipatoreProcessoreAddWidget->getRaffreddamentoALiquidoCheckBoxDissipatoreProcessore()->setCheckState(Qt::Unchecked);
    dissipatoreProcessoreAddWidget->getPrezzoDoubleSpinBoxDissipatoreProcessore()->clear();
}

void PCBuilderController::clearMemoriaAdd() const{
    memoriaAddWidget->getNomeLineEditMemoria()->clear();
    memoriaAddWidget->getProduttoreLineEditMemoria()->clear();
    memoriaAddWidget->getVelocitaLineEditMemoria()->clear();
    memoriaAddWidget->getCapacitaLineEditMemoria()->clear();
    memoriaAddWidget->getTipologiaLineEditMemoria()->clear();
    memoriaAddWidget->getPrezzoDoubleSpinBoxMemoria()->clear();
    memoriaAddWidget->getLatenzaSpinBoxMemoria()->clear();
}

void PCBuilderController::clearMonitorAdd() const{
    monitorAddWidget->getNomeLineEditMonitor()->clear();
    monitorAddWidget->getProduttoreLineEditMonitor()->clear();
    monitorAddWidget->getRisoluzioneRaccomandataLineEditMonitor()->clear();
    monitorAddWidget->getFormatoLineEditMonitor()->clear();
    monitorAddWidget->getAngoloDiVisualizzazioneLineEditMonitor()->clear();
    monitorAddWidget->getColoriDelDisplayLineEditMonitor()->clear();
    monitorAddWidget->getLuminositaLineEditMonitor()->clear();
    monitorAddWidget->getRapportoDiContrastoLineEditMonitor()->clear();
    monitorAddWidget->getTempoDiRispostaLineEditMonitor()->clear();
    monitorAddWidget->getTipologiaDisplayLineEditMonitor()->clear();
    monitorAddWidget->getFrequenzaDiAggiornamentoLineEditMonitor()->clear();
    monitorAddWidget->getAltoparlantiIncorporatiCheckBoxMonitor()->setCheckState(Qt::Unchecked);
    monitorAddWidget->getWidescreenCheckBoxMonitor()->setCheckState(Qt::Unchecked);
    monitorAddWidget->getPrezzoDoubleSpinBoxMonitor()->clear();
}

void PCBuilderController::clearMouseAdd() const{
    mouseAddWidget->getNomeLineEditMouse()->clear();
    mouseAddWidget->getProduttoreLineEditMouse()->clear();
    mouseAddWidget->getConnessioneLineEditMouse()->clear();
    mouseAddWidget->getTipologiaTracciamentoLineEditMouse()->clear();
    mouseAddWidget->getColoreLineEditMouse()->clear();
    mouseAddWidget->getOrientamentoDellaManoLineEditMouse()->clear();
    mouseAddWidget->getDpiMassimiSpinBoxMouse()->clear();
    mouseAddWidget->getPrezzoDoubleSpinBoxMouse()->clear();
}

void PCBuilderController::clearProcessoreAdd() const{
    processoreAddWidget->getNomeLineEditProcessore()->clear();
    processoreAddWidget->getProduttoreLineEditProcessore()->clear();
    processoreAddWidget->getSocketLineEditProcessore()->clear();
    processoreAddWidget->getLarghezzaDatiLineEditProcessore()->clear();
    processoreAddWidget->getFrequenzaOperativaLineEditProcessore()->clear();
    processoreAddWidget->getFrequenzaTurboLineEditProcessore()->clear();
    processoreAddWidget->getL1CacheLineEditProcessore()->clear();
    processoreAddWidget->getL2CacheLineEditProcessore()->clear();
    processoreAddWidget->getL3CacheLineEditProcessore()->clear();
    processoreAddWidget->getLitografiaLineEditProcessore()->clear();
    processoreAddWidget->getTdpLineEditProcessore()->clear();
    processoreAddWidget->getGraficaIntegrataLineEditProcessore()->clear();
    processoreAddWidget->getIncludeDissipatoreCheckBoxProcessore()->setCheckState(Qt::Unchecked);
    processoreAddWidget->getHyperThreadingCheckBoxProcessore()->setCheckState(Qt::Unchecked);
    processoreAddWidget->getNumeroCoreSpinBoxProcessore()->clear();
    processoreAddWidget->getPrezzoDoubleSpinBoxProcessore()->clear();
}

void PCBuilderController::clearSchedaGraficaAdd() const{
    schedaGraficaAddWidget->getNomeLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getProduttoreLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getInterfacciaLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getChipsetLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getMemoriaLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getTipologiaMemoriaLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getFrequenzaCoreLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getTdpLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getSupportoSLILineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getSupportoCrossfireLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getLunghezzaLineEditSchedaGrafica()->clear();
    schedaGraficaAddWidget->getPrezzoDoubleSpinBoxSchedaGrafica()->clear();
}

void PCBuilderController::clearSchedaMadreAdd() const{
    schedaMadreAddWidget->getNomeLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getProduttoreLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getFattoreDiFormaLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getChipsetLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getSocketProcessoreLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getSlotMemoriaLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getTipologiaMemoriaLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getMemoriaMassimaLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getEthernetLineEditSchedaMadre()->clear();
    schedaMadreAddWidget->getSupportoRAIDCheckBoxSchedaMadre()->setCheckState(Qt::Unchecked);
    schedaMadreAddWidget->getSupportoCrossfireCheckBoxSchedaMadre()->setCheckState(Qt::Unchecked);
    schedaMadreAddWidget->getSupportoSLICheckBoxSchedaMadre()->setCheckState(Qt::Unchecked);
    schedaMadreAddWidget->getSata3GBsSpinBoxSchedaMadre()->clear();
    schedaMadreAddWidget->getSata6GBsSpinBoxSchedaMadre()->clear();
    schedaMadreAddWidget->getSataExpressSpinboxSchedaMadre()->clear();
    schedaMadreAddWidget->getUsb2SpinBoxSchedaMadre()->clear();
    schedaMadreAddWidget->getUsb3SpinBoxSchedaMadre()->clear();
    schedaMadreAddWidget->getPrezzoDoubleSpinBoxSchedaMadre()->clear();
}

void PCBuilderController::clearSistemaOperativoAdd() const{
    sistemaOperativoAddWidget->getNomeLineEditSistemaOperativo()->clear();
    sistemaOperativoAddWidget->getProduttoreLineEditSistemaOperativo()->clear();
    sistemaOperativoAddWidget->getModalitaLineEditSistemaOperativo()->clear();
    sistemaOperativoAddWidget->getMemoriaMassimaSupportataLineEditSistemaOperativo()->clear();
    sistemaOperativoAddWidget->getPrezzoDoubleSpinBoxSistemaOperativo()->clear();
}

void PCBuilderController::clearTastieraAdd() const{
    tastieraAddWidget->getNomeLineEditTastiera()->clear();
    tastieraAddWidget->getProduttoreLineEditTastiera()->clear();
    tastieraAddWidget->getColoreLineEditTastiera()->clear();
    tastieraAddWidget->getConnessioneLineEditTastiera()->clear();
    tastieraAddWidget->getTipologiaLineEditTastiera()->clear();
    tastieraAddWidget->getTipologiaSwitchLineEditTastiera()->clear();
    tastieraAddWidget->getRetroilluminazioneCheckBoxTastiera()->setCheckState(Qt::Unchecked);
    tastieraAddWidget->getPrezzoDoubleSpinBoxTastiera()->clear();
}

void PCBuilderController::clearUnitaOtticaAdd() const{
    unitaOtticaAddWidget->getNomeLineEditUnitaOttica()->clear();
    unitaOtticaAddWidget->getProduttoreLineEditUnitaOttica()->clear();
    unitaOtticaAddWidget->getFattoreDiFormaLineEditUnitaOttica()->clear();
    unitaOtticaAddWidget->getInterfacciaLineEditUnitaOttica()->clear();
    unitaOtticaAddWidget->getCacheLineEditUnitaOttica()->clear();
    unitaOtticaAddWidget->getVelocitaLineEditUnitaOttica()->clear();
    unitaOtticaAddWidget->getPrezzoDoubleSpinBoxUnitaOttica()->clear();
}
