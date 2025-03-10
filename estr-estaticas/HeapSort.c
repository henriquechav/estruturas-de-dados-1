/* Implementação do algoritmo Heap Sort em C. */
#include <stdio.h>
#include <stdlib.h>

int FilhoEsq(int p)
{
    return 2 * p + 1;
}

int FilhoDir(int p)
{
    return 2 * p + 2;
}

int UltimoPai(int n)
{
    return (n / 2) - 1;
}

void Peneirar(int *h, int n, int p)
{
    int maior = p, aux;

    if (FilhoEsq(p) < n && h[FilhoEsq(p)] > h[maior])
        maior = FilhoEsq(p);
    if (FilhoDir(p) < n && h[FilhoDir(p)] > h[maior])
        maior = FilhoDir(p);
    
    if (maior != p) {
        aux = h[p];
        h[p] = h[maior];
        h[maior] = aux;
        Peneirar(h, n, maior);
    }
}

void ConstruirHeap(int *h, int n)
{
    int i;
    for (i = UltimoPai(n); i >= 0; i--)
        Peneirar(h, n, i);
}

void RemoverMax(int *h, int n)
{
    int aux = h[0];
    h[0] = h[n-1];
    h[n-1] = aux;
}

void HeapSort(int *h, int n)
{
    ConstruirHeap(h, n);
    int i;
    for (i = n; i > 0; i--) {
        RemoverMax(h, i);
        Peneirar(h, i - 1, 0);
    }
}
