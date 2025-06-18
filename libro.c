#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"


struct Libro{
    int id;
    char autor[30];
    char titulo[60];
    int estado;
};


LibroPtr crearLibro(int id, char autor[], char titulo[]){
    LibroPtr libro = (LibroPtr) malloc(sizeof(struct Libro));
    libro->id = id;
    strcpy(libro->autor, autor);
    strcpy(libro->titulo, titulo);
    libro->estado = 0;
    return libro;
}

int getId(LibroPtr libro){
    return libro->id;
}

int getEstado(LibroPtr libro){
    return libro->estado;
}

void setEstado(LibroPtr libro, int estado){
    libro->estado = estado;
}

void mostrarLibro(LibroPtr libro){
    if (libro->estado ==  0){
        printf("ID: %d, AUTOR: %s, TITULO: %s\n", libro->id, libro->autor, libro->titulo);
    }
    else{
        printf("LIBRO OCUPADO: %s\n", libro->titulo);
    }
}


void mostrarLibroGenerico(void * dato){
    LibroPtr libro = (LibroPtr)dato;
    mostrarLibro(libro);
}