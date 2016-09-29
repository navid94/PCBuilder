#ifndef MYWIDGET_CREACONFPCBUILDER_H
#define MYWIDGET_CREACONFPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSignalMapper>
#include <QString>
#include <QLayout>

class MyWidget_CreaConfPCBuilder:public QWidget{
    Q_OBJECT
private:

    QSignalMapper* signalMapper;
    QGridLayout* gridLayout;

    QLabel* PCBuiler_creaconfLabel;
    QLabel* componenteLabel;
    QLabel* selezioneLabel;
    QLabel* prezzoLabel;
    QLabel* totaleLabel;
    QLabel* processoreLabel;
    QLabel* dissipatoreProcessoreLabel;
    QLabel* schedaMadreLabel;
    QLabel* memoriaLabel;
    QLabel* archiviazioneLabel;
    QLabel* schedaGraficaLabel;
    QLabel* caseLabel;
    QLabel* alimentatoreLabel;
    QLabel* unitaOtticaLabel;
    QLabel* sistemaOperativoLabel;
    QLabel* monitorLabel;
    QLabel* mouseLabel;
    QLabel* tastieraLabel;
    QLabel* cuffieLabel;
    QLabel* altoparlantiLabel;

    QLabel* processorePrezzoLabel;
    QLabel* dissipatoreProcessorePrezzoLabel;
    QLabel* schedaMadrePrezzoLabel;
    QLabel* memoriaPrezzoLabel;
    QLabel* archiviazionePrezzoLabel;
    QLabel* schedaGraficaPrezzoLabel;
    QLabel* casePrezzoLabel;
    QLabel* alimentatorePrezzoLabel;
    QLabel* unitaOtticaPrezzoLabel;
    QLabel* sistemaOperativoPrezzoLabel;
    QLabel* monitorPrezzoLabel;
    QLabel* mousePrezzoLabel;
    QLabel* tastieraPrezzoLabel;
    QLabel* cuffiePrezzoLabel;
    QLabel* altoparlantiPrezzoLabel;

    QLabel* prezzoTotaleLabel;

    QLabel* processoreNomeLabel;
    QLabel* dissipatoreProcessoreNomeLabel;
    QLabel* schedaMadreNomeLabel;
    QLabel* memoriaNomeLabel;
    QLabel* archiviazioneNomeLabel;
    QLabel* schedaGraficaNomeLabel;
    QLabel* caseNomeLabel;
    QLabel* alimentatoreNomeLabel;
    QLabel* unitaOtticaNomeLabel;
    QLabel* sistemaOperativoNomeLabel;
    QLabel* monitorNomeLabel;
    QLabel* mouseNomeLabel;
    QLabel* tastieraNomeLabel;
    QLabel* cuffieNomeLabel;
    QLabel* altoparlantiNomeLabel;

    QPushButton* indietroPushButton;
    QPushButton* salvaConfigurazionePushButton;
    QPushButton* nuovaConfigurazionePushButton;
    QPushButton* aggiungiProcessorePushButton;
    QPushButton* aggiungiDissipatoreProcessorePushButton;
    QPushButton* aggiungiSchedaMadrePushButton;
    QPushButton* aggiungiMemoriaPushButton;
    QPushButton* aggiungiArchiviazionePushButton;
    QPushButton* aggiungiSchedaGraficaPushButton;
    QPushButton* aggiungiCasePushButton;
    QPushButton* aggiungiAlimentatorePushButton;
    QPushButton* aggiungiUnitaOtticaPushButton;
    QPushButton* aggiungiSistemaOperativoPushButton;
    QPushButton* aggiungiMonitorPushButton;
    QPushButton* aggiungiMousePushButton;
    QPushButton* aggiungiTastieraPushButton;
    QPushButton* aggiungiCuffiePushButton;
    QPushButton* aggiungiAltoparlantiPushButton;

    void createPushButtons();
    void createLabels();
public:
    MyWidget_CreaConfPCBuilder(QWidget* =0);

    QGridLayout* getGridLayout() const;

    QPushButton* getIndietroPushButton() const;
    QPushButton* getSalvaConfigurazionePushButton() const;
    QPushButton* getNuovaConfigurazionePushButton() const;
    QPushButton* getAggiungiProcessorePushButton() const;
    QPushButton* getAggiungiDissipatoreProcessorePushButton() const;
    QPushButton* getAggiungiSchedaMadrePushButton() const;
    QPushButton* getAggiungiMemoriaPushButton() const;
    QPushButton* getAggiungiArchiviazionePushButton() const;
    QPushButton* getAggiungiSchedaGraficaPushButton() const;
    QPushButton* getAggiungiCasePushButton() const;
    QPushButton* getAggiungiAlimentatorePushButton() const;
    QPushButton* getAggiungiUnitaOtticaPushButton() const;
    QPushButton* getAggiungiSistemaOperativoPushButton() const;
    QPushButton* getAggiungiMonitorPushButton() const;
    QPushButton* getAggiungiMousePushButton() const;
    QPushButton* getAggiungiTastieraPushButton() const;
    QPushButton* getAggiungiCuffiePushButton() const;
    QPushButton* getAggiungiAltoparlantiPushButton() const;

    QLabel* getProcessoreNomeLabel() const;
    QLabel* getDissipatoreProcessoreNomeLabel() const;
    QLabel* getSchedaMadreNomeLabel() const;
    QLabel* getMemoriaNomeLabel() const;
    QLabel* getArchiviazioneNomeLabel() const;
    QLabel* getSchedaGraficaNomeLabel() const;
    QLabel* getCaseNomeLabel() const;
    QLabel* getAlimentatoreNomeLabel() const;
    QLabel* getUnitaOtticaNomeLabel() const;
    QLabel* getSistemaOperativoNomeLabel() const;
    QLabel* getMonitorNomeLabel() const;
    QLabel* getMouseNomeLabel() const;
    QLabel* getTastieraNomeLabel() const;
    QLabel* getCuffieNomeLabel() const;
    QLabel* getAltoparlantiNomeLabel() const;
/*
    QLabel* getProcessorePrezzoLabel() const;
    QLabel* getDissipatoreProcessorePrezzoLabel() const;
    QLabel* getSchedaMadrePrezzoLabel() const;
    QLabel* getMemoriaPrezzoLabel() const;
    QLabel* getArchiviazionePrezzoLabel() const;
    QLabel* getSchedaGraficaPrezzoLabel() const;
    QLabel* getCasePrezzoLabel() const;
    QLabel* getAlimentatorePrezzoLabel() const;
    QLabel* getUnitaOtticaPrezzoLabel() const;
    QLabel* getSistemaOperativoPrezzoLabel() const;
    QLabel* getMonitorPrezzoLabel() const;
    QLabel* getMousePrezzoLabel() const;
    QLabel* getTastieraPrezzoLabel() const;
    QLabel* getCuffiePrezzoLabel() const;
    QLabel* getAltoparlantiPrezzoLabel() const;
*/
    void setProcessorePrezzoLabel(const QString&);
    void setDissipatoreProcessorePrezzoLabel(const QString&);
    void setSchedaMadrePrezzoLabel(const QString&);
    void setMemoriaPrezzoLabel(const QString&);
    void setArchiviazionePrezzoLabel(const QString&);
    void setSchedaGraficaPrezzoLabel(const QString&);
    void setCasePrezzoLabel(const QString&);
    void setAlimentatorePrezzoLabel(const QString&);
    void setUnitaOtticaPrezzoLabel(const QString&);
    void setSistemaOperativoPrezzoLabel(const QString&);
    void setMonitorPrezzoLabel(const QString&);
    void setMousePrezzoLabel(const QString&);
    void setTastieraPrezzoLabel(const QString&);
    void setCuffiePrezzoLabel(const QString&);
    void setAltoparlantiPrezzoLabel(const QString&);
    void setPrezzoTotaleLabel(const QString&);
signals:
    void sendMessage(const QString&);
};

#endif // MYWIDGET_CREACONFPCBUILDER_H
