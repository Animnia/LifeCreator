#include "WarnWindow.h"
#include "ui_WarnWindow.h"

WarnWindow::WarnWindow(MainWindow *mainWindow, QWidget *parent)
    : QWidget(parent)
    , mainWindow(mainWindow)
    , ui(new Ui::WarnWindow)
{
    resize(200,200);
    ui->setupUi(this);
}


WarnWindow::~WarnWindow()
{
    delete ui;
}

