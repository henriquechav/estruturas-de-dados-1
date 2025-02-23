// Programa tirado do livro "C completo e total"
#include <stdio.h>
void main(void)
{
    int i;
    char str[80], str2[80];

    scanf("%d%[^abcdefg]%s", &i, str, str2);
    printf("%d %s %s\n", i, str, str2);   
}
