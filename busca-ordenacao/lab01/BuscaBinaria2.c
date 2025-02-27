// Solução para o problema 92.
#include <stdio.h>
#include <stdlib.h>

void LeVetor(int*, unsigned long);
void MostraVetor(int*, int, int);
int BuscaBinaria(int*, int, int);

void main(void)
{
    /* Inicializa vetor. */
    int *vet;
    unsigned long tamanho;
    scanf("%ld", &tamanho);
    vet = (int*)malloc(tamanho*sizeof(int));
    LeVetor(vet, tamanho);

    /* Realiza procedimento enquanto não lê EOF. */
    int buscado, indice;
    while ( scanf("%d", &buscado) != EOF )
    {
        indice = BuscaBinaria(vet, tamanho, buscado);
        if (indice != -1) {
            printf("VALOR %d LOCALIZADO NA COLECAO\n", buscado);
        } else {
            printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", buscado);
        }
    } 
}

/* Retorna o índice do elemento buscado, caso não encontre retorna -1.
   Também mostra os subvetores descartados ao longo do procedimento. */
int BuscaBinaria(int *v, int n, int x)
{
    int esq = 0, dir = n-1, meio;
    while (esq <= dir)
    {
        meio = (esq + dir) / 2;
        if (v[meio] == x)
            return meio;
        else if (v[meio] > x)
        {
            MostraVetor(v, meio, dir);
            dir = meio - 1;
        }
        else
        {
            MostraVetor(v, esq, meio);
            esq = meio + 1;
        }
    }
    return -1;
}

// Lê certo número de inteiros para o vetor.
void LeVetor(int *v, unsigned long tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
        scanf("%d", v+i);
}

// Imprime o vetor na tela de um índice a outro.
void MostraVetor(int *v, int i, int fim)
{
    for (; i <= fim; i++)
    {
        printf("%d", v[i]);
        if (i != fim)
            putchar(' ');
        else 
            putchar('\n');
    }
}
