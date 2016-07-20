#include "PCBuilderGUI.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    PCBuilderGUI PCBuilder;

    return app.exec();
}
