#include "SistemaOperativo.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

SistemaOperativo::SistemaOperativo(const QString& input_nome, double input_prezzo, const QString& input_produttore,
                                   const QString& input_modalita, const QString& input_memoriaMassimaSupportata):
    Componente(input_nome,input_prezzo,input_produttore),modalita(input_modalita),memoriaMassimaSupportata(input_memoriaMassimaSupportata){}

void SistemaOperativo::saveXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode sistemaOperativo_node=doc.createElement("SistemaOperarivo");
        root.appendChild(sistemaOperativo_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode modalita_node=doc.createElement("Modalita");
        modalita_node.appendChild(doc.createTextNode(this->getModalita()));

        QDomNode memoriaMassimaSupportata_node=doc.createElement("MemoriaMassimaSupportata");
        memoriaMassimaSupportata_node.appendChild(doc.createTextNode(this->getMemoriaMassimaSupportata()));



        sistemaOperativo_node.appendChild(nome_node);
        sistemaOperativo_node.appendChild(prezzo_node);
        sistemaOperativo_node.appendChild(produttore_node);
        sistemaOperativo_node.appendChild(modalita_node);
        sistemaOperativo_node.appendChild(memoriaMassimaSupportata_node);

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
        QDomNode sistemaOperativo_node=doc.createElement("SistemaOperativo");
        componenti_node.appendChild(sistemaOperativo_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode modalita_node=doc.createElement("Modalita");
        modalita_node.appendChild(doc.createTextNode(this->getModalita()));

        QDomNode memoriaMassimaSupportata_node=doc.createElement("MemoriaMassimaSupportata");
        memoriaMassimaSupportata_node.appendChild(doc.createTextNode(this->getMemoriaMassimaSupportata()));


        sistemaOperativo_node.appendChild(nome_node);
        sistemaOperativo_node.appendChild(prezzo_node);
        sistemaOperativo_node.appendChild(produttore_node);
        sistemaOperativo_node.appendChild(modalita_node);
        sistemaOperativo_node.appendChild(memoriaMassimaSupportata_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void SistemaOperativo::deleteXMLComponente(){
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
        QDomNode modalita_node;
        QDomNode memoriaMassimaSupportata_node;

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
                modalita_node=produttore_node.nextSiblingElement();
                memoriaMassimaSupportata_node=modalita_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(modalita_node);
        componente_node.removeChild(memoriaMassimaSupportata_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

QString SistemaOperativo::getModalita() const{
    return modalita;
}

QString SistemaOperativo::getMemoriaMassimaSupportata() const{
    return memoriaMassimaSupportata;
}

QString SistemaOperativo::getType() const{
    return "SistemaOperativo";
}
