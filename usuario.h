#ifndef USUARIO_H
#define USUARIO_H
#include "nodo.h"

struct Usuario;
typedef struct Usuario * UsuarioPtr;
UsuarioPtr crearUsuario(int id, char nombre[], char dni[]);
NodoPtr registrarUsuario();
void mostrarUsuario(UsuarioPtr usuario);
void mostrarUsuarioGenerico(void * dato);


#endif