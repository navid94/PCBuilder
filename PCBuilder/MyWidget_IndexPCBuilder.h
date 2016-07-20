#ifndef MYWIDGET_INDEXPCBUILDER_H
#define MYWIDGET_INDEXPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MyWidget_IndexPCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* pcbuilderLabel;
    QLabel* selmodaccessoLabel;

    QPushButton* adminPushButton;
    QPushButton* utentePushButton;

    void createLabels();
    void createPushButtons();
public:
    MyWidget_IndexPCBuilder(QWidget* =0);
    QPushButton* getadminPushButton() const;
    QPushButton* getutentePushButton() const;
};


#endif // MYWIDGET_INDEXPCBUILDER_H
