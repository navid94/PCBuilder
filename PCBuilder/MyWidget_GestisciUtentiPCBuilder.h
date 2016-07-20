#ifndef MYWIDGET_GESTISCIUTENTIPCBUILDER_H
#define MYWIDGET_GESTISCIUTENTIPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QString>

class MyWidget_GestisciUtentiPCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* PCBuilder_Gestione_utentiLabel;
    QLabel* modifica_dati_utenteLabel;
    QLabel* rimuovi_utenteLabel;
    QLabel* usernameLabel;
    QLabel* emailLabel;
    QLabel* nomeLabel;
    QLabel* cognomeLabel;
    QLabel* passwordLabel;
    QLabel* tipo_accountLabel;
    QLabel* data_di_nascitaLabel;

    QLineEdit* username_utentemodificaLineEdit;
    QLineEdit* usernameLineEdit;
    QLineEdit* emailLineEdit;
    QLineEdit* nomeLineEdit;
    QLineEdit* cognomeLineEdit;
    QLineEdit* passwordLineEdit;
    QLineEdit* username_utenterimuovereLineEdit;

    QComboBox* tipoaccountComboBox;
    QComboBox* giornonascitaComboBox;
    QComboBox* mesenascitaComboBox;
    QComboBox* annonascitaComboBox;

    QPushButton* indietroPushButton;
    QPushButton* modificaPushButton;
    QPushButton* elimina_utentePushButton;

    void createLabels();
    void createPushButtons();
    void createLineEdits();
    void createComboBoxes();
public:
    MyWidget_GestisciUtentiPCBuilder(QWidget* =0);

    QPushButton* get_indietroPushButton() const;
    QPushButton* get_modificaPushButton() const;
    QPushButton* get_elimina_utentePushButton() const;

    QString username_utentemodificaValue() const;
    QString usernameValue() const;
    QString emailValue() const;
    QString nomeValue() const;
    QString cognomeValue() const;
    QString passwordValue() const;
    QString username_utenterimuovereValue() const;
    QString tipoaccountValue() const;
    QString giornonascitaValue() const;
    QString mesenascitaValue() const;
    QString annonascitaValue() const;

};

#endif // MYWIDGET_GESTISCIUTENTIPCBUILDER_H
