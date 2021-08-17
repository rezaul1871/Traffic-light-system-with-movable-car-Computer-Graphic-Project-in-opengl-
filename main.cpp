#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>

float p=0.0;
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0; i<100; i++)

    {
        float angle = 4.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();
}
void display(void)

{
glClear (GL_COLOR_BUFFER_BIT);

glBegin(GL_QUADS);
//making lower side
glColor3f (0.0, 1.0, 0.0);
glVertex3f (0, 0, 0.0);
glVertex3f (60, 0, 0.0);
glVertex3f (60, 5, 0.0);
glVertex3f (0, 5, 0.0);
//Road side
glColor3f (0.0, 0.0, 0.0);
glVertex3f (0, 5, 0.0);
glVertex3f (60,5, 0.0);
glVertex3f (60, 20, 0.0);
glVertex3f (0, 20, 0.0);
//Upper side
glColor3f (0.0, 1.0, 0.0);
glVertex3f (0, 20, 0.0);
glVertex3f (60, 20, 0.0);
glVertex3f (60, 40, 0.0);
glVertex3f (0, 40, 0.0);
//Upper road
glColor3f (0.0, 0.0, 0.0);
glVertex3f (20, 20, 0.0);
glVertex3f (35, 20, 0.0);
glVertex3f (30, 40, 0.0);
glVertex3f (15, 40, 0.0);
//Move code
       if(p<=100)
       p=p-0.005;
      else
        p=0;
    glutPostRedisplay();
//bus body
glColor3f (1, 0, 0);
glVertex3f (p+45, 17, 0.0);
glVertex3f (p+45, 22, 0.0);
glVertex3f (p+58, 22, 0.0);
glVertex3f (p+58, 17, 0.0);
//bus body sider
glVertex3f (p+42, 17, 0.0);
glVertex3f (p+42, 20, 0.0);
glVertex3f (p+45, 20, 0.0);
glVertex3f (p+45, 17, 0.0);

//bus windows 1
glColor3f (0,1,1);
glVertex3f (p+45.2, 19, 0.0);
glVertex3f (p+45.2, 21, 0.0);
glVertex3f (p+47, 21, 0.0);
glVertex3f (p+47, 19, 0.0);
//door
glColor3f (1, 1, 1);
glVertex3f (p+47.2, 17, 0.0);
glVertex3f (p+47.2, 21, 0.0);
glVertex3f (p+49, 21, 0.0);
glVertex3f (p+49, 17, 0.0);
//windows 1 (side by side windows)
glColor3f (0,1,1);
glVertex3f (p+50, 19, 0.0);
glVertex3f (p+50, 21, 0.0);
glVertex3f (p+52.5, 21, 0.0);
glVertex3f (p+52.5, 19, 0.0);
//windows 2
glVertex3f (p+53, 19, 0.0);
glVertex3f (p+53, 21, 0.0);
glVertex3f (p+55.5, 21, 0.0);
glVertex3f (p+55.5, 19, 0.0);
//windows 3
glVertex3f (p+56, 19, 0.0);
glVertex3f (p+56, 21, 0.0);
glVertex3f (p+58, 21, 0.0);
glVertex3f (p+58, 19, 0.0);
glEnd();
//car fornt windows
glBegin(GL_TRIANGLES);
glColor3f (0,1,1);
glVertex3f (p+42, 20, 0.0);
glVertex3f (p+45, 20, 0.0);
glVertex3f (p+45, 22, 0.0);
glEnd();
glColor3f (0.224, 0.255, 0.255	);
circle(1,1,p+45,17);
circle(1,1,p+55,17);
glBegin(GL_QUADS);
//Taffic Light part start
//Traffic light bottom 1
glColor3f (0.224, 0.255, 0.255	);
glVertex3f (35, 12, 0.0);
glVertex3f (35, 14, 0.0);
glVertex3f (40, 14, 0.0);
glVertex3f (40, 12, 0.0);
//Traffic light bottom 2
glVertex3f (36, 14, 0.0);
glVertex3f (36, 17, 0.0);
glVertex3f (39, 17, 0.0);
glVertex3f (39, 14, 0.0);
//Traffic light upper position
glVertex3f (35.5, 17, 0.0);
glVertex3f (35.5, 26, 0.0);
glVertex3f (39.5, 26, 0.0);
glVertex3f (39.5, 17, 0.0);
//light 1
glColor3f (1, 1, 0);
glVertex3f (36, 20, 0.0);
glVertex3f (36, 21, 0.0);
glVertex3f (39, 21, 0.0);
glVertex3f (39, 20, 0.0);
//light 2
glColor3f (0.0, 1.0, 0.0);
glVertex3f (36, 22, 0.0);
glVertex3f (36, 23, 0.0);
glVertex3f (39, 23, 0.0);
glVertex3f (39, 22, 0.0);
//light 3
glColor3f (1, 1, 1);
glVertex3f (36, 24, 0.0);
glVertex3f (36, 25, 0.0);
glVertex3f (39, 25, 0.0);
glVertex3f (39, 24, 0.0);
//Traffic light part stop
glEnd();
/*
//Car part start
glBegin(GL_QUADS);
glColor3f (0,0,1);
glVertex3f (4, 7, 0.0);
glVertex3f (4, 11, 0.0);
glVertex3f (18, 11, 0.0);
glVertex3f (18, 7, 0.0);
//font part
glVertex3f (18, 6, 0.0);
glVertex3f (18, 11, 0.0);
glVertex3f (20, 10, 0.0);
glVertex3f (20, 7, 0.0);
//back part
glVertex3f (4 ,6, 0.0);
glVertex3f (4, 11, 0.0);
glVertex3f (1, 10, 0.0);
glVertex3f (1, 7, 0.0);

//door
glColor3f (1,0,1);
glVertex3f (3 ,10, 0.0);
glVertex3f (5, 11, 0.0);
glVertex3f (15, 11, 0.0);
glVertex3f (17, 10, 0.0);
glEnd();
glColor3f(1,1,1);
circle(0.2,0.2,5,5);
circle(0.2,0.2,15,5);*/
glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glLoadIdentity();
glOrtho(0.0,60, 0.0, 40, -1.0, 1.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (720, 720);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Star Designing");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
