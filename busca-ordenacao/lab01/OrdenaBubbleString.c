// Solução para o problema 95.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RecebeVetor(char**, unsigned);
void ExibeVetor(char**, unsigned);
void BubbleSort(char**, unsigned);

void main(void)
{
    char **vet;
    unsigned tamanho;
    scanf("%u", &tamanho);
    getchar(); /* descarta '\n' deixado no buffer */
    vet = (char**)malloc(tamanho*sizeof(char*));

    /* Aloca memória para cada string do vetor. */
    int i = 0;
    for (; i < tamanho; i++)
        vet[i] = (char*)malloc(80*sizeof(char));

    RecebeVetor(vet, tamanho);
    BubbleSort(vet, tamanho);

    /* Libera memória de cada string do vetor */
    for (i = 0; i < tamanho; i++)
        free(vet[i]);

    free(vet);
}

void BubbleSort(char **vet, unsigned tamanho)
{
    ExibeVetor(vet, tamanho);
    int i, j, trocas = 0;
    char *aux;
    
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if ( strcmp(vet[j], vet[j+1]) > 0 )
            {
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;

                trocas++;
                ExibeVetor(vet, tamanho);
            }
        }
    }

    ExibeVetor(vet, tamanho);
    printf("Trocas: %d\n", trocas);
}

void RecebeVetor(char **vet, unsigned tamanho)
{
    int i = 0;
    for (; i < tamanho; i++)
    {
        scanf("%s", vet[i]);
        getchar(); /* descarta espaço em branco */
    }
}

void ExibeVetor(char **vet, unsigned tamanho)
{
    int i = 0;
    for (; i < tamanho; i++)
    {
        printf("%s", vet[i]);
        if (i != tamanho - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
}
