#ifndef MYWIDGET_REGISTRAZIONEUTENTEPCBUILDER_H
#define MYWIDGET_REGISTRAZIONEUTENTEPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QString>

class MyWidget_RegistrazioneUtentePCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* usernameLabel;
    QLabel* passwordLabel;
    QLabel* confermapasswordLabel;
    QLabel* emailLabel;
    QLabel* PCBuilder_registrazioneLabel;
    QLabel* nomeLabel;
    QLabel* cognomeLabel;
    QLabel* datanascitaLabel;

    QPushButton* registratiPushButton;
    QPushButton* indietroPushButton;

    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;
    QLineEdit* confermapasswordLineEdit;
    QLineEdit* emailLineEdit;
    QLineEdit* nomeLineEdit;
    QLineEdit* cognomeLineEdit;

    QComboBox* giornonascitaComboBox;
    QComboBox* mesenascitaComboBox;
    QComboBox* annonascitaComboBox;

    void createLabels();
    void createLineEdits();
    void createPushButtons();
    void createComboBoxes();


public:
    MyWidget_RegistrazioneUtentePCBuilder(QWidget* =0);
    QPushButton* get_registratiPushButton() const;
    QPushButton* get_indietroPushButton() const;
    QString usernameValue() const;
    QString passwordValue() const;
    QString confermapasswordValue() const;
    QString nomeValue() const;
    QString cognomeValue() const;
    QString emailValue() const;
    QString giornonascitaValue() const;
    QString mesenascitaValue() const;
    QString annonascitaValue() const;
};

#endif // MYWIDGET_REGISTRAZIONEUTENTEPCBUILDER_H
