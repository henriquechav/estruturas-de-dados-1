/* Solução para o problema 149. */
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
    listadd *listas[2];
    listas[0] = criar();
    listas[1] = criar();
    int valor, ind;
    char cmd, lst;
    while (scanf(" %c", &cmd) != EOF) {
        scanf(" %c", &lst);
        if (lst == 'A') ind = 0;
        else ind = 1;
        switch (cmd) {
            case 'I':
                scanf("%d", &valor);
                inserir(listas[ind], valor);
                break;
            case 'E':
                scanf("%d", &valor);
                remover(listas[ind], valor);
                break;
            case 'M':
                mostrarPrimeiroUltimo(listas[ind]);
                break;
            case 'R':
                mostrarUltimoPrimeiro(listas[ind]);
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
        it->proximo = NULL;
        it->anterior = NULL;
    }
    return it;
}

listadd* criar(void)
{
    listadd* l = (listadd*)malloc(sizeof(listadd));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

void inserir(listadd *l, int chave)
{
    item *novo = criarItem(chave);
    item *it = l->primeiro;
    while (it != NULL && it->chave < chave)
        it = it->proximo;

    if (it != NULL) { /* meio ou começo lista não-vazia */
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
    } else { /* final ou começo lista vazia */
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

    if (it->anterior != NULL) { /* meio ou final */
        if (it->proximo != NULL) {
            it->anterior->proximo = it->proximo;
            it->proximo->anterior = it->anterior;
        } else {
            it->anterior->proximo = NULL;
            l->ultimo = it->anterior;
        }
    } else { /* começo com um ou vários elementos */
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
    for (int count = 0; it != NULL; it = it->proximo, count++) {
        if (it->chave == chave)
            return count;
    }
    return -1;
}

void mostrarPrimeiroUltimo(listadd *l)
{
    item *it = l->primeiro;
    while (it != NULL) {
        printf("%d%s", it->chave, it->proximo != NULL ? " " : "\n");
        it = it->proximo;
    }
}

void mostrarUltimoPrimeiro(listadd *l)
{
    item *it = l->ultimo;
    while (it != NULL) {
        printf("%d%s", it->chave, it->anterior != NULL ? " " : "\n");
        it = it->anterior;
    }
}
