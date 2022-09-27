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
    glutMainLoop();

    return 0;
}

