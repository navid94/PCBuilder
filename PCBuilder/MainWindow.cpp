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
    ConfigurazionePCBuilder=0;

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

MyWidget_ConfigurazionePCBuilder* MainWindow::get_ConfigurazionePCBuilder() const{
    return ConfigurazionePCBuilder;
}

void MainWindow::set_PartsListPCBuilder(MyWidget_PartsListPCBuilder* p){
    PartsListPCBuilder=p;
}

void MainWindow::set_CreaConfPCBuilder(MyWidget_CreaConfPCBuilder* p){
    CreaConfPCBuilder=p;
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
        CreaConfPCBuilder=new MyWidget_CreaConfPCBuilder;
        stackedWidget->addWidget(CreaConfPCBuilder);
        connect(CreaConfPCBuilder->getIndietroPushButton(),SIGNAL(clicked()),controller,SLOT(callShowIndex()));
        connect(CreaConfPCBuilder,SIGNAL(sendMessage(const QString&)),this,SLOT(openPartsListPCBuilder(const QString&)));
        connect(CreaConfPCBuilder->getNuovaConfigurazionePushButton(),SIGNAL(clicked()),controller,SLOT(resetConfigurazione()));
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
        connect(GestisciComponentiPCBuilder->getTipo_componenteAggiungi(),SIGNAL(currentIndexChanged(const QString&)),controller,SLOT(callSetAddWidget(const QString&)));
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

void MainWindow::openPartsListPCBuilder(const QString& componente){
    if (!PartsListPCBuilder)
    {
        PartsListPCBuilder=new MyWidget_PartsListPCBuilder;
        connect(PartsListPCBuilder->getIndietroPushButton(),SIGNAL(clicked()),this,SLOT(openCreaConfPCBuilder()));
        connect(PartsListPCBuilder,SIGNAL(sendMessage(const QString&)),controller,SLOT(updateConfigurazione(const QString&)));
        stackedWidget->addWidget(PartsListPCBuilder);
        controller->populatePartsList(componente);
    }
    stackedWidget->setCurrentWidget(PartsListPCBuilder);
}

void MainWindow::openConfigurazionePCBuilder(const QString& nomeConfigurazione){
    if (!ConfigurazionePCBuilder)
    {
        ConfigurazionePCBuilder=new MyWidget_ConfigurazionePCBuilder;
        controller->createConfigurazioneView(nomeConfigurazione);
        connect(ConfigurazionePCBuilder->getIndietroPushButton(),SIGNAL(clicked()),this,SLOT(openLeMieConfigurazioniPCBuilder()));
        stackedWidget->addWidget(ConfigurazionePCBuilder);
    }
    stackedWidget->setCurrentWidget(ConfigurazionePCBuilder);
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
    if (ConfigurazionePCBuilder)
    {
        stackedWidget->removeWidget(ConfigurazionePCBuilder);
        delete ConfigurazionePCBuilder;
        ConfigurazionePCBuilder=0;
    }
    if (!LeMieConfigurazioniPCBuilder)
    {
        LeMieConfigurazioniPCBuilder=new MyWidget_LeMieConfigurazioniPCBuilder;
        connect(LeMieConfigurazioniPCBuilder->getIndietroPushButton(),SIGNAL(clicked()),controller,SLOT(callShowIndex()));
        connect(LeMieConfigurazioniPCBuilder,SIGNAL(sendViewMessage(const QString&)),this,SLOT(openConfigurazionePCBuilder(const QString&)));
        connect(LeMieConfigurazioniPCBuilder,SIGNAL(sendEditMessage(const QString&)),controller,SLOT(editConfigurazione(const QString&)));
        controller->populateConfigurazioneList();
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

void MainWindow::openSpecificheComponentePCBuilder(const QString& nomeComponente){
    if (!SpecificheComponentePCBuilder)
    {
        SpecificheComponentePCBuilder=new MyWidget_SpecificheComponentePCBuilder;
        connect(SpecificheComponentePCBuilder->getIndietroPushButton(),SIGNAL(clicked()),this,SLOT(openCercaPartiPCBuilder()));
        this->get_Controller()->callSetSpecsWidget(nomeComponente);
        stackedWidget->addWidget(SpecificheComponentePCBuilder);
    }
    stackedWidget->setCurrentWidget(SpecificheComponentePCBuilder);
}

void MainWindow::closeEvent(QCloseEvent* event){
    emit closeMainWindow();
}
