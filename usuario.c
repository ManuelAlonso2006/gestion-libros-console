#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "nodo.h"

struct Usuario{
    int id;
    char nombre[30];
    char dni[20];
};


UsuarioPtr crearUsuario(int id, char nombre[], char dni[]){
    UsuarioPtr usuario = (UsuarioPtr) malloc(sizeof(struct Usuario));
    usuario->id = id;
    strcpy(usuario->nombre, nombre);
    strcpy(usuario->dni, dni);
    return usuario;
}

NodoPtr registrarUsuario(){
    char idUsuario;
    char nombreUsuario[30];
    char dniUsuario[20];
    printf("INGRESE SU ID DE USUARIO: ");
    scanf("%d",&idUsuario);
    printf("INGRESE SU NOMBRE DE USUARIO: ");
    scanf("%s",nombreUsuario);
    printf("INGRESE SU DNI: ");
    scanf("%s",dniUsuario);
    UsuarioPtr usuario = crearUsuario(idUsuario, nombreUsuario, dniUsuario);
    NodoPtr nodoUs = crearNodo(usuario);
}

void mostrarUsuario(UsuarioPtr usuario){
    printf("ID: %d, NOMBRE: %s, DNI: %s\n", usuario->id, usuario->nombre, usuario->dni);
}


void mostrarUsuarioGenerico(void * dato){
    UsuarioPtr usuario = (UsuarioPtr)dato;
    mostrarUsuario(usuario);
}