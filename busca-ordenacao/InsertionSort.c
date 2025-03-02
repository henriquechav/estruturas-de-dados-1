/* Recebe um vetor v[0..n-1] com n >= 0 e o ordena de modo crescente. A 
 * complexidade de tempo deste algoritmo é, no pior caso, a mesma do Bubble 
 * Sort e do Selection Sort, ou seja, O(n²). Mas no melhor caso é 
 * consideravelmente mais eficiente: O(n). */
void InsertionSort(int v[], int n)
{
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] >= chave) {
            v[j+1] = v[j];
            v[j] = chave;
            j--;
        }
    }
}
