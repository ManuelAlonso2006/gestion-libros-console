#ifndef PILA_H
#define PILA_H
#include "nodo.h"

struct Pila;
typedef struct Pila * PilaPtr;
PilaPtr crearPila(NodoPtr nodo);
void insertar(PilaPtr pila, NodoPtr nodo);
NodoPtr eliminar(PilaPtr pila);
NodoPtr getUltimo(PilaPtr pila);
void borrarPila(PilaPtr pila);


#endif