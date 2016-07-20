#ifndef MYWIDGET_PARTSLISTPCBUILDER_H
#define MYWIDGET_PARTSLISTPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QSignalMapper>

class MyWidget_PartsListPCBuilder:public QWidget{
    Q_OBJECT
private:
    QString componente;

    QSignalMapper* signalMapper;

    QLabel* PCBuilder_ListaComponentiLabel;
    QLabel* componenteLabel;
    QLabel* produttoreLabel;
    QLabel* prezzoLabel;

    QPushButton* indietroPushButton;
public:
    MyWidget_PartsListPCBuilder(const QString&, QWidget* =0);
    void createLabels();
    void createPushButtons();

    QPushButton* getIndietroPushButton() const;
signals:
    void sendMessage(const QString&);
};

#endif // MYWIDGET_PARTSLISTPCBUILDER_H
