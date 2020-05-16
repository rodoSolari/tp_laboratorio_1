#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesParaTiposDeDatos.h"

int isNumeric(char stringNumber[]){
    int respuesta=1;
    int i;

    for(i=0;stringNumber[i]!='\0';i++){
        if(stringNumber[i]<'0' || stringNumber[i]>'9'){
            respuesta=0;
            break;
        }
    }
    return respuesta;
}

int isFloat(char stringNumber[]){
    int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(stringNumber != NULL && strlen(stringNumber) > 0){
		for(i=0 ; stringNumber[i] != '\0'; i++){
			if(stringNumber[i] < '0' || stringNumber[i] > '9' ){
				if(stringNumber[i] == '.' && contadorPuntos == 0){
					contadorPuntos++;
				}else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

void getFloat(float* number, char* message, char* errorMessage){
    char string[MAX_STRING];

    printf("%s", message);
    fflush(stdin);
    gets(string);
    *number=atof(string);

    while(isFloat(string)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        *number=atof(string);
    }
}

void getInt(int* number, char* message, char* errorMessage){
    char string[MAX_STRING];
    printf("%s", message);
    fflush(stdin);
    gets(string);
    *number=atoi(string);
    while(isNumeric(string)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        *number=atoi(string);
    }
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

void getString(char* arrayString, char* message, char* errorMessage)
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
