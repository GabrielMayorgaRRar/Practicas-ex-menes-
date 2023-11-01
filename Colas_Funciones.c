#include <stdbool.h>
#define MAX 100
// Declarar
typedef int TDato;
typedef struct
{
    TDato datos[MAX];
    int primero;
    int ultimo;
} TCola;

// Inicializar
void ini_cola(TCola *cola)
{
    cola->primero = 0;
    cola->ultimo = 0;
}

// Comprobar que este vacia
bool cola_esta_vacia(TCola cola)
{
    return (cola.primero == cola.ultimo);
}

// Comprobar si esta llena.
bool cola_esta_llena(TCola cola)
{
    return ((cola.ultimo - cola.primero) == MAX - 1);
}

// Encolar
bool encolar(TCola *cola, TDato dato)
{
    if (cola_esta_llena(*cola))
    {
        return false;
    }
    cola->datos[cola->ultimo] = dato;
    cola->ultimo++;
    return true;
}

// Desencolar.
bool desencolar(TCola *cola, TDato *dato)
{
    if (cola_esta_vacia(*cola))
    {
        return false;
    }
    *dato = cola->datos[cola->primero];
    cola->primero++;
    return true;
}
