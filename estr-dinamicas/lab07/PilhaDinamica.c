/* Solução para o problema 143. */
#include <stdio.h>
#include <stdlib.h>

struct item
{
    int chave;
    struct item *anterior;
};
typedef struct item item;

struct pilhad
{
    item *topo;
};
typedef struct pilhad pilhad;

item* criarItem(int);
pilhad* criar(void);
int vazia(pilhad*);
void empilhar(pilhad*, item*);
void desempilhar(pilhad*);
void mostrar(pilhad*);

int main(void)
{
    pilhad *pilha = criar();
    int valor;
    char cmd;

    while (scanf(" %c", &cmd) != EOF) {
        switch (cmd) {
            case 'E':
                scanf("%d", &valor);
                empilhar(pilha, criarItem(valor));
                break;
            case 'D':
                desempilhar(pilha);
                break;
            case 'M':
                mostrar(pilha);
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

pilhad* criar(void)
{
    pilhad *pilha = (pilhad*)malloc(sizeof(pilha));
    if (pilha != NULL)
        pilha->topo = NULL;
    return pilha;
}

int vazia(pilhad *p)
{
    return p->topo == NULL;
}

void empilhar(pilhad *p, item *novo)
{
    novo->anterior = p->topo;
    p->topo = novo;
}

void desempilhar(pilhad *p)
{
    if (!vazia(p)) {
        item *aux = p->topo;
        p->topo = p->topo->anterior;
        printf("[%d]\n", aux->chave);
        free(aux);
    }
}

void mostrar(pilhad *p)
{
    item *it = p->topo;
    while (it != NULL) {
        printf("%d%s", it->chave, it->anterior != NULL ? " " : "\n");
        it = it->anterior;
    }
}
