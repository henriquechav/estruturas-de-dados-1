// Solução para o problema 97.
#include <stdio.h>

void Intercala(char*, char*);

int main(void)
{
    char nome[101], matricula[12];
    while ( scanf("%s %s", nome, matricula) != EOF ) {
        Intercala(nome, matricula);
    }

    return 0;
}

/* Intercala os caracteres de duas strings e exibe o resultado no terminal. */
void Intercala(char *s1, char *s2)
{
    char resultado[112];

    /* Índices para o resultado, s1 e s2, respectivamente.*/
    int i = 0, a = 0, b = 0;
    while (s1[a] || s2[b]) {
        /* Intercala baseado na paridade de i. Mas, caso os elementos de s1 ou 
           s2 acabem, concatena o restante da outra string. */
        if (i % 2 == 0) {
            if (s1[a]) {
                resultado[i] = s1[a];
                i++; a++;
            } else {
                for (; s2[b]; i++, b++)
                    resultado[i] = s2[b];
            }
        } else {
            if (s2[b]) {
                resultado[i] = s2[b];
                i++; b++;
            } else {
                for (; s1[a]; i++, a++)
                    resultado[i] = s1[a];
            }
        }
    }
    resultado[i] = '\0'; /* Delimita fim da string. */
    printf("%s\n", resultado);
}
