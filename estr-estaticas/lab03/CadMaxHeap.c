/* Solução para o problema 107. */
#include <stdio.h>
#include <stdlib.h>

struct tHeap
{
    long unsigned *itens;
    int tam, qnt;
};

struct tHeap criarHeap(int n)
{
    struct tHeap h;
    h.itens = (long unsigned*)malloc(n*sizeof(long unsigned));
    h.tam = n;
    h.qnt = 0;
    return h;
}

/* Funções auxiliares. */
int filhoEsq(int p) {
    return 2 * p + 1;
}
int filhoDir(int p) {
    return 2 * p + 2;
}
int pai(int f) {
    return (f - 1) / 2;
}
int ultimoPai(int n) {
    return (n / 2) - 1;
}

void peneirar(struct tHeap *h, int p)
{
    long unsigned aux;
    int maior = p;

    if (filhoDir(p) < h->qnt && h->itens[filhoDir(p)] > h->itens[maior])
        maior = filhoDir(p);
    if (filhoEsq(p) < h->qnt && h->itens[filhoEsq(p)] > h->itens[maior])
        maior = filhoEsq(p);

    if (maior != p) {
        aux = h->itens[maior];
        h->itens[maior] = h->itens[p];
        h->itens[p] = aux;
        peneirar(h, maior);
    }
}

void construirHeap(struct tHeap *h)
{
    int i;
    for (i = ultimoPai(h->qnt); i >= 0; i--)
        peneirar(h, i);
}

void removerMax(struct tHeap *h)
{
    long unsigned rem;
    if (h->qnt > 0) {
        rem = h->itens[0];
        h->itens[0] = h->itens[h->qnt-1];
        h->itens[h->qnt-1] = rem;
        h->qnt -= 1;
        peneirar(h, 0);
        printf("%lu\n", rem);
    }
}

void inserirHeap(struct tHeap *h, int chave)
{
    int iNovo = h->qnt;
    if (h->qnt < h->tam) {
        h->itens[iNovo] = chave;
        h->qnt += 1;
        if (chave > h->itens[pai(iNovo)])
            construirHeap(h);
    }
}

void mostrarHeap(struct tHeap *h)
{
    int i;
    for (i = 0; i < h->qnt; i++)
        printf("%lu%s", h->itens[i], i < h->qnt - 1 ? " " : "\n");
}

int main(void)
{
    int tam;
    scanf("%d", &tam);
    struct tHeap heap;
    heap = criarHeap(tam);

    long unsigned chave;
    char cmd;
    while ( scanf("\n%c", &cmd) != EOF ) {
        switch (cmd) {
            case 'I':
                scanf("%lu", &chave);
                inserirHeap(&heap, chave);
                break;
        
            case 'M':
                mostrarHeap(&heap);
                break;

            case 'R':
                removerMax(&heap);
                break;
        }
    }

    return 0;
}
