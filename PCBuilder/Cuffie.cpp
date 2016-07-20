#include "Cuffie.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Cuffie::Cuffie(const QString& input_nome, double input_prezzo, const QString& input_produttore,
               const QString& input_tipologia, const QString& input_sistemaAcustico, const QString& input_colore,
               bool input_microfono, const QString& input_canali, const QString& input_impedenza,
               const QString& input_frequenzaDiRisposta, const QString& input_connessione, const QString& input_connettore):
    Componente(input_nome,input_prezzo,input_produttore),tipologia(input_tipologia),sistemaAcustico(input_sistemaAcustico),
    colore(input_colore),microfono(input_microfono),canali(input_canali),impedenza(input_impedenza),
    frequenzaDiRisposta(input_frequenzaDiRisposta),connessione(input_connessione),connettore(input_connettore){}

void Cuffie::saveXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode cuffie_node=doc.createElement("Cuffie");
        root.appendChild(cuffie_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode sistemaAcustico_node=doc.createElement("SistemaAcustico");
        sistemaAcustico_node.appendChild(doc.createTextNode(this->getSistemaAcustico()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode microfono_node=doc.createElement("Microfono");
        microfono_node.appendChild(doc.createTextNode(QString::number(this->getMicrofono())));

        QDomNode canali_node=doc.createElement("Canali");
        canali_node.appendChild(doc.createTextNode(this->getCanali()));

        QDomNode impedenza_node=doc.createElement("Impedenza");
        impedenza_node.appendChild(doc.createTextNode(this->getImpedenza()));

        QDomNode frequenzaDiRisposta_node=doc.createElement("FrequenzaDiRisposta");
        frequenzaDiRisposta_node.appendChild(doc.createTextNode(this->getFrequenzaDiRisposta()));

        QDomNode connessione_node=doc.createElement("Connessione");
        connessione_node.appendChild(doc.createTextNode(this->getConnessione()));

        QDomNode connettore_node=doc.createElement("Connettore");
        connettore_node.appendChild(doc.createTextNode(this->getConnettore()));

        cuffie_node.appendChild(nome_node);
        cuffie_node.appendChild(prezzo_node);
        cuffie_node.appendChild(produttore_node);
        cuffie_node.appendChild(tipologia_node);
        cuffie_node.appendChild(sistemaAcustico_node);
        cuffie_node.appendChild(colore_node);
        cuffie_node.appendChild(microfono_node);
        cuffie_node.appendChild(canali_node);
        cuffie_node.appendChild(impedenza_node);
        cuffie_node.appendChild(frequenzaDiRisposta_node);
        cuffie_node.appendChild(connessione_node);
        cuffie_node.appendChild(connettore_node);

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
        QDomNode cuffie_node=doc.createElement("Cuffie");
        componenti_node.appendChild(cuffie_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode sistemaAcustico_node=doc.createElement("SistemaAcustico");
        sistemaAcustico_node.appendChild(doc.createTextNode(this->getSistemaAcustico()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode microfono_node=doc.createElement("Microfono");
        microfono_node.appendChild(doc.createTextNode(QString::number(this->getMicrofono())));

        QDomNode canali_node=doc.createElement("Canali");
        canali_node.appendChild(doc.createTextNode(this->getCanali()));

        QDomNode impedenza_node=doc.createElement("Impedenza");
        impedenza_node.appendChild(doc.createTextNode(this->getImpedenza()));

        QDomNode frequenzaDiRisposta_node=doc.createElement("FrequenzaDiRisposta");
        frequenzaDiRisposta_node.appendChild(doc.createTextNode(this->getFrequenzaDiRisposta()));

        QDomNode connessione_node=doc.createElement("Connessione");
        connessione_node.appendChild(doc.createTextNode(this->getConnessione()));

        QDomNode connettore_node=doc.createElement("Connettore");
        connettore_node.appendChild(doc.createTextNode(this->getConnettore()));

        cuffie_node.appendChild(nome_node);
        cuffie_node.appendChild(prezzo_node);
        cuffie_node.appendChild(produttore_node);
        cuffie_node.appendChild(tipologia_node);
        cuffie_node.appendChild(sistemaAcustico_node);
        cuffie_node.appendChild(colore_node);
        cuffie_node.appendChild(microfono_node);
        cuffie_node.appendChild(canali_node);
        cuffie_node.appendChild(impedenza_node);
        cuffie_node.appendChild(frequenzaDiRisposta_node);
        cuffie_node.appendChild(connessione_node);
        cuffie_node.appendChild(connettore_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Cuffie::deleteXMLComponente(){
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
        QDomNode tipologia_node;
        QDomNode sistemaAcustico_node;
        QDomNode colore_node;
        QDomNode microfono_node;
        QDomNode canali_node;
        QDomNode impedenza_node;
        QDomNode frequenzaDiRisposta_node;
        QDomNode connessione_node;
        QDomNode connettore_node;

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
                tipologia_node=produttore_node.nextSiblingElement();
                sistemaAcustico_node=tipologia_node.nextSiblingElement();
                colore_node=sistemaAcustico_node.nextSiblingElement();
                microfono_node=colore_node.nextSiblingElement();
                canali_node=microfono_node.nextSiblingElement();
                impedenza_node=canali_node.nextSiblingElement();
                frequenzaDiRisposta_node=impedenza_node.nextSiblingElement();
                connessione_node=frequenzaDiRisposta_node.nextSiblingElement();
                connettore_node=connessione_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(tipologia_node);
        componente_node.removeChild(sistemaAcustico_node);
        componente_node.removeChild(colore_node);
        componente_node.removeChild(microfono_node);
        componente_node.removeChild(canali_node);
        componente_node.removeChild(impedenza_node);
        componente_node.removeChild(frequenzaDiRisposta_node);
        componente_node.removeChild(connessione_node);
        componente_node.removeChild(connettore_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

QString Cuffie::getTipologia() const{
    return tipologia;
}

QString Cuffie::getSistemaAcustico() const{
    return sistemaAcustico;
}

QString Cuffie::getColore() const{
    return colore;
}

bool Cuffie::getMicrofono() const{
    return microfono;
}

QString Cuffie::getCanali() const{
    return canali;
}

QString Cuffie::getImpedenza() const{
    return impedenza;
}

QString Cuffie::getFrequenzaDiRisposta() const{
    return frequenzaDiRisposta;
}

QString Cuffie::getConnessione() const{
    return connessione;
}

QString Cuffie::getConnettore() const{
    return connettore;
}

QString Cuffie::getType() const{
    return "Cuffie";
}
