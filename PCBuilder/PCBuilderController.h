#ifndef PCBUILDERCONTROLLER_H
#define PCBUILDERCONTROLLER_H

#include "MainWindow.h"

#include "AlimentatoreAddWidget.h"
#include "AltoparlantiAddWidget.h"
#include "ArchiviazioneAddWidget.h"
#include "CaseAddWidget.h"
#include "CuffieAddWidget.h"
#include "DissipatoreProcessoreAddWidget.h"
#include "MemoriaAddWidget.h"
#include "MonitorAddWidget.h"
#include "MouseAddWidget.h"
#include "ProcessoreAddWidget.h"
#include "SchedaGraficaAddWidget.h"
#include "SchedaMadreAddWidget.h"
#include "SistemaOperativoAddWidget.h"
#include "TastieraAddWidget.h"
#include "UnitaOtticaAddWidget.h"
#include "AlimentatoreSpecsWidget.h"
#include "AltoparlantiSpecsWidget.h"
#include "ArchiviazioneSpecsWidget.h"
#include "CaseSpecsWidget.h"
#include "CuffieSpecsWidget.h"
#include "DissipatoreProcessoreSpecsWidget.h"
#include "MemoriaSpecsWidget.h"
#include "MonitorSpecsWidget.h"
#include "MouseSpecsWidget.h"
#include "ProcessoreSpecsWidget.h"
#include "SchedaGraficaSpecsWidget.h"
#include "SchedaMadreSpecsWidget.h"
#include "SistemaOperativoSpecsWidget.h"
#include "TastieraSpecsWidget.h"
#include "UnitaOtticaSpecsWidget.h"

#include <QMap>
#include <QString>

class Utente;
class UtenteNonRegistrato;
class UtenteRegistrato;
class DBUtenti;
class Componente;
class DBComponenti;
class Configurazione;

class PCBuilderController:public QObject{
    Q_OBJECT
private:
    MainWindow* mw;
    Utente* u;
    Utente* dbUser;
    DBUtenti* dbusers;
    DBComponenti* dbcomponents;
    Componente* comp;
    Componente* dbComp;
    Configurazione* conf;
    Configurazione* confTemp;

    AlimentatoreAddWidget* alimentatoreAddWidget;
    AltoparlantiAddWidget* altoparlantiAddWidget;
    ArchiviazioneAddWidget* archiviazioneAddWidget;
    CaseAddWidget* caseAddWidget;
    CuffieAddWidget* cuffieAddWidget;
    DissipatoreProcessoreAddWidget* dissipatoreProcessoreAddWidget;
    MemoriaAddWidget* memoriaAddWidget;
    MonitorAddWidget* monitorAddWidget;
    MouseAddWidget* mouseAddWidget;
    ProcessoreAddWidget* processoreAddWidget;
    SchedaGraficaAddWidget* schedaGraficaAddWidget;
    SchedaMadreAddWidget* schedaMadreAddWidget;
    SistemaOperativoAddWidget* sistemaOperativoAddWidget;
    TastieraAddWidget* tastieraAddWidget;
    UnitaOtticaAddWidget* unitaOtticaAddWidget;

    AlimentatoreSpecsWidget* alimentatoreSpecsWidget;
    AltoparlantiSpecsWidget* altoparlantiSpecsWidget;
    ArchiviazioneSpecsWidget* archiviazioneSpecsWidget;
    CaseSpecsWidget* caseSpecsWidget;
    CuffieSpecsWidget* cuffieSpecsWidget;
    DissipatoreProcessoreSpecsWidget* dissipatoreProcessoreSpecsWidget;
    MemoriaSpecsWidget* memoriaSpecsWidget;
    MonitorSpecsWidget* monitorSpecsWidget;
    MouseSpecsWidget* mouseSpecsWidget;
    ProcessoreSpecsWidget* processoreSpecsWidget;
    SchedaGraficaSpecsWidget* schedaGraficaSpecsWidget;
    SchedaMadreSpecsWidget* schedaMadreSpecsWidget;
    SistemaOperativoSpecsWidget* sistemaOperativoSpecsWidget;
    TastieraSpecsWidget* tastieraSpecsWidget;
    UnitaOtticaSpecsWidget* unitaOtticaSpecsWidget;

    void eseguiRegistrazione(const QString&, const QString&, const QString&, const QString&,
                             const QString&, const QString&, const QString&, const QString&);
    bool email_validation(const QString&) const;
    void load_DBUtenti();
    void load_DBComponenti();
    void saveXMLUtenti(Utente*) const;
    void clearLayout(QLayout*);
    bool validateComponenteAdd(const QString&) const;
    void updatePrezzoTotaleConfigurazione(double) const;
public:
    PCBuilderController();
    ~PCBuilderController();
    void set_IndexUtenteNonRegistrato();
    void set_IndexUtenteRegistrato();
    void set_IndexUtentePremium();
    MainWindow* get_MainWindow() const;
    QString getUserType() const;
    Utente* getUser() const;
    DBComponenti* getDBComponents() const;
    void createAlimentatoreAdd();
    void createAltoparlantiAdd();
    void createArchiviazioneAdd();
    void createCaseAdd();
    void createCuffieAdd();
    void createDissipatoreProcessoreAdd();
    void createMemoriaAdd();
    void createMonitorAdd();
    void createMouseAdd();
    void createProcessoreAdd();
    void createSchedaGraficaAdd();
    void createSchedaMadreAdd();
    void createSistemaOperativoAdd();
    void createTastieraAdd();
    void createUnitaOtticaAdd();

    void clearAlimentatoreAdd() const;
    void clearAltoparlantiAdd() const;
    void clearArchiviazioneAdd() const;
    void clearCaseAdd() const;
    void clearCuffieAdd() const;
    void clearDissipatoreProcessoreAdd() const;
    void clearMemoriaAdd() const;
    void clearMonitorAdd() const;
    void clearMouseAdd() const;
    void clearProcessoreAdd() const;
    void clearSchedaGraficaAdd() const;
    void clearSchedaMadreAdd() const;
    void clearSistemaOperativoAdd() const;
    void clearTastieraAdd() const;
    void clearUnitaOtticaAdd() const;

    void eseguiAggiuntaMemoria();
    void eseguiAggiuntaSchedaGrafica();
    void eseguiAggiuntaSchedaMadre();
    void eseguiAggiuntaProcessore();
    void eseguiAggiuntaArchiviazione();
    void eseguiAggiuntaAlimentatore();
    void eseguiAggiuntaDissipatoreProcessore();
    void eseguiAggiuntaCase();
    void eseguiAggiuntaUnitaOttica();
    void eseguiAggiuntaMonitor();
    void eseguiAggiuntaSistemaOperativo();
    void eseguiAggiuntaMouse();
    void eseguiAggiuntaTastiera();
    void eseguiAggiuntaCuffie();
    void eseguiAggiuntaAltoparlanti();
    void createAlimentatoreSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&,
                                 const QString&, double);
    void createAltoparlantiSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&,
                                 const QString&, const QString&);
    void createArchiviazioneSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&,
                                  const QString&, const QString&, const QString&);
    void createCaseSpecs(const QString&, double, const QString&, const QString&, const QString&, bool, int, int, const QString&,
                         const QString&, const QString&);
    void createCuffieSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&, bool, const QString&,
                           const QString&, const QString&, const QString&, const QString&);
    void createDissipatoreProcessoreSpecs(const QString&, double, const QString&, const QString&, bool, const QString&,
                                          const QString&, const QString&, const QString&);
    void createMemoriaSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&, int);
    void createMonitorSpecs(const QString&, double, const QString&, const QString&, bool, const QString&, const QString&,
                            const QString&, const QString&, const QString&, const QString&, const QString&, bool, const QString&);
    void createMouseSpecs(const QString&, double, const QString&, const QString&, const QString&, int, const QString&, const QString&);
    void createProcessoreSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&, const QString&,
                               int, const QString&, const QString&, const QString&, const QString&, const QString&, bool, bool, const QString&);
    void createSchedaGraficaSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&, const QString&,
                                  const QString&, const QString&, const QString&, const QString&, const QString&);
    void createSchedaMadreSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&,
                                const QString&, const QString&, const QString&, bool, bool, bool, const QString&, int, int, int, int, int);
    void createSistemaOperativoSpecs(const QString&, double, const QString&, const QString&, const QString&);
    void createTastieraSpecs(const QString&, double, const QString&, const QString&, bool, const QString&, const QString&, const QString&);
    void createUnitaOtticaSpecs(const QString&, double, const QString&, const QString&, const QString&, const QString&, const QString&);

    void updateConfigurazioneAlimentatore(const QString&, double);
    void updateConfigurazioneAltoparlanti(const QString&, double);
    void updateConfigurazioneArchiviazione(const QString&, double);
    void updateConfigurazioneCase(const QString&, double);
    void updateConfigurazioneCuffie(const QString&, double);
    void updateConfigurazioneDissipatoreProcessore(const QString&, double);
    void updateConfigurazioneMemoria(const QString&, double);
    void updateConfigurazioneMonitor(const QString&, double);
    void updateConfigurazioneMouse(const QString&, double);
    void updateConfigurazioneProcessore(const QString&, double);
    void updateConfigurazioneSchedaGrafica(const QString&, double);
    void updateConfigurazioneSchedaMadre(const QString&, double);
    void updateConfigurazioneSistemaOperativo(const QString&, double);
    void updateConfigurazioneTastiera(const QString&, double);
    void updateConfigurazioneUnitaOttica(const QString&, double);

    void populatePartsList(const QString&);
    Configurazione* getConfigurazione() const;
    void populateConfigurazioneList() const;
    void createConfigurazioneView(const QString&) const;
    DBUtenti* getDBUtenti() const;
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
    void callSetAddWidget(const QString&);
    void callSetSpecsWidget(const QString&);
    void updateConfigurazione(const QString&);
    void saveConfigurazione();
    void eseguiAccessoPopUp();
    void editConfigurazione(const QString&);
    void resetConfigurazione();
private slots:
    void close_MainWindow();
    void close_LoginPopUpPCBuilder();
};


#endif // PCBUILDERCONTROLLER_H
