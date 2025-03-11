/* Solução para o problema 106. */
#include <stdio.h>
#include <stdlib.h>

void scanVetor(int[], int);
void printVetor(int[], int);
void construirHeap(int[], int);
void peneirar(int[], int, int);
/* Funções auxiliares. */
int filhoEsq(int);
int filhoDir(int);
int ultimoPai(int);

int main(void)
{
    int n, *v;
    scanf("%d", &n);

    while (n != 0) {
        v = (int*)malloc(n*sizeof(int));
        scanVetor(v, n);
        construirHeap(v, n);
        printVetor(v, n);
        free(v);
        scanf("%d", &n);
    }

    return 0;
}

void peneirar(int h[], int n, int p)
{
    int aux, menor = p;

    if (filhoDir(p) < n && h[filhoDir(p)] < h[menor])
        menor = filhoDir(p);
    if (filhoEsq(p) < n && h[filhoEsq(p)] < h[menor])
        menor = filhoEsq(p);

    if (menor != p) {
        aux = h[menor];
        h[menor] = h[p];
        h[p] = aux;
        peneirar(h, n, menor);
    }
}

void construirHeap(int v[], int n)
{
    int i;
    for (i = ultimoPai(n); i >= 0; i--)
        peneirar(v, n, i);
}

int filhoEsq(int p)
{
    return 2 * p + 1;
}

int filhoDir(int p)
{
    return 2 * p + 2;
}

int ultimoPai(int n)
{
    return (n / 2) - 1;
}

void scanVetor(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

void printVetor(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
}
