/* Solução para o problema 27. */
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
no* buscar(arvoreb*, int);
void inserir(arvoreb*, no*);
void imdMenor(arvoreb*, int);
void imdMaior(arvoreb*, int);
no* antecessor(no*);
no* sucessor(no*);

int main(void)
{
    arvoreb *arvore = criar();
    char cmd[25];
    int valor;

    while (scanf("%s", cmd) != EOF) {
        scanf("%d", &valor);
        if (strcmp(cmd, "insert") == 0) {
            inserir(arvore, criarNo(valor));
        } else if (strcmp(cmd, "immediately-less") == 0) {
            imdMenor(arvore, valor);
        } else { /* immediately-greater */
            imdMaior(arvore, valor);
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

// Função antecessor corrigida
no* antecessor(no *r) {
    if (r == NULL) return NULL;
    
    // Caso 1: possui subárvore esquerda
    if (r->esq != NULL) {
        no *current = r->esq;
        while (current->dir != NULL)
            current = current->dir;
        return current;
    }
    
    // Caso 2: busca no ancestral
    no *p = r->pai;
    while (p != NULL && r == p->esq) {
        r = p;
        p = p->pai;
    }
    return p;
}

// Função sucessor corrigida
no* sucessor(no *r) {
    if (r == NULL) return NULL;
    
    // Caso 1: possui subárvore direita
    if (r->dir != NULL) {
        no *current = r->dir;
        while (current->esq != NULL)
            current = current->esq;
        return current;
    }
    
    // Caso 2: busca no ancestral
    no *p = r->pai;
    while (p != NULL && r == p->dir) {
        r = p;
        p = p->pai;
    }
    return p;
}

// Modificações nas funções imdMenor e imdMaior para verificar existência do nó
void imdMenor(arvoreb *t, int chave) {
    no *alvo = buscar(t, chave);
    if (alvo == NULL) {
        // Opcional: tratar caso o nó não exista (depende dos requisitos)
        printf("nao ha imediatamente menor que %d\n", chave);
        return;
    }
    no *r = antecessor(alvo);
    if (r != NULL)
        printf("%d\n", r->chave);
    else
        printf("nao ha imediatamente menor que %d\n", chave);
}

void imdMaior(arvoreb *t, int chave) {
    no *alvo = buscar(t, chave);
    if (alvo == NULL) {
        // Opcional: tratar caso o nó não exista
        printf("nao ha imediatamente maior que %d\n", chave);
        return;
    }
    no *r = sucessor(alvo);
    if (r != NULL)
        printf("%d\n", r->chave);
    else
        printf("nao ha imediatamente maior que %d\n", chave);
}

// void imdMenor(arvoreb *t, int chave)
// {
//     no *r = antecessor(buscar(t, chave));
//     if (r != NULL)
//         printf("%d\n", r->chave);
//     else
//         printf("nao ha imediatamente menor que %d\n", chave);
// }

// void imdMaior(arvoreb *t, int chave)
// {
//     no *r = sucessor(buscar(t, chave));
//     if (r != NULL)
//         printf("%d\n", r->chave);
//     else
//         printf("nao ha imediatamente maior que %d\n", chave);
// }

// no* antecessor(no *r)
// {
//     if (r != NULL) {
//         r = r->esq;
//         while (r != NULL && r->dir != NULL)
//             r = r->dir;
//     }
//     return r;
// }

// no* sucessor(no *r)
// {
//     if (r != NULL) {
//         r = r->dir;
//         while (r != NULL && r->esq != NULL)
//             r = r->esq;
//     }
//     return r;
// }
