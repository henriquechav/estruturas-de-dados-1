/* Solução para o problema 139. */
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
tItem* deletarPos(tItem*, int);
void mostrar(tLista*);
void inserir(tLista*, long);
void excluir(tLista*);

int main(void)
{
    tLista *lista;
    long valor;
    int qntBlocos, qntItens, pos;
    scanf("%d", &qntBlocos);
    for (int i = 0; i < qntBlocos; i++) {
        lista = criarLista();
        scanf("%d", &qntItens);
        for (int j = 0; j < qntItens; j++) {
            scanf("%ld", &valor);
            inserir(lista, valor);
        }
        scanf("%d", &pos);
        lista->primeiro = deletarPos(lista->primeiro, pos);
        mostrar(lista);
        excluir(lista);
    }

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
    tItem *it = (tItem*)malloc(sizeof(tItem));
    if (it != NULL) {
        it->chave = chave;
        it->proximo = NULL;
    }
    return it;
}

tItem* deletarPos(tItem *cabeca, int pos)
{
    tItem *anterior = NULL;
    tItem *it = cabeca;
    int count = 0;
    while (it != NULL && count < pos) {
        anterior = it;
        it = it->proximo;
        count++;
    }
    if (anterior != NULL)
        anterior->proximo = it->proximo;
    else 
        cabeca = it->proximo;
    free(it);
    return cabeca;
}

void mostrar(tLista *l)
{
    tItem *it = l->primeiro;
    while (it != NULL) {
        printf("%ld%s", it->chave, it->proximo != NULL ? " " : "\n");
        it = it->proximo;
    }
}

void inserir(tLista *l, long chave)
{
    tItem *it = l->primeiro;
    while (it != NULL && it->proximo != NULL)
        it = it->proximo;
    if (it != NULL)
        it->proximo = criarItem(chave);
    else
        l->primeiro = criarItem(chave);
}

void excluir(tLista *l)
{
    tItem *aux = NULL;
    tItem *it = l->primeiro;
    while (it != NULL) {
        aux = it;
        it = it->proximo;
        free(aux);
    }
    free(l);
}
