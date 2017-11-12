/**
 * @brief
 *  数码迷彩的主窗口，主要用于完成与客户的交互
 *  其中包含用于显示数码迷彩的子窗口widget，
 *  通过设置widget的相关参数，来显示数码迷彩
 * @author GaoYifan
 */
#ifndef DIGITMAINWINDOW_H
#define DIGITMAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include "widget.h"
#include "setsizedialog.h"
#include "colorDialog/dialog.h"
#include "fileHandle/filehandle.h"
#include "openGL3D/myglwidget.h"
#include "colorHandle/picturehandle.h"
#include <string>
#include <QProcess>

namespace Ui {
class DigitMainWindow;
}

class DigitMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DigitMainWindow(QWidget *parent = 0);
    ~DigitMainWindow();
    //子窗口，该窗口为迷彩显示区域
    Widget *childWidget;
    //新建迷彩时设置迷彩尺寸对话框
    setSizeDialog *sizedg;
    //设置迷彩颜色对话框
    Dialog *colordg;
    //重置尺寸
    void updateSizeShow();

public slots:
    //用于接收从setSizeDialog发送回来的迷彩尺寸数据
    void setSize(int l,int w,int h);
    //用于接收从colordg发送回来的迷彩颜色数据
    void setColors(vector<QColor>cls,vector<int>rls);
protected:
    //处理绘图事件
    void paintEvent(QPaintEvent *event);
private slots:
    //新建文件
    void on_actionNew_triggered();
    //编辑迷彩小块
    void on_radioButton_released();
    //移动数码迷彩小块
    void on_radioButton_2_released();
    //保存数码迷彩
    void on_actionSave_triggered();
    //打开数码迷彩
    void on_actionOpen_triggered();

    void on_action3dShow_triggered();

    void on_actionKeyshot_triggered();

private:
    Ui::DigitMainWindow *ui;
    int h,l,w;
    //用户处理文件的打开，保存等工作
    FileHandle *fileHandle;
    //颜色及比例
    vector<QColor> cls;
    vector<int> rls;
};

#endif // DIGITMAINWINDOW_H
