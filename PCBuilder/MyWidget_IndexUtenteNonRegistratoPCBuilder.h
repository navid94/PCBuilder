#ifndef MYWIDGET_INDEXUTENTENONREGISTRATOPCBUILDER_H
#define MYWIDGET_INDEXUTENTENONREGISTRATOPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

class MyWidget_IndexUtenteNonRegistratoPCBuilder:public QWidget{
    Q_OBJECT
private:
    QPushButton* creaconfPushButton;
    QPushButton* accediPushButton;
    QPushButton* registratiPushButton;
    QPushButton* indietroPushButton;

    QLabel* PCBuilder_IndexUtenteNonRegistratoLabel;
    QLabel* usernameLabel;
    QLabel* passwordLabel;
    QLabel* oppureLabel;

    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;

    void createPushButtons();
    void createLabels();
    void createLineEdits();
public:
    MyWidget_IndexUtenteNonRegistratoPCBuilder(QWidget* =0);
    QPushButton* get_creaconfPushButton() const;
    QPushButton* get_accediPushButton() const;
    QPushButton* get_registratiPushButton() const;
    QPushButton* get_indietroPushButton() const;

    QString usernameValue() const;
    QString passwordValue() const;
};


#endif // MYWIDGET_INDEXUTENTENONREGISTRATOPCBUILDER_H
