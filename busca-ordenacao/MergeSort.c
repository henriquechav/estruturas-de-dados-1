// Implementação do algoritmo Merge Sort em C.

void MergeSort(int *v, int e, int d)
{
    int meio;
    if (e < d)
    {
        meio = (e + d) / 2;
        MergeSort(v, e, meio);
        MergeSort(v, meio+1, d);
        Intercala(v, e, meio+1, d);
    }
}

/* Necessário implementar o Intercala(). */
void Intercala(int *v, int e, int meio, int d)
{

}
