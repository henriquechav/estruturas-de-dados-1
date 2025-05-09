/* Solução para o problema 125. */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *itens;
    int tamanho;
    int inicio;
    int final;
} tFila;

tFila* criar(int);
int vazia(tFila*);
int cheia(tFila*);
void enfileirar(tFila*, int);
void desenfileirar(tFila*);

int main(void)
{
    int n;
    scanf("%d", &n);
    tFila *fila = criar(n);

    int valor;
    char cmd;
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf("%d", &valor);
                enfileirar(fila, valor);
                break;
            case 'D':
                desenfileirar(fila);
                break;
        }
    }

    return 0;
}

tFila* criar(int n)
{
    tFila *fila = (tFila*)malloc(sizeof(tFila));
    fila->itens = (int*)malloc(n*sizeof(int));
    fila->tamanho = n;
    fila->inicio = -1;
    fila->final = -1;
    return fila;
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

void enfileirar(tFila *fila, int novo)
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
        printf("%d\n", fila->itens[fila->inicio]);
        if (fila->inicio == fila->final) {
            fila->inicio = -1;
            fila->final = -1;
        } else {
            fila->inicio++;
        }
    }
}
