#ifndef CUSTOMTOOLBAR_H
#define CUSTOMTOOLBAR_H

#include <QWidget>

class CustomToolBar : public QWidget
{
    Q_OBJECT

public:
    CustomToolBar(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;  // 用于绘制工具栏背景
};

#endif // CUSTOMTOOLBAR_H
