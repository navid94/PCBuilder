#include "Mouse.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Mouse::Mouse(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller,
             const QString& input_connessione, const QString& input_tipologiaTracciamento, int input_DPIMassimi,
             const QString& input_colore, const QString& input_orientamentoDellaMano):Componente(input_nome,input_prezzo,input_produttore,input_controller),
    connessione(input_connessione),tipologiaTracciamento(input_tipologiaTracciamento),DPIMassimi(input_DPIMassimi),
    colore(input_colore),orientamentoDellaMano(input_orientamentoDellaMano){}

Mouse::Mouse(PCBuilderController* input_controller):Componente(input_controller){}

void Mouse::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode mouse_node=doc.createElement("Mouse");
        root.appendChild(mouse_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode connessione_node=doc.createElement("Connessione");
        connessione_node.appendChild(doc.createTextNode(this->getConnessione()));

        QDomNode tipologiaTracciamento_node=doc.createElement("TipologiaTracciamento");
        tipologiaTracciamento_node.appendChild(doc.createTextNode(this->getTipologiaTracciamento()));

        QDomNode DPIMassimi_node=doc.createElement("DPIMassimi");
        DPIMassimi_node.appendChild(doc.createTextNode(QString::number(this->getDPIMassimi())));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode orientamentoDellaMano_node=doc.createElement("OrientamentoDellaMano");
        orientamentoDellaMano_node.appendChild(doc.createTextNode(this->getOrientamentoDellaMano()));

        mouse_node.appendChild(nome_node);
        mouse_node.appendChild(prezzo_node);
        mouse_node.appendChild(produttore_node);
        mouse_node.appendChild(connessione_node);
        mouse_node.appendChild(tipologiaTracciamento_node);
        mouse_node.appendChild(DPIMassimi_node);
        mouse_node.appendChild(colore_node);
        mouse_node.appendChild(orientamentoDellaMano_node);

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
        QDomNode mouse_node=doc.createElement("Mouse");
        componenti_node.appendChild(mouse_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode connessione_node=doc.createElement("Connessione");
        connessione_node.appendChild(doc.createTextNode(this->getConnessione()));

        QDomNode tipologiaTracciamento_node=doc.createElement("TipologiaTracciamento");
        tipologiaTracciamento_node.appendChild(doc.createTextNode(this->getTipologiaTracciamento()));

        QDomNode DPIMassimi_node=doc.createElement("DPIMassimi");
        DPIMassimi_node.appendChild(doc.createTextNode(QString::number(this->getDPIMassimi())));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode orientamentoDellaMano_node=doc.createElement("OrientamentoDellaMano");
        orientamentoDellaMano_node.appendChild(doc.createTextNode(this->getOrientamentoDellaMano()));

        mouse_node.appendChild(nome_node);
        mouse_node.appendChild(prezzo_node);
        mouse_node.appendChild(produttore_node);
        mouse_node.appendChild(connessione_node);
        mouse_node.appendChild(tipologiaTracciamento_node);
        mouse_node.appendChild(DPIMassimi_node);
        mouse_node.appendChild(colore_node);
        mouse_node.appendChild(orientamentoDellaMano_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Mouse::deleteXMLComponente() const{
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
        QDomNode connessione_node;
        QDomNode tipologiaTracciamento_node;
        QDomNode DPIMassimi_node;
        QDomNode colore_node;
        QDomNode orientamentoDellaMano_node;

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
                connessione_node=produttore_node.nextSiblingElement();
                tipologiaTracciamento_node=connessione_node.nextSiblingElement();
                DPIMassimi_node=tipologiaTracciamento_node.nextSiblingElement();
                colore_node=DPIMassimi_node.nextSiblingElement();
                orientamentoDellaMano_node=colore_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(connessione_node);
        componente_node.removeChild(tipologiaTracciamento_node);
        componente_node.removeChild(DPIMassimi_node);
        componente_node.removeChild(colore_node);
        componente_node.removeChild(orientamentoDellaMano_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* Mouse::clone() const{
    return new Mouse(*this);
}

void Mouse::setAddWidget() const{
    this->getController()->createMouseAdd();
}

void Mouse::addComponente() const{
    this->getController()->eseguiAggiuntaMouse();
}

void Mouse::setSpecsWidget() const{
    this->getController()->createMouseSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getConnessione(),this->getTipologiaTracciamento(),
                                            this->getDPIMassimi(),this->getColore(),this->getOrientamentoDellaMano());
}

void Mouse::clearAddWidget() const{
    this->getController()->clearMouseAdd();
}

void Mouse::updateConfigurazione() const{
    this->getController()->updateConfigurazioneMouse(this->getNome(),this->getPrezzo());
}

QString Mouse::getNomeTipoComponente() const{
    return "Mouse";
}

QString Mouse::getConnessione() const{
    return connessione;
}

QString Mouse::getTipologiaTracciamento() const{
    return tipologiaTracciamento;
}

int Mouse::getDPIMassimi() const{
    return DPIMassimi;
}

QString Mouse::getColore() const{
    return colore;
}

QString Mouse::getOrientamentoDellaMano() const{
    return orientamentoDellaMano;
}

QString Mouse::getType() const{
    return "Mouse";
}
