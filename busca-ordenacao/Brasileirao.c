// Solução para o problema 96. (Ainda considerado errado pelo juiz BOCA.)
#include <stdio.h>
#include <stdlib.h>

/* Armazena dados de cada equipe do campeonato. */
struct equipe 
{
    char nome[101];
    unsigned pontos, vitorias, empates, derrotas;
    unsigned saldo, gols_pro, gols_contra;
};

/* Protótipos de funções. */
void RecebeEquipes(struct equipe*, unsigned);
void RecebePartidas(struct equipe*, unsigned);
void OrdenaEquipes(struct equipe*, unsigned);
void ExibeEquipes(struct equipe*, unsigned);

void main(void)
{
    /* Inicialização do vetor de equipes. */
    unsigned qnt_equipes;
    scanf("%u", &qnt_equipes);
    struct equipe *equipes;
    equipes = (struct equipe*)malloc(qnt_equipes*sizeof(struct equipe));
    
    /* Inicialização dos valores no registro de cada equipe para 0. */
    int i;
    for (i = 0; i < qnt_equipes; i++) {
        equipes[i].pontos = 0; equipes[i].vitorias = 0;
        equipes[i].empates = 0; equipes[i].derrotas = 0;
        equipes[i].saldo = 0; equipes[i].gols_pro = 0;
        equipes[i].gols_contra = 0;
    }

    /* Realiza procedimento. */
    RecebeEquipes(equipes, qnt_equipes);
    RecebePartidas(equipes, qnt_equipes);
    OrdenaEquipes(equipes, qnt_equipes);
    ExibeEquipes(equipes, qnt_equipes);

    /* Libera memória alocada. */
    free(equipes);
}

/* Ordena as equipes segundo seus pontos, com número de vitórias, saldo de gols
   e gols pró como critérios de desempate. Faz isso aos moldes do algoritmo 
   Bubble Sort. */
void 
OrdenaEquipes(struct equipe *e, unsigned qnt_equipes)
{
    struct equipe aux;
    int i, j;
    for (i = 0; i < qnt_equipes-1; i++) {
        for (j = 0; j < qnt_equipes-i-1; j++) {
            /* Condições para haver a troca de posições entre equipes. */
            if (   /* critério principal */
                   (e[j].pontos < e[j+1].pontos)

                   /* critério secundário */
                || (   e[j].pontos   == e[j+1].pontos 
                    && e[j].vitorias <  e[j+1].vitorias)

                   /* critério terciário */
                || (   e[j].pontos   == e[j+1].pontos 
                    && e[j].vitorias == e[j+1].vitorias 
                    && e[j].saldo    <  e[j+1].saldo)

                   /* critério último */
                || (   e[j].pontos   == e[j+1].pontos 
                    && e[j].vitorias == e[j+1].vitorias 
                    && e[j].saldo    == e[j+1].saldo 
                    && e[j].gols_pro <  e[j+1].gols_pro)
            ) 
            { /* troca posições */ 
                aux = e[j];
                e[j] = e[j+1];
                e[j+1] = aux;
            } 
        }
    }
}

/* Lê do usuário todas as partidas do campeonato e registra as estatísticas
   de cada equipe participante. */
void 
RecebePartidas(struct equipe *e, unsigned qnt_equipes)
{
    /* Índices para mandante (m) e visitante (v). */
    int m, v; 
    unsigned m_gols, v_gols;
    for (m = 0; m < qnt_equipes; m++) {
        for (v = 0; v < qnt_equipes; v++) {
            if (m == v) continue; /* pula índices iguais */

            /* Lê e registra os dados. */
            scanf("%*s %u x %u %*s", &m_gols, &v_gols);
            e[m].gols_pro += m_gols; e[m].gols_contra += v_gols;
            e[v].gols_pro += v_gols; e[v].gols_contra += m_gols;
            
            /* Casos de vitórias, empates e derrotas. */
            if (m_gols == v_gols) {
                e[m].empates++; e[m].pontos++;
                e[v].empates++; e[v].pontos++;
            } else if (m_gols > v_gols) {
                e[m].vitorias++; e[m].pontos += 3;
                e[v].derrotas++;
            } else {
                e[m].derrotas++;
                e[v].vitorias++; e[v].pontos += 3;
            }
        }
    }

    /* Depois de ter os dados, calcula o saldo de gols de cada equipe. */
    int i;
    for (i = 0; i < qnt_equipes; i++) 
        e[i].saldo = e[i].gols_pro - e[i].gols_contra;
}

/* Formata os dados processados e os exibe no terminal. */
void 
ExibeEquipes(struct equipe *e, unsigned qnt_equipes)
{
    printf("CAMPEAO: %s\n", e[0].nome);
    printf("VICE-CAMPEAO: %s\n", e[1].nome);
    
    int i;
    printf("REBAIXADOS: ");
    for (i = qnt_equipes - 1; i >= qnt_equipes - 4; i--) {
        printf("%s", e[i].nome);
        if (i > qnt_equipes - 3) {
            printf(", ");
        } else if (i == qnt_equipes - 3) {
            printf(" e ");
        } else {
            putchar('\n');
        }
    }

    printf("TABELA FINAL:\n");
    for (i = 0; i < qnt_equipes; i++) {
        printf("%s %u ", e[i].nome, e[i].pontos); 
        printf("%u %u %u ", e[i].vitorias, e[i].empates, e[i].derrotas);
        printf("%d %u %u\n", e[i].saldo, e[i].gols_pro, e[i].gols_contra);
    }
}

/* Lê do usuário o nome de cada equipe. */
void 
RecebeEquipes(struct equipe *equipes, unsigned qnt_equipes)
{
    int i;
    for (i = 0; i < qnt_equipes; i++) {
        scanf("%s", equipes[i].nome);
    }
}
