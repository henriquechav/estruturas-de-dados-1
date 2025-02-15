#include <stdio.h>
int main()
{
    char U[51];
    unsigned A;

    scanf("%s", U);
    scanf("%u", &A);

    printf("Voce estuda na %s ha %u anos.\n", U, A);

    return 0;
}
