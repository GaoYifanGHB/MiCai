
#-------------------------------------------------
#
# Project created by QtCreator 2017-10-25T15:13:01
#
#-------------------------------------------------

QT       += core gui
QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MiCai
TEMPLATE = app
INCLUDEPATH +=D:\OpenCV\MinGW\install\include
INCLUDEPATH +=D:\OpenCV\MinGW\install\include\opencv


LIBS+=D:\OpenCV\MinGW\install\lib\*.a\


HEADERS += \
    setsizedialog.h \
    editdigitdialog.h \
    digitmananger.h \
    digit.h \
    colorDialog/dialog.h \
    colorDialog/coloritem.h \
    colorHandle/picturehandle.h \
    colorHandle/colorhandle.h \
    fileHandle/filehandle.h \
    openGL3D/myglwidget.h \
    digitmainwindow.h \
    widget.h \
    caculate/savespot.h \
    caculate/getpoint.h \
    caculate/getcurvature.h \
    caculate/colorm.h \
    drawWidget/spot.h \
    drawWidget/drawwidget.h \
    myScrollDialog/myqscrollarea.h \
    myScrollDialog/mydialog.h \
    qtPropertyBrowser/qtvariantproperty.h \
    qtPropertyBrowser/qttreepropertybrowser.h \
    qtPropertyBrowser/qtpropertymanager.h \
    qtPropertyBrowser/qtpropertybrowserutils_p.h \
    qtPropertyBrowser/qtpropertybrowser.h \
    qtPropertyBrowser/qtgroupboxpropertybrowser.h \
    qtPropertyBrowser/qteditorfactory.h \
    qtPropertyBrowser/qtbuttonpropertybrowser.h \
    window/wumainwin.h \
    window/spotColorAll.h \
    window/mythread.h \
    window/MainWindow.h \
    window/controlthread.h \
    window/childwindow.h \
    model/wumian.h \
    model/glm.h \
    model/fiveview.h \
    model/first_opengl.h

SOURCES += \
    setsizedialog.cpp \
    editdigitdialog.cpp \
    digitmananger.cpp \
    digit.cpp \
    colorDialog/dialog.cpp \
    colorDialog/coloritem.cpp \
    colorHandle/picturehandle.cpp \
    colorHandle/colorhandle.cpp \
    fileHandle/filehandle.cpp \
    openGL3D/myglwidget.cpp \
    digitmainwindow.cpp \
    widget.cpp \
    caculate/savespot.cpp \
    caculate/getpoint.cpp \
    caculate/getcurvature.cpp \
    caculate/colorm.cpp \
    drawWidget/spot.cpp \
    drawWidget/drawWidget.cpp \
    myScrollDialog/myqscrollarea.cpp \
    myScrollDialog/mydialog.cpp \
    qtPropertyBrowser/qtvariantproperty.cpp \
    qtPropertyBrowser/qttreepropertybrowser.cpp \
    qtPropertyBrowser/qtpropertymanager.cpp \
    qtPropertyBrowser/qtpropertybrowserutils.cpp \
    qtPropertyBrowser/qtpropertybrowser.cpp \
    qtPropertyBrowser/qtgroupboxpropertybrowser.cpp \
    qtPropertyBrowser/qteditorfactory.cpp \
    qtPropertyBrowser/qtbuttonpropertybrowser.cpp \
    window/wumainwin.cpp \
    window/mythread.cpp \
    window/mainWindow.cpp \
    window/controlthread.cpp \
    window/childwindow.cpp \
    model/wumian.cpp \
    model/glm.cpp \
    model/fiveview.cpp \
    model/first_opengl.cpp \
    main.cpp

FORMS += \
    setsizedialog.ui \
    editdigitdialog.ui \
    colorDialog/dialog.ui \
    colorDialog/coloritem.ui \
    digitmainwindow.ui \
    widget.ui \
    wumainwin.ui \
    mydialog.ui \
    childwindow.ui \
    mainwindow.ui
