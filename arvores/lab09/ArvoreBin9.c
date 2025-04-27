/* Solução para o problema 16. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char chave;
    struct no *pai;
    struct no *esq;
    struct no *dir;
} no;

typedef struct arvoreb
{
    no *raiz;
} arvoreb;

no* criarNo(char);
arvoreb* criar(void);
void preOrder(no*);
void inOrder(no*);
void postOrder(no*);
void inserir(arvoreb*, no*);
void remover(arvoreb*, char);
no* sucessor(no*);
no* removerSucessor(no*);

int main(void)
{
    char cmd[25]; char valor;
    arvoreb *arvore = criar();
    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "insert") == 0) {
            scanf(" %c", &valor);
            inserir(arvore, criarNo(valor));
        } else if (strcmp(cmd, "delete") == 0) {
            scanf(" %c", &valor);
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

no* criarNo(char chave)
{
    no *it = (no*)malloc(sizeof(no));
    if (it != NULL) {
        it->chave = chave;
        it->pai = NULL;
        it->esq = NULL;
        it->dir = NULL;
    }
    return it;
}

arvoreb* criar(void)
{
    arvoreb *tr = (arvoreb*)malloc(sizeof(arvoreb));
    if (tr != NULL)
        tr->raiz = NULL;
    return tr;
}

void preOrder(no *it)
{
    if (it != NULL) {
        printf("%c\n", it->chave);
        preOrder(it->esq);
        preOrder(it->dir);
    }
}

void inOrder(no *it)
{
    if (it != NULL) {
        inOrder(it->esq);
        printf("%c\n", it->chave);
        inOrder(it->dir);
    }
}

void postOrder(no *it)
{
    if (it != NULL) {
        postOrder(it->esq);
        postOrder(it->dir);
        printf("%c\n", it->chave);
    }
}

void inserir(arvoreb *tr, no *novo)
{
    no *aux = NULL, *it = tr->raiz;
    while (it != NULL) {
        aux = it;
        if (it->chave <= novo->chave)
            it = it->dir;
        else
            it = it->esq;
    }

    if (aux != NULL) {
        novo->pai = aux;
        if (aux->chave <= novo->chave)
            aux->dir = novo;
        else
            aux->esq = novo;
    } else {
        tr->raiz = novo;
    }
}

void remover(arvoreb *tr, char chave)
{
    no *aux = NULL, *it = tr->raiz, *subs;
    while (it != NULL && it->chave != chave) {
        aux = it;
        if (it->chave < chave)
            it = it->dir;
        else
            it = it->esq;
    }

    if (it != NULL) {
        if (it->dir == NULL && it->esq == NULL) { /* folha */
            if (aux != NULL) {
                if (aux->esq == it)
                    aux->esq = NULL;
                else
                    aux->dir = NULL;
            } else {
                tr->raiz = NULL;
            }
        } else if (it->dir != NULL && it->esq != NULL) { /* pai de dois */
            subs = removerSucessor(sucessor(it));
            subs->pai = aux;
            subs->esq = it->esq;
            subs->dir = it->dir;

            if (aux != NULL) {
                if (aux->esq == it)
                    aux->esq = subs;
                else
                    aux->dir = subs;
            } else {
                tr->raiz = subs;
            }

            if (it->esq != NULL)
                it->esq->pai = subs;
            if (it->dir != NULL)
                it->dir->pai = subs;
        } else { /* pai de um */
            if (aux != NULL) {
                if (aux->esq == it) {
                    if (it->esq != NULL) {
                        aux->esq = it->esq;
                        it->esq->pai = aux;
                    } else {
                        aux->esq = it->dir;
                        it->dir->pai = aux;
                    }
                } else {
                    if (it->esq != NULL) {
                        aux->dir = it->esq;
                        it->esq->pai = aux;
                    } else {
                        aux->dir = it->dir;
                        it->dir->pai = aux;
                    }
                }
            } else {
                if (it->esq != NULL) {
                    tr->raiz = it->esq;
                    it->esq->pai = NULL;
                } else {
                    tr->raiz = it->dir;
                    it->dir->pai = NULL;
                } 
            }
        }
        it->pai = NULL;
        it->esq = NULL;
        it->dir = NULL;
        printf("%c\n", it->chave);
        free(it);
    }
}

no* sucessor(no *it)
{
    it = it->dir;
    while (it->esq != NULL)
        it = it->esq;
    return it;
}

no* removerSucessor(no *it)
{
    no *pai = it->pai;
    if (pai->esq == it)
        pai->esq = it->dir;
    else
        pai->dir = it->dir;

    if (it->dir != NULL) {
        it->dir->pai = pai;
        it->dir = NULL;
    }

    it->pai = NULL;

    return it;
}
