#ifndef MYWIDGET_GESTISCICOMPONENTIPCBUILDER_H
#define MYWIDGET_GESTISCICOMPONENTIPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QString>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QStackedWidget>
#include <QCheckBox>

class MyWidget_GestisciComponentiPCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* PCBuilder_Gestione_componentiLabel;
    QLabel* aggiungi_componenteLabel;
    QLabel* rimuovi_componenteLabel;

    //Memoria
    QLabel* nomeLabelMemoria;
    QLabel* prezzoLabelMemoria;
    QLabel* produttoreLabelMemoria;
    QLabel* velocitaLabelMemoria;
    QLabel* capacitaLabelMemoria;
    QLabel* tipologiaLabelMemoria;
    QLabel* latenzaLabelMemoria;
    QLineEdit* nomeLineEditMemoria;
    QLineEdit* produttoreLineEditMemoria;
    QLineEdit* velocitaLineEditMemoria;
    QLineEdit* capacitaLineEditMemoria;
    QLineEdit* tipologiaLineEditMemoria;
    QDoubleSpinBox* prezzoDoubleSpinBoxMemoria;
    QSpinBox* latenzaSpinBoxMemoria;

    //SchedaGrafica
    QLabel* nomeLabelSchedaGrafica;
    QLabel* prezzoLabelSchedaGrafica;
    QLabel* produttoreLabelSchedaGrafica;
    QLabel* interfacciaLabelSchedaGrafica;
    QLabel* chipsetLabelSchedaGrafica;
    QLabel* memoriaLabelSchedaGrafica;
    QLabel* tipologiaMemoriaLabelSchedaGrafica;
    QLabel* frequenzaCoreLabelSchedaGrafica;
    QLabel* tdpLabelSchedaGrafica;
    QLabel* supportoSLILabelSchedaGrafica;
    QLabel* supportoCrossfireLabelSchedaGrafica;
    QLabel* lunghezzaLabelSchedaGrafica;
    QLineEdit* nomeLineEditSchedaGrafica;
    QLineEdit* produttoreLineEditSchedaGrafica;
    QLineEdit* interfacciaLineEditSchedaGrafica;
    QLineEdit* chipsetLineEditSchedaGrafica;
    QLineEdit* memoriaLineEditSchedaGrafica;
    QLineEdit* tipologiaMemoriaLineEditSchedaGrafica;
    QLineEdit* frequenzaCoreLineEditSchedaGrafica;
    QLineEdit* tdpLineEditSchedaGrafica;
    QLineEdit* supportoSLILineEditSchedaGrafica;
    QLineEdit* supportoCrossfireLineEditSchedaGrafica;
    QLineEdit* lunghezzaLineEditSchedaGrafica;
    QDoubleSpinBox* prezzoDoubleSpinBoxSchedaGrafica;

    //SchedaMadre
    QLabel* nomeLabelSchedaMadre;
    QLabel* prezzoLabelSchedaMadre;
    QLabel* produttoreLabelSchedaMadre;
    QLabel* fattoreDiFormaLabelSchedaMadre;
    QLabel* chipsetLabelSchedaMadre;
    QLabel* socketProcessoreLabelSchedaMadre;
    QLabel* slotMemoriaLabelSchedaMadre;
    QLabel* tipologiaMemoriaLabelSchedaMadre;
    QLabel* memoriaMassimaLabelSchedaMadre;
    QLabel* ethernetLabelSchedaMadre;
    QLabel* sata3GBsLabelSchedaMadre;
    QLabel* sata6GBsLabelSchedaMadre;
    QLabel* sataExpressLabelSchedaMadre;
    QLabel* usb2LabelSchedaMadre;
    QLabel* usb3LabelSchedaMadre;
    QLineEdit* nomeLineEditSchedaMadre;
    QLineEdit* produttoreLineEditSchedaMadre;
    QLineEdit* fattoreDiFormaLineEditSchedaMadre;
    QLineEdit* chipsetLineEditSchedaMadre;
    QLineEdit* socketProcessoreLineEditSchedaMadre;
    QLineEdit* slotMemoriaLineEditSchedaMadre;
    QLineEdit* tipologiaMemoriaLineEditSchedaMadre;
    QLineEdit* memoriaMassimaLineEditSchedaMadre;
    QLineEdit* ethernetLineEditSchedaMadre;
    QCheckBox* supportoRAIDCheckBoxSchedaMadre;
    QCheckBox* supportoCrossfireCheckBoxSchedaMadre;
    QCheckBox* supportoSLICheckBoxSchedaMadre;
    QSpinBox* sata3GBsSpinBoxSchedaMadre;
    QSpinBox* sata6GBsSpinBoxSchedaMadre;
    QSpinBox* sataExpressSpinboxSchedaMadre;
    QSpinBox* usb2SpinBoxSchedaMadre;
    QSpinBox* usb3SpinBoxSchedaMadre;
    QDoubleSpinBox* prezzoDoubleSpinBoxSchedaMadre;

    //Processore
    QLabel* nomeLabelProcessore;
    QLabel* prezzoLabelProcessore;
    QLabel* produttoreLabelProcessore;
    QLabel* socketLabelProcessore;
    QLabel* larghezzaDatiLabelProcessore;
    QLabel* frequenzaOperativaLabelProcessore;
    QLabel* frequenzaTurboLabelProcessore;
    QLabel* numeroCoreLabelProcessore;
    QLabel* l1CacheLabelProcessore;
    QLabel* l2CacheLabelProcessore;
    QLabel* l3CacheLabelProcessore;
    QLabel* litografiaLabelProcessore;
    QLabel* tdpLabelProcessore;
    QLabel* graficaIntegrataLabelProcessore;
    QLineEdit* nomeLineEditProcessore;
    QLineEdit* produttoreLineEditProcessore;
    QLineEdit* socketLineEditProcessore;
    QLineEdit* larghezzaDatiLineEditProcessore;
    QLineEdit* frequenzaOperativaLineEditProcessore;
    QLineEdit* frequenzaTurboLineEditProcessore;
    QLineEdit* l1CacheLineEditProcessore;
    QLineEdit* l2CacheLineEditProcessore;
    QLineEdit* l3CacheLineEditProcessore;
    QLineEdit* litografiaLineEditProcessore;
    QLineEdit* tdpLineEditProcessore;
    QLineEdit* graficaIntegrataLineEditProcessore;
    QCheckBox* includeDissipatoreCheckBoxProcessore;
    QCheckBox* hyperThreadingCheckBoxProcessore;
    QSpinBox* numeroCoreSpinBoxProcessore;
    QDoubleSpinBox* prezzoDoubleSpinBoxProcessore;

    //Archiviazione
    QLabel* nomeLabelArchiviazione;
    QLabel* prezzoLabelArchiviazione;
    QLabel* produttoreLabelArchiviazione;
    QLabel* tipologiaLabelArchiviazione;
    QLabel* capacitaLabelArchiviazione;
    QLabel* interfacciaLabelArchiviazione;
    QLabel* cacheLabelArchiviazione;
    QLabel* fattoreDiFormaLabelArchiviazione;
    QLabel* rpmLabelArchiviazione;
    QLineEdit* nomeLineEditArchiviazione;
    QLineEdit* produttoreLineEditArchiviazione;
    QLineEdit* tipologiaLineEditArchiviazione;
    QLineEdit* capacitaLineEditArchiviazione;
    QLineEdit* interfacciaLineEditArchiviazione;
    QLineEdit* cacheLineEditArchiviazione;
    QLineEdit* fattoreDiFormaLineEditArchiviazione;
    QLineEdit* rpmLineEditArchiviazione;
    QDoubleSpinBox* prezzoDoubleSpinBoxArchiviazione;

    //Alimentatore
    QLabel* nomeLabelAlimentatore;
    QLabel* prezzoLabelAlimentatore;
    QLabel* produttoreLabelAlimentatore;
    QLabel* tipologiaLabelAlimentatore;
    QLabel* wattaggioLabelAlimentatore;
    QLabel* modulareLabelAlimentatore;
    QLabel* certificazioneEfficienzaLabelAlimentatore;
    QLabel* efficienzaLabelAlimentatore;
    QLineEdit* nomeLineEditAlimentatore;
    QLineEdit* produttoreLineEditAlimentatore;
    QLineEdit* tipologiaLineEditAlimentatore;
    QLineEdit* wattaggioLineEditAlimentatore;
    QLineEdit* modulareLineEditAlimentatore;
    QLineEdit* certificazioneEfficienzaLineEditAlimentatore;
    QDoubleSpinBox* efficienzaDoubleSpinBoxAlimentatore;
    QDoubleSpinBox* prezzoDoubleSpinBoxAlimentatore;

    //DissipatoreProcessore
    QLabel* nomeLabelDissipatoreProcessore;
    QLabel* prezzoLabelDissipatoreProcessore;
    QLabel* produttoreLabelDissipatoreProcessore;
    QLabel* socketSupportatiLabelDissipatoreProcessore;
    QLabel* rpmVentolaLabelDissipatoreProcessore;
    QLabel* altezzaLabelDissipatoreProcessore;
    QLabel* altezzaRadiatoreLabelDissipatoreProcessore;
    QLabel* livelloRumoreLabelDissipatoreProcessore;
    QLineEdit* nomeLineEditDissipatoreProcessore;
    QLineEdit* produttoreLineEditDissipatoreProcessore;
    QLineEdit* socketSupportatiLineEditDissipatoreProcessore;
    QLineEdit* rpmVentolaLineEditDissipatoreProcessore;
    QLineEdit* altezzaLineEditDissipatoreProcessore;
    QLineEdit* altezzaRadiatoreLineEditDissipatoreProcessore;
    QLineEdit* livelloRumoreLineEditDissipatoreProcessore;
    QCheckBox* raffreddamentoALiquidoCheckBoxDissipatoreProcessore;
    QDoubleSpinBox* prezzoDoubleSpinBoxDissipatoreProcessore;

    //Case
    QLabel* nomeLabelCase;
    QLabel* prezzoLabelCase;
    QLabel* produttoreLabelCase;
    QLabel* tipologiaLabelCase;
    QLabel* coloreLabelCase;
    QLabel* slotInterni25LabelCase;
    QLabel* slotInterni35LabelCase;
    QLabel* compatibilitaSchedaMadreLabelCase;
    QLabel* lunghezzaMassimaSchedaGraficaLabelCase;
    QLabel* dimensioniLabelCase;
    QLineEdit* nomeLineEditCase;
    QLineEdit* produttoreLineEditCase;
    QLineEdit* tipologiaLineEditCase;
    QLineEdit* coloreLineEditCase;
    QLineEdit* compatibilitaSchedaMadreLineEditCase;
    QLineEdit* lunghezzaMassimaSchedaGraficaLineEditCase;
    QLineEdit* dimensioniLineEditCase;
    QCheckBox* alimentatoreInclusoCheckBoxCase;
    QSpinBox* slotInterni25SpinBoxCase;
    QSpinBox* slotInterni35SpinBoxCase;
    QDoubleSpinBox* prezzoDoubleSpinBoxCase;

    //UnitaOttica
    QLabel* nomeLabelUnitaOttica;
    QLabel* prezzoLabelUnitaOttica;
    QLabel* produttoreLabelUnitaOttica;
    QLabel* fattoreDiFormaLabelUnitaOttica;
    QLabel* interfacciaLabelUnitaOttica;
    QLabel* cacheLabelUnitaOttica;
    QLabel* velocitaLabelUnitaOttica;
    QLineEdit* nomeLineEditUnitaOttica;
    QLineEdit* produttoreLineEditUnitaOttica;
    QLineEdit* fattoreDiFormaLineEditUnitaOttica;
    QLineEdit* interfacciaLineEditUnitaOttica;
    QLineEdit* cacheLineEditUnitaOttica;
    QLineEdit* velocitaLineEditUnitaOttica;
    QDoubleSpinBox* prezzoDoubleSpinBoxUnitaOttica;

    //Monitor
    QLabel* nomeLabelMonitor;
    QLabel* prezzoLabelMonitor;
    QLabel* produttoreLabelMonitor;
    QLabel* risoluzioneRaccomandataLabelMonitor;
    QLabel* formatoLabelMonitor;
    QLabel* angoloDiVisualizzazioneLabelMonitor;
    QLabel* coloriDelDisplayLabelMonitor;
    QLabel* luminositaLabelMonitor;
    QLabel* rapportoDiContrastoLabelMonitor;
    QLabel* tempoDiRispostaLabelMonitor;
    QLabel* tipologiaDisplayLabelMonitor;
    QLabel* frequenzaDiAggiornamentoLabelMonitor;
    QLineEdit* nomeLineEditMonitor;
    QLineEdit* produttoreLineEditMonitor;
    QLineEdit* risoluzioneRaccomandataLineEditMonitor;
    QLineEdit* formatoLineEditMonitor;
    QLineEdit* angoloDiVisualizzazioneLineEditMonitor;
    QLineEdit* coloriDelDisplayLineEditMonitor;
    QLineEdit* luminositaLineEditMonitor;
    QLineEdit* rapportoDiContrastoLineEditMonitor;
    QLineEdit* tempoDiRispostaLineEditMonitor;
    QLineEdit* tipologiaDisplayLineEditMonitor;
    QLineEdit* frequenzaDiAggiornamentoLineEditMonitor;
    QCheckBox* altoparlantiIncorporatiCheckBoxMonitor;
    QCheckBox* widescreenCheckBoxMonitor;
    QDoubleSpinBox* prezzoDoubleSpinBoxMonitor;

    //SistemaOperativo
    QLabel* nomeLabelSistemaOperativo;
    QLabel* prezzoLabelSistemaOperativo;
    QLabel* produttoreLabelSistemaOperativo;
    QLabel* modalitaLabelSistemaOperativo;
    QLabel* memoriaMassimaSupportataLabelSistemaOperativo;
    QLineEdit* nomeLineEditSistemaOperativo;
    QLineEdit* produttoreLineEditSistemaOperativo;
    QLineEdit* modalitaLineEditSistemaOperativo;
    QLineEdit* memoriaMassimaSupportataLineEditSistemaOperativo;
    QDoubleSpinBox* prezzoDoubleSpinBoxSistemaOperativo;

    //Mouse
    QLabel* nomeLabelMouse;
    QLabel* prezzoLabelMouse;
    QLabel* produttoreLabelMouse;
    QLabel* connessioneLabelMouse;
    QLabel* tipologiaTracciamentoLabelMouse;
    QLabel* dpiMassimiLabelMouse;
    QLabel* coloreLabelMouse;
    QLabel* orientamentoDellaManoLabelMouse;
    QLineEdit* nomeLineEditMouse;
    QLineEdit* produttoreLineEditMouse;
    QLineEdit* connessioneLineEditMouse;
    QLineEdit* tipologiaTracciamentoLineEditMouse;
    QLineEdit* coloreLineEditMouse;
    QLineEdit* orientamentoDellaManoLineEditMouse;
    QSpinBox* dpiMassimiSpinBoxMouse;
    QDoubleSpinBox* prezzoDoubleSpinBoxMouse;

    //Tastiera
    QLabel* nomeLabelTastiera;
    QLabel* prezzoLabelTastiera;
    QLabel* produttoreLabelTastiera;
    QLabel* coloreLabelTastiera;
    QLabel* connessioneLabelTastiera;
    QLabel* tipologiaLabelTastiera;
    QLabel* tipologiaSwitchLabelTastiera;
    QLineEdit* nomeLineEditTastiera;
    QLineEdit* produttoreLineEditTastiera;
    QLineEdit* coloreLineEditTastiera;
    QLineEdit* connessioneLineEditTastiera;
    QLineEdit* tipologiaLineEditTastiera;
    QLineEdit* tipologiaSwitchLineEditTastiera;
    QCheckBox* retroilluminazioneCheckBoxTastiera;
    QDoubleSpinBox* prezzoDoubleSpinBoxTastiera;

    //Cuffie
    QLabel* nomeLabelCuffie;
    QLabel* prezzoLabelCuffie;
    QLabel* produttoreLabelCuffie;
    QLabel* tipologiaLabelCuffie;
    QLabel* sistemaAcusticoLabelCuffie;
    QLabel* coloreLabelCuffie;
    QLabel* canaliLabelCuffie;
    QLabel* impedenzaLabelCuffie;
    QLabel* frequenzaDiRispostaLabelCuffie;
    QLabel* connessioneLabelCuffie;
    QLabel* connettoreLabelCuffie;
    QLineEdit* nomeLineEditCuffie;
    QLineEdit* produttoreLineEditCuffie;
    QLineEdit* tipologiaLineEditCuffie;
    QLineEdit* sistemaAcusticoLineEditCuffie;
    QLineEdit* coloreLineEditCuffie;
    QLineEdit* canaliLineEditCuffie;
    QLineEdit* impedenzaLineEditCuffie;
    QLineEdit* frequenzaDiRispostaLineEditCuffie;
    QLineEdit* connessioneLineEditCuffie;
    QLineEdit* connettoreLineEditCuffie;
    QCheckBox* microfonoCheckBoxCuffie;
    QDoubleSpinBox* prezzoDoubleSpinBoxCuffie;

    //Altoparlanti
    QLabel* nomeLabelAltoparlanti;
    QLabel* prezzoLabelAltoparlanti;
    QLabel* produttoreLabelAltoparlanti;
    QLabel* coloreLabelAltoparlanti;
    QLabel* configurazioneLabelAltoparlanti;
    QLabel* frequenzaDiRispostaLabelAltoparlanti;
    QLabel* potenzaTotaleLabelAltoparlanti;
    QLabel* potenzeLabelAltoparlanti;
    QLineEdit* nomeLineEditAltoparlanti;
    QLineEdit* produttoreLineEditAltoparlanti;
    QLineEdit* coloreLineEditAltoparlanti;
    QLineEdit* configurazioneLineEditAltoparlanti;
    QLineEdit* frequenzaDiRispostaLineEditAltoparlanti;
    QLineEdit* potenzaTotaleLineEditAltoparlanti;
    QLineEdit* potenzeLineEditAltoparlanti;
    QDoubleSpinBox* prezzoDoubleSpinBoxAltoparlanti;

    QLineEdit* rimuoviComponenteLineEdit;

    QPushButton* indietroPushButton;
    QPushButton* aggiungiPushButton;
    QPushButton* rimuoviPushButton;

    QComboBox* tipo_componenteAggiungi;

    QStackedWidget* aggiungi_stackedWidget;

    QWidget* aggiungi_emptyPage;
    QWidget* aggiungi_memoriaPage;
    QWidget* aggiungi_schedaGraficaPage;
    QWidget* aggiungi_schedaMadrePage;
    QWidget* aggiungi_processorePage;
    QWidget* aggiungi_archiviazionePage;
    QWidget* aggiungi_alimentatorePage;
    QWidget* aggiungi_dissipatoreProcessorePage;
    QWidget* aggiungi_casePage;
    QWidget* aggiungi_unitaOtticaPage;
    QWidget* aggiungi_monitorPage;
    QWidget* aggiungi_sistemaOperativoPage;
    QWidget* aggiungi_mousePage;
    QWidget* aggiungi_tastieraPage;
    QWidget* aggiungi_cuffiePage;
    QWidget* aggiungi_altoparlantiPage;

    void createLabels();
    void createPushButtons();
    void createLineEdits();
    void createComboBoxes();
    void createCheckBoxes();
    void createSpinBoxes();
    void createDoubleSpinBoxes();
public:
    MyWidget_GestisciComponentiPCBuilder(QWidget* =0);
    void clearForms();

    QPushButton* get_indietroPushButton() const;
    QPushButton* get_aggiungi_PushButton() const;
    QPushButton* get_rimuoviPushButton() const;

    QString tipo_componenteAggiungiValue() const;

    QString rimuoviComponenteValue() const;

    QLineEdit* getRimuoviComponenteLineEdit() const;

    //Memoria
    QString nomeMemoriaValue() const;
    QString produttoreMemoriaValue() const;
    QString velocitaMemoriaValue() const;
    QString capacitaMemoriaValue() const;
    QString tipologiaMemoriaValue() const;
    double prezzoMemoriaValue() const;
    int latenzaMemoriaValue() const;

    //SchedaGrafica
    QString nomeSchedaGraficaValue() const;
    QString produttoreSchedaGraficaValue() const;
    QString interfacciaSchedaGraficaValue() const;
    QString chipsetSchedaGraficaValue() const;
    QString memoriaSchedaGraficaValue() const;
    QString tipologiaMemoriaSchedaGraficaValue() const;
    QString frequenzaCoreSchedaGraficaValue() const;
    QString tdpSchedaGraficaValue() const;
    QString supportoSLISchedaGraficaValue() const;
    QString supportoCrossfireSchedaGraficaValue() const;
    QString lunghezzaSchedaGraficaValue() const;
    double prezzoSchedaGraficaValue() const;

    //SchedaMadre
    QString nomeSchedaMadreValue() const;
    QString produttoreSchedaMadreValue() const;
    QString fattoreDiFormaSchedaMadreValue() const;
    QString chipsetSchedaMadreValue() const;
    QString socketProcessoreSchedaMadreValue() const;
    QString slotMemoriaSchedaMadreValue() const;
    QString tipologiaMemoriaSchedaMadreValue() const;
    QString memoriaMassimaSchedaMadreValue() const;
    QString ethernetSchedaMadreValue() const;
    bool supportoRAIDSchedaMadreValue() const;
    bool supportoCrossfireSchedaMadreValue() const;
    bool supportoSLISchedaMadreValue() const;
    int sata3GBsSchedaMadreValue() const;
    int sata6GBsSchedaMadreValue() const;
    int sataExpressSchedaMadreValue() const;
    int usb2SchedaMadreValue() const;
    int usb3SchedaMadreValue() const;
    double prezzoSchedaMadreValue() const;

    //Processore
    QString nomeProcessoreValue() const;
    QString produttoreProcessoreValue() const;
    QString socketProcessoreValue() const;
    QString larghezzaDatiProcessoreValue() const;
    QString frequenzaOperativaProcessoreValue() const;
    QString frequenzaTurboProcessoreValue() const;
    QString l1CacheProcessoreValue() const;
    QString l2CacheProcessoreValue() const;
    QString l3CacheProcessoreValue() const;
    QString litografiaProcessoreValue() const;
    QString tdpProcessoreValue() const;
    QString graficaIntegrataProcessoreValue() const;
    bool includeDissipatoreProcessoreValue() const;
    bool hyperThreadingProcessoreValue() const;
    int numeroCoreProcessoreValue() const;
    double prezzoProcessoreValue() const;

    //Archiviazione
    QString nomeArchiviazioneValue() const;
    QString produttoreArchiviazioneValue() const;
    QString tipologiaArchiviazioneValue() const;
    QString capacitaArchiviazioneValue() const;
    QString interfacciaArchiviazioneValue() const;
    QString cacheArchiviazioneValue() const;
    QString fattoreDiFormaArchiviazioneValue() const;
    QString rpmArchiviazioneValue() const;
    double prezzoArchiviazioneValue() const;

    //Alimentatore
    QString nomeAlimentatoreValue() const;
    QString produttoreAlimentatoreValue() const;
    QString tipologiaAlimentatoreValue() const;
    QString wattaggioAlimentatoreValue() const;
    QString modulareAlimentatoreValue() const;
    QString certificazioneEfficienzaAlimentatoreValue() const;
    double efficienzaAlimentatoreValue() const;
    double prezzoAlimentatoreValue() const;

    //DissipatoreProcessore
    QString nomeDissipatoreProcessoreValue() const;
    QString produttoreDissipatoreProcessoreValue() const;
    QString socketSupportatiDissipatoreProcessoreValue() const;
    QString rpmVentolaDissipatoreProcessoreValue() const;
    QString altezzaDissipatoreProcessoreValue() const;
    QString altezzaRadiatoreDissipatoreProcessoreValue() const;
    QString livelloRumoreDissipatoreProcessoreValue() const;
    bool raffreddamentoALiquidoDissipatoreProcessoreValue() const;
    double prezzoDissipatoreProcessoreValue() const;

    //Case
    QString nomeCaseValue() const;
    QString produttoreCaseValue() const;
    QString tipologiaCaseValue() const;
    QString coloreCaseValue() const;
    QString compatibilitaSchedaMadreCaseValue() const;
    QString lunghezzaMassimaSchedaGraficaCaseValue() const;
    QString dimensioniCaseValue() const;
    bool alimentatoreInclusoCaseValue() const;
    int slotInterni25CaseValue() const;
    int slotInterni35CaseValue() const;
    double prezzoCaseValue() const;

    //UnitaOttica
    QString nomeUnitaOtticaValue() const;
    QString produttoreUnitaOtticaValue() const;
    QString fattoreDiFormaUnitaOtticaValue() const;
    QString interfacciaUnitaOtticaValue() const;
    QString cacheUnitaOtticaValue() const;
    QString velocitaUnitaOtticaValue() const;
    double prezzoUnitaOtticaValue() const;

    //Monitor
    QString nomeMonitorValue() const;
    QString produttoreMonitorValue() const;
    QString risoluzioneRaccomandataMonitorValue() const;
    QString formatoMonitorValue() const;
    QString angoloDiVisualizzazioneMonitorValue() const;
    QString coloriDelDisplayMonitorValue() const;
    QString luminositaMonitorValue() const;
    QString rapportoDiContrastoMonitorValue() const;
    QString tempoDiRispostaMonitorValue() const;
    QString tipologiaDisplayMonitorValue() const;
    QString frequenzaDiAggiornamentoMonitorValue() const;
    bool altoparlantiIncorporatiMonitorValue() const;
    bool widescreenMonitorValue() const;
    double prezzoMonitorValue() const;

    //SistemaOperativo
    QString nomeSistemaOperativoValue() const;
    QString produttoreSistemaOperativoValue() const;
    QString modalitaSistemaOperativoValue() const;
    QString memoriaMassimaSupportataSistemaOperativoValue() const;
    double prezzoSistemaOperativoValue() const;

    //Mouse
    QString nomeMouseValue() const;
    QString produttoreMouseValue() const;
    QString connessioneMouseValue() const;
    QString tipologiaTracciamentoMouseValue() const;
    QString coloreMouseValue() const;
    QString orientamentoDellaManoMouseValue() const;
    int dpiMassimiMouseValue() const;
    double prezzoMouseValue() const;

    //Tastiera
    QString nomeTastieraValue() const;
    QString produttoreTastieraValue() const;
    QString coloreTastieraValue() const;
    QString connessioneTastieraValue() const;
    QString tipologiaTastieraValue() const;
    QString tipologiaSwitchTastieraValue() const;
    bool retroilluminazioneTastieraValue() const;
    double prezzoTastieraValue() const;

    //Cuffie
    QString nomeCuffieValue() const;
    QString produttoreCuffieValue() const;
    QString tipologiaCuffieValue() const;
    QString sistemaAcusticoCuffieValue() const;
    QString coloreCuffieValue() const;
    QString canaliCuffieValue() const;
    QString impedenzaCuffieValue() const;
    QString frequenzaDiRispostaCuffieValue() const;
    QString connessioneCuffieValue() const;
    QString connettoreCuffieValue() const;
    bool microfonoCuffieValue() const;
    double prezzoCuffieValue() const;

    //Altoparlanti
    QString nomeAltoparlantiValue() const;
    QString produttoreAltoparlantiValue() const;
    QString coloreAltoparlantiValue() const;
    QString configurazioneAltoparlantiValue() const;
    QString frequenzaDiRispostaAltoparlantiValue() const;
    QString potenzaTotaleAltoparlantiValue() const;
    QString potenzeAltoparlantiValue() const;
    double prezzoAltoparlantiValue() const;

};

#endif // MYWIDGET_GESTISCICOMPONENTIPCBUILDER_H
