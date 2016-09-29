#ifndef MEMORIASPECSWIDGET_H
#define MEMORIASPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class MemoriaSpecsWidget:public QWidget{
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
    QLabel* capacitaLabel;
    QLabel* capacitaValueLabel;
    QLabel* velocitaLabel;
    QLabel* velocitaValueLabel;
    QLabel* latenzaLabel;
    QLabel* latenzaValueLabel;
public:
    MemoriaSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setTipologiaValueLabel(const QString&);
    void setCapacitaValueLabel(const QString&);
    void setVelocitaValueLabel(const QString&);
    void setLatenzaValueLabel(const QString&);
};

#endif // MEMORIASPECSWIDGET_H
