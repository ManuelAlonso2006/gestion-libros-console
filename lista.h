#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"


struct Lista;
typedef struct Lista * ListaPtr;

ListaPtr crearLista(NodoPtr nodo);
NodoPtr obtenerPrimero(ListaPtr lista);
void agregarNodoPrincipio(ListaPtr lista, NodoPtr nodo);
void agregarNodoFinal(ListaPtr lista, NodoPtr nodo);
void agregarNodoPosicion(ListaPtr lista, int posicion, NodoPtr nodo);
int contarElementos(ListaPtr lista);
void mostrarListaGenerica(ListaPtr lista, void(*mostrarDato)(void * dato));
void ordenarListaGenerica(ListaPtr lista, int(*compararDatos)(void * dato1, void * dato2));
void buscarElementoEnLista(ListaPtr lista, int(*compararDatos)(void * dato1, void * dato2), DatoPtr datoBuscado);
void busquedaBinaria(ListaPtr lista, int(*compararDatos)(void * dato1, void * dato2), DatoPtr datoBuscado);
void borrarElemento(ListaPtr lista, int posicion);
void borrarLista(ListaPtr lista);

#endif