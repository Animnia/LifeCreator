#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QPainter>
#include <QMouseEvent>
#include <QHash>
#include <vector>
#include "mainwindow.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class SettingWindow;
}
QT_END_NAMESPACE

class SettingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SettingWindow(MainWindow *mainWindow, QWidget *parent = nullptr);
    ~SettingWindow();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void nextButtonClicked();

private:
    std::vector<std::pair<int,int>> range;
    int rangeNum = 8;
    QHash<int,int> fate;
    QString title = "LifeGameProject";
    QColor color = Qt::black;
    int size = 64;
    std::vector<std::vector<QColor>> colors;

    //position
    int frameWidth = 8;
    int frameHeight = 2;
    int moveHeight_1 = 3;
    int moveHeight_2 = 8;
    int moveFix_x = 4;
    int moveFix_y = -2;

    //draw blocks
    struct GridCell {
        QRect rect;
        QColor color;
    };

    // 3 parts
    QVector<QVector<GridCell>> gridCells_;
    QVector<QVector<GridCell>> gridNums_;
    QVector<QVector<GridCell>> gridDieNums_;
    GridCell gridZero;
    GridCell gridDieZero;

    //click
    QLineEdit *titleEdit;
    QComboBox *colorBox;
    QComboBox *sizeBox;

    QPushButton *nextButton;
    MainWindow *mainWindow;
    Ui::SettingWindow *ui;

private:

    void drawGrid(QPainter *painter);
    void editTitle(const QString &text);
    void selectColor();
    void selectSize();
    void showGrid(QVector<QVector<GridCell>> grid);

    // use this to pack range and fate info, then used in mainwindow
    void changeRange();
    void changeFate();

public:

    //get info
    QString getTitle();
    int getSize();
    QColor getColor();
    std::vector<std::pair<int,int>> getRange();
    int getRangeNum();
    QHash<int,int> getFate();
    void init();
    std::vector<std::vector<QColor>> getColors();

    //set info
    void setTitle(QString t);
    void setSize(int s);
    void setColor(QColor c);
    void setRange(std::vector<std::pair<int,int>> r);
    void setRangeNum(int rn);
    void setFate(QHash<int,int> f);
    void setColors(std::vector<std::vector<QColor>> cs);

};
#endif // SETTINGWINDOW_H
