// Solução para o problema 94.
#include <stdio.h>
#include <stdlib.h>

void RecebeVetor(char*, unsigned);
void ExibeVetor(char*, unsigned);
void BubbleSort(char*, unsigned);

void main(void)
{
    char *vet;
    unsigned tamanho;
    scanf("%u", &tamanho);
    getchar(); /* descarta '\n' deixado no buffer */
    vet = (char*)malloc(tamanho*sizeof(char));
    RecebeVetor(vet, tamanho);
    BubbleSort(vet, tamanho);
    free(vet);
}

void BubbleSort(char *vet, unsigned tamanho)
{
    ExibeVetor(vet, tamanho);
    int i, j, aux, trocas = 0;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (vet[j] > vet[j+1])
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

void RecebeVetor(char *vet, unsigned tamanho)
{
    int i = 0;
    for (; i < tamanho; i++)
    {
        scanf("%c", vet+i);
        getchar(); /* descarta o espaço em branco */
    }
}

void ExibeVetor(char *vet, unsigned tamanho)
{
    int i = 0;
    for (; i < tamanho; i++)
    {
        putchar(vet[i]);
        if (i != tamanho - 1) {
            putchar(' ');
        } else {
            putchar('\n');
        }
    }
}
