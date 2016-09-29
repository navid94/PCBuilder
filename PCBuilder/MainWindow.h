#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MyWidget_IndexPCBuilder.h"
#include "MyWidget_IndexUtenteNonRegistratoPCBuilder.h"
#include "MyWidget_IndexUtenteRegistratoPCBuilder.h"
#include "MyWidget_IndexUtentePremiumPCBuilder.h"
#include "MyWidget_RegistrazioneUtentePCBuilder.h"
#include "MyWidget_PartsListPCBuilder.h"
#include "MyWidget_IndexAdminPCBuilder.h"
#include "MyWidget_GestisciUtentiPCBuilder.h"
#include "MyWidget_GestisciComponentiPCBuilder.h"
#include "MyWidget_ModificaProfiloUtentePCBuilder.h"
#include "MyWidget_CreaConfPCBuilder.h"
#include "MyWidget_LoginPopUpPCBuilder.h"
#include "MyWidget_LeMieConfigurazioniPCBuilder.h"
#include "MyWidget_CercaPartiPCBuilder.h"
#include "MyWidget_SpecificheComponentePCBuilder.h"
#include "MyWidget_ConfigurazionePCBuilder.h"

#include <QMainWindow>
#include <QAction>
#include <QStackedWidget>
#include <QScrollArea>

class PCBuilderController;

class MainWindow: public QMainWindow{
    Q_OBJECT
private:
    void createActions();
    void createMenus();
    void createToolbar();
    void createStatusbar();

    QMenu* fileMenu;
    QMenu* viewMenu;
    QMenu* helpMenu;

    QAction* exitAction;
    QAction* fullScreenAction;
    QAction* normalViewAction;
    QAction* aboutAction;

    QToolBar* fileToolBar;

    QStackedWidget* stackedWidget;
    QScrollArea* scrollArea;

    PCBuilderController* controller;
    MyWidget_IndexPCBuilder* IndexPCBuilder;
    MyWidget_IndexUtenteNonRegistratoPCBuilder* IndexUtenteNonRegistratoPCBuilder;
    MyWidget_IndexUtenteRegistratoPCBuilder* IndexUtenteRegistratoPCBuilder;
    MyWidget_IndexUtentePremiumPCBuilder* IndexUtentePremiumPCBuilder;
    MyWidget_RegistrazioneUtentePCBuilder* RegistrazioneUtentePCBuilder;
    MyWidget_PartsListPCBuilder* PartsListPCBuilder;
    MyWidget_IndexAdminPCBuilder* IndexAdminPCBuilder;
    MyWidget_GestisciUtentiPCBuilder* GestisciUtentiPCBuilder;
    MyWidget_GestisciComponentiPCBuilder* GestisciComponentiPCBuilder;
    MyWidget_ModificaProfiloUtentePCBuilder* ModificaProfiloUtentePCBuilder;
    MyWidget_CreaConfPCBuilder* CreaConfPCBuilder;
    MyWidget_LoginPopUpPCBuilder* LoginPopUpPCBuilder;
    MyWidget_LeMieConfigurazioniPCBuilder* LeMieConfigurazioniPCBuilder;
    MyWidget_CercaPartiPCBuilder* CercaPartiPCBuilder;
    MyWidget_SpecificheComponentePCBuilder* SpecificheComponentePCBuilder;
    MyWidget_ConfigurazionePCBuilder* ConfigurazionePCBuilder;
public:
    MainWindow(PCBuilderController*);
    ~MainWindow();

    QStackedWidget* get_stackedWidget() const;
    PCBuilderController* get_Controller() const;
    MyWidget_IndexPCBuilder* get_IndexPCBuilder() const;
    MyWidget_IndexUtenteNonRegistratoPCBuilder* get_IndexUtenteNonRegistratoPCBuilder() const;
    MyWidget_IndexUtenteRegistratoPCBuilder* get_IndexUtenteRegistratoPCBuilder() const;
    MyWidget_IndexUtentePremiumPCBuilder* get_IndexUtentePremiumPCBuilder() const;
    MyWidget_RegistrazioneUtentePCBuilder* get_RegistrazioneUtentePCBuilder() const;
    MyWidget_PartsListPCBuilder* get_PartsListPCBuilder() const;
    MyWidget_IndexAdminPCBuilder* get_IndexAdminPCBuilder() const;
    MyWidget_GestisciUtentiPCBuilder* get_GestisciUtentiPCBuilder() const;
    MyWidget_GestisciComponentiPCBuilder* get_GestisciComponentiPCBuilder() const;
    MyWidget_ModificaProfiloUtentePCBuilder* get_ModificaProfiloUtentePCBuilder() const;
    MyWidget_CreaConfPCBuilder* get_CreaConfPCBuilder() const;
    MyWidget_LoginPopUpPCBuilder* get_LoginPopUpPCBuilder() const;
    MyWidget_LeMieConfigurazioniPCBuilder* get_LeMieConfigurazioniPCBuilder() const;
    MyWidget_CercaPartiPCBuilder* get_CercaPartiPCBuilder() const;
    MyWidget_SpecificheComponentePCBuilder* get_SpecificheComponentePCBuilder() const;
    MyWidget_ConfigurazionePCBuilder* get_ConfigurazionePCBuilder() const;

    void set_PartsListPCBuilder(MyWidget_PartsListPCBuilder*);
    void set_CreaConfPCBuilder(MyWidget_CreaConfPCBuilder*);

    void closeEvent(QCloseEvent*);
    void openLoginPopUpPCBuilder();

signals:
    void closeMainWindow();
    void closeLoginPopUpPCBuilder();

private slots:
    void openIndexAdminPCBuilder();
    void openGestisciUtentiPCBuilder();
    void openGestisciComponentiPCBuilder();
    void openAboutPage();
public slots:
    void openIndexUtenteNonRegistratoPCBuilder();
    void openIndexUtenteRegistratoPCBuilder();
    void openIndexUtentePremiumPCBuilder();
    void openRegistrazioneUtentePCBuilder();
    void openModificaProfiloUtentePCBuilder();
    void openIndexPCBuilder();
    void openCreaConfPCBuilder();
    void openPartsListPCBuilder(const QString&);
    void openLeMieConfigurazioniPCBuilder();
    void openCercaPartiPCBuilder();
    void openSpecificheComponentePCBuilder(const QString&);
    void openConfigurazionePCBuilder(const QString&);
};


#endif // MAINWINDOW_H
