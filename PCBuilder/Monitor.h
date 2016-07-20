#ifndef MONITOR_H
#define MONITOR_H

#include "Componente.h"

class Monitor:public Componente{
private:
    QString risoluzioneRaccomandata;
    bool widescreen;
    QString formato;
    QString angoloDiVisualizzazione;
    QString coloriDelDisplay;
    QString luminosita;
    QString rapportoDiContrasto;
    QString tempoDiRisposta;
    QString tipologiaDisplay;
    bool altoparlantiIncorporati;
    QString frequenzaDiAggiornamento;
public:
    Monitor(const QString&, double, const QString&, const QString&, bool, const QString&, const QString&, const QString&,
             const QString&, const QString&, const QString&, const QString&, bool, const QString&);
    virtual void saveXMLComponente();
    virtual void deleteXMLComponente();
    virtual QString getType() const;

    QString getRisoluzioneRaccomandata() const;
    bool getWidescreen() const;
    QString getFormato() const;
    QString getAngoloDiVisualizzazione() const;
    QString getColoriDelDisplay() const;
    QString getLuminosita() const;
    QString getRapportoDiContrasto() const;
    QString getTempoDiRisposta() const;
    QString getTipologiaDisplay() const;
    bool getAltoparlantiIncorporati() const;
    QString getFrequenzaDiAggiornamento() const;
};

#endif // MONITOR_H
