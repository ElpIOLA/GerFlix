#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include <string.h>

/*
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;

*/

void inicializarSeriesEstado(eSerie series[], int cant){
    int i;

    for(i=0; i<cant; i++){
        series[i].estado = 0;
    }
}


void inicializarSeriesHardCode(eSerie series[])
{
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};
    int i;

    for(i=0; i<5; i++){
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado = 1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}

void mostrarListaSeries(eSerie serie[], int cant){
    int i, j, auxId, auxTem;
    char auxNom[21], auxGen[21];

    for(i=0;i<cant-1;i++){
        for(j=i+1;j<cant;j++){
            if(serie[i].estado == 1){
               if(serie[i].idSerie>serie[j].idSerie){

                auxId = serie[i].idSerie;
                serie[i].idSerie = serie[j].idSerie;
                serie[j].idSerie = auxId;

                strcpy(auxNom,serie[i].nombre);
                strcpy(serie[i].nombre,serie[j].nombre);
                strcpy(serie[j].nombre,auxNom);

                strcpy(auxGen,serie[i].genero);
                strcpy(serie[i].genero,serie[j].genero);
                strcpy(serie[j].genero,auxGen);

                auxTem = serie[i].cantidadTemporadas;
                serie[i].cantidadTemporadas = serie[j].cantidadTemporadas;
                serie[j].cantidadTemporadas = auxTem;
                }
            }
        }
    }

    for(i=0;i<cant;i++){
        printf("\n%d -- %s -- %s -- %d\n",serie[i].idSerie,serie[i].nombre,serie[i].genero,serie[i].cantidadTemporadas);
    }
}



