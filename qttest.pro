QT       += core gui uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
RC_ICONS = LC.ico
TARGET = LifeCreator
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GameFile.cpp \
    GameLogic.cpp \
    SettingWindow.cpp \
    StartWindow.cpp \
    WarnWindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GameFile.h \
    GameLogic.h \
    SettingWindow.h \
    StartWindow.h \
    WarnWindow.h \
    mainwindow.h

FORMS += \
    SettingWindow.ui \
    StartWindow.ui \
    WarnWindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
