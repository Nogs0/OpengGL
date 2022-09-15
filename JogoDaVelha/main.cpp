#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

float x, y;
char Game[9];
int jogadas = 0;
//coluna = primeiros dois dados da matriz
struct
{
    float coluna [6] = {-0.45, -0.15, 0.15,  0.45};

    float linha[6] = {  0.45,  0.15, -0.15, -0.45};
} pontos;

void Tabuleiro(void);
int VerificaTabuleiro(float mousex, float mousey);
void mouse(int button, int state, int mousex, int mousey);
void FillGame();
void imprimeJogo();
int main(int argc, char *argv[])
{
    FillGame();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(650,300);
    glutCreateWindow("Jogo da Velha");
    glutMouseFunc(mouse);
    glutDisplayFunc(Tabuleiro);

    glutMainLoop();

    return EXIT_SUCCESS;
}
void Tabuleiro(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glBegin(GL_LINES);
    glVertex2f(0.45, 0.15);
    glVertex2f(-0.45, 0.15);
    glVertex2f(0.45, -0.15);
    glVertex2f(-0.45,-0.15);

    glVertex2f(0.15,0.45);
    glVertex2f(0.15,-0.45);
    glVertex2f(-0.15, -0.45);
    glVertex2f(-0.15, 0.45);
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500,0.0,500);

    glFlush();
}

void FillGame(){
    int i = 0;
    for(i = 0; i<9; i++)
        Game[i] = ' ';
}
int VerificaTabuleiro(float mousex, float mousey)
{
    mousey = mousey;
    mousex = mousex;

    if(mousey < 210 && mousey > 140)
    {
        jogadas++;
        if(mousex < 210 && mousex > 145)
            return 0;
        if(mousex < 285 && mousex > 215)
            return 1;
        if(mousex < 360 && mousex > 290)
            return 2;
    }
    else if(mousey < 285 && mousey > 215)
    {
        jogadas++;
        if(mousex < 210 && mousex > 145)
            return 3;
        if(mousex < 285 && mousex > 215)
            return 4;
        if(mousex < 360 && mousex > 290)
            return 5;
    }
    else if(mousey < 360 && mousey > 290)
    {
        jogadas++;
        if(mousex < 210 && mousex > 145)
            return 6;
        if(mousex < 285 && mousex > 215)
            return 7;
        if(mousex < 360 && mousex > 290)
            return 8;
    }
    return 9;
}

void mouse(int button, int state, int mousex, int mousey)
{
    int posicao;

    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN){
    x = mousex;
    y = (mousey);
        posicao = VerificaTabuleiro(x, y);
    }
    if(posicao < 9){
    if(Game[posicao] == ' '){
        if(jogadas %2 != 0)
            Game[posicao] = 'X';
        else
            Game[posicao] = 'O';
    }
    else jogadas--;
    imprimeJogo();
    }
}

void imprimeJogo(){
    int i = 0;
    for(i=0;i<9;i++){
        printf("%c\n", Game[i]);
    }

}
