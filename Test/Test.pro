######################################################################
# Automatically generated by qmake (3.1) Sun Jul 12 16:07:30 2020
######################################################################
CONFIG += c++17
QT+=testlib

TEMPLATE = app
TARGET = Test
INCLUDEPATH += .

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
SOURCES += \
    testModels/arraymodel.cpp \
    testModels/arrayviewmodel.cpp \
    testModels/treemodel.cpp \
    testModels/treeviewmodel.cpp \
    unittest.cpp

HEADERS += \
    testModels/ArrayC.h \
    testModels/Tree.h \
    testModels/arraymodel.h \
    testModels/arrayviewmodel.h \
    testModels/etlbase.h \
    testModels/treemodel.h \
    testModels/treeviewmodel.h
