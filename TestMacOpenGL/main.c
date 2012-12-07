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

#define WIDTH 400
#define HEIGHT 400

static int day = 10;
static GLfloat angle = 0.0f;

void display()
{
//    glClear(GL_COLOR_BUFFER_BIT); // 清屏
//    glColor4f(0.0, 1.0, 0.0, 0.5);// 绘制矩形
//    glRectf(0.1, 0.1, 0.6, 0.6);
//    glColor4f(1.0, 1.0, 0.0, 0.7);// 绘制矩形
//    glRectf(0.4, 0.3, 0.9, 0.8);
//    glFlush(); // 强制绘图完成
    
    /*
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75, 1, 1, 400000000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);
    
    // 绘制红色的“太阳”
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(69600000, 20, 20);
    // 绘制蓝色的“地球”
    glColor3f(0.0f, 0.0f, 1.0f);
    glRotatef(day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(150000000, 0.0f, 0.0f);
    glutSolidSphere(15945000, 20, 20);
    // 绘制黄色的“月亮”
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(day/30.0*360.0 - day/360.0*360.0, 0.0f, 0.0f, -1.0f);
    glTranslatef(38000000, 0.0f, 0.0f);
    glutSolidSphere(4345000, 20, 20);
    //*/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // 创建透视效果视图
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0f, 1.0f, 1.0f, 20.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    // 定义太阳光源，它是一种白色的光源
    {
        GLfloat sun_light_position[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_light_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_light_diffuse[]  = {1.0f, 1.0f, 1.0f, 1.0f};
        GLfloat sun_light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
        
        glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT,  sun_light_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE,  sun_light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);
        
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
        glEnable(GL_DEPTH_TEST);
    }
    
    // 定义太阳的材质并绘制太阳
    {
        GLfloat sun_mat_ambient[]  = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_mat_diffuse[]  = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_mat_specular[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_mat_emission[] = {0.5f, 0.0f, 0.0f, 1.0f};
        GLfloat sun_mat_shininess  = 0.0f;
        
        glMaterialfv(GL_FRONT, GL_AMBIENT,   sun_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   sun_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  sun_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION,  sun_mat_emission);
        glMaterialf (GL_FRONT, GL_SHININESS, sun_mat_shininess);
        
        glutSolidSphere(2.0, 40, 32);
    }
    
    // 定义地球的材质并绘制地球
    {
        GLfloat earth_mat_ambient[]  = {0.0f, 0.0f, 0.5f, 1.0f};
        GLfloat earth_mat_diffuse[]  = {0.0f, 0.0f, 0.5f, 1.0f};
        GLfloat earth_mat_specular[] = {0.0f, 0.0f, 1.0f, 1.0f};
        GLfloat earth_mat_emission[] = {0.0f, 0.0f, 0.0f, 1.0f};
        GLfloat earth_mat_shininess  = 30.0f;
        
        glMaterialfv(GL_FRONT, GL_AMBIENT,   earth_mat_ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE,   earth_mat_diffuse);
        glMaterialfv(GL_FRONT, GL_SPECULAR,  earth_mat_specular);
        glMaterialfv(GL_FRONT, GL_EMISSION,  earth_mat_emission);
        glMaterialf (GL_FRONT, GL_SHININESS, earth_mat_shininess);
        
        glRotatef(angle, 0.0f, -1.0f, 0.0f);
        glTranslatef(5.0f, 0.0f, 0.0f);
        glutSolidSphere(2.0, 40, 32);
    }
    
    glFlush();
    
    glutSwapBuffers();
}

void myIdle()
{
    ++day;
    if (day >= 360) {
        day = 0;
    }
    display();
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
    printf("reshap");
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
    glutCreateWindow("sun earth moon"); //(argv[0]);
    init ();
    glutDisplayFunc(&display);
    glutIdleFunc(&myIdle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

