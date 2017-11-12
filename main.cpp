#include <QApplication>
#include "digitmainwindow.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <QTextCodec>
#include "window/MainWindow.h"
#include <QGLWidget>
#include "drawWidget/drawwidget.h"
#include"myScrollDialog/myqscrollarea.h"
#include <QTextCodec>
#include<window/controlthread.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    MainWindow *w=new MainWindow;
    controlThread *control=new controlThread;
    w->getControlThread(control);
    control->getMainWindow(w);
    DrawWidget *centralDraw=new DrawWidget(w);
    myQScrollArea *pArea= new myQScrollArea;


    pArea->setWidget(centralDraw);
    w->setCentralWidget(pArea);
    pArea->getDrawWidget(centralDraw);
    w->getCentral(centralDraw);
    w->showMaximized();
    centralDraw->getMainArea(w,pArea);
    a.setWindowIcon(QIcon("../draw/icon/myapp.ico"));
    w->setWindowTitle(QWidget::tr("迷彩自动生成系统"));
    return a.exec();

}
