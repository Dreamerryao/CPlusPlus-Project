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
    WINDOW/mode1_display.cpp \
    WINDOW/model1_main.cpp \
    WINDOW/sinks/mode1_displaycommandsink.cpp \
    WINDOW/sinks/mode2_displaycommandsink.cpp \
    WINDOW/sinks/mode2updatesink.cpp \
    WINDOW/sinks/opupdatesink.cpp \
    WINDOW/square.cpp \
    app/commands/aboutcommand.cpp \
    app/commands/cancelcommand.cpp \
    app/commands/changecommand.cpp \
    app/commands/m1command.cpp \
    app/commands/m2command.cpp \
    app/main.cpp \
    app/app.cpp \
    WINDOW/model2_main.cpp \
    model/arraymodel.cpp \
    model/treemodel.cpp \
    viewModel/arrayviewmodel.cpp \
    viewModel/commands/arrayaddcommand.cpp \
    viewModel/commands/arraydelcommand.cpp \
    viewModel/commands/arraynewcommand.cpp \
    viewModel/commands/arrayreplacecommand.cpp \
    viewModel/commands/queuedeqcommand.cpp \
    viewModel/commands/stackpopcommand.cpp \
    viewModel/commands/treedelcommand.cpp \
    viewModel/commands/treeinscommand.cpp \
    viewModel/sinks/arraymodelsink.cpp \
    viewModel/sinks/treemodelsink.cpp \
    viewModel/treeviewmodel.cpp \
    viewModel/commands/treenewcommand.cpp

HEADERS += \
    WINDOW/about.h \
    WINDOW/firstpage.h \
    WINDOW/mode1_display.h \
    WINDOW/model1_main.h \
    WINDOW/sinks/mode1_displaycommandsink.h \
    WINDOW/sinks/mode2_displaycommandsink.h \
    WINDOW/sinks/mode2updatesink.h \
    WINDOW/sinks/opupdatesink.h \
    WINDOW/square.h \
    app/app.h \
    app/commands/aboutcommand.h \
    app/commands/cancelcommand.h \
    app/commands/changecommand.h \
    app/commands/m1command.h \
    app/commands/m2command.h \
    common/ArrayC.h \
    common/Tree.h \
    common/etlbase.h \
    WINDOW/model2_main.h \
    model/arraymodel.h \
    model/treemodel.h \
    viewModel/arrayviewmodel.h \
    viewModel/commands/arrayaddcommand.h \
    viewModel/commands/arraydelcommand.h \
    viewModel/commands/arraynewcommand.h \
    viewModel/commands/arrayreplacecommand.h \
    viewModel/commands/queuedeqcommand.h \
    viewModel/commands/stackpopcommand.h \
    viewModel/commands/treedelcommand.h \
    viewModel/commands/treeinscommand.h \
    viewModel/sinks/arraymodelsink.h \
    viewModel/sinks/treemodelsink.h \
    viewModel/treeviewmodel.h \
    viewModel/commands/treenewcommand.h

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

CONFIG += c++17
CONFIG += resources_big

FORMS += \
    WINDOW/about.ui \
    WINDOW/firstpage.ui \
    WINDOW/mode1_display.ui \
    WINDOW/model1_main.ui \
    WINDOW/model2_main.ui

RESOURCES += \
    images.qrc
