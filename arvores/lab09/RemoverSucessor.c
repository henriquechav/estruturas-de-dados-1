/* Solução para o problema 25. */
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
void preOrder(no*);
no* buscar(arvoreb*, int);
void inserir(arvoreb*, no*);
void remover(arvoreb*, int);
no* sucessor(no*);
no* removerSucessor(no*);

int main(void)
{
    arvoreb *arvore = criar();
    
    int qntNos, valor;
    scanf("%d", &qntNos);
    for (int i = 0; i < qntNos; i++) {
        scanf("%d", &valor);
        inserir(arvore, criarNo(valor));
    }

    int qntRem;
    scanf("%d", &qntRem);
    for (int j = 0; j < qntRem; j++) {
        scanf("%d", &valor);
        remover(arvore, valor);
    }

    preOrder(arvore->raiz);

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

void preOrder(no *r)
{
    if (r == NULL) return;
    printf("%d\n", r->chave);
    preOrder(r->esq);
    preOrder(r->dir);
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

void remover(arvoreb *t, int chave)
{
    no *r = t->raiz, *pai = NULL, *subs;
    while (r != NULL && r->chave != chave) {
        pai = r;
        if (r->chave < chave)
            r = r->dir;
        else
            r = r->esq;
    }

    if (r != NULL) {
        if (r->esq == NULL && r->dir == NULL) {
            if (pai != NULL) {
                if (pai->esq == r)
                    pai->esq = NULL;
                else
                    pai->dir = NULL;
            } else {
                t->raiz = NULL;
            }
        } else if (r->esq != NULL && r->dir != NULL) {
            subs = removerSucessor(sucessor(r));
            subs->pai = pai;
            subs->esq = r->esq;
            subs->dir = r->dir;

            r->esq->pai = subs;
            if (r->dir != NULL)
                r->dir->pai = subs;

            if (pai != NULL) {
                if (pai->esq == r)
                    pai->esq = subs;
                else
                    pai->dir = subs;
            } else {
                t->raiz = subs;
            }
        } else {
            no *filho;
            if (r->esq != NULL)
                filho = r->esq;
            else
                filho = r->dir;
            
            if (pai != NULL) {
                filho->pai = pai;
                if (pai->esq == r)
                    pai->esq = filho;
                else
                    pai->dir = filho;
            } else {
                t->raiz = filho;
            }
        }
        r->pai = NULL;
        r->esq = NULL;
        r->dir = NULL;
        free(r);
    }
}

no* sucessor(no *r)
{
    r = r->dir;
    while (r->esq != NULL)
        r = r->esq;
    return r;
}

no* removerSucessor(no *r)
{
    no *pai = r->pai;

    if (pai->esq == r)
        pai->esq = r->dir;
    else
        pai->dir = r->dir;

    if (r->dir != NULL) {
        r->dir->pai = pai;
        r->dir = NULL;
    }

    r->pai = NULL;

    return r;
}
