#ifndef ARCHIVIAZIONEADDWIDGET_H
#define ARCHIVIAZIONEADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>

class ArchiviazioneAddWidget:public QWidget{
    Q_OBJECT
private:
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
public:
    ArchiviazioneAddWidget(QWidget* =0);
    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();

    QString nomeArchiviazioneValue() const;
    QString produttoreArchiviazioneValue() const;
    QString tipologiaArchiviazioneValue() const;
    QString capacitaArchiviazioneValue() const;
    QString interfacciaArchiviazioneValue() const;
    QString cacheArchiviazioneValue() const;
    QString fattoreDiFormaArchiviazioneValue() const;
    QString rpmArchiviazioneValue() const;
    double prezzoArchiviazioneValue() const;

    QLineEdit* getNomeLineEditArchiviazione() const;
    QLineEdit* getProduttoreLineEditArchiviazione() const;
    QLineEdit* getTipologiaLineEditArchiviazione() const;
    QLineEdit* getCapacitaLineEditArchiviazione() const;
    QLineEdit* getInterfacciaLineEditArchiviazione() const;
    QLineEdit* getCacheLineEditArchiviazione() const;
    QLineEdit* getFattoreDiFormaLineEditArchiviazione() const;
    QLineEdit* getRpmLineEditArchiviazione() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxArchiviazione() const;
};

#endif // ARCHIVIAZIONEADDWIDGET_H
