#ifndef ARCHIVIAZIONESPECSWIDGET_H
#define ARCHIVIAZIONESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class ArchiviazioneSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* tipologiaLabel;
    QLabel* tipologiaValueLabel;
    QLabel* capacitaLabel;
    QLabel* capacitaValueLabel;
    QLabel* interfacciaLabel;
    QLabel* interfacciaValueLabel;
    QLabel* cacheLabel;
    QLabel* cacheValueLabel;
    QLabel* fattoreDiFormaLabel;
    QLabel* fattoreDiFormaValueLabel;
    QLabel* rpmLabel;
    QLabel* rpmValueLabel;
public:
    ArchiviazioneSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setTipologiaValueLabel(const QString&);
    void setCapacitaValueLabel(const QString&);
    void setInterfacciaValueLabel(const QString&);
    void setCacheValueLabel(const QString&);
    void setFattoreDiFormaValueLabel(const QString&);
    void setRpmValueLabel(const QString&);
};

#endif // ARCHIVIAZIONESPECSWIDGET_H
