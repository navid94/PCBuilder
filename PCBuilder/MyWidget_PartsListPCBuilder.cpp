#include "MyWidget_PartsListPCBuilder.h"
#include <QLayout>
#include <QFile>
#include <QTextStream>
#include <QDomNode>
#include <QVector>

MyWidget_PartsListPCBuilder::MyWidget_PartsListPCBuilder(const QString& input_componente ,QWidget* parent):
    QWidget(parent),componente(input_componente){
    createLabels();
    createPushButtons();

    signalMapper=new QSignalMapper(this);

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QGridLayout* gridLayout=new QGridLayout;
    QVBoxLayout* verticalLayout1=new QVBoxLayout;

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_ListaComponentiLabel);

    gridLayout->addWidget(componenteLabel,0,0,1,1);
    gridLayout->addWidget(produttoreLabel,0,1,1,1);
    gridLayout->addWidget(prezzoLabel,0,2,1,1);

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
        QVector<QLabel*> componenteLabels;
        QVector<QLabel*> produttoreLabels;
        QVector<QLabel*> prezzoLabels;
        QVector<QPushButton*> aggiungiPushButtons;
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
                aggiungiPushButtons.append(new QPushButton(tr("Aggiungi")));
                aggiungiPushButtons[n]->setMaximumSize(QSize(150,50));
                aggiungiPushButtons[n]->setMinimumSize(QSize(0,0));
                connect(aggiungiPushButtons[n],SIGNAL(clicked()),signalMapper,SLOT(map()));
                QString info=nome+("&")+(QString::number(prezzo))+("&")+(componente);
                signalMapper->setMapping(aggiungiPushButtons[n],info);
                gridLayout->addWidget(aggiungiPushButtons[n],i,3,1,1);

                i++;
                n++;
            }
            componente_node=componente_node.nextSiblingElement();
        }
        file.close();
    }
    connect(signalMapper,SIGNAL(mapped(const QString&)),this,SIGNAL(sendMessage(const QString&)));
    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(gridLayout);

    setLayout(verticalLayout1);
}

void MyWidget_PartsListPCBuilder::createLabels(){
    PCBuilder_ListaComponentiLabel=new QLabel("PCBuilder - "+(tr("Lista componenti")));
    QFont font_PCBuilder_ListaComponentiLabel=PCBuilder_ListaComponentiLabel->font();
    font_PCBuilder_ListaComponentiLabel.setPointSize(24);
    PCBuilder_ListaComponentiLabel->setFont(font_PCBuilder_ListaComponentiLabel);
    PCBuilder_ListaComponentiLabel->setMaximumSize(QSize(470,50));
    PCBuilder_ListaComponentiLabel->setMinimumSize(QSize(0,0));

    QFont header_font;
    header_font.setPointSize(18);

    componenteLabel=new QLabel(tr("Componente"));
    componenteLabel->setFont(header_font);
    componenteLabel->setMaximumSize(QSize(160,30));
    componenteLabel->setMinimumSize(QSize(0,0));

    produttoreLabel=new QLabel(tr("Produttore"));
    produttoreLabel->setFont(header_font);
    produttoreLabel->setMaximumSize(QSize(130,30));
    produttoreLabel->setMinimumSize(QSize(0,0));

    prezzoLabel=new QLabel(tr("Prezzo"));
    prezzoLabel->setFont(header_font);
    prezzoLabel->setMaximumSize(QSize(80,30));
    prezzoLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_PartsListPCBuilder::createPushButtons(){
    indietroPushButton=new QPushButton(tr("Indietro"));
    indietroPushButton->setMaximumSize(QSize(150,30));
    indietroPushButton->setMinimumSize(QSize(0,0));
}

QPushButton* MyWidget_PartsListPCBuilder::getIndietroPushButton() const{
    return indietroPushButton;
}
