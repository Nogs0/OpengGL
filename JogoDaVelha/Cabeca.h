#ifndef CABECA_H_INCLUDED
#define CABECA_H_INCLUDED

void Wins();
void Draw();
void drawplays();
void drawO(float, float);
void drawX(float, float, float, float, float);
void Layout();
void Finish();
void mouse(int button, int state, int mousex, int mousey);
void Coluna(float x);

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
void Beginning();


#endif // CABECA_H_INCLUDED
