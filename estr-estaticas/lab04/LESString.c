/* Solução para o problema 113. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tLista 
{
    char **itens;
    int tam, qnt;
};

struct tLista criarLista(int n)
{
    struct tLista l;
    l.itens = (char**)malloc(n*sizeof(char*));
    
    int i;
    for (i = 0; i < n; i++)
        l.itens[i] = NULL;
    
    l.tam = n; l.qnt = 0;
    return l;
}

int cheia(struct tLista *l)
{
    return l->qnt == l->tam;
}

int vazia(struct tLista *l)
{
    return l->qnt == 0;
}

void mostrar(struct tLista *l)
{
    int i;
    for (i = 0; i < l->qnt; i++)
        printf("%s%s", l->itens[i], i != l->qnt - 1 ? " " : "\n");
}

int buscar(struct tLista *l, char *chave)
{
    int i;
    for (i = 0; i < l->qnt; i++)
        if (strcmp(l->itens[i], chave) == 0)
            return i;
    return -1;
}

void inserir(struct tLista *l, char *chave)
{
    int i, j;
    if (!cheia(l) && buscar(l, chave) == -1) {
        for (i = 0; i < l->qnt && (strcmp(l->itens[i], chave) < 0); i++);
        for (j = l->qnt - 1; j >= i; j--)
            l->itens[j+1] = l->itens[j];
        l->itens[i] = strdup(chave);
        l->qnt++;
    }
}

void remover(struct tLista *l, int iRem)
{
    int i;
    if (!vazia(l) && iRem != -1 && iRem < l->qnt) {
        free(l->itens[iRem]);
        for (i = iRem; i < l->qnt - 1; i++)
            l->itens[i] = l->itens[i+1];
        l->qnt--;
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    struct tLista lista;
    lista = criarLista(n);

    char cmd, chave[80];
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'I':
                scanf(" %s", chave);
                inserir(&lista, chave);
                break;
            case 'R':
                scanf(" %s", chave);
                remover(&lista, buscar(&lista, chave));
                break;
            case 'B':
                scanf(" %s", chave);
                if (buscar(&lista, chave) == -1)
                    printf("NAO\n");
                else
                    printf("SIM\n");
                break;
            case 'M':
                mostrar(&lista);
        }
    }

    return 0;
}
