/* Solução para o problema 114. */
#include <stdio.h>
#include <stdlib.h>

typedef struct tPilha
{
    int *itens;
    long topo, tam;
} tPilha;

tPilha* criar(long);
int topo(tPilha*);
int vazia(tPilha*);
int cheia(tPilha*);
void exibirTopoBase(tPilha*);
void exibirBaseTopo(tPilha*);
void empilhar(tPilha*, int);
void desempilhar(tPilha*);

int main(void)
{
    long n;
    scanf("%ld", &n);

    tPilha *pilha;
    pilha = criar(n);

    int valor;
    char cmd;
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf("%d", &valor);
                empilhar(pilha, valor);
                break;
            case 'D':
                desempilhar(pilha);
                break;
            case 'T':
                if (!vazia(pilha))
                    printf("%d\n", topo(pilha));
                break;
            case 'X':
                exibirTopoBase(pilha);
                break;
            case 'B':
                exibirBaseTopo(pilha);
        }
    }

    return 0;
}

tPilha* criar(long n)
{
    tPilha *pilha = (tPilha*)malloc(sizeof(tPilha));
    pilha->itens = (int*)malloc(n*sizeof(int));
    pilha->topo = -1;
    pilha->tam = n;
    return pilha;
}

int topo(tPilha *pilha)
{
    return pilha->itens[pilha->topo];
}

int vazia(tPilha *pilha)
{
    return pilha->topo == -1;
}

int cheia(tPilha *pilha)
{
    return pilha->topo == pilha->tam - 1;
}

void exibirTopoBase(tPilha *pilha)
{
    long i;
    for (i = pilha->topo; i >= 0; i--)
        printf("%d%s", pilha->itens[i], i != 0 ? " " : "\n");
}

void exibirBaseTopo(tPilha *pilha)
{
    long i;
    for (i = 0; i <= pilha->topo; i++)
        printf("%d%s", pilha->itens[i], i != pilha->topo ? " " : "\n");
}

void empilhar(tPilha *pilha, int novo)
{
    if (!cheia(pilha))
        pilha->itens[++pilha->topo] = novo;
}

void desempilhar(tPilha *pilha)
{
    if (!vazia(pilha))
        pilha->topo--;
}
