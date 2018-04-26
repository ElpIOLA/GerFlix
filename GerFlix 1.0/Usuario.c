#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant){
    int i;

    for(i=0; i<cant; i++){
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[]){

    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};

    int i;

    for(i=0; i<15; i++){
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);
    }
}

void mostrarListaUsuarios(eUsuario user[], int cant){
    int i, j, auxId;
    char auxNom[21];

    for(i=0;i<cant-1;i++){
        for(j=i+1;j<cant;j++){
            if(user[i].estado == 1){
                if(user[i].idUsuario>user[j].idUsuario){

                    auxId = user[i].idUsuario;
                    user[i].idUsuario = user[j].idUsuario;
                    user[j].idUsuario = auxId;

                    strcpy(auxNom,user[i].nombre);
                    strcpy(user[i].nombre,user[j].nombre);
                    strcpy(user[j].nombre,auxNom);

                }
            }
        }
    }

    for(i=0;i<cant;i++){
        printf("\n%d -- %s\n",user[i].idUsuario,user[i].nombre);
    }
}

void mostrarUsuarioConSuSerie(eUsuario user[], int cantUser, eSerie serie[], int cantSerie){
    int i, j, auxId, auxIdSerie;
    char auxNom[21];

     for(i=0;i<cantUser-1;i++){
        for(j=i+1;j<cantUser;j++){
            if(user[i].estado == 1){
                if(user[i].idSerie == serie[i].idSerie){
                    if(user[i].idSerie>user[j].idSerie){
                        auxId = user[i].idUsuario;
                        user[i].idUsuario = user[j].idUsuario;
                        user[j].idUsuario = auxId;

                        strcpy(auxNom,user[i].nombre);
                        strcpy(user[i].nombre,user[j].nombre);
                        strcpy(user[j].nombre,auxNom);

                        auxIdSerie = user[i].idSerie;
                        user[i].idSerie = user[j].idSerie;
                        user[j].idSerie = auxIdSerie;
                    }
                }
            }
        }
     }

     for(i=0;i<cantUser;i++){
        printf("\n%d -- %s -- %d\n",user[i].idUsuario,user[i].nombre,user[i].idSerie);
     }
}

void mostrarSerieConSuUser(eSerie serie[], int cantSerie, eUsuario user[], int cantUser){
    int i, j, auxId;
    char auxNom[21], auxNomUser[21];

    for(i=0;i<cantSerie-1;i++){
        for(j=i+1;j<cantSerie;j++){
            if(serie[i].idSerie == user[i].idSerie){
                if(serie[i].idSerie>serie[j].idSerie){
                    auxId = serie[i].idSerie;
                    serie[i].idSerie = serie[j].idSerie;
                    serie[j].idSerie = auxId;

                    strcpy(auxNom,serie[i].nombre);
                    strcpy(serie[i].nombre,serie[j].nombre);
                    strcpy(serie[j].nombre,auxNom);

                    strcpy(auxNomUser,user[i].nombre);
                    strcpy(user[i].nombre,user[j].nombre);
                    strcpy(user[j].nombre,auxNomUser);
                }
            }
        }
    }

    for(i=0;i<cantSerie;i++){
        printf("\n%d -- %s -- %s",serie[i].idSerie,serie[i].nombre,user[i].nombre);
    }
}
