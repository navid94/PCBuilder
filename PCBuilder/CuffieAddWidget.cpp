#include "CuffieAddWidget.h"

#include <QLayout>
#include <QFont>

CuffieAddWidget::CuffieAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createCheckBoxes();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelCuffie,0,0,1,1);
    gridLayout->addWidget(nomeLineEditCuffie,0,1,1,1);
    gridLayout->addWidget(prezzoLabelCuffie,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxCuffie,1,1,1,1);
    gridLayout->addWidget(produttoreLabelCuffie,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditCuffie,2,1,1,1);
    gridLayout->addWidget(tipologiaLabelCuffie,3,0,1,1);
    gridLayout->addWidget(tipologiaLineEditCuffie,3,1,1,1);
    gridLayout->addWidget(sistemaAcusticoLabelCuffie,4,0,1,1);
    gridLayout->addWidget(sistemaAcusticoLineEditCuffie,4,1,1,1);
    gridLayout->addWidget(coloreLabelCuffie,5,0,1,1);
    gridLayout->addWidget(coloreLineEditCuffie,5,1,1,1);
    gridLayout->addWidget(canaliLabelCuffie,6,0,1,1);
    gridLayout->addWidget(canaliLineEditCuffie,6,1,1,1);
    gridLayout->addWidget(impedenzaLabelCuffie,7,0,1,1);
    gridLayout->addWidget(impedenzaLineEditCuffie,7,1,1,1);
    gridLayout->addWidget(frequenzaDiRispostaLabelCuffie,8,0,1,1);
    gridLayout->addWidget(frequenzaDiRispostaLineEditCuffie,8,1,1,1);
    gridLayout->addWidget(microfonoCheckBoxCuffie,9,1,1,1);
    gridLayout->addWidget(connessioneLabelCuffie,10,0,1,1);
    gridLayout->addWidget(connessioneLineEditCuffie,10,1,1,1);
    gridLayout->addWidget(connettoreLabelCuffie,11,0,1,1);
    gridLayout->addWidget(connettoreLineEditCuffie,11,1,1,1);
    setLayout(gridLayout);
}

void CuffieAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelCuffie=new QLabel(tr("Nome:"));
    nomeLabelCuffie->setFont(font_formLabel);
    nomeLabelCuffie->setMaximumSize(QSize(70,30));
    nomeLabelCuffie->setMinimumSize(QSize(0,0));

    prezzoLabelCuffie=new QLabel(tr("Prezzo:"));
    prezzoLabelCuffie->setFont(font_formLabel);
    prezzoLabelCuffie->setMaximumSize(QSize(80,30));
    prezzoLabelCuffie->setMinimumSize(QSize(0,0));

    produttoreLabelCuffie=new QLabel(tr("Produttore:"));
    produttoreLabelCuffie->setFont(font_formLabel);
    produttoreLabelCuffie->setMaximumSize(QSize(110,30));
    produttoreLabelCuffie->setMinimumSize(QSize(0,0));

    tipologiaLabelCuffie=new QLabel(tr("Tipologia:"));
    tipologiaLabelCuffie->setFont(font_formLabel);
    tipologiaLabelCuffie->setMaximumSize(QSize(90,30));
    tipologiaLabelCuffie->setMinimumSize(QSize(0,0));

    sistemaAcusticoLabelCuffie=new QLabel(tr("Sistema acustico:"));
    sistemaAcusticoLabelCuffie->setFont(font_formLabel);
    sistemaAcusticoLabelCuffie->setMaximumSize(QSize(170,30));
    sistemaAcusticoLabelCuffie->setMinimumSize(QSize(0,0));

    coloreLabelCuffie=new QLabel(tr("Colore:"));
    coloreLabelCuffie->setFont(font_formLabel);
    coloreLabelCuffie->setMaximumSize(QSize(70,30));
    coloreLabelCuffie->setMinimumSize(QSize(0,0));

    canaliLabelCuffie=new QLabel(tr("Canali:"));
    canaliLabelCuffie->setFont(font_formLabel);
    canaliLabelCuffie->setMaximumSize(QSize(70,30));
    canaliLabelCuffie->setMinimumSize(QSize(0,0));

    impedenzaLabelCuffie=new QLabel(tr("Impedenza:"));
    impedenzaLabelCuffie->setFont(font_formLabel);
    impedenzaLabelCuffie->setMaximumSize(QSize(120,30));
    impedenzaLabelCuffie->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLabelCuffie=new QLabel(tr("Frequenza di \nrisposta:"));
    frequenzaDiRispostaLabelCuffie->setFont(font_formLabel);
    frequenzaDiRispostaLabelCuffie->setMaximumSize(QSize(120,50));
    frequenzaDiRispostaLabelCuffie->setMinimumSize(QSize(0,0));

    connessioneLabelCuffie=new QLabel(tr("Connessione:"));
    connessioneLabelCuffie->setFont(font_formLabel);
    connessioneLabelCuffie->setMaximumSize(QSize(130,30));
    connessioneLabelCuffie->setMinimumSize(QSize(0,0));

    connettoreLabelCuffie=new QLabel(tr("Connettore:"));
    connettoreLabelCuffie->setFont(font_formLabel);
    connettoreLabelCuffie->setMaximumSize(QSize(120,30));
    connettoreLabelCuffie->setMinimumSize(QSize(0,0));
}

void CuffieAddWidget::createLineEdits(){
    nomeLineEditCuffie=new QLineEdit;
    nomeLineEditCuffie->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditCuffie->setMaximumSize(QSize(200,30));
    nomeLineEditCuffie->setMinimumSize(QSize(0,0));

    produttoreLineEditCuffie=new QLineEdit;
    produttoreLineEditCuffie->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditCuffie->setMaximumSize(QSize(200,30));
    produttoreLineEditCuffie->setMinimumSize(QSize(0,0));

    tipologiaLineEditCuffie=new QLineEdit;
    tipologiaLineEditCuffie->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditCuffie->setMaximumSize(QSize(200,30));
    tipologiaLineEditCuffie->setMinimumSize(QSize(0,0));

    sistemaAcusticoLineEditCuffie=new QLineEdit;
    sistemaAcusticoLineEditCuffie->setPlaceholderText(tr("Inserire sistema acustico"));
    sistemaAcusticoLineEditCuffie->setMaximumSize(QSize(200,30));
    sistemaAcusticoLineEditCuffie->setMinimumSize(QSize(0,0));

    coloreLineEditCuffie=new QLineEdit;
    coloreLineEditCuffie->setPlaceholderText(tr("Inserire colore"));
    coloreLineEditCuffie->setMaximumSize(QSize(200,30));
    coloreLineEditCuffie->setMinimumSize(QSize(0,0));

    canaliLineEditCuffie=new QLineEdit;
    canaliLineEditCuffie->setPlaceholderText(tr("Inserire canali"));
    canaliLineEditCuffie->setMaximumSize(QSize(200,30));
    canaliLineEditCuffie->setMinimumSize(QSize(0,0));

    impedenzaLineEditCuffie=new QLineEdit;
    impedenzaLineEditCuffie->setPlaceholderText(tr("Inserire impedenza"));
    impedenzaLineEditCuffie->setMaximumSize(QSize(200,30));
    impedenzaLineEditCuffie->setMinimumSize(QSize(0,0));

    frequenzaDiRispostaLineEditCuffie=new QLineEdit;
    frequenzaDiRispostaLineEditCuffie->setPlaceholderText(tr("Inserire frequenza di risposta"));
    frequenzaDiRispostaLineEditCuffie->setMaximumSize(QSize(200,30));
    frequenzaDiRispostaLineEditCuffie->setMinimumSize(QSize(0,0));

    connessioneLineEditCuffie=new QLineEdit;
    connessioneLineEditCuffie->setPlaceholderText(tr("Inserire connessione"));
    connessioneLineEditCuffie->setMaximumSize(QSize(200,30));
    connessioneLineEditCuffie->setMinimumSize(QSize(0,0));

    connettoreLineEditCuffie=new QLineEdit;
    connettoreLineEditCuffie->setPlaceholderText(tr("Inserire connettore"));
    connettoreLineEditCuffie->setMaximumSize(QSize(200,30));
    connettoreLineEditCuffie->setMinimumSize(QSize(0,0));
}

void CuffieAddWidget::createCheckBoxes(){
    microfonoCheckBoxCuffie=new QCheckBox(tr("Microfono"));
    microfonoCheckBoxCuffie->setMaximumSize(QSize(80,30));
    microfonoCheckBoxCuffie->setMinimumSize(QSize(0,0));
}

void CuffieAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxCuffie=new QDoubleSpinBox;
    prezzoDoubleSpinBoxCuffie->setSuffix(" €");
    prezzoDoubleSpinBoxCuffie->setMaximum(9999.99);
    prezzoDoubleSpinBoxCuffie->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxCuffie->setMinimumSize(QSize(0,0));
}

QString CuffieAddWidget::nomeCuffieValue() const{
    return nomeLineEditCuffie->text();
}

QString CuffieAddWidget::produttoreCuffieValue() const{
    return produttoreLineEditCuffie->text();
}

QString CuffieAddWidget::tipologiaCuffieValue() const{
    return tipologiaLineEditCuffie->text();
}

QString CuffieAddWidget::sistemaAcusticoCuffieValue() const{
    return sistemaAcusticoLineEditCuffie->text();
}

QString CuffieAddWidget::coloreCuffieValue() const{
    return coloreLineEditCuffie->text();
}

QString CuffieAddWidget::canaliCuffieValue() const{
    return canaliLineEditCuffie->text();
}

QString CuffieAddWidget::impedenzaCuffieValue() const{
    return impedenzaLineEditCuffie->text();
}

QString CuffieAddWidget::frequenzaDiRispostaCuffieValue() const{
    return frequenzaDiRispostaLineEditCuffie->text();
}

QString CuffieAddWidget::connessioneCuffieValue() const{
    return connessioneLineEditCuffie->text();
}

QString CuffieAddWidget::connettoreCuffieValue() const{
    return connettoreLineEditCuffie->text();
}

bool CuffieAddWidget::microfonoCuffieValue() const{
    return microfonoCheckBoxCuffie->isChecked();
}

double CuffieAddWidget::prezzoCuffieValue() const{
    return prezzoDoubleSpinBoxCuffie->value();
}

QLineEdit* CuffieAddWidget::getNomeLineEditCuffie() const{
    return nomeLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getProduttoreLineEditCuffie() const{
    return produttoreLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getTipologiaLineEditCuffie() const{
    return tipologiaLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getSistemaAcusticoLineEditCuffie() const{
    return sistemaAcusticoLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getColoreLineEditCuffie() const{
    return coloreLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getCanaliLineEditCuffie() const{
    return canaliLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getImpedenzaLineEditCuffie() const{
    return impedenzaLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getFrequenzaDiRispostaLineEditCuffie() const{
    return frequenzaDiRispostaLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getConnessioneLineEditCuffie() const{
    return connessioneLineEditCuffie;
}

QLineEdit* CuffieAddWidget::getConnettoreLineEditCuffie() const{
    return connettoreLineEditCuffie;
}

QCheckBox* CuffieAddWidget::getMicrofonoCheckBoxCuffie() const{
    return microfonoCheckBoxCuffie;
}

QDoubleSpinBox* CuffieAddWidget::getPrezzoDoubleSpinBoxCuffie() const{
    return prezzoDoubleSpinBoxCuffie;
}
