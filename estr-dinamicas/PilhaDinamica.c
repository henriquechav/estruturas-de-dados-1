/* Implementação de uma Pilha Dinâmica em C. */
#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    int chave;
    struct tItem *anterior;
};
typedef struct tItem tItem;

struct tPilha
{
    tItem *topo;
};
typedef struct tPilha tPilha;

tItem* criarItem(int chave)
{
    tItem *it = (tItem*)malloc(sizeof(tItem));
    if (it != NULL) {
        it->chave = chave;
        it->anterior = NULL;
    }
    return it;
}

tPilha* criar(void)
{
    tPilha *pilha = (tPilha*)malloc(sizeof(tPilha));
    if (pilha != NULL)
        pilha->topo = NULL;
    return pilha;
}

int vazia(tPilha *p)
{
    return p->topo == NULL;
}

void mostrarTopoBase(tPilha *p)
{
    tItem *it = p->topo;
    while (it != NULL) {
        printf("%d%s", it->chave, it->anterior != NULL ? " " : "\n");
        it = it->anterior;
    }
}

void empilhar(tPilha *p, tItem *novo)
{
    novo->anterior = p->topo;
    p->topo = novo; 
}

tItem* desempilhar(tPilha *p)
{
    tItem *it = p->topo;
    if (it != NULL) {
        p->topo = it->anterior;
        it->anterior = NULL;
    }
    return it;
}
