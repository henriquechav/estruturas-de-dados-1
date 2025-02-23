// Solução para o problema 93.
#include <stdio.h>
#include <stdlib.h>

void RecebeVetor(int*, unsigned);
void ExibeVetor(int*, unsigned);
void BubbleSort(int*, unsigned);

void main(void)
{
    int *vet;
    unsigned tamanho;
    scanf("%u", &tamanho);
    vet = (int*)malloc(tamanho*sizeof(int));
    RecebeVetor(vet, tamanho);
    BubbleSort(vet, tamanho);
    free(vet);
}

/* Ordena o vetor, imprimindo a cada troca, e conta o número de trocas. */
void BubbleSort(int *vet, unsigned tamanho)
{
    ExibeVetor(vet, tamanho);
    int i, j, aux, trocas = 0;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (vet[j] > vet[j+1])
            {
                aux = vet[j]; /* realiza a troca */
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

void ExibeVetor(int *vet, unsigned tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        printf("%d", vet[i]);
        if (i != tamanho - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
}

void RecebeVetor(int *vet, unsigned tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", vet+i);
    }
}
