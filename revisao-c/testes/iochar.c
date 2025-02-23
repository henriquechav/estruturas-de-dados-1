// Programa tirado do livro "C completo e total".
#include <stdio.h>
#include <ctype.h>

void main()
{
    char ch;

    printf("Entre com algum texto (digite um ponto para sair).\n");
    do {
        ch = getchar();

        if (islower(ch)) ch = toupper(ch);
        else ch = tolower(ch);

        putchar(ch);
    } while (ch != '.');
}
