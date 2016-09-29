#ifndef CUFFIESPECSWIDGET_H
#define CUFFIESPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class CuffieSpecsWidget:public QWidget{
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
    QLabel* sistemaAcusticoLabel;
    QLabel* sistemaAcusticoValueLabel;
    QLabel* coloreLabel;
    QLabel* coloreValueLabel;
    QLabel* microfonoLabel;
    QLabel* microfonoValueLabel;
    QLabel* canaliLabel;
    QLabel* canaliValueLabel;
    QLabel* impedenzaLabel;
    QLabel* impedenzaValueLabel;
    QLabel* frequenzaDiRispostaLabel;
    QLabel* frequenzaDiRispostaValueLabel;
    QLabel* connessioneLabel;
    QLabel* connessioneValueLabel;
    QLabel* connettoreLabel;
    QLabel* connettoreValueLabel;
public:
    CuffieSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setTipologiaValueLabel(const QString&);
    void setSistemaAcusticoValueLabel(const QString&);
    void setColoreValueLabel(const QString&);
    void setMicrofonoValueLabel(const QString&);
    void setCanaliValueLabel(const QString&);
    void setImpedenzaValueLabel(const QString&);
    void setFrequenzaDiRispostaValueLabel(const QString&);
    void setConnessioneValueLabel(const QString&);
    void setConnettoreValueLabel(const QString&);
};

#endif // CUFFIESPECSWIDGET_H
