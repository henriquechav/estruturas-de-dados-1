/* Solução para o problema 140. */
#include <stdio.h>
#include <stdlib.h>

struct tItem 
{
    int pos;
    long chave;
    struct tItem *proximo;
};
typedef struct tItem tItem;

struct tLista
{  
    tItem *primeiro;
    int qnt;
};
typedef struct tLista tLista; 

tLista* criar(void);
tItem* criarItem(long);
long pegarNo(tItem*, int);
void inserir(tLista*, long, int);
void excluir(tLista*);

int main(void)
{
    int qntBlocos, qntItens, pos;
    tLista *lista;
    long valor;
    scanf("%d", &qntBlocos);
    for (int i = 0; i < qntBlocos; i++) {
        lista = criar();
        scanf("%d", &qntItens);
        for (int j = qntItens - 1; j >= 0; j--) {
            scanf("%ld", &valor);
            inserir(lista, valor, j);
        }
        scanf("%d", &pos);
        valor = pegarNo(lista->primeiro, pos);
        printf("%ld\n", valor);
        excluir(lista);
    }

    return 0;
}

tLista* criar(void)
{
    tLista *lista = (tLista*)malloc(sizeof(tLista));
    if (lista != NULL) {
        lista->primeiro = NULL;
        lista->qnt = 0;
    }
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

long pegarNo(tItem *cabeca, int pos)
{
    tItem *it = cabeca;
    while (it != NULL && it->pos != pos)
        it = it->proximo;
    return it->chave;
}

void inserir(tLista *l, long chave, int pos)
{
    tItem *it = l->primeiro;
    tItem *novo = criarItem(chave);
    novo->pos = pos;

    while(it != NULL && it->proximo != NULL)
        it = it->proximo;
    if (it == NULL)
        l->primeiro = novo;
    else
        it->proximo = novo;
    
    l->qnt++;
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
