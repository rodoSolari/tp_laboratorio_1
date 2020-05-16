#ifndef FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
#define FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
#include "arrayEmployees.h"

int esString(char arrayString[]);
void getString(char* arrayString, char* message, char* errorMessage);
void getInt(int* number, char message[], char errorMessage[]);
int esNumerico(char stringNumber[]);
//void getFloat(float number, char* message, char* errorMessage);
#endif // FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
