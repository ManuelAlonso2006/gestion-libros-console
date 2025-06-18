#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "pila.h"
#include "biblioteca.h"
#include "nodo.h"
#include "lista.h"
#include "libro.h"


struct Biblioteca{
    char direccion[60];
    ListaPtr librosDisponibles;
    ColaPtr usuariosEnEspera;
    PilaPtr librosRecibidos;   
};


BibliotecaPtr crearBiblioteca(char direccion[], NodoPtr libro){
    BibliotecaPtr biblioteca = (BibliotecaPtr) malloc(sizeof(struct Biblioteca));
    strcpy(biblioteca->direccion, direccion);
    biblioteca->librosDisponibles = crearLista(libro);
    biblioteca->usuariosEnEspera = crearCola(NULL);
    biblioteca->librosRecibidos = crearPila(NULL);
    return biblioteca;
}


void agregarLibro(BibliotecaPtr biblioteca, NodoPtr libro){
    agregarNodoPrincipio(biblioteca->librosDisponibles, libro);
}


//RETORNA UN NODO DE LA LISTA DE LIBROS DISPONIBLES BUSCANDOLO POR SU ID
NodoPtr obtenerNodoLibro(BibliotecaPtr biblioteca, int id){
    NodoPtr actual = obtenerPrimero(biblioteca->librosDisponibles);
    while (actual != NULL){
        LibroPtr libro = (LibroPtr)getDato(actual);
        if (getId(libro) == id) {
            return actual;
        }
        actual = getSiguiente(actual);
    }
    return NULL;
}

//OBTIENE LA INFORMACION DEL LIBRO QUE SE ESTA DEVOLVIENDO Y LO INSERTA EN LA PILA DE LIBROS RECIBIDOS
void registrarDevolucion(BibliotecaPtr biblioteca, int idLibro, void(*mostrarLibro)(void * dato)){
    NodoPtr nodo = obtenerNodoLibro(biblioteca, idLibro);
    if (nodo == NULL) {
        printf("ERROR: NO SE ENCONTRO LIBRO CON ESE ID\n");
        return;
    }
    LibroPtr libro = (LibroPtr)(getDato(nodo));
    if (getEstado(libro) == 0){
        printf("ERROR: NO PUEDE DEVOLVER EL LIBRO POR YA ESTA DISPONIBLE\n");
        return;
    }
    NodoPtr nuevoNodo = crearNodo(libro);
    insertar(biblioteca->librosRecibidos, nuevoNodo);
    
    printf("DETALLES DEL LIBRO DEVUELTO: ");
    setEstado(libro, 0);
    mostrarLibro(libro);
    setEstado(libro, 1);
}


//AGARRA LA PILA DE LIBROS RECIBIDOS Y AL QUE ESTE PRIMERO LO REACOMODA, (LO SACA DE LA PILA Y SU ESTADO VUELVE A 0)
void reubicarLibro(BibliotecaPtr biblioteca, void(*mostrarLibro)(void * dato)){
    NodoPtr libro = eliminar(biblioteca->librosRecibidos);
    if (libro != NULL) {
        printf("LIBRO REUBICADO: ");
        setEstado((LibroPtr)getDato(libro), 0);
        mostrarLibro(getDato(libro));
    } else {
        printf("NO HAY LIBROS PARA REUBICAR.\n");
    }
}

//RECIBE A UN USUARIO Y LO AGREGA A LA COLA DE USUARIOS EN ESPERA;
void registrarSolicitud(BibliotecaPtr bilioteca, NodoPtr usuario, void(*mostrarUsuario)(void * dato)){
    encolar(bilioteca->usuariosEnEspera, usuario);
    printf("DATOS DEL USUARIO SOLICITANTE: ");
    mostrarUsuario(getDato(usuario));
}

//LE PRESTAMOS UN LIBRO AL USUARIO, EL LIBRO SE ELIJE ATRAVES DE SU ID
void procesarPrestamo(BibliotecaPtr biblioteca, int idLibro){
    //DESENCOLAMOS AL USUARIO
    desencolar(biblioteca->usuariosEnEspera);
    //OBTENEMOS EL NODO DEL LIBRO ATRAVES DEL ID
    NodoPtr libroNodo = obtenerNodoLibro(biblioteca, idLibro);
    if (libroNodo != NULL){
        //TRANSFORMAMOS EL NODO EN UN LIBRO PARA CAMBIAR EL ESTADO DE ESTE A 1
        LibroPtr libro = (LibroPtr)getDato(libroNodo);
        setEstado(libro, 1);
        printf("LIBRO OBTENIDO!! RECUERDA QUE DEBES DEVOLVERLO PRONTO\n");
    }
    else{
        printf("ERROR: NO SE ENCONTRO EL LIBRO SOLICITADO\n");
    }
}


void mostrarBiblioteca(BibliotecaPtr biblioteca, void(*mostrarLibros)(void * dato)){
    printf("BIBLIOTECA DE %s\n", biblioteca->direccion);
    mostrarListaGenerica(biblioteca->librosDisponibles, mostrarLibros);
}