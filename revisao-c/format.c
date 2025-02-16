#include <stdio.h>

void main(void)
{
    double item;
    item = 10.12304;
    printf("%f\n", item);
    printf("%10f\n", item);
    printf("%012f\n", item);
    printf("\n");

    /* mostra uma tabela de quadrados e cubos */
    int i;
    for(i=1; i<21; i++)
        printf("%-8d %-8d %-8d\n", i, i*i, i*i*i);
}
