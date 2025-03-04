/* Solução para o problema 102. */
#include <stdio.h>
#include <stdlib.h>

void Particiona(int[], long unsigned, long unsigned);
void Troca(int*, int*);

int main(void)
{
    long unsigned q, p;
    scanf("%ld", &q);
    scanf("%ld", &p);

    int i, *v;
    v = (int*)malloc(q*sizeof(int));
    for (i = 0; i < q; i++)
        scanf("%d", v + i);

    Particiona(v, p, q);

    for (i = 0; i < q; i++)
        printf("%d\n", v[i]);

    free(v);

    return 0;
}

/* Recebe um vetor v[0..q-1], um índice de pivô p e o tamanho q de v. Então
 * particiona v com relação a v[p], e substitui o resultado no próprio v. */
void Particiona(int v[], long unsigned p, long unsigned q)
{
    Troca(&v[p], &v[q-1]);

    long unsigned pm, i;
    for (i = 0, pm = -1; i < q; i++) {
        if (v[i] <= v[q-1]) {
            pm++; Troca(&v[pm], &v[i]);
        }
    }
}

/* Recebe dois ponteiros para inteiros e troca seus valores de posição. */
void Troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
