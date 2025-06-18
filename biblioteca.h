#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "nodo.h"


struct Biblioteca;
typedef struct Biblioteca * BibliotecaPtr;
BibliotecaPtr crearBiblioteca(char direccion[], NodoPtr libro);
void agregarLibro(BibliotecaPtr biblioteca, NodoPtr libro);
NodoPtr obtenerNodoLibro(BibliotecaPtr biblioteca, int id);
void registrarDevolucion(BibliotecaPtr biblioteca, int idLibro, void(*mostrarLibro)(void * dato));
void registrarSolicitud(BibliotecaPtr bilioteca, NodoPtr usuario, void(*mostrarUsuario)(void * dato));
void procesarPrestamo(BibliotecaPtr biblioteca, int idLibro);
void reubicarLibro(BibliotecaPtr biblioteca, void(*mostrarLibro)(void * dato));
void mostrarBiblioteca(BibliotecaPtr biblioteca, void(*mostrarLibros)(void * dato));

#endif