/* Solução para o problema 136. */
#include <stdio.h>
#include <stdlib.h>

struct tItem 
{
    long chave;
    struct tItem *proximo;
};
typedef struct tItem tItem;

struct tLista
{
    tItem *primeiro;
};
typedef struct tLista tLista;

tLista* criarLista(void);
tItem* criarItem(long);
tItem* inserirPosicao(tItem*, long, int);
void mostrar(tLista*);

int main(void)
{
    tLista *lista = criarLista();
    long valor;
    int n, pos;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%ld %d", &valor, &pos);
        lista->primeiro = inserirPosicao(lista->primeiro, valor, pos);
    }
    mostrar(lista);

    return 0;
}

tLista* criarLista(void)
{
    tLista *lista = (tLista*)malloc(sizeof(tLista));
    if (lista != NULL)
        lista->primeiro = NULL;
    return lista;
}

tItem* criarItem(long chave)
{
    tItem *item = (tItem*)malloc(sizeof(tItem));
    if (item != NULL) {
        item->chave = chave;
        item->proximo = NULL;
    }
    return item;
}

tItem* inserirPosicao(tItem *cabeca, long chave, int pos)
{
    tItem *novo = criarItem(chave);
    tItem *anterior = NULL;
    tItem *it = cabeca;
    int count = 0;
    while (it != NULL && count < pos) {
        anterior = it;
        it = it->proximo;
        count++;
    }

    novo->proximo = it;
    if (anterior != NULL) {
        anterior->proximo = novo;
        return cabeca;
    } else {
        return novo;
    }
}

void mostrar(tLista *l)
{
    tItem *it = l->primeiro;
    while (it != NULL) {
        printf("%ld%s", it->chave, it->proximo != NULL ? " " : "\n");
        it = it->proximo;
    }
}
