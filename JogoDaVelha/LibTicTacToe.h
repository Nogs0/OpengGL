#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.1415926535898

struct no{
    int vencedor;
    struct no *prox;
};
struct no *Partidas;
float x, y;
char Game[3][3];
int jogadas = 0, win = 0, active = 1, vencedor = 0;
bool check = true;
int posicao = -1;
float colunas[3] = { 0.6, 0.0,-0.6};

void wins();
void Draw(void);
void drawplays();
void drawO(float, float);
void drawX(float, float, float, float, float);
void Layout();
void Finish();
void mouse(int button, int state, int mousex, int mousey);

int VerificaTabuleiro(int mousex, int mousey);
int VerificaColuna0();
int VerificaColuna1();
int VerificaColuna2();
int VerificaLinha0();
int VerificaLinha1();
int VerificaLinha2();
int VerificationD1();
int VerificationD2();
void FillGame();
void imprimeJogo();

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
void Finish(){
    //Mostrar ranking dos jogadores
}
void TryAgain(){
    glClear(GL_COLOR_BUFFER_BIT);
    FillGame();
    active = 1;
    //clique em qualquer lugar para continuar

}
void Draw()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,0,0,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Layout();
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
    if(VerificationD1() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(-0.62, 0.58);
        glVertex2f(-0.58, 0.62);
        glVertex2f(0.62, -0.58);
        glVertex2f(0.58, -0.62);

    }
    glEnd();
    if(VerificationD2() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(-0.58, -0.62);
        glVertex2f(-0.62, -0.58);
        glVertex2f(0.62, 0.58);
        glVertex2f(0.58, 0.62);

    }
    glEnd();
    if(VerificaLinha0() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(-0.60, 0.28);
        glVertex2f(-0.60, 0.32);
        glVertex2f(0.60, 0.28);
        glVertex2f(0.60, 0.32);
    }
    glEnd();
    if(VerificaLinha1() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(-0.60, 0.02);
        glVertex2f(-0.60, -0.02);
        glVertex2f(0.60, 0.02);
        glVertex2f(0.60, -0.02);
    }
    glEnd();
    if(VerificaLinha2() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(-0.60, -0.28);
        glVertex2f(-0.60, -0.32);
        glVertex2f(0.60, -0.28);
        glVertex2f(0.60, -0.32);
    }
    glEnd();
    if(VerificaColuna0() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(-0.28, 0.60);
        glVertex2f(-0.32, 0.60);
        glVertex2f(-0.32,-0.60);
        glVertex2f(-0.28,-0.60);
    }
    glEnd();
    if(VerificaColuna1() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(-0.02, 0.60);
        glVertex2f(0.02,0.60);
        glVertex2f(-0.02,-0.60);
        glVertex2f(0.02,-0.60);
    }
    glEnd();
    if(VerificaColuna2() != 0){
        active = 0;
        glBegin(GL_QUADS);
        glVertex2f(0.32, 0.60);
        glVertex2f(0.28, 0.60);
        glVertex2f(0.32,-0.60);
        glVertex2f(0.28,-0.60);
    }
    glEnd();
    if(posicao == 9){
        Finish();
    }
    if(posicao == 10){
        TryAgain();
    }
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
    printf("%d\n ", mousex);
    printf("%d\n ", mousey);
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
        else if(mousex < 500 && mousex > 375 && mousey > 450 && mousey < 500){
            active = 0;
            return 9;
        }
        else if(mousex > 0 && mousex < 125 && mousey > 450 && mousey < 500){
            return 10;
        }
    return 11;

}

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        int linha = 0;
        x = mousex;
        y = mousey;
        posicao = VerificaTabuleiro(x, y);
        if(active == 1){
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
    }

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
            if(conf == 2){
                (jogadas%2 != 0) ? push(Partidas, 1) : push(Partidas, 2);
            }
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
