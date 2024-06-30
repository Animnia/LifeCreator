/********************************************************************************
** Form generated from reading UI file 'StartWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *LabelWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *controlWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_7;
    QWidget *widget_4;
    QWidget *buttonsWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *startButton;
    QPushButton *loadButton;
    QPushButton *helpButton;
    QWidget *widget_6;
    QWidget *widget_5;
    QLabel *label_2;

    void setupUi(QWidget *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(541, 367);
        verticalLayout = new QVBoxLayout(StartWindow);
        verticalLayout->setObjectName("verticalLayout");
        LabelWidget = new QWidget(StartWindow);
        LabelWidget->setObjectName("LabelWidget");
        QFont font;
        font.setPointSize(30);
        LabelWidget->setFont(font);
        verticalLayout_2 = new QVBoxLayout(LabelWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(LabelWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);


        verticalLayout->addWidget(LabelWidget);

        controlWidget = new QWidget(StartWindow);
        controlWidget->setObjectName("controlWidget");
        QFont font1;
        font1.setPointSize(11);
        controlWidget->setFont(font1);
        horizontalLayout = new QHBoxLayout(controlWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_7 = new QWidget(controlWidget);
        widget_7->setObjectName("widget_7");

        horizontalLayout->addWidget(widget_7);

        widget_4 = new QWidget(controlWidget);
        widget_4->setObjectName("widget_4");

        horizontalLayout->addWidget(widget_4);

        buttonsWidget = new QWidget(controlWidget);
        buttonsWidget->setObjectName("buttonsWidget");
        verticalLayout_3 = new QVBoxLayout(buttonsWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        startButton = new QPushButton(buttonsWidget);
        startButton->setObjectName("startButton");

        verticalLayout_3->addWidget(startButton);

        loadButton = new QPushButton(buttonsWidget);
        loadButton->setObjectName("loadButton");

        verticalLayout_3->addWidget(loadButton);

        helpButton = new QPushButton(buttonsWidget);
        helpButton->setObjectName("helpButton");

        verticalLayout_3->addWidget(helpButton);


        horizontalLayout->addWidget(buttonsWidget);

        widget_6 = new QWidget(controlWidget);
        widget_6->setObjectName("widget_6");

        horizontalLayout->addWidget(widget_6);

        widget_5 = new QWidget(controlWidget);
        widget_5->setObjectName("widget_5");
        label_2 = new QLabel(widget_5);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 130, 61, 21));
        QFont font2;
        font2.setPointSize(8);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(widget_5);


        verticalLayout->addWidget(controlWidget);


        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QWidget *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "start", nullptr));
        label->setText(QCoreApplication::translate("StartWindow", "LifeCreator", nullptr));
        startButton->setText(QCoreApplication::translate("StartWindow", "\345\210\233\345\273\272\351\241\271\347\233\256", nullptr));
        loadButton->setText(QCoreApplication::translate("StartWindow", "\345\212\240\350\275\275\351\241\271\347\233\256", nullptr));
        helpButton->setText(QCoreApplication::translate("StartWindow", "\346\225\231\347\250\213", nullptr));
        label_2->setText(QCoreApplication::translate("StartWindow", "Animnia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
