#include "MainWindow.h"
#include "PCBuilderController.h"

#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QStringList>
#include <QMessageBox>

#include <iostream>
using namespace std;

MainWindow::MainWindow(PCBuilderController* input_controller):controller(input_controller){
    resize(1024,720);

    createStatusbar();
    createActions();
    createMenus();
    createToolbar();

    IndexPCBuilder=0;
    IndexUtenteNonRegistratoPCBuilder=0;
    IndexUtenteRegistratoPCBuilder=0;
    IndexUtentePremiumPCBuilder=0;
    RegistrazioneUtentePCBuilder=0;
    IndexAdminPCBuilder=0;
    GestisciUtentiPCBuilder=0;
    GestisciComponentiPCBuilder=0;
    ModificaProfiloUtentePCBuilder=0;
    CreaConfPCBuilder=0;
    PartsListPCBuilder=0;
    LeMieConfigurazioniPCBuilder=0;
    CercaPartiPCBuilder=0;
    SpecificheComponentePCBuilder=0;

    stackedWidget=new QStackedWidget;
    scrollArea=new QScrollArea;
    scrollArea->setWidget(stackedWidget);
    stackedWidget->setMinimumSize(QSize(1024,720));

    openIndexPCBuilder();

    setCentralWidget(scrollArea);
}

MainWindow::~MainWindow(){
    delete controller;
}

void MainWindow::createStatusbar(){
    statusBar();
}

void MainWindow::createActions(){
    exitAction=new QAction(tr("Chiudi PCBuilder"),this);
    exitAction->setStatusTip(tr("Esci dall'applicazione"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));

    fullScreenAction=new QAction(tr("Schermo intero"),this);
    fullScreenAction->setStatusTip(tr("Mostra la finestra a tutto schermo"));
    connect(fullScreenAction,SIGNAL(triggered()),this,SLOT(showFullScreen()));

    normalViewAction=new QAction(tr("Dimensione normale"),this);
    normalViewAction->setStatusTip(tr("Mostra la finestra nella dimensione normale"));
    connect(normalViewAction,SIGNAL(triggered()),this,SLOT(showNormal()));

    aboutAction=new QAction(tr("Informazioni"),this);
    aboutAction->setStatusTip(tr("Mostra le informazioni riguardo all'applicazione"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(openAboutPage()));

}

void MainWindow::createMenus(){
    fileMenu= menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAction);

    viewMenu= menuBar()->addMenu(tr("&Vista"));
    viewMenu->addAction(fullScreenAction);
    viewMenu->addAction(normalViewAction);

    helpMenu= menuBar()->addMenu(tr("&Aiuto"));
    helpMenu->addAction(aboutAction);
}

void MainWindow::createToolbar(){
    fileToolBar= addToolBar(tr("&File"));
    fileToolBar->addAction(exitAction);
}

void MainWindow::openAboutPage(){
    QMessageBox::about(this,"PCBuilder",tr("Questo programma utilizza Qt in versione 5.3.2.\nPer ogni aiuto riferirsi alla relazione che accompagna tale programma."));
}

QStackedWidget* MainWindow::get_stackedWidget() const{
    return stackedWidget;
}

PCBuilderController* MainWindow::get_Controller() const{
    return controller;
}

MyWidget_IndexPCBuilder* MainWindow::get_IndexPCBuilder() const{
    return IndexPCBuilder;
}

MyWidget_IndexUtenteNonRegistratoPCBuilder* MainWindow::get_IndexUtenteNonRegistratoPCBuilder() const{
    return IndexUtenteNonRegistratoPCBuilder;
}

MyWidget_IndexUtenteRegistratoPCBuilder* MainWindow::get_IndexUtenteRegistratoPCBuilder() const{
    return IndexUtenteRegistratoPCBuilder;
}

MyWidget_IndexUtentePremiumPCBuilder* MainWindow::get_IndexUtentePremiumPCBuilder() const{
    return IndexUtentePremiumPCBuilder;
}

MyWidget_RegistrazioneUtentePCBuilder* MainWindow::get_RegistrazioneUtentePCBuilder() const{
    return RegistrazioneUtentePCBuilder;
}

MyWidget_PartsListPCBuilder* MainWindow::get_PartsListPCBuilder() const{
    return PartsListPCBuilder;
}

MyWidget_IndexAdminPCBuilder* MainWindow::get_IndexAdminPCBuilder() const{
    return IndexAdminPCBuilder;
}

MyWidget_GestisciUtentiPCBuilder* MainWindow::get_GestisciUtentiPCBuilder() const{
    return GestisciUtentiPCBuilder;
}

MyWidget_GestisciComponentiPCBuilder* MainWindow::get_GestisciComponentiPCBuilder() const{
    return GestisciComponentiPCBuilder;
}

MyWidget_ModificaProfiloUtentePCBuilder* MainWindow::get_ModificaProfiloUtentePCBuilder() const{
    return ModificaProfiloUtentePCBuilder;
}

MyWidget_CreaConfPCBuilder* MainWindow::get_CreaConfPCBuilder() const{
    return CreaConfPCBuilder;
}

MyWidget_LoginPopUpPCBuilder* MainWindow::get_LoginPopUpPCBuilder() const{
    return LoginPopUpPCBuilder;
}

MyWidget_LeMieConfigurazioniPCBuilder* MainWindow::get_LeMieConfigurazioniPCBuilder() const{
    return LeMieConfigurazioniPCBuilder;
}

MyWidget_CercaPartiPCBuilder* MainWindow::get_CercaPartiPCBuilder() const{
    return CercaPartiPCBuilder;
}

MyWidget_SpecificheComponentePCBuilder* MainWindow::get_SpecificheComponentePCBuilder() const{
    return SpecificheComponentePCBuilder;
}

void MainWindow::openCreaConfPCBuilder(){
    if (IndexUtenteNonRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteNonRegistratoPCBuilder);
        delete IndexUtenteNonRegistratoPCBuilder;
        IndexUtenteNonRegistratoPCBuilder=0;
    }
    if (IndexUtenteRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteRegistratoPCBuilder);
        delete IndexUtenteRegistratoPCBuilder;
        IndexUtenteRegistratoPCBuilder=0;
    }
    if (IndexUtentePremiumPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtentePremiumPCBuilder);
        delete IndexUtentePremiumPCBuilder;
        IndexUtentePremiumPCBuilder=0;
    }
    if (PartsListPCBuilder)
    {
        stackedWidget->removeWidget(PartsListPCBuilder);
        delete PartsListPCBuilder;
        PartsListPCBuilder=0;
    }
    if (!CreaConfPCBuilder)
    {
        CreaConfPCBuilder=new MyWidget_CreaConfPCBuilder();
        stackedWidget->addWidget(CreaConfPCBuilder);
        connect(CreaConfPCBuilder->getIndietroPushButton(),SIGNAL(clicked()),controller,SLOT(callShowIndex()));
        connect(CreaConfPCBuilder,SIGNAL(sendMessage(const QString&)),this,SLOT(openPartsListPCBuilder(const QString&)));
        connect(CreaConfPCBuilder->getNuovaConfigurazionePushButton(),SIGNAL(clicked()),this,SLOT(resetConfigurazione()));
        connect(CreaConfPCBuilder->getSalvaConfigurazionePushButton(),SIGNAL(clicked()),controller,SLOT(saveConfigurazione()));
    }
    stackedWidget->setCurrentWidget(CreaConfPCBuilder);
}

void MainWindow::openRegistrazioneUtentePCBuilder(){
    if (IndexUtenteNonRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteNonRegistratoPCBuilder);
        delete IndexUtenteNonRegistratoPCBuilder;
        IndexUtenteNonRegistratoPCBuilder=0;
    }
    if (!RegistrazioneUtentePCBuilder)
    {
        RegistrazioneUtentePCBuilder=new MyWidget_RegistrazioneUtentePCBuilder;
        RegistrazioneUtentePCBuilder->setMaximumSize(QSize(1024,600));
        connect(RegistrazioneUtentePCBuilder->get_indietroPushButton(),SIGNAL(clicked()),this,SLOT(openIndexUtenteNonRegistratoPCBuilder()));
        connect(RegistrazioneUtentePCBuilder->get_registratiPushButton(),SIGNAL(clicked()),controller,SLOT(registrati()));
        stackedWidget->addWidget(RegistrazioneUtentePCBuilder);
    }
    stackedWidget->setCurrentWidget(RegistrazioneUtentePCBuilder);
}

void MainWindow::openIndexUtenteNonRegistratoPCBuilder(){
    if (RegistrazioneUtentePCBuilder)
    {
        stackedWidget->removeWidget(RegistrazioneUtentePCBuilder);
        delete RegistrazioneUtentePCBuilder;
        RegistrazioneUtentePCBuilder=0;
    }
    if (CreaConfPCBuilder)
    {
        stackedWidget->removeWidget(CreaConfPCBuilder);
        delete CreaConfPCBuilder;
        CreaConfPCBuilder=0;
    }
    if (!IndexUtenteNonRegistratoPCBuilder)
    {
        IndexUtenteNonRegistratoPCBuilder=new MyWidget_IndexUtenteNonRegistratoPCBuilder;
        IndexUtenteNonRegistratoPCBuilder->setMaximumSize(QSize(1024,600));
        connect(IndexUtenteNonRegistratoPCBuilder->get_registratiPushButton(),SIGNAL(clicked()),this,SLOT(openRegistrazioneUtentePCBuilder()));
        connect(IndexUtenteNonRegistratoPCBuilder->get_indietroPushButton(),SIGNAL(clicked()),this,SLOT(openIndexPCBuilder()));
        connect(IndexUtenteNonRegistratoPCBuilder->get_accediPushButton(),SIGNAL(clicked()),controller,SLOT(accedi()));
        connect(IndexUtenteNonRegistratoPCBuilder->get_creaconfPushButton(),SIGNAL(clicked()),this,SLOT(openCreaConfPCBuilder()));
        stackedWidget->addWidget(IndexUtenteNonRegistratoPCBuilder);
    }
    stackedWidget->setCurrentWidget(IndexUtenteNonRegistratoPCBuilder);
}

void MainWindow::openIndexUtenteRegistratoPCBuilder(){
    if (IndexUtenteNonRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteNonRegistratoPCBuilder);
        delete IndexUtenteNonRegistratoPCBuilder;
        IndexUtenteNonRegistratoPCBuilder=0;
    }
    if (ModificaProfiloUtentePCBuilder)
    {
        stackedWidget->removeWidget(ModificaProfiloUtentePCBuilder);
        delete ModificaProfiloUtentePCBuilder;
        ModificaProfiloUtentePCBuilder=0;
    }
    if (CreaConfPCBuilder)
    {
        stackedWidget->removeWidget(CreaConfPCBuilder);
        delete CreaConfPCBuilder;
        CreaConfPCBuilder=0;
    }
    if (LeMieConfigurazioniPCBuilder)
    {
        stackedWidget->removeWidget(LeMieConfigurazioniPCBuilder);
        delete LeMieConfigurazioniPCBuilder;
        LeMieConfigurazioniPCBuilder=0;
    }
    if (!IndexUtenteRegistratoPCBuilder)
    {
        IndexUtenteRegistratoPCBuilder=new MyWidget_IndexUtenteRegistratoPCBuilder;
        IndexUtenteRegistratoPCBuilder->setMaximumSize(QSize(1024,600));
        stackedWidget->addWidget(IndexUtenteRegistratoPCBuilder);
        connect(IndexUtenteRegistratoPCBuilder->getModificaProfiloPushButton(),SIGNAL(clicked()),this,SLOT(openModificaProfiloUtentePCBuilder()));
        connect(IndexUtenteRegistratoPCBuilder->getEsciPushButton(),SIGNAL(clicked()),controller,SLOT(logout()));
        connect(IndexUtenteRegistratoPCBuilder->getCreaconfPushButton(),SIGNAL(clicked()),this,SLOT(openCreaConfPCBuilder()));
        connect(IndexUtenteRegistratoPCBuilder->getMostraconfsalvatePushButton(),SIGNAL(clicked()),this,SLOT(openLeMieConfigurazioniPCBuilder()));
    }
    stackedWidget->setCurrentWidget(IndexUtenteRegistratoPCBuilder);
}

void MainWindow::openIndexUtentePremiumPCBuilder(){
    if (IndexUtenteNonRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteNonRegistratoPCBuilder);
        delete IndexUtenteNonRegistratoPCBuilder;
        IndexUtenteNonRegistratoPCBuilder=0;
    }
    if (ModificaProfiloUtentePCBuilder)
    {
        stackedWidget->removeWidget(ModificaProfiloUtentePCBuilder);
        delete ModificaProfiloUtentePCBuilder;
        ModificaProfiloUtentePCBuilder=0;
    }
    if (CreaConfPCBuilder)
    {
        stackedWidget->removeWidget(CreaConfPCBuilder);
        delete CreaConfPCBuilder;
        CreaConfPCBuilder=0;
    }
    if (LeMieConfigurazioniPCBuilder)
    {
        stackedWidget->removeWidget(LeMieConfigurazioniPCBuilder);
        delete LeMieConfigurazioniPCBuilder;
        LeMieConfigurazioniPCBuilder=0;
    }
    if (CercaPartiPCBuilder)
    {
        stackedWidget->removeWidget(CercaPartiPCBuilder);
        delete CercaPartiPCBuilder;
        CercaPartiPCBuilder=0;
    }
    if (!IndexUtentePremiumPCBuilder)
    {
        IndexUtentePremiumPCBuilder=new MyWidget_IndexUtentePremiumPCBuilder;
        IndexUtentePremiumPCBuilder->setMaximumSize(QSize(1024,600));
        stackedWidget->addWidget(IndexUtentePremiumPCBuilder);
        connect(IndexUtentePremiumPCBuilder->getModificaProfiloPushButton(),SIGNAL(clicked()),this,SLOT(openModificaProfiloUtentePCBuilder()));
        connect(IndexUtentePremiumPCBuilder->getEsciPushButton(),SIGNAL(clicked()),controller,SLOT(logout()));
        connect(IndexUtentePremiumPCBuilder->getCreaconfPushButton(),SIGNAL(clicked()),this,SLOT(openCreaConfPCBuilder()));
        connect(IndexUtentePremiumPCBuilder->getMostraconfsalvatePushButton(),SIGNAL(clicked()),this,SLOT(openLeMieConfigurazioniPCBuilder()));
        connect(IndexUtentePremiumPCBuilder->getCercapartiPushButton(),SIGNAL(clicked()),this,SLOT(openCercaPartiPCBuilder()));
    }
    stackedWidget->setCurrentWidget(IndexUtentePremiumPCBuilder);
}

void MainWindow::openIndexAdminPCBuilder(){
    if (IndexPCBuilder)
    {
        stackedWidget->removeWidget(IndexPCBuilder);
        delete IndexPCBuilder;
        IndexPCBuilder=0;
    }
    if (GestisciComponentiPCBuilder)
    {
        stackedWidget->removeWidget(GestisciComponentiPCBuilder);
        delete GestisciComponentiPCBuilder;
        GestisciComponentiPCBuilder=0;
    }
    if (GestisciUtentiPCBuilder)
    {
        stackedWidget->removeWidget(GestisciUtentiPCBuilder);
        delete GestisciUtentiPCBuilder;
        GestisciUtentiPCBuilder=0;
    }
    if (!IndexAdminPCBuilder)
    {
        IndexAdminPCBuilder=new MyWidget_IndexAdminPCBuilder;
        IndexAdminPCBuilder->setMaximumSize(QSize(1024,600));
        connect(IndexAdminPCBuilder->get_indietroPushButton(),SIGNAL(clicked()),this,SLOT(openIndexPCBuilder()));
        connect(IndexAdminPCBuilder->get_gestisciutentiPushButton(),SIGNAL(clicked()),this,SLOT(openGestisciUtentiPCBuilder()));
        connect(IndexAdminPCBuilder->get_gestiscicompPushButton(),SIGNAL(clicked()),this,SLOT(openGestisciComponentiPCBuilder()));
        stackedWidget->addWidget(IndexAdminPCBuilder);
    }
    stackedWidget->setCurrentWidget(IndexAdminPCBuilder);
}

void MainWindow::openGestisciUtentiPCBuilder(){
    if (IndexAdminPCBuilder)
    {
        stackedWidget->removeWidget(IndexAdminPCBuilder);
        delete IndexAdminPCBuilder;
        IndexAdminPCBuilder=0;
    }
    if (!GestisciUtentiPCBuilder)
    {
        GestisciUtentiPCBuilder=new MyWidget_GestisciUtentiPCBuilder;
        GestisciUtentiPCBuilder->setMaximumSize(QSize(1024,600));
        connect(GestisciUtentiPCBuilder->get_indietroPushButton(),SIGNAL(clicked()),this,SLOT(openIndexAdminPCBuilder()));
        connect(GestisciUtentiPCBuilder->get_modificaPushButton(),SIGNAL(clicked()),controller,SLOT(callModificaUtenti()));
        connect(GestisciUtentiPCBuilder->get_elimina_utentePushButton(),SIGNAL(clicked()),controller,SLOT(callRimuoviUtente()));
        stackedWidget->addWidget(GestisciUtentiPCBuilder);
    }
    stackedWidget->setCurrentWidget(GestisciUtentiPCBuilder);
}

void MainWindow::openIndexPCBuilder(){
    if (IndexAdminPCBuilder)
    {
        stackedWidget->removeWidget(IndexAdminPCBuilder);
        delete IndexAdminPCBuilder;
        IndexAdminPCBuilder=0;
    }
    if (IndexUtenteNonRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteNonRegistratoPCBuilder);
        delete IndexUtenteNonRegistratoPCBuilder;
        IndexUtenteNonRegistratoPCBuilder=0;
    }
    if (IndexUtenteRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteRegistratoPCBuilder);
        delete IndexUtenteRegistratoPCBuilder;
        IndexUtenteRegistratoPCBuilder=0;
    }
    if (!IndexPCBuilder)
    {
        IndexPCBuilder=new MyWidget_IndexPCBuilder;
        IndexPCBuilder->setMaximumSize(QSize(1024,600));
        connect(IndexPCBuilder->getutentePushButton(),SIGNAL(clicked()),controller,SLOT(callShowIndex()));
        connect(IndexPCBuilder->getadminPushButton(),SIGNAL(clicked()),this,SLOT(openIndexAdminPCBuilder()));
        stackedWidget->addWidget(IndexPCBuilder);
    }
    stackedWidget->setCurrentWidget(IndexPCBuilder);
}

void MainWindow::openGestisciComponentiPCBuilder(){
    if (IndexAdminPCBuilder)
    {
        stackedWidget->removeWidget(IndexAdminPCBuilder);
        delete IndexAdminPCBuilder;
        IndexAdminPCBuilder=0;
    }
    if (!GestisciComponentiPCBuilder)
    {
        GestisciComponentiPCBuilder=new MyWidget_GestisciComponentiPCBuilder;
        stackedWidget->addWidget(GestisciComponentiPCBuilder);
        connect(GestisciComponentiPCBuilder->get_indietroPushButton(),SIGNAL(clicked()),this,SLOT(openIndexAdminPCBuilder()));
        connect(GestisciComponentiPCBuilder->get_aggiungi_PushButton(),SIGNAL(clicked()),controller,SLOT(aggiungi_componente()));
        connect(GestisciComponentiPCBuilder->get_rimuoviPushButton(),SIGNAL(clicked()),controller,SLOT(callRimuoviComponente()));
    }
    stackedWidget->setCurrentWidget(GestisciComponentiPCBuilder);
}

void MainWindow::openModificaProfiloUtentePCBuilder(){
    if (IndexUtentePremiumPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtentePremiumPCBuilder);
        delete IndexUtentePremiumPCBuilder;
        IndexUtentePremiumPCBuilder=0;
    }
    if (IndexUtenteRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteRegistratoPCBuilder);
        delete IndexUtenteRegistratoPCBuilder;
        IndexUtenteRegistratoPCBuilder=0;
    }
    if (!ModificaProfiloUtentePCBuilder)
    {
        ModificaProfiloUtentePCBuilder=new MyWidget_ModificaProfiloUtentePCBuilder(this);
        ModificaProfiloUtentePCBuilder->setMaximumSize(QSize(1024,600));
        stackedWidget->addWidget(ModificaProfiloUtentePCBuilder);
        connect(ModificaProfiloUtentePCBuilder->getModificaPushButton(),SIGNAL(clicked()),controller,SLOT(modificaProfiloUtente()));
        connect(ModificaProfiloUtentePCBuilder->getIndietroPushButton(),SIGNAL(clicked()),controller,SLOT(callShowIndex()));
        connect(ModificaProfiloUtentePCBuilder->getEliminaAccountPushButton(),SIGNAL(clicked()),controller,SLOT(deleteAccount()));
        connect(ModificaProfiloUtentePCBuilder->getDiventaPremiumPushButton(),SIGNAL(clicked()),controller,SLOT(upgradeAccount()));
    }
    stackedWidget->setCurrentWidget(ModificaProfiloUtentePCBuilder);
}

void MainWindow::openPartsListPCBuilder(const QString& comp){
    if (!PartsListPCBuilder)
    {
        PartsListPCBuilder=new MyWidget_PartsListPCBuilder(comp);
        connect(PartsListPCBuilder->getIndietroPushButton(),SIGNAL(clicked()),this,SLOT(openCreaConfPCBuilder()));
        connect(PartsListPCBuilder,SIGNAL(sendMessage(const QString&)),this,SLOT(updateConfigurazione(const QString&)));
        stackedWidget->addWidget(PartsListPCBuilder);
    }
    stackedWidget->setCurrentWidget(PartsListPCBuilder);
}

void MainWindow::closeEvent(QCloseEvent* event){
    emit closeMainWindow();
}

void MainWindow::updateConfigurazione(const QString& text){
    QStringList list=text.split("&");
    QString nome=list.at(0);
    QString prezzo=list.at(1);
    QString componente=list.at(2);

    if (componente=="Alimentatore")
    {
        CreaConfPCBuilder->setAlimentatorePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiAlimentatorePushButton());
        delete (CreaConfPCBuilder->getAggiungiAlimentatorePushButton());
        CreaConfPCBuilder->getAlimentatoreNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getAlimentatoreNomeLabel(),8,1,1,1);
    }
    if (componente=="Altoparlanti")
    {
        CreaConfPCBuilder->setAltoparlantiPrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiAltoparlantiPushButton());
        delete (CreaConfPCBuilder->getAggiungiAltoparlantiPushButton());
        CreaConfPCBuilder->getAltoparlantiNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getAltoparlantiNomeLabel(),15,1,1,1);
    }
    if (componente=="Archiviazione")
    {
        CreaConfPCBuilder->setArchiviazionePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiArchiviazionePushButton());
        delete (CreaConfPCBuilder->getAggiungiArchiviazionePushButton());
        CreaConfPCBuilder->getArchiviazioneNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getArchiviazioneNomeLabel(),5,1,1,1);
    }
    if (componente=="Case")
    {
        CreaConfPCBuilder->setCasePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiCasePushButton());
        delete (CreaConfPCBuilder->getAggiungiCasePushButton());
        CreaConfPCBuilder->getCaseNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getCaseNomeLabel(),7,1,1,1);
    }
    if (componente=="Processore")
    {
        CreaConfPCBuilder->setProcessorePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiProcessorePushButton());
        delete (CreaConfPCBuilder->getAggiungiProcessorePushButton());
        CreaConfPCBuilder->getProcessoreNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getProcessoreNomeLabel(),1,1,1,1);
    }
    if (componente=="Cuffie")
    {
        CreaConfPCBuilder->setCuffiePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiCuffiePushButton());
        delete (CreaConfPCBuilder->getAggiungiCuffiePushButton());
        CreaConfPCBuilder->getCuffieNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getCuffieNomeLabel(),14,1,1,1);
    }
    if (componente=="DissipatoreProcessore")
    {
        CreaConfPCBuilder->setDissipatoreProcessorePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiDissipatoreProcessorePushButton());
        delete (CreaConfPCBuilder->getAggiungiDissipatoreProcessorePushButton());
        CreaConfPCBuilder->getDissipatoreProcessoreNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getDissipatoreProcessoreNomeLabel(),2,1,1,1);
    }
    if (componente=="Memoria")
    {
        CreaConfPCBuilder->setMemoriaPrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiMemoriaPushButton());
        delete (CreaConfPCBuilder->getAggiungiMemoriaPushButton());
        CreaConfPCBuilder->getMemoriaNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getMemoriaNomeLabel(),4,1,1,1);
    }
    if (componente=="Monitor")
    {
        CreaConfPCBuilder->setMonitorPrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiMonitorPushButton());
        delete (CreaConfPCBuilder->getAggiungiMonitorPushButton());
        CreaConfPCBuilder->getMonitorNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getMonitorNomeLabel(),11,1,1,1);
    }
    if (componente=="Mouse")
    {
        CreaConfPCBuilder->setMousePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiMousePushButton());
        delete (CreaConfPCBuilder->getAggiungiMousePushButton());
        CreaConfPCBuilder->getMouseNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getMouseNomeLabel(),12,1,1,1);
    }
    if (componente=="SchedaGrafica")
    {
        CreaConfPCBuilder->setSchedaGraficaPrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiSchedaGraficaPushButton());
        delete (CreaConfPCBuilder->getAggiungiSchedaGraficaPushButton());
        CreaConfPCBuilder->getSchedaGraficaNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getSchedaGraficaNomeLabel(),6,1,1,1);
    }
    if (componente=="SchedaMadre")
    {
        CreaConfPCBuilder->setSchedaMadrePrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiSchedaMadrePushButton());
        delete (CreaConfPCBuilder->getAggiungiSchedaMadrePushButton());
        CreaConfPCBuilder->getSchedaMadreNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getSchedaMadreNomeLabel(),3,1,1,1);
    }
    if (componente=="SistemaOperativo")
    {
        CreaConfPCBuilder->setSistemaOperativoPrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiSistemaOperativoPushButton());
        delete (CreaConfPCBuilder->getAggiungiSistemaOperativoPushButton());
        CreaConfPCBuilder->getSistemaOperativoNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getSistemaOperativoNomeLabel(),10,1,1,1);
    }
    if (componente=="Tastiera")
    {
        CreaConfPCBuilder->setTastieraPrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiTastieraPushButton());
        delete (CreaConfPCBuilder->getAggiungiTastieraPushButton());
        CreaConfPCBuilder->getTastieraNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getTastieraNomeLabel(),13,1,1,1);
    }
    if (componente=="UnitaOttica")
    {
        CreaConfPCBuilder->setUnitaOtticaPrezzoLabel("€ "+(prezzo));
        CreaConfPCBuilder->getGridLayout()->removeWidget(CreaConfPCBuilder->getAggiungiUnitaOtticaPushButton());
        delete (CreaConfPCBuilder->getAggiungiUnitaOtticaPushButton());
        CreaConfPCBuilder->getUnitaOtticaNomeLabel()->setText(nome);
        CreaConfPCBuilder->getGridLayout()->addWidget(CreaConfPCBuilder->getUnitaOtticaNomeLabel(),9,1,1,1);
    }
    stackedWidget->removeWidget(PartsListPCBuilder);
    delete PartsListPCBuilder;
    PartsListPCBuilder=0;
    CreaConfPCBuilder->updateTotalePrezzo();
    stackedWidget->setCurrentWidget(CreaConfPCBuilder);
}

void MainWindow::resetConfigurazione(){
    stackedWidget->removeWidget(CreaConfPCBuilder);
    delete CreaConfPCBuilder;
    CreaConfPCBuilder=0;
    openCreaConfPCBuilder();
}

void MainWindow::openLoginPopUpPCBuilder(){
    LoginPopUpPCBuilder=new MyWidget_LoginPopUpPCBuilder;
    connect(LoginPopUpPCBuilder->get_accediPushButton(),SIGNAL(clicked()),controller,SLOT(eseguiAccessoPopUp()));
    connect(LoginPopUpPCBuilder,SIGNAL(closeLoginPopUpPCBuilder()),controller,SLOT(close_LoginPopUpPCBuilder()));
    LoginPopUpPCBuilder->setWindowFlags(Qt::WindowStaysOnTopHint);
    LoginPopUpPCBuilder->show();
}

void MainWindow::openLeMieConfigurazioniPCBuilder(){
    if (IndexUtenteRegistratoPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtenteRegistratoPCBuilder);
        delete IndexUtenteRegistratoPCBuilder;
        IndexUtenteRegistratoPCBuilder=0;
    }
    if (IndexUtentePremiumPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtentePremiumPCBuilder);
        delete IndexUtentePremiumPCBuilder;
        IndexUtentePremiumPCBuilder=0;
    }
    if (!LeMieConfigurazioniPCBuilder)
    {
        LeMieConfigurazioniPCBuilder=new MyWidget_LeMieConfigurazioniPCBuilder(this);
        connect(LeMieConfigurazioniPCBuilder->getIndietroPushButton(),SIGNAL(clicked()),controller,SLOT(callShowIndex()));
        connect(LeMieConfigurazioniPCBuilder,SIGNAL(sendMessage(const QString&)),controller,SLOT(editConfigurazione(const QString&)));
        stackedWidget->addWidget(LeMieConfigurazioniPCBuilder);
    }
    stackedWidget->setCurrentWidget(LeMieConfigurazioniPCBuilder);
}

void MainWindow::openCercaPartiPCBuilder(){
    if (IndexUtentePremiumPCBuilder)
    {
        stackedWidget->removeWidget(IndexUtentePremiumPCBuilder);
        delete IndexUtentePremiumPCBuilder;
        IndexUtentePremiumPCBuilder=0;
    }
    if (SpecificheComponentePCBuilder)
    {
        stackedWidget->removeWidget(SpecificheComponentePCBuilder);
        delete SpecificheComponentePCBuilder;
        SpecificheComponentePCBuilder=0;
    }
    if (!CercaPartiPCBuilder)
    {
        CercaPartiPCBuilder=new MyWidget_CercaPartiPCBuilder;
        connect(CercaPartiPCBuilder->getIndietroPushButton(),SIGNAL(clicked()),controller,SLOT(callShowIndex()));
        connect(CercaPartiPCBuilder,SIGNAL(sendMessage(const QString&)),this,SLOT(openSpecificheComponentePCBuilder(const QString&)));
        stackedWidget->addWidget(CercaPartiPCBuilder);
    }
    stackedWidget->setCurrentWidget(CercaPartiPCBuilder);
}

void MainWindow::openSpecificheComponentePCBuilder(const QString& componente){
    if (!SpecificheComponentePCBuilder)
    {
        SpecificheComponentePCBuilder=new MyWidget_SpecificheComponentePCBuilder(this,componente);
        connect(SpecificheComponentePCBuilder->getIndietroPushButton(),SIGNAL(clicked()),this,SLOT(openCercaPartiPCBuilder()));
        stackedWidget->addWidget(SpecificheComponentePCBuilder);
    }
    stackedWidget->setCurrentWidget(SpecificheComponentePCBuilder);
}
