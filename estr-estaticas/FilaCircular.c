/* Implementação de uma Fila Estática Circular em C. */
#include <stdio.h>
#include <stdlib.h>

struct tFila
{
    int *itens;
    int tamanho;
    int inicio;
    int final;
};

struct tFila criarFila(int n)
{
    struct tFila f;
    f.itens = (int*)malloc(n*sizeof(int));
    f.tamanho = n;
    f.inicio = f.final = 0;
    return f;
}

int primeiro(struct tFila f)
{
    return f.itens[f.inicio];
}

int ultimo(struct tFila f)
{
    int iUltimo = f.final - 1;
    if (iUltimo == -1)
        iUltimo = f.tamanho - 1;
    return f.itens[iUltimo];
}

int filaCheia(struct tFila f)
{
    return (f.final + 1) % f.tamanho == f.inicio;
}

int filaVazia(struct tFila f)
{
    return f.inicio == f.final;
}

void desenfileirar(struct tFila *f)
{
    if (!filaVazia(*f))
        f->inicio = (f->inicio + 1) % f->tamanho;
}

void enfileirar(struct tFila *f, int novo)
{
    if (!filaCheia(*f)) {
        f->itens[f->final] = novo;
        f->final = (f->final + 1) % f->tamanho;
    }
}

void mostrarFila(struct tFila f)
{
    for (int i = f.inicio; i != f.final; i = (i + 1) % f.tamanho)
        printf("%d%s", f.itens[i], f.itens[i] != ultimo(f) ? " " : "\n");
}
