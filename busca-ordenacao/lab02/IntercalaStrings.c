// Solução para o problema 98.
#include <stdio.h>
#include <stdlib.h>

void Intercala(char*, char*, char*);

int main(void)
{
    int n1, n2;
    char *s1, *s2;

    /* Incrementa n1 e n2 para conter o caractere nulo da string. */
    scanf("%d", &n1); n1++;
    s1 = (char*)malloc(n1*sizeof(char));
    scanf("%s", s1);

    scanf("%d", &n2); n2++;
    s2 = (char*)malloc(n2*sizeof(char));
    scanf("%s", s2);

    char *sr = (char*)malloc((n1+n2)*sizeof(char));
    Intercala(s1, s2, sr);
    printf("%s\n", sr);

    return 0;
}

/* Intercala duas strings ordenadas em uma terceira, ainda ordenada. */
void Intercala(char *s1, char *s2, char *sr)
{
    /* Índices para sr, s1 e s2, respectivamente.*/
    int i = 0, a = 0, b = 0;
    while (s1[a] || s2[b]) {
        /* Caso uma das strings acabe, preenche sr com o resto da outra. */
        if (!s1[a]) {
            for (; s2[b]; b++, i++)
                sr[i] = s2[b]; 
        }
        if (!s2[b]) {
            for (; s1[a]; a++, i++)
                sr[i] = s1[a]; 
        }

        /* Sempre adiciona o menor elemento a sr, mantendo a ordem. */
        if (s1[a] <= s2[b]) {
            sr[i] = s1[a];
            i++; a++;
        } else {
            sr[i] = s2[b];
            i++; b++;
        }
    }
    sr[i] = '\0'; /* Delimita o fim de sr. */
}
