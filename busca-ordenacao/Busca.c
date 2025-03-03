/* O seguinte programa foi tirado do livro Algoritmos em linguagem C do 
 * professor Paulo Feofiloff. Trata-se de uma busca simples que serve para
 * ilustrar os princípios de corretude, eficiência e elegância, da programação
 * de algoritmos. */

/* ------------------------------------------------------------------------ */

/* Esta função recebe um número x e um vetor v[0..n-1] com n >= 0 e devolve k 
 * no intervalo 0..n-1 tal que v[k] = x. Se tal k não existe, devolve -1. */
int Busca(int x, int v[], int n)
{
    int k;
    k = n - 1;
    while (k >= 0 && v[k] != x)
        k -= 1;
    return k;
}

/* Versão recursiva. */
int BuscaR(int x, int v[], int n)
{
    if (n == 0) return -1;
    if (x == v[n-1]) return n - 1;
    return BuscaR(x, v, n - 1);
}
