#ifndef PCBUILDERCONTROLLER_H
#define PCBUILDERCONTROLLER_H

#include "MainWindow.h"
#include "Componente.h"
#include "DBComponenti.h"

#include <QMap>
#include <QString>

class Utente;
class UtenteNonRegistrato;
class UtenteRegistrato;
class DBUtenti;

class PCBuilderController:public QObject{
    Q_OBJECT
private:
    MainWindow* mw;
    Utente* u;
    DBUtenti* dbusers;
    DBComponenti* dbcomponents;
    Componente* comp;

    void eseguiRegistrazione(const QString&, const QString&, const QString&, const QString&,
                             const QString&, const QString&, const QString&, const QString&);
    bool email_validation(const QString&) const;
    void load_DBUtenti();
    void load_DBComponenti();
    void eseguiAggiuntaMemoria(const QString&, const QString&, const QString&, const QString&, const QString&, double, int);
    void eseguiAggiuntaSchedaGrafica(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                     const QString&, const QString&, const QString&, const QString&, const QString&, double);
    void eseguiAggiuntaSchedaMadre(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                   const QString&, const QString&, const QString&, bool, bool, bool, int, int, int, int, int, double);
    void eseguiAggiuntaProcessore(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                  const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                  bool, bool, int, double);
    void eseguiAggiuntaArchiviazione(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                     const QString&, const QString&, double);
    void eseguiAggiuntaAlimentatore(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                    double, double);
    void eseguiAggiuntaDissipatoreProcessore(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                             const QString&, bool, double);
    void eseguiAggiuntaCase(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                            bool, int, int, double);
    void eseguiAggiuntaUnitaOttica(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                   double);
    void eseguiAggiuntaMonitor(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                               const QString&, const QString&, const QString&, const QString&, bool, bool, double);
    void eseguiAggiuntaSistemaOperativo(const QString&, const QString&, const QString&, const QString&, double);
    void eseguiAggiuntaMouse(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, int, double);
    void eseguiAggiuntaTastiera(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, bool, double);
    void eseguiAggiuntaCuffie(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                              const QString&, const QString&, const QString&, bool, double);
    void eseguiAggiuntaAltoparlanti(const QString&, const QString&, const QString&, const QString&, const QString&, const QString&, const QString&,
                                    double);
    void saveXMLUtenti(Utente*) const;
public:
    PCBuilderController();
    ~PCBuilderController();
    void set_IndexUtenteNonRegistrato();
    void set_IndexUtenteRegistrato();
    void set_IndexUtentePremium();
    MainWindow* get_MainWindow() const;
    void build_PartsListPCBuilder();
    QString getUserType() const;
    Utente* getUser() const;
    DBComponenti* getDBComponents() const;
    QMap<QString,QString> getComponentSpecs(const QString&) const;
public slots:
    void callShowIndex();
    void registrati();
    void accedi();
    void callRimuoviComponente();
    void modificaProfiloUtente();
    void logout();
    void callRimuoviUtente();
    void aggiungi_componente();
    void callModificaUtenti();
    void deleteAccount();
    void upgradeAccount();
    //void saveConfigurazione();
    //void eseguiAccessoPopUp();
    //void editConfigurazione(const QString&);
private slots:
    void close_MainWindow();
    void close_LoginPopUpPCBuilder();
};


#endif // PCBUILDERCONTROLLER_H
