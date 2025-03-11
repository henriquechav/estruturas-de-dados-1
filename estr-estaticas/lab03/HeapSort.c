/* Solução para o problema 109. */
#include <stdio.h>
#include <stdlib.h>

void mostrarVetor(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
}

int filhoEsq(int p) {
    return 2 * p + 1; }
int filhoDir(int p) {
    return 2 * p + 2; }
int ultimoPai(int n) {
    return (n / 2) - 1;
}

void peneirar(int h[], int n, int p)
{
    int aux, maior = p;

    if (filhoDir(p) < n && h[filhoDir(p)] > h[maior])
        maior = filhoDir(p);
    if (filhoEsq(p) < n && h[filhoEsq(p)] > h[maior])
        maior = filhoEsq(p);
    
    if (maior != p) {
        aux = h[maior];
        h[maior] = h[p];
        h[p] = aux;
        peneirar(h, n, maior);
    }
}

void construirHeap(int v[], int n)
{
    int i;
    for (i = ultimoPai(n); i >= 0; i--)
        peneirar(v, n, i);
}

void removerMax(int h[], int n)
{
    int aux = h[n-1];
    h[n-1] = h[0];
    h[0] = aux;
}

void heapSort(int h[], int n)
{
    construirHeap(h, n);
    int i;
    for (i = n; i > 0; i--) {
        mostrarVetor(h, i);
        removerMax(h, i);
        peneirar(h, i - 1, 0);
    }
}

int main(void)
{
    int n, *v;
    scanf("%d", &n);
    v = (int*)malloc(n*sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);

    mostrarVetor(v, n);
    heapSort(v, n);
    mostrarVetor(v, n);

    free(v);
    return 0;
}
