QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    e-module/src/E-Receipt/jab_enc.c \
    e-module/src/protobuf/main.pb.cc \
    e-module/src/E-Receipt/utils.c \
    billmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    printbilldialog.cpp

HEADERS += \
    e-module/src/E-Receipt/jab_enc.h \
    jabcode.h \
    e-module/src/protobuf/main.pb.h \
    e-module/src/E-Receipt/utils.h \
    billmodel.h \
    mainwindow.h \
    printbilldialog.h

FORMS += \
    mainwindow.ui \
    printbilldialog.ui

LIBS += -pthread -I/usr/local/include -L/usr/local/lib -lprotobuf -lpthread -lstdc++ -lpng16

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    e-module/src/protobuf/main.proto

unix: LIBS += -L$$PWD/e-module/src/E-Receipt/build/ -lRG

INCLUDEPATH += $$PWD/e-module/src/jabcode/src/jabcode/include
DEPENDPATH += $$PWD/e-module/src/jabcode/src/jabcode/include

unix: PRE_TARGETDEPS += $$PWD/e-module/src/E-Receipt/build/libRG.a

unix: LIBS += -L$$PWD/e-module/src/jabcode/src/jabcode/build/ -ljabcode

INCLUDEPATH += $$PWD/e-module/src/jabcode/src/jabcode/include
DEPENDPATH += $$PWD/e-module/src/jabcode/src/jabcode/include

unix: PRE_TARGETDEPS += $$PWD/e-module/src/jabcode/src/jabcode/build/libjabcode.a
