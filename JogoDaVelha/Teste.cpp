#include "Cabeca.h"
#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926535898

struct Jogador{
    char Nome[30];
    char Vitorias[30] = " ";
};
struct Jogador Player[2];
char Game[3][3];
int jogadas = 0, win = 0, active = 1, rodadas = 0;
bool check = true;
int posicao = -1;
int sair = 0;
float colunas[3] = { 0.6, 0.0,-0.6}, x, y;
struct Jogador Vencedor;

void DesenhaTextoStroke(char *aux)
{
    char *p;
    p = aux;
    while(*p)
    glutStrokeCharacter(GLUT_STROKE_ROMAN,*p++);
}

void Layout()
{
    GLfloat x = 0.25;
    GLfloat y = 1.0;
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(x,y-0.1);
    glVertex2f(x,y);
    glVertex2f(x+0.75,y);
    glVertex2f(x+0.75,y-0.1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-x,y-0.1);
    glVertex2f(-x,y);
    glVertex2f(-x-0.75,y);
    glVertex2f(-x-0.75,y-0.1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x+0.25,y-0.2);
    glVertex2f(x+0.25,y-0.1);
    glVertex2f(x+0.75,y-0.1);
    glVertex2f(x+0.75,y-0.2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x-0.75,y-0.2);
    glVertex2f(x-0.75,y-0.1);
    glVertex2f(x-1.25,y-0.1);
    glVertex2f(x-1.25,y-0.2);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x+0.25,-y+0.1);
    glVertex2f(x+0.25,-y);
    glVertex2f(x+0.75,-y);
    glVertex2f(x+0.75,-y+0.1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x-0.75,-y+0.1);
    glVertex2f(x-0.75,-y);
    glVertex2f(x-1.25,-y);
    glVertex2f(x-1.25,-y+0.1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x+0.25,-y+0.2);
    glVertex2f(x+0.25,-y+0.1);
    glVertex2f(x+0.75,-y+0.1);
    glVertex2f(x+0.75,-y+0.2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x-0.75,-y+0.2);
    glVertex2f(x-0.75,-y+0.1);
    glVertex2f(x-1.25,-y+0.1);
    glVertex2f(x-1.25,-y+0.2);
    glEnd();
}
void Beginning(){
    printf("Player 1...\nEnter with your name: ");
    scanf(" %29[^\n]", Player[0].Nome);
    printf("Player 2...\nEnter with your name: ");
    scanf(" %29[^\n]", Player[1].Nome);

}
void Coluna(float x){
    active = 0;
    glBegin(GL_LINES);
        glVertex2f(x, 0.60);
        glVertex2f(x,-0.60);
    glEnd();
}
void Linha(float y){
    active = 0;
    glBegin(GL_LINES);
        glVertex2f(0.60, y);
        glVertex2f(-0.60, y);
    glEnd();
}
void Finish()
{
    char frase[30];
    if(win!=0){
        strcpy(frase, "O vencedor foi:");
    }
    else{
        strcpy(frase, "Deu velha...");
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500.0, 0, 500.0);

    glColor3f(0,1,0);
    glTranslatef(60,400,0);
    glScalef(0.4,0.4,0.4);
    glLineWidth(2);
    DesenhaTextoStroke(frase);

    glColor3f(0,1,1);
    glTranslatef(-630,-220,0);
    glScalef(1,1,1);
    glLineWidth(2);
    DesenhaTextoStroke(Vencedor.Nome);

    glColor3f(0,1,0);
    glTranslatef(-500,-220,0);
    glScalef(1,1,1);
    glLineWidth(2);
    DesenhaTextoStroke("VITORIAS:");

    glColor3f(0,1,1);
    glTranslatef(-650,-220,0);
    glScalef(1,1,1);
    glLineWidth(2);
    DesenhaTextoStroke(Vencedor.Vitorias);

    glFlush();
    active = 0;

}
void TryAgain()
{
    glClear(GL_COLOR_BUFFER_BIT);
    FillGame();
    active = 1;
    char frase[] = "Clique!";

    glColor3f(0,1,0);
    glTranslatef(0,0,0);
    glScalef(0.5,0.5,0.5);
    glLineWidth(3);
    DesenhaTextoStroke(frase);

    glFlush();

}
void Draw()
{

    if(posicao == 10)
        TryAgain();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,0,0,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Layout();
    glLineWidth(4);
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

    if(VerificationD1() != 0)
    {
        active = 0;
        glBegin(GL_LINES);
        glVertex2f(-0.60, 0.60);
        glVertex2f(0.60, -0.60);

    }
    glEnd();
    if(VerificationD2() != 0)
    {
        active = 0;
        glBegin(GL_LINES);
        glVertex2f(-0.60, -0.60);
        glVertex2f(0.60, 0.60);

    }
    glEnd();
    if(VerificaLinha0() != 0)
        Linha(0.3);
    if(VerificaLinha1() != 0)
        Linha(0.0);
    if(VerificaLinha2() != 0)
        Linha(-0.3);
    if(VerificaColuna0() != 0)
        Coluna(-0.3);
    if(VerificaColuna1() != 0)
        Coluna(0.0);
    if(VerificaColuna2() != 0)
        Coluna(0.3);
    if(posicao == 9)
        Finish();
    drawplays();
    glFlush();
}

void FillGame()
{
    int i, j;
    for(i = 0; i<3; i++)
        for(j=0; j <3; j++)
            Game[i][j] = ' ';
}

int PlayValidation(int l, int c)
{
    if(Game[l][c] == ' ')
        return 1;
    return 0;
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
    if(active == 1){
    if(mousey < 210.00 && mousey > 140.00)
    {
        if(mousex < 210 && mousex > 145 && PlayValidation(0,0))
        {
            jogadas++;
            return 0;
        }
        if(mousex < 285 && mousex > 215 && PlayValidation(0,1))
        {
            jogadas++;
            return 1;
        }
        if(mousex < 360 && mousex > 290 && PlayValidation(0,2))
        {
            jogadas++;
            return 2;
        }
    }
    else if(mousey < 285 && mousey > 210)
    {
        if(mousex < 210 && mousex > 145 && PlayValidation(1,0))
        {
            jogadas++;
            return 3;
        }
        if(mousex < 285 && mousex > 215 && PlayValidation(1,1))
        {
            jogadas++;
            return 4;
        }
        if(mousex < 360 && mousex > 290 && PlayValidation(1,2))
        {
            jogadas++;
            return 5;
        }
    }
    else if(mousey < 360 && mousey > 285)
    {
        if(mousex < 210 && mousex > 145 && PlayValidation(2,0))
        {
            jogadas++;
            return 6;
        }
        if(mousex < 285 && mousex > 215 && PlayValidation(2,1))
        {
            jogadas++;
            return 7;
        }
        if(mousex < 360 && mousex > 290 && PlayValidation(2,2))
        {
            jogadas++;
            return 8;
        }
    }
    }
    if(mousey > 450 && mousey < 500){
        rodadas++;
    if(mousex < 500 && mousex > 375)
        return 9;
    else if(mousex > 0 && mousex < 125)
        return 10;
    }
    return 11;

}

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        check = true;
        int linha = 0;
        x = mousex;
        y = mousey;
        posicao = VerificaTabuleiro(x, y);
        Wins();
        if(active == 1)
        {
            (jogadas %2 != 0) ? Game[linha][posicao] = 'X' : Game[linha][posicao] = 'O';
            imprimeJogo();
        }
        win += VerificaLinha0();
        win += VerificaLinha1();
        win += VerificaLinha2();
        win += VerificaColuna0();
        win += VerificaColuna1();
        win += VerificaColuna2();
        win += VerificationD1();
        win += VerificationD2();
    } else if (state != GLUT_DOWN)
        check = false;

    glutPostRedisplay();
}

void drawplays()
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

int VerificaLinha0()
{
    int i = 0, j, conf = 0;
    for(j=0; j<2; j++)
    {
        if((!PlayValidation(i,j)) && Game[i][j] == Game[i][j+1])
            conf++;
        if(conf == 2)
            return 1;
    }
    return 0;
}

int VerificaLinha1()
{
    int i=1, j, conf = 0;


    for(j=0; j<2; j++)
    {
        if((!PlayValidation(i,j)) && Game[i][j] == Game[i][j+1])
            conf++;
        if(conf == 2)
            return 1;
    }


    return 0;
}

int VerificaLinha2()
{
    int i=2, j, conf = 0;
    for(j=0; j<2; j++)
    {
        if((!PlayValidation(i,j)) && Game[i][j] == Game[i][j+1])
            conf++;
        if(conf == 2)
            return 1;
    }
    return 0;
}

int VerificaColuna()
{
    int i, j, conf = 0;
    for(i = 0; i<3; i++)
    {
        for(j=0; j<2; j++)
        {
            if((!PlayValidation(j,i)) && Game[j][i] == Game[j+1][i])
                conf++;
        }
        if(conf == 2)
            return 1;
        conf = 0;
    }
    return 0;
}

int VerificaColuna0()
{
    int i = 0, j, conf = 0;
    for(j=0; j<2; j++)
    {
        if((!PlayValidation(j,i)) && Game[j][i] == Game[j+1][i])
            conf++;
        if(conf == 2)
            return 1;
    }
    return 0;
}
int VerificaColuna1()
{
    int i = 1, j, conf = 0;
    for(j=0; j<2; j++)
    {
        if((!PlayValidation(j,i)) && Game[j][i] == Game[j+1][i])
            conf++;
        if(conf == 2)
            return 1;
    }
    return 0;
}
int VerificaColuna2()
{
    int i = 2, j, conf = 0;
    for(j=0; j<2; j++)
    {
        if((!PlayValidation(j,i)) && Game[j][i] == Game[j+1][i])
            conf++;
        if(conf == 2)
            return 1;
    }
    return 0;
}

int VerificationD1()
{
    int i, conf = 0;
    for(i = 0; i<2; i++)
    {
        if((!PlayValidation(i,i)) && Game[i][i] == Game[i+1][i+1])
            conf++;
    }
    if(conf == 2)
        return 1;
    return 0;
}

int VerificationD2()
{
    int i, j, conf = 0;
    for(j = 0, i = 2; j<2, i>0 ; j++, i--)
    {
        if((!PlayValidation(i, j)) && Game[i][j] == Game[i-1][j+1])
            conf++;
    }
    if(conf == 2)
        return 1;
    return 0;

}

void Wins(){
    if(win != 0){
        if(jogadas%2 != 0){
            strcpy(Vencedor.Nome, Player[0].Nome);
            strcat(Player[0].Vitorias, " |");
        }
        else{
            strcpy(Vencedor.Nome, Player[1].Nome);
            strcat(Player[1].Vitorias, " |");
        }
    if(strcmp(Player[0].Vitorias, Player[1].Vitorias) > 0){
        strcpy(Vencedor.Vitorias, Player[0].Vitorias);
    }
    else strcpy(Vencedor.Vitorias, Player[1].Vitorias);
    }
}
