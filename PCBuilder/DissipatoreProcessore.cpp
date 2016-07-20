#include "DissipatoreProcessore.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

DissipatoreProcessore::DissipatoreProcessore(const QString& input_nome, double input_prezzo, const QString& input_produttore,
                                             const QString& input_socketSupportati, bool input_raffreddamentoALiquido,
                                             const QString& input_rpmVentola, const QString& input_altezza, const QString& input_livelloRumore,
                                             const QString& input_altezzaRadiatore):
    Componente(input_nome, input_prezzo,input_produttore),socketSupportati(input_socketSupportati),raffreddamentoALiquido(input_raffreddamentoALiquido),
    rpmVentola(input_rpmVentola),altezza(input_altezza),livelloRumore(input_livelloRumore),altezzaRadiatore(input_altezzaRadiatore){}

void DissipatoreProcessore::saveXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode dissipatoreProcessore_node=doc.createElement("DissipatoreProcessore");
        root.appendChild(dissipatoreProcessore_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode socketSupportati_node=doc.createElement("SocketSupportati");
        socketSupportati_node.appendChild(doc.createTextNode(this->getSocketSupportati()));

        QDomNode raffreddamentoALiquido_node=doc.createElement("RaffreddamentoALiquido");
        raffreddamentoALiquido_node.appendChild(doc.createTextNode(QString::number(this->getRaffreddamentoALiquido())));

        QDomNode rpmVentola_node=doc.createElement("RpmVentola");
        rpmVentola_node.appendChild(doc.createTextNode(this->getRpmVentola()));

        QDomNode altezza_node=doc.createElement("Altezza");
        altezza_node.appendChild(doc.createTextNode(this->getAltezza()));

        QDomNode livelloRumore_node=doc.createElement("LivelloRumore");
        livelloRumore_node.appendChild(doc.createTextNode(this->getLivelloRumore()));

        QDomNode altezzaRadiatore_node=doc.createElement("AltezzaRadiatore");
        altezzaRadiatore_node.appendChild(doc.createTextNode(this->getAltezzaRadiatore()));

        dissipatoreProcessore_node.appendChild(nome_node);
        dissipatoreProcessore_node.appendChild(prezzo_node);
        dissipatoreProcessore_node.appendChild(produttore_node);
        dissipatoreProcessore_node.appendChild(socketSupportati_node);
        dissipatoreProcessore_node.appendChild(raffreddamentoALiquido_node);
        dissipatoreProcessore_node.appendChild(rpmVentola_node);
        dissipatoreProcessore_node.appendChild(altezza_node);
        dissipatoreProcessore_node.appendChild(livelloRumore_node);
        dissipatoreProcessore_node.appendChild(altezzaRadiatore_node);

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
        QDomNode dissipatoreProcessore_node=doc.createElement("DissipatoreProcessore");
        componenti_node.appendChild(dissipatoreProcessore_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode socketSupportati_node=doc.createElement("SocketSupportati");
        socketSupportati_node.appendChild(doc.createTextNode(this->getSocketSupportati()));

        QDomNode raffreddamentoALiquido_node=doc.createElement("RaffreddamentoALiquido");
        raffreddamentoALiquido_node.appendChild(doc.createTextNode(QString::number(this->getRaffreddamentoALiquido())));

        QDomNode rpmVentola_node=doc.createElement("RpmVentola");
        rpmVentola_node.appendChild(doc.createTextNode(this->getRpmVentola()));

        QDomNode altezza_node=doc.createElement("Altezza");
        altezza_node.appendChild(doc.createTextNode(this->getAltezza()));

        QDomNode livelloRumore_node=doc.createElement("LivelloRumore");
        livelloRumore_node.appendChild(doc.createTextNode(this->getLivelloRumore()));

        QDomNode altezzaRadiatore_node=doc.createElement("AltezzaRadiatore");
        altezzaRadiatore_node.appendChild(doc.createTextNode(this->getAltezzaRadiatore()));

        dissipatoreProcessore_node.appendChild(nome_node);
        dissipatoreProcessore_node.appendChild(prezzo_node);
        dissipatoreProcessore_node.appendChild(produttore_node);
        dissipatoreProcessore_node.appendChild(socketSupportati_node);
        dissipatoreProcessore_node.appendChild(raffreddamentoALiquido_node);
        dissipatoreProcessore_node.appendChild(rpmVentola_node);
        dissipatoreProcessore_node.appendChild(altezza_node);
        dissipatoreProcessore_node.appendChild(livelloRumore_node);
        dissipatoreProcessore_node.appendChild(altezzaRadiatore_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void DissipatoreProcessore::deleteXMLComponente(){
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
        QDomNode socketSupportati_node;
        QDomNode raffreddamentoALiquido_node;
        QDomNode rpmVentola_node;
        QDomNode altezza_node;
        QDomNode livelloRumore_node;
        QDomNode altezzaRadiatore_node;

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
                socketSupportati_node=produttore_node.nextSiblingElement();
                raffreddamentoALiquido_node=socketSupportati_node.nextSiblingElement();
                rpmVentola_node=raffreddamentoALiquido_node.nextSiblingElement();
                altezza_node=rpmVentola_node.nextSiblingElement();
                livelloRumore_node=altezza_node.nextSiblingElement();
                altezzaRadiatore_node=livelloRumore_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(socketSupportati_node);
        componente_node.removeChild(raffreddamentoALiquido_node);
        componente_node.removeChild(rpmVentola_node);
        componente_node.removeChild(altezza_node);
        componente_node.removeChild(livelloRumore_node);
        componente_node.removeChild(altezzaRadiatore_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

QString DissipatoreProcessore::getSocketSupportati() const{
    return socketSupportati;
}

bool DissipatoreProcessore::getRaffreddamentoALiquido() const{
    return raffreddamentoALiquido;
}

QString DissipatoreProcessore::getRpmVentola() const{
    return rpmVentola;
}

QString DissipatoreProcessore::getAltezza() const{
    return altezza;
}

QString DissipatoreProcessore::getLivelloRumore() const{
    return livelloRumore;
}

QString DissipatoreProcessore::getAltezzaRadiatore() const{
    return altezzaRadiatore;
}

QString DissipatoreProcessore::getType() const{
    return "DissipatoreProcessore";
}
