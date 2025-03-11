/* Solução para o problema 105. */
#include <stdio.h>
#include <stdlib.h>

void scanVetor(int[], int);
void printVetor(int[], int);
void construirHeap(int[], int);
void peneirar(int[], int, int);
/* Funções auxiliares. */
int filhoDir(int);
int filhoEsq(int);
int ultimoPai(int);

int main(void)
{
    int n, *v;
    scanf("%d", &n);

    while (n != 0) {
        v = (int*)malloc(n*sizeof(int));
        scanVetor(v, n);
        construirHeap(v, n);
        printVetor(v, n);
        free(v);
        scanf("%d", &n);
    }
    
    return 0;
}

/* Recebe um heap h[0..n-1], seu tamanho n e o índice p de um nó pai. Aplica a
 * propriedade estrutural à subárvore partindo do nó de índice p. */
void peneirar(int h[], int n, int p)
{
    int aux, maior = p;

    if (filhoDir(p) < n && h[filhoDir(p)] > h[maior])
        maior = filhoDir(p);
    if (filhoEsq(p) < n && h[filhoEsq(p)] > h[maior])
        maior = filhoEsq(p);

    if (maior != p) {
        aux = h[maior];
        h[maior] = h[p];
        h[p] = aux;
        peneirar(h, n, maior);
    }
}

/* Recebe um vetor v[0..n-1] e seu tamanho n e o transforma em um heap. */
void construirHeap(int v[], int n)
{
    int i;
    for (i = ultimoPai(n); i >= 0; i--)
        peneirar(v, n, i);
}

/* Recebe um vetor v[0..n-1] e seu tamanho n e exibe seus valores. */
void printVetor(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", v[i], i < n - 1 ? " " : "\n");
}

/* Recebe um vetor v[0..n-1] e seu tamanho n e lê seus valores do usuário. */
void scanVetor(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

/* Funções auxiliares. */
int filhoEsq(int pai) {
    return 2 * pai + 1;
}

int filhoDir(int pai) {
    return 2 * pai + 2;
}

int ultimoPai(int n) {
    return (n / 2) - 1;
}
