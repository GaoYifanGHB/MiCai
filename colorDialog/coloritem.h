/**
 * @brief
 *  该类为颜色对话框中颜色列表的item
 *  用于输入并记录颜色和比例
 * @author GaoYifan
 */
#ifndef COLORITEM_H
#define COLORITEM_H

#include <QWidget>
#include<QRect>
#include<QMouseEvent>
#include <QPainter>
#include<QColorDialog>
#include<iostream>
using namespace std;

namespace Ui {
class ColorItem;
}

class ColorItem : public QWidget
{
    Q_OBJECT
    
public:
    explicit ColorItem(QWidget *parent = 0);
    QColor color;
    QRect rect;
    //设置与获取比例
    void setData(int num,QColor color);
    int getNum();
    ~ColorItem();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);
private:
    Ui::ColorItem *ui;
};

#endif // COLORITEM_H
