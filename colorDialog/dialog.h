/**
 * @brief
 *  设置颜色的对话框，生成迷彩时，用户输入迷彩的颜色及比例
 *  可通过快速主题选择颜色，也可通过图像识别出主题色
 * @author GaoYifan
 */
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "coloritem.h"
#include<iostream>
#include <QFileDialog>
#include"colorHandle/colorhandle.h"
using namespace std;


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    //添加一个颜色
    void addItem(int r,QColor color);
    void deleteItem(int i);
    ~Dialog();
signals:
    //将颜色列表发送回父窗口
    void sendColor(vector<QColor>,vector<int>);
private slots:
    //添加颜色按钮点击事件
    void on_pushButton_clicked();
    //确认按钮点击事件
    void on_pushButton_3_clicked();
    //关闭按钮点击事件
    void on_pushButton_2_clicked();

    //--------------各类主题被选择事件------------
    void on_radioButton_2_released();

    void on_radioButton_3_released();

    void on_radioButton_released();

    void on_radioButton_4_released();

    void on_radioButton_5_released();
    //--------------------------------------

    //由图片生成数码迷彩按钮点击
    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
