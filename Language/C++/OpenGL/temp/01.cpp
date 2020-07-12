
#include <GL/freeglut.h>
#include <stdio.h>

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '\x1B':
        exit(EXIT_SUCCESS);
        break;

    default:
        break;
    }
}
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
    for (int i = 0; i < dm; ++i)
    {

        // SetPixel(NULL, int(x), int(y), color);
        glBegin(GL_POINT);
        glVertex2i(x, y);
        glEnd();
        x += dx;
        y += dy;
    }
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glPointSize(10);
    glBegin(GL_POINT);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0.5, 0);
    glVertex3f(0.5, 0, 0);
    glEnd();
    glFlush();
}
// todo 无法画线
int main(int args, char **argv)
{
    glutInit(&args, argv);
    glutCreateWindow("gult test");

    // 设置窗口初始位置，
    glutInitWindowPosition(500, 500);
    // 设置窗口，初始大小，
    glutInitWindowSize(500, 500);
    // 初始化窗口颜色
    // glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(&display);

    glutMainLoop();
    system("pause");
    return EXIT_SUCCESS;
}