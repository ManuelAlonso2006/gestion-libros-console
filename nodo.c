#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"

struct Nodo{
    DatoPtr dato;
    NodoPtr siguiente;
};

NodoPtr crearNodo(DatoPtr dato){
    NodoPtr nodo = (NodoPtr) malloc(sizeof(struct Nodo));
    nodo->dato = dato;
    nodo->siguiente = NULL;
    return nodo;
}

DatoPtr getDato(NodoPtr nodo){
    if (nodo != NULL){
        return nodo->dato;
    }
    return NULL;
}

NodoPtr getSiguiente(NodoPtr nodo){
    if (nodo != NULL){
        return nodo->siguiente;
    }
    return NULL;
}

void setDato(NodoPtr nodo, DatoPtr dato){
    if (nodo != NULL){
        nodo->dato = dato;
    }
}

void setSiguiente(NodoPtr nodo, NodoPtr siguiente){
    if (nodo != NULL){
        nodo->siguiente = siguiente;
    }
}