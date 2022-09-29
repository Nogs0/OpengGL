#ifndef CABECA_H_INCLUDED
#define CABECA_H_INCLUDED

#endif // CABECA_H_INCLUDED
#include "LibTicTacToe.h"

int main(int argc, char *argv[])
{
    Begining();
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
