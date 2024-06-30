#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <QColor>
#include <vector>
#include <utility>
#include <QHash>
#include <QStack>

struct cellData //one cell
{
    int row;
    int col;
    QColor color;

    cellData(){}
    cellData(int row, int col, QColor color) : row(row), col(col), color(color) {}
};

struct ruleData //rule: range and fate
{
    std::vector<std::pair<int,int>> range;
    int rangeNumber;
    QHash<int,int> fate;

    ruleData()
    : range({{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}}),
        rangeNumber(8),
        fate({{0,0},{1,0},{2,1},{3,2},{4,0},{5,0},{6,0},{7,0},{8,0},{9,0}}) {}

    ruleData(std::vector<std::pair<int,int>> range, int rangeNumber, QHash<int,int> fate)
    /////////////////////////////
    //fate(num,fate)
    //0 dead, 1 still, 2 create
    /////////////////////////////
    : range(range), rangeNumber(rangeNumber), fate(fate) {}
};

class Information //contain all information
{

private:
    int size;
    QString mainTitle;
    QColor mainColor;
    ruleData mainRule;
    std::vector<cellData> mapData; //enable draw in mainwindow
    QStack<std::vector<cellData>> lastDatas; //to show last step, when file saved, this will be clean


public:
    Information()
        : size(64), mainTitle("LifeGameProject"), mainColor(Qt::black), mainRule(), mapData()  {}

    Information(int size, QString mainTitle, QColor mainColor, ruleData mainRule, std::vector<cellData> mapData)
        : size(size), mainTitle(mainTitle), mainColor(mainColor), mainRule(mainRule), mapData(mapData)  {}

    ~Information();

    //set and get data
    void setSize(int numCells);
    void setMainTitle(QString title);
    void setMainColor(QColor color);
    int getSize();
    QString getMainTitle();
    QColor getMainColor();
    int getRangeNumber();
    std::vector<std::pair<int,int>> getRange();
    QHash<int,int> getFate();
    std::vector<cellData> getMapData();
    void setMainRule(std::vector<std::pair<int,int>> range, int num, QHash<int,int> fate);

    //when finish setting, use this to init data into mainwindow
    void initMapData();
    void cleanMapData();
    void setMapData(int row, int col, QColor color);
    void setAllMapData(std::vector<cellData> datas);

    //next and last step
    void showCellData(int row, int col);
    void generateNext();
    void generatePre();

    //use stact to save last steps
    void pushData();
    bool stackIsEmpty();
    void showTop();
    void cleanStack();

    //test
    void showInformation();
    QColor getCellColor(int row, int col);
    std::vector<std::vector<QColor>> buildColors();

    int testcount(int row, int col); //test

private:

    bool isAlive(const cellData& cell);
    int countAliveNeighbors(int row, int col);
    void generateNextHelper();
    void generatePreHelper();

};

#endif // GAMELOGIC_H
