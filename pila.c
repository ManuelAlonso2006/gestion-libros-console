#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "pila.h"

struct Pila{
    NodoPtr ultimo;
};

PilaPtr crearPila(NodoPtr nodo){
    PilaPtr pila = (PilaPtr) malloc(sizeof(struct Pila));
    pila->ultimo = nodo;
    return pila;
}

void insertar(PilaPtr pila, NodoPtr nodo){
    NodoPtr actual = pila->ultimo;
    pila->ultimo = nodo;
    setSiguiente(nodo, actual);
}

NodoPtr eliminar(PilaPtr pila){
    if (pila->ultimo != NULL) {
        NodoPtr actual = pila->ultimo;
        pila->ultimo = getSiguiente(actual);
        return actual;
    }
    return NULL;
}

NodoPtr getUltimo(PilaPtr pila){
    if (pila->ultimo != NULL){
        return pila->ultimo;
    }
}

void borrarPila(PilaPtr pila){
    NodoPtr actual = pila->ultimo;
    NodoPtr siguiente;
    while (actual != NULL){
        siguiente = getSiguiente(actual);
        free(actual);
        actual = siguiente;
    }
    free(pila);
}
