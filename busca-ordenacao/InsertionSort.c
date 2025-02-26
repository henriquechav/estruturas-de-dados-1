// Implementação do algoritmo Insertion Sort em C.

void InsertionSort(int *v, int n)
{
    int i, j, chave;
    for (i = 1; i < n; i++)
    {
        chave = v[i];
        j = i-1;
        while (j >= 0 && v[j] >= chave)
        {
            v[j+1] = v[j];
            v[j] = chave;
            j--;
        }
    }
}
