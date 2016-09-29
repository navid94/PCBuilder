#ifndef UNITAOTTICASPECSWIDGET_H
#define UNITAOTTICASPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class UnitaOtticaSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* fattoreDiFormaLabel;
    QLabel* fattoreDiFormaValueLabel;
    QLabel* interfacciaLabel;
    QLabel* interfacciaValueLabel;
    QLabel* cacheLabel;
    QLabel* cacheValueLabel;
    QLabel* velocitaLabel;
    QLabel* velocitaValueLabel;
public:
    UnitaOtticaSpecsWidget(QWidget* =0);
    void createLabels();
    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setFattoreDiFormaValueLabel(const QString&);
    void setInterfacciaValueLabel(const QString&);
    void setCacheValueLabel(const QString&);
    void setVelocitaValueLabel(const QString&);
};

#endif // UNITAOTTICASPECSWIDGET_H
