#include "SchedaGrafica.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

SchedaGrafica::SchedaGrafica(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller,
                             const QString& input_interfaccia, const QString& input_chipset, const QString& input_memoria
                             , const QString& input_tipologiaMemoria, const QString& input_frequenzaCore, const QString& input_tdp
                             , const QString& input_supportoSLI, const QString& input_supportoCrossfire, const QString& input_lunghezza):
    Componente(input_nome,input_prezzo,input_produttore, input_controller), interfaccia(input_interfaccia), chipset(input_chipset), memoria(input_memoria),
    tipologiaMemoria(input_tipologiaMemoria),frequenzaCore(input_frequenzaCore), tdp(input_tdp), supportoSLI(input_supportoSLI), supportoCrossfire(input_supportoCrossfire), lunghezza(input_lunghezza){}

SchedaGrafica::SchedaGrafica(PCBuilderController* input_controller):Componente(input_controller){}

void SchedaGrafica::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode schedaGrafica_node=doc.createElement("SchedaGrafica");
        root.appendChild(schedaGrafica_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode interfaccia_node=doc.createElement("Interfaccia");
        interfaccia_node.appendChild(doc.createTextNode(this->getInterfaccia()));

        QDomNode chipset_node=doc.createElement("Chipset");
        chipset_node.appendChild(doc.createTextNode(this->getChipset()));

        QDomNode memoria_node=doc.createElement("Memoria");
        memoria_node.appendChild(doc.createTextNode(this->getMemoria()));

        QDomNode tipologiaMemoria_node=doc.createElement("TipologiaMemoria");
        tipologiaMemoria_node.appendChild(doc.createTextNode(this->getTipologiaMemoria()));

        QDomNode frequenzaCore_node=doc.createElement("FrequenzaCore");
        frequenzaCore_node.appendChild(doc.createTextNode(this->getFrequenzaCore()));

        QDomNode tdp_node=doc.createElement("Tdp");
        tdp_node.appendChild(doc.createTextNode(this->getTdp()));

        QDomNode supportoSLI_node=doc.createElement("SupportoSLI");
        supportoSLI_node.appendChild(doc.createTextNode(this->getSupportoSLI()));

        QDomNode supportoCrossfire_node=doc.createElement("SupportoCrossfire");
        supportoCrossfire_node.appendChild(doc.createTextNode(this->getSupportoCrossfire()));

        QDomNode lunghezza_node=doc.createElement("Lunghezza");
        lunghezza_node.appendChild(doc.createTextNode(this->getLunghezza()));

        schedaGrafica_node.appendChild(nome_node);
        schedaGrafica_node.appendChild(prezzo_node);
        schedaGrafica_node.appendChild(produttore_node);
        schedaGrafica_node.appendChild(interfaccia_node);
        schedaGrafica_node.appendChild(chipset_node);
        schedaGrafica_node.appendChild(memoria_node);
        schedaGrafica_node.appendChild(tipologiaMemoria_node);
        schedaGrafica_node.appendChild(frequenzaCore_node);
        schedaGrafica_node.appendChild(tdp_node);
        schedaGrafica_node.appendChild(supportoSLI_node);
        schedaGrafica_node.appendChild(supportoCrossfire_node);
        schedaGrafica_node.appendChild(lunghezza_node);

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
        QDomNode schedaGrafica_node=doc.createElement("SchedaGrafica");
        componenti_node.appendChild(schedaGrafica_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode interfaccia_node=doc.createElement("Interfaccia");
        interfaccia_node.appendChild(doc.createTextNode(this->getInterfaccia()));

        QDomNode chipset_node=doc.createElement("Chipset");
        chipset_node.appendChild(doc.createTextNode(this->getChipset()));

        QDomNode memoria_node=doc.createElement("Memoria");
        memoria_node.appendChild(doc.createTextNode(this->getMemoria()));

        QDomNode tipologiaMemoria_node=doc.createElement("TipologiaMemoria");
        tipologiaMemoria_node.appendChild(doc.createTextNode(this->getTipologiaMemoria()));

        QDomNode frequenzaCore_node=doc.createElement("FrequenzaCore");
        frequenzaCore_node.appendChild(doc.createTextNode(this->getFrequenzaCore()));

        QDomNode tdp_node=doc.createElement("Tdp");
        tdp_node.appendChild(doc.createTextNode(this->getTdp()));

        QDomNode supportoSLI_node=doc.createElement("SupportoSLI");
        supportoSLI_node.appendChild(doc.createTextNode(this->getSupportoSLI()));

        QDomNode supportoCrossfire_node=doc.createElement("SupportoCrossfire");
        supportoCrossfire_node.appendChild(doc.createTextNode(this->getSupportoCrossfire()));

        QDomNode lunghezza_node=doc.createElement("Lunghezza");
        lunghezza_node.appendChild(doc.createTextNode(this->getLunghezza()));

        schedaGrafica_node.appendChild(nome_node);
        schedaGrafica_node.appendChild(prezzo_node);
        schedaGrafica_node.appendChild(produttore_node);
        schedaGrafica_node.appendChild(interfaccia_node);
        schedaGrafica_node.appendChild(chipset_node);
        schedaGrafica_node.appendChild(memoria_node);
        schedaGrafica_node.appendChild(tipologiaMemoria_node);
        schedaGrafica_node.appendChild(frequenzaCore_node);
        schedaGrafica_node.appendChild(tdp_node);
        schedaGrafica_node.appendChild(supportoSLI_node);
        schedaGrafica_node.appendChild(supportoCrossfire_node);
        schedaGrafica_node.appendChild(lunghezza_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void SchedaGrafica::deleteXMLComponente() const{
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
        QDomNode interfaccia_node;
        QDomNode chipset_node;
        QDomNode memoria_node;
        QDomNode tipologiaMemoria_node;
        QDomNode frequenzaCore_node;
        QDomNode tdp_node;
        QDomNode supportoSLI_node;
        QDomNode supportoCrossfire_node;
        QDomNode lunghezza_node;

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
                interfaccia_node=produttore_node.nextSiblingElement();
                chipset_node=interfaccia_node.nextSiblingElement();
                memoria_node=chipset_node.nextSiblingElement();
                tipologiaMemoria_node=memoria_node.nextSiblingElement();
                frequenzaCore_node=tipologiaMemoria_node.nextSiblingElement();
                tdp_node=frequenzaCore_node.nextSiblingElement();
                supportoSLI_node=tdp_node.nextSiblingElement();
                supportoCrossfire_node=supportoSLI_node.nextSiblingElement();
                lunghezza_node=supportoCrossfire_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(interfaccia_node);
        componente_node.removeChild(chipset_node);
        componente_node.removeChild(memoria_node);
        componente_node.removeChild(tipologiaMemoria_node);
        componente_node.removeChild(frequenzaCore_node);
        componente_node.removeChild(tdp_node);
        componente_node.removeChild(supportoSLI_node);
        componente_node.removeChild(supportoCrossfire_node);
        componente_node.removeChild(lunghezza_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* SchedaGrafica::clone() const{
    return new SchedaGrafica(*this);
}

void SchedaGrafica::setAddWidget() const{
    this->getController()->createSchedaGraficaAdd();
}

void SchedaGrafica::addComponente() const{
    this->getController()->eseguiAggiuntaSchedaGrafica();
}

void SchedaGrafica::setSpecsWidget() const{
    this->getController()->createSchedaGraficaSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getInterfaccia(),this->getChipset(),
                                                    this->getMemoria(),this->getTipologiaMemoria(),this->getFrequenzaCore(),this->getTdp(),
                                                    this->getSupportoSLI(),this->getSupportoCrossfire(),this->getLunghezza());
}

void SchedaGrafica::clearAddWidget() const{
    this->getController()->clearSchedaGraficaAdd();
}

void SchedaGrafica::updateConfigurazione() const{
    this->getController()->updateConfigurazioneSchedaGrafica(this->getNome(),this->getPrezzo());
}

QString SchedaGrafica::getNomeTipoComponente() const{
    return "Scheda grafica";
}

QString SchedaGrafica::getInterfaccia() const{
    return interfaccia;
}

QString SchedaGrafica::getChipset() const{
    return chipset;
}

QString SchedaGrafica::getMemoria() const{
    return memoria;
}

QString SchedaGrafica::getTipologiaMemoria() const{
    return tipologiaMemoria;
}

QString SchedaGrafica::getFrequenzaCore() const{
    return frequenzaCore;
}

QString SchedaGrafica::getTdp() const{
    return tdp;
}

QString SchedaGrafica::getSupportoSLI() const{
    return supportoSLI;
}

QString SchedaGrafica::getSupportoCrossfire() const{
    return supportoCrossfire;
}

QString SchedaGrafica::getLunghezza() const{
    return lunghezza;
}

QString SchedaGrafica::getType() const{
    return "SchedaGrafica";
}
