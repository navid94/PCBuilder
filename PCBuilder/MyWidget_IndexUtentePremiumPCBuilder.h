#ifndef MYWIDGET_INDEXUTENTEPREMIUMPCBUILDER_H
#define MYWIDGET_INDEXUTENTEPREMIUMPCBUILDER_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class MyWidget_IndexUtentePremiumPCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* PCBuilder_IndexUtentePremiumLabel;

    QPushButton* creaconfPushButton;
    QPushButton* cercapartiPushButton;
    QPushButton* mostraconfsalvatePushButton;
    QPushButton* modificaprofiloPushButton;
    QPushButton* esciPushButton;

    void createPushButtons();
    void createLabels();
public:
    MyWidget_IndexUtentePremiumPCBuilder(QWidget* =0);
    QPushButton* getCreaconfPushButton() const;
    QPushButton* getCercapartiPushButton() const;
    QPushButton* getMostraconfsalvatePushButton() const;
    QPushButton* getModificaProfiloPushButton() const;
    QPushButton* getEsciPushButton() const;
};

#endif // MYWIDGET_INDEXUTENTEPREMIUMPCBUILDER_H
