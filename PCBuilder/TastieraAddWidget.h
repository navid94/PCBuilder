#ifndef TASTIERAADDWIDGET_H
#define TASTIERAADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleSpinBox>

class TastieraAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelTastiera;
    QLabel* prezzoLabelTastiera;
    QLabel* produttoreLabelTastiera;
    QLabel* coloreLabelTastiera;
    QLabel* connessioneLabelTastiera;
    QLabel* tipologiaLabelTastiera;
    QLabel* tipologiaSwitchLabelTastiera;
    QLineEdit* nomeLineEditTastiera;
    QLineEdit* produttoreLineEditTastiera;
    QLineEdit* coloreLineEditTastiera;
    QLineEdit* connessioneLineEditTastiera;
    QLineEdit* tipologiaLineEditTastiera;
    QLineEdit* tipologiaSwitchLineEditTastiera;
    QCheckBox* retroilluminazioneCheckBoxTastiera;
    QDoubleSpinBox* prezzoDoubleSpinBoxTastiera;
public:
    TastieraAddWidget(QWidget* =0);

    void createLabels();
    void createLineEdits();
    void createCheckBoxes();
    void createDoubleSpinBoxes();

    QString nomeTastieraValue() const;
    QString produttoreTastieraValue() const;
    QString coloreTastieraValue() const;
    QString connessioneTastieraValue() const;
    QString tipologiaTastieraValue() const;
    QString tipologiaSwitchTastieraValue() const;
    bool retroilluminazioneTastieraValue() const;
    double prezzoTastieraValue() const;

    QLineEdit* getNomeLineEditTastiera() const;
    QLineEdit* getProduttoreLineEditTastiera() const;
    QLineEdit* getColoreLineEditTastiera() const;
    QLineEdit* getConnessioneLineEditTastiera() const;
    QLineEdit* getTipologiaLineEditTastiera() const;
    QLineEdit* getTipologiaSwitchLineEditTastiera() const;
    QCheckBox* getRetroilluminazioneCheckBoxTastiera() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxTastiera() const;
};

#endif // TASTIERAADDWIDGET_H
