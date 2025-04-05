/* Solução para o problema 145. */
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int chave;
    struct item *ptr;
} item;

typedef struct pilhad
{
    item *topo;
} pilhad;

typedef struct filad
{
    item *primeiro;
    item *ultimo;
} filad;

item* criarItem(int);
pilhad* criarPilha(void);
filad* criarFila(void);
void empilhar(pilhad*, item*);
void desempilhar(pilhad*);
void igualar(pilhad*, filad*);
void mostrarFila(filad*);

int main(void)
{
    pilhad *pilha = criarPilha();
    filad *fila = criarFila();
    int valor;
    char cmd;
    while (scanf(" %c", &cmd) != EOF) {
        switch (cmd) {
            case 'E':
                scanf("%d", &valor);
                empilhar(pilha, criarItem(valor));
                break;
            case 'D':
                desempilhar(pilha);
                break;
            case 'F':
                igualar(pilha, fila);
                break;
            case 'M':
                mostrarFila(fila);
                break;
        }
    }

    return 0;
}

item* criarItem(int chave)
{
    item *it = (item*)malloc(sizeof(item));
    if (it != NULL) {
        it->chave = chave;
        it->ptr = NULL;
    }
    return it;
}

pilhad* criarPilha(void)
{
    pilhad *p = (pilhad*)malloc(sizeof(pilhad));
    if (p != NULL)
        p->topo = NULL;
    return p;
}

filad* criarFila(void)
{
    filad *f = (filad*)malloc(sizeof(filad));
    if (f != NULL) {
        f->primeiro = NULL;
        f->ultimo = NULL;
    }
    return f;
}

void empilhar(pilhad *p, item *novo)
{
    novo->ptr = p->topo;
    p->topo = novo;
}

void desempilhar(pilhad *p)
{
    if (p->topo != NULL) {
        p->topo = p->topo->ptr;
    }
}

void igualar(pilhad *p, filad *f)
{
    if (p->topo != NULL) {
        f->primeiro = p->topo;
        f->ultimo = p->topo;
        while (f->ultimo->ptr != NULL)
            f->ultimo = f->ultimo->ptr;
    }
}

void mostrarFila(filad *f)
{
    item *it = f->primeiro;
    while (it != NULL) {
        printf("%d\n", it->chave);
        it = it->ptr;
    }
}
