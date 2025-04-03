/* Solução para o problema 141. */
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

tLista* criar(void);
tItem* criarItem(long);
void inserir(tLista*, long);
void excluir(tLista*);
void mostrar(tLista*);
tItem* inverter(tItem*);

int main(void)
{
    int qntBlocos, qntItens;
    tLista *lista;
    long valor;
    scanf("%d", &qntBlocos);
    for (int i = 0; i < qntBlocos; i++) {
        scanf("%d", &qntItens);
        lista = criar();
        for (int j = 0; j < qntItens; j++) {
            scanf("%ld", &valor);
            inserir(lista, valor);
        }
        lista->primeiro = inverter(lista->primeiro);
        mostrar(lista);
        excluir(lista);
    }

    return 0;
}

tItem* inverter(tItem *it)
{
    tItem *anterior = NULL;
    tItem *aux = NULL;
    while (it != NULL && it->proximo != NULL) {
        anterior = aux;
        aux = it;
        it = it->proximo;
        aux->proximo = anterior;
    }
    if (it != NULL)
        it->proximo = aux;
    return it;
}

tLista* criar(void)
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

void inserir(tLista *l, long chave)
{
    tItem *it = l->primeiro;
    tItem *novo = criarItem(chave);
    while (it != NULL && it->proximo != NULL)
        it = it->proximo;
    if (it != NULL)
        it->proximo = novo;
    else
        l->primeiro = novo;
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

void mostrar(tLista *l)
{
    tItem *it = l->primeiro;
    while (it != NULL) {
        printf("%ld%s", it->chave, it->proximo != NULL ? " " : "\n");
        it = it->proximo;
    }
}
