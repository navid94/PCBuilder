#ifndef MYWIDGET_CERCAPARTIPCBUILDER_H
#define MYWIDGET_CERCAPARTIPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QSignalMapper>
#include <QString>
#include <QLayout>
#include <QVector>

class MyWidget_CercaPartiPCBuilder:public QWidget{
    Q_OBJECT
private:
    QSignalMapper* signalMapper;

    QVector<QLabel*> componenteLabels;
    QVector<QLabel*> produttoreLabels;
    QVector<QLabel*> prezzoLabels;
    QVector<QPushButton*> specifichePushButtons;

    QLabel* PCBuilder_CercaTraLePartiLabel;
    QLabel* tipologiaComponenteLabel;
    QLabel* componenteLabel;
    QLabel* prezzoLabel;
    QLabel* produttoreLabel;

    QPushButton* indietroPushButton;

    QComboBox* tipologiaComponenteComboBox;
    QGridLayout* gridLayout;
    void createLabels();
    void createPushButtons();
    void createComboBoxes();
public:
    MyWidget_CercaPartiPCBuilder(QWidget* =0);

    QPushButton* getIndietroPushButton() const;
private slots:
    void loadPartsList(const QString&);
signals:
    void sendMessage(const QString&);
};

#endif // MYWIDGET_CERCAPARTIPCBUILDER_H
