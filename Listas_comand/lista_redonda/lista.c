#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <malloc.h>

struct ListaCircular{
    struct lista *pri;
    struct lista *ult;
    int tam;
};

struct lista{
    int info;
    struct lista *prox;
};

ListaCircular *criar(){
    ListaCircular *l = (struct ListaCircular *) malloc(sizeof(ListaCircular));
    l->pri = NULL;
    l->ult = NULL;
    l->tam = 0;
    return l;
}

Lista *inserir(ListaCircular *l, int valor){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    if(l->pri == NULL){
        l->pri = novo;
        l->ult = novo;
        novo->prox = novo;
    }
    l->ult->prox = novo;
    novo->prox = l->pri;
    l->ult = novo;

    l->tam += 1;

    return novo;
}


Lista *remover(ListaCircular *l, int valor){
    Lista *recebe = l->pri;
    Lista *antes = NULL;
    while(recebe != NULL){
        if(recebe->info == valor){
            if(antes == NULL){
                l->pri = recebe->prox;
                l->ult->prox = recebe->prox;
                free(recebe);
                l->tam -= 1;
            }
           else{
            antes->prox = recebe->prox;
            free(recebe);
            l->tam -= 1;
            return recebe;
           }
        }
        antes = recebe;
        recebe = recebe->prox;
    }
    return 0;
}

void imprimir(ListaCircular *l) {
    Lista *p = l->pri;
if (p) {
    do {
        printf("%d\n", p->info);
        p = p->prox;
        }while (p != l->pri);
    }
}



