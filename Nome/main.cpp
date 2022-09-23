#include <GL/freeglut.h>
#include <iostream>

GLfloat escala = 1;
GLfloat trans1 = 0;
GLfloat trans2 = 0;
GLfloat trans = 0;
GLfloat rot = 0;


void Nome(){

    glClear(GL_COLOR_BUFFER_BIT);
    //REDIMENSIONAMENTO
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3,3,-3,3);

    glScalef(escala, escala, 0);
    //TRANSLAÇÃO
    glTranslatef(0.3, trans1, 0);
    //ROTAÇÃO
    glRotatef(rot, rot, 0,rot);

    glBegin(GL_LINES);
        glVertex2f(-0.55,0.4);
        glVertex2f(-0.35,0.4);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.45,0.4);
        glVertex2f(-0.45,0.1);
        glVertex2f(-0.5,0.05);
        glVertex2f(-0.52,0.1);
        glVertex2f(-0.53,0.13);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.21, 0.4);
        glVertex2f(-0.09,0.4);
        glVertex2f(-0.05,0.35);
        glVertex2f(-0.05,0.1);
        glVertex2f(-0.09,0.05);
        glVertex2f(-0.21,0.05);
        glVertex2f(-0.25,0.1);
        glVertex2f(-0.25,0.35);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.05,0.05);
        glVertex2f(0.15,0.4);
        glVertex2f(0.25,0.05);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0.11,0.25);
        glVertex2f(0.19,0.25);

    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.51, 0.4);
        glVertex2f(0.39,0.4);
        glVertex2f(0.35,0.35);
        glVertex2f(0.35,0.1);
        glVertex2f(0.39,0.05);
        glVertex2f(0.51,0.05);
        glVertex2f(0.55,0.1);
        glVertex2f(0.55,0.35);
    glEnd();
    glFlush();
}

void listeningKey(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escala++;
            break;
        case '-': if(escala>1)
                    escala--;
            break;
        case 'd': trans++;
            break;
        case 'a': trans--;
            break;
        case 'w': trans1++;
            break;
        case 's': trans1--;
            break;
        case 'q': rot+=10;
            break;
        case 'e': rot-=10;
            break;
    }
    Nome();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(400,150);
    glutCreateWindow("Hello Glut!");
    glutKeyboardFunc(listeningKey);
    glutDisplayFunc(Nome);
    glClearColor(0,0,1,0);
    glutMainLoop();
    return 0;
}
