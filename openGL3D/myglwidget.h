
#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include<iostream>
#include <QKeyEvent>
using namespace std;

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    void setSize(double l,double w,double h);

protected:
    void initializeGL();
    GLuint side_up;
    GLuint side_center;
    GLuint side_down;
    GLuint side_left;
    GLuint side_right;
    void resizeGL(int w, int h);
    void paintGL();
    void keyPressEvent(QKeyEvent *event);
private:
    GLfloat translate,xRot,yRot,zRot;
    double l,w,h;

signals:
    
public slots:
    
};

#endif // MYGLWIDGET_H
