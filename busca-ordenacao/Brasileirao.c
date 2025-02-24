// Solução para o problema 96.
#include <stdio.h>
#include <stdlib.h>

struct equipe
{
    char nome[101];
    unsigned pontos;
    unsigned vitorias;
    unsigned empates;
    unsigned derrotas;
    unsigned saldo;
    unsigned gols_pro;
    unsigned gols_contra;
};

void RecebeEquipes(struct equipe*, unsigned);
void RecebePartidas(struct equipe*, unsigned);
void OrdenaEquipes(struct equipe*, unsigned);
void ExibeEquipes(struct equipe*, unsigned);

void main(void)
{
    /* Inicializando vetor de equipes. */
    unsigned qnt_equipes;
    scanf("%u", &qnt_equipes);
    struct equipe *ptr;
    ptr = (struct equipe*)malloc(qnt_equipes*sizeof(struct equipe));
    
    int i = 0;
    for (; i < qnt_equipes; i++)
    {
        ptr[i].pontos = 0;
        ptr[i].vitorias = 0;
        ptr[i].empates = 0;
        ptr[i].derrotas = 0;
        ptr[i].gols_pro = 0;
        ptr[i].gols_contra = 0;
    }

    /* Realiza procedimento. */
    RecebeEquipes(ptr, qnt_equipes);
    RecebePartidas(ptr, qnt_equipes);
    OrdenaEquipes(ptr, qnt_equipes);
    ExibeEquipes(ptr, qnt_equipes);

    /* Libera memória alocada. */
    free(ptr);
}

/* Ordena as equipes segundo seus pontos, com número de vitórias, saldo de gols e gols pró como
   critérios de desempate. Faz isso aos moldes do algoritmo Bubble Sort. */
void OrdenaEquipes(struct equipe *ptr, unsigned qnt_equipes)
{
    struct equipe aux;
    int i, j;
    for (i = 0; i < qnt_equipes-1; i++)
    {
        for (j = 0; j < qnt_equipes-i-1; j++)
        {
            if /* condições com critérios de desempate */
            (   
                (   /* critério primário */
                    ptr[j].pontos < ptr[j+1].pontos
                ) || 
                (   /* critério secundário */
                    ptr[j].pontos == ptr[j+1].pontos && ptr[j].vitorias < ptr[j+1].vitorias 
                ) || 
                (   /* critério terciário */
                    ptr[j].pontos == ptr[j+1].pontos && ptr[j].vitorias == ptr[j+1].vitorias && 
                    ptr[j].saldo < ptr[j+1].saldo
                ) ||
                (   /* critério último */
                    ptr[j].pontos == ptr[j+1].pontos && ptr[j].vitorias == ptr[j+1].vitorias && 
                    ptr[j].saldo == ptr[j+1].saldo && ptr[j].gols_pro < ptr[j+1].gols_pro
                )
            )
            {   /* então realiza a troca de posições */
                aux = ptr[j];
                ptr[j] = ptr[j+1];
                ptr[j+1] = aux;
            } 
        }
    }
}

void RecebePartidas(struct equipe *ptr, unsigned qnt_equipes)
{
    int m, v; /* índices para mandante (m) e visitante (v) */
    unsigned m_gols, v_gols;
    for (m = 0; m < qnt_equipes; m++)
    {
        for (v = 0; v < qnt_equipes; v++)
        {
            if (m == v) continue; /* pula índices iguais */

            /* Lê e registra os dados. */
            scanf("%*s %u x %u %*s", &m_gols, &v_gols);
            ptr[m].gols_pro += m_gols; ptr[m].gols_contra += v_gols;
            ptr[v].gols_pro += v_gols; ptr[v].gols_contra += m_gols;
            
            if (m_gols == v_gols) {
                ptr[m].empates++; ptr[m].pontos++;
                ptr[v].empates++; ptr[v].pontos++;
            } else if (m_gols > v_gols) {
                ptr[m].vitorias++; ptr[m].pontos += 3;
                ptr[v].derrotas++;
            } else {
                ptr[m].derrotas++;
                ptr[v].vitorias++; ptr[v].pontos += 3;
            }
        }
    }

    /* Calcula saldo de gols de cada equipe. */
    int i = 0;
    for (; i < qnt_equipes; i++) 
        ptr[i].saldo = ptr[i].gols_pro - ptr[i].gols_contra;
}

void ExibeEquipes(struct equipe *ptr, unsigned qnt_equipes)
{
    printf("CAMPEAO: %s\n", ptr[0].nome);
    printf("VICE-CAMPEAO: %s\n", ptr[1].nome);
    
    int i;

    printf("REBAIXADOS: ");
    for (i = qnt_equipes-1; i >= qnt_equipes-4; i--)
    {
        printf("%s", ptr[i].nome);
        if (i > qnt_equipes-3) {
            printf(", ");
        } else if (i == qnt_equipes-3) {
            printf(" e ");
        } else {
            putchar('\n');
        }
    }

    printf("TABELA FINAL:\n");
    for (i = 0; i < qnt_equipes; i++)
    {
        printf("%s %u %u %u %u ", ptr[i].nome, ptr[i].pontos, ptr[i].vitorias, ptr[i].empates, ptr[i].derrotas);
        printf("%d %u %u\n", ptr[i].saldo, ptr[i].gols_pro, ptr[i].gols_contra);
    }
}

void RecebeEquipes(struct equipe *ptr, unsigned qnt_equipes)
{
    int i = 0;
    for (; i < qnt_equipes; i++)
    {
        scanf("%s", ptr[i].nome);
    }
}
