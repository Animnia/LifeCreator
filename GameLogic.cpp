#include "GameLogic.h"
#include <QDebug>

Information::~Information()
{}

void Information::setSize(int numCells)
{
    size = numCells;
}


void Information::setMainTitle(QString title)
{
    mainTitle = title;
}


void Information::setMainColor(QColor color)
{
    mainColor = color;
}


void Information::setMainRule(std::vector<std::pair<int,int>> range, int num, QHash<int,int> fate)
{
    mainRule.range = range;
    mainRule.rangeNumber = num;
    mainRule.fate = fate;
}


void Information::initMapData()
{
    for(int row = 0; row < size; ++row){
        for(int col = 0; col < size; ++col){
            mapData.push_back(cellData(row, col, Qt::white));
        }
    }
}


void Information::cleanMapData()
{
    mapData.clear();
}


void Information::setMapData(int row, int col, QColor color)
{
    mapData[col + row * size].color = color;
}


void Information::setAllMapData(std::vector<cellData> datas)
{
    mapData = datas;
}


void Information::showCellData(int row, int col)
{
    qDebug() << mapData[col + row * size].row << "," << mapData[col + row * size].col << " " <<mapData[col + row * size].color;
}


int Information::testcount(int row, int col)
{
    return countAliveNeighbors(row, col);
}


void Information::generateNext()
{
    generateNextHelper();
}


void Information::generatePre()
{
    generatePreHelper();
}


QColor Information::getCellColor(int row, int col)
{
    return mapData[row * size + col].color;
}


void Information::showInformation()
{
    qDebug() << "Title: " << mainTitle << "\n" << "Color:" << mainColor << "\n";
    qDebug() << "Size: " << size << "\n";
    qDebug() << "Rule:" << "\n";
    qDebug() << "range " << mainRule.rangeNumber << ":\n";
    for(auto block : mainRule.range)
    {
        qDebug() << "(" << block.first << "," << block.second << ")\n";
    }
    for(QHash<int,int>::const_iterator block = mainRule.fate.constBegin(); block != mainRule.fate.constEnd(); ++block)
    {
        qDebug() << block.key() << ": ";
        switch (block.value()) {
        case 0:
            qDebug() << "dead\n";
            break;
        case 1:
            qDebug() << "still\n";
            break;
        case 2:
            qDebug() << "create\n";
            break;
        default:
            qDebug() << "unknown\n";
            break;
        }
    }
    qDebug() << "blocks:\n";
    for(auto block : mapData)
    {
        qDebug() << "(" << block.row << "," << block.col << ")" << ": " << block.color << "\n";
    }
}


bool Information::isAlive(const cellData& cell)
{
    return cell.color != QColor(Qt::white);
}


int Information::countAliveNeighbors(int row, int col)
{
    int count = 0;
    int target = 0;
    for (auto rule : mainRule.range) {
        if(row + rule.first > size - 1 || row + rule.first < 0 || col + rule.second > size - 1 || col + rule.second < 0)
        {
            continue;
        }
        target = (row + rule.first) * size + col + rule.second;
        if(isAlive(mapData[target]))
        {
            count++;
        }
    }
    return count;
}


void Information::generateNextHelper()//main next
{
    std::vector<QColor> temp(size * size, Qt::white);
    int count = 0;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            count = countAliveNeighbors(row, col);
            switch (mainRule.fate[count]) {
            case 0:
                break;
            case 1:
                temp[row * size + col] = mapData[row * size + col].color;
                break;
            case 2:
                temp[row * size + col] = mainColor;
                break;

            default:
                break;
            }

        }
    }
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            mapData[row * size + col].color = temp[row * size + col];
        }
    }
}


void Information::generatePreHelper()//main last
{
    mapData = lastDatas.top();

    lastDatas.pop();
}


void Information::pushData()
{
    lastDatas.push(mapData);
}


bool Information::stackIsEmpty()
{
    return lastDatas.empty();
}


void Information::showTop()
{
    for (auto block : lastDatas.top()) {
        qDebug() << "(" << block.row << "," << block.col << ")" << ": " << block.color << "\n";
    }
}


void Information::cleanStack()
{
    lastDatas.clear();
}


int Information::getSize()
{
    return size;
}


QString Information::getMainTitle()
{
    return mainTitle;
}


QColor Information::getMainColor()
{
    return mainColor;
}


int Information::getRangeNumber()
{
    return mainRule.rangeNumber;
}


std::vector<std::pair<int,int>> Information::getRange()
{
    return mainRule.range;
}


QHash<int,int> Information::getFate()
{
    return mainRule.fate;
}


std::vector<cellData> Information::getMapData()
{
    return mapData;
}


// rebuild all cells, only used in load file
std::vector<std::vector<QColor>> Information::buildColors()
{
    std::vector<std::vector<QColor>> colors;
    colors.resize(size);
    for (int row = 0; row < size; ++row) {
        colors[row].resize(size);
        for (int col = 0; col < size; ++col) {
            colors[row][col] = mapData[col + row * size].color;
        }
    }
    return colors;
}
