#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef int TDato;
typedef struct
{
    TDato datos[MAX];
    int tam;
} TConjunto;

bool eliminar(TConjunto *c, TDato dato);
int buscar(TConjunto c, int inicio, int fin, TDato dato);
bool agregar(TConjunto *c, TDato dato);
bool conjunto_esta_lleno(TConjunto c);
bool conjunto_esta_vacio(TConjunto c);
void inicializar_conjunto(TConjunto *c);

int main()
{
    TConjunto conjunto;
    inicializar_conjunto(&conjunto);
    int N;
    printf("Cuantas Cosas quieres hacer?");
    scanf("%d", &N);
    char Opcion[MAX][MAX];
    for (int i = 0; i < N; i++)
    {
        printf("Que opcion quieres? :");
        scanf(" %[^\n]", Opcion[i]);
        getchar();
        if (strcmp(Opcion[i], "Agregar") == 0)
        {
            TDato valor;
            printf("Introduce el valor : ");
            scanf("%d", &valor);
            bool exito = agregar(&conjunto, valor);
            if (exito)
            {
                printf("Valor %d agregado al conjunto.\n", valor);
            }
            else
            {
                printf("No se pudo agregar el valor al conjunto.\n");
            }
        }
        else if (strcmp(Opcion[i], "Eliminar") == 0)
        {
            TDato valor;
            printf("Introduce el valor : ");
            scanf("%d", &valor);
            bool exito = eliminar(&conjunto, valor);
            if (exito)
            {
                printf("Valor %d eliminado del conjunto.\n", valor);
            }
            else
            {
                printf("El valor %d no existe en el conjunto.\n", valor);
            }
        }
        else if (strcmp(Opcion[i], "Buscar") == 0)
        {
            TDato valor;
            printf("Introduce el valor : ");
            scanf("%d", &valor);
            int pos = buscar(conjunto, 0, conjunto.tam - 1, valor);
            if (pos != -1)
            {
                printf("Valor %d encontrado en la posición %d del conjunto.\n", valor, pos);
            }
            else
            {
                printf("El valor %d no existe en el conjunto.\n", valor);
            }
        }
        else if (strcmp(Opcion[i], "Imprimir") == 0)
        {
            if (conjunto_esta_vacio(conjunto))
            {
                printf("El conjunto está vacío.\n");
            }
            else
            {
                printf("Elementos del conjunto:\n");
                for (int j = 0; j < conjunto.tam; j++)
                {
                    printf("%d ", conjunto.datos[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

void inicializar_conjunto(TConjunto *c)
{
    c->tam = 0;
}
bool conjunto_esta_vacio(TConjunto c)
{
    return c.tam == 0;
}
bool conjunto_esta_lleno(TConjunto c)
{
    return c.tam == MAX;
}

bool agregar(TConjunto *c, TDato dato)
{
    if (conjunto_esta_lleno(*c))
    {
        return false;
    }

    
    for (int i = 0; i < c->tam; i++)
    {
        if (c->datos[i] == dato)
        {
            return false; 
        }
    }

    
    int i;
    for (i = c->tam; i > 0 && c->datos[i - 1] > dato; i--)
    {
        c->datos[i] = c->datos[i - 1];
    }
    
    c->datos[i] = dato;
    c->tam++;

    return true;
}


bool eliminar(TConjunto *c, TDato dato)
{
    int pos = buscar(*c, 0, c->tam - 1, dato);
    if (pos == -1)
    {
        return false;
    }

    for (int i = pos; i < c->tam - 1; i++)
    {
        c->datos[i] = c->datos[i + 1];
    }

    c->tam--;

    return true;
}

int buscar(TConjunto c, int inicio, int fin, TDato dato)
{
    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;
        if (c.datos[medio] == dato)
        {
            return medio;
        }
        else if (c.datos[medio] < dato) 
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }
    return -1;
}