#include "UnitaOttica.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

UnitaOttica::UnitaOttica(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller,
                         const QString& input_fattoreDiForma, const QString& input_interfaccia,
                         const QString& input_cache, const QString& input_velocita):Componente(input_nome,input_prezzo,input_produttore,input_controller),
    fattoreDiForma(input_fattoreDiForma),interfaccia(input_interfaccia),cache(input_cache),velocita(input_velocita){}

UnitaOttica::UnitaOttica(PCBuilderController* input_controller):Componente(input_controller){}

void UnitaOttica::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode unitaOttica_node=doc.createElement("UnitaOttica");
        root.appendChild(unitaOttica_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode fattoreDiForma_node=doc.createElement("FattoreDiForma");
        fattoreDiForma_node.appendChild(doc.createTextNode(this->getFattoreDiForma()));

        QDomNode interfaccia_node=doc.createElement("Interfaccia");
        interfaccia_node.appendChild(doc.createTextNode(this->getInterfaccia()));

        QDomNode cache_node=doc.createElement("Cache");
        cache_node.appendChild(doc.createTextNode(this->getCache()));

        QDomNode velocita_node=doc.createElement("Velocita");
        velocita_node.appendChild(doc.createTextNode(this->getVelocita()));


        unitaOttica_node.appendChild(nome_node);
        unitaOttica_node.appendChild(prezzo_node);
        unitaOttica_node.appendChild(produttore_node);
        unitaOttica_node.appendChild(fattoreDiForma_node);
        unitaOttica_node.appendChild(interfaccia_node);
        unitaOttica_node.appendChild(cache_node);
        unitaOttica_node.appendChild(velocita_node);

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
        QDomNode unitaOttica_node=doc.createElement("UnitaOttica");
        componenti_node.appendChild(unitaOttica_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode fattoreDiForma_node=doc.createElement("FattoreDiForma");
        fattoreDiForma_node.appendChild(doc.createTextNode(this->getFattoreDiForma()));

        QDomNode interfaccia_node=doc.createElement("Interfaccia");
        interfaccia_node.appendChild(doc.createTextNode(this->getInterfaccia()));

        QDomNode cache_node=doc.createElement("Cache");
        cache_node.appendChild(doc.createTextNode(this->getCache()));

        QDomNode velocita_node=doc.createElement("Velocita");
        velocita_node.appendChild(doc.createTextNode(this->getVelocita()));


        unitaOttica_node.appendChild(nome_node);
        unitaOttica_node.appendChild(prezzo_node);
        unitaOttica_node.appendChild(produttore_node);
        unitaOttica_node.appendChild(fattoreDiForma_node);
        unitaOttica_node.appendChild(interfaccia_node);
        unitaOttica_node.appendChild(cache_node);
        unitaOttica_node.appendChild(velocita_node);


        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void UnitaOttica::deleteXMLComponente() const{
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
        QDomNode fattoreDiForma_node;
        QDomNode interfaccia_node;
        QDomNode cache_node;
        QDomNode velocita_node;

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
                fattoreDiForma_node=produttore_node.nextSiblingElement();
                interfaccia_node=fattoreDiForma_node.nextSiblingElement();
                cache_node=interfaccia_node.nextSiblingElement();
                velocita_node=cache_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(fattoreDiForma_node);
        componente_node.removeChild(interfaccia_node);
        componente_node.removeChild(cache_node);
        componente_node.removeChild(velocita_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* UnitaOttica::clone() const{
    return new UnitaOttica(*this);
}

void UnitaOttica::setAddWidget() const{
    this->getController()->createUnitaOtticaAdd();
}

void UnitaOttica::addComponente() const{
    this->getController()->eseguiAggiuntaUnitaOttica();
}

void UnitaOttica::setSpecsWidget() const{
    this->getController()->createUnitaOtticaSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getFattoreDiForma(),
                                                  this->getInterfaccia(),this->getCache(),this->getVelocita());
}

void UnitaOttica::clearAddWidget() const{
    this->getController()->clearUnitaOtticaAdd();
}

void UnitaOttica::updateConfigurazione() const{
    this->getController()->updateConfigurazioneUnitaOttica(this->getNome(),this->getPrezzo());
}

QString UnitaOttica::getNomeTipoComponente() const{
    return "Unità ottica";
}

QString UnitaOttica::getFattoreDiForma() const{
    return fattoreDiForma;
}

QString UnitaOttica::getInterfaccia() const{
    return interfaccia;
}

QString UnitaOttica::getCache() const{
    return cache;
}

QString UnitaOttica::getVelocita() const{
    return velocita;
}

QString UnitaOttica::getType() const{
    return "UnitaOttica";
}
