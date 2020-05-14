#ifndef FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
#define FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
#include "arrayEmployees.h"
int employeeSearchFirstEmpty(Employee* array,int limite);
int employeeSearchId(Employee list[], int limite, int valorBuscado);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
#endif // FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
