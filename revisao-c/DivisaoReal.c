#include <stdio.h>

void main(void)
{
    long int a, b;
    scanf("%li %li", &a, &b);
    printf("%.4f\n", (float)a/b);
}
