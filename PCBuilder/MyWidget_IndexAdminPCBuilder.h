#ifndef MYWIDGET_INDEXADMINPCBUILDER_H
#define MYWIDGET_INDEXADMINPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MyWidget_IndexAdminPCBuilder:public QWidget{
    Q_OBJECT
private:

    QLabel* pcbuilderadminLabel;
    QPushButton* gestiscicompPushButton;
    QPushButton* gestisciutentiPushButton;
    QPushButton* indietroPushButton;

    void createLabels();
    void createPushButtons();
public:
    MyWidget_IndexAdminPCBuilder(QWidget* =0);
    QPushButton* get_gestiscicompPushButton() const;
    QPushButton* get_gestisciutentiPushButton() const;
    QPushButton* get_indietroPushButton() const;
};

#endif // MYWIDGET_INDEXADMINPCBUILDER_H
