/* Recebe um vetor v[0..n-1] com n >= 0 e o ordena de modo crescente. Esta 
 * função tem complexidade de tempo, no pior e melhor caso, O(n²). */
void BubbleSort(int v[], int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j+1]) {
                aux = v[j+1];
                v[j+1] = v[j];
                v[j] = aux;
            }
        }
    }
}
