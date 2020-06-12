#ifndef VALIDARDATOS_H_INCLUDED
#define VALIDARDATOS_H_INCLUDED
#define MAX_STRING 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Verifica si la cadena ingresada es un string
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y -1 (falso) si no lo es
 */
int isValidString(char* cadena);


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
void getInt(int* number, char* message, char* errorMessage,int minimo,int maximo);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int esNumerico(char* cadena);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int esFloat(char stringNumber[]);


/**
 * \brief Solicita un tipo de dato flotante al usuario, luego vuelve a pedirle a ingresarlo por si no es el tipo de dato ingresado
 * \param number Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param message Es el mensaje a ser mostrado
 * \param errorMessage Es el mensaje de Error a ser mostrado
 * \return -
 */
void getFloat(float* number, char* message, char* errorMessage);
#endif // VALIDARDATOS_H_INCLUDED
