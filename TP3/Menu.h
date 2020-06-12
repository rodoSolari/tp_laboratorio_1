#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief imprime el menu principal
 *
 *  \param -
 *  \return -
 *
 */
void imprimirMenuPrincipal();

/** \brief imprime el menu para la modificacion de un empleado
 *
 *  \param -
 *  \return -
 *
 */
void imprimirMenuModificarEmployee();

/** \brief Imprime segun lo que reciba del controlador un mensaje
 *
 *  \param int retorno
 *  \param char mensaje[]
 *  \param char errorMensaje[]
 *  \return -
 *
 */
void imprimirRetornoController(int retorno,char mensaje[], char errorMensaje[]);

#endif // MENU_H_INCLUDED
