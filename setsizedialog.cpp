#include "setsizedialog.h"
#include "ui_setsizedialog.h"

setSizeDialog::setSizeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setSizeDialog)
{
    ui->setupUi(this);
    ui->len_et->setText("200");
    ui->wid_et->setText("300");
    ui->hei_et->setText("100");
}

setSizeDialog::~setSizeDialog()
{
    delete ui;
}
//点击取消按钮
void setSizeDialog::on_pushButton_2_clicked()
{
    this->close();
}
//点击发送按钮
void setSizeDialog::on_pushButton_clicked()
{
    int h=ui->hei_et->text().toInt();
    int w=ui->wid_et->text().toInt();
    int l=ui->len_et->text().toInt();
    emit sendSize(l,w,h);
    this->close();
}
