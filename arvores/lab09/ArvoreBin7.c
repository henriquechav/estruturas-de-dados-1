/* Solução para o problema 14. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void inOrder(no*);
void postOrder(no*);
void inserir(arvoreb*, no*);
void remover(arvoreb*, int);
no* antecessor(no*);
no* removerAntecessor(no*);

int main(void)
{
    arvoreb *arvore = criar();
    char cmd[20];
    int valor;
    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "insert") == 0) {
            scanf("%d", &valor);
            inserir(arvore, criarNo(valor));
        } else if (strcmp(cmd, "delete") == 0) {
            scanf("%d", &valor);
            remover(arvore, valor);
        } else if (strcmp(cmd, "pre-order") == 0) {
            preOrder(arvore->raiz);
        } else if (strcmp(cmd, "in-order") == 0) {
            inOrder(arvore->raiz);
        } else { /* post-order */
            postOrder(arvore->raiz);
        }
    }
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

void inOrder(no *r)
{
    if (r == NULL) return;
    inOrder(r->esq);
    printf("%d\n", r->chave);
    inOrder(r->dir);
}

void postOrder(no *r)
{
    if (r == NULL) return;
    postOrder(r->esq);
    postOrder(r->dir);
    printf("%d\n", r->chave);
}

void inserir(arvoreb *t, no *novo)
{
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
            subs = removerAntecessor(antecessor(r));
            subs->pai = r->pai;
            subs->esq = r->esq;
            subs->dir = r->dir;

            r->esq->pai = subs;
            if (r->dir != NULL);
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
                filho->pai = NULL;
            }
        }
        printf("%d\n", r->chave);
        r->pai = NULL;
        r->esq = NULL;
        r->dir = NULL;
        free(r);
    }
}

no* antecessor(no *r)
{
    r = r->esq;
    while (r->dir != NULL)
        r = r->dir;
    return r;
}

no* removerAntecessor(no *r)
{
    no *pai = r->pai;
    if (pai->esq == r)
        pai->esq = r->esq;
    else
        pai->dir = r->esq;
    
    if (r->esq != NULL) {
        r->esq->pai = pai;
        r->esq = NULL;
    }

    r->pai = NULL;

    return r;
}
