/* Solução para o problema 133. */
#include <stdio.h>
#include <stdlib.h>

struct tItem
{
    long chave;
    struct tItem *proximo;
};
typedef struct tItem tItem;

typedef struct 
{
    tItem *primeiro;
} tLista;

tLista* criarLista();
tItem* criarItem(long);
int vazia(tLista*);
void buscar(tLista*, long);
void inserir(tLista*, tItem*);
void remover(tLista*, long);
void mostrar(tLista*);

int main(void)
{
    tLista *lista = criarLista();
    long valor;
    char cmd;
    while ( scanf(" %c", &cmd) != EOF ) {
        if (cmd != 'L')
            scanf("%ld", &valor);
        switch (cmd) {
            case 'I':
                inserir(lista, criarItem(valor));
                break;
            case 'R':
                remover(lista, valor);
                break;
            case 'B':
                buscar(lista, valor);
                break;
            case 'L':
                mostrar(lista);
                break;
        }
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

int vazia(tLista *l)
{
    return l->primeiro == NULL;
}

void buscar(tLista *l, long chave)
{
    tItem *it = l->primeiro;
    while (it != NULL && it->chave < chave)
        it = it->proximo;

    if (it != NULL && it->chave == chave)
        printf("SIM\n");
    else
        printf("NAO\n");
}

void inserir(tLista *l, tItem *novo)
{
    tItem *anterior = NULL;
    tItem *atual = l->primeiro;
    while (atual != NULL && atual->chave < novo->chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL || atual->chave != novo->chave) {
        novo->proximo = atual;
        if (anterior != NULL)
            anterior->proximo = novo;
        else
            l->primeiro = novo;
    }
}

void remover(tLista *l, long chave)
{
    tItem *anterior = NULL;
    tItem *rem = l->primeiro;
    while (rem != NULL && rem->chave < chave) {
        anterior = rem;
        rem = rem->proximo;
    }

    if (rem != NULL && rem->chave == chave) {
        if (anterior != NULL)
            anterior->proximo = rem->proximo;
        else 
            l->primeiro = rem->proximo;
        free(rem);
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
