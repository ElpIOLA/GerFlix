#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

int main()
{
    int opcion = 0;
    char seguir = 's';

    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

/*  1. Mostrar el listado de series
    2. Mostrar el listado de usuarios
    3. Mostrar el listado de Usuarios con el nombre de la serie que ve
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.
*/
    while(seguir == 's'){

    printf("\n\tRespuesta: ");
    scanf("%d",&opcion);

        switch(opcion){
            case 1:
                mostrarListaSeries(listaDeSeries,5);
                break;
            case 2:
                mostrarListaUsuarios(listaDeUsuarios,15);
                break;
            case 3:
                mostrarUsuarioConSuSerie(listaDeUsuarios,15,listaDeSeries);
                break;
            case 4:
                mostrarSerieConSuUser(listaDeSeries,5,listaDeUsuarios,15);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}

