#include "StartWindow.h"
#include <QPushButton>
#include "ui_StartWindow.h"
#include "GameFile.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>


StartWindow::StartWindow(SettingWindow *settingWindow, QWidget *parent)
    : QWidget(parent)
    , settingWindow(settingWindow)
    , ui(new Ui::StartWindow)
{
    resize(400,400);
    ui->setupUi(this);
    setWindowTitle("开始");

    startButton = findChild<QPushButton*>("startButton");
    connect(startButton, &QPushButton::clicked, this, &StartWindow::startButtonClicked);

    loadButton = findChild<QPushButton*>("loadButton");
    connect(loadButton, &QPushButton::clicked, this, &StartWindow::loadButtonClicked);

    helpButton = findChild<QPushButton*>("helpButton");
    connect(helpButton, &QPushButton::clicked, this, &StartWindow::helpButtonClicked);
}

StartWindow::~StartWindow()
{
    delete ui;
}


void StartWindow::startButtonClicked()
{
    if (settingWindow) {
        settingWindow->show();
        this->hide();
    }
}


void StartWindow::loadButtonClicked()
{
    loadJson(loadInfo);

    //can't exit
    if(DEBUG_WARNING_SIGN){
        return;
    }

    settingWindow->setColor(loadInfo.getMainColor());
    settingWindow->setTitle(loadInfo.getMainTitle());
    settingWindow->setSize(loadInfo.getSize());
    settingWindow->setRange(loadInfo.getRange());
    settingWindow->setRangeNum(loadInfo.getRangeNumber());
    settingWindow->setFate(loadInfo.getFate());
    settingWindow->setColors(loadInfo.buildColors());

    settingWindow->init();
    this->hide();
}

void StartWindow::helpButtonClicked()
{
    QString appDir = QCoreApplication::applicationDirPath();

    QString helpFilePath = appDir + "/README.docx";

    if (!QFile::exists(helpFilePath)) {
        QMessageBox::warning(this, "Error", "文件不存在！");
        return;
    }

    QUrl helpUrl = QUrl::fromLocalFile(helpFilePath);
    QDesktopServices::openUrl(helpUrl);
}
