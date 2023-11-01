#include <stdio.h>
#include <stdbool.h>

void pedir(int *N);
void rellenar_arreglo(int arr[], int N);
void pedir2(int *N2);
void quirksort(int arr[], int izq, int der);
int particion(int arr[], int izq, int der);
void intercambia(int *a, int *b);
void rellenar_arreglo2(int arr[], int N, int arr2[], int N2);
bool busqueda_binaria(int arr[], int inicio, int fin, int buscar);
void imprimir(int arr2[], int N2);

int main(int argc, char *argv[])
{
    int N;
    pedir(&N);
    int arr[N];
    rellenar_arreglo(arr, N);
    quirksort(arr, 0, N - 1);
    int N2;
    pedir2(&N2);
    int arr2[N2];
    rellenar_arreglo2(arr, N, arr2, N2);
    imprimir(arr2, N2);
}

void pedir(int *N)
{
    scanf("%d", N);
}

void rellenar_arreglo(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void quirksort(int arr[], int izq, int der)
{
    if (izq < der)
    {
        int pivote = particion(arr, izq, der);
        quirksort(arr, izq, pivote - 1);
        quirksort(arr, pivote + 1, der);
    }
}

int particion(int arr[], int izq, int der)
{
    int i = izq, j = der - 1, p = der;
    while (i <= j)
    {
        if (arr[i] < arr[p])
        {
            i++;
        }
        else if (arr[j] >= arr[p])
        {
            j--;
        }
        else if (arr[i] >= arr[p] && arr[j] < arr[p])
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

void pedir2(int *N2)
{
    scanf("%d", N2);
}

void rellenar_arreglo2(int arr[], int N, int arr2[], int N2)
{
    for (int i = 0; i < N2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i <= N2; i++)
    {
        if (!busqueda_binaria(arr, 0, N - 1, arr2[i]))
        {
            arr2[i] = 0;
        }
        else
        {
            arr2[i] = 1;
        }
    }
}

bool busqueda_binaria(int arr[], int inicio, int fin, int buscar)
{
    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == buscar)
        {
            return true;
        }
        else if (arr[medio] > buscar)
        {
            fin = medio - 1;
        }
        else
        {
            inicio = medio + 1;
        }
    }
    return false;
}

void imprimir(int arr2[], int N2)
{
    for (int i = 0; i < N2; i++)
    {
        printf("%d ", arr2[i]);
    }
}