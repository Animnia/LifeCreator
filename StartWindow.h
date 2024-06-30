#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "SettingWindow.h"
#include "GameLogic.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class StartWindow;
}
QT_END_NAMESPACE

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(SettingWindow *settingWindow, QWidget *parent = nullptr);
    ~StartWindow();

    /*signals:
    void startButtonClicked();*/

private slots:

    void startButtonClicked();
    void loadButtonClicked();
    void helpButtonClicked();

private:

    // all of this only used in load file
    Information loadInfo;

    QPushButton *startButton;
    QPushButton *loadButton;
    QPushButton *helpButton;
    SettingWindow *settingWindow;
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
