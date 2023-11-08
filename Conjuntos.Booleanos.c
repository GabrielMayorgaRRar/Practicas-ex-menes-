#include <stdio.h>
#include <stdbool.h>
#define MAX 100
// Declarar

typedef struct
{
    bool elementos[MAX];
    int tam;
} TConjuntoB;

void ini_conjunto(TConjuntoB *c)
{
    for (int i = 0; i < MAX; i++)
    {
        c->elementos[i] = false;
    }
    c->tam = 0;
}

bool agregar(TConjuntoB *c, int dato)
{
    if (dato < 0 || dato > MAX)
    {
        return false;
    }
    if (c->elementos[dato] == true)
    {
        return false;
    }
    c->elementos[dato] = true;
    c->tam++;
    return true;
}

bool eliminar(TConjuntoB *c, int dato)
{
    if (dato < 0 || dato > MAX)
    {
        return false;
    }
    if (c->elementos[dato] == false)
    {
        return false;
    }
    c->elementos[dato] = false;
    c->tam--;
    return true;
}

bool buscar(TConjuntoB c, int dato)
{
    if (dato < 0 || dato >= MAX)
    {
        return false;
    }
    return c.elementos[dato];
}

void imprimir(TConjuntoB conjunto)
{
    printf("Elementos del conjunto:\n");
    for (int i = 0; i < MAX; i++)
    {
        if (conjunto.elementos[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}