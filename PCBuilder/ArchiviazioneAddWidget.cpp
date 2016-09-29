#include "ArchiviazioneAddWidget.h"
#include <QFont>
#include <QLayout>

ArchiviazioneAddWidget::ArchiviazioneAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelArchiviazione,0,0,1,1);
    gridLayout->addWidget(nomeLineEditArchiviazione,0,1,1,1);
    gridLayout->addWidget(prezzoLabelArchiviazione,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxArchiviazione,1,1,1,1);
    gridLayout->addWidget(produttoreLabelArchiviazione,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditArchiviazione,2,1,1,1);
    gridLayout->addWidget(tipologiaLabelArchiviazione,3,0,1,1);
    gridLayout->addWidget(tipologiaLineEditArchiviazione,3,1,1,1);
    gridLayout->addWidget(capacitaLabelArchiviazione,4,0,1,1);
    gridLayout->addWidget(capacitaLineEditArchiviazione,4,1,1,1);
    gridLayout->addWidget(interfacciaLabelArchiviazione,5,0,1,1);
    gridLayout->addWidget(interfacciaLineEditArchiviazione,5,1,1,1);
    gridLayout->addWidget(cacheLabelArchiviazione,6,0,1,1);
    gridLayout->addWidget(cacheLineEditArchiviazione,6,1,1,1);
    gridLayout->addWidget(fattoreDiFormaLabelArchiviazione,7,0,1,1);
    gridLayout->addWidget(fattoreDiFormaLineEditArchiviazione,7,1,1,1);
    gridLayout->addWidget(rpmLabelArchiviazione,8,0,1,1);
    gridLayout->addWidget(rpmLineEditArchiviazione,8,1,1,1);
    setLayout(gridLayout);
}

void ArchiviazioneAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelArchiviazione=new QLabel(tr("Nome:"));
    nomeLabelArchiviazione->setFont(font_formLabel);
    nomeLabelArchiviazione->setMaximumSize(QSize(70,30));
    nomeLabelArchiviazione->setMinimumSize(QSize(0,0));

    prezzoLabelArchiviazione=new QLabel(tr("Prezzo:"));
    prezzoLabelArchiviazione->setFont(font_formLabel);
    prezzoLabelArchiviazione->setMaximumSize(QSize(80,30));
    prezzoLabelArchiviazione->setMinimumSize(QSize(0,0));

    produttoreLabelArchiviazione=new QLabel(tr("Produttore:"));
    produttoreLabelArchiviazione->setFont(font_formLabel);
    produttoreLabelArchiviazione->setMaximumSize(QSize(110,30));
    produttoreLabelArchiviazione->setMinimumSize(QSize(0,0));

    tipologiaLabelArchiviazione=new QLabel(tr("Tipologia:"));
    tipologiaLabelArchiviazione->setFont(font_formLabel);
    tipologiaLabelArchiviazione->setMaximumSize(QSize(90,30));
    tipologiaLabelArchiviazione->setMinimumSize(QSize(0,0));

    capacitaLabelArchiviazione=new QLabel(tr("Capacità:"));
    capacitaLabelArchiviazione->setFont(font_formLabel);
    capacitaLabelArchiviazione->setMaximumSize(QSize(90,30));
    capacitaLabelArchiviazione->setMinimumSize(QSize(0,0));

    interfacciaLabelArchiviazione=new QLabel(tr("Interfaccia:"));
    interfacciaLabelArchiviazione->setFont(font_formLabel);
    interfacciaLabelArchiviazione->setMaximumSize(QSize(110,30));
    interfacciaLabelArchiviazione->setMinimumSize(QSize(0,0));

    cacheLabelArchiviazione=new QLabel("Cache");
    cacheLabelArchiviazione->setFont(font_formLabel);
    cacheLabelArchiviazione->setMaximumSize(QSize(70,30));
    cacheLabelArchiviazione->setMinimumSize(QSize(0,0));

    fattoreDiFormaLabelArchiviazione=new QLabel(tr("Fattore di forma:"));
    fattoreDiFormaLabelArchiviazione->setFont(font_formLabel);
    fattoreDiFormaLabelArchiviazione->setMaximumSize(QSize(160,30));
    fattoreDiFormaLabelArchiviazione->setMinimumSize(QSize(0,0));

    rpmLabelArchiviazione=new QLabel("RPM:");
    rpmLabelArchiviazione->setFont(font_formLabel);
    rpmLabelArchiviazione->setMaximumSize(QSize(50,30));
    rpmLabelArchiviazione->setMinimumSize(QSize(0,0));
}

void ArchiviazioneAddWidget::createLineEdits(){
    nomeLineEditArchiviazione=new QLineEdit;
    nomeLineEditArchiviazione->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditArchiviazione->setMaximumSize(QSize(200,30));
    nomeLineEditArchiviazione->setMinimumSize(QSize(0,0));

    produttoreLineEditArchiviazione=new QLineEdit;
    produttoreLineEditArchiviazione->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditArchiviazione->setMaximumSize(QSize(200,30));
    produttoreLineEditArchiviazione->setMinimumSize(QSize(0,0));

    tipologiaLineEditArchiviazione=new QLineEdit;
    tipologiaLineEditArchiviazione->setPlaceholderText(tr("Inserire tipologia"));
    tipologiaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    tipologiaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    capacitaLineEditArchiviazione=new QLineEdit;
    capacitaLineEditArchiviazione->setPlaceholderText(tr("Inserire capacità"));
    capacitaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    capacitaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    interfacciaLineEditArchiviazione=new QLineEdit;
    interfacciaLineEditArchiviazione->setPlaceholderText(tr("Inserire interfaccia"));
    interfacciaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    interfacciaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    cacheLineEditArchiviazione=new QLineEdit;
    cacheLineEditArchiviazione->setPlaceholderText(tr("Inserire cache"));
    cacheLineEditArchiviazione->setMaximumSize(QSize(200,30));
    cacheLineEditArchiviazione->setMinimumSize(QSize(0,0));

    fattoreDiFormaLineEditArchiviazione=new QLineEdit;
    fattoreDiFormaLineEditArchiviazione->setPlaceholderText(tr("Inserire fattore di forma"));
    fattoreDiFormaLineEditArchiviazione->setMaximumSize(QSize(200,30));
    fattoreDiFormaLineEditArchiviazione->setMinimumSize(QSize(0,0));

    rpmLineEditArchiviazione=new QLineEdit;
    rpmLineEditArchiviazione->setPlaceholderText(tr("Inserire RPM"));
    rpmLineEditArchiviazione->setMaximumSize(QSize(200,30));
    rpmLineEditArchiviazione->setMinimumSize(QSize(0,0));
}

void ArchiviazioneAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxArchiviazione=new QDoubleSpinBox;
    prezzoDoubleSpinBoxArchiviazione->setSuffix(" €");
    prezzoDoubleSpinBoxArchiviazione->setMaximum(9999.99);
    prezzoDoubleSpinBoxArchiviazione->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxArchiviazione->setMinimumSize(QSize(0,0));
}

QString ArchiviazioneAddWidget::nomeArchiviazioneValue() const{
    return nomeLineEditArchiviazione->text();
}

QString ArchiviazioneAddWidget::produttoreArchiviazioneValue() const{
    return produttoreLineEditArchiviazione->text();
}

QString ArchiviazioneAddWidget::tipologiaArchiviazioneValue() const{
    return tipologiaLineEditArchiviazione->text();
}

QString ArchiviazioneAddWidget::capacitaArchiviazioneValue() const{
    return capacitaLineEditArchiviazione->text();
}

QString ArchiviazioneAddWidget::interfacciaArchiviazioneValue() const{
    return interfacciaLineEditArchiviazione->text();
}

QString ArchiviazioneAddWidget::cacheArchiviazioneValue() const{
    return cacheLineEditArchiviazione->text();
}

QString ArchiviazioneAddWidget::fattoreDiFormaArchiviazioneValue() const{
    return fattoreDiFormaLineEditArchiviazione->text();
}

QString ArchiviazioneAddWidget::rpmArchiviazioneValue() const{
    return rpmLineEditArchiviazione->text();
}

double ArchiviazioneAddWidget::prezzoArchiviazioneValue() const{
    return prezzoDoubleSpinBoxArchiviazione->value();
}

QLineEdit* ArchiviazioneAddWidget::getNomeLineEditArchiviazione() const
{
    return nomeLineEditArchiviazione;
}

QLineEdit* ArchiviazioneAddWidget::getProduttoreLineEditArchiviazione() const
{
    return produttoreLineEditArchiviazione;
}

QLineEdit* ArchiviazioneAddWidget::getTipologiaLineEditArchiviazione() const{
    return tipologiaLineEditArchiviazione;
}

QLineEdit* ArchiviazioneAddWidget::getCapacitaLineEditArchiviazione() const{
    return capacitaLineEditArchiviazione;
}

QLineEdit* ArchiviazioneAddWidget::getInterfacciaLineEditArchiviazione() const{
    return interfacciaLineEditArchiviazione;
}

QLineEdit* ArchiviazioneAddWidget::getCacheLineEditArchiviazione() const{
    return cacheLineEditArchiviazione;
}

QLineEdit* ArchiviazioneAddWidget::getFattoreDiFormaLineEditArchiviazione() const{
    return fattoreDiFormaLineEditArchiviazione;
}

QLineEdit* ArchiviazioneAddWidget::getRpmLineEditArchiviazione() const{
    return rpmLineEditArchiviazione;
}

QDoubleSpinBox* ArchiviazioneAddWidget::getPrezzoDoubleSpinBoxArchiviazione() const{
    return prezzoDoubleSpinBoxArchiviazione;
}
