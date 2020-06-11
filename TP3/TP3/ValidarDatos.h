#ifndef VALIDARDATOS_H_INCLUDED
#define VALIDARDATOS_H_INCLUDED
#define MAX_STRING 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidNombre(char* cadena,int longitud);
int esNumerica(char* cadena, int limite);

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
void getInt(int* number, char* message, char* errorMessage,int minimo,int maximo);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int esNumerico(char stringNumber[]);

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

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
void getLong(long* number, char* message, char* errorMessage, int minimo, int maximo);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int esMarca(char arrayString[]);

/**
 * \brief Verifica si la cadena ingresada es una marca
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es una marca y 0 (falso) si no lo es
 */
void getMarca(char* arrayString, char* message, char* errorMessage);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
char getChar(char* message, char* errorMessage,char primerValor,char segundoValor);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
int esTipo(char arrayString[]);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
void getTipo(char* arrayString, char* message, char* errorMessage);


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 */
void getPatente(char* arrayString, char* message, char* errorMessage);
#endif // VALIDARDATOS_H_INCLUDED
