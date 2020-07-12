
#include <GL/glut.h> //引用相关包
#include <windows.h>
#include <GL/glaux.h>
#include <stdio.h>
#include <stdlib.h>

char *filename = "C:\\Users\\Lenovo\\OneDrive\\Projects\\SRC\\Language\\C++\\OpenGL\\exper\\exper5\\mf.bmp";

GLfloat xrot = 0;  // X 旋转量
GLfloat yrot = 0;  // Y 旋转量
GLfloat zrot = 0;  // Z 旋转量
GLuint texture[1]; // 存储一个纹理---数组

//载入位图图象到内存——固定用法
AUX_RGBImageRec *LoadBMP(CHAR *Filename)
{
    FILE *File = NULL; // 文件句柄
    if (!Filename)     // 确保文件名已提供
    {
        return NULL; // 如果没提供，返回 NULL
    }
    File = fopen(Filename, "r"); // 尝试打开文件
    if (File)                    // 判断文件存在与否
    {
        fclose(File);                      // 关闭句柄
        return auxDIBImageLoadA(Filename); // 载入位图并返回指针
    }
    return NULL; // 如果载入失败，返回 NULL
}

//载入位图(调用上面的代码)并转换成纹理——固定用法
//参数：纹理指针、bmp文件名、用户指定的纹理编号
int LoadGLTextures(GLuint *texture, char *bmp_file_name, int texture_id)
{
    int Status = FALSE; // 状态指示器
    // 创建纹理的存储空间
    AUX_RGBImageRec *TextureImage[1];
    memset(TextureImage, 0, sizeof(void *) * 1); // 将指针设为 NULL
    // 载入位图，检查有无错误，如果位图没找到则退出
    if (TextureImage[0] = LoadBMP(bmp_file_name))
    {
        Status = TRUE; // 将 Status 设为 TRUE
        //生成(generate)纹理
        glGenTextures(texture_id, texture); //&texture[0]);
        //绑定2D纹理对象
        glBindTexture(GL_TEXTURE_2D, *texture); //texture[0]);
        //关联图像数据与纹理对象
        glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
        //图形绘制时所使用的滤波器参数
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    }

    //释放图像的内存，因为已经生成纹理了，没用了
    if (TextureImage[0]) // 纹理是否存在
    {
        if (TextureImage[0]->data) // 纹理图像是否存在
        {
            free(TextureImage[0]->data); // 释放纹理图像占用的内存
        }
        free(TextureImage[0]); // 释放图像结构
    }
    else
        printf("纹理不存在");
    return Status; // 返回 Status
}
int DrawGLScene(GLvoid) // Here's Where We Do All The Drawing
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear The Screen And The Depth Buffer
    glLoadIdentity();                                   // Reset The View

    GLfloat x_m, y_m, z_m, u_m, v_m; // 顶点的临时 X, Y, Z, U 和 V 的数值
    GLfloat xtrans = -xpos;          // 用于操作者沿X轴平移时的大小
    GLfloat ztrans = -zpos;
    GLfloat ytrans = -walkbias - 0.25f;
    GLfloat sceneroty = 360.0f - yrot; // 位于操作者方向的360度角

    int numtriangles; // 保有三角形数量的整数

    glRotatef(lookupdown, 1.0f, 0, 0); // 上下旋转
    glRotatef(sceneroty, 0, 1.0f, 0);  // 左右旋转

    glTranslatef(xtrans, ytrans, ztrans);          //以操作者为中心的平移场景
    glBindTexture(GL_TEXTURE_2D, texture[filter]); // 根据filter选择的纹理

    numtriangles = sector1.numtriangles; // 取得Sector1的三角形数量

    // Process Each Triangle
    for (int loop_m = 0; loop_m < numtriangles; loop_m++) // 遍历所有的三角形
    {
        glBegin(GL_TRIANGLES); // 开始绘制三角形
        glNormal3f(0.0f, 0.0f, 1.0f);
        x_m = sector1.triangle[loop_m].vertex[0].x; //第一点的 X 分量
        y_m = sector1.triangle[loop_m].vertex[0].y;
        z_m = sector1.triangle[loop_m].vertex[0].z;
        u_m = sector1.triangle[loop_m].vertex[0].u;
        v_m = sector1.triangle[loop_m].vertex[0].v;
        glTexCoord2f(u_m, v_m);
        glVertex3f(x_m, y_m, z_m);

        x_m = sector1.triangle[loop_m].vertex[1].x;
        y_m = sector1.triangle[loop_m].vertex[1].y;
        z_m = sector1.triangle[loop_m].vertex[1].z;
        u_m = sector1.triangle[loop_m].vertex[1].u;
        v_m = sector1.triangle[loop_m].vertex[1].v;
        glTexCoord2f(u_m, v_m);
        glVertex3f(x_m, y_m, z_m);

        x_m = sector1.triangle[loop_m].vertex[2].x;
        y_m = sector1.triangle[loop_m].vertex[2].y;
        z_m = sector1.triangle[loop_m].vertex[2].z;
        u_m = sector1.triangle[loop_m].vertex[2].u;
        v_m = sector1.triangle[loop_m].vertex[2].v;
        glTexCoord2f(u_m, v_m);
        glVertex3f(x_m, y_m, z_m); // 设置纹理坐标和顶点
        glEnd();
    }
    return TRUE; // Everything Went OK
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 清楚颜色数据和深度数据（清屏）
    glLoadIdentity();                                   // 重置视图
    glTranslatef(0.0f, 0.0f, -5.0f);
    DrawGLScene();
    glutSwapBuffers(); //交换缓冲区。显示图形
}

//初始化
void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); //清理颜色，为黑色，（也可认为是背景颜色）
    glCullFace(GL_BACK);              //背面裁剪(背面不可见)
    glEnable(GL_CULL_FACE);           //启用裁剪
    glEnable(GL_TEXTURE_2D);
    LoadGLTextures(&texture[0], filename, 1); //载入纹理贴图
    //LoadGLTextures(&texture[1], "mf1.bmp", 2);            //载入纹理贴图
}

//当窗口大小改变时，会调用这个函数
void reshape(GLsizei w, GLsizei h)
{
    //这里小说明一下：矩阵模式是不同的，他们各自有一个矩阵。投影相关
    //只能用投影矩阵。(只是目前情况下哦，等我学多了可能就知道为什么了。)
    glViewport(0, 0, w, h);                      //设置视口
    glMatrixMode(GL_PROJECTION);                 //设置矩阵模式为投影变换矩阵，
    glLoadIdentity();                            //变为单位矩阵
    gluPerspective(60, (GLfloat)w / h, 0, 1000); //设置投影矩阵

    glMatrixMode(GL_MODELVIEW); //设置矩阵模式为视图矩阵(模型)
    glLoadIdentity();           //变为单位矩阵
}

//键盘输入事件函数
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'x':                //当按下键盘上d时，以沿X轴旋转为主
        xrot += 1.0f;        //设置旋转增量
        glutPostRedisplay(); //重绘函数
        break;
    case 'y':
        yrot += 1.0f;
        glutPostRedisplay();
        break;
    case 'z':
        zrot += 1.0f;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);                       //固定格式
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //注意这里
    glutInitWindowSize(600, 600);                //显示框的大小
    glutInitWindowPosition(100, 100);            //确定显示框左上角的位置
    glutCreateWindow("opengl3d漫游");
    init(); //初始化资源,这里一定要在创建窗口以后，不然会无效。
    LoadGLTextures(&texture[0], filename, 1);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape); //绘制图形时的回调
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

int DrawGLScene(GLvoid)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    GLfloat x_m, y_m, z_m, u_m, v_m; // 顶点的临时 X, Y, Z, U 和 V 的数值
    GLfloat xtrans = -xpos;          // 用于操作者沿X轴平移时的大小
    GLfloat ztrans = -zpos;
    GLfloat ytrans = -walkbias - 0.25f;
    GLfloat sceneroty = 360.0f - yrot; // 位于操作者方向的360度角

    int numtriangles; // 保有三角形数量的整数

    glRotatef(lookupdown, 1.0f, 0, 0); // 上下旋转
    glRotatef(sceneroty, 0, 1.0f, 0);  // 左右旋转

    glTranslatef(xtrans, ytrans, ztrans);          //以操作者为中心的平移场景
    glBindTexture(GL_TEXTURE_2D, texture[filter]); // 根据filter选择的纹理

    numtriangles = sector1.numtriangles; // 取得Sector1的三角形数量

    // Process Each Triangle
    for (int loop_m = 0; loop_m < numtriangles; loop_m++) // 遍历所有的三角形
    {
        glBegin(GL_TRIANGLES); // 开始绘制三角形
        glNormal3f(0.0f, 0.0f, 1.0f);
        x_m = sector1.triangle[loop_m].vertex[0].x; //第一点的 X 分量
        y_m = sector1.triangle[loop_m].vertex[0].y;
        z_m = sector1.triangle[loop_m].vertex[0].z;
        u_m = sector1.triangle[loop_m].vertex[0].u;
        v_m = sector1.triangle[loop_m].vertex[0].v;
        glTexCoord2f(u_m, v_m);
        glVertex3f(x_m, y_m, z_m);

        x_m = sector1.triangle[loop_m].vertex[1].x;
        y_m = sector1.triangle[loop_m].vertex[1].y;
        z_m = sector1.triangle[loop_m].vertex[1].z;
        u_m = sector1.triangle[loop_m].vertex[1].u;
        v_m = sector1.triangle[loop_m].vertex[1].v;
        glTexCoord2f(u_m, v_m);
        glVertex3f(x_m, y_m, z_m);

        x_m = sector1.triangle[loop_m].vertex[2].x;
        y_m = sector1.triangle[loop_m].vertex[2].y;
        z_m = sector1.triangle[loop_m].vertex[2].z;
        u_m = sector1.triangle[loop_m].vertex[2].u;
        v_m = sector1.triangle[loop_m].vertex[2].v;
        glTexCoord2f(u_m, v_m);
        glVertex3f(x_m, y_m, z_m); // 设置纹理坐标和顶点
        glEnd();
    }
    return TRUE; // Everything Went OK
}
