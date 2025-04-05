/* Solução para o problema 146. */
#include <stdio.h>
#include <stdlib.h>

typedef struct item 
{
    char chave;
    struct item *anterior;
} item;

typedef struct pilhad
{
    item *topo;
} pilhad;

item* criarItem(char);
pilhad* criar(void);
void empilhar(pilhad*, item*);
char desempilhar(pilhad*);
void transferir(pilhad*, pilhad*);
char testarJogo(char, char);
void rodarJogos(pilhad*, pilhad*, int);

int main(void)
{
    pilhad *vencedores = criar();
    pilhad *participantes = criar();

    /* Oitavas-de-final */
    for (char c = 'P'; c >= 'A'; c -= 1)
        empilhar(participantes, criarItem(c));
    rodarJogos(participantes, vencedores, 8);
    transferir(vencedores, participantes);

    /* Quartas-de-final */
    rodarJogos(participantes, vencedores, 4);
    transferir(vencedores, participantes);

    /* Semifinal */
    rodarJogos(participantes, vencedores, 2);
    transferir(vencedores, participantes);

    /* Final */
    rodarJogos(participantes, vencedores, 1);

    /* Mostrar vencedor */
    printf("%c\n", vencedores->topo->chave);
    
    return 0;
}

item* criarItem(char chave)
{
    item *it = (item*)malloc(sizeof(item));
    if (it != NULL) {
        it->chave = chave;
        it->anterior = NULL;
    }
    return it;
}

pilhad* criar(void)
{
    pilhad *p = (pilhad*)malloc(sizeof(pilhad));
    if (p != NULL)
        p->topo = NULL;
    return p;
}

void empilhar(pilhad *p, item *novo)
{
    novo->anterior = p->topo;
    p->topo = novo;
}

char desempilhar(pilhad *p)
{
    if (p->topo != NULL) {
        item *aux = p->topo;
        char chave = p->topo->chave;
        p->topo = p->topo->anterior;
        free(aux);
        return chave;
    }
    return '\0';
}

void transferir(pilhad *p1, pilhad *p2)
{
    item *it = p1->topo;
    char chave;
    while (it != NULL) {
        it = it->anterior;
        chave = desempilhar(p1);
        empilhar(p2, criarItem(chave));
    }
}

char testarJogo(char timeEsq, char timeDir)
{
    int golsEsq, golsDir;
    scanf("%d %d", &golsEsq, &golsDir);
    if (golsEsq > golsDir)
        return timeEsq;
    else
        return timeDir;
}

void rodarJogos(pilhad *pAux, pilhad *p, int qnt)
{
    char timeEsq, timeDir, vencedor;
    for (int i = 0; i < qnt; i++) {
        timeEsq = desempilhar(pAux);
        timeDir = desempilhar(pAux);
        vencedor = testarJogo(timeEsq, timeDir);
        empilhar(p, criarItem(vencedor));
    }
}
