#ifndef MYWIDGET_PARTSLISTPCBUILDER_H
#define MYWIDGET_PARTSLISTPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QSignalMapper>
#include <QLayout>

class MyWidget_PartsListPCBuilder:public QWidget{
    Q_OBJECT
private:
    int row;
    QString componente;

    QGridLayout* gridLayout;

    QSignalMapper* signalMapper;

    QLabel* PCBuilder_ListaComponentiLabel;
    QLabel* componenteLabel;
    QLabel* produttoreLabel;
    QLabel* prezzoLabel;

    QPushButton* indietroPushButton;
public:
    MyWidget_PartsListPCBuilder(QWidget* =0);
    void createLabels();
    void createPushButtons();

    QPushButton* getIndietroPushButton() const;
    QGridLayout* getGridLayout() const;
    QSignalMapper* getSignalMapper() const;

    void addComponent(const QString&, const QString&, double);
signals:
    void sendMessage(const QString&);
};

#endif // MYWIDGET_PARTSLISTPCBUILDER_H
