#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#include "cola.h"

struct Cola{
    NodoPtr primero;
};


ColaPtr crearCola(NodoPtr nodo){
    ColaPtr cola = (ColaPtr) malloc(sizeof(struct Cola));
    cola->primero = nodo;
    return cola;
}

NodoPtr getPrimero(ColaPtr cola){
    if (cola->primero != NULL){
        return cola->primero;
    }
    return NULL;
}

void encolar(ColaPtr cola, NodoPtr nodo){
    NodoPtr actual = cola->primero;
    while (getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }
    setSiguiente(actual, nodo);
    
    
}

DatoPtr desencolar(ColaPtr cola){
    if (cola->primero != NULL){
        NodoPtr primero = cola->primero;
        NodoPtr siguiente = getSiguiente(primero);
        cola->primero = siguiente;
        DatoPtr dato = getDato(primero);
        free(primero);
        return dato;
    }
    return NULL;
}

void borrarCola(ColaPtr cola){
    if (cola->primero != NULL){
        NodoPtr actual = cola->primero;
        NodoPtr siguiente;
        while (actual != NULL){
            siguiente = getSiguiente(actual);
            free(actual);
            actual = siguiente;
        }
    }
    free(cola);
}