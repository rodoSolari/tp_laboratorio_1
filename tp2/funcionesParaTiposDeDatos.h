#ifndef FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
#define FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
#include "arrayEmployees.h"
#define MAX_STRING 50

int esString(char arrayString[]);

/**
 * \brief Solicita un string(cadena de caracteres) al usuario, luego vuelve a pedirle a ingresarlo por si no es el tipo de dato ingresado
 * \param arrayString Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param message Es el mensaje a ser mostrado
 * \param errorMessage Es el mensaje de Error a ser mostrado
 * \return -
 *
 */
void getString(char* arrayString, char* message, char* errorMessage);

/**
 * \brief Solicita un tipo de dato int al usuario, luego vuelve a pedirle a ingresarlo por si no es el tipo de dato ingresado
 * \param number Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param message Es el mensaje a ser mostrado
 * \param errorMessage Es el mensaje de Error a ser mostrado
 * \return -
 */
void getInt(int* number, char message[], char errorMessage[]);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int isNumeric(char stringNumber[]);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int isFloat(char stringNumber[]);


/**
 * \brief Solicita un tipo de dato flotante al usuario, luego vuelve a pedirle a ingresarlo por si no es el tipo de dato ingresado
 * \param number Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param message Es el mensaje a ser mostrado
 * \param errorMessage Es el mensaje de Error a ser mostrado
 * \return -
 */
void getFloat(float* number, char* message, char* errorMessage);
//void getFloat(float number, char* message, char* errorMessage);
#endif // FUNCIONESPARATIPOSDEDATOS_H_INCLUDED
