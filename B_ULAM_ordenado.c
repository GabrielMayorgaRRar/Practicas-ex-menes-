#include <stdio.h>

#define MAX 1000005

void leer(int *N, int A[], int *i);
void quirksort(int A[], int izq, int der);
int particion(int A[], int izq, int der);
void intercambia(int *a, int *b);
void imprimir(int A[], int i);

int main()
{
    int N, A[MAX], i = 1;
    leer(&N, A, &i);
    quirksort(A, 0, i - 1);
    imprimir(A, i);
    return 0;
}

void leer(int *N, int A[], int *i)
{
    scanf("%d", N);
    A[0] = *N;
    while (*N > 1)
    {
        if (*N % 2 == 0)
        {
            *N = *N / 2;
            A[(*i)++] = *N;
        }
        else
        {
            *N = (*N * 3) + 1;
            A[(*i)++] = *N;
        }
    }
}

void quirksort(int A[], int izq, int der)
{
    if (izq < der)
    {
        int pivote = particion(A, izq, der);
        quirksort(A, izq, pivote - 1);
        quirksort(A, pivote + 1, der);
    }
}

int particion(int A[], int izq, int der)
{
    int i = izq, j = der - 1, p = der;
    while (i <= j)
    {
        if (A[i] < A[p])
        {
            i++;
        }
        else if (A[j] >= A[p])
        {
            j--;
        }
        else if (A[i] >= A[p] && A[j] < A[p])
        {
            intercambia(&A[i], &A[j]);
            i++, j--;
        }
    }
    intercambia(&A[i], &A[p]);
        return i;
}

void intercambia(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void imprimir(int A[], int i)
{
    for (int c = 0; c < i; c++)
    {
        printf("%d ", A[c]);
    }
}
