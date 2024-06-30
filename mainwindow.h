#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <vector>
#include <QToolBar>
#include <QPushButton>
#include <QDoubleSpinBox>
#include <QTimer>
#include "GameLogic.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //when finish setting, use this to init
    std::vector<std::vector<QColor>> getCellColors();
    void initInfo(QString title, QColor color, int size, std::vector<std::pair<int,int>> range, int num, QHash<int,int> fate);
    void initNumCells(int num);
    void initCellColors(int size);
    void initAllCellColors(std::vector<std::vector<QColor>> colors);
    void rebuildMapData();
    void setTitle();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override; //move
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override; //zoom
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;

private slots:
    void playButtonClicked();
    void saveButtonClicked();
    void nextStepButtonClicked();
    void lastStepButtonClicked();
    void clearButtonClicked();

    void timeControlBoxValueChanged(double arg1);
    void paintNext();

    void openHelpDoc();

private:

    void setControls(bool arg); //when playing, can't operate
    bool checktimeInterval(); //time too long or short
    void paintPre(); //last step

private:

    QPushButton *playButton;
    QPushButton *saveButton;
    QPushButton *nextStepButton;
    QPushButton *lastStepButton;
    QPushButton *clearButton;
    QPushButton *titleButton;

    QAction *helpAction;

    QDoubleSpinBox *timeControlBox;


private:

    Information information;
    int numCells = 64;
    const int gridSize = 10;
    double timeInterval = 1.00;
    bool mousePressed;
    bool isNext = true;
    QPoint lastMousePos;
    QPoint gridOffset;
    QPoint centerPoint; // center point
    double zoomFactor = 1.0; // zoom

    QPoint hoveredCell;

    std::vector<std::vector<QColor>> cellColors;


    QTimer *generateTimer;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
