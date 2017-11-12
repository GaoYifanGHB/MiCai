/**
 * @brief
 *  该类用于保存和读取数码迷彩
 * @author GaoYifan
 */
#ifndef FILEHANDLE_H
#define FILEHANDLE_H
#include <fstream>
#include <sstream>
#include <string>
#include <digit.h>
#include <vector>
#include <digitmananger.h>
using namespace std;
class FileHandle
{
public:
    //构造函数
    FileHandle();
    FileHandle(string filename);
    //设置与获取digitmanager
    DigitMananger getDigitManager();
    void setDigitManager(DigitMananger dm);
    //设置与获取长宽高
    void getSize(int&l,int&w,int&h);
    void setSize(int l,int w,int h);
    //设置与获取颜色列表及比例
    void setColorList(vector<QColor>,vector<int>);
    void getColorList(vector<QColor>&,vector<int>&);
    //存入文件与读取文件
    void save();
    void read();
private:
    //文件名
    string filename;
    DigitMananger dm;
    int h,l,w;
    vector<QColor> cls;
    vector<int> rls;
    //读文件，写文件
    ofstream fout;
    ifstream fin;
    //存取长宽高
    void saveSize();
    void readSize();
    //存取颜色列表
    void saveColorList();
    void readColorList();
    //存取小斑块队列
    void saveDigitList();
    void readDigitList();
    //存取一个小斑块
    void saveOneDigit(Digit d);
    Digit readOneDigit();

};

#endif // FILEHANDLE_H
