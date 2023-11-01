#include <stdio.h>
#include <string.h>
#define MAX 150

void funcion_para_todo();
void leer(int *N, char Nombre[MAX][MAX]);
void imprimir(char Nombre[MAX][MAX], int N);

int main()
{
    funcion_para_todo();
    return 0;
}

void funcion_para_todo()
{
    int N;
    char Nombre[MAX][MAX];
    leer(&N, Nombre);
}

void leer(int *N, char Nombre[MAX][MAX])
{
    scanf("%d", N);
    for (int i = 0; i < *N; i++)
    {
        scanf(" %[^\n]", Nombre[i]);
        getchar();
        if(strcmp(Nombre[i], "Coca") == 0){
            printf("si?");
        }
    }


}