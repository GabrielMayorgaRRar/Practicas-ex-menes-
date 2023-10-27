#include <stdio.h>
#include <stdbool.h>

void pedir(int *N);
void rellenar_arreglo(int arr[], int N);
void pedir2(int *N2);
void rellenar_arreglo2(int arr[], int N, int arr2[], int N2);
bool busqueda_binaria(int arr[], int inicio, int fin, int buscar, int *pos);
void imprimir(int arr2[], int N2);

int main(int argc, char *argv[])
{
    int N;
    pedir(&N);
    int arr[N];
    rellenar_arreglo(arr, N);
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

void pedir2(int *N2)
{
    scanf("%d", N2);
}

void rellenar_arreglo2(int arr[], int N, int arr2[], int N2)
{
    int pos = 0;
    for (int i = 0; i < N2; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i <= N2; i++)
    {
        if (!busqueda_binaria(arr, 0, N - 1, arr2[i], &pos))
        {
            arr2[i] = 0;
        }
        else
        {
            arr2[i] = pos;
        }
    }
}

bool busqueda_binaria(int arr[], int inicio, int fin, int buscar, int *pos)
{
    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == buscar)
        {
            (*pos) = medio + 1;
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
    printf("\n");
    for (int i = 0; i < N2; i++)
    {
        printf("%d ", arr2[i]);
    }
}