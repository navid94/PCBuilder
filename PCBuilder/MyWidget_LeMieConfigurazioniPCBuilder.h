#ifndef MYWIDGET_LEMIECONFIGURAZIONIPCBUILDER_H
#define MYWIDGET_LEMIECONFIGURAZIONIPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QSignalMapper>

class MainWindow;

class MyWidget_LeMieConfigurazioniPCBuilder:public QWidget{
    Q_OBJECT
private:
    MainWindow* mw;
    QSignalMapper* signalMapper;

    QLabel* PCBuilder_LeMieConfigurazioniLabel;
    QLabel* nomeConfigurazioneLabel;

    QPushButton* indietroPushButton;

    void createLabels();
    void createPushButtons();
public:
    MyWidget_LeMieConfigurazioniPCBuilder(MainWindow*, QWidget* =0);

    QPushButton* getIndietroPushButton() const;
signals:
    void sendMessage(const QString&);
};

#endif // MYWIDGET_LEMIECONFIGURAZIONIPCBUILDER_H
