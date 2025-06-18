#ifndef COLA_H
#define COLA_H
#include "nodo.h"

struct Cola;
typedef struct Cola * ColaPtr;
ColaPtr crearCola(NodoPtr nodo);
NodoPtr getPrimero(ColaPtr cola);
void encolar(ColaPtr cola, NodoPtr nodo);
DatoPtr desencolar(ColaPtr cola);
void borrarCola(ColaPtr cola);


#endif