#include <stdio.h>

#define MAX 50
typedef struct Dato
{
    int Dato[MAX];
} TDato;

void od(int *N, TDato N_D_E[MAX]);
void ordenar(TDato N_D_E[MAX], int N);
void imprimir(TDato N_D_E[MAX], int N);
int main()
{
    int N;
    TDato N_D_E[MAX];
    od(&N, N_D_E);
    ordenar(N_D_E, N);
    imprimir(N_D_E, N);
}

void od(int *N, TDato N_D_E[MAX])
{
    scanf("%d", N);
    for (int i = 0; i < *N; i++)
    {
        for(int j=0; j<2; j++){
            scanf("%d", &N_D_E[i].Dato[j]);
        }
        
    }
}

void ordenar(TDato N_D_E[MAX], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (N_D_E[j].Dato[0] < N_D_E[j + 1].Dato[0])
            {
                TDato aux = N_D_E[j];
                N_D_E[j] = N_D_E[j+1];
                N_D_E[j + 1] = aux;
            }
        }
    }
}

void imprimir(TDato N_D_E[MAX], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<2; j++){
            printf("%d ", N_D_E[i].Dato[j]);
        }
        puts("\n");
    }
}