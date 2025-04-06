/* Solução para o problema 148. */
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int chave;
    struct item *proximo;
    struct item *anterior;
} item;

typedef struct listadd
{
    item *primeiro;
    item *ultimo;
} listadd;

item* criarItem(int);
listadd* criar(void);
void inserir(listadd*, int);
void remover(listadd*, int);
int buscar(listadd*, int);
void mostrarPrimeiroUltimo(listadd*);
void mostrarUltimoPrimeiro(listadd*);

int main(void)
{
    listadd *lista = criar();
    int valor;
    char cmd;
    while (scanf(" %c", &cmd) != EOF) {
        switch (cmd) {
            case 'I':
                scanf("%d", &valor);
                inserir(lista, valor);
                break;
            case 'E':
                scanf("%d", &valor);
                remover(lista, valor);
                break;
            case 'M':
                mostrarPrimeiroUltimo(lista);
                break;
            case 'R':
                mostrarUltimoPrimeiro(lista);
                break;
        }
    }

    return 0;
}

item* criarItem(int chave)
{
    item *it = (item*)malloc(sizeof(item));
    if (it != NULL) {
        it->chave = chave;
        it->anterior = NULL;
    }
    return it;
}

listadd* criar(void)
{
    listadd *l = (listadd*)malloc(sizeof(listadd));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

void inserir(listadd *l, int chave)
{
    if (buscar(l, chave) != -1) return;
    item *novo = criarItem(chave);
    item *it = l->primeiro;
    while (it != NULL && it->chave < chave)
        it = it->proximo;

    if (it != NULL) { /* inserção meio ou início (lista não-vazia) */
        if (it->anterior != NULL) {
            novo->proximo = it;
            novo->anterior = it->anterior;
            it->anterior->proximo = novo;
            it->anterior = novo;
        } else {
            novo->proximo = it;
            it->anterior = novo;
            l->primeiro = novo;
        }
    } else { /* inserção final ou início (lista vazia) */
        if (l->primeiro != NULL) {
            novo->anterior = l->ultimo;
            l->ultimo->proximo = novo;
            l->ultimo = novo;
        } else {
            l->primeiro = novo;
            l->ultimo = novo;
        }
    }
}

void remover(listadd *l, int chave)
{
    if (buscar(l, chave) == -1) return;
    item *it = l->primeiro;
    while (it->chave != chave)
        it = it->proximo;

    if (it->anterior != NULL) { /* remoção meio ou final */
        if (it->proximo != NULL) {
            it->anterior->proximo = it->proximo;
            it->proximo->anterior = it->anterior;
        } else {
            it->anterior->proximo = NULL;
            l->ultimo = it->anterior;
        }
    } else { /* remoção início com um ou vários elementos */
        if (l->primeiro == l->ultimo) {
            l->primeiro = NULL;
            l->ultimo = NULL;
        } else {
            it->proximo->anterior = NULL;
            l->primeiro = it->proximo;
        }
    }
    free(it);
}

int buscar(listadd *l, int chave)
{
    item *it = l->primeiro;
    int count = 0;
    while (it != NULL) {
        if (it->chave == chave)
            return count;
        count++;
        it = it->proximo;
    }
    return -1;
}

void mostrarPrimeiroUltimo(listadd *l)
{
    item *it = l->primeiro;
    while (it != NULL) {
        printf("%d ", it->chave);
        it = it->proximo;
    }
    printf("\n");
}

void mostrarUltimoPrimeiro(listadd *l)
{
    item *it = l->ultimo;
    while (it != NULL) {
        printf("%d ", it->chave);
        it = it->anterior;
    }
    printf("\n");
}
