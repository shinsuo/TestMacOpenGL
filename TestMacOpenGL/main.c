//
//  main.c
//  TestMacOpenGL
//
//  Created by shin on 11/17/12.
//  Copyright (c) 2012 shin. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<GLUT/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // 清屏
    glColor4f(0.0, 1.0, 0.0, 0.5);// 绘制矩形
    glRectf(0.1, 0.1, 0.6, 0.6);
    glColor4f(1.0, 1.0, 0.0, 0.7);// 绘制矩形
    glRectf(0.4, 0.3, 0.9, 0.8);
    glFlush(); // 强制绘图完成
}
void init()
{
    glEnable (GL_BLEND);    // 启用融合
    glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//产生融合因子
    glShadeModel (GL_FLAT);// 设置平面明暗处理
    glClearColor (0.0, 0.0, 0.0, 0.0);// 清屏
}

void reshape (int w,int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
                 1.5*(GLfloat)h/(GLfloat)w, -10.0,10.0);
    else
        glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
                 1.5*(GLfloat)w/(GLfloat)h, -1.5,1.5, -10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x,int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE |GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500,500);
    glutInitWindowPosition (100,100);
    glutCreateWindow (argv[0]);
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

