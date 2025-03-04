/* Solução para o problema 103. */
#include <stdio.h>
#include <stdlib.h>

void MergeSort(int*, int, int, int);
void Intercala(int*, int, int, int);
void PrintVector(int*, int);

int main(void)
{
    unsigned n;
    scanf("%u", &n);

    int i, *v = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", v + i);

    PrintVector(v, n);
    MergeSort(v, 0, n - 1, n);
    PrintVector(v, n);

    free(v);
    return 0;
}

void MergeSort(int *v, int e, int d, int n)
{
    int meio;
    if (e < d) {
        meio = (e + d) / 2;
        MergeSort(v, e, meio, n);
        MergeSort(v, meio + 1, d, n);
        PrintVector(v, n);
        Intercala(v, e, meio + 1, d);
    }
}

void Intercala(int *v, int e, int d, int fim_d)
{
    int *temp = (int*)malloc((fim_d+1)*sizeof(int));
    int inicio = e;
    int i, fim_e = d - 1;
    for (i = inicio; i <= fim_d; i++) {
        if (e > fim_e) {
            temp[i] = v[d]; d++;
            continue;
        }
        if (d > fim_d) {
            temp[i] = v[e]; e++;
            continue;
        }
        if (v[e] < v[d]) {
            temp[i] = v[e]; e++;
        } else {
            temp[i] = v[d]; d++;
        }
    }
    for (i = inicio; i <= fim_d; i++)
        v[i] = temp[i];
    free(temp);
}

/* Recebe um vetor v[0..n-1] e seu tamanho e o exibe no terminal. */
void PrintVector(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
}
