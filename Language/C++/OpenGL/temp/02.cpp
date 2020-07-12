
#include <windows.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>
void linedda(int x1, int y1, int x2, int y2)
{
    int dm = 0;
    if (abs(x2 - x1) >= abs(y1 - y2))
        dm = abs(x1 - x2);
    else
        dm = abs(y1 - y2);
    float dx = (float)abs(x1 - x2) / dm;
    float dy = (float)abs(y1 - y2) / dm;
    float x = x1 + 0.5;
    float y = x2 + 0.5;
    glColor3f(1.0f, 0.0f, 1.0f);
    glPointSize(10);
    for (int i = 0; i < dm; ++i)
    {
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        x += dx;
        y += dy;
    }
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    linedda(0, 0, 1, 1);

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Point");
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return (0);
}