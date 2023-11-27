QT       += core gui printsupport widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

qmake
TARGET = ../Calculator

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../controller/calculator/calculator_controller.cc \
    ../model/calculator/calculator_model.cc \
    ../controller/credit/credit_controller.cc \
    ../model/credit/credit_model.cc \
    ../controller/deposit/deposit_controller.cc \
    ../model/deposit/deposit_model.cc \
    credit/credit.cc \
    deposit/deposit.cc \
    graph/graph.cc \
    calculator/calculator.cc \
    main.cc \
    graph/qcustomplot.cc

HEADERS += \
    ../controller/calculator/calculator_controller.h \
    ../model/calculator/calculator_model.h \
    ../controller/credit/credit_controller.h \
    ../model/credit/credit_model.h \
    ../controller/deposit/deposit_controller.h \
    ../model/deposit/deposit_model.h \
    calculator/calculator.h \
    credit/credit.h \
    deposit/deposit.h \
    graph/graph.h \
    graph/qcustomplot.h

FORMS += \
    calculator/calculator.ui \
    credit/credit.ui \
    deposit/deposit.ui \
    graph/graph.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
