// Solução para o problema 99. (Ainda considerado errado pelo juiz BOCA)
#include <stdio.h>
#include <stdlib.h>

void Intercala(char*, int, int);

int main(void)
{
    char su[20001];
    int n, m;
    scanf("%s", su);
    scanf("%d %d", &n, &m);

    Intercala(su, n, m);

    return 0;
}

/* Intercala as substrings de tamanho n e m de su e exibe o resultado. */
void Intercala(char *su, int n, int m)
{
    /* Índices para o resultado e para as duas substrings, respectivamente. */
    int i = 0, a = 0, b = n;
    char *res = (char*)malloc((n+m+1)*sizeof(char));
    while (a < n || b < n + m) {
        /* Em casos onde uma das substrings acaba, deve ser concatenado no 
           resultado o resto da outra. */
        if (a >= n) {
            for (; b < n + m; b++, i++)
                res[i] = su[b];
            break;
        }

        if (b >= n + m) {
            for (; a < n; a++, i++)
                res[i] = su[a];
            break;
        }

        /* Sempre adiciona o menor elemento das substrings, mantendo a 
           ordem. */
        if (su[a] <= su[b]) {
            res[i] = su[a];
            i++; a++;
        } else {
            res[i] = su[b];
            i++; b++;
        }
    }
    res[i] = '\0'; /* Delimita o fim da string. */
    printf("%s\n", res);
    free(res);
}
