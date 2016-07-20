#include "SchedaMadre.h"
#include <QFile>
#include <QDomDocument>
#include <QTextStream>

SchedaMadre::SchedaMadre(const QString& input_nome, double input_prezzo, const QString& input_produttore, const QString& input_fattoreDiForma,
                         const QString& input_chipset, const QString& input_socketProcessore, const QString& input_slotMemoria,
                         const QString& input_tipologiaMemoria, const QString& input_memoriaMassima, bool input_supportoRAID,
                         bool input_supportoCrossfire, bool input_supportoSLI, const QString& input_ethernet,
                         int input_sata3GBs, int input_sata6GBs, int input_sataExpress, int input_usb2, int input_usb3):
    Componente(input_nome,input_prezzo,input_produttore),fattoreDiForma(input_fattoreDiForma),chipset(input_chipset),
    socketProcessore(input_socketProcessore),slotMemoria(input_slotMemoria), tipologiaMemoria(input_tipologiaMemoria),
    memoriaMassima(input_memoriaMassima),supportoRAID(input_supportoRAID),supportoCrossfire(input_supportoCrossfire),supportoSLI(input_supportoSLI),
    ethernet(input_ethernet),sata3GBs(input_sata3GBs),sata6GBs(input_sata6GBs),sataExpress(input_sataExpress),usb2(input_usb2),usb3(input_usb3){}

void SchedaMadre::saveXMLComponente(){
    QString filename="Componenti.xml";
    if (QFile::exists(filename))
    {
        QDomDocument doc("Componenti");
        QFile file(filename);
        file.open(QIODevice::ReadWrite);
        doc.setContent(&file);
        QDomNode root=doc.firstChildElement();
        QDomNode schedaMadre_node=doc.createElement("SchedaMadre");
        root.appendChild(schedaMadre_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode fattoreDiForma_node=doc.createElement("FattoreDiForma");
        fattoreDiForma_node.appendChild(doc.createTextNode(this->getFattoreDiForma()));

        QDomNode chipset_node=doc.createElement("Chipset");
        chipset_node.appendChild(doc.createTextNode(this->getChipset()));

        QDomNode socketProcessore_node=doc.createElement("SocketProcessore");
        socketProcessore_node.appendChild(doc.createTextNode(this->getSocketProcessore()));

        QDomNode slotMemoria_node=doc.createElement("SlotMemoria");
        slotMemoria_node.appendChild(doc.createTextNode(this->getSlotMemoria()));

        QDomNode tipologiaMemoria_node=doc.createElement("TipologiaMemoria");
        tipologiaMemoria_node.appendChild(doc.createTextNode(this->getTipologiaMemoria()));

        QDomNode memoriaMassima_node=doc.createElement("MemoriaMassima");
        memoriaMassima_node.appendChild(doc.createTextNode(this->getMemoriaMassima()));

        QDomNode supportoRAID_node=doc.createElement("SupportoRAID");
        supportoRAID_node.appendChild(doc.createTextNode(QString::number(this->getSupportoRAID())));

        QDomNode supportoCrossfire_node=doc.createElement("SupportoCrossfire");
        supportoCrossfire_node.appendChild(doc.createTextNode(QString::number(this->getSupportoCrossfire())));

        QDomNode supportoSLI_node=doc.createElement("SupportoSLI");
        supportoSLI_node.appendChild(doc.createTextNode(QString::number(this->getSupportoSLI())));

        QDomNode ethernet_node=doc.createElement("Ethernet");
        ethernet_node.appendChild(doc.createTextNode(this->getEthernet()));

        QDomNode sata3GBs_node=doc.createElement("Sata3GBs");
        sata3GBs_node.appendChild(doc.createTextNode(QString::number(this->getSata3GBs())));

        QDomNode sata6GBs_node=doc.createElement("Sata6GBs");
        sata6GBs_node.appendChild(doc.createTextNode(QString::number(this->getSata6GBs())));

        QDomNode sataExpress_node=doc.createElement("SataExpress");
        sataExpress_node.appendChild(doc.createTextNode(QString::number(this->getSataExpress())));

        QDomNode usb2_node=doc.createElement("Usb2");
        usb2_node.appendChild(doc.createTextNode(QString::number(this->getUsb2())));

        QDomNode usb3_node=doc.createElement("Usb3");
        usb3_node.appendChild(doc.createTextNode(QString::number(this->getUsb3())));

        schedaMadre_node.appendChild(nome_node);
        schedaMadre_node.appendChild(prezzo_node);
        schedaMadre_node.appendChild(produttore_node);
        schedaMadre_node.appendChild(fattoreDiForma_node);
        schedaMadre_node.appendChild(chipset_node);
        schedaMadre_node.appendChild(socketProcessore_node);
        schedaMadre_node.appendChild(slotMemoria_node);
        schedaMadre_node.appendChild(tipologiaMemoria_node);
        schedaMadre_node.appendChild(memoriaMassima_node);
        schedaMadre_node.appendChild(supportoRAID_node);
        schedaMadre_node.appendChild(supportoCrossfire_node);
        schedaMadre_node.appendChild(supportoSLI_node);
        schedaMadre_node.appendChild(ethernet_node);
        schedaMadre_node.appendChild(sata3GBs_node);
        schedaMadre_node.appendChild(sata6GBs_node);
        schedaMadre_node.appendChild(sataExpress_node);
        schedaMadre_node.appendChild(usb2_node);
        schedaMadre_node.appendChild(usb3_node);


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
        QDomNode schedaMadre_node=doc.createElement("SchedaMadre");
        componenti_node.appendChild(schedaMadre_node);

        QDomNode nome_node=doc.createElement("Nome");
        nome_node.appendChild(doc.createTextNode(this->getNome()));

        QDomNode prezzo_node=doc.createElement("Prezzo");
        prezzo_node.appendChild(doc.createTextNode(QString::number(this->getPrezzo())));

        QDomNode produttore_node=doc.createElement("Produttore");
        produttore_node.appendChild(doc.createTextNode(this->getProduttore()));

        QDomNode fattoreDiForma_node=doc.createElement("FattoreDiForma");
        fattoreDiForma_node.appendChild(doc.createTextNode(this->getFattoreDiForma()));

        QDomNode chipset_node=doc.createElement("Chipset");
        chipset_node.appendChild(doc.createTextNode(this->getChipset()));

        QDomNode socketProcessore_node=doc.createElement("SocketProcessore");
        socketProcessore_node.appendChild(doc.createTextNode(this->getSocketProcessore()));

        QDomNode slotMemoria_node=doc.createElement("SlotMemoria");
        slotMemoria_node.appendChild(doc.createTextNode(this->getSlotMemoria()));

        QDomNode tipologiaMemoria_node=doc.createElement("TipologiaMemoria");
        tipologiaMemoria_node.appendChild(doc.createTextNode(this->getTipologiaMemoria()));

        QDomNode memoriaMassima_node=doc.createElement("MemoriaMassima");
        memoriaMassima_node.appendChild(doc.createTextNode(this->getMemoriaMassima()));

        QDomNode supportoRAID_node=doc.createElement("SupportoRAID");
        supportoRAID_node.appendChild(doc.createTextNode(QString::number(this->getSupportoRAID())));

        QDomNode supportoCrossfire_node=doc.createElement("SupportoCrossfire");
        supportoCrossfire_node.appendChild(doc.createTextNode(QString::number(this->getSupportoCrossfire())));

        QDomNode supportoSLI_node=doc.createElement("SupportoSLI");
        supportoSLI_node.appendChild(doc.createTextNode(QString::number(this->getSupportoSLI())));

        QDomNode ethernet_node=doc.createElement("Ethernet");
        ethernet_node.appendChild(doc.createTextNode(this->getEthernet()));

        QDomNode sata3GBs_node=doc.createElement("Sata3GBs");
        sata3GBs_node.appendChild(doc.createTextNode(QString::number(this->getSata3GBs())));

        QDomNode sata6GBs_node=doc.createElement("Sata6GBs");
        sata6GBs_node.appendChild(doc.createTextNode(QString::number(this->getSata6GBs())));

        QDomNode sataExpress_node=doc.createElement("SataExpress");
        sataExpress_node.appendChild(doc.createTextNode(QString::number(this->getSataExpress())));

        QDomNode usb2_node=doc.createElement("Usb2");
        usb2_node.appendChild(doc.createTextNode(QString::number(this->getUsb2())));

        QDomNode usb3_node=doc.createElement("Usb3");
        usb3_node.appendChild(doc.createTextNode(QString::number(this->getUsb3())));

        schedaMadre_node.appendChild(nome_node);
        schedaMadre_node.appendChild(prezzo_node);
        schedaMadre_node.appendChild(produttore_node);
        schedaMadre_node.appendChild(fattoreDiForma_node);
        schedaMadre_node.appendChild(chipset_node);
        schedaMadre_node.appendChild(socketProcessore_node);
        schedaMadre_node.appendChild(slotMemoria_node);
        schedaMadre_node.appendChild(tipologiaMemoria_node);
        schedaMadre_node.appendChild(memoriaMassima_node);
        schedaMadre_node.appendChild(supportoRAID_node);
        schedaMadre_node.appendChild(supportoCrossfire_node);
        schedaMadre_node.appendChild(supportoSLI_node);
        schedaMadre_node.appendChild(ethernet_node);
        schedaMadre_node.appendChild(sata3GBs_node);
        schedaMadre_node.appendChild(sata6GBs_node);
        schedaMadre_node.appendChild(sataExpress_node);
        schedaMadre_node.appendChild(usb2_node);
        schedaMadre_node.appendChild(usb3_node);

        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

void SchedaMadre::deleteXMLComponente(){
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
        QDomNode chipset_node;
        QDomNode socketProcessore_node;
        QDomNode slotMemoria_node;
        QDomNode tipologiaMemoria_node;
        QDomNode memoriaMassima_node;
        QDomNode supportoRAID_node;
        QDomNode supportoCrossfire_node;
        QDomNode supportoSLI_node;
        QDomNode ethernet_node;
        QDomNode sata3GBs_node;
        QDomNode sata6GBs_node;
        QDomNode sataExpress_node;
        QDomNode usb2_node;
        QDomNode usb3_node;

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
                chipset_node=fattoreDiForma_node.nextSiblingElement();
                socketProcessore_node=chipset_node.nextSiblingElement();
                slotMemoria_node=socketProcessore_node.nextSiblingElement();
                tipologiaMemoria_node=slotMemoria_node.nextSiblingElement();
                memoriaMassima_node=tipologiaMemoria_node.nextSiblingElement();
                supportoRAID_node=memoriaMassima_node.nextSiblingElement();
                supportoCrossfire_node=supportoRAID_node.nextSiblingElement();
                supportoSLI_node=supportoCrossfire_node.nextSiblingElement();
                ethernet_node=supportoSLI_node.nextSiblingElement();
                sata3GBs_node=ethernet_node.nextSiblingElement();
                sata6GBs_node=sata3GBs_node.nextSiblingElement();
                sataExpress_node=sata6GBs_node.nextSiblingElement();
                usb2_node=sataExpress_node.nextSiblingElement();
                usb3_node=usb2_node.nextSiblingElement();
                trovato=true;
            }
        }
        componente_node.removeChild(nome_node);
        componente_node.removeChild(prezzo_node);
        componente_node.removeChild(produttore_node);
        componente_node.removeChild(fattoreDiForma_node);
        componente_node.removeChild(chipset_node);
        componente_node.removeChild(socketProcessore_node);
        componente_node.removeChild(slotMemoria_node);
        componente_node.removeChild(tipologiaMemoria_node);
        componente_node.removeChild(memoriaMassima_node);
        componente_node.removeChild(supportoRAID_node);
        componente_node.removeChild(supportoCrossfire_node);
        componente_node.removeChild(supportoSLI_node);
        componente_node.removeChild(ethernet_node);
        componente_node.removeChild(sata3GBs_node);
        componente_node.removeChild(sata6GBs_node);
        componente_node.removeChild(sataExpress_node);
        componente_node.removeChild(usb2_node);
        componente_node.removeChild(usb3_node);
        root.removeChild(componente_node);


        file.resize(0);
        QTextStream out(&file);
        out<<doc.toString();
        file.close();
    }
}

QString SchedaMadre::getFattoreDiForma() const{
    return fattoreDiForma;
}

QString SchedaMadre::getChipset() const{
    return chipset;
}

QString SchedaMadre::getSocketProcessore() const{
    return socketProcessore;
}

QString SchedaMadre::getSlotMemoria() const{
    return slotMemoria;
}

QString SchedaMadre::getTipologiaMemoria() const{
    return tipologiaMemoria;
}

QString SchedaMadre::getMemoriaMassima() const{
    return memoriaMassima;
}

bool SchedaMadre::getSupportoRAID() const{
    return supportoRAID;
}

bool SchedaMadre::getSupportoCrossfire() const{
    return supportoCrossfire;
}

bool SchedaMadre::getSupportoSLI() const{
    return supportoSLI;
}

QString SchedaMadre::getEthernet() const{
    return ethernet;
}

int SchedaMadre::getSata3GBs() const{
    return sata3GBs;
}

int SchedaMadre::getSata6GBs() const{
    return sata6GBs;
}

int SchedaMadre::getSataExpress() const{
    return sataExpress;
}

int SchedaMadre::getUsb2() const{
    return usb2;
}

int SchedaMadre::getUsb3() const{
    return usb3;
}

QString SchedaMadre::getType() const{
    return "SchedaMadre";
}
