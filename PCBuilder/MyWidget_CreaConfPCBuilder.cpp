#include "MyWidget_CreaConfPCBuilder.h"


#include <iostream>
using namespace std;

MyWidget_CreaConfPCBuilder::MyWidget_CreaConfPCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createPushButtons();

    signalMapper=new QSignalMapper(this);
    connect(aggiungiAlimentatorePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiAltoparlantiPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiArchiviazionePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiCasePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiProcessorePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiCuffiePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiDissipatoreProcessorePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiMemoriaPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiMonitorPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiMousePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiSchedaGraficaPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiSchedaMadrePushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiSistemaOperativoPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiTastieraPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    connect(aggiungiUnitaOtticaPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(aggiungiAlimentatorePushButton,"Alimentatore");
    signalMapper->setMapping(aggiungiAltoparlantiPushButton,"Altoparlanti");
    signalMapper->setMapping(aggiungiArchiviazionePushButton,"Archiviazione");
    signalMapper->setMapping(aggiungiCasePushButton,"Case");
    signalMapper->setMapping(aggiungiProcessorePushButton,"Processore");
    signalMapper->setMapping(aggiungiCuffiePushButton,"Cuffie");
    signalMapper->setMapping(aggiungiDissipatoreProcessorePushButton,"DissipatoreProcessore");
    signalMapper->setMapping(aggiungiMemoriaPushButton,"Memoria");
    signalMapper->setMapping(aggiungiMonitorPushButton,"Monitor");
    signalMapper->setMapping(aggiungiMousePushButton,"Mouse");
    signalMapper->setMapping(aggiungiSchedaGraficaPushButton,"SchedaGrafica");
    signalMapper->setMapping(aggiungiSchedaMadrePushButton,"SchedaMadre");
    signalMapper->setMapping(aggiungiSistemaOperativoPushButton,"SistemaOperativo");
    signalMapper->setMapping(aggiungiTastieraPushButton,"Tastiera");
    signalMapper->setMapping(aggiungiUnitaOtticaPushButton,"UnitaOttica");
    connect(signalMapper,SIGNAL(mapped(const QString&)),this,SIGNAL(sendMessage(const QString&)));


    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    horizontalLayout1->setContentsMargins(0,0,0,50);

    QHBoxLayout* horizontalLayout2=new QHBoxLayout;

    QVBoxLayout* verticalLayout1=new QVBoxLayout;

    gridLayout=new QGridLayout;

    gridLayout->setContentsMargins(0,0,0,50);

    horizontalLayout1->addWidget(PCBuiler_creaconfLabel);

    gridLayout->addWidget(componenteLabel,0,0,1,1);
    gridLayout->addWidget(selezioneLabel,0,1,1,1);
    gridLayout->addWidget(prezzoLabel,0,2,1,1);
    gridLayout->addWidget(processoreLabel,1,0,1,1);
    gridLayout->addWidget(aggiungiProcessorePushButton,1,1,1,1);
    gridLayout->addWidget(processorePrezzoLabel,1,2,1,1);
    gridLayout->addWidget(dissipatoreProcessoreLabel,2,0,1,1);
    gridLayout->addWidget(aggiungiDissipatoreProcessorePushButton,2,1,1,1);
    gridLayout->addWidget(dissipatoreProcessorePrezzoLabel,2,2,1,1);
    gridLayout->addWidget(schedaMadreLabel,3,0,1,1);
    gridLayout->addWidget(aggiungiSchedaMadrePushButton,3,1,1,1);
    gridLayout->addWidget(schedaMadrePrezzoLabel,3,2,1,1);
    gridLayout->addWidget(memoriaLabel,4,0,1,1);
    gridLayout->addWidget(aggiungiMemoriaPushButton,4,1,1,1);
    gridLayout->addWidget(memoriaPrezzoLabel,4,2,1,1);
    gridLayout->addWidget(archiviazioneLabel,5,0,1,1);
    gridLayout->addWidget(aggiungiArchiviazionePushButton,5,1,1,1);
    gridLayout->addWidget(archiviazionePrezzoLabel,5,2,1,1);
    gridLayout->addWidget(schedaGraficaLabel,6,0,1,1);
    gridLayout->addWidget(aggiungiSchedaGraficaPushButton,6,1,1,1);
    gridLayout->addWidget(schedaGraficaPrezzoLabel,6,2,1,1);
    gridLayout->addWidget(caseLabel,7,0,1,1);
    gridLayout->addWidget(aggiungiCasePushButton,7,1,1,1);
    gridLayout->addWidget(casePrezzoLabel,7,2,1,1);
    gridLayout->addWidget(alimentatoreLabel,8,0,1,1);
    gridLayout->addWidget(aggiungiAlimentatorePushButton,8,1,1,1);
    gridLayout->addWidget(alimentatorePrezzoLabel,8,2,1,1);
    gridLayout->addWidget(unitaOtticaLabel,9,0,1,1);
    gridLayout->addWidget(aggiungiUnitaOtticaPushButton,9,1,1,1);
    gridLayout->addWidget(unitaOtticaPrezzoLabel,9,2,1,1);
    gridLayout->addWidget(sistemaOperativoLabel,10,0,1,1);
    gridLayout->addWidget(aggiungiSistemaOperativoPushButton,10,1,1,1);
    gridLayout->addWidget(sistemaOperativoPrezzoLabel,10,2,1,1);
    gridLayout->addWidget(monitorLabel,11,0,1,1);
    gridLayout->addWidget(aggiungiMonitorPushButton,11,1,1,1);
    gridLayout->addWidget(monitorPrezzoLabel,11,2,1,1);
    gridLayout->addWidget(mouseLabel,12,0,1,1);
    gridLayout->addWidget(aggiungiMousePushButton,12,1,1,1);
    gridLayout->addWidget(mousePrezzoLabel,12,2,1,1);
    gridLayout->addWidget(tastieraLabel,13,0,1,1);
    gridLayout->addWidget(aggiungiTastieraPushButton,13,1,1,1);
    gridLayout->addWidget(tastieraPrezzoLabel,13,2,1,1);
    gridLayout->addWidget(cuffieLabel,14,0,1,1);
    gridLayout->addWidget(aggiungiCuffiePushButton,14,1,1,1);
    gridLayout->addWidget(cuffiePrezzoLabel,14,2,1,1);
    gridLayout->addWidget(altoparlantiLabel,15,0,1,1);
    gridLayout->addWidget(aggiungiAltoparlantiPushButton,15,1,1,1);
    gridLayout->addWidget(altoparlantiPrezzoLabel,15,2,1,1);
    gridLayout->addWidget(totaleLabel,16,0,1,1);
    gridLayout->addWidget(prezzoTotaleLabel,16,1,1,2);

    horizontalLayout2->addWidget(indietroPushButton);
    horizontalLayout2->addWidget(nuovaConfigurazionePushButton);
    horizontalLayout2->addWidget(salvaConfigurazionePushButton);

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(gridLayout);
    verticalLayout1->addLayout(horizontalLayout2);

    setLayout(verticalLayout1);
}

void MyWidget_CreaConfPCBuilder::updateTotalePrezzo(){
    double tot=0;
    QString processorePrezzo=processorePrezzoLabel->text();
    QString dissipatoreProcessorePrezzo=dissipatoreProcessorePrezzoLabel->text();
    QString schedaMadrePrezzo=schedaMadrePrezzoLabel->text();
    QString memoriaPrezzo=memoriaPrezzoLabel->text();
    QString archiviazionePrezzo=archiviazionePrezzoLabel->text();
    QString schedaGraficaPrezzo=schedaGraficaPrezzoLabel->text();
    QString casePrezzo=casePrezzoLabel->text();
    QString alimentatorePrezzo=alimentatorePrezzoLabel->text();
    QString unitaOtticaPrezzo=unitaOtticaPrezzoLabel->text();
    QString sistemaOperativoPrezzo=sistemaOperativoPrezzoLabel->text();
    QString monitorPrezzo=monitorPrezzoLabel->text();
    QString mousePrezzo=mousePrezzoLabel->text();
    QString tastieraPrezzo=tastieraPrezzoLabel->text();
    QString cuffiePrezzo=cuffiePrezzoLabel->text();
    QString altoparlantiPrezzo=altoparlantiPrezzoLabel->text();

    if (processorePrezzo!="")
    {
        processorePrezzo.remove("€ ");
        tot=tot+processorePrezzo.toDouble();
    }
    if (dissipatoreProcessorePrezzo!="")
    {
        dissipatoreProcessorePrezzo.remove("€ ");
        tot=tot+dissipatoreProcessorePrezzo.toDouble();
    }
    if (schedaMadrePrezzo!="")
    {
        schedaMadrePrezzo.remove("€ ");
        tot=tot+schedaMadrePrezzo.toDouble();
    }
    if (memoriaPrezzo!="")
    {
        memoriaPrezzo.remove("€ ");
        tot=tot+memoriaPrezzo.toDouble();
    }
    if (archiviazionePrezzo!="")
    {
        archiviazionePrezzo.remove("€ ");
        tot=tot+archiviazionePrezzo.toDouble();
    }
    if (schedaGraficaPrezzo!="")
    {
        schedaGraficaPrezzo.remove("€ ");
        tot=tot+schedaGraficaPrezzo.toDouble();
    }
    if (casePrezzo!="")
    {
        casePrezzo.remove("€ ");
        tot=tot+casePrezzo.toDouble();
    }
    if (alimentatorePrezzo!="")
    {
        alimentatorePrezzo.remove("€ ");
        tot=tot+alimentatorePrezzo.toDouble();
    }
    if (unitaOtticaPrezzo!="")
    {
        unitaOtticaPrezzo.remove("€ ");
        tot=tot+unitaOtticaPrezzo.toDouble();
    }
    if (sistemaOperativoPrezzo!="")
    {
        sistemaOperativoPrezzo.remove("€ ");
        tot=tot+sistemaOperativoPrezzo.toDouble();
    }
    if (monitorPrezzo!="")
    {
        monitorPrezzo.remove("€ ");
        tot=tot+monitorPrezzo.toDouble();
    }
    if (mousePrezzo!="")
    {
        mousePrezzo.remove("€ ");
        tot=tot+mousePrezzo.toDouble();
    }
    if (tastieraPrezzo!="")
    {
        tastieraPrezzo.remove("€ ");
        tot=tot+tastieraPrezzo.toDouble();
    }
    if (cuffiePrezzo!="")
    {
        cuffiePrezzo.remove("€ ");
        tot=tot+cuffiePrezzo.toDouble();
    }
    if (altoparlantiPrezzo!="")
    {
        altoparlantiPrezzo.remove("€ ");
        tot=tot+altoparlantiPrezzo.toDouble();
    }
    prezzoTotaleLabel->setText("€ "+(QString::number(tot)));
}

void MyWidget_CreaConfPCBuilder::createLabels(){
    PCBuiler_creaconfLabel=new QLabel("PCBuilder - "+(tr("Crea la tua configurazione")));
    QFont font_PCBuilder_creaconfLabel=PCBuiler_creaconfLabel->font();
    font_PCBuilder_creaconfLabel.setPointSize(24);
    PCBuiler_creaconfLabel->setFont(font_PCBuilder_creaconfLabel);
    PCBuiler_creaconfLabel->setMaximumSize(QSize(620,40));
    PCBuiler_creaconfLabel->setMinimumSize(QSize(0,0));

    QFont font_headerFormLabel;
    font_headerFormLabel.setPointSize(18);

    componenteLabel=new QLabel(tr("Componente"));
    componenteLabel->setFont(font_headerFormLabel);
    componenteLabel->setMaximumSize(QSize(160,30));
    componenteLabel->setMinimumSize(QSize(0,0));

    selezioneLabel=new QLabel(tr("Selezione"));
    selezioneLabel->setFont(font_headerFormLabel);
    selezioneLabel->setMaximumSize(QSize(120,30));
    selezioneLabel->setMinimumSize(QSize(0,0));

    prezzoLabel=new QLabel(tr("Prezzo"));
    prezzoLabel->setFont(font_headerFormLabel);
    prezzoLabel->setMaximumSize(QSize(80,30));
    prezzoLabel->setMinimumSize(QSize(0,0));

    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    processoreLabel=new QLabel("Processore");
    processoreLabel->setFont(font_formLabel);
    processoreLabel->setMaximumSize(QSize(110,30));
    processoreLabel->setMinimumSize(QSize(0,0));

    dissipatoreProcessoreLabel=new QLabel(tr("Dissipatore processore"));
    dissipatoreProcessoreLabel->setFont(font_formLabel);
    dissipatoreProcessoreLabel->setMaximumSize(QSize(220,30));
    dissipatoreProcessoreLabel->setMinimumSize(QSize(0,0));

    schedaMadreLabel=new QLabel(tr("Scheda madre"));
    schedaMadreLabel->setFont(font_formLabel);
    schedaMadreLabel->setMaximumSize(QSize(140,30));
    schedaMadreLabel->setMinimumSize(QSize(0,0));

    memoriaLabel=new QLabel(tr("Memoria"));
    memoriaLabel->setFont(font_formLabel);
    memoriaLabel->setMaximumSize(QSize(90,30));
    memoriaLabel->setMinimumSize(QSize(0,0));

    archiviazioneLabel=new QLabel(tr("Archiviazione"));
    archiviazioneLabel->setFont(font_formLabel);
    archiviazioneLabel->setMaximumSize(QSize(130,30));
    archiviazioneLabel->setMinimumSize(QSize(0,0));

    schedaGraficaLabel=new QLabel(tr("Scheda grafica"));
    schedaGraficaLabel->setFont(font_formLabel);
    schedaGraficaLabel->setMaximumSize(QSize(140,30));
    schedaGraficaLabel->setMinimumSize(QSize(0,0));

    caseLabel=new QLabel("Case");
    caseLabel->setFont(font_formLabel);
    caseLabel->setMaximumSize(QSize(50,30));
    caseLabel->setMinimumSize(QSize(0,0));

    alimentatoreLabel=new QLabel(tr("Alimentatore"));
    alimentatoreLabel->setFont(font_formLabel);
    alimentatoreLabel->setMaximumSize(QSize(130,30));
    alimentatoreLabel->setMinimumSize(QSize(0,0));

    unitaOtticaLabel=new QLabel(tr("Unità ottica"));
    unitaOtticaLabel->setFont(font_formLabel);
    unitaOtticaLabel->setMaximumSize(QSize(110,30));
    unitaOtticaLabel->setMinimumSize(QSize(0,0));

    sistemaOperativoLabel=new QLabel(tr("Sistema operativo"));
    sistemaOperativoLabel->setFont(font_formLabel);
    sistemaOperativoLabel->setMaximumSize(QSize(180,30));
    sistemaOperativoLabel->setMinimumSize(QSize(0,0));

    monitorLabel=new QLabel("Monitor");
    monitorLabel->setFont(font_formLabel);
    monitorLabel->setMaximumSize(QSize(80,30));
    monitorLabel->setMinimumSize(QSize(0,0));

    mouseLabel=new QLabel("Mouse");
    mouseLabel->setFont(font_formLabel);
    mouseLabel->setMaximumSize(QSize(70,30));
    mouseLabel->setMinimumSize(QSize(0,0));

    tastieraLabel=new QLabel(tr("Tastiera"));
    tastieraLabel->setFont(font_formLabel);
    tastieraLabel->setMaximumSize(QSize(80,30));
    tastieraLabel->setMinimumSize(QSize(0,0));

    cuffieLabel=new QLabel(tr("Cuffie"));
    cuffieLabel->setFont(font_formLabel);
    cuffieLabel->setMaximumSize(QSize(70,30));
    cuffieLabel->setMinimumSize(QSize(0,0));

    altoparlantiLabel=new QLabel(tr("Altoparlanti"));
    altoparlantiLabel->setFont(font_formLabel);
    altoparlantiLabel->setMaximumSize(QSize(120,30));
    altoparlantiLabel->setMinimumSize(QSize(0,0));

    processorePrezzoLabel=new QLabel("");
    processorePrezzoLabel->setFont(font_formLabel);
    processorePrezzoLabel->setMaximumSize(QSize(150,30));
    processorePrezzoLabel->setMinimumSize(QSize(0,0));

    dissipatoreProcessorePrezzoLabel=new QLabel("");
    dissipatoreProcessorePrezzoLabel->setFont(font_formLabel);
    dissipatoreProcessorePrezzoLabel->setMaximumSize(QSize(150,30));
    dissipatoreProcessorePrezzoLabel->setMinimumSize(QSize(0,0));

    schedaMadrePrezzoLabel=new QLabel("");
    schedaMadrePrezzoLabel->setFont(font_formLabel);
    schedaMadrePrezzoLabel->setMaximumSize(QSize(150,30));
    schedaMadrePrezzoLabel->setMinimumSize(QSize(0,0));

    memoriaPrezzoLabel=new QLabel("");
    memoriaPrezzoLabel->setFont(font_formLabel);
    memoriaPrezzoLabel->setMaximumSize(QSize(150,30));
    memoriaPrezzoLabel->setMinimumSize(QSize(0,0));

    archiviazionePrezzoLabel=new QLabel("");
    archiviazionePrezzoLabel->setFont(font_formLabel);
    archiviazionePrezzoLabel->setMaximumSize(QSize(150,30));
    archiviazionePrezzoLabel->setMinimumSize(QSize(0,0));

    schedaGraficaPrezzoLabel=new QLabel("");
    schedaGraficaPrezzoLabel->setFont(font_formLabel);
    schedaGraficaPrezzoLabel->setMaximumSize(QSize(150,30));
    schedaGraficaPrezzoLabel->setMinimumSize(QSize(0,0));

    casePrezzoLabel=new QLabel("");
    casePrezzoLabel->setFont(font_formLabel);
    casePrezzoLabel->setMaximumSize(QSize(150,30));
    casePrezzoLabel->setMinimumSize(QSize(0,0));

    alimentatorePrezzoLabel=new QLabel("");
    alimentatorePrezzoLabel->setFont(font_formLabel);
    alimentatorePrezzoLabel->setMaximumSize(QSize(150,30));
    alimentatorePrezzoLabel->setMinimumSize(QSize(0,0));

    unitaOtticaPrezzoLabel=new QLabel("");
    unitaOtticaPrezzoLabel->setFont(font_formLabel);
    unitaOtticaPrezzoLabel->setMaximumSize(QSize(150,30));
    unitaOtticaPrezzoLabel->setMinimumSize(QSize(0,0));

    sistemaOperativoPrezzoLabel=new QLabel("");
    sistemaOperativoPrezzoLabel->setFont(font_formLabel);
    sistemaOperativoPrezzoLabel->setMaximumSize(QSize(150,30));
    sistemaOperativoPrezzoLabel->setMinimumSize(QSize(0,0));

    monitorPrezzoLabel=new QLabel("");
    monitorPrezzoLabel->setFont(font_formLabel);
    monitorPrezzoLabel->setMaximumSize(QSize(150,30));
    monitorPrezzoLabel->setMinimumSize(QSize(0,0));

    mousePrezzoLabel=new QLabel("");
    mousePrezzoLabel->setFont(font_formLabel);
    mousePrezzoLabel->setMaximumSize(QSize(150,30));
    mousePrezzoLabel->setMinimumSize(QSize(0,0));

    tastieraPrezzoLabel=new QLabel("");
    tastieraPrezzoLabel->setFont(font_formLabel);
    tastieraPrezzoLabel->setMaximumSize(QSize(150,30));
    tastieraPrezzoLabel->setMinimumSize(QSize(0,0));

    cuffiePrezzoLabel=new QLabel("");
    cuffiePrezzoLabel->setFont(font_formLabel);
    cuffiePrezzoLabel->setMaximumSize(QSize(150,30));
    cuffiePrezzoLabel->setMinimumSize(QSize(0,0));

    altoparlantiPrezzoLabel=new QLabel("");
    altoparlantiPrezzoLabel->setFont(font_formLabel);
    altoparlantiPrezzoLabel->setMaximumSize(QSize(150,30));
    altoparlantiPrezzoLabel->setMinimumSize(QSize(0,0));

    totaleLabel=new QLabel(tr("Totale"));
    totaleLabel->setFont(font_headerFormLabel);
    totaleLabel->setMaximumSize(QSize(70,30));
    totaleLabel->setMinimumSize(QSize(0,0));

    prezzoTotaleLabel=new QLabel("");
    prezzoTotaleLabel->setFont(font_formLabel);
    prezzoTotaleLabel->setMaximumSize(QSize(150,30));
    prezzoTotaleLabel->setMinimumSize(QSize(0,0));

    processoreNomeLabel=new QLabel("");
    processoreNomeLabel->setFont(font_formLabel);
    processoreNomeLabel->setMaximumHeight(30);
    processoreNomeLabel->setMinimumSize(QSize(0,0));
    dissipatoreProcessoreNomeLabel=new QLabel("");
    dissipatoreProcessoreNomeLabel->setFont(font_formLabel);
    dissipatoreProcessoreNomeLabel->setMaximumHeight(30);
    dissipatoreProcessoreNomeLabel->setMinimumSize(QSize(0,0));
    schedaMadreNomeLabel=new QLabel("");
    schedaMadreNomeLabel->setFont(font_formLabel);
    schedaMadreNomeLabel->setMaximumHeight(30);
    schedaMadreNomeLabel->setMinimumSize(QSize(0,0));
    memoriaNomeLabel=new QLabel("");
    memoriaNomeLabel->setFont(font_formLabel);
    memoriaNomeLabel->setMaximumHeight(30);
    memoriaNomeLabel->setMinimumSize(QSize(0,0));
    archiviazioneNomeLabel=new QLabel("");
    archiviazioneNomeLabel->setFont(font_formLabel);
    archiviazioneNomeLabel->setMaximumHeight(30);
    archiviazioneNomeLabel->setMinimumSize(QSize(0,0));
    schedaGraficaNomeLabel=new QLabel("");
    schedaGraficaNomeLabel->setFont(font_formLabel);
    schedaGraficaNomeLabel->setMaximumHeight(30);
    schedaGraficaNomeLabel->setMinimumSize(QSize(0,0));
    caseNomeLabel=new QLabel("");
    caseNomeLabel->setFont(font_formLabel);
    caseNomeLabel->setMaximumHeight(30);
    caseNomeLabel->setMinimumSize(QSize(0,0));
    alimentatoreNomeLabel=new QLabel("");
    alimentatoreNomeLabel->setFont(font_formLabel);
    alimentatoreNomeLabel->setMaximumHeight(30);
    alimentatoreNomeLabel->setMinimumSize(QSize(0,0));
    unitaOtticaNomeLabel=new QLabel("");
    unitaOtticaNomeLabel->setFont(font_formLabel);
    unitaOtticaNomeLabel->setMaximumHeight(30);
    unitaOtticaNomeLabel->setMinimumSize(QSize(0,0));
    sistemaOperativoNomeLabel=new QLabel("");
    sistemaOperativoNomeLabel->setFont(font_formLabel);
    sistemaOperativoNomeLabel->setMaximumHeight(30);
    sistemaOperativoNomeLabel->setMinimumSize(QSize(0,0));
    monitorNomeLabel=new QLabel("");
    monitorNomeLabel->setFont(font_formLabel);
    monitorNomeLabel->setMaximumHeight(30);
    monitorNomeLabel->setMinimumSize(QSize(0,0));
    mouseNomeLabel=new QLabel("");
    mouseNomeLabel->setFont(font_formLabel);
    mouseNomeLabel->setMaximumHeight(30);
    mouseNomeLabel->setMinimumSize(QSize(0,0));
    tastieraNomeLabel=new QLabel("");
    tastieraNomeLabel->setFont(font_formLabel);
    tastieraNomeLabel->setMaximumHeight(30);
    tastieraNomeLabel->setMinimumSize(QSize(0,0));
    cuffieNomeLabel=new QLabel("");
    cuffieNomeLabel->setFont(font_formLabel);
    cuffieNomeLabel->setMaximumHeight(30);
    cuffieNomeLabel->setMinimumSize(QSize(0,0));
    altoparlantiNomeLabel=new QLabel("");
    altoparlantiNomeLabel->setFont(font_formLabel);
    altoparlantiNomeLabel->setMaximumHeight(30);
    altoparlantiNomeLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_CreaConfPCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(250,50));
    indietroPushButton->setMinimumSize(QSize(0,0));

    salvaConfigurazionePushButton=new QPushButton(tr("Salva la configurazione"));
    salvaConfigurazionePushButton->setMaximumSize(QSize(250,50));
    salvaConfigurazionePushButton->setMinimumSize(QSize(0,0));

    nuovaConfigurazionePushButton=new QPushButton(tr("Nuova configurazione"));
    nuovaConfigurazionePushButton->setMaximumSize(QSize(250,50));
    nuovaConfigurazionePushButton->setMinimumSize(QSize(0,0));

    aggiungiProcessorePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiProcessorePushButton->setMaximumSize(QSize(100,30));
    aggiungiProcessorePushButton->setMinimumSize(QSize(0,0));

    aggiungiDissipatoreProcessorePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiDissipatoreProcessorePushButton->setMaximumSize(QSize(100,30));
    aggiungiDissipatoreProcessorePushButton->setMinimumSize(QSize(0,0));

    aggiungiSchedaMadrePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiSchedaMadrePushButton->setMaximumSize(QSize(100,30));
    aggiungiSchedaMadrePushButton->setMinimumSize(QSize(0,0));

    aggiungiMemoriaPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiMemoriaPushButton->setMaximumSize(QSize(100,30));
    aggiungiMemoriaPushButton->setMinimumSize(QSize(0,0));

    aggiungiArchiviazionePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiArchiviazionePushButton->setMaximumSize(QSize(100,30));
    aggiungiArchiviazionePushButton->setMinimumSize(QSize(0,0));

    aggiungiSchedaGraficaPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiSchedaGraficaPushButton->setMaximumSize(QSize(100,30));
    aggiungiSchedaGraficaPushButton->setMinimumSize(QSize(0,0));

    aggiungiCasePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiCasePushButton->setMaximumSize(QSize(100,30));
    aggiungiCasePushButton->setMinimumSize(QSize(0,0));

    aggiungiAlimentatorePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiAlimentatorePushButton->setMaximumSize(QSize(100,30));
    aggiungiAlimentatorePushButton->setMinimumSize(QSize(0,0));

    aggiungiUnitaOtticaPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiUnitaOtticaPushButton->setMaximumSize(QSize(100,30));
    aggiungiUnitaOtticaPushButton->setMinimumSize(QSize(0,0));

    aggiungiSistemaOperativoPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiSistemaOperativoPushButton->setMaximumSize(QSize(100,30));
    aggiungiSistemaOperativoPushButton->setMinimumSize(QSize(0,0));

    aggiungiMonitorPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiMonitorPushButton->setMaximumSize(QSize(100,30));
    aggiungiMonitorPushButton->setMinimumSize(QSize(0,0));

    aggiungiMousePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiMousePushButton->setMaximumSize(QSize(100,30));
    aggiungiMousePushButton->setMinimumSize(QSize(0,0));

    aggiungiTastieraPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiTastieraPushButton->setMaximumSize(QSize(100,30));
    aggiungiTastieraPushButton->setMinimumSize(QSize(0,0));

    aggiungiCuffiePushButton=new QPushButton(tr("Aggiungi"));
    aggiungiCuffiePushButton->setMaximumSize(QSize(100,30));
    aggiungiCuffiePushButton->setMinimumSize(QSize(0,0));

    aggiungiAltoparlantiPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiAltoparlantiPushButton->setMaximumSize(QSize(100,30));
    aggiungiAltoparlantiPushButton->setMinimumSize(QSize(0,0));
}

QGridLayout* MyWidget_CreaConfPCBuilder::getGridLayout() const{
    return gridLayout;
}

QPushButton* MyWidget_CreaConfPCBuilder::getIndietroPushButton() const{
    return indietroPushButton;
}

QPushButton*  MyWidget_CreaConfPCBuilder::getSalvaConfigurazionePushButton() const{
    return salvaConfigurazionePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getNuovaConfigurazionePushButton() const{
    return nuovaConfigurazionePushButton;
}

QPushButton*  MyWidget_CreaConfPCBuilder::getAggiungiProcessorePushButton() const{
    return aggiungiProcessorePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiDissipatoreProcessorePushButton() const{
    return aggiungiDissipatoreProcessorePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiSchedaMadrePushButton() const{
    return aggiungiSchedaMadrePushButton;
}

QPushButton*  MyWidget_CreaConfPCBuilder::getAggiungiMemoriaPushButton() const{
    return aggiungiMemoriaPushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiArchiviazionePushButton() const{
    return aggiungiArchiviazionePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiSchedaGraficaPushButton() const{
    return aggiungiSchedaGraficaPushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiCasePushButton() const{
    return aggiungiCasePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiAlimentatorePushButton() const{
    return aggiungiAlimentatorePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiUnitaOtticaPushButton() const{
    return aggiungiUnitaOtticaPushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiSistemaOperativoPushButton() const{
    return aggiungiSistemaOperativoPushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiMonitorPushButton() const{
    return aggiungiMonitorPushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiMousePushButton() const{
    return aggiungiMousePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiTastieraPushButton() const{
    return aggiungiTastieraPushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiCuffiePushButton() const{
    return aggiungiCuffiePushButton;
}

QPushButton* MyWidget_CreaConfPCBuilder::getAggiungiAltoparlantiPushButton() const{
    return aggiungiAltoparlantiPushButton;
}

QLabel* MyWidget_CreaConfPCBuilder::getProcessoreNomeLabel() const{
    return processoreNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getDissipatoreProcessoreNomeLabel() const{
    return dissipatoreProcessoreNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getSchedaMadreNomeLabel() const{
    return schedaMadreNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getMemoriaNomeLabel() const{
    return memoriaNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getArchiviazioneNomeLabel() const{
    return archiviazioneNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getSchedaGraficaNomeLabel() const{
    return schedaGraficaNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getCaseNomeLabel() const{
    return caseNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getAlimentatoreNomeLabel() const{
    return alimentatoreNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getUnitaOtticaNomeLabel() const{
    return unitaOtticaNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getSistemaOperativoNomeLabel() const{
    return sistemaOperativoNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getMonitorNomeLabel() const{
    return monitorNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getMouseNomeLabel() const{
    return mouseNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getTastieraNomeLabel() const{
    return tastieraNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getCuffieNomeLabel() const{
    return cuffieNomeLabel;
}

QLabel* MyWidget_CreaConfPCBuilder::getAltoparlantiNomeLabel() const{
    return altoparlantiNomeLabel;
}

void MyWidget_CreaConfPCBuilder::setProcessorePrezzoLabel(const QString& prezzo){
    processorePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setDissipatoreProcessorePrezzoLabel(const QString& prezzo){
    dissipatoreProcessorePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setSchedaMadrePrezzoLabel(const QString& prezzo){
    schedaMadrePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setMemoriaPrezzoLabel(const QString& prezzo){
    memoriaPrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setArchiviazionePrezzoLabel(const QString& prezzo){
    archiviazionePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setSchedaGraficaPrezzoLabel(const QString& prezzo){
    schedaGraficaPrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setCasePrezzoLabel(const QString& prezzo){
    casePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setAlimentatorePrezzoLabel(const QString& prezzo){
    alimentatorePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setUnitaOtticaPrezzoLabel(const QString& prezzo){
    unitaOtticaPrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setSistemaOperativoPrezzoLabel(const QString& prezzo){
    sistemaOperativoPrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setMonitorPrezzoLabel(const QString& prezzo){
    monitorPrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setMousePrezzoLabel(const QString& prezzo){
    mousePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setTastieraPrezzoLabel(const QString& prezzo){
    tastieraPrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setCuffiePrezzoLabel(const QString& prezzo){
    cuffiePrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setAltoparlantiPrezzoLabel(const QString& prezzo){
    altoparlantiPrezzoLabel->setText(prezzo);
}

void MyWidget_CreaConfPCBuilder::setPrezzoTotaleLabel(const QString& prezzoTotale){
    prezzoTotaleLabel->setText(prezzoTotale);
}
