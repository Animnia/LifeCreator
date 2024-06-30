#include "SettingWindow.h"
#include <QPushButton>
#include <QDebug>
#include "ui_SettingWindow.h"


SettingWindow::SettingWindow(MainWindow *mainWindow, QWidget *parent)
    : QWidget(parent)
    , mainWindow(mainWindow)
    , ui(new Ui::SettingWindow)
{
    setFixedSize(600, 500);

    //fix the window
    Qt::WindowFlags flags = windowFlags();
    flags &= ~Qt::WindowMaximizeButtonHint;

    setWindowFlags(flags);

    ui->setupUi(this);
    setWindowTitle("设置");
    nextButton = findChild<QPushButton*>("nextButton");
    connect(nextButton, &QPushButton::clicked, this, &SettingWindow::nextButtonClicked);

    titleEdit = findChild<QLineEdit*>("titleEdit");
    connect(titleEdit, &QLineEdit::textChanged, this, &SettingWindow::editTitle);


    colorBox = findChild<QComboBox*>("colorBox");
    colorBox->addItem("黑色");
    colorBox->addItem("红色");
    colorBox->addItem("蓝色");
    colorBox->addItem("粉色");
    connect(colorBox, &QComboBox::currentIndexChanged, this, &SettingWindow::selectColor);



    sizeBox = findChild<QComboBox*>("sizeBox");
    sizeBox->addItem("32 * 32");
    sizeBox->addItem("64 * 64");
    sizeBox->addItem("128 * 128");
    sizeBox->addItem("256 * 256");
    connect(sizeBox, &QComboBox::currentIndexChanged, this, &SettingWindow::selectSize);


    int gridSide = 5;
    int gridSize = 40;
    gridCells_.resize(gridSide);

    //draw range
    for (int row = 0; row < gridSide; ++row) {
        gridCells_[row].resize(gridSide);
        for (int col = 0; col < gridSide; ++col) {
            int x = width() / 4 * 3 - gridSize * (col - 1);
            int y = height() / 4 + gridSize * row;

            QRect cellRect(x, y, gridSize, gridSize);
            gridCells_[row][col].rect = cellRect;
            gridCells_[row][col].color = Qt::white;
        }
    }

    int settingSize = 20; //size
    int settingRow = 2;
    int settingCol = 12;

    gridNums_.resize(settingRow);

    //draw fate: create
    for (int row = 0; row < settingRow; ++row) {
        gridNums_[row].resize(settingCol);
        for (int col = 0; col < settingCol; ++col) {
            int x = width() / frameWidth + settingSize * (col - 1) ;
            int y = height() / frameHeight + settingSize * (row + moveHeight_1);

            QRect numRect(x, y, settingSize, settingSize);
            gridNums_[row][col].rect = numRect;
            gridNums_[row][col].color = Qt::white;
        }
    }

    //draw fate: die
    gridDieNums_.resize(settingRow);

    for (int row = 0; row < settingRow; ++row) {
        gridDieNums_[row].resize(settingCol);
        for (int col = 0; col < settingCol; ++col) {
            int x = width() / frameWidth + settingSize * (col - 1) ;
            int y = height() / frameHeight + settingSize * (row + moveHeight_2);

            QRect numDieRect(x, y, settingSize, settingSize);
            gridDieNums_[row][col].rect = numDieRect;
            gridDieNums_[row][col].color = Qt::white;
        }
    }

    //draw zero block
    gridZero.color = Qt::white;
    gridZero.rect = QRect(gridNums_[0][0].rect.x() - settingSize, gridNums_[0][0].rect.y(), settingSize, settingSize);
    gridDieZero.color = Qt::white;
    gridDieZero.rect = QRect(gridDieNums_[0][0].rect.x() - settingSize, gridDieNums_[0][0].rect.y(), settingSize, settingSize);


    int middleRow = gridSide / 2;
    int middleCol = gridSide / 2;
    gridCells_[middleRow][middleCol].color = color;
    gridCells_[middleRow + 1][middleCol].color = Qt::gray;
    gridCells_[middleRow + 1][middleCol + 1].color = Qt::gray;
    gridCells_[middleRow + 1][middleCol - 1].color = Qt::gray;
    gridCells_[middleRow][middleCol + 1].color = Qt::gray;
    gridCells_[middleRow][middleCol - 1].color = Qt::gray;
    gridCells_[middleRow - 1][middleCol].color = Qt::gray;
    gridCells_[middleRow - 1][middleCol + 1].color = Qt::gray;
    gridCells_[middleRow - 1][middleCol - 1].color = Qt::gray;

    gridNums_[0][2].color = QColor::fromRgb(0x92, 0xBD, 0x6C);//gray

    gridDieZero.color = QColor::fromRgb(0x92, 0xBD, 0x6C);;
    gridDieNums_[0][0].color = QColor::fromRgb(0x92, 0xBD, 0x6C);
    gridDieNums_[0][3].color = QColor::fromRgb(0x92, 0xBD, 0x6C);
    gridDieNums_[0][4].color = QColor::fromRgb(0x92, 0xBD, 0x6C);
    gridDieNums_[0][5].color = QColor::fromRgb(0x92, 0xBD, 0x6C);
    gridDieNums_[0][6].color = QColor::fromRgb(0x92, 0xBD, 0x6C);
    gridDieNums_[0][7].color = QColor::fromRgb(0x92, 0xBD, 0x6C);

}


void SettingWindow::showGrid(QVector<QVector<GridCell>> grid)
{
    for (QVector<GridCell> i : grid) {
        for (GridCell j : i) {
            qDebug() << j.color << ' ' << j.rect;
        }

    }
}


SettingWindow::~SettingWindow()
{
    delete ui;
}


void SettingWindow::init()
{
    mainWindow->initNumCells(size);
    mainWindow->initInfo(title, color, size, range, rangeNum, fate);
    mainWindow->rebuildMapData();
    mainWindow->initCellColors(size);
    mainWindow->setTitle();
    mainWindow->initAllCellColors(colors);
    mainWindow->show();
}


void SettingWindow::nextButtonClicked()
{
    changeRange();
    changeFate();

    mainWindow->initNumCells(size);
    mainWindow->initInfo(title, color, size, range, rangeNum, fate);
    mainWindow->rebuildMapData();
    mainWindow->initCellColors(size);
    mainWindow->setTitle();

   if (mainWindow) {
        mainWindow->show();
        this->hide();
    }
}


void SettingWindow::editTitle(const QString &text)
{
    title = text;
}


void SettingWindow::selectColor()
{
    QString color_ = colorBox->currentText();
    if(color_ == "黑色"){
        color = Qt::black;
    }
    else if(color_ == "红色"){
        color = Qt::red;
    }
    else if(color_ == "蓝色"){
        color = Qt::blue;
    }
    else if(color_ == "粉色"){
        color = QColor::fromRgb(0xFF, 0xB4, 0xFF);
    }
    int middleRow = 2;
    int middleCol = 2;
    gridCells_[middleRow][middleCol].color = color;
    update();
}


void SettingWindow::selectSize()
{
    QString size_ = sizeBox->currentText();
    if(size_ == "32 * 32"){
        size = 32;
    }
    else if(size_ == "64 * 64"){
        size = 64;
    }
    else if(size_ == "128 * 128"){
        size = 128;
    }
    else if(size_ == "256 * 256"){
        size = 256;
    }
}


void SettingWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    drawGrid(&painter);
}


void SettingWindow::drawGrid(QPainter *painter)
{
    QColor gridColor = QColor(Qt::lightGray);

    // Draw cell
    for (int row = 0; row < gridCells_.size(); ++row) {
        for (int col = 0; col < gridCells_[row].size(); ++col) {
            QRect cellRect = gridCells_[row][col].rect;

            painter->fillRect(cellRect, gridCells_[row][col].color);
            painter->setPen(gridColor);
            painter->drawRect(cellRect);
        }
    }
    int cellCounter = 1;

    // Draw rule: life
    painter->fillRect(gridZero.rect, gridZero.color);
    painter->setPen(gridColor);
    painter->drawRect(gridZero.rect);
    painter->setPen(Qt::black);
    painter->drawText(gridZero.rect.center() - QPoint(moveFix_x, moveFix_y), QString::number(0));

    for (int row = 0; row < gridNums_.size(); ++row) {
        for (int col = 0; col < gridNums_[row].size(); ++col) {
            if(row * 12 + col + 1 > rangeNum){
                gridNums_[row][col].color = Qt::gray;
            }
            if(row * 12 + col + 1 <= rangeNum && gridNums_[row][col].color == Qt::gray){
                gridNums_[row][col].color = Qt::white;
            }

            QRect numRect = gridNums_[row][col].rect;

            painter->fillRect(numRect, gridNums_[row][col].color);
            painter->setPen(gridColor);
            painter->drawRect(numRect);
            painter->setPen(Qt::black);
            painter->drawText(numRect.center() - QPoint(moveFix_x, moveFix_y), QString::number(cellCounter));
            ++cellCounter;
        }
    }

    cellCounter = 1;

    // Draw rule: die
    painter->fillRect(gridDieZero.rect, gridDieZero.color);
    painter->setPen(gridColor);
    painter->drawRect(gridDieZero.rect);
    painter->setPen(Qt::black);
    painter->drawText(gridDieZero.rect.center() - QPoint(moveFix_x, moveFix_y), QString::number(0));

    for (int row = 0; row < gridDieNums_.size(); ++row) {
        for (int col = 0; col < gridDieNums_[row].size(); ++col) {
            if(row * 12 + col + 1 > rangeNum){
                gridDieNums_[row][col].color = Qt::gray;
            }
            if(row * 12 + col + 1 <= rangeNum && gridDieNums_[row][col].color == Qt::gray){
                gridDieNums_[row][col].color = Qt::white;
            }

            QRect numDieRect = gridDieNums_[row][col].rect;

            painter->fillRect(numDieRect, gridDieNums_[row][col].color);
            painter->setPen(gridColor);
            painter->drawRect(numDieRect);
            painter->setPen(Qt::black);
            painter->drawText(numDieRect.center() - QPoint(moveFix_x, moveFix_y), QString::number(cellCounter));
            ++cellCounter;
        }
    }

}


void SettingWindow::mousePressEvent(QMouseEvent *event)
{
    if(gridZero.rect.contains(event->pos())){
        if(gridZero.color == Qt::white){
            gridZero.color = QColor::fromRgb(0x92, 0xBD, 0x6C);
            gridDieZero.color = Qt::white;
        }
        else{
            gridZero.color = Qt::white;
        }
        update();
        return;
    }

    if(gridDieZero.rect.contains(event->pos())){
        if(gridDieZero.color == Qt::white){
            gridDieZero.color = QColor::fromRgb(0x92, 0xBD, 0x6C);
            gridZero.color = Qt::white;
        }
        else{
            gridDieZero.color = Qt::white;
        }
        update();
        return;
    }

    //set range
    for (int row = 0; row < gridCells_.size(); ++row) {
        for (int col = 0; col < gridCells_[row].size(); ++col) {
            QRect cellRect = gridCells_[row][col].rect;
            if (cellRect.contains(event->pos()) && !(row == 2 && col == 2)) {

                if (gridCells_[row][col].color == Qt::white) {
                    gridCells_[row][col].color = Qt::gray;
                    ++rangeNum;
                } else {
                    gridCells_[row][col].color = Qt::white;
                    --rangeNum;
                }

                update();
                return;
            }
        }
    }

    //set fate: create
    for (int row = 0; row < gridNums_.size(); ++row) {
        for (int col = 0; col < gridNums_[row].size(); ++col) {
            QRect numRect = gridNums_[row][col].rect;
            if (numRect.contains(event->pos())) {

                if (gridNums_[row][col].color == Qt::white) {
                    gridNums_[row][col].color = QColor::fromRgb(0x92, 0xBD, 0x6C);
                    gridDieNums_[row][col].color = Qt::white;
                }
                else if(gridNums_[row][col].color == QColor::fromRgb(0x92, 0xBD, 0x6C)){
                    gridNums_[row][col].color = Qt::white;
                }
                showGrid(gridNums_);
                update();
                return;
            }
        }
    }

    //set fate: die
    for (int row = 0; row < gridDieNums_.size(); ++row) {
        for (int col = 0; col < gridDieNums_[row].size(); ++col) {
            QRect numDieRect = gridDieNums_[row][col].rect;
            if (numDieRect.contains(event->pos())) {

                if (gridDieNums_[row][col].color == Qt::white) {
                    gridDieNums_[row][col].color = QColor::fromRgb(0x92, 0xBD, 0x6C);
                    gridNums_[row][col].color = Qt::white;
                }
                else if(gridDieNums_[row][col].color == QColor::fromRgb(0x92, 0xBD, 0x6C)){
                    gridDieNums_[row][col].color = Qt::white;
                }
                showGrid(gridDieNums_);
                update();
                return;
            }
        }
    }
}


//pack range into mainwindow
void SettingWindow::changeRange()
{
    for (int row = 0; row < gridCells_.size(); ++row) {
        for (int col = 0; col < gridCells_[row].size(); ++col) {
            if(gridCells_[row][col].color == Qt::gray){
                int dy = row - 2;
                int dx = 2 - col;
                range.push_back({dy, dx});
            }
        }
    }
}


//same fate
void SettingWindow::changeFate()
{
    if(gridZero.color == QColor::fromRgb(0x92, 0xBD, 0x6C)){
        fate.insert(0,2);
    }
    else if(gridDieZero.color == QColor::fromRgb(0x92, 0xBD, 0x6C)){
        fate.insert(0,0);
    }
    else{
        fate.insert(0,1);
    }

    for (int row = 0; row < gridNums_.size(); ++row) {
        for (int col = 0; col < gridNums_[row].size(); ++col) {
            if(gridNums_[row][col].color == Qt::gray){
                continue;
            }
            if(gridNums_[row][col].color == QColor::fromRgb(0x92, 0xBD, 0x6C)){
                fate.insert(row * 12 + col + 1,2);
            }
            else if(gridDieNums_[row][col].color == QColor::fromRgb(0x92, 0xBD, 0x6C)){
                fate.insert(row * 12 + col + 1,0);
            }
            else{
                fate.insert(row * 12 + col + 1,1);
            }
        }
    }
}


QString SettingWindow::getTitle()
{
    return title;
}


int SettingWindow::getSize()
{
    return size;
}


QColor SettingWindow::getColor()
{
    return color;
}


std::vector<std::pair<int,int>> SettingWindow::getRange()
{
    return range;
}


int SettingWindow::getRangeNum()
{
    return rangeNum;
}


QHash<int,int> SettingWindow::getFate()
{
    return fate;
}


std::vector<std::vector<QColor>> SettingWindow::getColors()
{
    return colors;
}


void SettingWindow::setTitle(QString t)
{
    title = t;
}


void SettingWindow::setSize(int s)
{
    size = s;
}


void SettingWindow::setColor(QColor c)
{
    color = c;
}


void SettingWindow::setRange(std::vector<std::pair<int,int>> r)
{
    range = r;
}


void SettingWindow::setRangeNum(int rn)
{
    rangeNum = rn;
}


void SettingWindow::setFate(QHash<int,int> f)
{
    fate = f;
}


void SettingWindow::setColors(std::vector<std::vector<QColor>> cs)
{
    colors = cs;
}

