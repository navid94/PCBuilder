#include "Memoria.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Memoria::Memoria(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller,
                 const QString& input_velocita, const QString& input_capacita, const QString& input_tipologia,
                 int input_latenza):Componente(input_nome, input_prezzo, input_produttore, input_controller), velocita(input_velocita),
    capacita(input_capacita), tipologia(input_tipologia), latenza(input_latenza){}

Memoria::Memoria(PCBuilderController* input_controller):Componente(input_controller){}

void Memoria::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode memoria_node=doc.createElement("Memoria");
        root.appendChild(memoria_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode velocita_node=doc.createElement("Velocita");
        velocita_node.appendChild(doc.createTextNode(this->getVelocita()));

        QDomNode capacita_node=doc.createElement("Capacita");
        capacita_node.appendChild(doc.createTextNode(this->getCapacita()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode latenza_node=doc.createElement("Latenza");
        latenza_node.appendChild(doc.createTextNode(QString::number(this->getLatenza())));



        memoria_node.appendChild(nome_node);
        memoria_node.appendChild(prezzo_node);
        memoria_node.appendChild(produttore_node);
        memoria_node.appendChild(velocita_node);
        memoria_node.appendChild(capacita_node);
        memoria_node.appendChild(tipologia_node);
        memoria_node.appendChild(latenza_node);

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
        QDomNode memoria_node=doc.createElement("Memoria");
        componenti_node.appendChild(memoria_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode velocita_node=doc.createElement("Velocita");
        velocita_node.appendChild(doc.createTextNode(this->getVelocita()));

        QDomNode capacita_node=doc.createElement("Capacita");
        capacita_node.appendChild(doc.createTextNode(this->getCapacita()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode latenza_node=doc.createElement("Latenza");
        latenza_node.appendChild(doc.createTextNode(QString::number(this->getLatenza())));


        memoria_node.appendChild(nome_node);
        memoria_node.appendChild(prezzo_node);
        memoria_node.appendChild(produttore_node);
        memoria_node.appendChild(velocita_node);
        memoria_node.appendChild(capacita_node);
        memoria_node.appendChild(tipologia_node);
        memoria_node.appendChild(latenza_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Memoria::deleteXMLComponente() const{
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
        QDomNode velocita_node;
        QDomNode capacita_node;
        QDomNode tipologia_node;
        QDomNode latenza_node;

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
                velocita_node=produttore_node.nextSiblingElement();
                capacita_node=velocita_node.nextSiblingElement();
                tipologia_node=capacita_node.nextSiblingElement();
                latenza_node=tipologia_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(velocita_node);
        componente_node.removeChild(capacita_node);
        componente_node.removeChild(tipologia_node);
        componente_node.removeChild(latenza_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* Memoria::clone() const{
    return new Memoria(*this);
}

void Memoria::setAddWidget() const{
    this->getController()->createMemoriaAdd();
}

void Memoria::addComponente() const{
    this->getController()->eseguiAggiuntaMemoria();
}

void Memoria::setSpecsWidget() const{
    this->getController()->createMemoriaSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getVelocita(),this->getCapacita(),
                                              this->getTipologia(),this->getLatenza());
}

void Memoria::clearAddWidget() const{
    this->getController()->clearMemoriaAdd();
}

void Memoria::updateConfigurazione() const{
    this->getController()->updateConfigurazioneMemoria(this->getNome(),this->getPrezzo());
}

QString Memoria::getNomeTipoComponente() const{
    return "Memoria";
}

QString Memoria::getVelocita() const{
    return velocita;
}

QString Memoria::getCapacita() const{
    return capacita;
}

QString Memoria::getTipologia() const{
    return tipologia;
}

int Memoria::getLatenza() const{
    return latenza;
}

QString Memoria::getType() const{
    return "Memoria";
}
