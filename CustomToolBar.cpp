#include "CustomToolBar.h"
#include <QPainter>
#include <QPushButton>

CustomToolBar::CustomToolBar(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(30);  // 设置工具栏高度
    auto *button = new QPushButton("Button", this);  // 创建按钮
    button->move(0, 0);  // 定位按钮

}

void CustomToolBar::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor lightBlue(173, 216, 230);  // 创建淡蓝色
    painter.fillRect(rect(), lightBlue);  // 使用自定义的颜色
}
