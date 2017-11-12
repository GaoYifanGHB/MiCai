/**
 * @brief
 *  该类主要用于设置数码迷彩的尺寸
 *  主要功能为输入数码迷彩的尺寸，然后将数码迷彩的尺寸以信号的形式发送给父窗口(DigitMainWindow)
 * @author GaoYifan
 */
#ifndef SETSIZEDIALOG_H
#define SETSIZEDIALOG_H

#include <QDialog>

namespace Ui {
class setSizeDialog;
}

class setSizeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit setSizeDialog(QWidget *parent = 0);
    ~setSizeDialog();
    
private slots:
    //取消按钮点击事件
    void on_pushButton_2_clicked();
    //确认按钮点击事件
    void on_pushButton_clicked();
signals:
    //用于发送给父窗口的信号，将尺寸传递给父窗口
    void sendSize(int,int,int);
private:
    Ui::setSizeDialog *ui;
};

#endif // SETSIZEDIALOG_H
