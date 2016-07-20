#include "Monitor.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Monitor::Monitor(const QString& input_nome, double input_prezzo, const QString& input_produttore,
                 const QString& input_risoluzioneRaccomandata, bool input_widescreen,
                 const QString& input_formato, const QString& input_angoloDiVisualizzazione,
                 const QString& input_coloriDelDisplay, const QString& input_luminosita, const QString& input_rapportoDiContrasto,
                 const QString& input_tempoDiRisposta, const QString& input_tipologiaDisplay,
                 bool input_altoparlantiIncorporati, const QString& input_frequenzaDiAggiornamento):Componente(input_nome,input_prezzo,input_produttore),
    risoluzioneRaccomandata(input_risoluzioneRaccomandata),widescreen(input_widescreen),formato(input_formato),
    angoloDiVisualizzazione(input_angoloDiVisualizzazione),coloriDelDisplay(input_coloriDelDisplay),luminosita(input_luminosita),
    rapportoDiContrasto(input_rapportoDiContrasto),tempoDiRisposta(input_tempoDiRisposta),tipologiaDisplay(input_tipologiaDisplay),
    altoparlantiIncorporati(input_altoparlantiIncorporati),frequenzaDiAggiornamento(input_frequenzaDiAggiornamento){}

void Monitor::saveXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode monitor_node=doc.createElement("Monitor");
        root.appendChild(monitor_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode risoluzioneRaccomandata_node=doc.createElement("RisoluzioneRaccomandata");
        risoluzioneRaccomandata_node.appendChild(doc.createTextNode(this->getRisoluzioneRaccomandata()));

        QDomNode widescreen_node=doc.createElement("Widescreen");
        widescreen_node.appendChild(doc.createTextNode(QString::number(this->getWidescreen())));

        QDomNode formato_node=doc.createElement("Formato");
        formato_node.appendChild(doc.createTextNode(this->getFormato()));

        QDomNode angoloDiVisualizzazione_node=doc.createElement("AngoloDiVisualizzazione");
        angoloDiVisualizzazione_node.appendChild(doc.createTextNode(this->getAngoloDiVisualizzazione()));

        QDomNode coloriDelDisplay_node=doc.createElement("ColoriDelDisplay");
        coloriDelDisplay_node.appendChild(doc.createTextNode(this->getColoriDelDisplay()));

        QDomNode luminosita_node=doc.createElement("Luminosita");
        luminosita_node.appendChild(doc.createTextNode(this->getLuminosita()));

        QDomNode rapportoDiContrasto_node=doc.createElement("RapportoDiContrasto");
        rapportoDiContrasto_node.appendChild(doc.createTextNode(this->getRapportoDiContrasto()));

        QDomNode tempoDiRisposta_node=doc.createElement("TempoDiRisposta");
        tempoDiRisposta_node.appendChild(doc.createTextNode(this->getTempoDiRisposta()));

        QDomNode tipologiaDisplay_node=doc.createElement("TipologiaDisplay");
        tipologiaDisplay_node.appendChild(doc.createTextNode(this->getTipologiaDisplay()));

        QDomNode altoparlantiIncorporati_node=doc.createElement("AltoparlantiIncorporati");
        altoparlantiIncorporati_node.appendChild(doc.createTextNode(QString::number(this->getAltoparlantiIncorporati())));

        QDomNode frequenzaDiAggiornamento_node=doc.createElement("FrequenzaDiAggiornamento");
        frequenzaDiAggiornamento_node.appendChild(doc.createTextNode(this->getFrequenzaDiAggiornamento()));

        monitor_node.appendChild(nome_node);
        monitor_node.appendChild(prezzo_node);
        monitor_node.appendChild(produttore_node);
        monitor_node.appendChild(risoluzioneRaccomandata_node);
        monitor_node.appendChild(widescreen_node);
        monitor_node.appendChild(formato_node);
        monitor_node.appendChild(angoloDiVisualizzazione_node);
        monitor_node.appendChild(coloriDelDisplay_node);
        monitor_node.appendChild(luminosita_node);
        monitor_node.appendChild(rapportoDiContrasto_node);
        monitor_node.appendChild(tempoDiRisposta_node);
        monitor_node.appendChild(tipologiaDisplay_node);
        monitor_node.appendChild(altoparlantiIncorporati_node);
        monitor_node.appendChild(frequenzaDiAggiornamento_node);

        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
    else
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomProcessingInstruction header=doc.createProcessingInstruction("xml","version='1.0' encoding='UTF-8'");
        doc.appendChild(header);
        QDomNode componenti_node=doc.createElement("Componenti");
        doc.appendChild(componenti_node);
        QDomNode monitor_node=doc.createElement("Monitor");
        componenti_node.appendChild(monitor_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode risoluzioneRaccomandata_node=doc.createElement("RisoluzioneRaccomandata");
        risoluzioneRaccomandata_node.appendChild(doc.createTextNode(this->getRisoluzioneRaccomandata()));

        QDomNode widescreen_node=doc.createElement("Widescreen");
        widescreen_node.appendChild(doc.createTextNode(QString::number(this->getWidescreen())));

        QDomNode formato_node=doc.createElement("Formato");
        formato_node.appendChild(doc.createTextNode(this->getFormato()));

        QDomNode angoloDiVisualizzazione_node=doc.createElement("AngoloDiVisualizzazione");
        angoloDiVisualizzazione_node.appendChild(doc.createTextNode(this->getAngoloDiVisualizzazione()));

        QDomNode coloriDelDisplay_node=doc.createElement("ColoriDelDisplay");
        coloriDelDisplay_node.appendChild(doc.createTextNode(this->getColoriDelDisplay()));

        QDomNode luminosita_node=doc.createElement("Luminosita");
        luminosita_node.appendChild(doc.createTextNode(this->getLuminosita()));

        QDomNode rapportoDiContrasto_node=doc.createElement("RapportoDiContrasto");
        rapportoDiContrasto_node.appendChild(doc.createTextNode(this->getRapportoDiContrasto()));

        QDomNode tempoDiRisposta_node=doc.createElement("TempoDiRisposta");
        tempoDiRisposta_node.appendChild(doc.createTextNode(this->getTempoDiRisposta()));

        QDomNode tipologiaDisplay_node=doc.createElement("TipologiaDisplay");
        tipologiaDisplay_node.appendChild(doc.createTextNode(this->getTipologiaDisplay()));

        QDomNode altoparlantiIncorporati_node=doc.createElement("AltoparlantiIncorporati");
        altoparlantiIncorporati_node.appendChild(doc.createTextNode(QString::number(this->getAltoparlantiIncorporati())));

        QDomNode frequenzaDiAggiornamento_node=doc.createElement("FrequenzaDiAggiornamento");
        frequenzaDiAggiornamento_node.appendChild(doc.createTextNode(this->getFrequenzaDiAggiornamento()));

        monitor_node.appendChild(nome_node);
        monitor_node.appendChild(prezzo_node);
        monitor_node.appendChild(produttore_node);
        monitor_node.appendChild(risoluzioneRaccomandata_node);
        monitor_node.appendChild(widescreen_node);
        monitor_node.appendChild(formato_node);
        monitor_node.appendChild(angoloDiVisualizzazione_node);
        monitor_node.appendChild(coloriDelDisplay_node);
        monitor_node.appendChild(luminosita_node);
        monitor_node.appendChild(rapportoDiContrasto_node);
        monitor_node.appendChild(tempoDiRisposta_node);
        monitor_node.appendChild(tipologiaDisplay_node);
        monitor_node.appendChild(altoparlantiIncorporati_node);
        monitor_node.appendChild(frequenzaDiAggiornamento_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Monitor::deleteXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QFile file(filename);
        QDomDocument doc("Componenti");
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode componente_node=root.firstChildElement();

        QDomNode nome_node;
        QDomNode prezzo_node;
        QDomNode produttore_node;
        QDomNode risoluzioneRaccomandata_node;
        QDomNode widescreen_node;
        QDomNode formato_node;
        QDomNode angoloDiVisualizzazione_node;
        QDomNode coloriDelDisplay_node;
        QDomNode luminosita_node;
        QDomNode rapportoDiContrasto_node;
        QDomNode tempoDiRisposta_node;
        QDomNode tipologiaDisplay_node;
        QDomNode altoparlantiIncorporati_node;
        QDomNode frequenzaDiAggiornamento_node;

        bool trovato=false;
        while (!componente_node.isNull() && !trovato)
        {
            nome_node=componente_node.firstChildElement();

            QString nome_value=nome_node.firstChild().nodeValue();
            if (nome_value!=this->getNome())
                componente_node=componente_node.nextSiblingElement();
            else
            {
                prezzo_node=nome_node.nextSiblingElement();
                produttore_node=prezzo_node.nextSiblingElement();
                risoluzioneRaccomandata_node=produttore_node.nextSiblingElement();
                widescreen_node=risoluzioneRaccomandata_node.nextSiblingElement();
                formato_node=widescreen_node.nextSiblingElement();
                angoloDiVisualizzazione_node=formato_node.nextSiblingElement();
                coloriDelDisplay_node=angoloDiVisualizzazione_node.nextSiblingElement();
                luminosita_node=coloriDelDisplay_node.nextSiblingElement();
                rapportoDiContrasto_node=luminosita_node.nextSiblingElement();
                tempoDiRisposta_node=rapportoDiContrasto_node.nextSiblingElement();
                tipologiaDisplay_node=tempoDiRisposta_node.nextSiblingElement();
                altoparlantiIncorporati_node=tipologiaDisplay_node.nextSiblingElement();
                frequenzaDiAggiornamento_node=altoparlantiIncorporati_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(risoluzioneRaccomandata_node);
        componente_node.removeChild(widescreen_node);
        componente_node.removeChild(formato_node);
        componente_node.removeChild(angoloDiVisualizzazione_node);
        componente_node.removeChild(coloriDelDisplay_node);
        componente_node.removeChild(luminosita_node);
        componente_node.removeChild(rapportoDiContrasto_node);
        componente_node.removeChild(tempoDiRisposta_node);
        componente_node.removeChild(tipologiaDisplay_node);
        componente_node.removeChild(altoparlantiIncorporati_node);
        componente_node.removeChild(frequenzaDiAggiornamento_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

QString Monitor::getRisoluzioneRaccomandata() const{
    return risoluzioneRaccomandata;
}

bool Monitor::getWidescreen() const{
    return widescreen;
}

QString Monitor::getFormato() const{
    return formato;
}

QString Monitor::getAngoloDiVisualizzazione() const{
    return angoloDiVisualizzazione;
}

QString Monitor::getColoriDelDisplay() const{
    return coloriDelDisplay;
}

QString Monitor::getLuminosita() const{
    return luminosita;
}

QString Monitor::getRapportoDiContrasto() const{
    return rapportoDiContrasto;
}

QString Monitor::getTempoDiRisposta() const{
    return tempoDiRisposta;
}

QString Monitor::getTipologiaDisplay() const{
    return tipologiaDisplay;
}

bool Monitor::getAltoparlantiIncorporati() const{
    return altoparlantiIncorporati;
}

QString Monitor::getFrequenzaDiAggiornamento() const{
    return frequenzaDiAggiornamento;
}

QString Monitor::getType() const{
    return "Monitor";
}
