#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesParaTiposDeDatos.h"

int esNumerico(char stringNumber[]){
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

/*void getFloat(float number, char* message, char* errorMessage){
    char string[50];
    printf("%s", message);
    fflush(stdin);
    gets(string);
    number=atof(string);
    while(esNumerico(number)==1){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        number=atof(string);
    }
}*/

void getInt(int number, char* message, char* errorMessage){
    char string[50];
    printf("%s", message);
    fflush(stdin);
    gets(string);
    number=atoi(string);
    while(esNumerico(string)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        number=atoi(string);
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
