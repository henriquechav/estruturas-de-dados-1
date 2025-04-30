/* Solução para o problema 26. */
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *pai;
    struct no *esq;
    struct no *dir;
} no;

typedef struct arvoreb
{
    no *raiz;
} arvoreb;

no* criarNo(int);
arvoreb* criar(void);
no* buscar(arvoreb*, int);
void inserir(arvoreb*, no*);
int altura(no*);

int main(void)
{
    arvoreb *arvore = criar();
    
    int qntNos, valor;
    scanf("%d", &qntNos);
    for (int i = 0; i < qntNos; i++) {
        scanf("%d", &valor);
        inserir(arvore, criarNo(valor));
    }

    printf("%d\n", altura(arvore->raiz));

    return 0;
}

no* criarNo(int chave)
{
    no *r = (no*)malloc(sizeof(no));
    if (r != NULL) {
        r->chave = chave;
        r->pai = NULL;
        r->esq = NULL;
        r->dir = NULL;
    }
    return r;
}

arvoreb* criar(void)
{
    arvoreb *t = (arvoreb*)malloc(sizeof(arvoreb));
    if (t != NULL)
        t->raiz = NULL;
    return t;
}

no* buscar(arvoreb *t, int chave)
{
    no *r = t->raiz;
    while (r != NULL && r->chave != chave) {
        if (r->chave < chave)
            r = r->dir;
        else
            r = r->esq;
    }
    return r;
}

void inserir(arvoreb *t, no *novo)
{
    if (buscar(t, novo->chave) != NULL) return;

    no *r = t->raiz, *pai = NULL;
    while (r != NULL) {
        pai = r;
        if (r->chave < novo->chave)
            r = r->dir;
        else
            r = r->esq;
    }

    if (pai != NULL) {
        novo->pai = pai;
        if (pai->chave < novo->chave)
            pai->dir = novo;
        else
            pai->esq = novo;
    } else {
        t->raiz = novo;
    }
}

int altura(no *r)
{
    if (r == NULL) 
        return -1;
    int altEsq = altura(r->esq);
    int altDir = altura(r->dir);
    if (altEsq > altDir)
        return altEsq + 1;
    else 
        return altDir + 1;
}