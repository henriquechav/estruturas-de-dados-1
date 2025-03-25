/* Solução para o problema 128. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[102];
} tItem;

typedef struct 
{
    tItem *itens;
    int tamanho;
    int inicio;
    int final;
} tFila;

tFila* criarFila(int);
tItem criarItem(char*);
int vazia(tFila*);
int cheia(tFila*);
void enfileirar(tFila*, tItem);
void desenfileirar(tFila*);

int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();
    tFila *fila = criarFila(n);

    char cmd, valor[102];
    while ( scanf("%c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf(" %s", valor);
                enfileirar(fila, criarItem(valor));
                break;
            case 'D':
                desenfileirar(fila);
                break;
        }
    }

    return 0;
}

tFila* criarFila(int n)
{
    tFila *fila = (tFila*)malloc(sizeof(tFila));
    fila->itens = (tItem*)malloc(n*sizeof(tItem));
    fila->tamanho = n;
    fila->inicio = -1;
    fila->final = -1;
    return fila;
}

tItem criarItem(char *nome)
{
    tItem it;
    strcpy(it.nome, nome);
    return it;
}

int vazia(tFila *fila)
{
    return (fila->inicio == -1 && fila->final == -1)
            || fila->inicio > fila->final;
}

int cheia(tFila *fila)
{
    return fila->final == fila->tamanho - 1;
}

void enfileirar(tFila *fila, tItem novo)
{
    if (!cheia(fila)) {
        if (fila->inicio == -1)
            fila->inicio++;
        fila->itens[++fila->final] = novo;
    }
}

void desenfileirar(tFila *fila)
{
    if (!vazia(fila)) {
        printf("%s\n", fila->itens[fila->inicio].nome);
        if (fila->inicio == fila->final) {
            fila->inicio = -1;
            fila->final = -1;
        } else {
            fila->inicio++;
        }
    }
}
