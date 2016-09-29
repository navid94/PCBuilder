#ifndef SISTEMAOPERATIVOSPECSWIDGET_H
#define SISTEMAOPERATIVOSPECSWIDGET_H

#include <QWidget>
#include <QLabel>

class SistemaOperativoSpecsWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabel;
    QLabel* nomeValueLabel;
    QLabel* produttoreLabel;
    QLabel* produttoreValueLabel;
    QLabel* prezzoLabel;
    QLabel* prezzoValueLabel;
    QLabel* modalitaLabel;
    QLabel* modalitaValueLabel;
    QLabel* memoriaMassimaSupportataLabel;
    QLabel* memoriaMassimaSupportataValueLabel;
public:
    SistemaOperativoSpecsWidget(QWidget* =0);
    void createLabels();

    void setNomeValueLabel(const QString&);
    void setProduttoreValueLabel(const QString&);
    void setPrezzoValueLabel(const QString&);
    void setModalitaValueLabel(const QString&);
    void setMemoriaMassimaSupportataValueLabel(const QString&);
};

#endif // SISTEMAOPERATIVOSPECSWIDGET_H
