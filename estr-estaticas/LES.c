/* Implementação de uma Lista Estática Sequencial em C. */
#include <stdio.h>
#include <stdlib.h>

struct tLista
{
    int *itens;
    int qnt;
    int tam;
};

struct tLista criarLista(int n)
{
    struct tLista lista;
    lista.itens = (int*)malloc(n*sizeof(int));
    lista.tam = n;
    lista.qnt = 0;
    return lista;
}

int listaCheia(struct tLista lista)
{
    return lista.qnt == lista.tam;
}

int listaVazia(struct tLista lista)
{
    return lista.qnt == 0;
}

void mostrarLista(struct tLista lista)
{
    int i;
    for (i = 0; i < lista.qnt; i++)
        printf("%d%s", lista.itens[i], i != lista.qnt - 1 ? " " : "\n");
}

int buscarLista(struct tLista lista, int chave)
{
    int i;
    for (i = 0; i < lista.qnt; i++)
        if (lista.itens[i] == chave)
            return i;
    return -1;
}

void inserir(struct tLista *lista, int chave)
{
    int i, j;
    if (!listaCheia(*lista)) {
        for (i = 0; lista->itens[i] < chave && i < lista->qnt; i++);
        for (j = lista->qnt - 1; j >= i; j--)
            lista->itens[j+1] = lista->itens[j];
        lista->itens[i] = chave;
        lista->qnt++;
    }
}

void remover(struct tLista *lista, int iRem)
{
    int i;
    if (!listaVazia(*lista) && iRem != -1) {
        for (i = iRem; i < lista->qnt - 1; i++)
            lista->itens[i] = lista->itens[i+1];
        lista->qnt--;
    }
}

int main(void)
{
    int opc, n, chave, iChave;
    struct tLista lista;
    printf("Informe o tamanho da lista, por favor: ");
    scanf("%d", &n);
    lista = criarLista(n);

    do {
        do {
            printf("Escolha uma das opções a seguir:\n");
            printf("1 - Inserir\n");
            printf("2 - Mostrar Lista\n");
            printf("3 - Buscar Lista\n");
            printf("4 - Remover\n");
            printf("5 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        } while(opc < 1 || opc > 5);
        
        if (opc == 1 || opc == 3 || opc == 4) {
            printf("Informe o valor da chave: ");
            scanf("%d", &chave);
        }

        switch (opc) {
            case 1: inserir(&lista, chave);
                    break;
            case 2: mostrarLista(lista);
                    break;
            case 3: iChave = buscarLista(lista, chave);
                    if (iChave != -1)
                        printf("Item (%d) localizado\n", lista.itens[iChave]);
                    else
                        printf("Item (%d) não localizado\n", chave);
                    break;
            case 4: remover(&lista, buscarLista(lista, chave));
        }
    } while (opc != 5);

    printf("Finalizando o programa...\n");
    return 0;
}
