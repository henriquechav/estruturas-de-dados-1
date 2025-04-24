/* Solução para o problema 9. */
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
int vazia(arvoreb*);
void preOrder(no*);
void inOrder(no*);
void inOrderAux(no*, int*);
void postOrder(no*);
void inserir(arvoreb*, no*);
void remover(arvoreb*, int);
no* sucessor(no*);
no* removerSucessor(no*);

int main(void)
{
    char cmd[25]; int valor;
    arvoreb *arvore = criar();
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

int vazia(arvoreb *t)
{
    return t->raiz == NULL;
}

void preOrder(no *r)
{
    if (r != NULL) {
        printf("%s%d", r->pai != NULL ? " " : "", r->chave);
        preOrder(r->esq);
        preOrder(r->dir);
        if (r->pai == NULL)
            printf("\n");
    }
}

void inOrder(no *r)
{
    if (r != NULL) {
        int primeiro = 1;
        inOrderAux(r, &primeiro);
        printf("\n");
    }
}

void inOrderAux(no *r, int *primeiro)
{
    if (r != NULL) {
        inOrderAux(r->esq, primeiro);
        if (*primeiro) {
            printf("%d", r->chave);
            *primeiro = 0;
        } else {
            printf(" %d", r->chave);
        }
        inOrderAux(r->dir, primeiro);
    }
}

void postOrder(no *r)
{
    if (r != NULL) {
        postOrder(r->esq);
        postOrder(r->dir);
        printf("%d%s", r->chave, r->pai != NULL ? " " : "\n");
    }
}

void inserir(arvoreb *t, no *novo)
{
    no *r = t->raiz, *pai = NULL;
    while (r != NULL) {
        pai = r;
        if (r->chave <= novo->chave)
            r = r->dir;
        else
            r = r->esq;
    }

    if (pai == NULL) { /* raiz */
        t->raiz = novo;
    } else { /* não raiz */
        if (pai->chave <= novo->chave) {
            pai->dir = novo;
        } else {
            pai->esq = novo;
        }
        novo->pai = pai;
    }
}

void remover(arvoreb *t, int chave)
{
    no *pai = NULL, *r = t->raiz, *subs;
    while (r != NULL && r->chave != chave) {
        pai = r;
        if (r->chave < chave)
            r = r->dir;
        else 
            r = r->esq;
    }

    if (r != NULL) {
        if (r->esq == NULL && r->dir == NULL) { /* folha */
            if (pai != NULL) {
                if (r->pai->esq == r)
                    r->pai->esq = NULL;
                else
                    r->pai->dir = NULL;
            } else {
                t->raiz = NULL;
            }
        } else if (r->esq != NULL & r->dir != NULL) { /* pai de dois */
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
        } else { /* pai de um */
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
