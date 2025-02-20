#include <stdio.h>
void main(void)
{
    char ch = 'W';
    char *p = &ch;

    printf("endereço de 'W': %p\n", p);

    printf("entre com um endereço: ");
    scanf("%p", &p);
    printf("na posição %p há %c\n", p, *p);
}
