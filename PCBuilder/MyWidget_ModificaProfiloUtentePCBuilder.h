#ifndef MYWIDGET_MODIFICAPROFILOUTENTEPCBUILDER_H
#define MYWIDGET_MODIFICAPROFILOUTENTEPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QString>

class MainWindow;

class MyWidget_ModificaProfiloUtentePCBuilder:public QWidget{
    Q_OBJECT
private:
    MainWindow* mw;

    QLabel* PCBuilder_ModificaProfiloLabel;
    QLabel* emailLabel;
    QLabel* nomeLabel;
    QLabel* cognomeLabel;
    QLabel* nuovaPasswordLabel;
    QLabel* confermaNuovaPasswordLabel;
    QLabel* dataDiNascitaLabel;

    QPushButton* indietroPushButton;
    QPushButton* modificaPushButton;
    QPushButton* eliminaAccountPushButton;
    QPushButton* diventaPremiumPushButton;

    QLineEdit* emailLineEdit;
    QLineEdit* nomeLineEdit;
    QLineEdit* cognomeLineEdit;
    QLineEdit* nuovaPasswordLineEdit;
    QLineEdit* confermaNuovaPasswordLineEdit;

    QComboBox* giornoNascitaComboBox;
    QComboBox* meseNascitaComboBox;
    QComboBox* annoNascitaComboBox;

    void createPushButtons();
    void createLabels();
    void createLineEdits();
    void createComboBoxes();
public:
    MyWidget_ModificaProfiloUtentePCBuilder(MainWindow*,QWidget* =0);

    QPushButton* getIndietroPushButton() const;
    QPushButton* getModificaPushButton() const;
    QPushButton* getEliminaAccountPushButton() const;
    QPushButton* getDiventaPremiumPushButton() const;

    QString emailValue() const;
    QString nomeValue() const;
    QString cognomeValue() const;
    QString nuovaPasswordValue() const;
    QString confermaNuovaPasswordValue() const;
    QString giornoNascitaValue() const;
    QString meseNascitaValue() const;
    QString annoNascitaValue() const;
};

#endif // MYWIDGET_MODIFICAPROFILOUTENTEPCBUILDER_H
