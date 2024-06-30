#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameFile.h"
#include "GameLogic.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QIcon>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mousePressed(false)
    , gridOffset(0, 0)
    , centerPoint(width() / 2, height() / 2)
    , cellColors(numCells, std::vector<QColor>(numCells, Qt::white))
    , ui(new Ui::MainWindow)
{
    resize(400, 400);
    ui->setupUi(this);
    setWindowTitle("LifeCreator");

    information.setSize(numCells);
    information.initMapData();

    playButton = findChild<QPushButton*>("playButton");
    connect(playButton, &QPushButton::clicked, this, &MainWindow::playButtonClicked);

    saveButton = findChild<QPushButton*>("saveButton");
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveButtonClicked);

    nextStepButton = findChild<QPushButton*>("nextStepButton");
    connect(nextStepButton, &QPushButton::clicked, this, &MainWindow::nextStepButtonClicked);

    lastStepButton = findChild<QPushButton*>("lastStepButton");
    lastStepButton->setEnabled(false);
    connect(lastStepButton, &QPushButton::clicked, this, &MainWindow::lastStepButtonClicked);

    clearButton = findChild<QPushButton*>("clearButton");
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::clearButtonClicked);

    titleButton = findChild<QPushButton*>("titleButton");

    timeControlBox = findChild<QDoubleSpinBox*>("timeControlBox");
    connect(timeControlBox, &QDoubleSpinBox::valueChanged, this, &MainWindow::timeControlBoxValueChanged);

    generateTimer = new QTimer(this);
    connect(generateTimer, &QTimer::timeout, this, &MainWindow::paintNext);

    helpAction = findChild<QAction*>("helpAction");
    connect(helpAction, &QAction::triggered, this, &MainWindow::openHelpDoc);

    /////////////////////////
    /// test here////
    /// ////////////////////

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openHelpDoc()
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


void MainWindow::setTitle()
{
    titleButton->setText(information.getMainTitle());
}


std::vector<std::vector<QColor>> MainWindow::getCellColors()
{
    return cellColors;
}


void MainWindow::showEvent(QShowEvent *event)
{
    QMainWindow::showEvent(event);
    update();
}


void MainWindow::resizeEvent(QResizeEvent* event) //get center point
{
    centerPoint = QPoint(width() / 2, height() / 2);
    QMainWindow::resizeEvent(event);
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int cellSize = static_cast<int>(gridSize * zoomFactor);
    int gridWidth = cellSize * numCells;
    int gridHeight = cellSize * numCells;

    //block start
    QPoint gridStart = centerPoint - QPoint(gridWidth / 2, gridHeight / 2) + gridOffset;

    painter.setPen(QPen(Qt::lightGray, 1));
    painter.setBrush(Qt::NoBrush);

    for (int row = 0; row < numCells; ++row) {
        for (int col = 0; col < numCells; ++col) {
            //use rect to paint blocks
            QRect rect = QRect(gridStart.x() + col * cellSize, gridStart.y() + row * cellSize, cellSize, cellSize);
            painter.fillRect(rect, cellColors[row][col]);
            painter.drawRect(rect);
            //change info
            information.setMapData(row, col, cellColors[row][col]);
        }
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !generateTimer->isActive()){
        int cellSize = static_cast<int>(gridSize * zoomFactor); // zoom
        QPoint gridStart = centerPoint - QPoint(numCells * cellSize / 2, numCells * cellSize / 2) + gridOffset;

        int col = (event->pos().x() - gridStart.x()) / cellSize;
        int row = (event->pos().y() - gridStart.y()) / cellSize;

        if (col >= 0 && col < numCells && row >= 0 && row < numCells) {
            cellColors[row][col] = cellColors[row][col] == information.getMainColor() ? Qt::white : information.getMainColor();
            information.setMapData(row, col, cellColors[row][col]);
            information.showCellData(row, col); //test
            update();
        }
    }

    else if (event->button() == Qt::RightButton) {
        //drag
        mousePressed = true;
        lastMousePos = event->pos();//finish drag
    }
}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePressed && event->buttons() & Qt::RightButton) {
        //drag
        QPoint delta = event->pos() - lastMousePos;
        gridOffset += delta;
        lastMousePos = event->pos();
        update();
    }

    //drag mouse left to draw line
    else if(!generateTimer->isActive()){
        int cellSize = static_cast<int>(gridSize * zoomFactor);
        QPoint gridStart = centerPoint - QPoint(numCells * cellSize / 2, numCells * cellSize / 2) + gridOffset;

        int col = (event->pos().x() - gridStart.x()) / cellSize;
        int row = (event->pos().y() - gridStart.y()) / cellSize;

        if (col >= 0 && col < numCells && row >= 0 && row < numCells) {
            if(cellColors[row][col] == Qt::white) {
            cellColors[row][col] = information.getMainColor();
            information.setMapData(row, col, cellColors[row][col]);
            update();
            }
        }
    }
}


//enable next operate
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mousePressed = false;
}


void MainWindow::wheelEvent(QWheelEvent *event)
{
    double scaleFactor = 1.1;
    double oldZoomFactor = zoomFactor;

    if (event->angleDelta().y() > 0) {
        zoomFactor *= scaleFactor;
    } else {
        zoomFactor /= scaleFactor;
    }

    zoomFactor = qMax(0.5, qMin(zoomFactor, 3.0));

    //make zoom center in window center
    QPoint mousePos = event->position().toPoint();
    gridOffset = (gridOffset - (mousePos - centerPoint)) * (zoomFactor / oldZoomFactor) + (mousePos - centerPoint);

    update();
}


void MainWindow::saveButtonClicked()
{
    saveToFile(information);
    qDebug() << "saved";
}


void MainWindow::playButtonClicked()
{
    //remember change button type
    if(checktimeInterval()){
        setControls(generateTimer->isActive());

        if(generateTimer->isActive()){
            generateTimer->stop();
            if(information.stackIsEmpty()){
               lastStepButton->setEnabled(false);
            }
            playButton->setText("启动");
            playButton->setIcon(QIcon::fromTheme("media-playback-start"));

        }

        else{
            generateTimer->start(timeInterval * 1000);
            playButton->setText("暂停");
            playButton->setIcon(QIcon::fromTheme("media-playback-stop"));
            qDebug() << "played";
        }
    }
}


void MainWindow::nextStepButtonClicked()
{
    paintNext();
}


void MainWindow::lastStepButtonClicked()
{
    paintPre();
    //stack can't empty
    if(information.stackIsEmpty()){
        lastStepButton->setEnabled(false);
    }
}


void MainWindow::clearButtonClicked()
{
    rebuildMapData();
    lastStepButton->setEnabled(false);
    for (int row = 0; row < numCells; ++row) {
        for (int col = 0; col < numCells; ++col) {
            cellColors[row][col] = information.getCellColor(row, col);
        }
    }
    update();
}


void MainWindow::timeControlBoxValueChanged(double arg1)
{
    timeInterval = arg1;
    qDebug() << timeInterval;
}


void MainWindow::paintNext()
{
    information.pushData();
    if(generateTimer->isActive()){
        lastStepButton->setEnabled(false);
    }
    else{
        lastStepButton->setEnabled(true);
    }

    information.generateNext();
    for (int row = 0; row < numCells; ++row) {
        for (int col = 0; col < numCells; ++col) {
            cellColors[row][col] = information.getCellColor(row, col);
        }
    }
    update();
}


void MainWindow::paintPre()
{
    information.generatePre();
    for (int row = 0; row < numCells; ++row) {
        for (int col = 0; col < numCells; ++col) {
            cellColors[row][col] = information.getCellColor(row, col);
        }
    }
    update();
}


//when playing, set buttons false
void MainWindow::setControls(bool arg)
{
    saveButton->setEnabled(arg);
    nextStepButton->setEnabled(arg);
    lastStepButton->setEnabled(arg);
    clearButton->setEnabled(arg);
    timeControlBox->setEnabled(arg);
}


//too small
bool MainWindow::checktimeInterval()
{
    return timeInterval >= 0.1;
}

//////////////////////////////////////
/// only used in finishing setting
/// in load file
//////////////////////////////////////

void MainWindow::initInfo(QString title, QColor color, int size, std::vector<std::pair<int,int>> range, int num, QHash<int,int> fate)
{
    information.setMainTitle(title);
    information.setMainColor(color);
    information.setSize(size);
    information.setMainRule(range, num, fate);
}


void MainWindow::initNumCells(int num)
{
    numCells = num;
}


void MainWindow::initCellColors(int size)
{
    std::vector<std::vector<QColor>> copy(size, std::vector<QColor>(size, Qt::white));
    cellColors.clear();
    cellColors = copy;
}


void MainWindow::initAllCellColors(std::vector<std::vector<QColor>> colors)
{
    cellColors = colors;
}


void MainWindow::rebuildMapData()
{
    information.cleanStack();
    information.cleanMapData();
    information.initMapData();
}


