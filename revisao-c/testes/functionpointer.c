// Programa tirado do livro "C completo e total"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "string.h"

void check(char *a, char *b,
            int (*cmp) (const char *, const char *));
int numcmp(const char *a, const char *b);

void main(void)
{
    char s1[80], s2[80];

    scanf("%s", s1);
    scanf("%s", s2);

    if (isalpha(*s1))
        check(s1, s2, strcmp);
    else
        check(s1, s2, numcmp);
}

void check(char *a, char *b,
    int (*cmp) (const char *, const char *))
{
    printf("testando igualdade\n");
    if (!(*cmp)(a, b)) printf("igual\n");
    else printf("diferente\n");
}

int numcmp(const char *a, const char *b)
{
    if(atoi(a) == atoi(b)) return 0;
    else return 1;
}
