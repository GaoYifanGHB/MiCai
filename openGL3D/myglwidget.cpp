#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    translate=-6.0;
    xRot=yRot=zRot=0.0;
}

void MyGLWidget::setSize(double l, double w, double h)
{
    this->l=l;
    this->w=w;
    this->h=h;
}

void MyGLWidget::initializeGL()
{
    glClearColor(0.0,0.0,0.0,0.5);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glDepthFunc(GL_LEQUAL);
    side_center=bindTexture(QPixmap("side_c.png"));
    side_up=bindTexture(QPixmap("side_u.png"));
    side_down=bindTexture(QPixmap("side_d.png"));
    side_left=bindTexture(QPixmap("side_l.png"));

    side_right=bindTexture(QPixmap("side_r.png"));
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    cout<<side_center<<endl;
}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,(GLint)w,(GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(GLfloat)w/(GLfloat)h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,translate);
    glRotatef(xRot,1.0,0.0,0.0);
    glRotatef(yRot,0.0,1.0,0.0);
    glRotatef(zRot,0.0,0.0,1.0);
    //上面
    glBindTexture(GL_TEXTURE_2D,side_center);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0,1.0);glVertex3f(w/2,h/2,l/2);
    glTexCoord2f(0.0,1.0);glVertex3f(w/2,h/2,-l/2);
    glTexCoord2f(0.0,0.0);glVertex3f(-w/2,h/2,-l/2);
    glTexCoord2f(1.0,0.0);glVertex3f(-w/2,h/2,l/2);
    glEnd();
    //下面
    glBindTexture(GL_TEXTURE_2D,side_center);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0,0.0);glVertex3f(w/2,-h/2,l/2);
    glTexCoord2f(1.0,1.0);glVertex3f(w/2,-h/2,-l/2);
    glTexCoord2f(0.0,1.0);glVertex3f(-w/2,-h/2,-l/2);
    glTexCoord2f(0.0,0.0);glVertex3f(-w/2,-h/2,l/2);
    glEnd();
    //后面
    glBindTexture(GL_TEXTURE_2D,side_up);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0,1.0);glVertex3f(w/2,h/2,-l/2);
    glTexCoord2f(0.0,1.0);glVertex3f(-w/2,h/2,-l/2);
    glTexCoord2f(0.0,0.0);glVertex3f(-w/2,-h/2,-l/2);
    glTexCoord2f(1.0,0.0);glVertex3f(w/2,-h/2,-l/2);
    glEnd();
    //前面
    glBindTexture(GL_TEXTURE_2D,side_down);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0,1.0);glVertex3f(w/2,h/2,l/2);
    glTexCoord2f(0.0,1.0);glVertex3f(-w/2,h/2,l/2);
    glTexCoord2f(0.0,0.0);glVertex3f(-w/2,-h/2,l/2);
    glTexCoord2f(1.0,0.0);glVertex3f(w/2,-h/2,l/2);
    glEnd();

    //右面
    glBindTexture(GL_TEXTURE_2D,side_right);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0);glVertex3f(w/2,h/2,l/2);
    glTexCoord2f(0.0,0.0);glVertex3f(w/2,h/2,-l/2);
    glTexCoord2f(1.0,0.0);glVertex3f(w/2,-h/2,-l/2);
    glTexCoord2f(1.0,1.0);glVertex3f(w/2,-h/2,l/2);
    glEnd();

    //左面
    glBindTexture(GL_TEXTURE_2D,side_left);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0,1.0);glVertex3f(-w/2,h/2,l/2);
    glTexCoord2f(0.0,0.0);glVertex3f(-w/2,h/2,-l/2);
    glTexCoord2f(1.0,0.0);glVertex3f(-w/2,-h/2,-l/2);
    glTexCoord2f(1.0,1.0);glVertex3f(-w/2,-h/2,l/2);
    glEnd();
}

void MyGLWidget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        zRot+=10;
        break;
    case Qt::Key_Down:
        zRot-=10;
        break;
    case Qt::Key_Left:
        xRot+=10;
        break;
    case Qt::Key_Right:
        xRot-=10;
        break;
    case Qt::Key_A:
        translate+=1;
        break;
    case Qt::Key_D:
        translate-=1;
        break;
    }
    updateGL();
    QGLWidget::keyPressEvent(event);
}
