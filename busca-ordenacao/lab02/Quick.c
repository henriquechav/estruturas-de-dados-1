/* Solução para o problema 104. */
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int*, int, int, int);
int Particiona(int*, int, int, int);
void PrintVect(int*, int);

int main(void)
{
    int n, i, *v;
    scanf("%d", &n);
    v = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", v + i);

    PrintVect(v, n);
    QuickSort(v, 0, n - 1, n);
    PrintVect(v, n);

    free(v);
    return 0;
}

void QuickSort(int *v, int e, int d, int n)
{
    int p;
    if (e < d) {
        p = Particiona(v, e, d, n);
        QuickSort(v, e, p - 1, n);
        QuickSort(v, p + 1, d, n);
    }
}

int Particiona(int *v, int e, int d, int n)
{
    int i, pm = e - 1, aux;
    for (i = e; i < d; i++) {
        if (v[i] <= v[d]) {
            pm++; aux = v[i]; v[i] = v[pm]; v[pm] = aux;
        }
        PrintVect(v, n);
    }
    pm++; aux = v[i]; v[i] = v[pm]; v[pm] = aux;   
    PrintVect(v, n);
    return pm;
}

void PrintVect(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
}
