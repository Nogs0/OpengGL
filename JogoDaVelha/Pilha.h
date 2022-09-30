#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
typedef struct no{
    int partida;
    char *ganhador;
    struct no *prox;
}No;
typedef struct{
    No* inicio;
    No* fim;
}Fila;
void criar(Fila *);
int push(Fila *, int, char*);
No* pop(Fila *);
int vazia(Fila);
void mostra(Fila);
No* inicio(Fila);
#endif // PILHA_H_INCLUDED
