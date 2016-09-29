#ifndef MYWIDGET_LEMIECONFIGURAZIONIPCBUILDER_H
#define MYWIDGET_LEMIECONFIGURAZIONIPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QSignalMapper>
#include <QLayout>

class MyWidget_LeMieConfigurazioniPCBuilder:public QWidget{
    Q_OBJECT
private:
    QSignalMapper* viewSignalMapper;
    QSignalMapper* editSignalMapper;
    QGridLayout* gridLayout;

    QLabel* PCBuilder_LeMieConfigurazioniLabel;
    QLabel* nomeConfigurazioneLabel;

    QPushButton* indietroPushButton;

    void createLabels();
    void createPushButtons();
public:
    MyWidget_LeMieConfigurazioniPCBuilder(QWidget* =0);

    QPushButton* getIndietroPushButton() const;
    QGridLayout* getGridLayout() const;
    QSignalMapper* getViewSignalMapper() const;
    QSignalMapper* getEditSignalMapper() const;
signals:
    void sendEditMessage(const QString&);
    void sendViewMessage(const QString&);
};

#endif // MYWIDGET_LEMIECONFIGURAZIONIPCBUILDER_H
