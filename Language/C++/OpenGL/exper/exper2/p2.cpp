/*使用DDA算法画线*/
#include <iostream>
using namespace std;
#include <GL/freeglut.h>
#include <stdio.h>
#include <Windows.h>

void myDisplay(void);
void setPixel(int x, int y);
int round(const float a);
void ChangeSize(GLsizei w, GLsizei h);
void lineDDA(int x0, int y0, int xEnd, int yEnd);

void CirclePoint(int x, int y, int offx, int offy)
{
    glPointSize(3.0f); //设置像素点大小
    setPixel(x + offx, y + offy);
    setPixel(y + offx, x + offy);
    setPixel(x + offx, -y + offy);
    setPixel(-y + offx, x + offy);
    setPixel(-x + offx, y + offy);
    setPixel(y + offx, -x + offy);
    setPixel(-x + offx, -y + offy);
    setPixel(-y + offx, -x + offy);
}

void MidPointCircle(int x1, int y1, int r)
{
    int x, y, e;
    x = 0;
    y = r;
    e = 1 - r;
    CirclePoint(x, y, x1, y1);
    while (x <= y)
    {
        if (e < 0)
            e += 2 * x + 3;
        else
        {
            e += 2 * (x - y) + 5;
            y--;
        }
        x++;
        CirclePoint(x, y, x1, y1);
    }
}
void myDisplay(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    MidPointCircle(150, 150, 70);
    MidPointCircle(150, 80, 30);
    MidPointCircle(80, 150, 50);
}

void setPixel(int x, int y)
{

    glPointSize(3.0f);
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
    glutCreateWindow("Daily Practice");
    glutDisplayFunc(&myDisplay);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 0;
}