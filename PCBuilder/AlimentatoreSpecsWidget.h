#ifndef ALIMENTATORESPECSWIDGET_H
#define ALIMENTATORESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class AlimentatoreSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* tipologiaLabel;
    QLabel* tipologiaValueLabel;
    QLabel* wattaggioLabel;
    QLabel* wattaggioValueLabel;
    QLabel* modulareLabel;
    QLabel* modulareValueLabel;
    QLabel* certificazioneDiEfficienzaLabel;
    QLabel* certificazioneDiEfficienzaValueLabel;
    QLabel* efficienzaLabel;
    QLabel* efficienzaValueLabel;
public:
    AlimentatoreSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setTipologiaValueLabel(const QString&);
    void setWattaggioValueLabel(const QString&);
    void setModulareValueLabel(const QString&);
    void setCertificazioneDiEfficienzaValueLabel(const QString&);
    void setEfficienzaValueLabel(const QString&);
};

#endif // ALIMENTATORESPECSWIDGET_H
