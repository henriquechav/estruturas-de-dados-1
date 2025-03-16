/* Implementação de Pilha Estática em C. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tItem
{
    char nome[50];
};

struct tPilha
{
    struct tItem *itens;
    int topo;
    int tam;
};

struct tItem criarItem(char*);
struct tPilha criarPilha(int);
struct tItem topo(struct tPilha);
void mostrarPilhaBaseTopo(struct tPilha);
void mostrarPilhaTopoBase(struct tPilha);
int pilhaVazia(struct tPilha);
int pilhaCheia(struct tPilha);
void empilhar(struct tPilha*, struct tItem);
void desempilhar(struct tPilha*);

int main(void)
{
    int opc, n;
    char nome[50];
    struct tPilha pilha;
    printf("Informe o tamanho da pilha: ");
    scanf("%d", &n);
    pilha = criarPilha(n);

    do {
        do {
            printf("Escolha uma das opções a seguir: \n");
            printf("1 - Empilhar\n");
            printf("2 - Mostrar Pilha Base Topo\n");
            printf("3 - Mostrar Pilha Topo Base\n");
            printf("4 - Topo\n");
            printf("5 - Desempilhar\n");
            printf("6 - Sair\n");
            printf("==> ");
            scanf("%d", &opc);
        } while (opc < 1 || opc > 6);

        switch (opc) {
            case 1: printf("Informe o nome: ");
                    scanf("%s", nome);
                    empilhar(&pilha, criarItem(nome));
                    break;
            case 2: mostrarPilhaBaseTopo(pilha);
                    break;
            case 3: mostrarPilhaTopoBase(pilha);
                    break;
            case 4: if (!pilhaVazia(pilha))
                        printf("Item [%s] está no topo\n", topo(pilha).nome);
                    break;
            case 5: if (!pilhaVazia(pilha)) {
                        printf("Item [%s] desempilhado\n", topo(pilha).nome);
                        desempilhar(&pilha);
                    }
        }
    } while (opc != 6);

    printf("Finalizando o programa...\n");
    return 0;
}

struct tItem criarItem(char *nome)
{
    struct tItem item;
    strcpy(item.nome, nome);
    return item;
}

struct tPilha criarPilha(int n)
{
    struct tPilha pilha;
    pilha.itens = (struct tItem*)malloc(n*sizeof(struct tItem));
    pilha.tam = n;
    pilha.topo = -1;
    return pilha;
}

struct tItem topo(struct tPilha pilha)
{
    return pilha.itens[pilha.topo];
}

void mostrarPilhaBaseTopo(struct tPilha pilha)
{
    int i;
    for (i = 0; i <= pilha.topo; i++)
        printf("%s%s", pilha.itens[i].nome, i != pilha.topo ? " " : "\n");
}

void mostrarPilhaTopoBase(struct tPilha pilha)
{
    int i;
    for (i = pilha.topo; i >= 0; i--)
        printf("%s%s", pilha.itens[i].nome, i != 0 ? " " : "\n");
}

int pilhaVazia(struct tPilha pilha)
{
    return pilha.topo == -1;
}

int pilhaCheia(struct tPilha pilha)
{
    return pilha.topo == pilha.tam - 1;
}

void empilhar(struct tPilha *pilha, struct tItem item)
{
    if (!pilhaCheia(*pilha))
        pilha->itens[++pilha->topo] = item;
}

void desempilhar(struct tPilha *pilha)
{
    if (!pilhaVazia(*pilha))
        pilha->topo--;
}
