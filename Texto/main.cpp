#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int x=0;
void DesenhaTextoStroke(char *aux)
{
char *p;
p = aux;
while(*p)
glutStrokeCharacter(GLUT_STROKE_ROMAN,*p++);
}
void display(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glColor3f(1,0,0);
    glTranslatef(240,180,0);
    glScalef(0.2, 0.2, 0.2); // diminui o tamanho do fonte
    glLineWidth(2); // define a espessura da linha
    DesenhaTextoStroke("Teste\n");
    glColor3f(0,1,0);
    glTranslatef(5,0,0);
    glScalef(4, 2, 0); // diminui o tamanho do fonte
    glLineWidth(2); // define a espessura da linha
    DesenhaTextoStroke("WiLl\n");
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Teste de fonte de texto");
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMainLoop();
}
