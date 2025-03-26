/* Solução para o problema 119. */
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char matricula[11];
    char nome[81];
    int pontos;
    int tempo;
} aluno;

void bubbleSort(aluno*, int);

int main(void)
{
    int n;
    scanf("%d", &n);
    aluno *a = (aluno*)malloc(n*sizeof(aluno));

    for (int i = 0; i < n; i++)
        scanf("%s %s %d %d", a[i].matricula, a[i].nome, 
            &a[i].pontos, &a[i].tempo);

    bubbleSort(a, n);

    for(int i = 0; i < n; i++)
        printf("%s %s %d (%d)\n", a[i].matricula, a[i].nome,
            a[i].pontos, a[i].tempo);

    return 0;
}

void bubbleSort(aluno *a, int n)
{
    aluno aux;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j].pontos < a[j+1].pontos) {
                aux = a[j+1]; 
                a[j+1] = a[j];
                a[j] = aux;
            } else if (a[j].pontos == a[j+1].pontos) {
                if (a[j].tempo > a[j+1].tempo) {
                    aux = a[j+1];
                    a[j+1] = a[j];
                    a[j] = aux;
                }
            }
        }
    }
}
