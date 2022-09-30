#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

void criar(Fila *q){
    q->inicio = NULL;
    q->fim =NULL;
}

int push(Fila *q, int rodada, char *nome){
    No *aux;
    aux = (No *)malloc(sizeof(No));
    if(aux == NULL) return 0;
    aux->partida = rodada;
    aux->ganhador = nome;
    if(q->inicio == NULL){
        aux->prox = NULL;
        q->inicio = q->fim = aux;
        return 1;
    }
    q->fim->prox = aux;
    q->fim = aux;
    return 1;
}

No* pop(Fila *q){
    No *remover = NULL;

    if(q->inicio == NULL) return NULL;

    remover = q->inicio;
    q->inicio = q->inicio->prox;
    return remover;
}

int vazia(Fila q){
    if(q.inicio == NULL) return 1;
    return 0;
}

void mostra(Fila q){
    No *aux;
    if(q.inicio == NULL) printf("Fila Vazia!\n");
    else{
        aux = q.inicio;
        do{
            printf("Partida: %d\n", aux->partida);
            printf("Vencedor: %s\n", aux->ganhador);
            aux = aux->prox;
        }while(aux != NULL);
    }
}

No* inicio(Fila q){
    if(q.inicio == NULL) return NULL;
    else return q.inicio;

}
