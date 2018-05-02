#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionValidar.h"
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant){
    int i;

    for(i=0; i<cant; i++){
        usuarios[i].estado = 0;
    }
}

void alta_usuario(eUsuario user[], int cantUser){
    int i;

    int id_user[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre_user[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int id_serie[15] = {100,104,101,104,102,100,100,103,101,102,103,101,100,100,101};

    inicializarUsuariosEstado(user,cantUser);

    for(i=0;i<cantUser;i++){
        if(user[i].estado == 0){
            user[i].idUsuario=id_user[i];
            user[i].idSerie=id_serie[i];
            user[i].estado = 1;
            strcpy(user[i].nombre, nombre_user[i]);
        }
    }
    system("cls");
    printf("\n\tUSUARIOS DADOS DE ALTA!\n");
}

void baja_usuario(eUsuario user[], int cantUser){
    int i, aux_id;
    char auxId[21];

    if(!getStringNumeros("\n\tIngrese ID Usuario: ",auxId)){
        printf("\n\tERROR! La ID debe contener solo numeros.\n");
    }
    aux_id = atoi(auxId);

    for(i=0;i<cantUser;i++){
        if(user[i].estado == 1){
            if(aux_id == user[i].idUsuario){
                user[i].estado = 0;
                system("cls");
                printf("\n\tUSUARIO DADO DE BAJA!\n");
                break;
            }else{
                system("cls");
                printf("\n\tUSUARIO INEXISTENTE!\n");
                break;
            }
        }
    }
}

void modificar_User(eUsuario user[], int cantUser){
    int i, auxID, nueva_id_serie;
    char aux_id[21], auxNom[21], auxNueIdSer[21];

    if(!getStringNumeros("\n\tIngrese ID del usuario a modificar: ",aux_id)){
        printf("\n\tERROR! La ID debe contener solo numeros.");
    }
    auxID = atoi(aux_id);

    for(i=0;i<cantUser;i++){
        if(user[i].estado == 1){
            if(auxID == user[i].idUsuario){

                system("cls");
                printf("\n\tUSUARIO ENCONTRADO!\n\n");

                printf("\n\tNOMBRE ACTUAL: %s\n",user[i].nombre);
                if(!getStringLetras("\n\tIngrese Nuevo Nombre: ",auxNom)){
                    printf("\n\tERROR! El nombre debe contener solo letras.");
                    break;
                }
                fflush(stdin);
                strcpy(user[i].nombre,auxNom);

                printf("\n\tSERIE ACTUAL: %d",user[i].idSerie);
                if(!getStringNumeros("\n\tIngrese nueva ID Serie:\n\t(EL ID ES ENTRE [100 y 105]\n\tRespuesta: )",auxNueIdSer)){
                    printf("\n\tERROR! La ID debe contener solo numeros.");
                    break;
                }
                nueva_id_serie = atoi(auxNueIdSer);
                if(nueva_id_serie >= 100 && nueva_id_serie <= 105){
                    user[i].idSerie = nueva_id_serie;
                }else{
                    printf("\n\tERROR! ID INEXISTENTES!");
                    break;
                }
                system("cls");
                printf("\n\tUSUARIO MODIFICADO!");
            }
        }
    }
}
/**-------------------------FUNCIONES DE LISTAS----------------------------------*/

void mostrarListaUsuarios(eUsuario user[], int cant){
    int i;

    for(i=0;i<cant;i++){
        if(user[i].estado == 1){
            printf("\n\t%d -- %s\n",user[i].idUsuario,user[i].nombre);
        }
    }
}

void mostrarUsuarioConSuSerie(eUsuario user[], int cantUser, eSerie serie[], int cantSerie){
    int i, j;

    for(i=0;i<cantUser;i++){
        for(j=0;j<cantSerie;j++){
            if(user[i].idSerie == serie[j].idSerie){
                if(user[i].estado == 1){
                    printf("\n\t%d -- %s -- %s\n",user[i].idUsuario,user[i].nombre,serie[j].nombre);
                }
            }
        }
    }
}
void mostrarSerieConSuUser(eSerie serie[], int cantSerie, eUsuario user[], int cantUser){
    int i, j;

    char espacio[] = " ";

    for(i=0;i<cantSerie;i++){
        if(serie[i].estado == 1){
            for(j=0;j<cantUser;j++){
                if(user[j].estado == 1){
                    if(serie[i].idSerie == user[j].idSerie){
                        strcat(serie[i].nombre,espacio);
                        strcat(serie[i].nombre,user[j].nombre);
                    }
                }
            }
        }
    }

    for(i=0;i<cantSerie;i++){
        if(serie[i].estado == 1){
            printf("\n\t%s\n",serie[i].nombre);
        }
    }
}

