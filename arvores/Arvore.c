/* Implementação de Árvore Binária de Busca em C. */
#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *pai;
    struct no *direita;
    struct no *esquerda;
} no;

typedef struct arvoreb
{
    no *raiz;
} arvoreb;

no* criarNo(int);
arvoreb* criar(void);
no* raiz(arvoreb*);
int vazia(arvoreb*);
void preOrder(no*);
void inOrder(no*);
void postOrder(no*);
no* buscar(arvoreb*, int);
void inserir(arvoreb*, no*);
no* remover(arvoreb*, int);
no* sucessor(no*);
no* removerSucessor(no*);

int main(void)
{
    int opc, chave;
    no *it;
    arvoreb *arvore = criar();

    do {
        do {
            printf("Escolha uma das opções a seguir:\n");
            printf("1 - Inserir na Árvore\n");
            printf("2 - Mostrar Árvore (Pre-Order)\n");
            printf("3 - Mostrar Árvore (In-Order)\n");
            printf("4 - Mostrar Árvore (Post-Order)\n");
            printf("5 - Raiz da Árvore\n");
            printf("6 - Buscar na Árvore\n");
            printf("7 - Remover da Árvore\n");
            printf("8 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        } while (opc < 1 || opc > 8);

        if (opc == 1 || opc == 6 || opc == 7) {
            printf("Informe o valor da chave: ");
            scanf("%d", &chave);
        }

        switch (opc) {
            case 1:
                inserir(arvore, criarNo(chave));
                break;
            case 2:
                preOrder(raiz(arvore));
                break;
            case 3:
                inOrder(raiz(arvore));
                break;
            case 4:
                postOrder(raiz(arvore));
                break;
            case 5:
                if (!vazia(arvore))
                    printf("Chave %d na raiz.\n", raiz(arvore)->chave);
                break;
            case 6:
                printf("Item %d%slocalizado.\n", chave, buscar(arvore, chave) != NULL ? " " : " não ");
                break;
            case 7:
                it = remover(arvore, chave);
                if (it != NULL) {
                    printf("Item %d removido.\n", it->chave);
                    free(it);
                }
                break;
        }
    } while (opc != 8);

    printf("Saindo.\n");
    return 0;
}

no* criarNo(int chave)
{
    no *it = (no*)malloc(sizeof(no));
    if (it != NULL) {
        it->chave = chave;
        it->pai = NULL;
        it->esquerda = NULL;
        it->direita = NULL;
    }
    return it;
}

arvoreb* criar(void)
{
    arvoreb *a = (arvoreb*)malloc(sizeof(arvoreb));
    if (a != NULL)
        a->raiz = NULL;
    return a;
}

no* raiz(arvoreb *a)
{
    return a->raiz;
}

int vazia(arvoreb *a)
{
    return a->raiz == NULL;
}

void preOrder(no *it)
{
    if (it != NULL) {
        printf("%d\n", it->chave);
        preOrder(it->esquerda);
        preOrder(it->direita);
    }
}

void inOrder(no *it)
{
    if (it != NULL) {
        inOrder(it->esquerda);
        printf("%d\n", it->chave);
        inOrder(it->direita);
    }
}

void postOrder(no *it)
{
    if (it != NULL) {
        postOrder(it->esquerda);
        postOrder(it->direita);
        printf("%d\n", it->chave);
    }
}

no* buscar(arvoreb *a, int chave)
{
    no *it = a->raiz;
    while (it != NULL && it->chave != chave) {
        if (it->chave < chave) {
            it = it->direita;
        } else {
            it = it->esquerda;
        }
    }
    return it;
}

void inserir(arvoreb *a, no *novo)
{
    no *aux = NULL;
    no *it = a->raiz;

    while (it != NULL) {
        aux = it;
        if (it->chave < novo->chave)
            it = it->direita;
        else 
            it = it->esquerda;
    }

    if (aux != NULL) { /* incluindo não raiz */
        novo->pai = aux;
        if (aux->chave < novo->chave)
            aux->direita = novo;
        else
            aux->esquerda = novo;
    } else { /* incluindo raiz */
        a->raiz = novo;
    }
}

no* remover(arvoreb *a, int chave)
{
    no *pai = NULL, *filho = a->raiz, *subs;

    while (filho != NULL && filho->chave != chave) {
        pai = filho;
        if (filho->chave < chave)
            filho = filho->direita;
        else
            filho = filho->esquerda;
    }

    if (filho != NULL) { /* nó encontrado */
        if (filho->esquerda == NULL && filho->direita == NULL) { /* folha */
            if (pai != NULL) {
                if (pai->esquerda == filho)
                    pai->esquerda = NULL;
                else
                    pai->direita = NULL;
            } else {
                a->raiz = NULL;
            }
        } else if (filho->esquerda != NULL && filho->direita != NULL) { /* pai de dois */
            subs = removerSucessor(sucessor(filho));
            subs->pai = pai;
            subs->esquerda = filho->esquerda;
            subs->direita = filho->direita;

            if (pai != NULL) {
                if (pai->esquerda == filho)
                    pai->esquerda = subs;
                else 
                    pai->direita = subs;
            } else {
                a->raiz = subs;
            }

            if (filho->esquerda != NULL)
                filho->esquerda->pai = subs;
            if (filho->direita != NULL)
                filho->direita->pai = subs;
        } else { /* pai de um */
            if (pai != NULL) {
                if (pai->esquerda == filho) {
                    if (filho->esquerda != NULL) {
                        pai->esquerda = filho->esquerda;
                        filho->esquerda->pai = pai;
                    } else {
                        pai->esquerda = filho->direita;
                        filho->direita->pai = pai;
                    }
                } else {
                    if (filho->esquerda != NULL) {
                        pai->direita = filho->esquerda;
                        filho->esquerda->pai = pai;
                    } else {
                        pai->direita = filho->direita;
                        filho->direita->pai = pai;
                    }
                }
            } else { /* raiz */
                if (filho->esquerda != NULL) {
                    a->raiz = filho->esquerda;
                    filho->esquerda->pai = NULL;
                } else {
                    a->raiz = filho->direita;
                    filho->direita->pai = NULL;
                }
            }   
        }
        filho->pai = NULL;
        filho->esquerda = NULL;
        filho->direita = NULL;
    }
    return filho;
}

no* sucessor(no *r)
{
    no *pai = NULL;
    r = r->direita;
    while (r != NULL) {
        pai = r;
        r = r->esquerda;
    }
    return pai;
}

no* removerSucessor(no *r)
{
    no *pai = r->pai;
    if (pai->esquerda == r)
        pai->esquerda = r->direita;
    else 
        pai->direita = r->direita;

    if (r->direita != NULL)
        r->direita->pai = pai;
    
    r->pai = NULL;
    r->direita = NULL;
    return r;
}
