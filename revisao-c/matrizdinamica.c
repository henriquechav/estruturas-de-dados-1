// Programa tirado do livro "C completo e total"

/* Apresenta as potências dos números de 1 a 10.
   Nota: muito embora esse programa esteja correto,
   alguns compiladores apresentarão um warning com
   relação aos argumentos para as funções table()
   e show(). Se isso acontecer, ignore. */

#include <stdio.h>
#include <stdlib.h>

int pwr(int a, int b);
void table(int p[4][10]);
void show(int p[4][10]);

void main(void)
{
    int *p;

    p = malloc(40*sizeof(int));

    if (!p) {
        printf("Falha na solicitação de memória.\n");
        exit(1);
    }

    /* aqui, p é simplesmente um ponteiro */
    table(p);
    show(p);
}

/* Constroi a tabela de potências. */
void table(int p[4][10]) /* Agora o compilador tem uma matriz 
                            para trabalhar. */
{
    register int i, j;

    for (j = 1; j < 11; j++)
        for (i = 1; i < 5; i++) p[i-1][j-1] = pwr(j, i);
}

/* Exibe a tabela de potências inteiras. */
void show(int p[4][10]) /* Agora o compilador tem uma matriz
                           para trabalhar. */
{
    register int i, j;

    printf("%10s %10s %10s %10s\n", "N", "N^2", "N^3", "N^4");
    for (j = 1; j < 11; j++) {
        for (i = 1; i < 5; i++) printf("%10d ", p[i-1][j-1]);
        printf("\n");
    }
}

/* Eleva um inteiro a uma potência especificada. */
pwr(int a, int b)
{
    register int t = 1;
    
    for (; b; b--) t = t * a;
    return t;
}
