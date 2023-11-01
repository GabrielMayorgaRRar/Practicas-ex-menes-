#include <stdio.h>
#include <string.h>
#define MAX 150

void funcion_para_todo();
void leer(int *N, char Nombre[MAX][MAX]);
void burbuja(char Nombre[MAX][MAX], int N);
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
    burbuja(Nombre,N);
    imprimir(Nombre,N);
}

void leer(int *N, char Nombre[MAX][MAX])
{
    scanf("%d", N);
    for (int i = 0; i < *N; i++)
    {
        scanf(" %[^\n]", Nombre[i]);
        getchar();
    }
}

void burbuja(char Nombre[MAX][MAX], int N){
    for(int i=0; i<N-1; i++){
        for(int j=0; j<N-i-1; j++){
            if(strcmp(Nombre[j], Nombre[j+1]) < 0){
                char aux[MAX]; 
                strcpy(aux, Nombre[j]);
                strcpy(Nombre[j], Nombre[j+1]);
                strcpy(Nombre[j+1], aux);
            }
        }
    }
}

void imprimir(char Nombre[MAX][MAX], int N){
    for(int i=0; i<N; i++){
        printf("%s \n", Nombre[i]);
    }
}