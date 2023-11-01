#include <stdio.h>
#define MAX 110
void leer_d(int arr[], int *N);
void burble(int arr[], int N);
void intercambia(int *a, int *b);
void insercion(int arr[], int tam);
void seleccion(int arr[], int tam);
void quicksort(int arr[], int izq, int der);
int particion(int arr[], int izq, int der);
void imprimir(int arr[], int N);

int main()
{
    int N, arr[MAX];
    leer_d(arr, &N);
    quicksort(arr, 0, N - 1);
    imprimir(arr, N);
    return 0;
}

void leer_d(int arr[], int *N)
{
    scanf("%d", N);
    for (int i = 0; i < *N; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void quicksort(int arr[], int izq, int der)
{
    if (izq < der)
    {
        int pivote = particion(arr, izq, der);
        quicksort(arr, izq, pivote - 1);
        quicksort(arr, pivote + 1, der);
    }
}

int particion(int arr[], int izq, int der)
{
    int i = izq, j = der - 1, p = der;
    while (i <= j)
    {
        if (arr[i] > arr[p])
        {
            i++;
        }
        else if (arr[j] <= arr[p])
        {
            j--;
        }
        else if (arr[i] <= arr[p] && arr[j] > arr[p])
        {
            intercambia(&arr[i], &arr[j]);
            i++, j--;
        }
    }
    intercambia(&arr[i], &arr[p]);
    return i;
}

void intercambia(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void imprimir(int arr[], int N)
{
    puts("\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
}