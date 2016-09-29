#include "Archiviazione.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Archiviazione::Archiviazione(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller, const QString& input_tipologia,
                             const QString& input_capacita, const QString& input_interfaccia, const QString& input_cache,
                             const QString& input_fattoreDiForma, const QString& input_rpm):Componente(input_nome,input_prezzo,input_produttore,input_controller),
    tipologia(input_tipologia),capacita(input_capacita),interfaccia(input_interfaccia),
    cache(input_cache),fattoreDiForma(input_fattoreDiForma),rpm(input_rpm){}

Archiviazione::Archiviazione(PCBuilderController* input_controller):Componente(input_controller){}

void Archiviazione::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode archiviazione_node=doc.createElement("Archiviazione");
        root.appendChild(archiviazione_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode capacita_node=doc.createElement("Capacita");
        capacita_node.appendChild(doc.createTextNode(this->getCapacita()));

        QDomNode interfaccia_node=doc.createElement("Interfaccia");
        interfaccia_node.appendChild(doc.createTextNode(this->getInterfaccia()));

        QDomNode cache_node=doc.createElement("Cache");
        cache_node.appendChild(doc.createTextNode(this->getCache()));

        QDomNode fattoreDiForma_node=doc.createElement("FattoreDiForma");
        fattoreDiForma_node.appendChild(doc.createTextNode(this->getFattoreDiForma()));

        QDomNode rpm_node=doc.createElement("Rpm");
        rpm_node.appendChild(doc.createTextNode(this->getRpm()));

        archiviazione_node.appendChild(nome_node);
        archiviazione_node.appendChild(prezzo_node);
        archiviazione_node.appendChild(produttore_node);
        archiviazione_node.appendChild(tipologia_node);
        archiviazione_node.appendChild(capacita_node);
        archiviazione_node.appendChild(interfaccia_node);
        archiviazione_node.appendChild(cache_node);
        archiviazione_node.appendChild(fattoreDiForma_node);
        archiviazione_node.appendChild(rpm_node);

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
        QDomNode archiviazione_node=doc.createElement("Archiviazione");
        componenti_node.appendChild(archiviazione_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode capacita_node=doc.createElement("Capacita");
        capacita_node.appendChild(doc.createTextNode(this->getCapacita()));

        QDomNode interfaccia_node=doc.createElement("Interfaccia");
        interfaccia_node.appendChild(doc.createTextNode(this->getInterfaccia()));

        QDomNode cache_node=doc.createElement("Cache");
        cache_node.appendChild(doc.createTextNode(this->getCache()));

        QDomNode fattoreDiForma_node=doc.createElement("FattoreDiForma");
        fattoreDiForma_node.appendChild(doc.createTextNode(this->getFattoreDiForma()));

        QDomNode rpm_node=doc.createElement("Rpm");
        rpm_node.appendChild(doc.createTextNode(this->getRpm()));

        archiviazione_node.appendChild(nome_node);
        archiviazione_node.appendChild(prezzo_node);
        archiviazione_node.appendChild(produttore_node);
        archiviazione_node.appendChild(tipologia_node);
        archiviazione_node.appendChild(capacita_node);
        archiviazione_node.appendChild(interfaccia_node);
        archiviazione_node.appendChild(cache_node);
        archiviazione_node.appendChild(fattoreDiForma_node);
        archiviazione_node.appendChild(rpm_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Archiviazione::deleteXMLComponente() const{
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
        QDomNode capacita_node;
        QDomNode interfaccia_node;
        QDomNode cache_node;
        QDomNode fattoreDiForma_node;
        QDomNode rpm_node;

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
                capacita_node=tipologia_node.nextSiblingElement();
                interfaccia_node=capacita_node.nextSiblingElement();
                cache_node=interfaccia_node.nextSiblingElement();
                fattoreDiForma_node=cache_node.nextSiblingElement();
                rpm_node=fattoreDiForma_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(tipologia_node);
        componente_node.removeChild(capacita_node);
        componente_node.removeChild(interfaccia_node);
        componente_node.removeChild(cache_node);
        componente_node.removeChild(fattoreDiForma_node);
        componente_node.removeChild(rpm_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* Archiviazione::clone() const{
    return new Archiviazione(*this);
}

void Archiviazione::setAddWidget() const{
    this->getController()->createArchiviazioneAdd();
}

void Archiviazione::addComponente() const{
    this->getController()->eseguiAggiuntaArchiviazione();
}

void Archiviazione::setSpecsWidget() const{
    this->getController()->createArchiviazioneSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getTipologia(),this->getCapacita(),
                                                    this->getInterfaccia(),this->getCache(),this->getFattoreDiForma(),this->getRpm());
}

void Archiviazione::updateConfigurazione() const{
    this->getController()->updateConfigurazioneArchiviazione(this->getNome(),this->getPrezzo());
}

void Archiviazione::clearAddWidget() const{
    this->getController()->clearArchiviazioneAdd();
}

QString Archiviazione::getNomeTipoComponente() const{
    return "Archiviazione";
}

QString Archiviazione::getTipologia() const{
    return tipologia;
}

QString Archiviazione::getCapacita() const{
    return capacita;
}

QString Archiviazione::getInterfaccia() const{
    return interfaccia;
}

QString Archiviazione::getCache() const{
    return cache;
}

QString Archiviazione::getFattoreDiForma() const{
    return fattoreDiForma;
}

QString Archiviazione::getRpm() const{
    return rpm;
}

QString Archiviazione::getType() const{
    return "Archiviazione";
}
