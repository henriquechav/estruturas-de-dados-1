// Solução para o problema 90.
#include <stdio.h>
#include <stdlib.h>

void LeVetor(int*, int);
int EncontraMaior(int*, int);
int BuscaLinear(int*, int, int);

void main(void)
{
    int *p, size, maior, indice;

    scanf("%d", &size);
    while (size != 0)
    {
        p = (int*)malloc(size*sizeof(int));

        LeVetor(p, size);
        maior = EncontraMaior(p, size);
        indice = BuscaLinear(p, size, maior);
        printf("%d %d\n", indice, maior);
     
        free(p); 
        
        scanf("%d", &size);
    }
}

// Lê um certo número de inteiros para o vetor.
void LeVetor(int *p, int size)
{
    int i;
    for (i = 0; i < size; i++)
        scanf("%d", p+i);
}

// Retorna o maior elemento do vetor.
int EncontraMaior(int *p, int size)
{
    int maior, i;
    for (i = 1, maior = *p; i < size; i++)
        if (maior < *(p+i))
            maior = *(p+i);

    return maior;
}

// Retorna o primeiro índice do elemento buscado.
int BuscaLinear(int *p, int size, int x)
{
    int i;
    for (i = 0; i < size; i++)
        if (*(p+i) == x)
            return i;
    
    return -1;
}
