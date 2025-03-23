/* Solução para o problema 116. Ainda considerado errado pelo juiz BOCA. */
#include <stdio.h>
#include <stdlib.h>

typedef struct tPilha
{
    char *itens;
    long tamanho, topo;
} tPilha;

tPilha* criar(long);
int vazia(tPilha*);
int cheia(tPilha*);
char topo(tPilha*);
void exibirTopoBase(tPilha*);
void exibirBaseTopo(tPilha*);
void empilhar(tPilha*, char);
void desempilhar(tPilha*);

int main(void)
{
    long n;
    scanf("%ld", &n);
    tPilha *pilha = criar(n);

    char cmd, valor;
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf(" %c", &valor);
                empilhar(pilha, valor);
                break;
            case 'D':
                desempilhar(pilha);
                break;
            case 'T':
                if (!vazia(pilha))
                    printf("%c\n", topo(pilha));
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
    pilha->itens = (char*)malloc(n*sizeof(char));
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

char topo(tPilha *pilha)
{
    return pilha->itens[pilha->topo];
}

void exibirTopoBase(tPilha *pilha)
{
    long i;
    for (i = pilha->topo; i >= 0; i--)
        printf("%c%s", pilha->itens[i], i != 0 ? " " : "\n");
}

void exibirBaseTopo(tPilha *pilha)
{
    long i;
    for (i = 0; i <= pilha->topo; i++)
        printf("%c%s", pilha->itens[i], i != pilha->topo ? " " : "\n");
}

void empilhar(tPilha *pilha, char novo)
{
    if (!cheia(pilha))
        pilha->itens[++pilha->topo] = novo;
}

void desempilhar(tPilha *pilha)
{
    if (!vazia(pilha))
        pilha->topo--;
}
