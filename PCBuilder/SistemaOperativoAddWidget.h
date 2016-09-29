#ifndef SISTEMAOPERATIVOADDWIDGET_H
#define SISTEMAOPERATIVOADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>

class SistemaOperativoAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelSistemaOperativo;
    QLabel* prezzoLabelSistemaOperativo;
    QLabel* produttoreLabelSistemaOperativo;
    QLabel* modalitaLabelSistemaOperativo;
    QLabel* memoriaMassimaSupportataLabelSistemaOperativo;
    QLineEdit* nomeLineEditSistemaOperativo;
    QLineEdit* produttoreLineEditSistemaOperativo;
    QLineEdit* modalitaLineEditSistemaOperativo;
    QLineEdit* memoriaMassimaSupportataLineEditSistemaOperativo;
    QDoubleSpinBox* prezzoDoubleSpinBoxSistemaOperativo;
public:
    SistemaOperativoAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();

    QString nomeSistemaOperativoValue() const;
    QString produttoreSistemaOperativoValue() const;
    QString modalitaSistemaOperativoValue() const;
    QString memoriaMassimaSupportataSistemaOperativoValue() const;
    double prezzoSistemaOperativoValue() const;

    QLineEdit* getNomeLineEditSistemaOperativo() const;
    QLineEdit* getProduttoreLineEditSistemaOperativo() const;
    QLineEdit* getModalitaLineEditSistemaOperativo() const;
    QLineEdit* getMemoriaMassimaSupportataLineEditSistemaOperativo() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxSistemaOperativo() const;
};

#endif // SISTEMAOPERATIVOADDWIDGET_H
