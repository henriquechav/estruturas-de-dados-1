// Implementação do algoritmo Quick Sort em C.

void QuickSort(int *v, int e, int d)
{
    int p;
    if (e < d)
    {
        p = Particiona(v, e, d);
        QuickSort(v, e, p-1);
        QuickSort(v, p+1, d);
    }
}

/* Necessário implementar o Particiona(). */
int Particiona(int *v, int e, int d)
{
    
}
