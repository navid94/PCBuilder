#ifndef MYWIDGET_INDEXUTENTEREGISTRATOPCBUILDER_H
#define MYWIDGET_INDEXUTENTEREGISTRATOPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class MyWidget_IndexUtenteRegistratoPCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* PCBuilder_IndexUtenteRegistratoLabel;

    QPushButton* creaconfPushButton;
    QPushButton* mostraconfsalvatePushButton;
    QPushButton* modificaprofiloPushButton;
    QPushButton* esciPushButton;

    void createPushButtons();
    void createLabels();
public:
    MyWidget_IndexUtenteRegistratoPCBuilder(QWidget* =0);

    QPushButton* getCreaconfPushButton() const;
    QPushButton* getMostraconfsalvatePushButton() const;
    QPushButton* getModificaProfiloPushButton() const;
    QPushButton* getEsciPushButton() const;
};


#endif // MYWIDGET_INDEXUTENTEREGISTRATOPCBUILDER_H
