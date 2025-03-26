/* Solução para o problema 131. */
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
int vazia(tFila*);
int cheia(tFila*);
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

void enfileirar(tFila *f, char novo)
{
    if (!cheia(f)) {
        f->itens[f->final] = novo;
        f->final = (f->final + 1) % f->tamanho;
    }
}

void desenfileirar(tFila *f)
{
    if (!vazia(f)) {
        printf("%c\n", f->itens[f->inicio]);
        f->inicio = (f->inicio + 1) % f->tamanho;
    }
}
