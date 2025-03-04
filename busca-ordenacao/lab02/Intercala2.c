/* Solução para o problema 101. */
#include <stdio.h>
#include <stdlib.h>

void ScanVector(long unsigned[], long unsigned);
void PrintVector(long unsigned[], long unsigned);
void Intercala(long unsigned[], long unsigned, long unsigned);

int main(void)
{
    long unsigned q1, q2;
    scanf("%ld", &q1);
    scanf("%ld", &q2);

    long unsigned *vu;
    vu = malloc((q1+q2)*sizeof(long unsigned));
    ScanVector(vu, q1);
    ScanVector(vu + q1, q2);

    Intercala(vu, q1, q2);
    PrintVector(vu, q1 + q2);

    free(vu);

    return 0;
}

/* Recebe um vetor vu[0..q1+q2-1] com dois subvetores ordenados de tamanho q1
 * e q2. Intercala de modo ordenado os elementos de ambos subvetores e 
 * substitui o resultado no próprio vetor vu. */
void Intercala(long unsigned vu[], long unsigned q1, long unsigned q2)
{
    long unsigned *temp, e, fim_e, d, fim_d;
    temp = malloc((q1+q2)*sizeof(long unsigned));
    e = 0; fim_e = q1;
    d = q1; fim_d = q1 + q2;

    int i;
    for (i = 0; i < q1 + q2; i++) {
        if (e >= fim_e) {
            temp[i] = vu[d]; d++;
            continue;
        }
        if (d >= fim_d) {
            temp[i] = vu[e]; e++;
            continue;
        }
        if (vu[e] < vu[d]) {
            temp[i] = vu[e]; e++;
        } else {
            temp[i] = vu[d]; d++;
        }
    }

    for (i = 0; i < q1 + q2; i++)
        vu[i] = temp[i];

    free(temp);
}

/* Recebe um vetor v[0..q-1] e seu tamanho e lê do usuário seus elementos. */
void ScanVector(long unsigned v[], long unsigned q)
{
    int i;
    for (i = 0; i < q; i++)
        scanf("%ld", &v[i]);
}

/* Recebe um vetor v[0..q-1] e seu tamanho e exibe seus elementos. */
void PrintVector(long unsigned v[], long unsigned q)
{
    int i;
    for (i = 0; i < q; i++)
        printf("%ld\n", v[i]);
}
