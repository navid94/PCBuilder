#include "Altoparlanti.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Altoparlanti::Altoparlanti(const QString& input_nome, double input_prezzo, const QString& input_produttore,
                           const QString& input_colore, const QString& input_configurazione,
                           const QString& input_frequenzaDiRisposta, const QString& input_potenzaTotale,
                           const QString& input_potenze):Componente(input_nome,input_prezzo,input_produttore),
    colore(input_colore),configurazione(input_configurazione),frequenzaDiRisposta(input_frequenzaDiRisposta),
    potenzaTotale(input_potenzaTotale),potenze(input_potenze){}

void Altoparlanti::saveXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode altoparlanti_node=doc.createElement("Altoparlanti");
        root.appendChild(altoparlanti_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode configurazione_node=doc.createElement("Configurazione");
        configurazione_node.appendChild(doc.createTextNode(this->getConfigurazione()));

        QDomNode frequenzaDiRisposta_node=doc.createElement("FrequenzaDiRisposta");
        frequenzaDiRisposta_node.appendChild(doc.createTextNode(this->getFrequenzaDiRisposta()));

        QDomNode potenzaTotale_node=doc.createElement("PotenzaTotale");
        potenzaTotale_node.appendChild(doc.createTextNode(this->getPotenzaTotale()));

        QDomNode potenze_node=doc.createElement("Potenze");
        potenze_node.appendChild(doc.createTextNode(this->getPotenze()));

        altoparlanti_node.appendChild(nome_node);
        altoparlanti_node.appendChild(prezzo_node);
        altoparlanti_node.appendChild(produttore_node);
        altoparlanti_node.appendChild(colore_node);
        altoparlanti_node.appendChild(configurazione_node);
        altoparlanti_node.appendChild(frequenzaDiRisposta_node);
        altoparlanti_node.appendChild(potenzaTotale_node);
        altoparlanti_node.appendChild(potenze_node);

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
        QDomNode altoparlanti_node=doc.createElement("Altoparlanti");
        componenti_node.appendChild(altoparlanti_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode configurazione_node=doc.createElement("Configurazione");
        configurazione_node.appendChild(doc.createTextNode(this->getConfigurazione()));

        QDomNode frequenzaDiRisposta_node=doc.createElement("FrequenzaDiRisposta");
        frequenzaDiRisposta_node.appendChild(doc.createTextNode(this->getFrequenzaDiRisposta()));

        QDomNode potenzaTotale_node=doc.createElement("PotenzaTotale");
        potenzaTotale_node.appendChild(doc.createTextNode(this->getPotenzaTotale()));

        QDomNode potenze_node=doc.createElement("Potenze");
        potenze_node.appendChild(doc.createTextNode(this->getPotenze()));

        altoparlanti_node.appendChild(nome_node);
        altoparlanti_node.appendChild(prezzo_node);
        altoparlanti_node.appendChild(produttore_node);
        altoparlanti_node.appendChild(colore_node);
        altoparlanti_node.appendChild(configurazione_node);
        altoparlanti_node.appendChild(frequenzaDiRisposta_node);
        altoparlanti_node.appendChild(potenzaTotale_node);
        altoparlanti_node.appendChild(potenze_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Altoparlanti::deleteXMLComponente(){
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
        QDomNode colore_node;
        QDomNode configurazione_node;
        QDomNode frequenzaDiRisposta_node;
        QDomNode potenzaTotale_node;
        QDomNode potenze_node;

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
                colore_node=produttore_node.nextSiblingElement();
                configurazione_node=colore_node.nextSiblingElement();
                frequenzaDiRisposta_node=configurazione_node.nextSiblingElement();
                potenzaTotale_node=frequenzaDiRisposta_node.nextSiblingElement();
                potenze_node=potenzaTotale_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(colore_node);
        componente_node.removeChild(configurazione_node);
        componente_node.removeChild(frequenzaDiRisposta_node);
        componente_node.removeChild(potenzaTotale_node);
        componente_node.removeChild(potenze_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}


QString Altoparlanti::getColore() const{
    return colore;
}

QString Altoparlanti::getConfigurazione() const{
    return configurazione;
}

QString Altoparlanti::getFrequenzaDiRisposta() const{
    return frequenzaDiRisposta;
}

QString Altoparlanti::getPotenzaTotale() const{
    return potenzaTotale;
}

QString Altoparlanti::getPotenze() const{
    return potenze;
}

QString Altoparlanti::getType() const{
    return "Altoparlanti";
}
