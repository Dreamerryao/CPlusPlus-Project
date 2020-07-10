#include "app.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    app VisApp;
    VisApp.run();
    return a.exec();
}
