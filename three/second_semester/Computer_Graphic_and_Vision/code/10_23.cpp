#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/GLUT.h>

GLint winWidth = 600, winHeight = 600; // Initial display-window size.
GLfloat x_0 = 100.0, y_0 = 50.0, z_0 = 50.0; // Viewing-coordinate origin.
GLfloat xref = 50.0, yref = 50.0, zref = 0.0; // Look-at point.
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.
/* Set coordinate limits for the clipping window: */
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;
/* Set positions for near and far clipping planes: */
GLfloat dnear = 25.0, dfar = 125.0;

int mode = 0;

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    
    gluLookAt(x_0, y_0, z_0, xref, yref, zref, Vx, -Vy, Vz);
    //    gluLookAt(x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
    glMatrixMode(GL_PROJECTION);
    glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}
void displayFcn()
{
    glClear(GL_COLOR_BUFFER_BIT);
    /* Set parameters for a square fill area. */
    glColor3f(0.0, 1.0, 0.0); // Set fill color to green.
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_LINE); // Wire-frame back face.
    if(mode == 1){
        glBegin(GL_QUADS);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(100.0, 0.0, 0.0);
        glVertex3f(100.0, 100.0, 0.0);
        glVertex3f(0.0, 100.0, 0.0);
        glEnd();
    }
    else
        if(mode == 2){
//            glColor3f(0.0, 1.0, 0.0);
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_TRIANGLES);
            glVertex3f(0.0, 0.0, 0.0);
            glVertex3f(0.0, 100.0, 0.0);
            glVertex3f(70.0, 0.0, 0.0);
            glEnd();
            
        }
    else{
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex3f(30.0, 0.0, 0.0);
        glVertex3f(0.0, 45.0, 0.0);
        glVertex3f(30.0, 90.0, 0.0);
        glVertex3f(60.0, 90.0, 0.0);
        glVertex3f(90.0, 45.0, 0.0);
        glVertex3f(60.0, 0.0, 0.0);
        glEnd();
    }
    glFlush();
}
void reshapeFcn(GLint newWidth, GLint newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
    winWidth = newWidth;
    winHeight = newHeight;
}

void mymenu(int value) {
    if(value==1){
        mode = 1;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x_0, y_0, z_0, xref, yref, zref, Vx, Vy, Vz);
        displayFcn();
      
    }
    if(value==2){
        mode = 2;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x_0, y_0, z_0, xref, yref, zref, Vx, Vy, Vz);

//        gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

        displayFcn();
        
    }
    if(value==3){
        mode = 3;
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(x_0, y_0, z_0, xref, yref, zref, Vx, Vy, Vz);
        
//        gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        
        displayFcn();
        
    }
    
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Perspective View of A Square");
    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(reshapeFcn);
    
    
    int menu_id = glutCreateMenu(mymenu);
    glutAddMenuEntry("QUADS", 1);
    glutAddMenuEntry("TRIANGLES", 2);
    glutAddMenuEntry("POLYGONS", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}

