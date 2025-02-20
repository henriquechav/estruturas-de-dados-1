// Programa tirado do livro "C completo e total"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void push(int);
int pop(void);

int *tos, *p1, stack[SIZE];

void main(void)
{
    int value;
    tos = stack; /* faz tos conter o topo da pilha */
    p1 = stack; /* inicializa p1 */

    do {
        printf("Digite o valor: ");
        scanf("%i", &value);
        if (value != 0) push(value);
        else printf("valor do topo é %i\n", pop());
    } while (value != -1);
}

void push(int i)
{
    p1++;
    if (p1 == (tos + SIZE)) {
        printf("Estouro da pilha\n");
        exit(1);
    }
    *p1 = i;
}

int pop(void)
{
    if (p1 == tos) {
        printf("Estouro da pilha\n");
        exit(1);
    }
    p1--;
    return *(p1+1);
}
