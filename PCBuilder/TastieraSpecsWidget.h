#ifndef TASTIERASPECSWIDGET_H
#define TASTIERASPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class TastieraSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* coloreLabel;
    QLabel* coloreValueLabel;
    QLabel* retroilluminazioneLabel;
    QLabel* retroilluminazioneValueLabel;
    QLabel* connessioneLabel;
    QLabel* connessioneValueLabel;
    QLabel* tipologiaLabel;
    QLabel* tipologiaValueLabel;
    QLabel* tipologiaSwitchLabel;
    QLabel* tipologiaSwitchValueLabel;
public:
    TastieraSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setColoreValueLabel(const QString&);
    void setRetroilluminazioneValueLabel(const QString&);
    void setConnessioneValueLabel(const QString&);
    void setTipologiaValueLabel(const QString&);
    void setTipologiaSwitchValueLabel(const QString&);
};

#endif // TASTIERASPECSWIDGET_H
