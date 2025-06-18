#ifndef LIBRO_H
#define LIBRO_H

struct Libro;
typedef struct Libro * LibroPtr;
LibroPtr crearLibro(int id, char autor[], char titulo[]);
int getId(LibroPtr libro);
int getEstado(LibroPtr libro);
void setEstado(LibroPtr libro, int estado);
void mostrarLibro(LibroPtr libro);
void mostrarLibroGenerico(void * dato);

#endif