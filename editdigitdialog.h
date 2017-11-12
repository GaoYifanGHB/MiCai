/**
 * @brief
 *  用于编辑数码迷彩
 *  将数码迷彩画出，并通过鼠标点击来编辑数码迷彩
 * @author GaoYifan
 */
#ifndef EDITDIGITDIALOG_H
#define EDITDIGITDIALOG_H

#include <QDialog>
#include"digit.h"
#include<QPainter>
#include<QMouseEvent>
#include<iostream>
using namespace std;

namespace Ui {
class EditDigitDialog;
}

class EditDigitDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EditDigitDialog(QWidget *parent = 0);
    //设置要编辑的数码迷彩
    void setDigit(Digit d,int n);
    //设置网格尺寸
    void initGridSize(int l,int w);
    //对一个小格子涂色
    void drawOneGrid(int,int,QColor );
    ~EditDigitDialog();
signals:
    //将已经编辑好的数码迷彩发送回父窗口
    void sendDigit(Digit,int);
protected:
    //处理画图事件
    void paintEvent(QPaintEvent *event);
    //处理鼠标点击
    void mousePressEvent(QMouseEvent *event);
private slots:
    //确认按钮点击事件
    void on_buttonBox_accepted();

private:
    //要编辑的数码迷彩
    Digit d;
    //数码迷彩在整个数码迷彩列表（见digitManager）中的位置
    int n;
    //转换为绝对坐标
    int toRX(int x);
    int toRY(int y);
    //网格尺寸
    int gridsize;
    Ui::EditDigitDialog *ui;
};

#endif // EDITDIGITDIALOG_H
