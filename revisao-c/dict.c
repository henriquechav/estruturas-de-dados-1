// Programa tirado, e adaptado, do livro "C completo e total".

/* Um dicionário simples. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* lista de palavras e significados */
char *dic[][40] = {
    "atlas", "um livro de mapas",
    "carro", "um veículo motorizado",
    "telefone", "um dispositivo de comunicação",
    "avião", "uma máquina voadora",
    "", "" /* nulo termina a lista */
};

void main(void)
{
    char word[80], ch;
    char **p;
    do {
        puts("\nEntre a palavra: ");
        scanf("%s", word);

        p = (char **)dic;

        /* encontra a palavra e imprime seu significado */
        do {
            if(!strcmp(*p, word)) {
                printf("significado: ");
                puts(*(p+1));
                break;
            }
            if(!strcmp(*p, word)) break;
            p = p + 2; /* avança na lista */
        } while(*p);
        if(!*p) puts("a palavra não está no dicionário");
        getchar(); /* descarta '\n' do buffer */
        printf("outra? (y/n): ");
        ch = getchar();
    } while(toupper(ch) != 'N');
}
