#ifndef DISSIPATOREPROCESSORESPECSWIDGET_H
#define DISSIPATOREPROCESSORESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class DissipatoreProcessoreSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* socketSupportatiLabel;
    QLabel* socketSupportatiValueLabel;
    QLabel* raffreddamentoALiquidoLabel;
    QLabel* raffreddamentoALiquidoValueLabel;
    QLabel* rpmVentolaLabel;
    QLabel* rpmVentolaValueLabel;
    QLabel* altezzaLabel;
    QLabel* altezzaValueLabel;
    QLabel* altezzaRadiatoreLabel;
    QLabel* altezzaRadiatoreValueLabel;
    QLabel* livelloRumoreLabel;
    QLabel* livelloRumoreValueLabel;
public:
    DissipatoreProcessoreSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setSocketSupportatiValueLabel(const QString&);
    void setRaffreddamentoALiquidoValueLabel(const QString&);
    void setRpmVentolaValueLabel(const QString&);
    void setAltezzaValueLabel(const QString&);
    void setAltezzaRadiatoreValueLabel(const QString&);
    void setLivelloRumoreValueLabel(const QString&);
};

#endif // DISSIPATOREPROCESSORESPECSWIDGET_H
