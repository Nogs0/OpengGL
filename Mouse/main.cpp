#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

float r, g, b , x, y;
typedef struct{
    float x;
    float y;
}Posicoes;
Posicoes Posicao[100];
int i = 0;
bool check = true; //checar com qual botão do mouse o usuário pressionou

void mouse(int button, int state, int mousex, int mousey){ //button = qual botão pressionou, state = down/up, mousex && mousey = posição onde o usuário clicou

    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        check = true;
        x = mousex; //variável global recebe a coluna onde o clic foi efetuado
        y = 480-mousey; // valores de linha do mouse ao click se torna espelhado, po conta disso a necessidade do 480-mousey >> resolução (480) - posição onde o clic ocorreu
        Posicao[i].x = x;
        Posicao[i].y = y;
        printf(" - %5.2f - ", Posicao[i].x);
        printf(" - %5.2f - ", Posicao[i].y);
        printf("\n");
        i++;
        if(i % 2 == 0){
            r =1;
            g = 0;
            b = 0;
        } else{
            r = 0;
            g = 0;
            b = 1;
        }
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
        glClearColor(1,1,1,0);
        glClear(GL_COLOR_BUFFER_BIT);
        check = false;
    }
    glutPostRedisplay();
}

void display (){
    glColor3f(r,g,b);
    glPointSize(50);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
    if(check){
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
    }

    glFlush();
}

int main(int argc, char **argv){
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Interação via Mouse");
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
