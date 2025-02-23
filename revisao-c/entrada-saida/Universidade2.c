// Solução para o problema 4.
#include <stdio.h>
int main()
{
    char U[51];
    unsigned A;

    printf("Onde voce estuda: ");
    scanf("%s", U);
    printf("Quanto tempo: ");
    scanf("%u", &A);

    printf("Voce estuda na %s ha %d anos.\n", U, A);

    return 0;
}
