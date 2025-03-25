/* Solução para o problema 130. */
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float *itens;
    int tamanho;
    int inicio;
    int final;
} tFila;

tFila* criar(int);
int cheia(tFila*);
int vazia(tFila*);
void enfileirar(tFila*, float);
void desenfileirar(tFila*);

int main(void)
{
    int n;
    scanf("%d", &n);
    tFila *fila = criar(n);

    float valor;
    char cmd;
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'E':
                scanf("%f", &valor);
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
    fila->itens = (float*)malloc(n*sizeof(float));
    fila->tamanho = n;
    fila->inicio = 0;
    fila->final = 0;
    return fila;
}

int cheia(tFila *f)
{
    return (f->final + 1) % f->tamanho == f->inicio;
}

int vazia(tFila *f)
{
    return f->final == f->inicio;
}

void enfileirar(tFila *f, float novo)
{
    if (!cheia(f)) {
        f->itens[f->final] = novo;
        f->final = (f->final + 1) % f->tamanho;
    }
}

void desenfileirar(tFila *f)
{
    if (!vazia(f)) {
        printf("%.2f\n", f->itens[f->inicio]);
        f->inicio = (f->inicio + 1) % f->tamanho;
    }
}
