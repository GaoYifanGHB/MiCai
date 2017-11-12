/**
 * @brief
 *  该类用于将生成的数码迷彩保存为PNG格式文件
 * @author GaoYifan
 */
#ifndef PICTUREHANDLE_H
#define PICTUREHANDLE_H
#include"digitmananger.h"
#include<string>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
class PictureHandle
{
public:
    PictureHandle();
    void setSize(int l,int w,int h);
    void setBgColor(QColor bgcolor);
    void setDigitManager(DigitMananger dm);
    void drawToPicture();

private:
    int l,w,h;
    DigitMananger dm;
    QColor bgcolor;
    void drawOneGrid(int x,int y,QColor color,Mat &mat);
    void drawBgColor(Mat &mat);
    void drawOneDigit(Digit d,int dx,int dy,Mat &mat);
    void writeToFile(Mat mat,string filename);
};

#endif // PICTUREHANDLE_H
