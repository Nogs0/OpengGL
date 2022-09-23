#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#define PI 3.1415926535898

float x, y;
char Game[3][3];
int jogadas = 0;
bool check = true;
int posicao = -1;
float colunas[3] = { 0.6, 0.0,-0.6};

void draw();
void drawO(float, float);
void drawX(float, float, float, float, float);
void Tabuleiro(void);
int VerificaTabuleiro(int mousex, int mousey);
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
    glClearColor(1,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutMainLoop();

    return EXIT_SUCCESS;
}
void Tabuleiro()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,0,0,0);

    glMatrixMode(GL_MODELVIEW);
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

    draw();
    glFlush();
}

void FillGame()
{
    int i, j;
    for(i = 0; i<3; i++)
        for(j=0; j <3; j++)
            Game[i][j] = ' ';
}
void drawO(float w, float h)
{

    float ang, xx, yy;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
    {
        ang = (i * PI) / 180.0;
        xx =  w+ (cos(ang) * 0.15);
        yy =  h+ (sin(ang) * 0.15);
        glVertex2f(xx, yy);
    }
    glEnd();
}

void drawX(float n1, float n2, float n3, float n4, float FT)
{
    glBegin(GL_LINES);
        glVertex2f(n1, n2);
        glVertex2f(n3, n4);
    glEnd();

    glRotatef(180,0,1,0);
    glTranslatef(FT,0,0);
    glBegin(GL_LINES);
        glVertex2f(n1, n2);
        glVertex2f(n3, n4);
    glEnd();
}
int VerificaTabuleiro(int mousex, int mousey)
{

    if(mousey < 210.00 && mousey > 140.00)
    {
        jogadas++;
        if(mousex < 210 && mousex > 145 && Game[0][0] == ' ')   return 0;
        if(mousex < 285 && mousex > 215 && Game[0][1] == ' ')   return 1;
        if(mousex < 360 && mousex > 290 && Game[0][2] == ' ')   return 2;
    }
    else if(mousey < 285 && mousey > 210)
    {
        jogadas++;
        if(mousex < 210 && mousex > 145 && Game[1][0] == ' ')   return 3;
        if(mousex < 285 && mousex > 215 && Game[1][1] == ' ')   return 4;
        if(mousex < 360 && mousex > 290 && Game[1][2] == ' ')   return 5;
    }
    else if(mousey < 360 && mousey > 285)
    {
        jogadas++;
        if(mousex < 210 && mousex > 145 && Game[2][0] == ' ')   return 6;
        if(mousex < 285 && mousex > 215 && Game[2][1] == ' ')   return 7;
        if(mousex < 360 && mousex > 290 && Game[2][2] == ' ')   return 8;
    }
    return 9;
}

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int linha = 0;
        check = true;
        x = mousex;
        y = mousey;
        posicao = VerificaTabuleiro(x, y);
        if(posicao <= 2){
            if(Game[linha][posicao] == ' ')
                (jogadas %2 != 0) ? Game[linha][posicao] = 'X' : Game[linha][posicao] = 'O';
            else jogadas--;
        }
        else if(posicao <=5){
            if(Game[linha][posicao] == ' ')
                (jogadas %2 != 0) ? Game[linha][posicao] = 'X' : Game[linha][posicao] = 'O';
            else jogadas--;
        }
        else if(posicao<=8){
            if(Game[linha][posicao] == ' ')
                (jogadas %2 != 0) ? Game[linha][posicao] = 'X': Game[linha][posicao] = 'O';
            else jogadas--;
        }

        imprimeJogo();
        Tabuleiro();
    }
    else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        check = false;
    }
    glutPostRedisplay();
}

void draw()
{
    if(check)
    {
        if(posicao == 0)        (jogadas %2 != 0) ? drawX(-0.45, 0.15,-0.15, 0.45, colunas[0]) : drawO(-0.3, 0.3);
        else if(posicao == 1)   (jogadas %2 != 0) ? drawX(-0.15, 0.15, 0.15, 0.45, colunas[1]) : drawO( 0.0, 0.3);
        else if(posicao == 2)   (jogadas %2 != 0) ? drawX( 0.15, 0.15, 0.45, 0.45, colunas[2]) : drawO( 0.3, 0.3);
        else if(posicao == 3)   (jogadas %2 != 0) ? drawX(-0.45,-0.15,-0.15, 0.15, colunas[0]) : drawO(-0.3, 0.0);
        else if(posicao == 4)   (jogadas %2 != 0) ? drawX(-0.15,-0.15, 0.15, 0.15, colunas[1]) : drawO( 0.0, 0.0);
        else if(posicao == 5)   (jogadas %2 != 0) ? drawX( 0.15,-0.15, 0.45, 0.15, colunas[2]) : drawO( 0.3, 0.0);
        else if(posicao == 6)   (jogadas %2 != 0) ? drawX(-0.45,-0.45,-0.15,-0.15, colunas[0]) : drawO(-0.3,-0.3);
        else if(posicao == 7)   (jogadas %2 != 0) ? drawX(-0.15,-0.45, 0.15,-0.15, colunas[1]) : drawO( 0.0,-0.3);
        else if(posicao == 8)   (jogadas %2 != 0) ? drawX( 0.15,-0.45, 0.45,-0.15, colunas[2]) : drawO( 0.3,-0.3);
    }
}
void imprimeJogo()
{
    int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf(" %c ", Game[i][j]);
            if(j<2) printf("|");
        }
        if(i<2) printf("\n-----------\n");
    }
    printf("\n\n\n");
}
