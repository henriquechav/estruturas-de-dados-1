/* Solução para o problema 144. */
#include <stdio.h>
#include <stdlib.h>

typedef struct item 
{
    int chave;
    struct item *proximo;
    struct item *anterior;
} item;

typedef struct filad
{
    item *primeiro;
    item *ultimo;
} filad;

typedef struct pilhad
{
    item *topo;
} pilhad;

item* criarItem(int);
filad* criarFila(void);
pilhad* criarPilha(void);
void enfileirar(filad*, item*);
void desenfileirar(filad*);
void igualar(filad*, pilhad*);
void mostrarPilha(pilhad*);

int main(void)
{
    filad *fila = criarFila();
    pilhad *pilha = criarPilha();
    int valor;
    char cmd;
    while (scanf(" %c", &cmd) != EOF) {
        switch (cmd) {
            case 'E':
                scanf("%d", &valor);
                enfileirar(fila, criarItem(valor));
                break;
            case 'D':
                desenfileirar(fila);
                break;
            case 'P':
                igualar(fila, pilha);
                break;
            case 'M':
                mostrarPilha(pilha);
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
        it->proximo = NULL;
        it->anterior = NULL;
    }
    return it;
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

pilhad* criarPilha(void)
{
    pilhad *p = (pilhad*)malloc(sizeof(pilhad));
    if (p != NULL) 
        p->topo = NULL;
    return p;
}

void enfileirar(filad *f, item *novo)
{
    if (f->primeiro == NULL) {
        f->primeiro = novo;
    } else {
        f->ultimo->proximo = novo;
        f->ultimo->anterior = novo;
    }
    f->ultimo = novo;
}

void desenfileirar(filad *f)
{
    if (f->primeiro != NULL) {
        item *aux = f->primeiro;
        if (f->primeiro == f->ultimo) {
            f->primeiro = NULL;
            f->ultimo = NULL;
        } else {
            f->primeiro = f->primeiro->proximo;
        }
        free(aux);
    }
}

void igualar(filad *f, pilhad *p)
{
    p->topo = f->primeiro;
}

void mostrarPilha(pilhad *p)
{
    item *it = p->topo;
    while (it != NULL) {
        printf("%d\n", it->chave);
        it = it->anterior;
    }
}
