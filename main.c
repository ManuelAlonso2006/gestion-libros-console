#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "usuario.h"
#include "nodo.h"
#include "libro.h"
#include "biblioteca.h"


/*El programa deberá administrar como mínimo 3 estructuras propias,
bajo el paradigma de TDA.
El programa deberá utilizar por lo menos una pila void para almacenar 
libros devueltos recientemente y una cola void para gestionar solicitudes de préstamo.
El ejercicio es libre, a modo de ejemplo, Un Sistema de Biblioteca
tiene una cola de Usuarios esperando libros y una pila de Libros Recibidos.
Con el menú sí o sí se deberá poder apilar (registrar devolución) 
y desapilar (reubicar libro), encolar (registrar solicitud) 
y desencolar (procesar préstamo) 
y acceder a la información que corresponda de la pila (detalles del libro devuelto)
y la cola (datos del usuario solicitante).
El TP se deberá subir al campus virtual y adjuntarle un video de menos de 5 minutos
donde se lo ve en funcionamiento.
Es requisito utilizar funciones callback en todo su desarrollo.
*/

BibliotecaPtr generarBibliotecaEjemplo(){
        //<-----------------------------------LIBROS----------------------------------->
    int idLibro1 = 100, idLibro2 = 101, idLibro3 = 102, idLibro4 = 103, idLibro5 =104;
    char autorLibro1[30] = "Stephen King", autorLibro2[30] = "Mary Shelley", autorLibro3[30] = "Edgar Allan Poe", autorLibro4[30] = "Bram Stoker", autorLibro5[30] = "William Peter Blatty";
    char tituloLibro1[60] = "El Resplandor", tituloLibro2[60] = "Frankenstein", tituloLibro3[60] = "El Gato Negro", tituloLibro4[60] = "Dracula", tituloLibro5[60] = "El Exorsista";

    LibroPtr libro1 = crearLibro(idLibro1, autorLibro1, tituloLibro1);    
    LibroPtr libro2 = crearLibro(idLibro2, autorLibro2, tituloLibro2);
    LibroPtr libro3 = crearLibro(idLibro3, autorLibro3, tituloLibro3);
    LibroPtr libro4 = crearLibro(idLibro4, autorLibro4, tituloLibro4);
    LibroPtr libro5 = crearLibro(idLibro5, autorLibro5, tituloLibro5);

    NodoPtr nodoLibro1 = crearNodo(libro1);
    NodoPtr nodoLibro2 = crearNodo(libro2);
    NodoPtr nodoLibro3 = crearNodo(libro3);
    NodoPtr nodoLibro4 = crearNodo(libro4);
    NodoPtr nodoLibro5 = crearNodo(libro5);


    //<---------------------------------BIBLIOTECA--------------------------------->
    char direccionBiblioteca[60] = "Aguero 2502, Ciudad Autonoma de Buenos Aires, Argentina";
    BibliotecaPtr biblioteca = crearBiblioteca(direccionBiblioteca, nodoLibro1);

    printf("\n\n");

    //AGREGANDO LOS LIBROS DISPONIBLES
    agregarLibro(biblioteca, nodoLibro2);
    agregarLibro(biblioteca, nodoLibro3);
    agregarLibro(biblioteca, nodoLibro4);
    agregarLibro(biblioteca, nodoLibro5);
    return biblioteca;
}


void menu(BibliotecaPtr biblioteca, NodoPtr nodoUsuario){
    int decision;
    printf("1: SOLICITAR LIBRO\n2: DEVOLVER LIBRO\n3: VER LIBROS DISPONIBLES\n4: REUBICAR LIBROS\nTU: ");
    scanf("%d", &decision);
    switch (decision)
    {
    case 1:
        registrarSolicitud(biblioteca, nodoUsuario, mostrarUsuarioGenerico);
        printf("INGRESE EL ID DEL LIBRO QUE DESEA: ");
        scanf("%d", &decision);
        procesarPrestamo(biblioteca, decision);
        break;
    case 2:
        printf("INGRESE EL ID DEL LIBRO: ");
        scanf("%d", &decision);
        registrarDevolucion(biblioteca, decision, mostrarLibroGenerico);
        break;
    case 3:
        mostrarBiblioteca(biblioteca, mostrarLibroGenerico);
        break;
    case 4:
        reubicarLibro(biblioteca, mostrarLibroGenerico);
        break;
    default:
        printf("ERROR: OPCION INVALIDA\n");
        break;
    }
}




int main(){
    printf("BIENVENIDO A LA BIBLIOTECA, COMENZEMOS REGISTRANDOTE\n");
    NodoPtr usuario = registrarUsuario();
    printf("YA PUEDES DISFRUTAR DE LA LIBRERIA!!");
    BibliotecaPtr biblioteca = generarBibliotecaEjemplo();
    while (1){
        menu(biblioteca, usuario);
    }
    return 0;
}

