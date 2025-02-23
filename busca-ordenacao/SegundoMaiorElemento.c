// Solução para o problema 91.
#include <stdio.h>
#include <stdlib.h>

void LeVetor(int*, unsigned long);

void main(void)
{
    /* Inicializando vetor. */
    int *vet;
    unsigned long tamanho;
    scanf("%ld", &tamanho);
    vet = (int*)malloc(tamanho*sizeof(int));
    LeVetor(vet, tamanho);

    /* Encontra o maior elemento e seu índice. */
    int maior = vet[0], imaior = 0, i;
    for (i = 1; i < tamanho; i++)
    {
        if (maior < vet[i])
        {
            maior = vet[i];
            imaior = i;
        }
    }

    /* Encontra o segundo maior elemento e seu índice. */
    int segundo, isegundo;
    if (imaior != 0) { /* inicializa segundo com algo diferente de maior */
        segundo = vet[0];
        isegundo = 0;
    } else {
        segundo = vet[1];
        isegundo = 1;
    }

    for (i = 0; i < tamanho; i++)
    {
        if (segundo < vet[i] && i != imaior)
        {
            segundo = vet[i];
            isegundo = i;
        }
    }

    /* Exibe resultado */
    printf("%d %d\n", isegundo, segundo);

    free(vet);
}

/* Lê um certo número de inteiros para o vetor. */ 
void LeVetor(int *vet, unsigned long tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        scanf("%d", vet+i);
    }
}
