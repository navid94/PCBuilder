#include "MyWidget_LoginPopUpPCBuilder.h"
#include <QLayout>

MyWidget_LoginPopUpPCBuilder::MyWidget_LoginPopUpPCBuilder(QWidget* parent):QWidget(parent){
    createLabels();
    createLineEdits();
    createPushButtons();

    QVBoxLayout* verticalLayout1=new QVBoxLayout;
    QHBoxLayout* horizontalLayout1=new QHBoxLayout;
    QHBoxLayout* horizontalLayout2=new QHBoxLayout;
    QHBoxLayout* horizontalLayout3=new QHBoxLayout;

    horizontalLayout1->addWidget(usernameLabel);
    horizontalLayout1->addWidget(usernameLineEdit);
    horizontalLayout1->setContentsMargins(0,0,0,30);
    horizontalLayout1->setSpacing(30);

    horizontalLayout2->addWidget(passwordLabel);
    horizontalLayout2->addWidget(passwordLineEdit);
    horizontalLayout2->setContentsMargins(0,0,0,30);
    horizontalLayout2->setSpacing(30);

    horizontalLayout3->addWidget(accediPushButton);

    verticalLayout1->addLayout(horizontalLayout1);
    verticalLayout1->addLayout(horizontalLayout2);
    verticalLayout1->addLayout(horizontalLayout3);

    setLayout(verticalLayout1);

}

void MyWidget_LoginPopUpPCBuilder::createLabels(){
    QFont fontLabel;
    fontLabel.setPointSize(14);

    usernameLabel=new QLabel("Username");
    usernameLabel->setFont(fontLabel);
    usernameLabel->setMaximumSize(QSize(110,25));
    usernameLabel->setMinimumSize(QSize(0,0));

    passwordLabel=new QLabel("Password");
    passwordLabel->setFont(fontLabel);
    passwordLabel->setMaximumSize(QSize(100,25));
    passwordLabel->setMinimumSize(QSize(0,0));
}

void MyWidget_LoginPopUpPCBuilder::createLineEdits(){
    usernameLineEdit=new QLineEdit;
    usernameLineEdit->setMaximumSize(QSize(250,25));
    usernameLineEdit->setMinimumSize(QSize(0,0));

    passwordLineEdit=new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setMaximumSize(QSize(250,25));
    passwordLineEdit->setMinimumSize(QSize(0,0));
}

void MyWidget_LoginPopUpPCBuilder::createPushButtons(){
    accediPushButton=new QPushButton(tr("Accedi"));
    accediPushButton->setMaximumSize(QSize(150,50));
    accediPushButton->setMinimumSize(QSize(0,0));
}

QPushButton* MyWidget_LoginPopUpPCBuilder::get_accediPushButton() const{
    return accediPushButton;
}

QString MyWidget_LoginPopUpPCBuilder::usernameValue() const{
    return usernameLineEdit->text();
}

QString MyWidget_LoginPopUpPCBuilder::passwordValue() const{
    return passwordLineEdit->text();
}

void MyWidget_LoginPopUpPCBuilder::closeEvent(QCloseEvent* event){
    emit closeLoginPopUpPCBuilder();
}
