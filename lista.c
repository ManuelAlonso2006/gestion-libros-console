#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "nodo.h"


struct Lista{
    NodoPtr primerNodo;
};

ListaPtr crearLista(NodoPtr nodo){
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));
    lista->primerNodo = nodo;
    return lista;
}

NodoPtr obtenerPrimero(ListaPtr lista){
    return lista->primerNodo;
}

void agregarNodoPrincipio(ListaPtr lista, NodoPtr nodo){
    NodoPtr actual = lista->primerNodo;
    lista->primerNodo = nodo;
    setSiguiente(lista->primerNodo, actual);
}

void agregarNodoFinal(ListaPtr lista, NodoPtr nodo){
    NodoPtr actual = lista->primerNodo;
    while (getSiguiente(actual) != NULL){
        actual = getSiguiente(actual);
    }
    setSiguiente(actual, nodo);
}


void agregarNodoPosicion(ListaPtr lista, int posicion, NodoPtr nodo){
    if (posicion == contarElementos(lista)){
        agregarNodoFinal(lista, nodo);
        return;
    }
    if (posicion == 0){
        agregarNodoPrincipio(lista, nodo);
        return;
    }
    if (posicion < 0 || posicion > contarElementos(lista)){
        printf("POSICION NO VALIDA\n");
        return;
    }
    NodoPtr actual = lista->primerNodo;
    for (int i = 0; i < posicion - 1; i++){
        actual = getSiguiente(actual);
    }
    setSiguiente(nodo, getSiguiente(actual));
    setSiguiente(actual, nodo);
    
}

int contarElementos(ListaPtr lista){
    int elementos = 0;
    NodoPtr actual = lista->primerNodo;
    while (actual != NULL){
        elementos++;
        actual = getSiguiente(actual);
    }
    return elementos;
}

void mostrarListaGenerica(ListaPtr lista, void(*mostrarDato)(void * dato)){
    printf("LIBROS DISPONIBLES (cantidad de libros: %d): [\n", contarElementos(lista));
    NodoPtr actual = lista->primerNodo;
    int cont = 0;
    while (actual != NULL){
        printf("DATO %d: ", cont);
        mostrarDato(getDato(actual));
        actual = getSiguiente(actual);
        cont ++;
    }
    printf("\n]\n");
}

NodoPtr obtenerNodo(ListaPtr lista, int posicion){
    NodoPtr actual = lista->primerNodo;
    if (posicion == 0){
        return actual;
    }
    else{
        int contador = 0;
        while (contador < posicion && actual != NULL){
            actual = getSiguiente(actual);
            contador ++;
        }
        return actual;
    }
}

void ordenarListaGenerica(ListaPtr lista, int(*compararDatos)(void * dato1, void * dato2)){
    DatoPtr aux;
    NodoPtr actual;
    NodoPtr siguiente;
    int cantidad = contarElementos(lista);
    for (int i = 0; i < cantidad - 1; i++){
        actual = obtenerNodo(lista, i);
        for (int j = i + 1; j < cantidad; j++){
            siguiente = obtenerNodo(lista, j);
            if (compararDatos(getDato(actual), getDato(siguiente)) == 0){
                aux = getDato(actual);
                setDato(actual, getDato(siguiente));
                setDato(siguiente, aux);
            }

        }
    }
}

void buscarElementoEnLista(ListaPtr lista, int(*compararDatos)(void * dato1, void * dato2), DatoPtr datoBuscado){
    NodoPtr actual = lista->primerNodo;
    int posicion = 0;
    while (actual != NULL){
        if (compararDatos(datoBuscado, getDato(actual)) == 2){
            printf("EL DATO FUE ENCONTRADO EN LA POSICION %d\n", posicion);
            return;
        }
        actual = getSiguiente(actual);
        posicion++;
    }
    printf("EL DATO NO FUE ENCONTRADO\n");

}

void busquedaBinaria(ListaPtr lista, int(*compararDatos)(void * dato1, void * dato2), DatoPtr datoBuscado){
    int inicio = 0;
    int final = contarElementos(lista) - 1;
    int medio, posicion = 0;
    DatoPtr valorMedio;
    while (inicio <= final){
        medio = (inicio + final) / 2;
        valorMedio = obtenerNodo(lista, medio);
        if (compararDatos(getDato(valorMedio), datoBuscado) == 2){
            printf("EL DATO FUE ENCONTRADO EN LA POSICION %d\n", posicion);
            return;
        }
        else if (compararDatos(getDato(valorMedio), datoBuscado) == 1){
            inicio = medio + 1;
        }
        else{
            final = medio - 1;
        }
        posicion++;
    }
    printf("EL DATO NO FUE ENCONTRADO\n");

}

void borrarElemento(ListaPtr lista, int posicion){
    if (posicion < 0 || posicion > contarElementos(lista)){
        printf("POSICION NO VALIDA\n");
        return;
    }
    else if (posicion == 0){
        NodoPtr actual = lista->primerNodo;
        NodoPtr siguiente = getSiguiente(actual);
        lista->primerNodo = siguiente;
        free(actual);
        return;
    }
    else{
        NodoPtr actual = lista->primerNodo;
        NodoPtr siguiente = getSiguiente(actual);
        for (int i = 0; i < posicion - 1; i++){
            actual = siguiente;
            siguiente = getSiguiente(siguiente);
        }
        setSiguiente(actual, getSiguiente(siguiente));
        free(siguiente);
    }
}

void borrarLista(ListaPtr lista){
    NodoPtr actual = lista->primerNodo;
    NodoPtr siguiente;
    while (actual != NULL){
        siguiente = getSiguiente(actual);
        free(actual);
        actual = siguiente;
    }
    free(lista);   
}