#include "DissipatoreProcessoreSpecsWidget.h"
#include <QLayout>
#include <QFont>

DissipatoreProcessoreSpecsWidget::DissipatoreProcessoreSpecsWidget(QWidget* parent):QWidget(parent){
    createLabels();

    QGridLayout* gridLayout=new QGridLayout;
    gridLayout->setContentsMargins(200,75,0,25);

    gridLayout->addWidget(nomeLabel,0,0,1,1);
    gridLayout->addWidget(nomeValueLabel,0,1,1,1);
    gridLayout->addWidget(produttoreLabel,1,0,1,1);
    gridLayout->addWidget(produttoreValueLabel,1,1,1,1);
    gridLayout->addWidget(prezzoLabel,2,0,1,1);
    gridLayout->addWidget(prezzoValueLabel,2,1,1,1);
    gridLayout->addWidget(socketSupportatiLabel,3,0,1,1);
    gridLayout->addWidget(socketSupportatiValueLabel,3,1,1,1);
    gridLayout->addWidget(raffreddamentoALiquidoLabel,4,0,1,1);
    gridLayout->addWidget(raffreddamentoALiquidoValueLabel,4,1,1,1);
    gridLayout->addWidget(rpmVentolaLabel,5,0,1,1);
    gridLayout->addWidget(rpmVentolaValueLabel,5,1,1,1);
    gridLayout->addWidget(altezzaLabel,6,0,1,1);
    gridLayout->addWidget(altezzaValueLabel,6,1,1,1);
    gridLayout->addWidget(altezzaRadiatoreLabel,7,0,1,1);
    gridLayout->addWidget(altezzaRadiatoreValueLabel,7,1,1,1);
    gridLayout->addWidget(livelloRumoreLabel,8,0,1,1);
    gridLayout->addWidget(livelloRumoreValueLabel,8,1,1,1);

    setLayout(gridLayout);
}

void DissipatoreProcessoreSpecsWidget::createLabels(){
    QFont font_form;
    font_form.setPointSize(14);

    nomeLabel=new QLabel(tr("Nome"));
    nomeLabel->setMinimumSize(QSize(0,0));
    nomeLabel->setFont(font_form);

    nomeValueLabel=new QLabel("");
    nomeValueLabel->setMinimumSize(QSize(0,0));
    nomeValueLabel->setFont(font_form);
    nomeValueLabel->setWordWrap(true);

    produttoreLabel=new QLabel(tr("Produttore"));
    produttoreLabel->setMinimumSize(QSize(0,0));
    produttoreLabel->setFont(font_form);

    produttoreValueLabel=new QLabel("");
    produttoreValueLabel->setMinimumSize(QSize(0,0));
    produttoreValueLabel->setFont(font_form);
    produttoreValueLabel->setWordWrap(true);

    prezzoLabel=new QLabel(tr("Prezzo"));
    prezzoLabel->setMinimumSize(QSize(0,0));
    prezzoLabel->setFont(font_form);

    prezzoValueLabel=new QLabel("");
    prezzoValueLabel->setMinimumSize(QSize(0,0));
    prezzoValueLabel->setFont(font_form);
    prezzoValueLabel->setWordWrap(true);

    socketSupportatiLabel=new QLabel(tr("Socket supportati"));
    socketSupportatiLabel->setMinimumSize(QSize(0,0));
    socketSupportatiLabel->setFont(font_form);

    socketSupportatiValueLabel=new QLabel("");
    socketSupportatiValueLabel->setMinimumSize(QSize(0,0));
    socketSupportatiValueLabel->setFont(font_form);
    socketSupportatiValueLabel->setWordWrap(true);

    raffreddamentoALiquidoLabel=new QLabel(tr("Raffreddamento a liquido"));
    raffreddamentoALiquidoLabel->setMinimumSize(QSize(0,0));
    raffreddamentoALiquidoLabel->setFont(font_form);

    raffreddamentoALiquidoValueLabel=new QLabel("");
    raffreddamentoALiquidoValueLabel->setMinimumSize(QSize(0,0));
    raffreddamentoALiquidoValueLabel->setFont(font_form);
    raffreddamentoALiquidoValueLabel->setWordWrap(true);

    rpmVentolaLabel=new QLabel(tr("RPM ventola"));
    rpmVentolaLabel->setMinimumSize(QSize(0,0));
    rpmVentolaLabel->setFont(font_form);

    rpmVentolaValueLabel=new QLabel("");
    rpmVentolaValueLabel->setMinimumSize(QSize(0,0));
    rpmVentolaValueLabel->setFont(font_form);
    rpmVentolaValueLabel->setWordWrap(true);

    altezzaLabel=new QLabel(tr("Altezza"));
    altezzaLabel->setMinimumSize(QSize(0,0));
    altezzaLabel->setFont(font_form);

    altezzaValueLabel=new QLabel("");
    altezzaValueLabel->setMinimumSize(QSize(0,0));
    altezzaValueLabel->setFont(font_form);
    altezzaValueLabel->setWordWrap(true);

    altezzaRadiatoreLabel=new QLabel(tr("Altezza radiatore"));
    altezzaRadiatoreLabel->setMinimumSize(QSize(0,0));
    altezzaRadiatoreLabel->setFont(font_form);

    altezzaRadiatoreValueLabel=new QLabel("");
    altezzaRadiatoreValueLabel->setMinimumSize(QSize(0,0));
    altezzaRadiatoreValueLabel->setFont(font_form);
    altezzaRadiatoreValueLabel->setWordWrap(true);

    livelloRumoreLabel=new QLabel(tr("Livello rumore"));
    livelloRumoreLabel->setMinimumSize(QSize(0,0));
    livelloRumoreLabel->setFont(font_form);

    livelloRumoreValueLabel=new QLabel("");
    livelloRumoreValueLabel->setMinimumSize(QSize(0,0));
    livelloRumoreValueLabel->setFont(font_form);
    livelloRumoreValueLabel->setWordWrap(true);
}

void DissipatoreProcessoreSpecsWidget::setNomeValueLabel(const QString& nome){
    nomeValueLabel->setText(nome);
}

void DissipatoreProcessoreSpecsWidget::setProduttoreValueLabel(const QString& produttore){
    produttoreValueLabel->setText(produttore);
}

void DissipatoreProcessoreSpecsWidget::setPrezzoValueLabel(const QString& prezzo){
    prezzoValueLabel->setText(prezzo);
}

void DissipatoreProcessoreSpecsWidget::setSocketSupportatiValueLabel(const QString& socketSupportati){
    socketSupportatiValueLabel->setText(socketSupportati);
}

void DissipatoreProcessoreSpecsWidget::setRaffreddamentoALiquidoValueLabel(const QString& raffreddamentoALiquido){
    raffreddamentoALiquidoValueLabel->setText(raffreddamentoALiquido);
}

void DissipatoreProcessoreSpecsWidget::setRpmVentolaValueLabel(const QString& rpmVentola){
    rpmVentolaValueLabel->setText(rpmVentola);
}

void DissipatoreProcessoreSpecsWidget::setAltezzaValueLabel(const QString& altezza){
    altezzaValueLabel->setText(altezza);
}

void DissipatoreProcessoreSpecsWidget::setAltezzaRadiatoreValueLabel(const QString& altezzaRadiatore){
    altezzaRadiatoreValueLabel->setText(altezzaRadiatore);
}

void DissipatoreProcessoreSpecsWidget::setLivelloRumoreValueLabel(const QString& livelloRumore){
    livelloRumoreValueLabel->setText(livelloRumore);
}
