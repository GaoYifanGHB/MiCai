/**
 * @brief
 *  该类的主要作用从图片中提取主题色
 *  设计思路为：
 *  将图片的像素颜色与颜色库中颜色比较，
 *  获取颜色库中出现次数最多的四种颜色
 * @author GaoYifan
 */

#ifndef COLORHANDLE_H
#define COLORHANDLE_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<QColor>
#include<map>
#include<queue>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;
class ColorHandle
{
private:
    //最小可接受距离
    int minDist;
    //颜色及比例列表
    std::vector<int>rls;
    std::vector<cv::Vec3b>cls;
    std::vector<QColor> qcls;
    //颜色库中的颜色
    std::vector<cv::Vec3b>clcm;
    //颜色库中颜色在图中的像素点个数
    std::vector<long long>areas;

    //目标色
    cv::Vec3b target;
    //结果图像
    cv::Mat result;

    //计算与目标颜色的距离
    int getDistance(cv::Vec3b color)
    {
        return abs(color[0] - target[0])*abs(color[0] - target[0])
                + abs(color[1] - target[1])*abs(color[1] - target[1])
                + abs(color[2] - target[2])*abs(color[2] - target[2]);
    }
    int getDistance(Vec3b color1,Vec3b color2);
public:
    long long i;
    void readVolorLib();
    //空构造函数
    ColorHandle():minDist(2500)
    {
        //初始化默认参数
        target[0] = target[1] = target[2] = 0;
        readVolorLib();
    }
    //颜色列表及比例
    vector<QColor> getCls();
    vector<int> getRls();
    //设置最小距离
    void setColorDistanceThreshold(int distance);
    int getColorDistanceThreshold() const;
    //设置目标颜色
    void setTargetColor(unsigned char red, unsigned char green, unsigned char blue);
    void setTargetColor(cv::Vec3b color);
    //获取目标颜色
    cv::Vec3b getTargetColor() const;
    //计算并生成主题色及比例
    void calculate(const cv::Mat &image);
    cv::Mat process(const cv::Mat &image);
    void setColor(Vec3b &tc, int r, int g, int b);
};

#endif // COLORHANDLE_H
