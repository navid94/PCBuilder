#ifndef MYWIDGET_CONFIGURAZIONEPCBUILDER_H
#define MYWIDGET_CONFIGURAZIONEPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>

class MyWidget_ConfigurazionePCBuilder:public QWidget{
    Q_OBJECT
private:
    QGridLayout* gridLayout;

    QLabel* PCBuiler_ConfigurazioneLabel;
    QLabel* nomeConfigurazioneLabel;
    QLabel* nomeConfigurazioneValueLabel;
    QLabel* componenteLabel;
    QLabel* selezioneLabel;
    QLabel* prezzoLabel;
    QLabel* totaleLabel;
    QLabel* prezzoTotaleLabel;

    QPushButton* indietroPushButton;
public:
    MyWidget_ConfigurazionePCBuilder(QWidget* =0);
    void createLabels();
    void createPushButtons();

    QGridLayout* getGridLayout() const;
    QPushButton* getIndietroPushButton() const;
    void setNomeConfigurazioneValueLabel(const QString&);
    void setPrezzoTotaleLabel(const QString&);

};


#endif // MYWIDGET_CONFIGURAZIONEPCBUILDER_H
