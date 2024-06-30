#include "mainwindow.h"
#include "StartWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainw;

    SettingWindow settingw(&mainw);

    StartWindow startw(&settingw);

    startw.show();
    return a.exec();
}
