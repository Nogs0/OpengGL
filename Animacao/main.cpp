#include <GL/freeglut.h>
#include <stdio.h>
GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;
// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
GLfloat windowWidth;
GLfloat windowHeight;
GLfloat uai = 0.0f;
GLfloat xis = 0.0f;
GLfloat Ft = 20.0f;
typedef struct
{
    int ponto;
    int rsize;
    GLfloat x;
    GLfloat y;
} Quadrado;
typedef struct ponto
{
    GLfloat x;
    GLfloat y;
} Ponto;

Ponto roberto, junior;
Quadrado robertinho, juninho;

void Desenha(void)
{
    roberto.x = 270;
    roberto.y = 190;
    robertinho.rsize = 100;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2i(juninho.x,juninho.y+rsize);
    glVertex2i(juninho.x,juninho.y);
    glVertex2i(juninho.x+rsize,juninho.y);
    glVertex2i(juninho.x+rsize,juninho.y+rsize);

    glEnd();

    glTranslatef(xis, uai, 0);

    glBegin(GL_QUADS);
    glVertex2i(roberto.x,roberto.y+robertinho.rsize);
    glVertex2i(roberto.x,roberto.y);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2i(roberto.x+robertinho.rsize,roberto.y);
    glVertex2i(roberto.x+robertinho.rsize,roberto.y+robertinho.rsize);

    glEnd();
    glutSwapBuffers();

}
void Timer(int value)
{
    // Muda a dire o quando chega na borda esquerda ou direita��
    if(juninho.x > windowWidth-rsize || juninho.x < 0)
        xstep = -xstep;
    // Muda a dire o quando chega na borda superior ou inferior��
    if(juninho.y > windowHeight-rsize || juninho.y < 0)
        ystep = -ystep;
    // Verifica o de bordas.  Se a window for menor e o quadrado sair do volume de��
    if(juninho.y > windowWidth-rsize)
        juninho.y = windowWidth-rsize-1;
    if(juninho.y > windowHeight-rsize)
        juninho.y = windowHeight-rsize-1;
    juninho.x += xstep;
    juninho.y += ystep;
    glutPostRedisplay();
    glutTimerFunc(5,Timer, 0);
}
void

void listeningkey(unsigned char tecla, GLint x, GLint y)
{
    switch (tecla)
    {
    case 'a': xis -= Ft;
        break;
    case 'd': xis += Ft;
        break;
    case 's': uai -= Ft;
        break;
    case 'w': uai += Ft;
        break;
    }
}
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    printf("\n w: %d      h: %d ", w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    windowWidth = w;
    windowHeight = h;
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Animacao");
    glutKeyboardFunc(listeningkey);
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutTimerFunc(5, Timer, 0);
    glutMainLoop();
}
