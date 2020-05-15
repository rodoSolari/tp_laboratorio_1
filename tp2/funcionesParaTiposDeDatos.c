#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesParaTiposDeDatos.h"


int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}



int esString(char arrayString[]){
    int respuesta=0;
    for(int i=0; arrayString[i]!='\0'; i++){
        if((arrayString[i]<'a' || arrayString[i]>'z') && (arrayString[i]<'A' || arrayString[i]>'Z')){
            respuesta=1;
            break;
        }
    }
    return respuesta;
}

void getString(char arrayString[], char message[], char errorMessage[])
{
    printf("%s", message);
    fflush(stdin);
    gets(arrayString);

    while(esString(arrayString)==1){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(arrayString);
    }
}
