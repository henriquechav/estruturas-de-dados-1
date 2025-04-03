/* Implementação de Fila Dinâmica em C. */
#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    int chave;
    struct tItem *proximo;
};
typedef struct tItem tItem;

struct tFila
{
    tItem *primeiro;
    tItem *ultimo;
};
typedef struct tFila tFila;

tItem* criarItem(int chave)
{
    tItem *it = (tItem*)malloc(sizeof(tItem));
    if (it != NULL) {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

tFila* criar(void)
{
    tFila *fila = (tFila*)malloc(sizeof(tFila));
    if (fila != NULL) {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    return fila;
}

int vazia(tFila *f)
{
    return f->primeiro == NULL && f->ultimo == NULL;
}

void mostrar(tFila *f)
{
    tItem *it = f->primeiro;
    while (it != NULL) {
        printf("%d%s", it->chave, it->proximo != NULL ? " " : "\n");
        it = it->proximo;
    }
}

void enfileirar(tFila *f, tItem *novo)
{
    if (vazia(f)) {
        f->primeiro = novo;
    } else {
        f->ultimo->proximo = novo;
    }
    f->ultimo = novo;
}

tItem* desenfileirar(tFila *f)
{
    tItem *it = f->primeiro;
    if (it != NULL) {
        f->primeiro = it->proximo;
        if (f->primeiro == NULL)
            f->ultimo = NULL;
        it->proximo = NULL;
    }
    return it;
}
