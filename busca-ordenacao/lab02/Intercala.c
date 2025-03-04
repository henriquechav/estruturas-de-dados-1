/* Solução para o problema 100. */
#include <stdio.h>
#include <stdlib.h>

void ScanVector(long unsigned[], long unsigned);
void PrintVector(long unsigned[], long unsigned);
void Intercala(long unsigned[], long unsigned[], long unsigned[], 
                long unsigned, long unsigned, long unsigned);

int main(void)
{
    long unsigned q1, q2;
    scanf("%ld", &q1);
    scanf("%ld", &q2);

    long unsigned *v1, *v2;
    v1 = malloc(q1*sizeof(long unsigned));
    v2 = malloc(q2*sizeof(long unsigned));
    ScanVector(v1, q1);
    ScanVector(v2, q2);

    long unsigned *vr;
    vr = malloc((q1+q2)*sizeof(long unsigned));
    Intercala(vr, v1, v2, q1 + q2, q1, q2);
    PrintVector(vr, q1 + q2);

    free(v1);
    free(v2);

    return 0;
}

/* Recebe três vetores e seus respectivos tamanhos. Dois vetores v1[0..q1-1] e
 * v2[0..q2-1] que terão seus elementos intercalados de forma ordenada no 
 * vetor resultado vr[0..qq-1]. */
void Intercala(long unsigned vr[], long unsigned v1[], long unsigned v2[],
                long unsigned qq, long unsigned q1, long unsigned q2)
{
    int i, a = 0, b = 0;
    for (i = 0; i < qq; i++) {
        if (a >= q1) {
            vr[i] = v2[b]; b++;
            continue;
        }
        if (b >= q2) {
            vr[i] = v1[a]; a++;
            continue;
        }
        if (v1[a] < v2[b]) {
            vr[i] = v1[a]; a++;
        } else {
            vr[i] = v2[b]; b++;
        }
    }   
}

void ScanVector(long unsigned v[], long unsigned q)
{
    int i;
    for (i = 0; i < q; i++)
        scanf("%ld", &v[i]);
}

void PrintVector(long unsigned v[], long unsigned q)
{
    int i;
    for (i = 0; i < q; i++)
        printf("%ld\n", v[i]);
}
