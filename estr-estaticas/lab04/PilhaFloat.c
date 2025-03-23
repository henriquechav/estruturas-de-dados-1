/* Solução para o problema 115. */
#include <stdio.h>
#include <stdlib.h>

typedef struct tPilha
{
    float *itens;
    long tamanho, topo;
} tPilha;

tPilha* criar(long);
int vazia(tPilha*);
int cheia(tPilha*);
float topo(tPilha*);
void exibirTopoBase(tPilha*);
void exibirBaseTopo(tPilha*);
void empilhar(tPilha*, float);
void desempilhar(tPilha*);

int main(void)
{
    long n;
    scanf("%ld", &n);
    tPilha *pilha = criar(n);

    float valor;
    char cmd;
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf("%f", &valor);
                empilhar(pilha, valor);
                break;
            case 'D':
                desempilhar(pilha);
                break;
            case 'T':
                if (!vazia(pilha))
                    printf("%g\n", topo(pilha));
                break;
            case 'X':
                exibirTopoBase(pilha);
                break;
            case 'B':
                exibirBaseTopo(pilha);
                break;
        }
    }

    return 0;
}

tPilha* criar(long n)
{
    tPilha *pilha = (tPilha*)malloc(sizeof(tPilha));
    pilha->itens = (float*)malloc(n*sizeof(float));
    pilha->tamanho = n;
    pilha->topo = -1;
    return pilha;
}

int vazia(tPilha *pilha)
{
    return pilha->topo == -1;
}

int cheia(tPilha *pilha)
{   
    return pilha->topo == pilha->tamanho - 1;
}

float topo(tPilha *pilha)
{
    return pilha->itens[pilha->topo];
}

void exibirTopoBase(tPilha *pilha)
{
    long i;
    for (i = pilha->topo; i >= 0; i--)
        printf("%g%s", pilha->itens[i], i != 0 ? " " : "\n");
}

void exibirBaseTopo(tPilha *pilha)
{
    long i;
    for (i = 0; i <= pilha->topo; i++)
        printf("%g%s", pilha->itens[i], i != pilha->topo ? " " : "\n");
}

void empilhar(tPilha *pilha, float novo)
{
    if (!cheia(pilha))
        pilha->itens[++pilha->topo] = novo;
}

void desempilhar(tPilha *pilha)
{
    if (!vazia(pilha))
        pilha->topo--;
}
