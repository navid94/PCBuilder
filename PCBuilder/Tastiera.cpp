#include "Tastiera.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Tastiera::Tastiera(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller,
                   const QString& input_colore, bool input_retroilluminazione, const QString& input_connessione,
                   const QString& input_tipologia, const QString& input_tipologiaSwitch):
    Componente(input_nome,input_prezzo,input_produttore,input_controller),colore(input_colore),retroilluminazione(input_retroilluminazione),
    connessione(input_connessione),tipologia(input_tipologia),tipologiaSwitch(input_tipologiaSwitch){}

Tastiera::Tastiera(PCBuilderController* input_controller):Componente(input_controller){}

void Tastiera::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode tastiera_node=doc.createElement("Tastiera");
        root.appendChild(tastiera_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode retroilluminazione_node=doc.createElement("Retroilluminazione");
        retroilluminazione_node.appendChild(doc.createTextNode(QString::number(this->getRetroilluminazione())));

        QDomNode connessione_node=doc.createElement("Connessione");
        connessione_node.appendChild(doc.createTextNode(this->getConnessione()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode tipologiaSwitch_node=doc.createElement("TipologiaSwitch");
        tipologiaSwitch_node.appendChild(doc.createTextNode(this->getTipologiaSwitch()));

        tastiera_node.appendChild(nome_node);
        tastiera_node.appendChild(prezzo_node);
        tastiera_node.appendChild(produttore_node);
        tastiera_node.appendChild(colore_node);
        tastiera_node.appendChild(retroilluminazione_node);
        tastiera_node.appendChild(connessione_node);
        tastiera_node.appendChild(tipologia_node);
        tastiera_node.appendChild(tipologiaSwitch_node);

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
        QDomNode tastiera_node=doc.createElement("Tastiera");
        componenti_node.appendChild(tastiera_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode retroilluminazione_node=doc.createElement("Retroilluminazione");
        retroilluminazione_node.appendChild(doc.createTextNode(QString::number(this->getRetroilluminazione())));

        QDomNode connessione_node=doc.createElement("Connessione");
        connessione_node.appendChild(doc.createTextNode(this->getConnessione()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode tipologiaSwitch_node=doc.createElement("TipologiaSwitch");
        tipologiaSwitch_node.appendChild(doc.createTextNode(this->getTipologiaSwitch()));

        tastiera_node.appendChild(nome_node);
        tastiera_node.appendChild(prezzo_node);
        tastiera_node.appendChild(produttore_node);
        tastiera_node.appendChild(colore_node);
        tastiera_node.appendChild(retroilluminazione_node);
        tastiera_node.appendChild(connessione_node);
        tastiera_node.appendChild(tipologia_node);
        tastiera_node.appendChild(tipologiaSwitch_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Tastiera::deleteXMLComponente() const{
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
        QDomNode retroilluminazione_node;
        QDomNode connessione_node;
        QDomNode tipologia_node;
        QDomNode tipologiaSwitch_node;

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
                retroilluminazione_node=colore_node.nextSiblingElement();
                connessione_node=retroilluminazione_node.nextSiblingElement();
                tipologia_node=connessione_node.nextSiblingElement();
                tipologiaSwitch_node=tipologia_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(colore_node);
        componente_node.removeChild(retroilluminazione_node);
        componente_node.removeChild(connessione_node);
        componente_node.removeChild(tipologia_node);
        componente_node.removeChild(tipologiaSwitch_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* Tastiera::clone() const{
    return new Tastiera(*this);
}

void Tastiera::setAddWidget() const{
    this->getController()->createTastieraAdd();
}

void Tastiera::addComponente() const{
    this->getController()->eseguiAggiuntaTastiera();
}

void Tastiera::setSpecsWidget() const{
    this->getController()->createTastieraSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getColore(),this->getRetroilluminazione(),
                                               this->getConnessione(),this->getTipologia(),this->getTipologiaSwitch());
}

void Tastiera::clearAddWidget() const{
    this->getController()->clearTastieraAdd();
}

void Tastiera::updateConfigurazione() const{
    this->getController()->updateConfigurazioneTastiera(this->getNome(),this->getPrezzo());
}

QString Tastiera::getNomeTipoComponente() const{
    return "Tastiera";
}

QString Tastiera::getColore() const{
    return colore;
}

bool Tastiera::getRetroilluminazione() const{
    return retroilluminazione;
}

QString Tastiera::getConnessione() const{
    return connessione;
}

QString Tastiera::getTipologia() const{
    return tipologia;
}

QString Tastiera::getTipologiaSwitch() const{
    return tipologiaSwitch;
}

QString Tastiera::getType() const{
    return "Tastiera";
}
