QT       += core gui
QT       += network
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    add_train.cpp \
    add_user.cpp \
    loginwidget.cpp \
    main.cpp \
    mainwidget.cpp \
    modify_profile.cpp \
    registerfirstuser.cpp \
    ticket_operation.cpp \
    widget.cpp

HEADERS += \
    add_train.h \
    add_user.h \
    loginwidget.h \
    mainwidget.h \
    modify_profile.h \
    registerfirstuser.h \
    ticket_operation.h \
    widget.h

FORMS += \
    add_train.ui \
    add_user.ui \
    loginwidget.ui \
    mainwidget.ui \
    modify_profile.ui \
    registerfirstuser.ui \
    ticket_operation.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img_src.qrc
