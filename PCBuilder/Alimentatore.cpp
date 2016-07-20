#include "Alimentatore.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Alimentatore::Alimentatore(const QString& input_nome, double input_prezzo,
                           const QString& input_produttore, const QString& input_tipologia,
                           const QString& input_wattaggio, const QString& input_modulare,
                           const QString& input_cerfificazioneEfficienza, double input_efficienza):
    Componente(input_nome,input_prezzo,input_produttore),tipologia(input_tipologia),
    wattaggio(input_wattaggio),modulare(input_modulare),certificazioneEfficienza(input_cerfificazioneEfficienza),
    efficienza(input_efficienza){}

void Alimentatore::saveXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode alimentatore_node=doc.createElement("Alimentatore");
        root.appendChild(alimentatore_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode wattaggio_node=doc.createElement("Wattaggio");
        wattaggio_node.appendChild(doc.createTextNode(this->getWattaggio()));

        QDomNode modulare_node=doc.createElement("Modulare");
        modulare_node.appendChild(doc.createTextNode(this->getModulare()));

        QDomNode certificazioneEfficienza_node=doc.createElement("CertificazioneEfficienza");
        certificazioneEfficienza_node.appendChild(doc.createTextNode(this->getCertificazioneEfficienza()));

        QDomNode efficienza_node=doc.createElement("Efficienza");
        efficienza_node.appendChild(doc.createTextNode(QString::number(this->getEfficienza())));

        alimentatore_node.appendChild(nome_node);
        alimentatore_node.appendChild(prezzo_node);
        alimentatore_node.appendChild(produttore_node);
        alimentatore_node.appendChild(tipologia_node);
        alimentatore_node.appendChild(wattaggio_node);
        alimentatore_node.appendChild(modulare_node);
        alimentatore_node.appendChild(certificazioneEfficienza_node);
        alimentatore_node.appendChild(efficienza_node);

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
        QDomNode alimentatore_node=doc.createElement("Alimentatore");
        componenti_node.appendChild(alimentatore_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode wattaggio_node=doc.createElement("Wattaggio");
        wattaggio_node.appendChild(doc.createTextNode(this->getWattaggio()));

        QDomNode modulare_node=doc.createElement("Modulare");
        modulare_node.appendChild(doc.createTextNode(this->getModulare()));

        QDomNode certificazioneEfficienza_node=doc.createElement("CertificazioneEfficienza");
        certificazioneEfficienza_node.appendChild(doc.createTextNode(this->getCertificazioneEfficienza()));

        QDomNode efficienza_node=doc.createElement("Efficienza");
        efficienza_node.appendChild(doc.createTextNode(QString::number(this->getEfficienza())));

        alimentatore_node.appendChild(nome_node);
        alimentatore_node.appendChild(prezzo_node);
        alimentatore_node.appendChild(produttore_node);
        alimentatore_node.appendChild(tipologia_node);
        alimentatore_node.appendChild(wattaggio_node);
        alimentatore_node.appendChild(modulare_node);
        alimentatore_node.appendChild(certificazioneEfficienza_node);
        alimentatore_node.appendChild(efficienza_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Alimentatore::deleteXMLComponente(){
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
        QDomNode wattaggio_node;
        QDomNode modulare_node;
        QDomNode certificazioneEfficienza_node;
        QDomNode efficienza_node;

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
                wattaggio_node=tipologia_node.nextSiblingElement();
                modulare_node=wattaggio_node.nextSiblingElement();
                certificazioneEfficienza_node=modulare_node.nextSiblingElement();
                efficienza_node=certificazioneEfficienza_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(tipologia_node);
        componente_node.removeChild(wattaggio_node);
        componente_node.removeChild(modulare_node);
        componente_node.removeChild(certificazioneEfficienza_node);
        componente_node.removeChild(efficienza_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

QString Alimentatore::getTipologia() const{
    return tipologia;
}

QString Alimentatore::getWattaggio() const{
    return wattaggio;
}

QString Alimentatore::getModulare() const{
    return modulare;
}

QString Alimentatore::getCertificazioneEfficienza() const{
    return certificazioneEfficienza;
}

double Alimentatore::getEfficienza() const{
    return efficienza;
}

QString Alimentatore::getType() const{
    return "Alimentatore";
}
