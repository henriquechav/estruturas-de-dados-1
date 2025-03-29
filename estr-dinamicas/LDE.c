/* Implementação da estrutura Lista Dinâmica Encadeada em C. */
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int chave;
    tItem *proximo;
} tItem;

typedef struct 
{
    tItem *primeiro;
} tLista;

tLista* criarLista();
tItem* criarItem(int);
int vazia(tLista*);
tItem* primeiro(tLista*);
void mostrar(tLista*);
tItem* buscar(tLista*, int);
void inserir(tLista*, tItem*);
tItem* remover(tLista*, int);

int main(void)
{
    return 0;
}

tLista* criarLista()
{
    tLista *lista = (tLista*)malloc(sizeof(tLista));
    lista->primeiro = NULL;
    return lista;
}

tItem* criarItem(int chave)
{
    tItem *it = (tItem*)malloc(sizeof(tItem));
    it->chave = chave;
    it->proximo = NULL;
    return it;
}

int vazia(tLista *l)
{
    return l->primeiro == NULL;
}

tItem* primeiro(tLista *l)
{
    return l->primeiro;
}

void mostrar(tLista *l)
{
    tItem *it = primeiro(l); 
    while (it != NULL) {
        printf("%d%s", it->chave, it->proximo != NULL ? " " : "\n");
        it = it->proximo;
    }
}

tItem* buscar(tLista *l, int chave)
{
    tItem *it = primeiro(l);
    while (it != NULL && it->chave < chave)
        it = it->proximo;
    
    if (it != NULL && it->chave == chave)
        return it;
    else
        return NULL;
}

void inserir(tLista *l, tItem *novo)
{
    tItem *anterior = NULL;
    tItem *atual = primeiro(l);
    while (atual != NULL && atual->chave < novo->chave) {
        anterior = atual;
        atual = atual->proximo;
    }

    novo->proximo = atual;
    if (anterior != NULL) // meio ou final
        anterior->proximo = novo;
    else // início
        l->primeiro = novo;
}

tItem* remover(tLista *l, int chave)
{
    tItem *anterior = NULL;
    tItem *rem = primeiro(l);
    while (rem != NULL && rem->chave < chave) {
        anterior = rem;
        rem = rem->proximo;
    }

    if (rem != NULL && rem->chave == chave) {
        if (anterior != NULL)
            anterior->proximo = rem->proximo;
        else
            l->primeiro = rem->proximo;
        return rem;
    } else {
        return NULL;
    }
}
