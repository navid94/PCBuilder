#include "Processore.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Processore::Processore(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller,
                       const QString& input_socket, const QString& input_larghezzaDati, const QString& input_frequenzaOperativa,
                       const QString& input_frequenzaTurbo, int input_numeroCore, const QString& input_l1Cache,
                       const QString& input_l2Cache, const QString& input_l3Cache, const QString& input_litografia,
                       const QString& input_tdp, bool input_includeDissipatore, bool input_hyperThreading
                       , const QString& input_graficaIntegrata):Componente(input_nome,input_prezzo,input_produttore, input_controller),socket(input_socket),
    larghezzaDati(input_larghezzaDati),frequenzaOperativa(input_frequenzaOperativa),frequenzaTurbo(input_frequenzaTurbo),
    numeroCore(input_numeroCore),l1Cache(input_l1Cache),l2Cache(input_l2Cache),l3Cache(input_l3Cache),litografia(input_litografia),
    tdp(input_tdp),includeDissipatore(input_includeDissipatore),hyperThreading(input_hyperThreading),graficaIntegrata(input_graficaIntegrata){}

Processore::Processore(PCBuilderController* input_controller):Componente(input_controller){}

void Processore::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode processore_node=doc.createElement("Processore");
        root.appendChild(processore_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode socket_node=doc.createElement("Socket");
        socket_node.appendChild(doc.createTextNode(this->getSocket()));

        QDomNode larghezzaDati_node=doc.createElement("LarghezzaDati");
        larghezzaDati_node.appendChild(doc.createTextNode(this->getLarghezzaDati()));

        QDomNode frequenzaOperativa_node=doc.createElement("FrequenzaOperativa");
        frequenzaOperativa_node.appendChild(doc.createTextNode(this->getFrequenzaOperativa()));

        QDomNode frequenzaTurbo_node=doc.createElement("FrequenzaTurbo");
        frequenzaTurbo_node.appendChild(doc.createTextNode(this->getFrequenzaTurbo()));

        QDomNode numeroCore_node=doc.createElement("NumeroCore");
        numeroCore_node.appendChild(doc.createTextNode(QString::number(this->getNumeroCore())));

        QDomNode l1Cache_node=doc.createElement("L1Cache");
        l1Cache_node.appendChild(doc.createTextNode(this->getL1Cache()));

        QDomNode l2Cache_node=doc.createElement("L2Cache");
        l2Cache_node.appendChild(doc.createTextNode(this->getL2Cache()));

        QDomNode l3Cache_node=doc.createElement("L3Cache");
        l3Cache_node.appendChild(doc.createTextNode(this->getL3Cache()));

        QDomNode litografia_node=doc.createElement("Litografia");
        litografia_node.appendChild(doc.createTextNode(this->getLitografia()));

        QDomNode tdp_node=doc.createElement("Tdp");
        tdp_node.appendChild(doc.createTextNode(this->getTdp()));

        QDomNode includeDissipatore_node=doc.createElement("IncludeDissipatore");
        includeDissipatore_node.appendChild(doc.createTextNode(QString::number(this->getIncludeDissipatore())));

        QDomNode hyperThreading_node=doc.createElement("HyperThreading");
        hyperThreading_node.appendChild(doc.createTextNode(QString::number(this->getHyperThreading())));

        QDomNode graficaIntegrata_node=doc.createElement("GraficaIntegrata");
        graficaIntegrata_node.appendChild(doc.createTextNode(this->getGraficaIntegrata()));

        processore_node.appendChild(nome_node);
        processore_node.appendChild(prezzo_node);
        processore_node.appendChild(produttore_node);
        processore_node.appendChild(socket_node);
        processore_node.appendChild(larghezzaDati_node);
        processore_node.appendChild(frequenzaOperativa_node);
        processore_node.appendChild(frequenzaTurbo_node);
        processore_node.appendChild(numeroCore_node);
        processore_node.appendChild(l1Cache_node);
        processore_node.appendChild(l2Cache_node);
        processore_node.appendChild(l3Cache_node);
        processore_node.appendChild(litografia_node);
        processore_node.appendChild(tdp_node);
        processore_node.appendChild(includeDissipatore_node);
        processore_node.appendChild(hyperThreading_node);
        processore_node.appendChild(graficaIntegrata_node);

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
        QDomNode processore_node=doc.createElement("Processore");
        componenti_node.appendChild(processore_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode socket_node=doc.createElement("Socket");
        socket_node.appendChild(doc.createTextNode(this->getSocket()));

        QDomNode larghezzaDati_node=doc.createElement("LarghezzaDati");
        larghezzaDati_node.appendChild(doc.createTextNode(this->getLarghezzaDati()));

        QDomNode frequenzaOperativa_node=doc.createElement("FrequenzaOperativa");
        frequenzaOperativa_node.appendChild(doc.createTextNode(this->getFrequenzaOperativa()));

        QDomNode frequenzaTurbo_node=doc.createElement("FrequenzaTurbo");
        frequenzaTurbo_node.appendChild(doc.createTextNode(this->getFrequenzaTurbo()));

        QDomNode numeroCore_node=doc.createElement("NumeroCore");
        numeroCore_node.appendChild(doc.createTextNode(QString::number(this->getNumeroCore())));

        QDomNode l1Cache_node=doc.createElement("L1Cache");
        l1Cache_node.appendChild(doc.createTextNode(this->getL1Cache()));

        QDomNode l2Cache_node=doc.createElement("L2Cache");
        l2Cache_node.appendChild(doc.createTextNode(this->getL2Cache()));

        QDomNode l3Cache_node=doc.createElement("L3Cache");
        l3Cache_node.appendChild(doc.createTextNode(this->getL3Cache()));

        QDomNode litografia_node=doc.createElement("Litografia");
        litografia_node.appendChild(doc.createTextNode(this->getLitografia()));

        QDomNode tdp_node=doc.createElement("Tdp");
        tdp_node.appendChild(doc.createTextNode(this->getTdp()));

        QDomNode includeDissipatore_node=doc.createElement("IncludeDissipatore");
        includeDissipatore_node.appendChild(doc.createTextNode(QString::number(this->getIncludeDissipatore())));

        QDomNode hyperThreading_node=doc.createElement("HyperThreading");
        hyperThreading_node.appendChild(doc.createTextNode(QString::number(this->getHyperThreading())));

        QDomNode graficaIntegrata_node=doc.createElement("GraficaIntegrata");
        graficaIntegrata_node.appendChild(doc.createTextNode(this->getGraficaIntegrata()));

        processore_node.appendChild(nome_node);
        processore_node.appendChild(prezzo_node);
        processore_node.appendChild(produttore_node);
        processore_node.appendChild(socket_node);
        processore_node.appendChild(larghezzaDati_node);
        processore_node.appendChild(frequenzaOperativa_node);
        processore_node.appendChild(frequenzaTurbo_node);
        processore_node.appendChild(numeroCore_node);
        processore_node.appendChild(l1Cache_node);
        processore_node.appendChild(l2Cache_node);
        processore_node.appendChild(l3Cache_node);
        processore_node.appendChild(litografia_node);
        processore_node.appendChild(tdp_node);
        processore_node.appendChild(includeDissipatore_node);
        processore_node.appendChild(hyperThreading_node);
        processore_node.appendChild(graficaIntegrata_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Processore::deleteXMLComponente() const{
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
        QDomNode socket_node;
        QDomNode larghezzaDati_node;
        QDomNode frequenzaOperativa_node;
        QDomNode frequenzaTurbo_node;
        QDomNode numeroCore_node;
        QDomNode l1Cache_node;
        QDomNode l2Cache_node;
        QDomNode l3Cache_node;
        QDomNode litografia_node;
        QDomNode tdp_node;
        QDomNode includeDissipatore_node;
        QDomNode hyperThreading_node;
        QDomNode graficaIntegrata_node;

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
                socket_node=produttore_node.nextSiblingElement();
                larghezzaDati_node=socket_node.nextSiblingElement();
                frequenzaOperativa_node=larghezzaDati_node.nextSiblingElement();
                frequenzaTurbo_node=frequenzaOperativa_node.nextSiblingElement();
                numeroCore_node=frequenzaTurbo_node.nextSiblingElement();
                l1Cache_node=numeroCore_node.nextSiblingElement();
                l2Cache_node=l1Cache_node.nextSiblingElement();
                l3Cache_node=l2Cache_node.nextSiblingElement();
                litografia_node=l3Cache_node.nextSiblingElement();
                tdp_node=litografia_node.nextSiblingElement();
                includeDissipatore_node=tdp_node.nextSiblingElement();
                hyperThreading_node=includeDissipatore_node.nextSiblingElement();
                graficaIntegrata_node=hyperThreading_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(socket_node);
        componente_node.removeChild(larghezzaDati_node);
        componente_node.removeChild(frequenzaOperativa_node);
        componente_node.removeChild(frequenzaTurbo_node);
        componente_node.removeChild(numeroCore_node);
        componente_node.removeChild(l1Cache_node);
        componente_node.removeChild(l2Cache_node);
        componente_node.removeChild(l3Cache_node);
        componente_node.removeChild(litografia_node);
        componente_node.removeChild(tdp_node);
        componente_node.removeChild(includeDissipatore_node);
        componente_node.removeChild(hyperThreading_node);
        componente_node.removeChild(graficaIntegrata_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* Processore::clone() const{
    return new Processore(*this);
}

void Processore::setAddWidget() const{
    this->getController()->createProcessoreAdd();
}

void Processore::addComponente() const{
    this->getController()->eseguiAggiuntaProcessore();
}

void Processore::setSpecsWidget() const{
    this->getController()->createProcessoreSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getSocket(),this->getLarghezzaDati(),
                                                 this->getFrequenzaOperativa(),this->getFrequenzaTurbo(),this->getNumeroCore(),this->getL1Cache(),this->getL2Cache(),
                                                 this->getL3Cache(),this->getLitografia(),this->getTdp(),this->getIncludeDissipatore(),this->getHyperThreading(),this->getGraficaIntegrata());
}

void Processore::clearAddWidget() const{
    this->getController()->clearProcessoreAdd();
}

void Processore::updateConfigurazione() const{
    this->getController()->updateConfigurazioneProcessore(this->getNome(),this->getPrezzo());
}

QString Processore::getNomeTipoComponente() const{
    return "Processore";
}

QString Processore::getSocket() const{
    return socket;
}

QString Processore::getLarghezzaDati() const{
    return larghezzaDati;
}

QString Processore::getFrequenzaOperativa() const{
    return frequenzaOperativa;
}

QString Processore::getFrequenzaTurbo() const{
    return frequenzaTurbo;
}

int Processore::getNumeroCore() const{
    return numeroCore;
}

QString Processore::getL1Cache() const{
    return l1Cache;
}

QString Processore::getL2Cache() const{
    return l2Cache;
}

QString Processore::getL3Cache() const{
    return l3Cache;
}

QString Processore::getLitografia() const{
    return litografia;
}

QString Processore::getTdp() const{
    return tdp;
}

bool Processore::getIncludeDissipatore() const{
    return includeDissipatore;
}

bool Processore::getHyperThreading() const{
    return hyperThreading;
}

QString Processore::getGraficaIntegrata() const{
    return graficaIntegrata;
}

QString Processore::getType() const{
    return "Processore";
}
