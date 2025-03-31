/* Solução para o problema 135. */
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

tLista* criarLista();
tItem* criarItem(long);
tItem* inserirCauda(tItem*, long);
void mostrar(tLista*);
void excluir(tLista*);

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
            lista->primeiro = inserirCauda(lista->primeiro, valor);
        }
        mostrar(lista);
        excluir(lista);
    }

    return 0;
}

tLista* criarLista()
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

tItem* inserirCauda(tItem *cabeca, long chave)
{
    tItem *it = cabeca;
    while (it != NULL && it->proximo != NULL)
        it = it->proximo;
    if (it != NULL) {
        it->proximo = criarItem(chave);
        return cabeca;
    } else {
        return criarItem(chave);
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

void excluir(tLista *l)
{
    tItem *anterior = NULL;
    tItem *it = l->primeiro;
    while (it != NULL) {
        anterior = it;
        it = it->proximo;
        free(anterior);
    }
    free(l);
}
