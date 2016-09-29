#include "MyWidget_CercaPartiPCBuilder.h"
#include <QFile>
#include <QDomNode>


MyWidget_CercaPartiPCBuilder::MyWidget_CercaPartiPCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createPushButtons();
    createComboBoxes();

    signalMapper=new QSignalMapper(this);

    connect(tipologiaComponenteComboBox,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(loadPartsList(const QString&)));

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    gridLayout=new QGridLayout;

    horizontalLayout1->setContentsMargins(0,0,0,50);
    horizontalLayout1->setSpacing(50);
    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_CercaTraLePartiLabel);

    horizontalLayout2->addWidget(tipologiaComponenteLabel);
    horizontalLayout2->addWidget(tipologiaComponenteComboBox);

    gridLayout->addWidget(componenteLabel,0,0,1,1);
    gridLayout->addWidget(produttoreLabel,0,1,1,1);
    gridLayout->addWidget(prezzoLabel,0,2,1,1);

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(horizontalLayout2);
    verticalLayout1->addLayout(gridLayout);

    setLayout(verticalLayout1);
}

void MyWidget_CercaPartiPCBuilder::createLabels(){
    QFont font_header;
    font_header.setPointSize(18);

    PCBuilder_CercaTraLePartiLabel=new QLabel("PCBuilder - "+(tr("Cerca tra le parti")));
    QFont font_PCBuilder_CercaTraLePartiLabel=PCBuilder_CercaTraLePartiLabel->font();
    font_PCBuilder_CercaTraLePartiLabel.setPointSize(24);
    PCBuilder_CercaTraLePartiLabel->setFont(font_PCBuilder_CercaTraLePartiLabel);
    PCBuilder_CercaTraLePartiLabel->setMaximumSize(QSize(460,50));
    PCBuilder_CercaTraLePartiLabel->setMinimumSize(QSize(0,0));

    tipologiaComponenteLabel=new QLabel(tr("Tipologia componente"));
    tipologiaComponenteLabel->setFont(font_header);
    tipologiaComponenteLabel->setMaximumSize(QSize(310,30));
    tipologiaComponenteLabel->setMinimumSize(QSize(0,0));

    componenteLabel=new QLabel(tr("Componente"));
    componenteLabel->setFont(font_header);
    componenteLabel->setMaximumSize(QSize(160,30));
    componenteLabel->setMinimumSize(QSize(0,0));

    prezzoLabel=new QLabel(tr("Prezzo"));
    prezzoLabel->setFont(font_header);
    prezzoLabel->setMaximumSize(QSize(80,30));
    prezzoLabel->setMinimumSize(QSize(0,0));

    produttoreLabel=new QLabel(tr("Produttore"));
    produttoreLabel->setFont(font_header);
    produttoreLabel->setMaximumSize(QSize(130,30));
    produttoreLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_CercaPartiPCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));
}

void MyWidget_CercaPartiPCBuilder::createComboBoxes(){
    tipologiaComponenteComboBox=new QComboBox;
    tipologiaComponenteComboBox->setMaximumSize(QSize(300,25));
    tipologiaComponenteComboBox->setMinimumSize(QSize(0,0));
    tipologiaComponenteComboBox->addItem(tr("Seleziona il componente"));
    tipologiaComponenteComboBox->addItem(tr("Memoria"));
    tipologiaComponenteComboBox->addItem(tr("Scheda grafica"));
    tipologiaComponenteComboBox->addItem(tr("Scheda madre"));
    tipologiaComponenteComboBox->addItem(tr("Processore"));
    tipologiaComponenteComboBox->addItem(tr("Archiviazione"));
    tipologiaComponenteComboBox->addItem(tr("Alimentatore"));
    tipologiaComponenteComboBox->addItem(tr("Dissipatore processore"));
    tipologiaComponenteComboBox->addItem(tr("Case"));
    tipologiaComponenteComboBox->addItem(tr("Unità ottica"));
    tipologiaComponenteComboBox->addItem(tr("Monitor"));
    tipologiaComponenteComboBox->addItem(tr("Sistema operativo"));
    tipologiaComponenteComboBox->addItem(tr("Mouse"));
    tipologiaComponenteComboBox->addItem(tr("Tastiera"));
    tipologiaComponenteComboBox->addItem(tr("Cuffie"));
    tipologiaComponenteComboBox->addItem(tr("Altoparlanti"));
}

QPushButton* MyWidget_CercaPartiPCBuilder::getIndietroPushButton() const{
    return indietroPushButton;
}

void MyWidget_CercaPartiPCBuilder::loadPartsList(const QString& tipologiaComponente){
    for (int i=0;i<componenteLabels.size();i++)
    {
        gridLayout->removeWidget(componenteLabels.at(i));
        delete (componenteLabels.at(i));
    }
    componenteLabels.clear();
    for (int i=0;i<produttoreLabels.size();i++)
    {
        gridLayout->removeWidget(produttoreLabels.at(i));
        delete (produttoreLabels.at(i));
    }
    produttoreLabels.clear();
    for (int i=0;i<prezzoLabels.size();i++)
    {
        gridLayout->removeWidget(prezzoLabels.at(i));
        delete (prezzoLabels.at(i));
    }
    prezzoLabels.clear();
    for (int i=0;i<specifichePushButtons.size();i++)
    {
        gridLayout->removeWidget(specifichePushButtons.at(i));
        delete (specifichePushButtons.at(i));
    }
    specifichePushButtons.clear();
    if (tipologiaComponente!="Seleziona il componente")
    {
        QString componente;
        if (tipologiaComponente=="Memoria")
            componente="Memoria";
        if (tipologiaComponente=="Scheda grafica")
            componente="SchedaGrafica";
        if (tipologiaComponente=="Scheda madre")
            componente="SchedaMadre";
        if (tipologiaComponente=="Processore")
            componente="Processore";
        if (tipologiaComponente=="Archiviazione")
            componente="Archiviazione";
        if (tipologiaComponente=="Alimentatore")
            componente="Alimentatore";
        if (tipologiaComponente=="Dissipatore processore")
            componente="DissipatoreProcessore";
        if (tipologiaComponente=="Case")
            componente="Case";
        if (tipologiaComponente=="Unità ottica")
            componente="UnitaOttica";
        if (tipologiaComponente=="Monitor")
            componente="Monitor";
        if (tipologiaComponente=="Sistema operativo")
            componente="SistemaOperativo";
        if (tipologiaComponente=="Mouse")
            componente="Mouse";
        if (tipologiaComponente=="Tastiera")
            componente="Tastiera";
        if (tipologiaComponente=="Cuffie")
            componente="Cuffie";
        if (tipologiaComponente=="Altoparlanti")
            componente="Altoparlanti";

        QString filename="Componenti.xml";
        if (QFile::exists(filename))
        {
            QFile file(filename);
            QDomDocument doc("Componenti");
            file.open(QIODevice::ReadOnly);
            doc.setContent(&file);
            QDomNode root=doc.firstChildElement();
            QDomNode componente_node=root.firstChildElement();
            int n=0,i=1;
            QFont form_font;
            form_font.setPointSize(14);
            while (!componente_node.isNull())
            {
                QDomNode nome_node=componente_node.firstChildElement();
                QString nome=nome_node.firstChild().nodeValue();
                QDomNode prezzo_node=nome_node.nextSiblingElement();
                double prezzo=prezzo_node.firstChild().nodeValue().toDouble();
                QDomNode produttore_node=prezzo_node.nextSiblingElement();
                QString produttore=produttore_node.firstChild().nodeValue();

                if (componente_node.nodeName()==componente)
                {
                    componenteLabels.append(new QLabel(nome));
                    componenteLabels[n]->setFont(form_font);
                    componenteLabels[n]->setMaximumHeight(30);
                    componenteLabels[n]->setMinimumSize(QSize(0,0));
                    gridLayout->addWidget(componenteLabels[n],i,0,1,1);
                    produttoreLabels.append(new QLabel(produttore));
                    produttoreLabels[n]->setFont(form_font);
                    produttoreLabels[n]->setMaximumHeight(30);
                    produttoreLabels[n]->setMinimumSize(QSize(0,0));
                    gridLayout->addWidget(produttoreLabels[n],i,1,1,1);
                    prezzoLabels.append(new QLabel("€ "+(QString::number(prezzo))));
                    prezzoLabels[n]->setFont(form_font);
                    prezzoLabels[n]->setMaximumHeight(30);
                    prezzoLabels[n]->setMinimumSize(QSize(0,0));
                    gridLayout->addWidget(prezzoLabels[n],i,2,1,1);
                    specifichePushButtons.append(new QPushButton(tr("Specifiche")));
                    specifichePushButtons[n]->setMaximumSize(QSize(150,50));
                    specifichePushButtons[n]->setMinimumSize(QSize(0,0));
                    connect(specifichePushButtons[n],SIGNAL(clicked()),signalMapper,SLOT(map()));
                    signalMapper->setMapping(specifichePushButtons[n],nome);
                    gridLayout->addWidget(specifichePushButtons[n],i,3,1,1);

                    i++;
                    n++;
                }
                componente_node=componente_node.nextSiblingElement();
            }
            file.close();
        }
        connect(signalMapper,SIGNAL(mapped(const QString&)),this,SIGNAL(sendMessage(const QString&)));
    }
}
