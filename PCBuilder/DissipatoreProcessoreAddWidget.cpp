#include "DissipatoreProcessoreAddWidget.h"
#include <QFont>
#include <QLayout>

DissipatoreProcessoreAddWidget::DissipatoreProcessoreAddWidget(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createCheckBoxes();
    createDoubleSpinBoxes();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->addWidget(nomeLabelDissipatoreProcessore,0,0,1,1);
    gridLayout->addWidget(nomeLineEditDissipatoreProcessore,0,1,1,1);
    gridLayout->addWidget(prezzoLabelDissipatoreProcessore,1,0,1,1);
    gridLayout->addWidget(prezzoDoubleSpinBoxDissipatoreProcessore,1,1,1,1);
    gridLayout->addWidget(produttoreLabelDissipatoreProcessore,2,0,1,1);
    gridLayout->addWidget(produttoreLineEditDissipatoreProcessore,2,1,1,1);
    gridLayout->addWidget(socketSupportatiLabelDissipatoreProcessore,3,0,1,1);
    gridLayout->addWidget(socketSupportatiLineEditDissipatoreProcessore,3,1,1,1);
    gridLayout->addWidget(rpmVentolaLabelDissipatoreProcessore,4,0,1,1);
    gridLayout->addWidget(rpmVentolaLineEditDissipatoreProcessore,4,1,1,1);
    gridLayout->addWidget(altezzaLabelDissipatoreProcessore,5,0,1,1);
    gridLayout->addWidget(altezzaLineEditDissipatoreProcessore,5,1,1,1);
    gridLayout->addWidget(raffreddamentoALiquidoCheckBoxDissipatoreProcessore,6,1,1,1);
    gridLayout->addWidget(altezzaRadiatoreLabelDissipatoreProcessore,7,0,1,1);
    gridLayout->addWidget(altezzaRadiatoreLineEditDissipatoreProcessore,7,1,1,1);
    gridLayout->addWidget(livelloRumoreLabelDissipatoreProcessore,8,0,1,1);
    gridLayout->addWidget(livelloRumoreLineEditDissipatoreProcessore,8,1,1,1);
    setLayout(gridLayout);
}

void DissipatoreProcessoreAddWidget::createLabels(){
    QFont font_formLabel;
    font_formLabel.setPointSize(14);

    nomeLabelDissipatoreProcessore=new QLabel(tr("Nome:"));
    nomeLabelDissipatoreProcessore->setFont(font_formLabel);
    nomeLabelDissipatoreProcessore->setMaximumSize(QSize(70,30));
    nomeLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    prezzoLabelDissipatoreProcessore=new QLabel(tr("Prezzo:"));
    prezzoLabelDissipatoreProcessore->setFont(font_formLabel);
    prezzoLabelDissipatoreProcessore->setMaximumSize(QSize(80,30));
    prezzoLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    produttoreLabelDissipatoreProcessore=new QLabel(tr("Produttore:"));
    produttoreLabelDissipatoreProcessore->setFont(font_formLabel);
    produttoreLabelDissipatoreProcessore->setMaximumSize(QSize(110,30));
    produttoreLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    socketSupportatiLabelDissipatoreProcessore=new QLabel("Socket "+(tr("supportati:")));
    socketSupportatiLabelDissipatoreProcessore->setFont(font_formLabel);
    socketSupportatiLabelDissipatoreProcessore->setMaximumSize(QSize(180,30));
    socketSupportatiLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    rpmVentolaLabelDissipatoreProcessore=new QLabel("RPM "+(tr("ventola:")));
    rpmVentolaLabelDissipatoreProcessore->setFont(font_formLabel);
    rpmVentolaLabelDissipatoreProcessore->setMaximumSize(QSize(130,30));
    rpmVentolaLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaLabelDissipatoreProcessore=new QLabel(tr("Altezza:"));
    altezzaLabelDissipatoreProcessore->setFont(font_formLabel);
    altezzaLabelDissipatoreProcessore->setMaximumSize(QSize(80,30));
    altezzaLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaRadiatoreLabelDissipatoreProcessore=new QLabel(tr("Altezza radiatore:"));
    altezzaRadiatoreLabelDissipatoreProcessore->setFont(font_formLabel);
    altezzaRadiatoreLabelDissipatoreProcessore->setMaximumSize(QSize(170,30));
    altezzaRadiatoreLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

    livelloRumoreLabelDissipatoreProcessore=new QLabel(tr("Livello rumore:"));
    livelloRumoreLabelDissipatoreProcessore->setFont(font_formLabel);
    livelloRumoreLabelDissipatoreProcessore->setMaximumSize(QSize(150,30));
    livelloRumoreLabelDissipatoreProcessore->setMinimumSize(QSize(0,0));

}

void DissipatoreProcessoreAddWidget::createLineEdits(){
    nomeLineEditDissipatoreProcessore=new QLineEdit;
    nomeLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire nome"));
    nomeLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    nomeLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    produttoreLineEditDissipatoreProcessore=new QLineEdit;
    produttoreLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire produttore"));
    produttoreLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    produttoreLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    socketSupportatiLineEditDissipatoreProcessore=new QLineEdit;
    socketSupportatiLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire socket supportati"));
    socketSupportatiLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    socketSupportatiLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    rpmVentolaLineEditDissipatoreProcessore=new QLineEdit;
    rpmVentolaLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire rpm ventola"));
    rpmVentolaLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    rpmVentolaLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaLineEditDissipatoreProcessore=new QLineEdit;
    altezzaLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire altezza"));
    altezzaLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    altezzaLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    altezzaRadiatoreLineEditDissipatoreProcessore=new QLineEdit;
    altezzaRadiatoreLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire altezza radiatore"));
    altezzaRadiatoreLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    altezzaRadiatoreLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));

    livelloRumoreLineEditDissipatoreProcessore=new QLineEdit;
    livelloRumoreLineEditDissipatoreProcessore->setPlaceholderText(tr("Inserire livello rumore"));
    livelloRumoreLineEditDissipatoreProcessore->setMaximumSize(QSize(200,30));
    livelloRumoreLineEditDissipatoreProcessore->setMinimumSize(QSize(0,0));
}

void DissipatoreProcessoreAddWidget::createDoubleSpinBoxes(){
    prezzoDoubleSpinBoxDissipatoreProcessore=new QDoubleSpinBox;
    prezzoDoubleSpinBoxDissipatoreProcessore->setSuffix(" €");
    prezzoDoubleSpinBoxDissipatoreProcessore->setMaximum(9999.99);
    prezzoDoubleSpinBoxDissipatoreProcessore->setMaximumSize(QSize(90,25));
    prezzoDoubleSpinBoxDissipatoreProcessore->setMinimumSize(QSize(0,0));
}

void DissipatoreProcessoreAddWidget::createCheckBoxes(){
    raffreddamentoALiquidoCheckBoxDissipatoreProcessore=new QCheckBox(tr("Raffreddamento a liquido"));
    raffreddamentoALiquidoCheckBoxDissipatoreProcessore->setMaximumSize(QSize(180,30));
    raffreddamentoALiquidoCheckBoxDissipatoreProcessore->setMinimumSize(QSize(0,0));
}


QString DissipatoreProcessoreAddWidget::nomeDissipatoreProcessoreValue() const{
    return nomeLineEditDissipatoreProcessore->text();
}

QString DissipatoreProcessoreAddWidget::produttoreDissipatoreProcessoreValue() const{
    return produttoreLineEditDissipatoreProcessore->text();
}

QString DissipatoreProcessoreAddWidget::socketSupportatiDissipatoreProcessoreValue() const{
    return socketSupportatiLineEditDissipatoreProcessore->text();
}

QString DissipatoreProcessoreAddWidget::rpmVentolaDissipatoreProcessoreValue() const{
    return rpmVentolaLineEditDissipatoreProcessore->text();
}

QString DissipatoreProcessoreAddWidget::altezzaDissipatoreProcessoreValue() const{
    return altezzaLineEditDissipatoreProcessore->text();
}

QString DissipatoreProcessoreAddWidget::altezzaRadiatoreDissipatoreProcessoreValue() const{
    return altezzaRadiatoreLineEditDissipatoreProcessore->text();
}

QString DissipatoreProcessoreAddWidget::livelloRumoreDissipatoreProcessoreValue() const{
    return livelloRumoreLineEditDissipatoreProcessore->text();
}

bool DissipatoreProcessoreAddWidget::raffreddamentoALiquidoDissipatoreProcessoreValue() const{
    return raffreddamentoALiquidoCheckBoxDissipatoreProcessore->isChecked();
}

double DissipatoreProcessoreAddWidget::prezzoDissipatoreProcessoreValue() const{
    return prezzoDoubleSpinBoxDissipatoreProcessore->value();
}

QLineEdit* DissipatoreProcessoreAddWidget::getNomeLineEditDissipatoreProcessore() const{
    return nomeLineEditDissipatoreProcessore;
}

QLineEdit* DissipatoreProcessoreAddWidget::getProduttoreLineEditDissipatoreProcessore() const{
    return produttoreLineEditDissipatoreProcessore;
}

QLineEdit* DissipatoreProcessoreAddWidget::getSocketSupportatiLineEditDissipatoreProcessore() const{
    return socketSupportatiLineEditDissipatoreProcessore;
}

QLineEdit* DissipatoreProcessoreAddWidget::getRpmVentolaLineEditDissipatoreProcessore() const{
    return rpmVentolaLineEditDissipatoreProcessore;
}

QLineEdit* DissipatoreProcessoreAddWidget::getAltezzaLineEditDissipatoreProcessore() const{
    return altezzaLineEditDissipatoreProcessore;
}

QLineEdit* DissipatoreProcessoreAddWidget::getAltezzaRadiatoreLineEditDissipatoreProcessore() const{
    return altezzaRadiatoreLineEditDissipatoreProcessore;
}

QLineEdit* DissipatoreProcessoreAddWidget::getLivelloRumoreLineEditDissipatoreProcessore() const{
    return livelloRumoreLineEditDissipatoreProcessore;
}

QCheckBox* DissipatoreProcessoreAddWidget::getRaffreddamentoALiquidoCheckBoxDissipatoreProcessore() const{
    return raffreddamentoALiquidoCheckBoxDissipatoreProcessore;
}

QDoubleSpinBox* DissipatoreProcessoreAddWidget::getPrezzoDoubleSpinBoxDissipatoreProcessore() const{
    return prezzoDoubleSpinBoxDissipatoreProcessore;
}
