/* Solução para o problema 147. */
#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int chave;
    struct item *anterior;
} item;

typedef struct pilhad
{
    item *topo;
} pilhad;

item* criarItem(int);
pilhad* criar(void);
void empilhar(pilhad*, item*);
void mostrar(pilhad*);
int desempilhar(pilhad*);
int testarPrimo(long);
void limpar(pilhad*);

int main(void)
{
    int numeros, rodadas, valor;
    scanf("%d %d", &numeros, &rodadas);

    pilhad **A = (pilhad**)malloc((rodadas+1)*sizeof(pilhad*));
    A[0] = criar();
    for (int i = 0; i < numeros; i++) {
        scanf("%d", &valor);
        empilhar(A[0], criarItem(valor));
    }

    pilhad *B = criar();
    item *it;
    long primo = 2;
    for (int j = 1; j <= rodadas; j++) {
        while (!testarPrimo(primo)) primo++;
        A[j] = criar();
        it = A[j-1]->topo;
        while (it != NULL) {
            it = it->anterior;
            valor = desempilhar(A[j-1]);
            if (valor % primo == 0)
                empilhar(B, criarItem(valor));
            else
                empilhar(A[j], criarItem(valor));
        }
        mostrar(B);
        limpar(B);
        primo++;
    }
    mostrar(A[rodadas]);

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
    pilhad* p = (pilhad*)malloc(sizeof(pilhad));
    if (p != NULL)
        p->topo = NULL;
    return p;
}

void empilhar(pilhad *p, item *novo)
{
    novo->anterior = p->topo;
    p->topo = novo;
}

void mostrar(pilhad *p)
{
    item *it = p->topo;
    while (it != NULL) {
        printf("%d\n", it->chave);
        it = it->anterior;
    }
}

int desempilhar(pilhad *p)
{
    if (p->topo != NULL) {
        int aux = p->topo->chave;
        p->topo = p->topo->anterior;
        return aux;
    }
}

int testarPrimo(long num)
{
    if (num <= 1) return 0;
    for (int d = 2; d < num; d++) {
        if (num % d == 0)
            return 0;
    }
    return 1;
}

void limpar(pilhad *p)
{
    item *aux = NULL;
    item *it = p->topo;
    while (it != NULL) {
        aux = it;
        it = it->anterior;
        aux->anterior = NULL;
        free(aux);
    }
    p->topo = NULL;
}
