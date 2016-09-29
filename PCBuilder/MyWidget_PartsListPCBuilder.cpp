#include "MyWidget_PartsListPCBuilder.h"
#include <QFile>
#include <QTextStream>
#include <QDomNode>
#include <QVector>

MyWidget_PartsListPCBuilder::MyWidget_PartsListPCBuilder(QWidget* parent):
    QWidget(parent),row(1){
    createLabels();
    createPushButtons();

    signalMapper=new QSignalMapper(this);

    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    gridLayout=new QGridLayout;
    QVBoxLayout* verticalLayout1=new QVBoxLayout;

    horizontalLayout1->addWidget(indietroPushButton);
    horizontalLayout1->addWidget(PCBuilder_ListaComponentiLabel);

    gridLayout->addWidget(componenteLabel,0,0,1,1);
    gridLayout->addWidget(produttoreLabel,0,1,1,1);
    gridLayout->addWidget(prezzoLabel,0,2,1,1);


    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(gridLayout);

    connect(signalMapper,SIGNAL(mapped(const QString&)),this,SIGNAL(sendMessage(const QString&)));

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

QGridLayout* MyWidget_PartsListPCBuilder::getGridLayout() const{
    return gridLayout;
}

QSignalMapper* MyWidget_PartsListPCBuilder::getSignalMapper() const{
    return signalMapper;
}

void MyWidget_PartsListPCBuilder::addComponent(const QString& nome, const QString& produttore, double prezzo){
    QFont form_font;
    form_font.setPointSize(14);
    QLabel* nomeLabel=new QLabel(nome);
    nomeLabel->setFont(form_font);
    nomeLabel->setMinimumSize(QSize(0,0));
    QLabel* produttoreLabel=new QLabel(produttore);
    produttoreLabel->setFont(form_font);
    produttoreLabel->setMinimumSize(QSize(0,0));
    QLabel* prezzoLabel=new QLabel("€ "+(QString::number(prezzo)));
    prezzoLabel->setFont(form_font);
    prezzoLabel->setMinimumSize(QSize(0,0));
    QPushButton* aggiungiPushButton=new QPushButton(tr("Aggiungi"));
    aggiungiPushButton->setMaximumSize(QSize(150,50));
    aggiungiPushButton->setMinimumSize(QSize(0,0));
    connect(aggiungiPushButton,SIGNAL(clicked()),signalMapper,SLOT(map()));
    signalMapper->setMapping(aggiungiPushButton,nome);
    this->gridLayout->addWidget(nomeLabel,row,0,1,1);
    this->gridLayout->addWidget(produttoreLabel,row,1,1,1);
    this->gridLayout->addWidget(prezzoLabel,row,2,1,1);
    this->gridLayout->addWidget(aggiungiPushButton,row,3,1,1);
    row++;
}
