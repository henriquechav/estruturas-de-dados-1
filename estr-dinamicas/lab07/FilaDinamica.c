/* Solução para o problema 142. */
#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    long chave;
    struct tItem *proximo;
};
typedef struct tItem tItem;

struct tFila
{
    tItem *primeiro;
    tItem *ultimo;
};
typedef struct tFila tFila;

tItem* criarItem(long);
tFila* criar(void);
int vazia(tFila*);
void enfileirar(tFila*, tItem*);
void desenfileirar(tFila*);
void mostrar(tFila*);

int main(void)
{
    tFila *fila = criar();
    long valor;
    char cmd;

    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf("%ld", &valor);
                enfileirar(fila, criarItem(valor));
                break;
            case 'D':
                desenfileirar(fila);
                break;
            case 'M':
                mostrar(fila);
                break;
        }
    }

    return 0;
}

tItem* criarItem(long chave)
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

void enfileirar(tFila *f, tItem *novo)
{
    if (vazia(f))
        f->primeiro = novo;
    else
        f->ultimo->proximo = novo;
    f->ultimo = novo;
}

void desenfileirar(tFila *f)
{
    if (!vazia(f)) {
        tItem *aux = f->primeiro;
        if (f->primeiro == f->ultimo) {
            f->primeiro = NULL;
            f->ultimo = NULL;
        } else {
            f->primeiro = f->primeiro->proximo;
        }
        printf("<%ld>\n", aux->chave);
        free(aux);
    }
}

void mostrar(tFila *f)
{
    tItem *it = f->primeiro;
    while (it != NULL) {
        printf("%ld%s", it->chave, it->proximo != NULL ? " " : "\n");
        it = it->proximo;
    }
}
