

#include <stdlib.h>
#include <math.h>

#include <iostream>

#include <GL/glut.h>

using namespace std;
const GLdouble twoPi = 6.283185;
class screenPt{
public:
    GLint x, y;
};



GLsizei winWidth = 500, winHeight = 400;

void init(void){
    glClearColor(0.0, 0.533, 0.4274, 0.89);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}


void lineSegment(screenPt pt1, screenPt pt2){
    glBegin(GL_LINES);
    glVertex2i(pt1.x, pt1.y);
    glVertex2i(pt2.x, pt2.y);
    glEnd();
}


void drawCardioid(){
    const GLint a = 131.25;
    GLfloat r, theta, dtheta = 1.0 / float(a);
    GLint x0 = 150, y0 = 187.5; 
    screenPt curvePt[2];
    glColor3f(0.0, 0.0, 0.0);
    curvePt[0].x = x0;
    curvePt[0].y = y0;
    curvePt[0].x += a + a; 


    theta = dtheta;
    while (theta<twoPi){

         r = a*(1 + cos(theta)); 
        
        curvePt[1].x = x0 + r*cos(theta); 
        curvePt[1].y = y0 + r*sin(theta);
        lineSegment(curvePt[0], curvePt[1]);
        curvePt[0].x = curvePt[1].x;
        curvePt[0].y = curvePt[1].y;
        theta += dtheta; 
    }
}


void displayFcn(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
        drawCardioid();
    glFlush();
}


void winReshapeFcn(GLint newWidth, GLint newHeight){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Draw Curves");
    init();
    glutDisplayFunc(displayFcn);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();

    return 0;
}

