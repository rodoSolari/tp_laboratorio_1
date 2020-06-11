#include "ValidarDatos.h"
int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

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

int esFloat(char stringNumber[]){
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

    while(esFloat(string)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        *number=atof(string);
    }
}

void getInt(int* number, char* message, char* errorMessage,int minimo,int maximo){
    char string[MAX_STRING];
    printf("%s", message);
    fflush(stdin);
    gets(string);
    *number=atoi(string);
    while(esNumerico(string)==0 || *number<minimo || *number>maximo){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        *number=atoi(string);
    }
}


int esString(char arrayString[]){
    int respuesta=1;
    for(int i=0; arrayString[i]!='\0'; i++){
        if((arrayString[i]<'a' || arrayString[i]>'z') && (arrayString[i]<'A' || arrayString[i]>'Z')){
            respuesta=0;
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

    while(esString(arrayString)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(arrayString);
    }
}


