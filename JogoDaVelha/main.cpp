#include "Cabeca.h"
#include "Pilha.h"
#include <GL/freeglut.h>

int main(int argc, char *argv[])
{
    Beginning();
    FillGame();
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(600,200);
    glutCreateWindow("Tic Tac Toe");
    glutMouseFunc(mouse);
    glutDisplayFunc(Draw);
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutMainLoop();

    return 0;
}
