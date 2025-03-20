/* Solução para o problema 112. */
#include <stdio.h>
#include <stdlib.h>

struct tLista 
{
    char *itens;
    int tam;
    int qnt;
};

struct tLista criarLista(int n)
{
    struct tLista l;
    l.itens = (char*)malloc(n*sizeof(char));
    l.tam = n;
    l.qnt = 0;
    return l;
}

int listaVazia(struct tLista *l)
{
    return l->qnt == 0;
}

int listaCheia(struct tLista *l)
{
    return l->qnt == l->tam;
}

void mostrarLista(struct tLista *l)
{
    int i;
    for (i = 0; i < l->qnt; i++)
        printf("%c%s", l->itens[i], i != l->qnt - 1 ? " " : "\n");
}

int buscarLista(struct tLista *l, char chave)
{
    int i;
    for (i = 0; i < l->qnt; i++)
        if (l->itens[i] == chave)
            return i;
    return -1;
}

void inserir(struct tLista *l, char chave)
{
    int i, j;
    if (!listaCheia(l) && buscarLista(l, chave) == -1) {
        for (i = 0; l->itens[i] < chave && i < l->qnt; i++);
        for (j = l->qnt - 1; j >= i; j--)
            l->itens[j+1] = l->itens[j];
        l->itens[i] = chave;
        l->qnt++;
    }
}

void remover(struct tLista *l, int iRem)
{
    int i;
    if (!listaVazia(l) && iRem != -1) {
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

    char chave, cmd;
    while ( scanf(" %c", &cmd) != EOF ) {
        switch (cmd) {
            case 'I':
                scanf(" %c", &chave);
                inserir(&lista, chave);
                break;
            case 'R':
                scanf(" %c", &chave);
                remover(&lista, buscarLista(&lista, chave));
                break;
            case 'B':
                scanf(" %c", &chave);
                if (buscarLista(&lista, chave) == -1)
                    printf("NAO\n");
                else
                    printf("SIM\n");
                break;
            case 'M':
                mostrarLista(&lista);
        }
    }

    return 0;
}
