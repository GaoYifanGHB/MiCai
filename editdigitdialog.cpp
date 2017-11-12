#include "editdigitdialog.h"
#include "ui_editdigitdialog.h"

EditDigitDialog::EditDigitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDigitDialog)
{
    ui->setupUi(this);
}

EditDigitDialog::~EditDigitDialog()
{
    delete ui;
}
//设置数码迷彩
void EditDigitDialog::setDigit(Digit d,int n)
{
    this->d=d;
    this->n=n;
}
//初始化网格
void EditDigitDialog::initGridSize(int l, int w)
{
    double m=l>w?l:w;
    double n=height()>width()?height():width();
    n*=0.6;
    gridsize=(int)(n/m*10.0);

}
//根据坐标画一个小格子
void EditDigitDialog::drawOneGrid(int x, int y, QColor color)
{
    QPainter *painters=new QPainter(this);
    int cl=height()/3;
    int cw=width()/2;
    painters->fillRect(QRect(QPoint(cw+(x)*gridsize,cl+(y)*gridsize),QPoint(cw+(x+1)*gridsize,cl+(y+1)*gridsize)), QBrush(color));
    delete(painters);
}
//画图事件
void EditDigitDialog::paintEvent(QPaintEvent *event)
{
    QPainter *painters=new QPainter(this);

    int cy=height()/3;
    int cx=width()/2;
    initGridSize(d.getWidth(),d.getLength());
    gridsize=25;
    int w=d.getWidth();int l=d.getLength();
    int xs=-w/2,xe=w/2,ys=-l/2,ye=l/2;
    if(w%2)xe++;if(l%2)ye++;
    //画格
    for(int i=xs;i<=xe;i++){
        painters->drawLine(QPoint(cx+i*gridsize,cy+ys*gridsize),QPoint(cx+i*gridsize,cy+ye*gridsize));
    }
    for(int j=ys;j<=ye;j++){
        painters->drawLine(QPoint(cx+xs*gridsize,cy+j*gridsize),QPoint(cx+xe*gridsize,cy+j*gridsize));
    }
    //画小方块
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            if(d.mat[i][j]){
                drawOneGrid(xs+j,ys+i,d.getColor());
            }
        }
    }
    delete(painters);
}
//鼠标点击事件，点击没有颜色的小格子时，小格子出现颜色，点击有颜色的小格子时，小格子取消颜色
void EditDigitDialog::mousePressEvent(QMouseEvent *event)
{
    int w=d.getWidth();int l=d.getLength();
    int xs=-w/2,ys=-l/2;
    int x=toRX(event->x());
    int y=toRY(event->y());
    d.mat[y-ys+2][x-xs]=!d.mat[y-ys+2][x-xs];
    this->update();
}
//转换绝对坐标
int EditDigitDialog::toRX(int x)
{
    int cw=width()/2;
    int xx=x-cw;
    if(xx<0)xx-=gridsize;
    xx/=gridsize;
    return xx;
}
int EditDigitDialog::toRY(int y)
{
    int cl=height()/2;
    int yy=y-cl;
    if(yy<0)yy-=gridsize;
    yy/=gridsize;
    return yy;
}
//点击接受按钮，重新设置digit，然后发送回给父窗口

void EditDigitDialog::on_buttonBox_accepted()
{
    int num=0;
    for(int i=0;i<d.getLength();i++){
        for(int j=0;j<d.getWidth();j++){
            if(d.mat[i][j])num++;
        }
    }
    d.num=num;
    emit sendDigit(d,n);
}
