QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    WINDOW/about.cpp \
    WINDOW/firstpage.cpp \
    WINDOW/model1_main.cpp \
    WINDOW/operation.cpp \
    WINDOW/testwindow.cpp \
    app/commands/aboutcommand.cpp \
    app/commands/cancelcommand.cpp \
    app/commands/changecommand.cpp \
    app/commands/getline.cpp \
    app/commands/m1command.cpp \
    app/commands/m2command.cpp \
    app/commands/testbuttoncommand.cpp \
    app/main.cpp \
    app/app.cpp \
    WINDOW/model2_main.cpp \
    model/arraymodel.cpp \
    viewModel/arrayviewmodel.cpp \
    viewModel/commands/arrayaddcommand.cpp \
    viewModel/sinks/arraymodelsink.cpp

HEADERS += \
    WINDOW/about.h \
    WINDOW/firstpage.h \
    WINDOW/model1_main.h \
    WINDOW/operation.h \
    WINDOW/testwindow.h \
    app/app.h \
    app/commands/aboutcommand.h \
    app/commands/cancelcommand.h \
    app/commands/changecommand.h \
    app/commands/getline.h \
    app/commands/m1command.h \
    app/commands/m2command.h \
    app/commands/testbuttoncommand.h \
    common/ArrayC.h \
    common/any.h \
    common/etlbase.h \
    WINDOW/model2_main.h \
    model/arraymodel.h \
    viewModel/arrayviewmodel.h \
    viewModel/commands/arrayaddcommand.h \
    viewModel/sinks/arraymodelsink.h

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

CONFIG += c++17

FORMS += \
    WINDOW/about.ui \
    WINDOW/firstpage.ui \
    WINDOW/model1_main.ui \
    WINDOW/operation.ui \
    WINDOW/testwindow.ui \
    WINDOW/model2_main.ui
