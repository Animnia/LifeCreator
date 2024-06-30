/********************************************************************************
** Form generated from reading UI file 'WarnWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNWINDOW_H
#define UI_WARNWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WarnWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;

    void setupUi(QWidget *WarnWindow)
    {
        if (WarnWindow->objectName().isEmpty())
            WarnWindow->setObjectName("WarnWindow");
        WarnWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(WarnWindow);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(WarnWindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget = new QWidget(WarnWindow);
        widget->setObjectName("widget");

        verticalLayout->addWidget(widget);


        retranslateUi(WarnWindow);

        QMetaObject::connectSlotsByName(WarnWindow);
    } // setupUi

    void retranslateUi(QWidget *WarnWindow)
    {
        WarnWindow->setWindowTitle(QCoreApplication::translate("WarnWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("WarnWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WarnWindow: public Ui_WarnWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNWINDOW_H
