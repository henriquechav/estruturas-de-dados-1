/* Recebe um vetor v[0..n-1] com n >= 0 e o ordena de modo crescente. Como o 
 * Bubble Sort, esta função tem complexidade de tempo, no pior e no melhor 
 * caso, O(n²), porém, sensivelmente mais eficiente por realizar menor número 
 * de trocas. */
void SelectionSort(int v[], int n)
{
    int i, j, aux, iMin;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1, iMin = i; j < n; j++)
            if (v[j] < v[iMin]) 
                iMin = j;
        aux = v[i];
        v[i] = v[iMin];
        v[iMin] = aux;
    }
}
