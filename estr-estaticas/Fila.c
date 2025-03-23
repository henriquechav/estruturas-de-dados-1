/* Implementação de uma Fila Estática em C. */
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
    f.inicio = -1;
    f.final = -1;
    return f;
}

int filaVazia(struct tFila f)
{
    return f.inicio == -1 && f.final == -1 || f.inicio > f.final;
}

int filaCheia(struct tFila f)
{
    return f.final == f.tamanho - 1;
}

int primeiro(struct tFila f)
{
    return f.itens[f.inicio];
}

int ultimo(struct tFila f)
{
    return f.itens[f.final];
}

void mostrarFila(struct tFila f)
{
    int i;
    if (!filaVazia(f)) {
        for (i = f.inicio; i <= f.final; i++) {
            printf("%d%s", f.itens[i], i != f.final ? " " : "\n");
        }
    }
}

void enfileirar(struct tFila *f, int novo)
{
    if (!filaCheia(*f)) {
        if (f->inicio == -1)
            f->inicio++;
        f->final++;
        f->itens[f->final] = novo;
    }
}

void desenfileirar(struct tFila *f)
{
    if (!filaVazia(*f))
        f->inicio++;
}
