
#include "Serie.h"

typedef struct
{
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;
}eUsuario;

/**
 *\brief INICIALIZA EL ESTADO DEL USUARIO EN 0.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void inicializarUsuariosEstado(eUsuario[], int);

/**
 *\brief DA DE ALTA LOS USUARIOS.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void alta_usuario(eUsuario[], int);

/**
 *\brief DA DE BAJA UN USUARIO.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void baja_usuario(eUsuario[], int);

/**
 *\brief MODIFICA EL NOMBRE Y LA SERIE DEL USUARIO.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void modificar_User(eUsuario[], int);

/**
 *\brief MUESTRA UNA LISTA CON TODOS LOS USUARIOS ORDENADOS POR SU ID.
 *\param PARAMETRO 1: RECIBE LA ESTRUSCUTA.
 *\param PARAMETRO 2: RECIBE EL TAMAÑO DEL VECTOR.
*/
void mostrarListaUsuarios(eUsuario[], int);

/**
 *\brief MUESTRA UNA LISTA DE TODOS LOS USUARIOS CON LA SERIE QUE VEN.
 *\param PARAMETRO 1: RECIBE LA ESTRUCTURA DE EUSUARIO.
 *\param PARAMETRO 2: RECIBE LA ESTRUCTURA DE ESERIE.
 *\param PARAMETRO 3: RECIBE EL TAMAÑO DEL VECTOR.
*/
void mostrarUsuarioConSuSerie(eUsuario[], int, eSerie[], int);

/**
 *\brief MUESTRA UNA LISTA DE TODAS LAS SERIES CON SUS USUARIOS.
 *\param PARAMETRO 1: RECIBE LA ESTRUCTURA DE ESERIE.
 *\param PARAMETRO 2: RECIBE LA CANTIDAD DE SERIES HABILITADAS.
 *\param PARAMETRO 3: RECIBE LA ESTRUCTURA DE EUSUARIO.
 *\param PARAMETRO 4: RECIBE LA CANTIDAD DE USUARIOS HABILITADOS.
*/
void mostrarSerieConSuUser(eSerie[], int, eUsuario[], int);

