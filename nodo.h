#ifndef NODO_H
#define NODO_H

struct Nodo;
typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;
NodoPtr crearNodo(DatoPtr dato);
DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);
void setDato(NodoPtr nodo, DatoPtr dato);
void setSiguiente(NodoPtr nodo, NodoPtr siguiente);


#endif