/* Solução para o problema 117. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tItem
{
    char nome[90];
} tItem;

typedef struct tPilha
{
    tItem *itens;
    long tamanho;
    long topo;
} tPilha;

tPilha* criarPilha(long);
tItem criarItem(char[]);
int vazia(tPilha*);
int cheia(tPilha*);
char* topo(tPilha*);
void exibirTopoBase(tPilha*);
void exibirBaseTopo(tPilha*);
void empilhar(tPilha*, tItem);
void desempilhar(tPilha*);

int main(void)
{
    long n;
    scanf("%ld", &n);
    tPilha *pilha = criarPilha(n);

    char cmd, valor[90];
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf(" %s", valor);
                empilhar(pilha, criarItem(valor));
                break;
            case 'D':
                desempilhar(pilha);
                break;
            case 'T':
                if (!vazia(pilha))
                    printf("%s\n", topo(pilha));
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

tPilha* criarPilha(long n)
{
    tPilha *pilha = (tPilha*)malloc(sizeof(tPilha));
    pilha->itens = (tItem*)malloc(n*sizeof(tItem));
    pilha->tamanho = n;
    pilha->topo = -1;
    return pilha;
}

tItem criarItem(char nome[])
{
    tItem item;
    strcpy(item.nome, nome);
    return item;
}

int vazia(tPilha *pilha)
{
    return pilha->topo == -1;
}

int cheia(tPilha *pilha)
{
    return pilha->topo == pilha->tamanho - 1;
}

char* topo(tPilha *pilha)
{
    return pilha->itens[pilha->topo].nome;
}

void exibirTopoBase(tPilha *pilha)
{
    long i;
    for (i = pilha->topo; i >= 0; i--)
        printf("%s%s", pilha->itens[i].nome, i != 0 ? " " : "\n");
}

void exibirBaseTopo(tPilha *pilha)
{
    long i;
    for (i = 0; i <= pilha->topo; i++)
        printf("%s%s", pilha->itens[i].nome, i != pilha->topo ? " " : "\n");
}

void empilhar(tPilha *pilha, tItem novo)
{
    if (!cheia(pilha))
        pilha->itens[++pilha->topo] = novo;
}

void desempilhar(tPilha *pilha)
{
    if (!vazia(pilha))
        pilha->topo--;
}
