#include "ValidarDatos.h"

int isValidString(char* cadena)
{
    int longitud = 50;
	int i=0;
	int retorno = 1;

	if(cadena != NULL)
	{
		for(i=0 ; cadena[i] != '\0' && i<longitud; i++)
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

int esNumerico(char* cadena)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL)
	{
		retorno = 1; // VERDADERO
		for(i=0;cadena[i]!='\0';i++)
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

    while(esFloat(string)==0 || *number<0){
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



void getString(char* arrayString, char* message, char* errorMessage)
{
    printf("%s", message);
    fflush(stdin);
    gets(arrayString);

    while(isValidString(arrayString)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(arrayString);
    }
}


