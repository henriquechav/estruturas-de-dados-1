/* Solução para o problema 127. */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *itens;
    int tamanho;
    int inicio;
    int final;
} tFila;

tFila* criar(int);
int cheia(tFila*);
int vazia(tFila*);
void enfileirar(tFila*, char);
void desenfileirar(tFila*);

int main(void)
{
    int n;
    scanf("%d", &n);
    tFila *fila = criar(n);

    char cmd, valor;
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf(" %c", &valor);
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
    fila->itens = (char*)malloc(n*sizeof(char));
    fila->tamanho = n;
    fila->inicio = -1;
    fila->final = -1;
    return fila;
}

int cheia(tFila *fila)
{
    return fila->final == fila->tamanho - 1;
}

int vazia(tFila *fila)
{
    return (fila->inicio == -1 && fila->final == -1)
            || fila->inicio > fila->final;
}

void enfileirar(tFila *fila, char novo)
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
        printf("%c\n", fila->itens[fila->inicio]);
        if (fila->inicio == fila->final) {
            fila->inicio = -1;
            fila->final = -1;
        } else {
            fila->inicio++;
        }
    }
}
