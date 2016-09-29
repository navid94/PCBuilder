#ifndef CUFFIEADDWIDGET_H
#define CUFFIEADDWIDGET_H

#include <QWidget>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QDoubleSpinBox>

class CuffieAddWidget:public QWidget{
    Q_OBJECT
private:
    QLabel* nomeLabelCuffie;
    QLabel* prezzoLabelCuffie;
    QLabel* produttoreLabelCuffie;
    QLabel* tipologiaLabelCuffie;
    QLabel* sistemaAcusticoLabelCuffie;
    QLabel* coloreLabelCuffie;
    QLabel* canaliLabelCuffie;
    QLabel* impedenzaLabelCuffie;
    QLabel* frequenzaDiRispostaLabelCuffie;
    QLabel* connessioneLabelCuffie;
    QLabel* connettoreLabelCuffie;
    QLineEdit* nomeLineEditCuffie;
    QLineEdit* produttoreLineEditCuffie;
    QLineEdit* tipologiaLineEditCuffie;
    QLineEdit* sistemaAcusticoLineEditCuffie;
    QLineEdit* coloreLineEditCuffie;
    QLineEdit* canaliLineEditCuffie;
    QLineEdit* impedenzaLineEditCuffie;
    QLineEdit* frequenzaDiRispostaLineEditCuffie;
    QLineEdit* connessioneLineEditCuffie;
    QLineEdit* connettoreLineEditCuffie;
    QCheckBox* microfonoCheckBoxCuffie;
    QDoubleSpinBox* prezzoDoubleSpinBoxCuffie;
public:
    CuffieAddWidget(QWidget* =0);
    void createLabels();
    void createLineEdits();
    void createDoubleSpinBoxes();
    void createCheckBoxes();

    QString nomeCuffieValue() const;
    QString produttoreCuffieValue() const;
    QString tipologiaCuffieValue() const;
    QString sistemaAcusticoCuffieValue() const;
    QString coloreCuffieValue() const;
    QString canaliCuffieValue() const;
    QString impedenzaCuffieValue() const;
    QString frequenzaDiRispostaCuffieValue() const;
    QString connessioneCuffieValue() const;
    QString connettoreCuffieValue() const;
    bool microfonoCuffieValue() const;
    double prezzoCuffieValue() const;

    QLineEdit* getNomeLineEditCuffie() const;
    QLineEdit* getProduttoreLineEditCuffie() const;
    QLineEdit* getTipologiaLineEditCuffie() const;
    QLineEdit* getSistemaAcusticoLineEditCuffie() const;
    QLineEdit* getColoreLineEditCuffie() const;
    QLineEdit* getCanaliLineEditCuffie() const;
    QLineEdit* getImpedenzaLineEditCuffie() const;
    QLineEdit* getFrequenzaDiRispostaLineEditCuffie() const;
    QLineEdit* getConnessioneLineEditCuffie() const;
    QLineEdit* getConnettoreLineEditCuffie() const;
    QCheckBox* getMicrofonoCheckBoxCuffie() const;
    QDoubleSpinBox* getPrezzoDoubleSpinBoxCuffie() const;
};

#endif // CUFFIEADDWIDGET_H
