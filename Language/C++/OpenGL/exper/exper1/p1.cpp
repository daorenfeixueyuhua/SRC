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

void myDisplay(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    lineDDA(50, 50, 200, 200);
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

void lineDDA(int x0, int y0, int xEnd, int yEnd)
{
    glPointSize(3.0f); //设置像素点大小
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;
    if (abs(xEnd - x0) > abs(yEnd - y0))
        steps = abs(xEnd - x0);
    else
        steps = abs(yEnd - y0);
    xIncrement = float(dx) / float(steps); 
    yIncrement = float(dy) / float(steps);
    setPixel(round(x), round(y)); 
    for (k = 0; k < steps; k++)
    {

        x += xIncrement;
        y += yIncrement;
        setPixel(round(x), round(y));
        Sleep(100);
    }
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