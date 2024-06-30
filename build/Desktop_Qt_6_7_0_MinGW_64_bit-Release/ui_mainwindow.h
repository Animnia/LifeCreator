/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action1;
    QAction *action2;
    QAction *action1_2;
    QAction *action2_2;
    QAction *action1_3;
    QAction *action2_3;
    QAction *action1_4;
    QAction *action2_4;
    QAction *action1_5;
    QAction *action2_5;
    QAction *actionlefttool1;
    QAction *helpAction;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QFrame *upFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *titleButton;
    QLabel *label;
    QDoubleSpinBox *timeControlBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;
    QSpacerItem *verticalSpacer;
    QFrame *downFrame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *lastStepButton;
    QPushButton *playButton;
    QPushButton *nextStepButton;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menuBar;
    QMenu *help;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(677, 559);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        action1 = new QAction(MainWindow);
        action1->setObjectName("action1");
        action2 = new QAction(MainWindow);
        action2->setObjectName("action2");
        action1_2 = new QAction(MainWindow);
        action1_2->setObjectName("action1_2");
        action2_2 = new QAction(MainWindow);
        action2_2->setObjectName("action2_2");
        action1_3 = new QAction(MainWindow);
        action1_3->setObjectName("action1_3");
        action2_3 = new QAction(MainWindow);
        action2_3->setObjectName("action2_3");
        action1_4 = new QAction(MainWindow);
        action1_4->setObjectName("action1_4");
        action2_4 = new QAction(MainWindow);
        action2_4->setObjectName("action2_4");
        action1_5 = new QAction(MainWindow);
        action1_5->setObjectName("action1_5");
        action2_5 = new QAction(MainWindow);
        action2_5->setObjectName("action2_5");
        actionlefttool1 = new QAction(MainWindow);
        actionlefttool1->setObjectName("actionlefttool1");
        actionlefttool1->setMenuRole(QAction::TextHeuristicRole);
        helpAction = new QAction(MainWindow);
        helpAction->setObjectName("helpAction");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        upFrame = new QFrame(centralwidget);
        upFrame->setObjectName("upFrame");
        upFrame->setAutoFillBackground(false);
        upFrame->setStyleSheet(QString::fromUtf8("background-color:rgb(91, 93, 93)"));
        upFrame->setFrameShape(QFrame::StyledPanel);
        upFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(upFrame);
        horizontalLayout->setObjectName("horizontalLayout");
        saveButton = new QPushButton(upFrame);
        saveButton->setObjectName("saveButton");
        saveButton->setEnabled(true);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("document-save")));
        saveButton->setIcon(icon);

        horizontalLayout->addWidget(saveButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        titleButton = new QPushButton(upFrame);
        titleButton->setObjectName("titleButton");

        horizontalLayout->addWidget(titleButton);

        label = new QLabel(upFrame);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        timeControlBox = new QDoubleSpinBox(upFrame);
        timeControlBox->setObjectName("timeControlBox");
        timeControlBox->setMinimum(0.100000000000000);
        timeControlBox->setSingleStep(0.100000000000000);
        timeControlBox->setValue(1.000000000000000);

        horizontalLayout->addWidget(timeControlBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(upFrame);
        clearButton->setObjectName("clearButton");

        horizontalLayout->addWidget(clearButton);


        verticalLayout_3->addWidget(upFrame);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        downFrame = new QFrame(centralwidget);
        downFrame->setObjectName("downFrame");
        downFrame->setStyleSheet(QString::fromUtf8("background-color:rgb(91, 93, 93)"));
        downFrame->setFrameShape(QFrame::StyledPanel);
        downFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(downFrame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        lastStepButton = new QPushButton(downFrame);
        lastStepButton->setObjectName("lastStepButton");

        horizontalLayout_2->addWidget(lastStepButton);

        playButton = new QPushButton(downFrame);
        playButton->setObjectName("playButton");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("media-playback-start")));
        playButton->setIcon(icon1);

        horizontalLayout_2->addWidget(playButton);

        nextStepButton = new QPushButton(downFrame);
        nextStepButton->setObjectName("nextStepButton");

        horizontalLayout_2->addWidget(nextStepButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(downFrame);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 677, 21));
        menuBar->setStyleSheet(QString::fromUtf8("background-color:rgb(64, 65, 66)"));
        help = new QMenu(menuBar);
        help->setObjectName("help");
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(help->menuAction());
        help->addAction(helpAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        action2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        action1_2->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        action2_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        action1_3->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        action2_3->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        action1_4->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        action2_4->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        action1_5->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        action2_5->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        actionlefttool1->setText(QCoreApplication::translate("MainWindow", "lefttool1", nullptr));
#if QT_CONFIG(tooltip)
        actionlefttool1->setToolTip(QCoreApplication::translate("MainWindow", "lefttool1", nullptr));
#endif // QT_CONFIG(tooltip)
        helpAction->setText(QCoreApplication::translate("MainWindow", "\346\225\231\347\250\213\346\226\207\346\241\243", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        titleButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\277\255\344\273\243\345\221\250\346\234\237 (\347\247\222)", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        lastStepButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\346\255\245", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        nextStepButton->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\346\255\245", nullptr));
        help->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
