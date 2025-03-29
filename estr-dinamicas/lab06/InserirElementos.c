/* Solução para o problema 134. */
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
tItem* inserirCabeca(tItem*, long);
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
            lista->primeiro = inserirCabeca(lista->primeiro, valor);
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

tItem* inserirCabeca(tItem *cabeca, long chave)
{
    tItem *nova = criarItem(chave);
    nova->proximo = cabeca;
    return nova;
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
