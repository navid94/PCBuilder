#include "MyWidget_GestisciComponentiPCBuilder.h"

#include <QLayout>
#include <QFont>

MyWidget_GestisciComponentiPCBuilder::MyWidget_GestisciComponentiPCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createPushButtons();
    createLineEdits();
    createCheckBoxes();
    createComboBoxes();
    createSpinBoxes();
    createDoubleSpinBoxes();

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout4=new QHBoxLayout;
    QHBoxLayout* horizontalLayout5=new QHBoxLayout;
    QHBoxLayout* horizontalLayout7=new QHBoxLayout;
    QHBoxLayout* horizontalLayout9=new QHBoxLayout;

    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QVBoxLayout* verticalLayout3=new QVBoxLayout;
    QVBoxLayout* verticalLayout5=new QVBoxLayout;
    QVBoxLayout* verticalLayout6=new QVBoxLayout;

    aggiungi_stackedWidget=new QStackedWidget;

    aggiungi_emptyPage=new QWidget();
    aggiungi_memoriaPage=new QWidget();
    aggiungi_schedaGraficaPage=new QWidget();
    aggiungi_schedaMadrePage=new QWidget();
    aggiungi_processorePage=new QWidget();
    aggiungi_archiviazionePage=new QWidget();
    aggiungi_alimentatorePage=new QWidget();
    aggiungi_dissipatoreProcessorePage=new QWidget();
    aggiungi_casePage=new QWidget();
    aggiungi_unitaOtticaPage=new QWidget();
    aggiungi_monitorPage=new QWidget();
    aggiungi_sistemaOperativoPage=new QWidget();
    aggiungi_mousePage=new QWidget();
    aggiungi_tastieraPage=new QWidget();
    aggiungi_cuffiePage=new QWidget();
    aggiungi_altoparlantiPage=new QWidget();


    aggiungi_stackedWidget->addWidget(aggiungi_emptyPage);
    aggiungi_stackedWidget->addWidget(aggiungi_memoriaPage);
    aggiungi_stackedWidget->addWidget(aggiungi_schedaGraficaPage);
    aggiungi_stackedWidget->addWidget(aggiungi_schedaMadrePage);
    aggiungi_stackedWidget->addWidget(aggiungi_processorePage);
    aggiungi_stackedWidget->addWidget(aggiungi_archiviazionePage);
    aggiungi_stackedWidget->addWidget(aggiungi_alimentatorePage);
    aggiungi_stackedWidget->addWidget(aggiungi_dissipatoreProcessorePage);
    aggiungi_stackedWidget->addWidget(aggiungi_casePage);
    aggiungi_stackedWidget->addWidget(aggiungi_unitaOtticaPage);
    aggiungi_stackedWidget->addWidget(aggiungi_monitorPage);
    aggiungi_stackedWidget->addWidget(aggiungi_sistemaOperativoPage);
    aggiungi_stackedWidget->addWidget(aggiungi_mousePage);
    aggiungi_stackedWidget->addWidget(aggiungi_tastieraPage);
    aggiungi_stackedWidget->addWidget(aggiungi_cuffiePage);
    aggiungi_stackedWidget->addWidget(aggiungi_altoparlantiPage);


    QGridLayout* aggiungi_gridLayout1=new QGridLayout(aggiungi_memoriaPage);
    QGridLayout* aggiungi_gridLayout2=new QGridLayout(aggiungi_schedaGraficaPage);
    QGridLayout* aggiungi_gridLayout3=new QGridLayout(aggiungi_schedaMadrePage);
    QGridLayout* aggiungi_gridLayout4=new QGridLayout(aggiungi_processorePage);
    QGridLayout* aggiungi_gridLayout5=new QGridLayout(aggiungi_archiviazionePage);
    QGridLayout* aggiungi_gridLayout6=new QGridLayout(aggiungi_alimentatorePage);
    QGridLayout* aggiungi_gridLayout7=new QGridLayout(aggiungi_dissipatoreProcessorePage);
    QGridLayout* aggiungi_gridLayout8=new QGridLayout(aggiungi_casePage);
    QGridLayout* aggiungi_gridLayout9=new QGridLayout(aggiungi_unitaOtticaPage);
    QGridLayout* aggiungi_gridLayout10=new QGridLayout(aggiungi_monitorPage);
    QGridLayout* aggiungi_gridLayout11=new QGridLayout(aggiungi_sistemaOperativoPage);
    QGridLayout* aggiungi_gridLayout12=new QGridLayout(aggiungi_mousePage);
    QGridLayout* aggiungi_gridLayout13=new QGridLayout(aggiungi_tastieraPage);
    QGridLayout* aggiungi_gridLayout14=new QGridLayout(aggiungi_cuffiePage);
    QGridLayout* aggiungi_gridLayout15=new QGridLayout(aggiungi_altoparlantiPage);

    aggiungi_stackedWidget->setCurrentIndex(0);

    //horizontalLayout1->setContentsMargins(0,50,0,0);
    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_Gestione_componentiLabel);

    horizontalLayout2->setContentsMargins(0,20,0,10);
    horizontalLayout2->addWidget(rimuovi_componenteLabel);
    horizontalLayout2->addWidget(rimuoviComponenteLineEdit);
    horizontalLayout2->addWidget(rimuoviPushButton);

    horizontalLayout4->addWidget(aggiungiPushButton);

    horizontalLayout5->setContentsMargins(0,0,0,25);
    horizontalLayout5->addWidget(tipo_componenteAggiungi);

    horizontalLayout7->setContentsMargins(0,25,0,0);
    horizontalLayout7->addWidget(aggiungi_componenteLabel);


    verticalLayout1->addLayout(horizontalLayout7);
    verticalLayout1->addLayout(horizontalLayout5);

    verticalLayout6->addWidget(aggiungi_stackedWidget);

    verticalLayout3->addLayout(verticalLayout1);
    verticalLayout3->addLayout(verticalLayout6);
    verticalLayout3->addLayout(horizontalLayout4);

    horizontalLayout9->addLayout(verticalLayout3);

    verticalLayout5->addLayout(horizontalLayout1);
    verticalLayout5->addLayout(horizontalLayout9);
    verticalLayout5->addLayout(horizontalLayout2);



    //Memoria
    aggiungi_gridLayout1->addWidget(nomeLabelMemoria,0,0,1,1);
    aggiungi_gridLayout1->addWidget(nomeLineEditMemoria,0,1,1,1);
    aggiungi_gridLayout1->addWidget(prezzoLabelMemoria,1,0,1,1);
    aggiungi_gridLayout1->addWidget(prezzoDoubleSpinBoxMemoria,1,1,1,1);
    aggiungi_gridLayout1->addWidget(produttoreLabelMemoria,2,0,1,1);
    aggiungi_gridLayout1->addWidget(produttoreLineEditMemoria,2,1,1,1);
    aggiungi_gridLayout1->addWidget(latenzaLabelMemoria,3,0,1,1);
    aggiungi_gridLayout1->addWidget(latenzaSpinBoxMemoria,3,1,1,1);
    aggiungi_gridLayout1->addWidget(velocitaLabelMemoria,4,0,1,1);
    aggiungi_gridLayout1->addWidget(velocitaLineEditMemoria,4,1,1,1);
    aggiungi_gridLayout1->addWidget(capacitaLabelMemoria,5,0,1,1);
    aggiungi_gridLayout1->addWidget(capacitaLineEditMemoria,5,1,1,1);
    aggiungi_gridLayout1->addWidget(tipologiaLabelMemoria,6,0,1,1);
    aggiungi_gridLayout1->addWidget(tipologiaLineEditMemoria,6,1,1,1);

    //SchedaGrafica
    aggiungi_gridLayout2->addWidget(nomeLabelSchedaGrafica,0,0,1,1);
    aggiungi_gridLayout2->addWidget(nomeLineEditSchedaGrafica,0,1,1,1);
    aggiungi_gridLayout2->addWidget(prezzoLabelSchedaGrafica,1,0,1,1);
    aggiungi_gridLayout2->addWidget(prezzoDoubleSpinBoxSchedaGrafica,1,1,1,1);
    aggiungi_gridLayout2->addWidget(produttoreLabelSchedaGrafica,2,0,1,1);
    aggiungi_gridLayout2->addWidget(produttoreLineEditSchedaGrafica,2,1,1,1);
    aggiungi_gridLayout2->addWidget(interfacciaLabelSchedaGrafica,3,0,1,1);
    aggiungi_gridLayout2->addWidget(interfacciaLineEditSchedaGrafica,3,1,1,1);
    aggiungi_gridLayout2->addWidget(chipsetLabelSchedaGrafica,4,0,1,1);
    aggiungi_gridLayout2->addWidget(chipsetLineEditSchedaGrafica,4,1,1,1);
    aggiungi_gridLayout2->addWidget(memoriaLabelSchedaGrafica,5,0,1,1);
    aggiungi_gridLayout2->addWidget(memoriaLineEditSchedaGrafica,5,1,1,1);
    aggiungi_gridLayout2->addWidget(tipologiaMemoriaLabelSchedaGrafica,6,0,1,1);
    aggiungi_gridLayout2->addWidget(tipologiaMemoriaLineEditSchedaGrafica,6,1,1,1);
    aggiungi_gridLayout2->addWidget(frequenzaCoreLabelSchedaGrafica,7,0,1,1);
    aggiungi_gridLayout2->addWidget(frequenzaCoreLineEditSchedaGrafica,7,1,1,1);
    aggiungi_gridLayout2->addWidget(tdpLabelSchedaGrafica,8,0,1,1);
    aggiungi_gridLayout2->addWidget(tdpLineEditSchedaGrafica,8,1,1,1);
    aggiungi_gridLayout2->addWidget(supportoSLILabelSchedaGrafica,9,0,1,1);
    aggiungi_gridLayout2->addWidget(supportoSLILineEditSchedaGrafica,9,1,1,1);
    aggiungi_gridLayout2->addWidget(supportoCrossfireLabelSchedaGrafica,10,0,1,1);
    aggiungi_gridLayout2->addWidget(supportoCrossfireLineEditSchedaGrafica,10,1,1,1);
    aggiungi_gridLayout2->addWidget(lunghezzaLabelSchedaGrafica,11,0,1,1);
    aggiungi_gridLayout2->addWidget(lunghezzaLineEditSchedaGrafica,11,1,1,1);

    //SchedaMadre
    aggiungi_gridLayout3->addWidget(nomeLabelSchedaMadre,0,0,1,1);
    aggiungi_gridLayout3->addWidget(nomeLineEditSchedaMadre,0,1,1,1);
    aggiungi_gridLayout3->addWidget(prezzoLabelSchedaMadre,1,0,1,1);
    aggiungi_gridLayout3->addWidget(prezzoDoubleSpinBoxSchedaMadre,1,1,1,1);
    aggiungi_gridLayout3->addWidget(produttoreLabelSchedaMadre,2,0,1,1);
    aggiungi_gridLayout3->addWidget(produttoreLineEditSchedaMadre,2,1,1,1);
    aggiungi_gridLayout3->addWidget(fattoreDiFormaLabelSchedaMadre,3,0,1,1);
    aggiungi_gridLayout3->addWidget(fattoreDiFormaLineEditSchedaMadre,3,1,1,1);
    aggiungi_gridLayout3->addWidget(chipsetLabelSchedaMadre,4,0,1,1);
    aggiungi_gridLayout3->addWidget(chipsetLineEditSchedaMadre,4,1,1,1);
    aggiungi_gridLayout3->addWidget(socketProcessoreLabelSchedaMadre,5,0,1,1);
    aggiungi_gridLayout3->addWidget(socketProcessoreLineEditSchedaMadre,5,1,1,1);
    aggiungi_gridLayout3->addWidget(slotMemoriaLabelSchedaMadre,6,0,1,1);
    aggiungi_gridLayout3->addWidget(slotMemoriaLineEditSchedaMadre,6,1,1,1);
    aggiungi_gridLayout3->addWidget(tipologiaMemoriaLabelSchedaMadre,7,0,1,1);
    aggiungi_gridLayout3->addWidget(tipologiaMemoriaLineEditSchedaMadre,7,1,1,1);
    aggiungi_gridLayout3->addWidget(memoriaMassimaLabelSchedaMadre,8,0,1,1);
    aggiungi_gridLayout3->addWidget(memoriaMassimaLineEditSchedaMadre,8,1,1,1);
    aggiungi_gridLayout3->addWidget(supportoRAIDCheckBoxSchedaMadre,9,1,1,1);
    aggiungi_gridLayout3->addWidget(supportoSLICheckBoxSchedaMadre,10,1,1,1);
    aggiungi_gridLayout3->addWidget(supportoCrossfireCheckBoxSchedaMadre,11,1,1,1);
    aggiungi_gridLayout3->addWidget(ethernetLabelSchedaMadre,12,0,1,1);
    aggiungi_gridLayout3->addWidget(ethernetLineEditSchedaMadre,12,1,1,1);
    aggiungi_gridLayout3->addWidget(sata3GBsLabelSchedaMadre,13,0,1,1);
    aggiungi_gridLayout3->addWidget(sata3GBsSpinBoxSchedaMadre,13,1,1,1);
    aggiungi_gridLayout3->addWidget(sata6GBsLabelSchedaMadre,14,0,1,1);
    aggiungi_gridLayout3->addWidget(sata6GBsSpinBoxSchedaMadre,14,1,1,1);
    aggiungi_gridLayout3->addWidget(sataExpressLabelSchedaMadre,15,0,1,1);
    aggiungi_gridLayout3->addWidget(sataExpressSpinboxSchedaMadre,15,1,1,1);
    aggiungi_gridLayout3->addWidget(usb2LabelSchedaMadre,16,0,1,1);
    aggiungi_gridLayout3->addWidget(usb2SpinBoxSchedaMadre,16,1,1,1);
    aggiungi_gridLayout3->addWidget(usb3LabelSchedaMadre,17,0,1,1);
    aggiungi_gridLayout3->addWidget(usb3SpinBoxSchedaMadre,17,1,1,1);

    //Processore
    aggiungi_gridLayout4->addWidget(nomeLabelProcessore,0,0,1,1);
    aggiungi_gridLayout4->addWidget(nomeLineEditProcessore,0,1,1,1);
    aggiungi_gridLayout4->addWidget(prezzoLabelProcessore,1,0,1,1);
    aggiungi_gridLayout4->addWidget(prezzoDoubleSpinBoxProcessore,1,1,1,1);
    aggiungi_gridLayout4->addWidget(produttoreLabelProcessore,2,0,1,1);
    aggiungi_gridLayout4->addWidget(produttoreLineEditProcessore,2,1,1,1);
    aggiungi_gridLayout4->addWidget(socketLabelProcessore,3,0,1,1);
    aggiungi_gridLayout4->addWidget(socketLineEditProcessore,3,1,1,1);
    aggiungi_gridLayout4->addWidget(larghezzaDatiLabelProcessore,4,0,1,1);
    aggiungi_gridLayout4->addWidget(larghezzaDatiLineEditProcessore,4,1,1,1);
    aggiungi_gridLayout4->addWidget(frequenzaOperativaLabelProcessore,5,0,1,1);
    aggiungi_gridLayout4->addWidget(frequenzaOperativaLineEditProcessore,5,1,1,1);
    aggiungi_gridLayout4->addWidget(frequenzaTurboLabelProcessore,6,0,1,1);
    aggiungi_gridLayout4->addWidget(frequenzaTurboLineEditProcessore,6,1,1,1);
    aggiungi_gridLayout4->addWidget(numeroCoreLabelProcessore,7,0,1,1);
    aggiungi_gridLayout4->addWidget(numeroCoreSpinBoxProcessore,7,1,1,1);
    aggiungi_gridLayout4->addWidget(includeDissipatoreCheckBoxProcessore,8,1,1,1);
    aggiungi_gridLayout4->addWidget(hyperThreadingCheckBoxProcessore,9,1,1,1);
    aggiungi_gridLayout4->addWidget(l1CacheLabelProcessore,10,0,1,1);
    aggiungi_gridLayout4->addWidget(l1CacheLineEditProcessore,10,1,1,1);
    aggiungi_gridLayout4->addWidget(l2CacheLabelProcessore,11,0,1,1);
    aggiungi_gridLayout4->addWidget(l2CacheLineEditProcessore,11,1,1,1);
    aggiungi_gridLayout4->addWidget(l3CacheLabelProcessore,12,0,1,1);
    aggiungi_gridLayout4->addWidget(l3CacheLineEditProcessore,12,1,1,1);
    aggiungi_gridLayout4->addWidget(litografiaLabelProcessore,13,0,1,1);
    aggiungi_gridLayout4->addWidget(litografiaLineEditProcessore,13,1,1,1);
    aggiungi_gridLayout4->addWidget(tdpLabelProcessore,14,0,1,1);
    aggiungi_gridLayout4->addWidget(tdpLineEditProcessore,14,1,1,1);
    aggiungi_gridLayout4->addWidget(graficaIntegrataLabelProcessore,15,0,1,1);
    aggiungi_gridLayout4->addWidget(graficaIntegrataLineEditProcessore,15,1,1,1);

    //Archiviazione
    aggiungi_gridLayout5->addWidget(nomeLabelArchiviazione,0,0,1,1);
    aggiungi_gridLayout5->addWidget(nomeLineEditArchiviazione,0,1,1,1);
    aggiungi_gridLayout5->addWidget(prezzoLabelArchiviazione,1,0,1,1);
    aggiungi_gridLayout5->addWidget(prezzoDoubleSpinBoxArchiviazione,1,1,1,1);
    aggiungi_gridLayout5->addWidget(produttoreLabelArchiviazione,2,0,1,1);
    aggiungi_gridLayout5->addWidget(produttoreLineEditArchiviazione,2,1,1,1);
    aggiungi_gridLayout5->addWidget(tipologiaLabelArchiviazione,3,0,1,1);
    aggiungi_gridLayout5->addWidget(tipologiaLineEditArchiviazione,3,1,1,1);
    aggiungi_gridLayout5->addWidget(capacitaLabelArchiviazione,4,0,1,1);
    aggiungi_gridLayout5->addWidget(capacitaLineEditArchiviazione,4,1,1,1);
    aggiungi_gridLayout5->addWidget(interfacciaLabelArchiviazione,5,0,1,1);
    aggiungi_gridLayout5->addWidget(interfacciaLineEditArchiviazione,5,1,1,1);
    aggiungi_gridLayout5->addWidget(cacheLabelArchiviazione,6,0,1,1);
    aggiungi_gridLayout5->addWidget(cacheLineEditArchiviazione,6,1,1,1);
    aggiungi_gridLayout5->addWidget(fattoreDiFormaLabelArchiviazione,7,0,1,1);
    aggiungi_gridLayout5->addWidget(fattoreDiFormaLineEditArchiviazione,7,1,1,1);
    aggiungi_gridLayout5->addWidget(rpmLabelArchiviazione,8,0,1,1);
    aggiungi_gridLayout5->addWidget(rpmLineEditArchiviazione,8,1,1,1);

    //Alimentatore
    aggiungi_gridLayout6->addWidget(nomeLabelAlimentatore,0,0,1,1);
    aggiungi_gridLayout6->addWidget(nomeLineEditAlimentatore,0,1,1,1);
    aggiungi_gridLayout6->addWidget(prezzoLabelAlimentatore,1,0,1,1);
    aggiungi_gridLayout6->addWidget(prezzoDoubleSpinBoxAlimentatore,1,1,1,1);
    aggiungi_gridLayout6->addWidget(produttoreLabelAlimentatore,2,0,1,1);
    aggiungi_gridLayout6->addWidget(produttoreLineEditAlimentatore,2,1,1,1);
    aggiungi_gridLayout6->addWidget(tipologiaLabelAlimentatore,3,0,1,1);
    aggiungi_gridLayout6->addWidget(tipologiaLineEditAlimentatore,3,1,1,1);
    aggiungi_gridLayout6->addWidget(wattaggioLabelAlimentatore,4,0,1,1);
    aggiungi_gridLayout6->addWidget(wattaggioLineEditAlimentatore,4,1,1,1);
    aggiungi_gridLayout6->addWidget(modulareLabelAlimentatore,5,0,1,1);
    aggiungi_gridLayout6->addWidget(modulareLineEditAlimentatore,5,1,1,1);
    aggiungi_gridLayout6->addWidget(certificazioneEfficienzaLabelAlimentatore,6,0,1,1);
    aggiungi_gridLayout6->addWidget(certificazioneEfficienzaLineEditAlimentatore,6,1,1,1);
    aggiungi_gridLayout6->addWidget(efficienzaLabelAlimentatore,7,0,1,1);
    aggiungi_gridLayout6->addWidget(efficienzaDoubleSpinBoxAlimentatore,7,1,1,1);

    //DissipatoreProcessore
    aggiungi_gridLayout7->addWidget(nomeLabelDissipatoreProcessore,0,0,1,1);
    aggiungi_gridLayout7->addWidget(nomeLineEditDissipatoreProcessore,0,1,1,1);
    aggiungi_gridLayout7->addWidget(prezzoLabelDissipatoreProcessore,1,0,1,1);
    aggiungi_gridLayout7->addWidget(prezzoDoubleSpinBoxDissipatoreProcessore,1,1,1,1);
    aggiungi_gridLayout7->addWidget(produttoreLabelDissipatoreProcessore,2,0,1,1);
    aggiungi_gridLayout7->addWidget(produttoreLineEditDissipatoreProcessore,2,1,1,1);
    aggiungi_gridLayout7->addWidget(socketSupportatiLabelDissipatoreProcessore,3,0,1,1);
    aggiungi_gridLayout7->addWidget(socketSupportatiLineEditDissipatoreProcessore,3,1,1,1);
    aggiungi_gridLayout7->addWidget(rpmVentolaLabelDissipatoreProcessore,4,0,1,1);
    aggiungi_gridLayout7->addWidget(rpmVentolaLineEditDissipatoreProcessore,4,1,1,1);
    aggiungi_gridLayout7->addWidget(altezzaLabelDissipatoreProcessore,5,0,1,1);
    aggiungi_gridLayout7->addWidget(altezzaLineEditDissipatoreProcessore,5,1,1,1);
    aggiungi_gridLayout7->addWidget(raffreddamentoALiquidoCheckBoxDissipatoreProcessore,6,1,1,1);
    aggiungi_gridLayout7->addWidget(altezzaRadiatoreLabelDissipatoreProcessore,7,0,1,1);
    aggiungi_gridLayout7->addWidget(altezzaRadiatoreLineEditDissipatoreProcessore,7,1,1,1);
    aggiungi_gridLayout7->addWidget(livelloRumoreLabelDissipatoreProcessore,8,0,1,1);
    aggiungi_gridLayout7->addWidget(livelloRumoreLineEditDissipatoreProcessore,8,1,1,1);

    //Case
    aggiungi_gridLayout8->addWidget(nomeLabelCase,0,0,1,1);
    aggiungi_gridLayout8->addWidget(nomeLineEditCase,0,1,1,1);
    aggiungi_gridLayout8->addWidget(prezzoLabelCase,1,0,1,1);
    aggiungi_gridLayout8->addWidget(prezzoDoubleSpinBoxCase,1,1,1,1);
    aggiungi_gridLayout8->addWidget(produttoreLabelCase,2,0,1,1);
    aggiungi_gridLayout8->addWidget(produttoreLineEditCase,2,1,1,1);
    aggiungi_gridLayout8->addWidget(tipologiaLabelCase,3,0,1,1);
    aggiungi_gridLayout8->addWidget(tipologiaLineEditCase,3,1,1,1);
    aggiungi_gridLayout8->addWidget(coloreLabelCase,4,0,1,1);
    aggiungi_gridLayout8->addWidget(coloreLineEditCase,4,1,1,1);
    aggiungi_gridLayout8->addWidget(alimentatoreInclusoCheckBoxCase,5,1,1,1);
    aggiungi_gridLayout8->addWidget(slotInterni25LabelCase,6,0,1,1);
    aggiungi_gridLayout8->addWidget(slotInterni25SpinBoxCase,6,1,1,1);
    aggiungi_gridLayout8->addWidget(slotInterni35LabelCase,7,0,1,1);
    aggiungi_gridLayout8->addWidget(slotInterni35SpinBoxCase,7,1,1,1);
    aggiungi_gridLayout8->addWidget(compatibilitaSchedaMadreLabelCase,8,0,1,1);
    aggiungi_gridLayout8->addWidget(compatibilitaSchedaMadreLineEditCase,8,1,1,1);
    aggiungi_gridLayout8->addWidget(lunghezzaMassimaSchedaGraficaLabelCase,9,0,1,1);
    aggiungi_gridLayout8->addWidget(lunghezzaMassimaSchedaGraficaLineEditCase,9,1,1,1);
    aggiungi_gridLayout8->addWidget(dimensioniLabelCase,10,0,1,1);
    aggiungi_gridLayout8->addWidget(dimensioniLineEditCase,10,1,1,1);

    //UnitaOttica
    aggiungi_gridLayout9->addWidget(nomeLabelUnitaOttica,0,0,1,1);
    aggiungi_gridLayout9->addWidget(nomeLineEditUnitaOttica,0,1,1,1);
    aggiungi_gridLayout9->addWidget(prezzoLabelUnitaOttica,1,0,1,1);
    aggiungi_gridLayout9->addWidget(prezzoDoubleSpinBoxUnitaOttica,1,1,1,1);
    aggiungi_gridLayout9->addWidget(produttoreLabelUnitaOttica,2,0,1,1);
    aggiungi_gridLayout9->addWidget(produttoreLineEditUnitaOttica,2,1,1,1);
    aggiungi_gridLayout9->addWidget(fattoreDiFormaLabelUnitaOttica,3,0,1,1);
    aggiungi_gridLayout9->addWidget(fattoreDiFormaLineEditUnitaOttica,3,1,1,1);
    aggiungi_gridLayout9->addWidget(interfacciaLabelUnitaOttica,4,0,1,1);
    aggiungi_gridLayout9->addWidget(interfacciaLineEditUnitaOttica,4,1,1,1);
    aggiungi_gridLayout9->addWidget(cacheLabelUnitaOttica,5,0,1,1);
    aggiungi_gridLayout9->addWidget(cacheLineEditUnitaOttica,5,1,1,1);
    aggiungi_gridLayout9->addWidget(velocitaLabelUnitaOttica,6,0,1,1);
    aggiungi_gridLayout9->addWidget(velocitaLineEditUnitaOttica,6,1,1,1);

    //Monitor
    aggiungi_gridLayout10->addWidget(nomeLabelMonitor,0,0,1,1);
    aggiungi_gridLayout10->addWidget(nomeLineEditMonitor,0,1,1,1);
    aggiungi_gridLayout10->addWidget(prezzoLabelMonitor,1,0,1,1);
    aggiungi_gridLayout10->addWidget(prezzoDoubleSpinBoxMonitor,1,1,1,1);
    aggiungi_gridLayout10->addWidget(produttoreLabelMonitor,2,0,1,1);
    aggiungi_gridLayout10->addWidget(produttoreLineEditMonitor,2,1,1,1);
    aggiungi_gridLayout10->addWidget(risoluzioneRaccomandataLabelMonitor,3,0,1,1);
    aggiungi_gridLayout10->addWidget(risoluzioneRaccomandataLineEditMonitor,3,1,1,1);
    aggiungi_gridLayout10->addWidget(formatoLabelMonitor,4,0,1,1);
    aggiungi_gridLayout10->addWidget(formatoLineEditMonitor,4,1,1,1);
    aggiungi_gridLayout10->addWidget(angoloDiVisualizzazioneLabelMonitor,5,0,1,1);
    aggiungi_gridLayout10->addWidget(angoloDiVisualizzazioneLineEditMonitor,5,1,1,1);
    aggiungi_gridLayout10->addWidget(coloriDelDisplayLabelMonitor,6,0,1,1);
    aggiungi_gridLayout10->addWidget(coloriDelDisplayLineEditMonitor,6,1,1,1);
    aggiungi_gridLayout10->addWidget(luminositaLabelMonitor,7,0,1,1);
    aggiungi_gridLayout10->addWidget(luminositaLineEditMonitor,7,1,1,1);
    aggiungi_gridLayout10->addWidget(rapportoDiContrastoLabelMonitor,8,0,1,1);
    aggiungi_gridLayout10->addWidget(rapportoDiContrastoLineEditMonitor,8,1,1,1);
    aggiungi_gridLayout10->addWidget(altoparlantiIncorporatiCheckBoxMonitor,9,1,1,1);
    aggiungi_gridLayout10->addWidget(widescreenCheckBoxMonitor,10,1,1,1);
    aggiungi_gridLayout10->addWidget(tempoDiRispostaLabelMonitor,11,0,1,1);
    aggiungi_gridLayout10->addWidget(tempoDiRispostaLineEditMonitor,11,1,1,1);
    aggiungi_gridLayout10->addWidget(tipologiaDisplayLabelMonitor,12,0,1,1);
    aggiungi_gridLayout10->addWidget(tipologiaDisplayLineEditMonitor,12,1,1,1);
    aggiungi_gridLayout10->addWidget(frequenzaDiAggiornamentoLabelMonitor,13,0,1,1);
    aggiungi_gridLayout10->addWidget(frequenzaDiAggiornamentoLineEditMonitor,13,1,1,1);

    //SistemaOperativo
    aggiungi_gridLayout11->addWidget(nomeLabelSistemaOperativo,0,0,1,1);
    aggiungi_gridLayout11->addWidget(nomeLineEditSistemaOperativo,0,1,1,1);
    aggiungi_gridLayout11->addWidget(prezzoLabelSistemaOperativo,1,0,1,1);
    aggiungi_gridLayout11->addWidget(prezzoDoubleSpinBoxSistemaOperativo,1,1,1,1);
    aggiungi_gridLayout11->addWidget(produttoreLabelSistemaOperativo,2,0,1,1);
    aggiungi_gridLayout11->addWidget(produttoreLineEditSistemaOperativo,2,1,1,1);
    aggiungi_gridLayout11->addWidget(modalitaLabelSistemaOperativo,3,0,1,1);
    aggiungi_gridLayout11->addWidget(modalitaLineEditSistemaOperativo,3,1,1,1);
    aggiungi_gridLayout11->addWidget(memoriaMassimaSupportataLabelSistemaOperativo,4,0,1,1);
    aggiungi_gridLayout11->addWidget(memoriaMassimaSupportataLineEditSistemaOperativo,4,1,1,1);

    //Mouse
    aggiungi_gridLayout12->addWidget(nomeLabelMouse,0,0,1,1);
    aggiungi_gridLayout12->addWidget(nomeLineEditMouse,0,1,1,1);
    aggiungi_gridLayout12->addWidget(prezzoLabelMouse,1,0,1,1);
    aggiungi_gridLayout12->addWidget(prezzoDoubleSpinBoxMouse,1,1,1,1);
    aggiungi_gridLayout12->addWidget(produttoreLabelMouse,2,0,1,1);
    aggiungi_gridLayout12->addWidget(produttoreLineEditMouse,2,1,1,1);
    aggiungi_gridLayout12->addWidget(connessioneLabelMouse,3,0,1,1);
    aggiungi_gridLayout12->addWidget(connessioneLineEditMouse,3,1,1,1);
    aggiungi_gridLayout12->addWidget(tipologiaTracciamentoLabelMouse,4,0,1,1);
    aggiungi_gridLayout12->addWidget(tipologiaTracciamentoLineEditMouse,4,1,1,1);
    aggiungi_gridLayout12->addWidget(dpiMassimiLabelMouse,5,0,1,1);
    aggiungi_gridLayout12->addWidget(dpiMassimiSpinBoxMouse,5,1,1,1);
    aggiungi_gridLayout12->addWidget(coloreLabelMouse,6,0,1,1);
    aggiungi_gridLayout12->addWidget(coloreLineEditMouse,6,1,1,1);
    aggiungi_gridLayout12->addWidget(orientamentoDellaManoLabelMouse,7,0,1,1);
    aggiungi_gridLayout12->addWidget(orientamentoDellaManoLineEditMouse,7,1,1,1);

    //Tastiera
    aggiungi_gridLayout13->addWidget(nomeLabelTastiera,0,0,1,1);
    aggiungi_gridLayout13->addWidget(nomeLineEditTastiera,0,1,1,1);
    aggiungi_gridLayout13->addWidget(prezzoLabelTastiera,1,0,1,1);
    aggiungi_gridLayout13->addWidget(prezzoDoubleSpinBoxTastiera,1,1,1,1);
    aggiungi_gridLayout13->addWidget(produttoreLabelTastiera,2,0,1,1);
    aggiungi_gridLayout13->addWidget(produttoreLineEditTastiera,2,1,1,1);
    aggiungi_gridLayout13->addWidget(coloreLabelTastiera,3,0,1,1);
    aggiungi_gridLayout13->addWidget(coloreLineEditTastiera,3,1,1,1);
    aggiungi_gridLayout13->addWidget(connessioneLabelTastiera,4,0,1,1);
    aggiungi_gridLayout13->addWidget(connessioneLineEditTastiera,4,1,1,1);
    aggiungi_gridLayout13->addWidget(retroilluminazioneCheckBoxTastiera,5,1,1,1);
    aggiungi_gridLayout13->addWidget(tipologiaLabelTastiera,6,0,1,1);
    aggiungi_gridLayout13->addWidget(tipologiaLineEditTastiera,6,1,1,1);
    aggiungi_gridLayout13->addWidget(tipologiaSwitchLabelTastiera,7,0,1,1);
    aggiungi_gridLayout13->addWidget(tipologiaSwitchLineEditTastiera,7,1,1,1);

    //Cuffie
    aggiungi_gridLayout14->addWidget(nomeLabelCuffie,0,0,1,1);
    aggiungi_gridLayout14->addWidget(nomeLineEditCuffie,0,1,1,1);
    aggiungi_gridLayout14->addWidget(prezzoLabelCuffie,1,0,1,1);
    aggiungi_gridLayout14->addWidget(prezzoDoubleSpinBoxCuffie,1,1,1,1);
    aggiungi_gridLayout14->addWidget(produttoreLabelCuffie,2,0,1,1);
    aggiungi_gridLayout14->addWidget(produttoreLineEditCuffie,2,1,1,1);
    aggiungi_gridLayout14->addWidget(tipologiaLabelCuffie,3,0,1,1);
    aggiungi_gridLayout14->addWidget(tipologiaLineEditCuffie,3,1,1,1);
    aggiungi_gridLayout14->addWidget(sistemaAcusticoLabelCuffie,4,0,1,1);
    aggiungi_gridLayout14->addWidget(sistemaAcusticoLineEditCuffie,4,1,1,1);
    aggiungi_gridLayout14->addWidget(coloreLabelCuffie,5,0,1,1);
    aggiungi_gridLayout14->addWidget(coloreLineEditCuffie,5,1,1,1);
    aggiungi_gridLayout14->addWidget(canaliLabelCuffie,6,0,1,1);
    aggiungi_gridLayout14->addWidget(canaliLineEditCuffie,6,1,1,1);
    aggiungi_gridLayout14->addWidget(impedenzaLabelCuffie,7,0,1,1);
    aggiungi_gridLayout14->addWidget(impedenzaLineEditCuffie,7,1,1,1);
    aggiungi_gridLayout14->addWidget(frequenzaDiRispostaLabelCuffie,8,0,1,1);
    aggiungi_gridLayout14->addWidget(frequenzaDiRispostaLineEditCuffie,8,1,1,1);
    aggiungi_gridLayout14->addWidget(microfonoCheckBoxCuffie,9,1,1,1);
    aggiungi_gridLayout14->addWidget(connessioneLabelCuffie,10,0,1,1);
    aggiungi_gridLayout14->addWidget(connessioneLineEditCuffie,10,1,1,1);
    aggiungi_gridLayout14->addWidget(connettoreLabelCuffie,11,0,1,1);
    aggiungi_gridLayout14->addWidget(connettoreLineEditCuffie,11,1,1,1);

    //Altoparlanti
    aggiungi_gridLayout15->addWidget(nomeLabelAltoparlanti,0,0,1,1);
    aggiungi_gridLayout15->addWidget(nomeLineEditAltoparlanti,0,1,1,1);
    aggiungi_gridLayout15->addWidget(prezzoLabelAltoparlanti,1,0,1,1);
    aggiungi_gridLayout15->addWidget(prezzoDoubleSpinBoxAltoparlanti,1,1,1,1);
    aggiungi_gridLayout15->addWidget(produttoreLabelAltoparlanti,2,0,1,1);
    aggiungi_gridLayout15->addWidget(produttoreLineEditAltoparlanti,2,1,1,1);
    aggiungi_gridLayout15->addWidget(coloreLabelAltoparlanti,3,0,1,1);
    aggiungi_gridLayout15->addWidget(coloreLineEditAltoparlanti,3,1,1,1);
    aggiungi_gridLayout15->addWidget(configurazioneLabelAltoparlanti,4,0,1,1);
    aggiungi_gridLayout15->addWidget(configurazioneLineEditAltoparlanti,4,1,1,1);
    aggiungi_gridLayout15->addWidget(frequenzaDiRispostaLabelAltoparlanti,5,0,1,1);
    aggiungi_gridLayout15->addWidget(frequenzaDiRispostaLineEditAltoparlanti,5,1,1,1);
    aggiungi_gridLayout15->addWidget(potenzaTotaleLabelAltoparlanti,6,0,1,1);
    aggiungi_gridLayout15->addWidget(potenzaTotaleLineEditAltoparlanti,6,1,1,1);
    aggiungi_gridLayout15->addWidget(potenzeLabelAltoparlanti,7,0,1,1);
    aggiungi_gridLayout15->addWidget(potenzeLineEditAltoparlanti,7,1,1,1);

    connect(tipo_componenteAggiungi,SIGNAL(currentIndexChanged(int)),aggiungi_stackedWidget,SLOT(setCurrentIndex(int)));

    setLayout(verticalLayout5);
}

void MyWidget_GestisciComponentiPCBuilder::clearForms(){
    QString componente=tipo_componenteAggiungi->currentText();
    if (componente=="Memoria")
    {
        nomeLineEditMemoria->clear();
        produttoreLineEditMemoria->clear();
        velocitaLineEditMemoria->clear();
        capacitaLineEditMemoria->clear();
        tipologiaLineEditMemoria->clear();
        prezzoDoubleSpinBoxMemoria->clear();
        latenzaSpinBoxMemoria->clear();
    }
    if (componente=="Scheda grafica")
    {
        nomeLineEditSchedaGrafica->clear();
        produttoreLineEditSchedaGrafica->clear();
        interfacciaLineEditSchedaGrafica->clear();
        chipsetLineEditSchedaGrafica->clear();
        memoriaLineEditSchedaGrafica->clear();
        tipologiaMemoriaLineEditSchedaGrafica->clear();
        frequenzaCoreLineEditSchedaGrafica->clear();
        tdpLineEditSchedaGrafica->clear();
        supportoSLILineEditSchedaGrafica->clear();
        supportoCrossfireLineEditSchedaGrafica->clear();
        lunghezzaLineEditSchedaGrafica->clear();
        prezzoDoubleSpinBoxSchedaGrafica->clear();
    }
    if (componente=="Scheda madre")
    {
        nomeLineEditSchedaMadre->clear();
        produttoreLineEditSchedaMadre->clear();
        fattoreDiFormaLineEditSchedaMadre->clear();
        chipsetLineEditSchedaMadre->clear();
        socketProcessoreLineEditSchedaMadre->clear();
        slotMemoriaLineEditSchedaMadre->clear();
        tipologiaMemoriaLineEditSchedaMadre->clear();
        memoriaMassimaLineEditSchedaMadre->clear();
        ethernetLineEditSchedaMadre->clear();
        supportoRAIDCheckBoxSchedaMadre->setCheckState(Qt::Unchecked);
        supportoCrossfireCheckBoxSchedaMadre->setCheckState(Qt::Unchecked);
        supportoSLICheckBoxSchedaMadre->setCheckState(Qt::Unchecked);
        sata3GBsSpinBoxSchedaMadre->clear();
        sata6GBsSpinBoxSchedaMadre->clear();
        sataExpressSpinboxSchedaMadre->clear();
        usb2SpinBoxSchedaMadre->clear();
        usb3SpinBoxSchedaMadre->clear();
        prezzoDoubleSpinBoxSchedaMadre->clear();
    }
    if (componente=="Processore")
    {
        nomeLineEditProcessore->clear();
        produttoreLineEditProcessore->clear();
        socketLineEditProcessore->clear();
        larghezzaDatiLineEditProcessore->clear();
        frequenzaOperativaLineEditProcessore->clear();
        frequenzaTurboLineEditProcessore->clear();
        l1CacheLineEditProcessore->clear();
        l2CacheLineEditProcessore->clear();
        l3CacheLineEditProcessore->clear();
        litografiaLineEditProcessore->clear();
        tdpLineEditProcessore->clear();
        graficaIntegrataLineEditProcessore->clear();
        includeDissipatoreCheckBoxProcessore->setCheckState(Qt::Unchecked);
        hyperThreadingCheckBoxProcessore->setCheckState(Qt::Unchecked);
        numeroCoreSpinBoxProcessore->clear();
        prezzoDoubleSpinBoxProcessore->clear();
    }
    if (componente=="Archiviazione")
    {
        nomeLineEditArchiviazione->clear();
        produttoreLineEditArchiviazione->clear();
        tipologiaLineEditArchiviazione->clear();
        capacitaLineEditArchiviazione->clear();
        interfacciaLineEditArchiviazione->clear();
        cacheLineEditArchiviazione->clear();
        fattoreDiFormaLineEditArchiviazione->clear();
        rpmLineEditArchiviazione->clear();
        prezzoDoubleSpinBoxArchiviazione->clear();
    }
    if (componente=="Alimentatore")
    {
        nomeLineEditAlimentatore->clear();
        produttoreLineEditAlimentatore->clear();
        tipologiaLineEditAlimentatore->clear();
        wattaggioLineEditAlimentatore->clear();
        modulareLineEditAlimentatore->clear();
        certificazioneEfficienzaLineEditAlimentatore->clear();
        efficienzaDoubleSpinBoxAlimentatore->clear();
        prezzoDoubleSpinBoxAlimentatore->clear();
    }
    if (componente=="Dissipatore processore")
    {
        nomeLineEditDissipatoreProcessore->clear();
        produttoreLineEditDissipatoreProcessore->clear();
        socketSupportatiLineEditDissipatoreProcessore->clear();
        rpmVentolaLineEditDissipatoreProcessore->clear();
        altezzaLineEditDissipatoreProcessore->clear();
        altezzaRadiatoreLineEditDissipatoreProcessore->clear();
        livelloRumoreLineEditDissipatoreProcessore->clear();
        raffreddamentoALiquidoCheckBoxDissipatoreProcessore->setCheckState(Qt::Unchecked);
        prezzoDoubleSpinBoxDissipatoreProcessore->clear();
    }
    if (componente=="Case")
    {
        nomeLineEditCase->clear();
        produttoreLineEditCase->clear();
        tipologiaLineEditCase->clear();
        coloreLineEditCase->clear();
        compatibilitaSchedaMadreLineEditCase->clear();
        lunghezzaMassimaSchedaGraficaLineEditCase->clear();
        dimensioniLineEditCase->clear();
        alimentatoreInclusoCheckBoxCase->setCheckState(Qt::Unchecked);
        slotInterni25SpinBoxCase->clear();
        slotInterni35SpinBoxCase->clear();
        prezzoDoubleSpinBoxCase->clear();
    }
    if (componente=="Unità ottica")
    {
        nomeLineEditUnitaOttica->clear();
        produttoreLineEditUnitaOttica->clear();
        fattoreDiFormaLineEditUnitaOttica->clear();
        interfacciaLineEditUnitaOttica->clear();
        cacheLineEditUnitaOttica->clear();
        velocitaLineEditUnitaOttica->clear();
        prezzoDoubleSpinBoxUnitaOttica->clear();
    }
    if (componente=="Monitor")
    {
        nomeLineEditMonitor->clear();
        produttoreLineEditMonitor->clear();
        risoluzioneRaccomandataLineEditMonitor->clear();
        formatoLineEditMonitor->clear();
        angoloDiVisualizzazioneLineEditMonitor->clear();
        coloriDelDisplayLineEditMonitor->clear();
        luminositaLineEditMonitor->clear();
        rapportoDiContrastoLineEditMonitor->clear();
        tempoDiRispostaLineEditMonitor->clear();
        tipologiaDisplayLineEditMonitor->clear();
        frequenzaDiAggiornamentoLineEditMonitor->clear();
        altoparlantiIncorporatiCheckBoxMonitor->setCheckState(Qt::Unchecked);
        widescreenCheckBoxMonitor->setCheckState(Qt::Unchecked);
        prezzoDoubleSpinBoxMonitor->clear();
    }
    if (componente=="Sistema operativo")
    {
        nomeLineEditSistemaOperativo->clear();
        produttoreLineEditSistemaOperativo->clear();
        modulareLineEditAlimentatore->clear();
        memoriaMassimaSupportataLineEditSistemaOperativo->clear();
        prezzoDoubleSpinBoxSistemaOperativo->clear();
    }
    if (componente=="Mouse")
    {
        nomeLineEditMouse->clear();
        produttoreLineEditMouse->clear();
        connessioneLineEditMouse->clear();
        tipologiaTracciamentoLineEditMouse->clear();
        coloreLineEditMouse->clear();
        orientamentoDellaManoLineEditMouse->clear();
        dpiMassimiSpinBoxMouse->clear();
        prezzoDoubleSpinBoxMouse->clear();
    }
    if (componente=="Tastiera")
    {
        nomeLineEditTastiera->clear();
        produttoreLineEditTastiera->clear();
        coloreLineEditTastiera->clear();
        connessioneLineEditTastiera->clear();
        tipologiaLineEditTastiera->clear();
        tipologiaSwitchLineEditTastiera->clear();
        retroilluminazioneCheckBoxTastiera->setCheckState(Qt::Unchecked);
        prezzoDoubleSpinBoxTastiera->clear();
    }
    if (componente=="Cuffie")
    {
        nomeLineEditCuffie->clear();
        produttoreLineEditCuffie->clear();
        tipologiaLineEditCuffie->clear();
        sistemaAcusticoLineEditCuffie->clear();
        coloreLineEditCuffie->clear();
        canaliLineEditCuffie->clear();
        impedenzaLineEditCuffie->clear();
        frequenzaDiRispostaLineEditCuffie->clear();
        connessioneLineEditCuffie->clear();
        connettoreLineEditCuffie->clear();
        microfonoCheckBoxCuffie->setCheckState(Qt::Unchecked);
        prezzoDoubleSpinBoxCuffie->clear();
    }
    if (componente=="Altoparlanti")
    {
        nomeLineEditAltoparlanti->clear();
        produttoreLineEditAltoparlanti->clear();
        coloreLineEditAltoparlanti->clear();
        configurazioneLineEditAltoparlanti->clear();
        frequenzaDiRispostaLineEditAltoparlanti->clear();
        potenzaTotaleLineEditAltoparlanti->clear();
        potenzeLineEditAltoparlanti->clear();
        prezzoDoubleSpinBoxAltoparlanti->clear();
    }
}


void MyWidget_GestisciComponentiPCBuilder::createLabels(){

    PCBuilder_Gestione_componentiLabel=new QLabel("PCBuilder - "+(tr("Gestione componenti")));
    QFont font_PCBuilder_Gestione_componentiLabel=PCBuilder_Gestione_componentiLabel->font();
    font_PCBuilder_Gestione_componentiLabel.setPointSize(24);
    PCBuilder_Gestione_componentiLabel->setFont(font_PCBuilder_Gestione_componentiLabel);
    PCBuilder_Gestione_componentiLabel->setMaximumSize(QSize(550,50));
    PCBuilder_Gestione_componentiLabel->setMinimumSize(QSize(0,0));

    aggiungi_componenteLabel=new QLabel(tr("Aggiungi componente"));
    QFont font_aggiungi_componenteLabel=aggiungi_componenteLabel->font();
    font_aggiungi_componenteLabel.setPointSize(18);
    aggiungi_componenteLabel->setFont(font_aggiungi_componenteLabel);
    aggiungi_componenteLabel->setMaximumSize(QSize(270,30));
    aggiungi_componenteLabel->setMinimumSize(QSize(0,0));

    rimuovi_componenteLabel=new QLabel(tr("Rimuovi componente"));
    QFont font_rimuovi_componenteLabel=rimuovi_componenteLabel->font();
    font_rimuovi_componenteLabel.setPixelSize(18);
    rimuovi_componenteLabel->setFont(font_rimuovi_componenteLabel);
    rimuovi_componenteLabel->setMaximumSize(QSize(270,30));
    rimuovi_componenteLabel->setMinimumSize(QSize(0,0));

    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelMemoria=new QLabel(tr("Nome:"));
    nomeLabelMemoria->setFont(font_formLabel);
    nomeLabelMemoria->setMaximumSize(QSize(70,30));
    nomeLabelMemoria->setMinimumSize(QSize(0,0));

    prezzoLabelMemoria=new QLabel(tr("Prezzo:"));
    prezzoLabelMemoria->setFont(font_formLabel);
    prezzoLabelMemoria->setMaximumSize(QSize(80,30));
    prezzoLabelMemoria->setMinimumSize(QSize(0,0));


    produttoreLabelMemoria=new QLabel(tr("Produttore"));
    produttoreLabelMemoria->setFont(font_formLabel);
    produttoreLabelMemoria->setMaximumSize(QSize(110,30));
    produttoreLabelMemoria->setMinimumSize(QSize(0,0));


    velocitaLabelMemoria=new QLabel(tr("Velocità:"));
    velocitaLabelMemoria->setFont(font_formLabel);
    velocitaLabelMemoria->setMaximumSize(QSize(90,30));
    velocitaLabelMemoria->setMinimumSize(QSize(0,0));


    capacitaLabelMemoria=new QLabel(tr("Capacità:"));
    capacitaLabelMemoria->setFont(font_formLabel);
    capacitaLabelMemoria->setMaximumSize(QSize(90,30));
    capacitaLabelMemoria->setMinimumSize(QSize(0,0));

    tipologiaLabelMemoria=new QLabel(tr("Tipologia:"));
    tipologiaLabelMemoria->setFont(font_formLabel);
    tipologiaLabelMemoria->setMaximumSize(QSize(90,30));
    tipologiaLabelMemoria->setMinimumSize(QSize(0,0));


    latenzaLabelMemoria=new QLabel(tr("Latenza:"));
    latenzaLabelMemoria->setFont(font_formLabel);
    latenzaLabelMemoria->setMaximumSize(QSize(80,30));
    latenzaLabelMemoria->setMinimumSize(QSize(0,0));

    nomeLabelSchedaGrafica=new QLabel(tr("Nome:"));
    nomeLabelSchedaGrafica->setFont(font_formLabel);
    nomeLabelSchedaGrafica->setMaximumSize(QSize(70,30));
    nomeLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    prezzoLabelSchedaGrafica=new QLabel(tr("Prezzo:"));
    prezzoLabelSchedaGrafica->setFont(font_formLabel);
    prezzoLabelSchedaGrafica->setMaximumSize(QSize(80,30));
    prezzoLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    produttoreLabelSchedaGrafica=new QLabel(tr("Produttore:"));
    produttoreLabelSchedaGrafica->setFont(font_formLabel);
    produttoreLabelSchedaGrafica->setMaximumSize(QSize(110,30));
    produttoreLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    interfacciaLabelSchedaGrafica=new QLabel(tr("Interfaccia:"));
    interfacciaLabelSchedaGrafica->setFont(font_formLabel);
    interfacciaLabelSchedaGrafica->setMaximumSize(QSize(110,30));
    interfacciaLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    chipsetLabelSchedaGrafica=new QLabel("Chipset:");
    chipsetLabelSchedaGrafica->setFont(font_formLabel);
    chipsetLabelSchedaGrafica->setMaximumSize(QSize(80,30));
    chipsetLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    memoriaLabelSchedaGrafica=new QLabel(tr("Memoria:"));
    memoriaLabelSchedaGrafica->setFont(font_formLabel);
    memoriaLabelSchedaGrafica->setMaximumSize(QSize(90,30));
    memoriaLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLabelSchedaGrafica=new QLabel(tr("Tipologia \nmemoria:"));
    tipologiaMemoriaLabelSchedaGrafica->setFont(font_formLabel);
    tipologiaMemoriaLabelSchedaGrafica->setMaximumSize(QSize(90,50));
    tipologiaMemoriaLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    frequenzaCoreLabelSchedaGrafica=new QLabel(tr("Frequenza ")+("core:"));
    frequenzaCoreLabelSchedaGrafica->setFont(font_formLabel);
    frequenzaCoreLabelSchedaGrafica->setMaximumSize(QSize(160,30));
    frequenzaCoreLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    tdpLabelSchedaGrafica=new QLabel("TDP:");
    tdpLabelSchedaGrafica->setFont(font_formLabel);
    tdpLabelSchedaGrafica->setMaximumSize(QSize(50,30));
    tdpLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoSLILabelSchedaGrafica=new QLabel(tr("Supporto ")+("SLI:"));
    supportoSLILabelSchedaGrafica->setFont(font_formLabel);
    supportoSLILabelSchedaGrafica->setMaximumSize(QSize(130,30));
    supportoSLILabelSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoCrossfireLabelSchedaGrafica=new QLabel(tr("Supporto ")+("\nCrossfire:"));
    supportoCrossfireLabelSchedaGrafica->setFont(font_formLabel);
    supportoCrossfireLabelSchedaGrafica->setMaximumSize(QSize(90,50));
    supportoCrossfireLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    lunghezzaLabelSchedaGrafica=new QLabel(tr("Lunghezza:"));
    lunghezzaLabelSchedaGrafica->setFont(font_formLabel);
    lunghezzaLabelSchedaGrafica->setMaximumSize(QSize(110,30));
    lunghezzaLabelSchedaGrafica->setMinimumSize(QSize(0,0));

    nomeLabelSchedaMadre=new QLabel(tr("Nome:"));
    nomeLabelSchedaMadre->setFont(font_formLabel);
    nomeLabelSchedaMadre->setMaximumSize(QSize(70,30));
    nomeLabelSchedaMadre->setMinimumSize(QSize(0,0));

    prezzoLabelSchedaMadre=new QLabel("Prezzo:");
    prezzoLabelSchedaMadre->setFont(font_formLabel);
    prezzoLabelSchedaMadre->setMaximumSize(QSize(80,30));
    prezzoLabelSchedaMadre->setMinimumSize(QSize(0,0));

    produttoreLabelSchedaMadre=new QLabel(tr("Produttore:"));
    produttoreLabelSchedaMadre->setFont(font_formLabel);
    produttoreLabelSchedaMadre->setMaximumSize(QSize(110,30));
    produttoreLabelSchedaMadre->setMinimumSize(QSize(0,0));

    fattoreDiFormaLabelSchedaMadre=new QLabel(tr("Fattore di forma:"));
    fattoreDiFormaLabelSchedaMadre->setFont(font_formLabel);
    fattoreDiFormaLabelSchedaMadre->setMaximumSize(QSize(160,30));
    fattoreDiFormaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    chipsetLabelSchedaMadre=new QLabel("Chipset");
    chipsetLabelSchedaMadre->setFont(font_formLabel);
    chipsetLabelSchedaMadre->setMaximumSize(QSize(80,30));
    chipsetLabelSchedaMadre->setMinimumSize(QSize(0,0));

    socketProcessoreLabelSchedaMadre=new QLabel("Socket "+(tr("\nprocessore:")));
    socketProcessoreLabelSchedaMadre->setFont(font_formLabel);
    socketProcessoreLabelSchedaMadre->setMaximumSize(QSize(110,50));
    socketProcessoreLabelSchedaMadre->setMinimumSize(QSize(0,0));

    slotMemoriaLabelSchedaMadre=new QLabel("Slot "+(tr("memoria:")));
    slotMemoriaLabelSchedaMadre->setFont(font_formLabel);
    slotMemoriaLabelSchedaMadre->setMaximumSize(QSize(140,30));
    slotMemoriaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLabelSchedaMadre=new QLabel(tr("Tipologia \nmemoria:"));
    tipologiaMemoriaLabelSchedaMadre->setFont(font_formLabel);
    tipologiaMemoriaLabelSchedaMadre->setMaximumSize(QSize(90,50));
    tipologiaMemoriaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    memoriaMassimaLabelSchedaMadre=new QLabel(tr("Memoria massima:"));
    memoriaMassimaLabelSchedaMadre->setFont(font_formLabel);
    memoriaMassimaLabelSchedaMadre->setMaximumSize(QSize(190,30));
    memoriaMassimaLabelSchedaMadre->setMinimumSize(QSize(0,0));

    ethernetLabelSchedaMadre=new QLabel("Ethernet");
    ethernetLabelSchedaMadre->setFont(font_formLabel);
    ethernetLabelSchedaMadre->setMaximumSize(QSize(80,30));
    ethernetLabelSchedaMadre->setMinimumSize(QSize(0,0));

    sata3GBsLabelSchedaMadre=new QLabel("SATA 3GB/s:");
    sata3GBsLabelSchedaMadre->setFont(font_formLabel);
    sata3GBsLabelSchedaMadre->setMaximumSize(QSize(120,30));
    sata3GBsLabelSchedaMadre->setMinimumSize(QSize(0,0));

    sata6GBsLabelSchedaMadre=new QLabel("SATA 6GB/s:");
    sata6GBsLabelSchedaMadre->setFont(font_formLabel);
    sata6GBsLabelSchedaMadre->setMaximumSize(QSize(120,30));
    sata6GBsLabelSchedaMadre->setMinimumSize(QSize(0,0));

    sataExpressLabelSchedaMadre=new QLabel("SATA Express:");
    sataExpressLabelSchedaMadre->setFont(font_formLabel);
    sataExpressLabelSchedaMadre->setMaximumSize(QSize(140,30));
    sataExpressLabelSchedaMadre->setMinimumSize(QSize(0,0));

    usb2LabelSchedaMadre=new QLabel("USB 2.0:");
    usb2LabelSchedaMadre->setFont(font_formLabel);
    usb2LabelSchedaMadre->setMaximumSize(QSize(80,30));
    usb2LabelSchedaMadre->setMinimumSize(QSize(0,0));

    usb3LabelSchedaMadre=new QLabel("USB 3.0:");
    usb3LabelSchedaMadre->setFont(font_formLabel);
    usb3LabelSchedaMadre->setMaximumSize(QSize(80,30));
    usb3LabelSchedaMadre->setMinimumSize(QSize(0,0));

    nomeLabelProcessore=new QLabel(tr("Nome:"));
    nomeLabelProcessore->setFont(font_formLabel);
    nomeLabelProcessore->setMaximumSize(QSize(70,30));
    nomeLabelProcessore->setMinimumSize(QSize(0,0));

    prezzoLabelProcessore=new QLabel(tr("Prezzo:"));
    prezzoLabelProcessore->setFont(font_formLabel);
    prezzoLabelProcessore->setMaximumSize(QSize(80,30));
    prezzoLabelProcessore->setMinimumSize(QSize(0,0));

    produttoreLabelProcessore=new QLabel(tr("Produttore:"));
    produttoreLabelProcessore->setFont(font_formLabel);
    produttoreLabelProcessore->setMaximumSize(QSize(110,30));
    produttoreLabelProcessore->setMinimumSize(QSize(0,0));

    socketLabelProcessore=new QLabel("Socket "+(tr("processore:")));
    socketLabelProcessore->setFont(font_formLabel);
    socketLabelProcessore->setMaximumSize(QSize(70,30));
    socketLabelProcessore->setMinimumSize(QSize(0,0));

    larghezzaDatiLabelProcessore=new QLabel(tr("Larghezza dati:"));
    larghezzaDatiLabelProcessore->setFont(font_formLabel);
    larghezzaDatiLabelProcessore->setMaximumSize(QSize(150,30));
    larghezzaDatiLabelProcessore->setMinimumSize(QSize(0,0));

    frequenzaOperativaLabelProcessore=new QLabel(tr("Frequenza operativa:"));
    frequenzaOperativaLabelProcessore->setFont(font_formLabel);
    frequenzaOperativaLabelProcessore->setMaximumSize(QSize(200,30));
    frequenzaOperativaLabelProcessore->setMinimumSize(QSize(0,0));

    frequenzaTurboLabelProcessore=new QLabel(tr("Frequenza turbo:"));
    frequenzaTurboLabelProcessore->setFont(font_formLabel);
    frequenzaTurboLabelProcessore->setMaximumSize(QSize(170,30));
    frequenzaTurboLabelProcessore->setMinimumSize(QSize(0,0));

    numeroCoreLabelProcessore=new QLabel(tr("Numero ")+("core:"));
    numeroCoreLabelProcessore->setFont(font_formLabel);
    numeroCoreLabelProcessore->setMaximumSize(QSize(130,30));
    numeroCoreLabelProcessore->setMinimumSize(QSize(0,0));

    l1CacheLabelProcessore=new QLabel("L1 Cache:");
    l1CacheLabelProcessore->setFont(font_formLabel);
    l1CacheLabelProcessore->setMaximumSize(QSize(100,30));
    l1CacheLabelProcessore->setMinimumSize(QSize(0,0));

    l2CacheLabelProcessore=new QLabel("L2 Cache:");
    l2CacheLabelProcessore->setFont(font_formLabel);
    l2CacheLabelProcessore->setMaximumSize(QSize(100,30));
    l2CacheLabelProcessore->setMinimumSize(QSize(0,0));

    l3CacheLabelProcessore=new QLabel("L3 Cache:");
    l3CacheLabelProcessore->setFont(font_formLabel);
    l3CacheLabelProcessore->setMaximumSize(QSize(100,30));
    l3CacheLabelProcessore->setMinimumSize(QSize(0,0));

    litografiaLabelProcessore=new QLabel(tr("Litografia:"));
    litografiaLabelProcessore->setFont(font_formLabel);
    litografiaLabelProcessore->setMaximumSize(QSize(100,30));
    litografiaLabelProcessore->setMinimumSize(QSize(0,0));

    tdpLabelProcessore=new QLabel("TDP:");
    tdpLabelProcessore->setFont(font_formLabel);
    tdpLabelProcessore->setMaximumSize(QSize(50,30));
    tdpLabelProcessore->setMinimumSize(QSize(0,0));

    graficaIntegrataLabelProcessore=new QLabel(tr("Grafica integrata:"));
    graficaIntegrataLabelProcessore->setFont(font_formLabel);
    graficaIntegrataLabelProcessore->setMaximumSize(QSize(170,30));
    graficaIntegrataLabelProcessore->setMinimumSize(QSize(0,0));

    nomeLabelArchiviazione=new QLabel(tr("Nome:"));
    nomeLabelArchiviazione->setFont(font_formLabel);
    nomeLabelArchiviazione->setMaximumSize(QSize(70,30));
    nomeLabelArchiviazione->setMinimumSize(QSize(0,0));

    prezzoLabelArchiviazione=new QLabel(tr("Prezzo:"));
    prezzoLabelArchiviazione->setFont(font_formLabel);
    prezzoLabelArchiviazione->setMaximumSize(QSize(80,30));
    prezzoLabelArchiviazione->setMinimumSize(QSize(0,0));

    produttoreLabelArchiviazione=new QLabel(tr("Produttore:"));
    produttoreLabelArchiviazione->setFont(font_formLabel);
    produttoreLabelArchiviazione->setMaximumSize(QSize(110,30));
    produttoreLabelArchiviazione->setMinimumSize(QSize(0,0));

    tipologiaLabelArchiviazione=new QLabel(tr("Tipologia:"));
    tipologiaLabelArchiviazione->setFont(font_formLabel);
    tipologiaLabelArchiviazione->setMaximumSize(QSize(90,30));
    tipologiaLabelArchiviazione->setMinimumSize(QSize(0,0));

    capacitaLabelArchiviazione=new QLabel(tr("Capacità:"));
    capacitaLabelArchiviazione->setFont(font_formLabel);
    capacitaLabelArchiviazione->setMaximumSize(QSize(90,30));
    capacitaLabelArchiviazione->setMinimumSize(QSize(0,0));

    interfacciaLabelArchiviazione=new QLabel(tr("Interfaccia:"));
    interfacciaLabelArchiviazione->setFont(font_formLabel);
    interfacciaLabelArchiviazione->setMaximumSize(QSize(110,30));
    interfacciaLabelArchiviazione->setMinimumSize(QSize(0,0));

    cacheLabelArchiviazione=new QLabel("Cache");
    cacheLabelArchiviazione->setFont(font_formLabel);
    cacheLabelArchiviazione->setMaximumSize(QSize(70,30));
    cacheLabelArchiviazione->setMinimumSize(QSize(0,0));

    fattoreDiFormaLabelArchiviazione=new QLabel(tr("Fattore di forma:"));
    fattoreDiFormaLabelArchiviazione->setFont(font_formLabel);
    fattoreDiFormaLabelArchiviazione->setMaximumSize(QSize(160,30));
    fattoreDiFormaLabelArchiviazione->setMinimumSize(QSize(0,0));

    rpmLabelArchiviazione=new QLabel("RPM:");
    rpmLabelArchiviazione->setFont(font_formLabel);
    rpmLabelArchiviazione->setMaximumSize(QSize(50,30));
    rpmLabelArchiviazione->setMinimumSize(QSize(0,0));

    nomeLabelAlimentatore=new QLabel(tr("Nome:"));
    nomeLabelAlimentatore->setFont(font_formLabel);
    nomeLabelAlimentatore->setMaximumSize(QSize(70,30));
    nomeLabelAlimentatore->setMinimumSize(QSize(0,0));

    prezzoLabelAlimentatore=new QLabel(tr("Prezzo:"));
    prezzoLabelAlimentatore->setFont(font_formLabel);
    prezzoLabelAlimentatore->setMaximumSize(QSize(80,30));
    prezzoLabelAlimentatore->setMinimumSize(QSize(0,0));

    produttoreLabelAlimentatore=new QLabel(tr("Produttore:"));
    produttoreLabelAlimentatore->setFont(font_formLabel);
    produttoreLabelAlimentatore->setMaximumSize(QSize(110,30));
    produttoreLabelAlimentatore->setMinimumSize(QSize(0,0));

    tipologiaLabelAlimentatore=new QLabel(tr("Tipologia:"));
    tipologiaLabelAlimentatore->setFont(font_formLabel);
    tipologiaLabelAlimentatore->setMaximumSize(QSize(90,30));
    tipologiaLabelAlimentatore->setMinimumSize(QSize(0,0));

    wattaggioLabelAlimentatore=new QLabel(tr("Wattaggio:"));
    wattaggioLabelAlimentatore->setFont(font_formLabel);
    wattaggioLabelAlimentatore->setMaximumSize(QSize(110,30));
    wattaggioLabelAlimentatore->setMinimumSize(QSize(0,0));

    modulareLabelAlimentatore=new QLabel(tr("Modulare:"));
    modulareLabelAlimentatore->setFont(font_formLabel);
    modulareLabelAlimentatore->setMaximumSize(QSize(100,30));
    modulareLabelAlimentatore->setMinimumSize(QSize(0,0));

    certificazioneEfficienzaLabelAlimentatore=new QLabel(tr("Certificazione \nefficienza:"));
    certificazioneEfficienzaLabelAlimentatore->setFont(font_formLabel);
    certificazioneEfficienzaLabelAlimentatore->setMaximumSize(QSize(130,50));
    certificazioneEfficienzaLabelAlimentatore->setMinimumSize(QSize(0,0));

    efficienzaLabelAlimentatore=new QLabel(tr("Efficienza:"));
    efficienzaLabelAlimentatore->setFont(font_formLabel);
    efficienzaLabelAlimentatore->setMaximumSize(QSize(100,30));
    efficienzaLabelAlimentatore->setMinimumSize(QSize(0,0));

    nomeLabelDissipatoreProcessore=new QLabel(tr("Nome:"));
    nomeLabelDissipatoreProcessore->setFont(font_formLabel);
    nomeLabelDissipatoreProcessore->setMaximumSize(QSize(70,30));
    nomeLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    prezzoLabelDissipatoreProcessore=new QLabel(tr("Prezzo:"));
    prezzoLabelDissipatoreProcessore->setFont(font_formLabel);
    prezzoLabelDissipatoreProcessore->setMaximumSize(QSize(80,30));
    prezzoLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    produttoreLabelDissipatoreProcessore=new QLabel(tr("Produttore:"));
    produttoreLabelDissipatoreProcessore->setFont(font_formLabel);
    produttoreLabelDissipatoreProcessore->setMaximumSize(QSize(110,30));
    produttoreLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    socketSupportatiLabelDissipatoreProcessore=new QLabel("Socket "+(tr("supportati:")));
    socketSupportatiLabelDissipatoreProcessore->setFont(font_formLabel);
    socketSupportatiLabelDissipatoreProcessore->setMaximumSize(QSize(180,30));
    socketSupportatiLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    rpmVentolaLabelDissipatoreProcessore=new QLabel("RPM "+(tr("ventola:")));
    rpmVentolaLabelDissipatoreProcessore->setFont(font_formLabel);
    rpmVentolaLabelDissipatoreProcessore->setMaximumSize(QSize(130,30));
    rpmVentolaLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaLabelDissipatoreProcessore=new QLabel(tr("Altezza:"));
    altezzaLabelDissipatoreProcessore->setFont(font_formLabel);
    altezzaLabelDissipatoreProcessore->setMaximumSize(QSize(80,30));
    altezzaLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaRadiatoreLabelDissipatoreProcessore=new QLabel(tr("Altezza radiatore:"));
    altezzaRadiatoreLabelDissipatoreProcessore->setFont(font_formLabel);
    altezzaRadiatoreLabelDissipatoreProcessore->setMaximumSize(QSize(170,30));
    altezzaRadiatoreLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    livelloRumoreLabelDissipatoreProcessore=new QLabel(tr("Livello rumore:"));
    livelloRumoreLabelDissipatoreProcessore->setFont(font_formLabel);
    livelloRumoreLabelDissipatoreProcessore->setMaximumSize(QSize(150,30));
    livelloRumoreLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    nomeLabelCase=new QLabel(tr("Nome:"));
    nomeLabelCase->setFont(font_formLabel);
    nomeLabelCase->setMaximumSize(QSize(70,30));
    nomeLabelCase->setMinimumSize(QSize(0,0));

    prezzoLabelCase=new QLabel(tr("Prezzo:"));
    prezzoLabelCase->setFont(font_formLabel);
    prezzoLabelCase->setMaximumSize(QSize(80,30));
    prezzoLabelCase->setMinimumSize(QSize(0,0));

    produttoreLabelCase=new QLabel(tr("Produttore:"));
    produttoreLabelCase->setFont(font_formLabel);
    produttoreLabelCase->setMaximumSize(QSize(110,30));
    produttoreLabelCase->setMinimumSize(QSize(0,0));

    tipologiaLabelCase=new QLabel(tr("Tipologia:"));
    tipologiaLabelCase->setFont(font_formLabel);
    tipologiaLabelCase->setMaximumSize(QSize(90,30));
    tipologiaLabelCase->setMinimumSize(QSize(0,0));

    coloreLabelCase=new QLabel(tr("Colore:"));
    coloreLabelCase->setFont(font_formLabel);
    coloreLabelCase->setMaximumSize(QSize(70,30));
    coloreLabelCase->setMinimumSize(QSize(0,0));

    slotInterni25LabelCase=new QLabel("Slot "+(tr("interni 2.5:")));
    slotInterni25LabelCase->setFont(font_formLabel);
    slotInterni25LabelCase->setMaximumSize(QSize(160,30));
    slotInterni25LabelCase->setMinimumSize(QSize(0,0));

    slotInterni35LabelCase=new QLabel("Slot "+(tr("interni 3.5:")));
    slotInterni35LabelCase->setFont(font_formLabel);
    slotInterni35LabelCase->setMaximumSize(QSize(160,30));
    slotInterni35LabelCase->setMinimumSize(QSize(0,0));

    compatibilitaSchedaMadreLabelCase=new QLabel(tr("Compatibilità \nscheda madre:"));
    compatibilitaSchedaMadreLabelCase->setFont(font_formLabel);
    compatibilitaSchedaMadreLabelCase->setMaximumSize(QSize(140,50));
    compatibilitaSchedaMadreLabelCase->setMinimumSize(QSize(0,0));

    lunghezzaMassimaSchedaGraficaLabelCase=new QLabel(tr("Lunghezza massima \nscheda grafica:"));
    lunghezzaMassimaSchedaGraficaLabelCase->setFont(font_formLabel);
    lunghezzaMassimaSchedaGraficaLabelCase->setMaximumSize(QSize(200,50));
    lunghezzaMassimaSchedaGraficaLabelCase->setMinimumSize(QSize(0,0));

    dimensioniLabelCase=new QLabel(tr("Dimensioni:"));
    dimensioniLabelCase->setFont(font_formLabel);
    dimensioniLabelCase->setMaximumSize(QSize(120,30));
    dimensioniLabelCase->setMinimumSize(QSize(0,0));

    nomeLabelUnitaOttica=new QLabel(tr("Nome:"));
    nomeLabelUnitaOttica->setFont(font_formLabel);
    nomeLabelUnitaOttica->setMaximumSize(QSize(70,30));
    nomeLabelUnitaOttica->setMinimumSize(QSize(0,0));

    prezzoLabelUnitaOttica=new QLabel(tr("Prezzo:"));
    prezzoLabelUnitaOttica->setFont(font_formLabel);
    prezzoLabelUnitaOttica->setMaximumSize(QSize(80,30));
    prezzoLabelUnitaOttica->setMinimumSize(QSize(0,0));

    produttoreLabelUnitaOttica=new QLabel(tr("Produttore:"));
    produttoreLabelUnitaOttica->setFont(font_formLabel);
    produttoreLabelUnitaOttica->setMaximumSize(QSize(110,30));
    produttoreLabelUnitaOttica->setMinimumSize(QSize(0,0));

    fattoreDiFormaLabelUnitaOttica=new QLabel(tr("Fattore di forma:"));
    fattoreDiFormaLabelUnitaOttica->setFont(font_formLabel);
    fattoreDiFormaLabelUnitaOttica->setMaximumSize(QSize(160,30));
    fattoreDiFormaLabelUnitaOttica->setMinimumSize(QSize(0,0));

    interfacciaLabelUnitaOttica=new QLabel(tr("Interfaccia:"));
    interfacciaLabelUnitaOttica->setFont(font_formLabel);
    interfacciaLabelUnitaOttica->setMaximumSize(QSize(110,30));
    interfacciaLabelUnitaOttica->setMinimumSize(QSize(0,0));

    cacheLabelUnitaOttica=new QLabel("Cache:");
    cacheLabelUnitaOttica->setFont(font_formLabel);
    cacheLabelUnitaOttica->setMaximumSize(QSize(70,30));
    cacheLabelUnitaOttica->setMinimumSize(QSize(0,0));

    velocitaLabelUnitaOttica=new QLabel(tr("Velocità:"));
    velocitaLabelUnitaOttica->setFont(font_formLabel);
    velocitaLabelUnitaOttica->setMaximumSize(QSize(90,30));
    velocitaLabelUnitaOttica->setMinimumSize(QSize(0,0));

    nomeLabelMonitor=new QLabel(tr("Nome:"));
    nomeLabelMonitor->setFont(font_formLabel);
    nomeLabelMonitor->setMaximumSize(QSize(70,30));
    nomeLabelMonitor->setMinimumSize(QSize(0,0));

    prezzoLabelMonitor=new QLabel(tr("Prezzo:"));
    prezzoLabelMonitor->setFont(font_formLabel);
    prezzoLabelMonitor->setMaximumSize(QSize(80,30));
    prezzoLabelMonitor->setMinimumSize(QSize(0,0));

    produttoreLabelMonitor=new QLabel(tr("Produttore:"));
    produttoreLabelMonitor->setFont(font_formLabel);
    produttoreLabelMonitor->setMaximumSize(QSize(110,30));
    produttoreLabelMonitor->setMinimumSize(QSize(0,0));

    risoluzioneRaccomandataLabelMonitor=new QLabel(tr("Risoluzione \nraccomandata:"));
    risoluzioneRaccomandataLabelMonitor->setFont(font_formLabel);
    risoluzioneRaccomandataLabelMonitor->setMaximumSize(QSize(150,50));
    risoluzioneRaccomandataLabelMonitor->setMinimumSize(QSize(0,0));

    formatoLabelMonitor=new QLabel(tr("Formato:"));
    formatoLabelMonitor->setFont(font_formLabel);
    formatoLabelMonitor->setMaximumSize(QSize(90,30));
    formatoLabelMonitor->setMinimumSize(QSize(0,0));

    angoloDiVisualizzazioneLabelMonitor=new QLabel(tr("Angolo di \nvisualizzazione:"));
    angoloDiVisualizzazioneLabelMonitor->setFont(font_formLabel);
    angoloDiVisualizzazioneLabelMonitor->setMaximumSize(QSize(150,50));
    angoloDiVisualizzazioneLabelMonitor->setMinimumSize(QSize(0,0));

    coloriDelDisplayLabelMonitor=new QLabel(tr("Colori del ")+("display:"));
    coloriDelDisplayLabelMonitor->setFont(font_formLabel);
    coloriDelDisplayLabelMonitor->setMaximumSize(QSize(170,30));
    coloriDelDisplayLabelMonitor->setMinimumSize(QSize(0,0));

    luminositaLabelMonitor=new QLabel(tr("Luminosità:"));
    luminositaLabelMonitor->setFont(font_formLabel);
    luminositaLabelMonitor->setMaximumSize(QSize(110,30));
    luminositaLabelMonitor->setMinimumSize(QSize(0,0));

    rapportoDiContrastoLabelMonitor=new QLabel(tr("Rapporto di \ncontrasto:"));
    rapportoDiContrastoLabelMonitor->setFont(font_formLabel);
    rapportoDiContrastoLabelMonitor->setMaximumSize(QSize(120,50));
    rapportoDiContrastoLabelMonitor->setMinimumSize(QSize(0,0));

    tempoDiRispostaLabelMonitor=new QLabel(tr("Tempo di risposta:"));
    tempoDiRispostaLabelMonitor->setFont(font_formLabel);
    tempoDiRispostaLabelMonitor->setMaximumSize(QSize(200,30));
    tempoDiRispostaLabelMonitor->setMinimumSize(QSize(0,0));

    tipologiaDisplayLabelMonitor=new QLabel(tr("Tipologia ")+("display:"));
    tipologiaDisplayLabelMonitor->setFont(font_formLabel);
    tipologiaDisplayLabelMonitor->setMaximumSize(QSize(170,30));
    tipologiaDisplayLabelMonitor->setMinimumSize(QSize(0,0));

    frequenzaDiAggiornamentoLabelMonitor=new QLabel(tr("Frequenza di \naggiornamento:"));
    frequenzaDiAggiornamentoLabelMonitor->setFont(font_formLabel);
    frequenzaDiAggiornamentoLabelMonitor->setMaximumSize(QSize(150,50));
    frequenzaDiAggiornamentoLabelMonitor->setMinimumSize(QSize(0,0));

    nomeLabelSistemaOperativo=new QLabel(tr("Nome:"));
    nomeLabelSistemaOperativo->setFont(font_formLabel);
    nomeLabelSistemaOperativo->setMaximumSize(QSize(70,30));
    nomeLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    prezzoLabelSistemaOperativo=new QLabel(tr("Prezzo:"));
    prezzoLabelSistemaOperativo->setFont(font_formLabel);
    prezzoLabelSistemaOperativo->setMaximumSize(QSize(80,30));
    prezzoLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    produttoreLabelSistemaOperativo=new QLabel(tr("Produttore:"));
    produttoreLabelSistemaOperativo->setFont(font_formLabel);
    produttoreLabelSistemaOperativo->setMaximumSize(QSize(110,30));
    produttoreLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    modalitaLabelSistemaOperativo=new QLabel(tr("Modalità:"));
    modalitaLabelSistemaOperativo->setFont(font_formLabel);
    modalitaLabelSistemaOperativo->setMaximumSize(QSize(90,30));
    modalitaLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    memoriaMassimaSupportataLabelSistemaOperativo=new QLabel(tr("Memoria massima supportata:"));
    memoriaMassimaSupportataLabelSistemaOperativo->setFont(font_formLabel);
    memoriaMassimaSupportataLabelSistemaOperativo->setMaximumSize(QSize(180,50));
    memoriaMassimaSupportataLabelSistemaOperativo->setMinimumSize(QSize(0,0));

    nomeLabelMouse=new QLabel(tr("Nome:"));
    nomeLabelMouse->setFont(font_formLabel);
    nomeLabelMouse->setMaximumSize(QSize(70,30));
    nomeLabelMouse->setMinimumSize(QSize(0,0));

    prezzoLabelMouse=new QLabel(tr("Prezzo:"));
    prezzoLabelMouse->setFont(font_formLabel);
    prezzoLabelMouse->setMaximumSize(QSize(80,30));
    prezzoLabelMouse->setMinimumSize(QSize(0,0));

    produttoreLabelMouse=new QLabel(tr("Produttore:"));
    produttoreLabelMouse->setFont(font_formLabel);
    produttoreLabelMouse->setMaximumSize(QSize(110,30));
    produttoreLabelMouse->setMinimumSize(QSize(0,0));

    connessioneLabelMouse=new QLabel(tr("Connessione:"));
    connessioneLabelMouse->setFont(font_formLabel);
    connessioneLabelMouse->setMaximumSize(QSize(130,30));
    connessioneLabelMouse->setMinimumSize(QSize(0,0));

    tipologiaTracciamentoLabelMouse=new QLabel(tr("Tipologia tracciamento:"));
    tipologiaTracciamentoLabelMouse->setFont(font_formLabel);
    tipologiaTracciamentoLabelMouse->setMaximumSize(QSize(230,30));
    tipologiaTracciamentoLabelMouse->setMinimumSize(QSize(0,0));

    dpiMassimiLabelMouse=new QLabel("DPI "+(tr("massimi:")));
    dpiMassimiLabelMouse->setFont(font_formLabel);
    dpiMassimiLabelMouse->setMaximumSize(QSize(130,30));
    dpiMassimiLabelMouse->setMinimumSize(QSize(0,0));

    coloreLabelMouse=new QLabel(tr("Colore:"));
    coloreLabelMouse->setFont(font_formLabel);
    coloreLabelMouse->setMaximumSize(QSize(70,30));
    coloreLabelMouse->setMinimumSize(QSize(0,0));

    orientamentoDellaManoLabelMouse=new QLabel(tr("Orientamento della mano:"));
    orientamentoDellaManoLabelMouse->setFont(font_formLabel);
    orientamentoDellaManoLabelMouse->setMaximumSize(QSize(140,50));
    orientamentoDellaManoLabelMouse->setMinimumSize(QSize(0,0));

    nomeLabelTastiera=new QLabel(tr("Nome:"));
    nomeLabelTastiera->setFont(font_formLabel);
    nomeLabelTastiera->setMaximumSize(QSize(70,30));
    nomeLabelTastiera->setMinimumSize(QSize(0,0));

    prezzoLabelTastiera=new QLabel(tr("Prezzo:"));
    prezzoLabelTastiera->setFont(font_formLabel);
    prezzoLabelTastiera->setMaximumSize(QSize(80,30));
    prezzoLabelTastiera->setMinimumSize(QSize(0,0));

    produttoreLabelTastiera=new QLabel(tr("Produttore:"));
    produttoreLabelTastiera->setFont(font_formLabel);
    produttoreLabelTastiera->setMaximumSize(QSize(110,30));
    produttoreLabelTastiera->setMinimumSize(QSize(0,0));

    coloreLabelTastiera=new QLabel(tr("Colore:"));
    coloreLabelTastiera->setFont(font_formLabel);
    coloreLabelTastiera->setMaximumSize(QSize(70,30));
    coloreLabelTastiera->setMinimumSize(QSize(0,0));

    connessioneLabelTastiera=new QLabel(tr("Connessione:"));
    connessioneLabelTastiera->setFont(font_formLabel);
    connessioneLabelTastiera->setMaximumSize(QSize(130,30));
    connessioneLabelTastiera->setMinimumSize(QSize(0,0));

    tipologiaLabelTastiera=new QLabel(tr("Tipologia:"));
    tipologiaLabelTastiera->setFont(font_formLabel);
    tipologiaLabelTastiera->setMaximumSize(QSize(90,30));
    tipologiaLabelTastiera->setMinimumSize(QSize(0,0));

    tipologiaSwitchLabelTastiera=new QLabel(tr("Tipologia ")+("switch:"));
    tipologiaSwitchLabelTastiera->setFont(font_formLabel);
    tipologiaSwitchLabelTastiera->setMaximumSize(QSize(160,30));
    tipologiaSwitchLabelTastiera->setMinimumSize(QSize(0,0));

    nomeLabelCuffie=new QLabel(tr("Nome:"));
    nomeLabelCuffie->setFont(font_formLabel);
    nomeLabelCuffie->setMaximumSize(QSize(70,30));
    nomeLabelCuffie->setMinimumSize(QSize(0,0));

    prezzoLabelCuffie=new QLabel(tr("Prezzo:"));
    prezzoLabelCuffie->setFont(font_formLabel);
    prezzoLabelCuffie->setMaximumSize(QSize(80,30));
    prezzoLabelCuffie->setMinimumSize(QSize(0,0));

    produttoreLabelCuffie=new QLabel(tr("Produttore:"));
    produttoreLabelCuffie->setFont(font_formLabel);
    produttoreLabelCuffie->setMaximumSize(QSize(110,30));
    produttoreLabelCuffie->setMinimumSize(QSize(0,0));

    tipologiaLabelCuffie=new QLabel(tr("Tipologia:"));
    tipologiaLabelCuffie->setFont(font_formLabel);
    tipologiaLabelCuffie->setMaximumSize(QSize(90,30));
    tipologiaLabelCuffie->setMinimumSize(QSize(0,0));

    sistemaAcusticoLabelCuffie=new QLabel(tr("Sistema acustico:"));
    sistemaAcusticoLabelCuffie->setFont(font_formLabel);
    sistemaAcusticoLabelCuffie->setMaximumSize(QSize(170,30));
    sistemaAcusticoLabelCuffie->setMinimumSize(QSize(0,0));

    coloreLabelCuffie=new QLabel(tr("Colore:"));
    coloreLabelCuffie->setFont(font_formLabel);
    coloreLabelCuffie->setMaximumSize(QSize(70,30));
    coloreLabelCuffie->setMinimumSize(QSize(0,0));

    canaliLabelCuffie=new QLabel(tr("Canali:"));
    canaliLabelCuffie->setFont(font_formLabel);
    canaliLabelCuffie->setMaximumSize(QSize(70,30));
    canaliLabelCuffie->setMinimumSize(QSize(0,0));

    impedenzaLabelCuffie=new QLabel(tr("Impedenza:"));
    impedenzaLabelCuffie->setFont(font_formLabel);
    impedenzaLabelCuffie->setMaximumSize(QSize(120,30));
    impedenzaLabelCuffie->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLabelCuffie=new QLabel(tr("Frequenza di \nrisposta:"));
    frequenzaDiRispostaLabelCuffie->setFont(font_formLabel);
    frequenzaDiRispostaLabelCuffie->setMaximumSize(QSize(120,50));
    frequenzaDiRispostaLabelCuffie->setMinimumSize(QSize(0,0));

    connessioneLabelCuffie=new QLabel(tr("Connessione:"));
    connessioneLabelCuffie->setFont(font_formLabel);
    connessioneLabelCuffie->setMaximumSize(QSize(130,30));
    connessioneLabelCuffie->setMinimumSize(QSize(0,0));

    connettoreLabelCuffie=new QLabel(tr("Connettore:"));
    connettoreLabelCuffie->setFont(font_formLabel);
    connettoreLabelCuffie->setMaximumSize(QSize(120,30));
    connettoreLabelCuffie->setMinimumSize(QSize(0,0));

    nomeLabelAltoparlanti=new QLabel(tr("Nome:"));
    nomeLabelAltoparlanti->setFont(font_formLabel);
    nomeLabelAltoparlanti->setMaximumSize(QSize(70,30));
    nomeLabelAltoparlanti->setMinimumSize(QSize(0,0));

    prezzoLabelAltoparlanti=new QLabel(tr("Prezzo:"));
    prezzoLabelAltoparlanti->setFont(font_formLabel);
    prezzoLabelAltoparlanti->setMaximumSize(QSize(80,30));
    prezzoLabelAltoparlanti->setMinimumSize(QSize(0,0));

    produttoreLabelAltoparlanti=new QLabel(tr("Produttore:"));
    produttoreLabelAltoparlanti->setFont(font_formLabel);
    produttoreLabelAltoparlanti->setMaximumSize(QSize(110,30));
    produttoreLabelAltoparlanti->setMinimumSize(QSize(0,0));

    coloreLabelAltoparlanti=new QLabel(tr("Colore:"));
    coloreLabelAltoparlanti->setFont(font_formLabel);
    coloreLabelAltoparlanti->setMaximumSize(QSize(70,30));
    coloreLabelAltoparlanti->setMinimumSize(QSize(0,0));

    configurazioneLabelAltoparlanti=new QLabel(tr("Configurazione:"));
    configurazioneLabelAltoparlanti->setFont(font_formLabel);
    configurazioneLabelAltoparlanti->setMaximumSize(QSize(150,30));
    configurazioneLabelAltoparlanti->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLabelAltoparlanti=new QLabel(tr("Frequenza di \nrisposta:"));
    frequenzaDiRispostaLabelAltoparlanti->setFont(font_formLabel);
    frequenzaDiRispostaLabelAltoparlanti->setMaximumSize(QSize(120,50));
    frequenzaDiRispostaLabelAltoparlanti->setMinimumSize(QSize(0,0));

    potenzaTotaleLabelAltoparlanti=new QLabel(tr("Potenza totale:"));
    potenzaTotaleLabelAltoparlanti->setFont(font_formLabel);
    potenzaTotaleLabelAltoparlanti->setMaximumSize(QSize(150,30));
    potenzaTotaleLabelAltoparlanti->setMinimumSize(QSize(0,0));

    potenzeLabelAltoparlanti=new QLabel(tr("Potenze:"));
    potenzeLabelAltoparlanti->setFont(font_formLabel);
    potenzeLabelAltoparlanti->setMaximumSize(QSize(90,30));
    potenzeLabelAltoparlanti->setMinimumSize(QSize(0,0));
}

void MyWidget_GestisciComponentiPCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));

    aggiungiPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiPushButton->setMaximumSize(QSize(160,60));
    aggiungiPushButton->setMinimumSize(QSize(0,0));

    rimuoviPushButton=new QPushButton(tr("Rimuovi"));
    rimuoviPushButton->setMaximumSize(160,60);
    rimuoviPushButton->setMinimumSize(QSize(0,0));
}

void MyWidget_GestisciComponentiPCBuilder::createCheckBoxes(){
    supportoRAIDCheckBoxSchedaMadre=new QCheckBox(tr("Supporto ")+("RAID"));
    supportoRAIDCheckBoxSchedaMadre->setMaximumSize(QSize(110,30));
    supportoRAIDCheckBoxSchedaMadre->setMinimumSize(QSize(0,0));

    supportoCrossfireCheckBoxSchedaMadre=new QCheckBox(tr("Supporto ")+("Crossfire"));
    supportoCrossfireCheckBoxSchedaMadre->setMaximumSize(QSize(140,30));
    supportoCrossfireCheckBoxSchedaMadre->setMinimumSize(QSize(0,0));

    supportoSLICheckBoxSchedaMadre=new QCheckBox(tr("Supporto ")+("SLI"));
    supportoSLICheckBoxSchedaMadre->setMaximumSize(QSize(100,30));
    supportoSLICheckBoxSchedaMadre->setMinimumSize(QSize(0,0));

    includeDissipatoreCheckBoxProcessore=new QCheckBox(tr("Include dissipatore processore"));
    includeDissipatoreCheckBoxProcessore->setMaximumSize(QSize(210,30));
    includeDissipatoreCheckBoxProcessore->setMinimumSize(QSize(0,0));

    hyperThreadingCheckBoxProcessore=new QCheckBox("Hyper-Threading");
    hyperThreadingCheckBoxProcessore->setMaximumSize(QSize(120,30));
    hyperThreadingCheckBoxProcessore->setMinimumSize(QSize(0,0));

    raffreddamentoALiquidoCheckBoxDissipatoreProcessore=new QCheckBox(tr("Raffreddamento a liquido"));
    raffreddamentoALiquidoCheckBoxDissipatoreProcessore->setMaximumSize(QSize(180,30));
    raffreddamentoALiquidoCheckBoxDissipatoreProcessore->setMinimumSize(QSize(0,0));

    alimentatoreInclusoCheckBoxCase=new QCheckBox(tr("Alimentatore incluso"));
    alimentatoreInclusoCheckBoxCase->setMaximumSize(QSize(150,30));
    alimentatoreInclusoCheckBoxCase->setMinimumSize(QSize(0,0));

    altoparlantiIncorporatiCheckBoxMonitor=new QCheckBox(tr("Altoparlanti incorporati"));
    altoparlantiIncorporatiCheckBoxMonitor->setMaximumSize(QSize(160,30));
    altoparlantiIncorporatiCheckBoxMonitor->setMinimumSize(QSize(0,0));

    widescreenCheckBoxMonitor=new QCheckBox("Widescreen");
    widescreenCheckBoxMonitor->setMaximumSize(QSize(90,30));
    widescreenCheckBoxMonitor->setMinimumSize(QSize(0,0));

    retroilluminazioneCheckBoxTastiera=new QCheckBox(tr("Retroilluminazione"));
    retroilluminazioneCheckBoxTastiera->setMaximumSize(QSize(140,30));
    retroilluminazioneCheckBoxTastiera->setMinimumSize(QSize(0,0));

    microfonoCheckBoxCuffie=new QCheckBox(tr("Microfono"));
    microfonoCheckBoxCuffie->setMaximumSize(QSize(80,30));
    microfonoCheckBoxCuffie->setMinimumSize(QSize(0,0));
}

void MyWidget_GestisciComponentiPCBuilder::createComboBoxes(){
    tipo_componenteAggiungi=new QComboBox;
    tipo_componenteAggiungi->setMaximumSize(QSize(250,25));
    tipo_componenteAggiungi->setMinimumSize(QSize(0,0));
    tipo_componenteAggiungi->addItem(tr("Seleziona il componente"));
    tipo_componenteAggiungi->addItem(tr("Memoria"));
    tipo_componenteAggiungi->addItem(tr("Scheda grafica"));
    tipo_componenteAggiungi->addItem(tr("Scheda madre"));
    tipo_componenteAggiungi->addItem(tr("Processore"));
    tipo_componenteAggiungi->addItem(tr("Archiviazione"));
    tipo_componenteAggiungi->addItem(tr("Alimentatore"));
    tipo_componenteAggiungi->addItem(tr("Dissipatore processore"));
    tipo_componenteAggiungi->addItem(tr("Case"));
    tipo_componenteAggiungi->addItem(tr("Unità ottica"));
    tipo_componenteAggiungi->addItem(tr("Monitor"));
    tipo_componenteAggiungi->addItem(tr("Sistema operativo"));
    tipo_componenteAggiungi->addItem(tr("Mouse"));
    tipo_componenteAggiungi->addItem(tr("Tastiera"));
    tipo_componenteAggiungi->addItem(tr("Cuffie"));
    tipo_componenteAggiungi->addItem(tr("Altoparlanti"));
}

void MyWidget_GestisciComponentiPCBuilder::createLineEdits(){
    nomeLineEditMemoria=new QLineEdit;
    nomeLineEditMemoria->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditMemoria->setMaximumSize(QSize(200,30));
    nomeLineEditMemoria->setMinimumSize(QSize(0,0));

    produttoreLineEditMemoria=new QLineEdit;
    produttoreLineEditMemoria->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditMemoria->setMaximumSize(QSize(200,30));
    produttoreLineEditMemoria->setMinimumSize(QSize(0,0));

    velocitaLineEditMemoria=new QLineEdit;
    velocitaLineEditMemoria->setPlaceholderText(tr("Inserire velocita"));
    velocitaLineEditMemoria->setMaximumSize(QSize(200,30));
    velocitaLineEditMemoria->setMinimumSize(QSize(0,0));

    capacitaLineEditMemoria=new QLineEdit;
    capacitaLineEditMemoria->setPlaceholderText(tr("Inserire capacità"));
    capacitaLineEditMemoria->setMaximumSize(QSize(200,30));
    capacitaLineEditMemoria->setMinimumSize(QSize(0,0));

    tipologiaLineEditMemoria=new QLineEdit;
    tipologiaLineEditMemoria->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditMemoria->setMaximumSize(QSize(200,30));
    tipologiaLineEditMemoria->setMinimumSize(QSize(0,0));

    nomeLineEditSchedaGrafica=new QLineEdit;
    nomeLineEditSchedaGrafica->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    nomeLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    produttoreLineEditSchedaGrafica=new QLineEdit;
    produttoreLineEditSchedaGrafica->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    produttoreLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    interfacciaLineEditSchedaGrafica=new QLineEdit;
    interfacciaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire interfaccia"));
    interfacciaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    interfacciaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    chipsetLineEditSchedaGrafica=new QLineEdit;
    chipsetLineEditSchedaGrafica->setPlaceholderText(tr("Inserire chipset"));
    chipsetLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    chipsetLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    memoriaLineEditSchedaGrafica=new QLineEdit;
    memoriaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire memoria"));
    memoriaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    memoriaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLineEditSchedaGrafica=new QLineEdit;
    tipologiaMemoriaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire tipologia memoria"));
    tipologiaMemoriaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    tipologiaMemoriaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    frequenzaCoreLineEditSchedaGrafica=new QLineEdit;
    frequenzaCoreLineEditSchedaGrafica->setPlaceholderText(tr("Inserire frequenza core"));
    frequenzaCoreLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    frequenzaCoreLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    tdpLineEditSchedaGrafica=new QLineEdit;
    tdpLineEditSchedaGrafica->setPlaceholderText(tr("Inserire TDP"));
    tdpLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    tdpLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoSLILineEditSchedaGrafica=new QLineEdit;
    supportoSLILineEditSchedaGrafica->setPlaceholderText(tr("Inserire supporto SLI"));
    supportoSLILineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    supportoSLILineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    supportoCrossfireLineEditSchedaGrafica=new QLineEdit;
    nomeLineEditSchedaGrafica->setPlaceholderText(tr("Inserire supporto Crossfire"));
    supportoCrossfireLineEditSchedaGrafica->setPlaceholderText(tr(""));
    supportoCrossfireLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    supportoCrossfireLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    lunghezzaLineEditSchedaGrafica=new QLineEdit;
    lunghezzaLineEditSchedaGrafica->setPlaceholderText(tr("Inserire lunghezza"));
    lunghezzaLineEditSchedaGrafica->setMaximumSize(QSize(200,30));
    lunghezzaLineEditSchedaGrafica->setMinimumSize(QSize(0,0));

    nomeLineEditSchedaMadre=new QLineEdit;
    nomeLineEditSchedaMadre->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    nomeLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    produttoreLineEditSchedaMadre=new QLineEdit;
    produttoreLineEditSchedaMadre->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    produttoreLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    fattoreDiFormaLineEditSchedaMadre=new QLineEdit;
    fattoreDiFormaLineEditSchedaMadre->setPlaceholderText(tr("Inserire fattore di forma"));
    fattoreDiFormaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    fattoreDiFormaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    chipsetLineEditSchedaMadre=new QLineEdit;
    chipsetLineEditSchedaMadre->setPlaceholderText(tr("Inserire chipset"));
    chipsetLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    chipsetLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    socketProcessoreLineEditSchedaMadre=new QLineEdit;
    socketProcessoreLineEditSchedaMadre->setPlaceholderText(tr("Inserire socket processore"));
    socketProcessoreLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    socketProcessoreLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    slotMemoriaLineEditSchedaMadre=new QLineEdit;
    slotMemoriaLineEditSchedaMadre->setPlaceholderText(tr("Inserire slot memoria"));
    slotMemoriaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    slotMemoriaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    tipologiaMemoriaLineEditSchedaMadre=new QLineEdit;
    tipologiaMemoriaLineEditSchedaMadre->setPlaceholderText(tr("Inserire tipologia memoria"));
    tipologiaMemoriaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    tipologiaMemoriaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    memoriaMassimaLineEditSchedaMadre=new QLineEdit;
    memoriaMassimaLineEditSchedaMadre->setPlaceholderText(tr("Inserire memoria massima"));
    memoriaMassimaLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    memoriaMassimaLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    ethernetLineEditSchedaMadre=new QLineEdit;
    ethernetLineEditSchedaMadre->setPlaceholderText(tr("Inserire ethernet"));
    ethernetLineEditSchedaMadre->setMaximumSize(QSize(200,30));
    ethernetLineEditSchedaMadre->setMinimumSize(QSize(0,0));

    nomeLineEditProcessore=new QLineEdit;
    nomeLineEditProcessore->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditProcessore->setMaximumSize(QSize(200,30));
    nomeLineEditProcessore->setMinimumSize(QSize(0,0));

    produttoreLineEditProcessore=new QLineEdit;
    produttoreLineEditProcessore->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditProcessore->setMaximumSize(QSize(200,30));
    produttoreLineEditProcessore->setMinimumSize(QSize(0,0));

    socketLineEditProcessore=new QLineEdit;
    socketLineEditProcessore->setPlaceholderText(tr("Inserire socket"));
    socketLineEditProcessore->setMaximumSize(QSize(200,30));
    socketLineEditProcessore->setMinimumSize(QSize(0,0));

    larghezzaDatiLineEditProcessore=new QLineEdit;
    larghezzaDatiLineEditProcessore->setPlaceholderText(tr("Inserire larghezza dati"));
    larghezzaDatiLineEditProcessore->setMaximumSize(QSize(200,30));
    larghezzaDatiLineEditProcessore->setMinimumSize(QSize(0,0));

    frequenzaOperativaLineEditProcessore=new QLineEdit;
    frequenzaOperativaLineEditProcessore->setPlaceholderText(tr("Inserire frequenza operativa"));
    frequenzaOperativaLineEditProcessore->setMaximumSize(QSize(200,30));
    frequenzaOperativaLineEditProcessore->setMinimumSize(QSize(0,0));

    frequenzaTurboLineEditProcessore=new QLineEdit;
    frequenzaTurboLineEditProcessore->setPlaceholderText(tr("Inserire frequenza turbo"));
    frequenzaTurboLineEditProcessore->setMaximumSize(QSize(200,30));
    frequenzaTurboLineEditProcessore->setMinimumSize(QSize(0,0));

    l1CacheLineEditProcessore=new QLineEdit;
    l1CacheLineEditProcessore->setPlaceholderText(tr("Inserire L1Cache"));
    l1CacheLineEditProcessore->setMaximumSize(QSize(200,30));
    l1CacheLineEditProcessore->setMinimumSize(QSize(0,0));

    l2CacheLineEditProcessore=new QLineEdit;
    l2CacheLineEditProcessore->setPlaceholderText(tr("Inserire L2Cache"));
    l2CacheLineEditProcessore->setMaximumSize(QSize(200,30));
    l2CacheLineEditProcessore->setMinimumSize(QSize(0,0));

    l3CacheLineEditProcessore=new QLineEdit;
    l3CacheLineEditProcessore->setPlaceholderText(tr("Inserire L3Cache"));
    l3CacheLineEditProcessore->setMaximumSize(QSize(200,30));
    l3CacheLineEditProcessore->setMinimumSize(QSize(0,0));

    litografiaLineEditProcessore=new QLineEdit;
    litografiaLineEditProcessore->setPlaceholderText(tr("Inserire litografia"));
    litografiaLineEditProcessore->setMaximumSize(QSize(200,30));
    litografiaLineEditProcessore->setMinimumSize(QSize(0,0));

    tdpLineEditProcessore=new QLineEdit;
    tdpLineEditProcessore->setPlaceholderText(tr("Inserire TDP"));
    tdpLineEditProcessore->setMaximumSize(QSize(200,30));
    tdpLineEditProcessore->setMinimumSize(QSize(0,0));

    graficaIntegrataLineEditProcessore=new QLineEdit;
    graficaIntegrataLineEditProcessore->setPlaceholderText(tr("Inserire grafica integrata"));
    graficaIntegrataLineEditProcessore->setMaximumSize(QSize(200,30));
    graficaIntegrataLineEditProcessore->setMinimumSize(QSize(0,0));

    nomeLineEditArchiviazione=new QLineEdit;
    nomeLineEditArchiviazione->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditArchiviazione->setMaximumSize(QSize(200,30));
    nomeLineEditArchiviazione->setMinimumSize(QSize(0,0));

    produttoreLineEditArchiviazione=new QLineEdit;
    produttoreLineEditArchiviazione->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditArchiviazione->setMaximumSize(QSize(200,30));
    produttoreLineEditArchiviazione->setMinimumSize(QSize(0,0));

    tipologiaLineEditArchiviazione=new QLineEdit;
    tipologiaLineEditArchiviazione->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    tipologiaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    capacitaLineEditArchiviazione=new QLineEdit;
    capacitaLineEditArchiviazione->setPlaceholderText(tr("Inserire capacità"));
    capacitaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    capacitaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    interfacciaLineEditArchiviazione=new QLineEdit;
    interfacciaLineEditArchiviazione->setPlaceholderText(tr("Inserire interfaccia"));
    interfacciaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    interfacciaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    cacheLineEditArchiviazione=new QLineEdit;
    cacheLineEditArchiviazione->setPlaceholderText(tr("Inserire cache"));
    cacheLineEditArchiviazione->setMaximumSize(QSize(200,30));
    cacheLineEditArchiviazione->setMinimumSize(QSize(0,0));

    fattoreDiFormaLineEditArchiviazione=new QLineEdit;
    fattoreDiFormaLineEditArchiviazione->setPlaceholderText(tr("Inserire fattore di forma"));
    fattoreDiFormaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    fattoreDiFormaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    rpmLineEditArchiviazione=new QLineEdit;
    rpmLineEditArchiviazione->setPlaceholderText(tr("Inserire RPM"));
    rpmLineEditArchiviazione->setMaximumSize(QSize(200,30));
    rpmLineEditArchiviazione->setMinimumSize(QSize(0,0));

    nomeLineEditAlimentatore=new QLineEdit;
    nomeLineEditAlimentatore->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditAlimentatore->setMaximumSize(QSize(200,30));
    nomeLineEditAlimentatore->setMinimumSize(QSize(0,0));

    produttoreLineEditAlimentatore=new QLineEdit;
    produttoreLineEditAlimentatore->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditAlimentatore->setMaximumSize(QSize(200,30));
    produttoreLineEditAlimentatore->setMinimumSize(QSize(0,0));

    tipologiaLineEditAlimentatore=new QLineEdit;
    tipologiaLineEditAlimentatore->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditAlimentatore->setMaximumSize(QSize(200,30));
    tipologiaLineEditAlimentatore->setMinimumSize(QSize(0,0));

    wattaggioLineEditAlimentatore=new QLineEdit;
    wattaggioLineEditAlimentatore->setPlaceholderText(tr("Inserire wattaggio"));
    wattaggioLineEditAlimentatore->setMaximumSize(QSize(200,30));
    wattaggioLineEditAlimentatore->setMinimumSize(QSize(0,0));

    modulareLineEditAlimentatore=new QLineEdit;
    modulareLineEditAlimentatore->setPlaceholderText(tr("Inserire modularità"));
    modulareLineEditAlimentatore->setMaximumSize(QSize(200,30));
    modulareLineEditAlimentatore->setMinimumSize(QSize(0,0));

    certificazioneEfficienzaLineEditAlimentatore=new QLineEdit;
    certificazioneEfficienzaLineEditAlimentatore->setPlaceholderText(tr("Inserire certificazione efficienza"));
    certificazioneEfficienzaLineEditAlimentatore->setMaximumSize(QSize(200,30));
    certificazioneEfficienzaLineEditAlimentatore->setMinimumSize(QSize(0,0));

    nomeLineEditDissipatoreProcessore=new QLineEdit;
    nomeLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    nomeLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    produttoreLineEditDissipatoreProcessore=new QLineEdit;
    produttoreLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    produttoreLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    socketSupportatiLineEditDissipatoreProcessore=new QLineEdit;
    socketSupportatiLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire socket supportati"));
    socketSupportatiLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    socketSupportatiLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    rpmVentolaLineEditDissipatoreProcessore=new QLineEdit;
    rpmVentolaLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire rpm ventola"));
    rpmVentolaLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    rpmVentolaLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaLineEditDissipatoreProcessore=new QLineEdit;
    altezzaLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire altezza"));
    altezzaLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    altezzaLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaRadiatoreLineEditDissipatoreProcessore=new QLineEdit;
    altezzaRadiatoreLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire altezza radiatore"));
    altezzaRadiatoreLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    altezzaRadiatoreLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    livelloRumoreLineEditDissipatoreProcessore=new QLineEdit;
    livelloRumoreLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire livello rumore"));
    livelloRumoreLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    livelloRumoreLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    nomeLineEditCase=new QLineEdit;
    nomeLineEditCase->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditCase->setMaximumSize(QSize(200,30));
    nomeLineEditCase->setMinimumSize(QSize(0,0));

    produttoreLineEditCase=new QLineEdit;
    produttoreLineEditCase->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditCase->setMaximumSize(QSize(200,30));
    produttoreLineEditCase->setMinimumSize(QSize(0,0));

    tipologiaLineEditCase=new QLineEdit;
    tipologiaLineEditCase->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditCase->setMaximumSize(QSize(200,30));
    tipologiaLineEditCase->setMinimumSize(QSize(0,0));

    coloreLineEditCase=new QLineEdit;
    coloreLineEditCase->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditCase->setMaximumSize(QSize(200,30));
    coloreLineEditCase->setMinimumSize(QSize(0,0));

    compatibilitaSchedaMadreLineEditCase=new QLineEdit;
    compatibilitaSchedaMadreLineEditCase->setPlaceholderText(tr("Inserire compatibilità scheda madre"));
    compatibilitaSchedaMadreLineEditCase->setMaximumSize(QSize(200,30));
    compatibilitaSchedaMadreLineEditCase->setMinimumSize(QSize(0,0));

    lunghezzaMassimaSchedaGraficaLineEditCase=new QLineEdit;
    lunghezzaMassimaSchedaGraficaLineEditCase->setPlaceholderText(tr("Inserire lunghezza massima scheda grafica"));
    lunghezzaMassimaSchedaGraficaLineEditCase->setMaximumSize(QSize(200,30));
    lunghezzaMassimaSchedaGraficaLineEditCase->setMinimumSize(QSize(0,0));

    dimensioniLineEditCase=new QLineEdit;
    dimensioniLineEditCase->setPlaceholderText(tr("Inserire dimensioni"));
    dimensioniLineEditCase->setMaximumSize(QSize(200,30));
    dimensioniLineEditCase->setMinimumSize(QSize(0,0));

    nomeLineEditUnitaOttica=new QLineEdit;
    nomeLineEditUnitaOttica->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    nomeLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    produttoreLineEditUnitaOttica=new QLineEdit;
    produttoreLineEditUnitaOttica->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    produttoreLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    fattoreDiFormaLineEditUnitaOttica=new QLineEdit;
    fattoreDiFormaLineEditUnitaOttica->setPlaceholderText(tr("Inserire fattore di forma"));
    fattoreDiFormaLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    fattoreDiFormaLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    interfacciaLineEditUnitaOttica=new QLineEdit;
    interfacciaLineEditUnitaOttica->setPlaceholderText(tr("Inserire interfaccia"));
    interfacciaLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    interfacciaLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    cacheLineEditUnitaOttica=new QLineEdit;
    cacheLineEditUnitaOttica->setPlaceholderText(tr("Inserire cache"));
    cacheLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    cacheLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    velocitaLineEditUnitaOttica=new QLineEdit;
    velocitaLineEditUnitaOttica->setPlaceholderText(tr("Inserire velocita"));
    velocitaLineEditUnitaOttica->setMaximumSize(QSize(200,30));
    velocitaLineEditUnitaOttica->setMinimumSize(QSize(0,0));

    nomeLineEditMonitor=new QLineEdit;
    nomeLineEditMonitor->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditMonitor->setMaximumSize(QSize(200,30));
    nomeLineEditMonitor->setMinimumSize(QSize(0,0));

    produttoreLineEditMonitor=new QLineEdit;
    produttoreLineEditMonitor->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditMonitor->setMaximumSize(QSize(200,30));
    produttoreLineEditMonitor->setMinimumSize(QSize(0,0));

    risoluzioneRaccomandataLineEditMonitor=new QLineEdit;
    risoluzioneRaccomandataLineEditMonitor->setPlaceholderText(tr("Inserire risoluzione raccomandata"));
    risoluzioneRaccomandataLineEditMonitor->setMaximumSize(QSize(200,30));
    risoluzioneRaccomandataLineEditMonitor->setMinimumSize(QSize(0,0));

    formatoLineEditMonitor=new QLineEdit;
    formatoLineEditMonitor->setPlaceholderText(tr("Inserire formato"));
    formatoLineEditMonitor->setPlaceholderText(tr("Inserire formato"));
    formatoLineEditMonitor->setMaximumSize(QSize(200,30));
    formatoLineEditMonitor->setMinimumSize(QSize(0,0));

    angoloDiVisualizzazioneLineEditMonitor=new QLineEdit;
    angoloDiVisualizzazioneLineEditMonitor->setPlaceholderText(tr("Inserire angolo di visualizzazione"));
    angoloDiVisualizzazioneLineEditMonitor->setMaximumSize(QSize(200,30));
    angoloDiVisualizzazioneLineEditMonitor->setMinimumSize(QSize(0,0));

    coloriDelDisplayLineEditMonitor=new QLineEdit;
    coloriDelDisplayLineEditMonitor->setPlaceholderText(tr("Inserire colori del display"));
    coloriDelDisplayLineEditMonitor->setMaximumSize(QSize(200,30));
    coloriDelDisplayLineEditMonitor->setMinimumSize(QSize(0,0));

    luminositaLineEditMonitor=new QLineEdit;
    luminositaLineEditMonitor->setPlaceholderText(tr("Inserire luminosità"));
    luminositaLineEditMonitor->setMaximumSize(QSize(200,30));
    luminositaLineEditMonitor->setMinimumSize(QSize(0,0));

    rapportoDiContrastoLineEditMonitor=new QLineEdit;
    rapportoDiContrastoLineEditMonitor->setPlaceholderText(tr("Inserire rapporto di contrasto"));
    rapportoDiContrastoLineEditMonitor->setMaximumSize(QSize(200,30));
    rapportoDiContrastoLineEditMonitor->setMinimumSize(QSize(0,0));

    tempoDiRispostaLineEditMonitor=new QLineEdit;
    tempoDiRispostaLineEditMonitor->setPlaceholderText(tr("Inserire tempo di risposta"));
    tempoDiRispostaLineEditMonitor->setMaximumSize(QSize(200,30));
    tempoDiRispostaLineEditMonitor->setMinimumSize(QSize(0,0));

    tipologiaDisplayLineEditMonitor=new QLineEdit;
    tipologiaDisplayLineEditMonitor->setPlaceholderText(tr("Inserire tipologia display"));
    tipologiaDisplayLineEditMonitor->setMaximumSize(QSize(200,30));
    tipologiaDisplayLineEditMonitor->setMinimumSize(QSize(0,0));

    frequenzaDiAggiornamentoLineEditMonitor=new QLineEdit;
    frequenzaDiAggiornamentoLineEditMonitor->setPlaceholderText(tr("Inserire frequenza di aggiornamento"));
    frequenzaDiAggiornamentoLineEditMonitor->setMaximumSize(QSize(200,30));
    frequenzaDiAggiornamentoLineEditMonitor->setMinimumSize(QSize(0,0));

    nomeLineEditSistemaOperativo=new QLineEdit;
    nomeLineEditSistemaOperativo->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    nomeLineEditSistemaOperativo->setMinimumSize(QSize(0,0));

    produttoreLineEditSistemaOperativo=new QLineEdit;
    produttoreLineEditSistemaOperativo->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    produttoreLineEditSistemaOperativo->setMinimumSize(QSize(0,0));

    modalitaLineEditSistemaOperativo=new QLineEdit;
    modalitaLineEditSistemaOperativo->setPlaceholderText(tr("Inserire modalità"));
    modalitaLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    modalitaLineEditSistemaOperativo->setMinimumSize(QSize(0,0));

    memoriaMassimaSupportataLineEditSistemaOperativo=new QLineEdit;
    memoriaMassimaSupportataLineEditSistemaOperativo->setPlaceholderText(tr("Inserire memoria massima supportata"));
    memoriaMassimaSupportataLineEditSistemaOperativo->setMaximumSize(QSize(200,30));
    memoriaMassimaSupportataLineEditSistemaOperativo->setMinimumSize(QSize(0,0));

    nomeLineEditMouse=new QLineEdit;
    nomeLineEditMouse->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditMouse->setMaximumSize(QSize(200,30));
    nomeLineEditMouse->setMinimumSize(QSize(0,0));

    produttoreLineEditMouse=new QLineEdit;
    produttoreLineEditMouse->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditMouse->setMaximumSize(QSize(200,30));
    produttoreLineEditMouse->setMinimumSize(QSize(0,0));

    connessioneLineEditMouse=new QLineEdit;
    connessioneLineEditMouse->setPlaceholderText(tr("Inserire connessione"));
    connessioneLineEditMouse->setMaximumSize(QSize(200,30));
    connessioneLineEditMouse->setMinimumSize(QSize(0,0));

    tipologiaTracciamentoLineEditMouse=new QLineEdit;
    tipologiaTracciamentoLineEditMouse->setPlaceholderText(tr("Inserire tipologia tracciamento"));
    tipologiaTracciamentoLineEditMouse->setMaximumSize(QSize(200,30));
    tipologiaTracciamentoLineEditMouse->setMinimumSize(QSize(0,0));

    coloreLineEditMouse=new QLineEdit;
    coloreLineEditMouse->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditMouse->setMaximumSize(QSize(200,30));
    coloreLineEditMouse->setMinimumSize(QSize(0,0));

    orientamentoDellaManoLineEditMouse=new QLineEdit;
    orientamentoDellaManoLineEditMouse->setPlaceholderText(tr("Inserire orientamento della mano"));
    orientamentoDellaManoLineEditMouse->setMaximumSize(QSize(200,30));
    orientamentoDellaManoLineEditMouse->setMinimumSize(QSize(0,0));

    nomeLineEditTastiera=new QLineEdit;
    nomeLineEditTastiera->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditTastiera->setMaximumSize(QSize(200,30));
    nomeLineEditTastiera->setMinimumSize(QSize(0,0));

    produttoreLineEditTastiera=new QLineEdit;
    produttoreLineEditTastiera->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditTastiera->setMaximumSize(QSize(200,30));
    produttoreLineEditTastiera->setMinimumSize(QSize(0,0));

    coloreLineEditTastiera=new QLineEdit;
    coloreLineEditTastiera->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditTastiera->setMaximumSize(QSize(200,30));
    coloreLineEditTastiera->setMinimumSize(QSize(0,0));

    connessioneLineEditTastiera=new QLineEdit;
    connessioneLineEditTastiera->setPlaceholderText(tr("Inserire connessione"));
    connessioneLineEditTastiera->setMaximumSize(QSize(200,30));
    connessioneLineEditTastiera->setMinimumSize(QSize(0,0));

    tipologiaLineEditTastiera=new QLineEdit;
    tipologiaLineEditTastiera->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditTastiera->setMaximumSize(QSize(200,30));
    tipologiaLineEditTastiera->setMinimumSize(QSize(0,0));

    tipologiaSwitchLineEditTastiera=new QLineEdit;
    tipologiaSwitchLineEditTastiera->setPlaceholderText(tr("Inserire tipologia switch"));
    tipologiaSwitchLineEditTastiera->setMaximumSize(QSize(200,30));
    tipologiaSwitchLineEditTastiera->setMinimumSize(QSize(0,0));

    nomeLineEditCuffie=new QLineEdit;
    nomeLineEditCuffie->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditCuffie->setMaximumSize(QSize(200,30));
    nomeLineEditCuffie->setMinimumSize(QSize(0,0));

    produttoreLineEditCuffie=new QLineEdit;
    produttoreLineEditCuffie->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditCuffie->setMaximumSize(QSize(200,30));
    produttoreLineEditCuffie->setMinimumSize(QSize(0,0));

    tipologiaLineEditCuffie=new QLineEdit;
    tipologiaLineEditCuffie->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditCuffie->setMaximumSize(QSize(200,30));
    tipologiaLineEditCuffie->setMinimumSize(QSize(0,0));

    sistemaAcusticoLineEditCuffie=new QLineEdit;
    sistemaAcusticoLineEditCuffie->setPlaceholderText(tr("Inserire sistema acustico"));
    sistemaAcusticoLineEditCuffie->setMaximumSize(QSize(200,30));
    sistemaAcusticoLineEditCuffie->setMinimumSize(QSize(0,0));

    coloreLineEditCuffie=new QLineEdit;
    coloreLineEditCuffie->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditCuffie->setMaximumSize(QSize(200,30));
    coloreLineEditCuffie->setMinimumSize(QSize(0,0));

    canaliLineEditCuffie=new QLineEdit;
    canaliLineEditCuffie->setPlaceholderText(tr("Inserire canali"));
    canaliLineEditCuffie->setMaximumSize(QSize(200,30));
    canaliLineEditCuffie->setMinimumSize(QSize(0,0));

    impedenzaLineEditCuffie=new QLineEdit;
    impedenzaLineEditCuffie->setPlaceholderText(tr("Inserire impedenza"));
    impedenzaLineEditCuffie->setMaximumSize(QSize(200,30));
    impedenzaLineEditCuffie->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLineEditCuffie=new QLineEdit;
    frequenzaDiRispostaLineEditCuffie->setPlaceholderText(tr("Inserire frequenza di risposta"));
    frequenzaDiRispostaLineEditCuffie->setMaximumSize(QSize(200,30));
    frequenzaDiRispostaLineEditCuffie->setMinimumSize(QSize(0,0));

    connessioneLineEditCuffie=new QLineEdit;
    connessioneLineEditCuffie->setPlaceholderText(tr("Inserire connessione"));
    connessioneLineEditCuffie->setMaximumSize(QSize(200,30));
    connessioneLineEditCuffie->setMinimumSize(QSize(0,0));

    connettoreLineEditCuffie=new QLineEdit;
    connettoreLineEditCuffie->setPlaceholderText(tr("Inserire connettore"));
    connettoreLineEditCuffie->setMaximumSize(QSize(200,30));
    connettoreLineEditCuffie->setMinimumSize(QSize(0,0));

    nomeLineEditAltoparlanti=new QLineEdit;
    nomeLineEditAltoparlanti->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    nomeLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    produttoreLineEditAltoparlanti=new QLineEdit;
    produttoreLineEditAltoparlanti->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    produttoreLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    coloreLineEditAltoparlanti=new QLineEdit;
    coloreLineEditAltoparlanti->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    coloreLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    configurazioneLineEditAltoparlanti=new QLineEdit;
    configurazioneLineEditAltoparlanti->setPlaceholderText(tr("Inserire configurazione"));
    configurazioneLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    configurazioneLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLineEditAltoparlanti=new QLineEdit;
    frequenzaDiRispostaLineEditAltoparlanti->setPlaceholderText(tr("Inserire frequenza di risposta"));
    frequenzaDiRispostaLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    frequenzaDiRispostaLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    potenzaTotaleLineEditAltoparlanti=new QLineEdit;
    potenzaTotaleLineEditAltoparlanti->setPlaceholderText(tr("Inserire potenza totale"));
    potenzaTotaleLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    potenzaTotaleLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    potenzeLineEditAltoparlanti=new QLineEdit;
    potenzeLineEditAltoparlanti->setPlaceholderText(tr("Inserire potenze"));
    potenzeLineEditAltoparlanti->setMaximumSize(QSize(200,30));
    potenzeLineEditAltoparlanti->setMinimumSize(QSize(0,0));

    rimuoviComponenteLineEdit=new QLineEdit;
    rimuoviComponenteLineEdit->setPlaceholderText(tr("Inserire nome componente da rimuovere"));
    rimuoviComponenteLineEdit->setMaximumSize(QSize(200,30));
    rimuoviComponenteLineEdit->setMinimumSize(QSize(0,0));
}

void MyWidget_GestisciComponentiPCBuilder::createSpinBoxes(){
    latenzaSpinBoxMemoria=new QSpinBox;
    latenzaSpinBoxMemoria->setMaximum(99);
    latenzaSpinBoxMemoria->setMaximumSize(QSize(50,25));
    latenzaSpinBoxMemoria->setMinimumSize(QSize(0,0));

    sata3GBsSpinBoxSchedaMadre=new QSpinBox;
    sata3GBsSpinBoxSchedaMadre->setMaximum(99);
    sata3GBsSpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    sata3GBsSpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    sata6GBsSpinBoxSchedaMadre=new QSpinBox;
    sata6GBsSpinBoxSchedaMadre->setMaximum(99);
    sata6GBsSpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    sata6GBsSpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    sataExpressSpinboxSchedaMadre=new QSpinBox;
    sataExpressSpinboxSchedaMadre->setMaximum(99);
    sataExpressSpinboxSchedaMadre->setMaximumSize(QSize(50,25));
    sataExpressSpinboxSchedaMadre->setMinimumSize(QSize(0,0));

    usb2SpinBoxSchedaMadre=new QSpinBox;
    usb2SpinBoxSchedaMadre->setMaximum(99);
    usb2SpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    usb2SpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    usb3SpinBoxSchedaMadre=new QSpinBox;
    usb3SpinBoxSchedaMadre->setMaximum(99);
    usb3SpinBoxSchedaMadre->setMaximumSize(QSize(50,25));
    usb3SpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    numeroCoreSpinBoxProcessore=new QSpinBox;
    numeroCoreSpinBoxProcessore->setMaximum(99);
    numeroCoreSpinBoxProcessore->setMaximumSize(QSize(50,25));
    numeroCoreSpinBoxProcessore->setMinimumSize(QSize(0,0));

    slotInterni25SpinBoxCase=new QSpinBox;
    slotInterni25SpinBoxCase->setMaximum(99);
    slotInterni25SpinBoxCase->setMaximumSize(QSize(50,25));
    slotInterni25SpinBoxCase->setMinimumSize(0,0);

    slotInterni35SpinBoxCase=new QSpinBox;
    slotInterni35SpinBoxCase->setMaximum(99);
    slotInterni35SpinBoxCase->setMaximumSize(QSize(50,25));
    slotInterni35SpinBoxCase->setMinimumSize(QSize(0,0));

    dpiMassimiSpinBoxMouse=new QSpinBox;
    dpiMassimiSpinBoxMouse->setMaximum(99999);
    dpiMassimiSpinBoxMouse->setMaximumSize(QSize(70,25));
    dpiMassimiSpinBoxMouse->setMinimumSize(QSize(0,0));
}

void MyWidget_GestisciComponentiPCBuilder::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxAlimentatore=new QDoubleSpinBox;
    prezzoDoubleSpinBoxAlimentatore->setSuffix(" €");
    prezzoDoubleSpinBoxAlimentatore->setMaximum(9999.99);
    prezzoDoubleSpinBoxAlimentatore->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxAlimentatore->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxAltoparlanti=new QDoubleSpinBox;
    prezzoDoubleSpinBoxAltoparlanti->setSuffix(" €");
    prezzoDoubleSpinBoxAltoparlanti->setMaximum(9999.99);
    prezzoDoubleSpinBoxAltoparlanti->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxAltoparlanti->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxArchiviazione=new QDoubleSpinBox;
    prezzoDoubleSpinBoxArchiviazione->setSuffix(" €");
    prezzoDoubleSpinBoxArchiviazione->setMaximum(9999.99);
    prezzoDoubleSpinBoxArchiviazione->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxArchiviazione->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxCase=new QDoubleSpinBox;
    prezzoDoubleSpinBoxCase->setSuffix(" €");
    prezzoDoubleSpinBoxCase->setMaximum(9999.99);
    prezzoDoubleSpinBoxCase->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxCase->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxCuffie=new QDoubleSpinBox;
    prezzoDoubleSpinBoxCuffie->setSuffix(" €");
    prezzoDoubleSpinBoxCuffie->setMaximum(9999.99);
    prezzoDoubleSpinBoxCuffie->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxCuffie->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxDissipatoreProcessore=new QDoubleSpinBox;
    prezzoDoubleSpinBoxDissipatoreProcessore->setSuffix(" €");
    prezzoDoubleSpinBoxDissipatoreProcessore->setMaximum(9999.99);
    prezzoDoubleSpinBoxDissipatoreProcessore->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxDissipatoreProcessore->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxMemoria=new QDoubleSpinBox;
    prezzoDoubleSpinBoxMemoria->setSuffix(" €");
    prezzoDoubleSpinBoxMemoria->setMaximum(9999.99);
    prezzoDoubleSpinBoxMemoria->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxMemoria->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxMonitor=new QDoubleSpinBox;
    prezzoDoubleSpinBoxMonitor->setSuffix(" €");
    prezzoDoubleSpinBoxMonitor->setMaximum(9999.99);
    prezzoDoubleSpinBoxMonitor->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxMonitor->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxMouse=new QDoubleSpinBox;
    prezzoDoubleSpinBoxMouse->setSuffix(" €");
    prezzoDoubleSpinBoxMouse->setMaximum(9999.99);
    prezzoDoubleSpinBoxMouse->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxMouse->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxProcessore=new QDoubleSpinBox;
    prezzoDoubleSpinBoxProcessore->setSuffix(" €");
    prezzoDoubleSpinBoxProcessore->setMaximum(9999.99);
    prezzoDoubleSpinBoxProcessore->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxProcessore->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxSchedaGrafica=new QDoubleSpinBox;
    prezzoDoubleSpinBoxSchedaGrafica->setSuffix(" €");
    prezzoDoubleSpinBoxSchedaGrafica->setMaximum(9999.99);
    prezzoDoubleSpinBoxSchedaGrafica->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxSchedaGrafica->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxSchedaMadre=new QDoubleSpinBox;
    prezzoDoubleSpinBoxSchedaMadre->setSuffix(" €");
    prezzoDoubleSpinBoxSchedaMadre->setMaximum(9999.99);
    prezzoDoubleSpinBoxSchedaMadre->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxSchedaMadre->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxSistemaOperativo=new QDoubleSpinBox;
    prezzoDoubleSpinBoxSistemaOperativo->setSuffix(" €");
    prezzoDoubleSpinBoxSistemaOperativo->setMaximum(9999.99);
    prezzoDoubleSpinBoxSistemaOperativo->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxSistemaOperativo->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxTastiera=new QDoubleSpinBox;
    prezzoDoubleSpinBoxTastiera->setSuffix(" €");
    prezzoDoubleSpinBoxTastiera->setMaximum(9999.99);
    prezzoDoubleSpinBoxTastiera->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxTastiera->setMinimumSize(QSize(0,0));

    prezzoDoubleSpinBoxUnitaOttica=new QDoubleSpinBox;
    prezzoDoubleSpinBoxUnitaOttica->setSuffix(" €");
    prezzoDoubleSpinBoxUnitaOttica->setMaximum(9999.99);
    prezzoDoubleSpinBoxUnitaOttica->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxUnitaOttica->setMinimumSize(QSize(0,0));

    efficienzaDoubleSpinBoxAlimentatore=new QDoubleSpinBox;
    efficienzaDoubleSpinBoxAlimentatore->setSuffix(" %");
    efficienzaDoubleSpinBoxAlimentatore->setMaximum(999.99);
    efficienzaDoubleSpinBoxAlimentatore->setMaximumSize(QSize(80,25));
    efficienzaDoubleSpinBoxAlimentatore->setMinimumSize(QSize(0,0));
}

QPushButton* MyWidget_GestisciComponentiPCBuilder::get_indietroPushButton() const{
    return indietroPushButton;
}

QPushButton* MyWidget_GestisciComponentiPCBuilder::get_aggiungi_PushButton() const{
    return aggiungiPushButton;
}

QPushButton* MyWidget_GestisciComponentiPCBuilder::get_rimuoviPushButton() const{
    return rimuoviPushButton;
}

QString MyWidget_GestisciComponentiPCBuilder::tipo_componenteAggiungiValue() const{
    return tipo_componenteAggiungi->currentText();
}

QString MyWidget_GestisciComponentiPCBuilder::rimuoviComponenteValue() const{
    return rimuoviComponenteLineEdit->text();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeMemoriaValue() const{
    return nomeLineEditMemoria->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreMemoriaValue() const{
    return produttoreLineEditMemoria->text();
}

QString MyWidget_GestisciComponentiPCBuilder::velocitaMemoriaValue() const{
    return velocitaLineEditMemoria->text();
}

QString MyWidget_GestisciComponentiPCBuilder::capacitaMemoriaValue() const{
    return capacitaLineEditMemoria->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaMemoriaValue() const{
    return tipologiaLineEditMemoria->text();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoMemoriaValue() const{
    return prezzoDoubleSpinBoxMemoria->value();
}

int MyWidget_GestisciComponentiPCBuilder::latenzaMemoriaValue() const{
    return latenzaSpinBoxMemoria->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeSchedaGraficaValue() const{
    return nomeLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreSchedaGraficaValue() const{
    return produttoreLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::interfacciaSchedaGraficaValue() const{
    return interfacciaLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::chipsetSchedaGraficaValue() const{
    return chipsetLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::memoriaSchedaGraficaValue() const{
    return memoriaLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaMemoriaSchedaGraficaValue() const{
    return tipologiaMemoriaLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::frequenzaCoreSchedaGraficaValue() const{
    return frequenzaCoreLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tdpSchedaGraficaValue() const{
    return tdpLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::supportoSLISchedaGraficaValue() const{
    return supportoSLILineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::supportoCrossfireSchedaGraficaValue() const{
    return supportoCrossfireLineEditSchedaGrafica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::lunghezzaSchedaGraficaValue() const{
    return lunghezzaLineEditSchedaGrafica->text();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoSchedaGraficaValue() const{
    return prezzoDoubleSpinBoxSchedaGrafica->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeSchedaMadreValue() const{
    return nomeLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreSchedaMadreValue() const{
    return produttoreLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::fattoreDiFormaSchedaMadreValue() const{
    return fattoreDiFormaLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::chipsetSchedaMadreValue() const{
    return chipsetLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::socketProcessoreSchedaMadreValue() const{
    return socketProcessoreLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::slotMemoriaSchedaMadreValue() const{
    return slotMemoriaLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaMemoriaSchedaMadreValue() const{
    return tipologiaMemoriaLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::memoriaMassimaSchedaMadreValue() const{
    return memoriaMassimaLineEditSchedaMadre->text();
}

QString MyWidget_GestisciComponentiPCBuilder::ethernetSchedaMadreValue() const{
    return ethernetLineEditSchedaMadre->text();
}

bool MyWidget_GestisciComponentiPCBuilder::supportoRAIDSchedaMadreValue() const{
    return supportoRAIDCheckBoxSchedaMadre->isChecked();
}

bool MyWidget_GestisciComponentiPCBuilder::supportoCrossfireSchedaMadreValue() const{
    return supportoCrossfireCheckBoxSchedaMadre->isChecked();
}

bool MyWidget_GestisciComponentiPCBuilder::supportoSLISchedaMadreValue() const{
    return supportoSLICheckBoxSchedaMadre->isChecked();
}

int MyWidget_GestisciComponentiPCBuilder::sata3GBsSchedaMadreValue() const{
    return sata3GBsSpinBoxSchedaMadre->value();
}

int MyWidget_GestisciComponentiPCBuilder::sata6GBsSchedaMadreValue() const{
    return sata6GBsSpinBoxSchedaMadre->value();
}

int MyWidget_GestisciComponentiPCBuilder::sataExpressSchedaMadreValue() const{
    return sataExpressSpinboxSchedaMadre->value();
}

int MyWidget_GestisciComponentiPCBuilder::usb2SchedaMadreValue() const{
    return usb2SpinBoxSchedaMadre->value();
}

int MyWidget_GestisciComponentiPCBuilder::usb3SchedaMadreValue() const{
    return usb3SpinBoxSchedaMadre->value();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoSchedaMadreValue() const{
    return prezzoDoubleSpinBoxSchedaMadre->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeProcessoreValue() const{
    return nomeLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreProcessoreValue() const{
    return produttoreLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::socketProcessoreValue() const{
    return socketLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::larghezzaDatiProcessoreValue() const{
    return larghezzaDatiLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::frequenzaOperativaProcessoreValue() const{
    return frequenzaOperativaLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::frequenzaTurboProcessoreValue() const{
    return frequenzaTurboLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::l1CacheProcessoreValue() const{
    return l1CacheLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::l2CacheProcessoreValue() const{
    return l2CacheLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::l3CacheProcessoreValue() const{
    return l3CacheLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::litografiaProcessoreValue() const{
    return litografiaLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tdpProcessoreValue() const{
    return tdpLineEditProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::graficaIntegrataProcessoreValue() const{
    return graficaIntegrataLineEditProcessore->text();
}

bool MyWidget_GestisciComponentiPCBuilder::includeDissipatoreProcessoreValue() const{
    return includeDissipatoreCheckBoxProcessore->isChecked();
}

bool MyWidget_GestisciComponentiPCBuilder::hyperThreadingProcessoreValue() const{
    return hyperThreadingCheckBoxProcessore->isChecked();
}

int MyWidget_GestisciComponentiPCBuilder::numeroCoreProcessoreValue() const{
    return numeroCoreSpinBoxProcessore->value();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoProcessoreValue() const{
    return prezzoDoubleSpinBoxProcessore->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeArchiviazioneValue() const{
    return nomeLineEditArchiviazione->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreArchiviazioneValue() const{
    return produttoreLineEditArchiviazione->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaArchiviazioneValue() const{
    return tipologiaLineEditArchiviazione->text();
}

QString MyWidget_GestisciComponentiPCBuilder::capacitaArchiviazioneValue() const{
    return capacitaLineEditArchiviazione->text();
}

QString MyWidget_GestisciComponentiPCBuilder::interfacciaArchiviazioneValue() const{
    return interfacciaLineEditArchiviazione->text();
}

QString MyWidget_GestisciComponentiPCBuilder::cacheArchiviazioneValue() const{
    return cacheLineEditArchiviazione->text();
}

QString MyWidget_GestisciComponentiPCBuilder::fattoreDiFormaArchiviazioneValue() const{
    return fattoreDiFormaLineEditArchiviazione->text();
}

QString MyWidget_GestisciComponentiPCBuilder::rpmArchiviazioneValue() const{
    return rpmLineEditArchiviazione->text();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoArchiviazioneValue() const{
    return prezzoDoubleSpinBoxArchiviazione->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeAlimentatoreValue() const{
    return nomeLineEditAlimentatore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreAlimentatoreValue() const{
    return produttoreLineEditAlimentatore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaAlimentatoreValue() const{
    return tipologiaLineEditAlimentatore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::wattaggioAlimentatoreValue() const{
    return wattaggioLineEditAlimentatore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::modulareAlimentatoreValue() const{
    return modulareLineEditAlimentatore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::certificazioneEfficienzaAlimentatoreValue() const{
    return certificazioneEfficienzaLineEditAlimentatore->text();
}

double MyWidget_GestisciComponentiPCBuilder::efficienzaAlimentatoreValue() const{
    return efficienzaDoubleSpinBoxAlimentatore->value();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoAlimentatoreValue() const{
    return prezzoDoubleSpinBoxAlimentatore->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeDissipatoreProcessoreValue() const{
    return nomeLineEditDissipatoreProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreDissipatoreProcessoreValue() const{
    return produttoreLineEditDissipatoreProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::socketSupportatiDissipatoreProcessoreValue() const{
    return socketSupportatiLineEditDissipatoreProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::rpmVentolaDissipatoreProcessoreValue() const{
    return rpmVentolaLineEditDissipatoreProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::altezzaDissipatoreProcessoreValue() const{
    return altezzaLineEditDissipatoreProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::altezzaRadiatoreDissipatoreProcessoreValue() const{
    return altezzaRadiatoreLineEditDissipatoreProcessore->text();
}

QString MyWidget_GestisciComponentiPCBuilder::livelloRumoreDissipatoreProcessoreValue() const{
    return livelloRumoreLineEditDissipatoreProcessore->text();
}

bool MyWidget_GestisciComponentiPCBuilder::raffreddamentoALiquidoDissipatoreProcessoreValue() const{
    return raffreddamentoALiquidoCheckBoxDissipatoreProcessore->isChecked();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoDissipatoreProcessoreValue() const{
    return prezzoDoubleSpinBoxDissipatoreProcessore->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeCaseValue() const{
    return nomeLineEditCase->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreCaseValue() const{
    return produttoreLineEditCase->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaCaseValue() const{
    return tipologiaLineEditCase->text();
}

QString MyWidget_GestisciComponentiPCBuilder::coloreCaseValue() const{
    return coloreLineEditCase->text();
}

QString MyWidget_GestisciComponentiPCBuilder::compatibilitaSchedaMadreCaseValue() const{
    return compatibilitaSchedaMadreLineEditCase->text();
}

QString MyWidget_GestisciComponentiPCBuilder::lunghezzaMassimaSchedaGraficaCaseValue() const{
    return lunghezzaMassimaSchedaGraficaLineEditCase->text();
}

QString MyWidget_GestisciComponentiPCBuilder::dimensioniCaseValue() const{
    return dimensioniLineEditCase->text();
}

bool MyWidget_GestisciComponentiPCBuilder::alimentatoreInclusoCaseValue() const{
    return alimentatoreInclusoCheckBoxCase->isChecked();
}

int MyWidget_GestisciComponentiPCBuilder::slotInterni25CaseValue() const{
    return slotInterni25SpinBoxCase->value();
}

int MyWidget_GestisciComponentiPCBuilder::slotInterni35CaseValue() const{
    return slotInterni35SpinBoxCase->value();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoCaseValue() const{
    return prezzoDoubleSpinBoxCase->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeUnitaOtticaValue() const{
    return nomeLineEditUnitaOttica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreUnitaOtticaValue() const{
    return produttoreLineEditUnitaOttica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::fattoreDiFormaUnitaOtticaValue() const{
    return fattoreDiFormaLineEditUnitaOttica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::interfacciaUnitaOtticaValue() const{
    return interfacciaLineEditUnitaOttica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::cacheUnitaOtticaValue() const{
    return cacheLineEditUnitaOttica->text();
}

QString MyWidget_GestisciComponentiPCBuilder::velocitaUnitaOtticaValue() const{
    return velocitaLineEditUnitaOttica->text();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoUnitaOtticaValue() const{
    return prezzoDoubleSpinBoxUnitaOttica->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeMonitorValue() const{
    return nomeLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreMonitorValue() const{
    return produttoreLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::risoluzioneRaccomandataMonitorValue() const{
    return risoluzioneRaccomandataLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::formatoMonitorValue() const{
    return formatoLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::angoloDiVisualizzazioneMonitorValue() const{
    return angoloDiVisualizzazioneLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::coloriDelDisplayMonitorValue() const{
    return coloriDelDisplayLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::luminositaMonitorValue() const{
    return luminositaLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::rapportoDiContrastoMonitorValue() const{
    return rapportoDiContrastoLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tempoDiRispostaMonitorValue() const{
    return tempoDiRispostaLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaDisplayMonitorValue() const{
    return tipologiaDisplayLineEditMonitor->text();
}

QString MyWidget_GestisciComponentiPCBuilder::frequenzaDiAggiornamentoMonitorValue() const{
    return frequenzaDiAggiornamentoLineEditMonitor->text();
}

bool MyWidget_GestisciComponentiPCBuilder::altoparlantiIncorporatiMonitorValue() const{
    return altoparlantiIncorporatiCheckBoxMonitor->isChecked();
}

bool MyWidget_GestisciComponentiPCBuilder::widescreenMonitorValue() const{
    return widescreenCheckBoxMonitor->isChecked();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoMonitorValue() const{
    return prezzoDoubleSpinBoxMonitor->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeSistemaOperativoValue() const{
    return nomeLineEditSistemaOperativo->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreSistemaOperativoValue() const{
    return produttoreLineEditSistemaOperativo->text();
}

QString MyWidget_GestisciComponentiPCBuilder::modalitaSistemaOperativoValue() const{
    return modalitaLineEditSistemaOperativo->text();
}

QString MyWidget_GestisciComponentiPCBuilder::memoriaMassimaSupportataSistemaOperativoValue() const{
    return memoriaMassimaSupportataLineEditSistemaOperativo->text();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoSistemaOperativoValue() const{
    return prezzoDoubleSpinBoxSistemaOperativo->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeMouseValue() const{
    return nomeLineEditMouse->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreMouseValue() const{
    return produttoreLineEditMouse->text();
}

QString MyWidget_GestisciComponentiPCBuilder::connessioneMouseValue() const{
    return connessioneLineEditMouse->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaTracciamentoMouseValue() const{
    return tipologiaTracciamentoLineEditMouse->text();
}

QString MyWidget_GestisciComponentiPCBuilder::coloreMouseValue() const{
    return coloreLineEditMouse->text();
}

QString MyWidget_GestisciComponentiPCBuilder::orientamentoDellaManoMouseValue() const{
    return orientamentoDellaManoLineEditMouse->text();
}

int MyWidget_GestisciComponentiPCBuilder::dpiMassimiMouseValue() const{
    return dpiMassimiSpinBoxMouse->value();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoMouseValue() const{
    return prezzoDoubleSpinBoxMouse->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeTastieraValue() const{
    return nomeLineEditTastiera->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreTastieraValue() const{
    return produttoreLineEditTastiera->text();
}

QString MyWidget_GestisciComponentiPCBuilder::coloreTastieraValue() const{
    return coloreLineEditTastiera->text();
}

QString MyWidget_GestisciComponentiPCBuilder::connessioneTastieraValue() const{
    return connessioneLineEditTastiera->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaTastieraValue() const{
    return tipologiaLineEditTastiera->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaSwitchTastieraValue() const{
    return tipologiaSwitchLineEditTastiera->text();
}

bool MyWidget_GestisciComponentiPCBuilder::retroilluminazioneTastieraValue() const{
    return retroilluminazioneCheckBoxTastiera->isChecked();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoTastieraValue() const{
    return prezzoDoubleSpinBoxTastiera->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeCuffieValue() const{
    return nomeLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreCuffieValue() const{
    return produttoreLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::tipologiaCuffieValue() const{
    return tipologiaLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::sistemaAcusticoCuffieValue() const{
    return sistemaAcusticoLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::coloreCuffieValue() const{
    return coloreLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::canaliCuffieValue() const{
    return canaliLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::impedenzaCuffieValue() const{
    return impedenzaLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::frequenzaDiRispostaCuffieValue() const{
    return frequenzaDiRispostaLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::connessioneCuffieValue() const{
    return connessioneLineEditCuffie->text();
}

QString MyWidget_GestisciComponentiPCBuilder::connettoreCuffieValue() const{
    return connettoreLineEditCuffie->text();
}

bool MyWidget_GestisciComponentiPCBuilder::microfonoCuffieValue() const{
    return microfonoCheckBoxCuffie->isChecked();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoCuffieValue() const{
    return prezzoDoubleSpinBoxCuffie->value();
}

QString MyWidget_GestisciComponentiPCBuilder::nomeAltoparlantiValue() const{
    return nomeLineEditAltoparlanti->text();
}

QString MyWidget_GestisciComponentiPCBuilder::produttoreAltoparlantiValue() const{
    return produttoreLineEditAltoparlanti->text();
}

QString MyWidget_GestisciComponentiPCBuilder::coloreAltoparlantiValue() const{
    return coloreLineEditAltoparlanti->text();
}

QString MyWidget_GestisciComponentiPCBuilder::configurazioneAltoparlantiValue() const{
    return configurazioneLineEditAltoparlanti->text();
}

QString MyWidget_GestisciComponentiPCBuilder::frequenzaDiRispostaAltoparlantiValue() const{
    return frequenzaDiRispostaLineEditAltoparlanti->text();
}

QString MyWidget_GestisciComponentiPCBuilder::potenzaTotaleAltoparlantiValue() const{
    return potenzaTotaleLineEditAltoparlanti->text();
}

QString MyWidget_GestisciComponentiPCBuilder::potenzeAltoparlantiValue() const{
    return potenzeLineEditAltoparlanti->text();
}

double MyWidget_GestisciComponentiPCBuilder::prezzoAltoparlantiValue() const{
    return prezzoDoubleSpinBoxAltoparlanti->value();
}

QLineEdit* MyWidget_GestisciComponentiPCBuilder::getRimuoviComponenteLineEdit() const{
    return rimuoviComponenteLineEdit;
}
