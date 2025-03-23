/* Solução para o problema 118. */
#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();

    char linha[110];
    int count = 0;
    int balanceado = 1;

    for (int i = 0; i < n; i++) {
        if (fgets(linha, sizeof(linha), stdin) == NULL)
            break;

        for (int j = 0; linha[j] != '\0'; j++) {
            if (linha[j] == '{') {
                count++;
            } else if (linha[j] == '}') {
                count--;
                if (count < 0) {
                    balanceado = 0;
                    break;
                }
            }
        }

        if (!balanceado)
            break;
    }

    printf("%c\n", (balanceado && count == 0) ? 'S' : 'N');

    return 0;
}
