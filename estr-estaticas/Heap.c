/* Implementação de uma estrutura Heap em C. */
#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 10

struct tHeap
{
    int itens[TAMANHO];
    int qnt;
};

void IniciarHeap(struct tHeap *h)
{
    h->qnt = 0;
}

struct tHeap* CriarHeap(void)
{
    struct tHeap *heap = (struct tHeap*)malloc(sizeof(struct tHeap));
    if (heap != NULL)
        IniciaHeap(heap);
    else {
        printf("\nErro na alocação do heap!\n");
        exit(1);
    }
    return heap;
}

int LerItem(void)
{
    int it;
    printf("Informe o dado: ");
    scanf("%d", &it);
    return it;
}

int FilhoDir(int pai)
{
    return 2 * pai + 2;
}

int FilhoEsq(int pai)
{
    return 2 * pai + 1;
}

int Pai(int filho)
{
    return (int) (filho - 1) / 2;
}

int UltimoPai(struct tHeap h)
{
    return (int) (h.qnt / 2) - 1;
}

void Peneirar(struct tHeap *heap, int pai)
{
    int fEsq = FilhoEsq(pai), fDir = FilhoDir(pai);
    int maior, aux;

    if (fEsq < heap->qnt && heap->itens[fEsq] > heap->itens[pai])
        maior = fEsq;
    else
        maior = pai;

    if (fDir < heap->qnt && heap->itens[fDir] > heap->itens[maior])
        maior = fDir;

    if (maior != pai) {
        aux = heap->itens[pai];
        heap->itens[pai] = heap->itens[maior];
        heap->itens[maior] = aux;

        Peneirar(heap, maior);
    }
}

void ConstruirHeap(struct tHeap *heap)
{
    int i;
    for (i = UltimoPai(*heap); i >= 0; i--)
        Peneirar(heap, i);
}

void InserirHeap(struct tHeap *heap)
{
    int novo;
    int iNovo = heap->qnt;

    if (heap->qnt != TAMANHO) {
        novo = LerItem();
        heap->itens[iNovo] = novo;
        heap->qnt++;
        if (heap->qnt != 1 && heap->itens[Pai(iNovo)] < heap->itens[iNovo])
            ConstruirHeap(heap);
    } else {
        printf("\nHeap cheio!\n");
        system("pause");
    }
}

int RemoverMaxHeap(struct tHeap *heap)
{
    int aux;
    if (heap->qnt > 0) {
        aux = heap->itens[0];
        heap->itens[0] = heap->itens[heap->qnt-1];
        heap->itens[heap->qnt-1] = aux;
        heap->qnt--;
        Peneirar(heap, 0);
        printf("\nItem máximo removido: %d\n", aux);
        return aux;
    } else {
        printf("\nHeap vazio!!!\n");
    }
    system("pause");
    return NULL;
}
