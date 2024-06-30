/********************************************************************************
** Form generated from reading UI file 'SettingWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QLineEdit *titleEdit;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *colorBox;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *sizeBox;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_4;
    QWidget *mapWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *nextButton;

    void setupUi(QWidget *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName("SettingWindow");
        SettingWindow->resize(600, 500);
        horizontalLayout_2 = new QHBoxLayout(SettingWindow);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        widget_2 = new QWidget(SettingWindow);
        widget_2->setObjectName("widget_2");
        QFont font;
        font.setPointSize(13);
        widget_2->setFont(font);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget_2);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        widget = new QWidget(widget_2);
        widget->setObjectName("widget");
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        QFont font2;
        font2.setPointSize(10);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_4);

        titleEdit = new QLineEdit(widget);
        titleEdit->setObjectName("titleEdit");
        titleEdit->setFont(font2);

        horizontalLayout_5->addWidget(titleEdit);


        verticalLayout_2->addWidget(widget);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName("widget_4");
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        colorBox = new QComboBox(widget_4);
        colorBox->setObjectName("colorBox");
        colorBox->setFont(font2);

        horizontalLayout_3->addWidget(colorBox);


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName("widget_5");
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(widget_5);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_3);

        sizeBox = new QComboBox(widget_5);
        sizeBox->setObjectName("sizeBox");
        sizeBox->setFont(font2);

        horizontalLayout_4->addWidget(sizeBox);


        verticalLayout_2->addWidget(widget_5);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName("label_5");
        QFont font3;
        font3.setPointSize(12);
        label_5->setFont(font3);

        verticalLayout_2->addWidget(label_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font3);

        verticalLayout_2->addWidget(label_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_2->addWidget(widget_2);

        mapWidget = new QWidget(SettingWindow);
        mapWidget->setObjectName("mapWidget");
        verticalLayout = new QVBoxLayout(mapWidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_5);

        label_7 = new QLabel(mapWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(label_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        verticalLayout->addItem(horizontalSpacer_2);

        widget_3 = new QWidget(mapWidget);
        widget_3->setObjectName("widget_3");
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        nextButton = new QPushButton(widget_3);
        nextButton->setObjectName("nextButton");

        horizontalLayout->addWidget(nextButton);


        verticalLayout->addWidget(widget_3);


        horizontalLayout_2->addWidget(mapWidget);


        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("SettingWindow", "\350\256\276\345\256\232\346\270\270\346\210\217\350\247\204\345\210\231(\351\273\230\350\256\244\344\270\272Conway\357\274\211", nullptr));
        label_4->setText(QCoreApplication::translate("SettingWindow", "\351\241\271\347\233\256\345\220\215\347\247\260", nullptr));
        titleEdit->setText(QCoreApplication::translate("SettingWindow", "LifeGameProject", nullptr));
        titleEdit->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("SettingWindow", "\347\273\206\350\203\236\351\242\234\350\211\262", nullptr));
        colorBox->setCurrentText(QString());
        colorBox->setPlaceholderText(QCoreApplication::translate("SettingWindow", "\351\273\221\350\211\262", nullptr));
        label_3->setText(QCoreApplication::translate("SettingWindow", "\347\275\221\346\240\274\345\244\247\345\260\217", nullptr));
        sizeBox->setPlaceholderText(QCoreApplication::translate("SettingWindow", "64 * 64", nullptr));
        label_5->setText(QCoreApplication::translate("SettingWindow", "\350\256\276\347\275\256\346\226\260\347\273\206\350\203\236\344\272\247\347\224\237\346\211\200\351\234\200\347\232\204\345\221\250\345\233\264\347\273\206\350\203\236\346\225\260\347\233\256", nullptr));
        label_6->setText(QCoreApplication::translate("SettingWindow", "\350\256\276\347\275\256\347\273\206\350\203\236\346\255\273\344\272\241\346\211\200\351\234\200\347\232\204\345\221\250\345\233\264\347\273\206\350\203\236\346\225\260\347\233\256", nullptr));
        label_7->setText(QCoreApplication::translate("SettingWindow", "\345\234\250\344\270\213\346\226\271\351\200\211\346\213\251\345\215\225\344\270\252\347\273\206\350\203\236\345\217\227\345\275\261\345\223\215\347\232\204\350\214\203\345\233\264", nullptr));
        nextButton->setText(QCoreApplication::translate("SettingWindow", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
