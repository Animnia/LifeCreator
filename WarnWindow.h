#ifndef WARNWINDOW_H
#define WARNWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class WarnWindow;
}
QT_END_NAMESPACE

class WarnWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WarnWindow(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~WarnWindow();



private:
    MainWindow *mainWindow;
    Ui::WarnWindow *ui;
};

#endif // WARNWINDOW_H
