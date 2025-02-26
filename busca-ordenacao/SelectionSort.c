// Implementação do algoritmo Selection Sort em C.

void SelectionSort(int *v, int n)
{
    int i, j, aux, iMin;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1, iMin = i; j < n; j++)
        {
            if (v[j] < v[iMin])
                iMin = j;
        }
        aux = v[iMin];
        v[iMin] = v[i];
        v[i] = aux;
    }
}
