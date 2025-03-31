/* Solução para o problema 138. */
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
void inserirCauda(tLista*, tItem*);
void mostrarListaReversa(tItem*);
void excluirLista(tLista*);

int main(void)
{
    tLista *lista;
    long valor;
    int q, n;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &n);
        lista = criarLista();
        for (int j = 0; j < n; j++) {
            scanf("%ld", &valor);
            inserirCauda(lista, criarItem(valor));
        }
        mostrarListaReversa(lista->primeiro);
        excluirLista(lista);
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

void inserirCauda(tLista *l, tItem *novo)
{
    tItem *it = l->primeiro;
    while (it != NULL && it->proximo != NULL)
        it = it->proximo;
    if (it != NULL)
        it->proximo = novo;
    else
        l->primeiro = novo;
}

void mostrarListaReversa(tItem *cabeca)
{
    if (cabeca == NULL) {
        return;
    } else {
        mostrarListaReversa(cabeca->proximo);
        printf("%ld\n", cabeca->chave);
    }
}

void excluirLista(tLista *l)
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
