/* Solução para o problema 132. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nome[101];
} tItem;

typedef struct 
{
    tItem *itens;
    int tamanho;
    int inicio;
    int final;
} tFila;

tItem criarItem(char*);
tFila* criarFila(int);
int vazia(tFila*);
int cheia(tFila*);
void enfileirar(tFila*, tItem);
void desenfileirar(tFila*);

int main(void)
{
    int n;
    scanf("%d", &n);
    tFila *fila = criarFila(n);

    char cmd, valor[101];
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf(" %s\n", valor);
                enfileirar(fila, criarItem(valor));
                break;
            case 'D':
                desenfileirar(fila);
                break;
        }
    }

    return 0;
}

tItem criarItem(char *valor)
{
    tItem it;
    strcpy(it.nome, valor);
    return it;
}

tFila* criarFila(int n)
{
    tFila *fila = (tFila*)malloc(sizeof(tFila));
    fila->itens = (tItem*)malloc(n*sizeof(tItem));
    fila->tamanho = n;
    fila->inicio = 0;
    fila->final = 0;
    return fila;
}

int vazia(tFila *f)
{
    return f->inicio == f->final;
}

int cheia(tFila *f)
{
    return (f->final + 1) % f->tamanho == f->inicio;
}

void enfileirar(tFila *f, tItem novo)
{
    if (!cheia(f)) {
        f->itens[f->final] = novo;
        f->final = (f->final + 1) % f->tamanho;
    }
}

void desenfileirar(tFila *f)
{
    if (!vazia(f)) {
        printf("%s\n", f->itens[f->inicio].nome);
        f->inicio = (f->inicio + 1) % f->tamanho;
    }
}
