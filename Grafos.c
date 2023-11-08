#include <stdio.h>
#include <stdbool.h>
#define DIRIGIDO 1
#define NO_DIRIGIDO 0
#define MAX_VERTICES 101
// Declarar

typedef struct grafo
{
    int tipo;
    int matriz[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
    bool vertices[MAX_VERTICES];
} TGrafo;

inicializar_grafo(TGrafo *g, int tipo)
{
    g->tipo = tipo;
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        for (int j = 0; j < MAX_VERTICES; j++)
        {
            g->matriz[i][j] = 0;
        }
        g->vertices[i] = false;
    }
    g->num_vertices = 0;
}

void agrega_vertice(TGrafo *g, int v)
{
    if (v >= 0 && v < MAX_VERTICES && !g->vertices[v])
    {
        g->vertices[v] = true;
        g->num_vertices++;
    }
}

void agrega_arista(TGrafo *g, int V1, int V2)
{
    if (g->vertices[V1] == false)
    {
        agrega_vertice(g, V1);
    }
    if (g->vertices[V2] == false)
    {
        agrega_vertice(g, V2);
    }
    g->matriz[V1][V2] = 1;
    if (g->tipo == NO_DIRIGIDO)
    {
        g->matriz[V2][V1] = 1;
    }
}

void eliminar_vertice(TGrafo *g, int V)
{
    if (V >= 0 && V < MAX_VERTICES && g->vertices[V] == true)
    {
        g->num_vertices--;
        g->vertices[V] = false;
        for (int i = 0; i < MAX_VERTICES; i++)
        {
            g->matriz[V][i] = 0;
            g->matriz[i][V] = 0;
        }
    }
}

void eliminar_arista(TGrafo *g, int V1, int V2)
{
    if (V1 >= 0 && V1 < MAX_VERTICES && V2 >= 0 && V2 < MAX_VERTICES && g->vertices[V1] && g->vertices[V2])
    {
        g->matriz[V1][V2] = 0;
        if (g->tipo == NO_DIRIGIDO)
        {
            g->matriz[V2][V1] = 0;
        }
    }
}

void imprimir_grafo(TGrafo *g)
{
    printf("Matriz de adyacencia:\n");
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        if (g->vertices[i])
        {
            for (int j = 0; j < MAX_VERTICES; j++)
            {
                if (g->vertices[j])
                {
                    printf("%d ", g->matriz[i][j]);
                }
            }
            printf("\n");
        }
    }
}

int buscar_vertice(TGrafo *g, int V)
{
    if (V >= 0 && V < MAX_VERTICES && g->vertices[V])
    {
        return V;
    }
    return -1; // Si no se encuentra el vértice, se devuelve -1.
}