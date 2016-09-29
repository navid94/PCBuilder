#include "Case.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

Case::Case(const QString& input_nome, double input_prezzo, const QString& input_produttore, PCBuilderController* input_controller, const QString& input_tipologia,
           const QString& input_colore, bool input_alimentatoreIncluso, int input_slotInterni25, int input_slotInterni35,
           const QString& input_compatibilitaSchedaMadre, const QString& input_lunghezzaMassimaSchedaGrafica,
           const QString& input_dimensioni):Componente(input_nome,input_prezzo,input_produttore, input_controller),
    tipologia(input_tipologia),colore(input_colore),alimentatoreIncluso(input_alimentatoreIncluso),
    slotInterni25(input_slotInterni25),slotInterni35(input_slotInterni35),compatibilitaSchedaMadre(input_compatibilitaSchedaMadre),
    lunghezzaMassimaSchedaGrafica(input_lunghezzaMassimaSchedaGrafica),dimensioni(input_dimensioni){}

Case::Case(PCBuilderController* input_controller):Componente(input_controller){}

void Case::saveXMLComponente() const{
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode case_node=doc.createElement("Case");
        root.appendChild(case_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode alimentatoreIncluso_node=doc.createElement("AlimentatoreIncluso");
        alimentatoreIncluso_node.appendChild(doc.createTextNode(QString::number(this->getAlimentatoreIncluso())));

        QDomNode slotInterni25_node=doc.createElement("SlotInterni25");
        slotInterni25_node.appendChild(doc.createTextNode(QString::number(this->getSlotInterni25())));

        QDomNode slotInterni35_node=doc.createElement("SlotInterni35");
        slotInterni35_node.appendChild(doc.createTextNode(QString::number(this->getSlotInterni35())));

        QDomNode compatibilitaSchedaMadre_node=doc.createElement("compatibilitaSchedaMadre");
        compatibilitaSchedaMadre_node.appendChild(doc.createTextNode(this->getCompatibilitaSchedaMadre()));

        QDomNode lunghezzaMassimaSchedaGrafica_node=doc.createElement("LunghezzaMassimaSchedaGrafica");
        lunghezzaMassimaSchedaGrafica_node.appendChild(doc.createTextNode(this->getLunghezzaMassimaSchedaGrafica()));

        QDomNode dimensioni_node=doc.createElement("Dimensioni");
        dimensioni_node.appendChild(doc.createTextNode(this->getDimensioni()));

        case_node.appendChild(nome_node);
        case_node.appendChild(prezzo_node);
        case_node.appendChild(produttore_node);
        case_node.appendChild(tipologia_node);
        case_node.appendChild(colore_node);
        case_node.appendChild(alimentatoreIncluso_node);
        case_node.appendChild(slotInterni25_node);
        case_node.appendChild(slotInterni35_node);
        case_node.appendChild(compatibilitaSchedaMadre_node);
        case_node.appendChild(lunghezzaMassimaSchedaGrafica_node);
        case_node.appendChild(dimensioni_node);

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
        QDomNode case_node=doc.createElement("Case");
        componenti_node.appendChild(case_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode tipologia_node=doc.createElement("Tipologia");
        tipologia_node.appendChild(doc.createTextNode(this->getTipologia()));

        QDomNode colore_node=doc.createElement("Colore");
        colore_node.appendChild(doc.createTextNode(this->getColore()));

        QDomNode alimentatoreIncluso_node=doc.createElement("AlimentatoreIncluso");
        alimentatoreIncluso_node.appendChild(doc.createTextNode(QString::number(this->getAlimentatoreIncluso())));

        QDomNode slotInterni25_node=doc.createElement("SlotInterni25");
        slotInterni25_node.appendChild(doc.createTextNode(QString::number(this->getSlotInterni25())));

        QDomNode slotInterni35_node=doc.createElement("SlotInterni35");
        slotInterni35_node.appendChild(doc.createTextNode(QString::number(this->getSlotInterni35())));

        QDomNode compatibilitaSchedaMadre_node=doc.createElement("compatibilitaSchedaMadre");
        compatibilitaSchedaMadre_node.appendChild(doc.createTextNode(this->getCompatibilitaSchedaMadre()));

        QDomNode lunghezzaMassimaSchedaGrafica_node=doc.createElement("LunghezzaMassimaSchedaGrafica");
        lunghezzaMassimaSchedaGrafica_node.appendChild(doc.createTextNode(this->getLunghezzaMassimaSchedaGrafica()));

        QDomNode dimensioni_node=doc.createElement("Dimensioni");
        dimensioni_node.appendChild(doc.createTextNode(this->getDimensioni()));

        case_node.appendChild(nome_node);
        case_node.appendChild(prezzo_node);
        case_node.appendChild(produttore_node);
        case_node.appendChild(tipologia_node);
        case_node.appendChild(colore_node);
        case_node.appendChild(alimentatoreIncluso_node);
        case_node.appendChild(slotInterni25_node);
        case_node.appendChild(slotInterni35_node);
        case_node.appendChild(compatibilitaSchedaMadre_node);
        case_node.appendChild(lunghezzaMassimaSchedaGrafica_node);
        case_node.appendChild(dimensioni_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void Case::deleteXMLComponente() const{
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
        QDomNode colore_node;
        QDomNode alimentatoreIncluso_node;
        QDomNode slotInterni25_node;
        QDomNode slotInterni35_node;
        QDomNode compatibilitaSchedaMadre_node;
        QDomNode lunghezzaMassimaSchedaGrafica_node;
        QDomNode dimensioni_node;

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
                colore_node=tipologia_node.nextSiblingElement();
                alimentatoreIncluso_node=colore_node.nextSiblingElement();
                slotInterni25_node=alimentatoreIncluso_node.nextSiblingElement();
                slotInterni35_node=slotInterni25_node.nextSiblingElement();
                compatibilitaSchedaMadre_node=slotInterni35_node.nextSiblingElement();
                lunghezzaMassimaSchedaGrafica_node=compatibilitaSchedaMadre_node.nextSiblingElement();
                dimensioni_node=lunghezzaMassimaSchedaGrafica_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(tipologia_node);
        componente_node.removeChild(colore_node);
        componente_node.removeChild(alimentatoreIncluso_node);
        componente_node.removeChild(slotInterni25_node);
        componente_node.removeChild(slotInterni35_node);
        componente_node.removeChild(compatibilitaSchedaMadre_node);
        componente_node.removeChild(lunghezzaMassimaSchedaGrafica_node);
        componente_node.removeChild(dimensioni_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

Componente* Case::clone() const{
    return new Case(*this);
}

void Case::setAddWidget() const{
    this->getController()->createCaseAdd();
}

void Case::addComponente() const{
    this->getController()->eseguiAggiuntaCase();
}

void Case::setSpecsWidget() const{
    this->getController()->createCaseSpecs(this->getNome(),this->getPrezzo(),this->getProduttore(),this->getTipologia(),this->getColore(),
                                           this->getAlimentatoreIncluso(),this->getSlotInterni25(),this->getSlotInterni35(),this->getCompatibilitaSchedaMadre(),
                                           this->getLunghezzaMassimaSchedaGrafica(),this->getDimensioni());
}

void Case::updateConfigurazione() const{
    this->getController()->updateConfigurazioneCase(this->getNome(),this->getPrezzo());
}

void Case::clearAddWidget() const{
    return this->getController()->clearCaseAdd();
}

QString Case::getNomeTipoComponente() const{
    return "Case";
}

QString Case::getTipologia() const{
    return tipologia;
}

QString Case::getColore() const{
    return colore;
}

bool Case::getAlimentatoreIncluso() const{
    return alimentatoreIncluso;
}

int Case::getSlotInterni25() const{
    return slotInterni25;
}

int Case::getSlotInterni35() const{
    return slotInterni35;
}

QString Case::getCompatibilitaSchedaMadre() const{
    return compatibilitaSchedaMadre;
}

QString Case::getLunghezzaMassimaSchedaGrafica() const{
    return lunghezzaMassimaSchedaGrafica;
}

QString Case::getDimensioni() const{
    return dimensioni;
}

QString Case::getType() const{
    return "Case";
}
