// Problema ainda não resolvido.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
    unsigned n; /* número de testes*/
    scanf("%u", &n);
    
    /* reserva n espaços para 10 char */
    char *p = malloc(n*10*sizeof(char)); 

    /* lê resultados e os guarda no vetor dinâmico */
    int i, m1, m2;
    for (i = 0; i < n; i++)
    {
        scanf("%i %i", &m1, &m2);

        if      (m1 <= 2 && m2 <= 2)     strcpy(p+i*10, "Nova");
        else if (m1 >= 97 && m2 >= 97)   strcpy(p+i*10, "Cheia");
        else if (m1 < m2)                strcpy(p+i*10, "Crescente");
        else                             strcpy(p+i*10, "Minguante");
    }

    /* exibe resultados */
    for (i = 0; i < n; i++) 
        printf("%s\n", p+i*10);

    free(p);
}
