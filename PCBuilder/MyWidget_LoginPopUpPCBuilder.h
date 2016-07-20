#ifndef MYWIDGET_LOGINPOPUPPCBUILDER_H
#define MYWIDGET_LOGINPOPUPPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

class MyWidget_LoginPopUpPCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* usernameLabel;
    QLabel* passwordLabel;

    QLineEdit* usernameLineEdit;
    QLineEdit* passwordLineEdit;

    QPushButton* accediPushButton;

    void createPushButtons();
    void createLabels();
    void createLineEdits();
public:
    MyWidget_LoginPopUpPCBuilder(QWidget* =0);

    QPushButton* get_accediPushButton() const;
    QString usernameValue() const;
    QString passwordValue() const;

    void closeEvent(QCloseEvent*);

signals:
    void closeLoginPopUpPCBuilder();
};


#endif // MYWIDGET_LOGINPOPUPPCBUILDER_H
