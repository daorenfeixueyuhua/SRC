/*使用DDA算法画线*/
#include <iostream>
using namespace std;
#include <GL/freeglut.h>
#include <stdio.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Windows.h>
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

//确定多边形绕法的方向
bool bWinding = true;
void myDisplay(void);
void setPixel(int x, int y);
int round(const float a);
void ChangeSize(GLsizei w, GLsizei h);
void lineDDA(int x0, int y0, int xEnd, int yEnd);

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // //旋转图形
    // glPushMatrix();
    // glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    // // glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    //设置点的大小以及线宽
    glPointSize(5.0f);
    glLineWidth(5.0f);

    //设置多边形绕法的方向是顺时针还是逆时针
    glPushMatrix();
    glRotatef(90, 200.0, 200.0, 0.0);
    //绘制三角形
    glBegin(GL_TRIANGLES);
    glVertex2i(50, 50);
    glVertex2i(50, 100);
    glVertex2i(100, 75);
    glEnd();
    glPopMatrix();

    //绘制三角形
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 50);
    glVertex2i(100, 100);
    glVertex2i(150, 75);
    glEnd();

    //绘制四边形
    glBegin(GL_QUADS);
    glVertex2i(100, 200);
    glVertex2i(150, 179);
    glVertex2i(125, 235);
    glVertex2i(100, 250);
    glEnd();

    //绘制四边形
    glBegin(GL_QUADS);
    glVertex2i(0, 200);
    glVertex2i(50, 200);
    glVertex2i(50, 236);
    glVertex2i(0, 225);
    glEnd();

    glutSwapBuffers();
}

void setPixel(int x, int y)
{

    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

int round(const float a)
{
    return int(a + 0.5);
}

void ChangeSize(GLsizei w, GLsizei h)
{
    if (h == 0)
        h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(0.0f, 250.0f, 0.0f, 250.0f * h / w, 1.0, -1.0);
    else
        glOrtho(0.0f, 250.0f * w / h, 0.0f, 250.0f, 1.0, -1.0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(400, 400);

    glMatrixMode(GL_PROJECTION || GL_MODELVIEW);
    //观察参数：x坐标值从0到200，y是从0到150
    gluOrtho2D(-350.0, 350.0, -350.0, 350.0);
    glutCreateWindow("Daily Practice");
    glutDisplayFunc(&myDisplay);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 0;
}