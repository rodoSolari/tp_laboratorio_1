#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "ValidarDatos.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[100];
    int horasTrabajadas;
    float sueldo;
}Employee;

/** \brief Constructor del empleado
 *
 *  \param -
 *  \return devuelve un empleado
 *
 */
Employee* employee_new();

/** \brief Agrega nuevos datos a un empleado
 *
 *  \param char* idStr  id del empleado en formato string
 *  \param char* nombreStr char* nombre del empleado
 *  \param char* horasTrabajadasStr horas trabajadas del empleado en formato string
 *  \param char* sueldoStr sueldo del empleado en formato string
 *  \return  Devuelve el empleado con los datos ingresados
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief elimina el empleado, liberando la memoria
 *
 *  \param Employee* this puntero apuntando al empleado
 *  \return -
 *
 */
void employee_delete(Employee* this);


/** \brief (Setter de id) : Agrega el valor ingresado al id del empleado
 *
 *  \param Employee* this puntero apuntando al empleado
 * \return int Retorna  ( 0) Error: si el puntero a empleado es NULL
                        ( 1) Si se ingreso el valor al id del empleado
 */
int employee_setId(Employee* this,int id);

/** \brief (Getter de id) : Obtiene el id del empleado
 *
 *  \param Employee* this puntero apuntando al empleado
 *  \param int* id
 *  \return int Retorna  ( 0) Error: si el puntero al empleado o el id es NULL
                         ( 1) Si se pudo obtener el id del empleado
 */
int employee_getId(Employee* this,int* id);

/** \brief (Setter de nombre) : Agrega el valor ingresado al nombre del empleado
 *
 *  \param Employee* this puntero apuntando al empleado
 *  \param char* nombre del empleado
 *  \return int Retorna  ( 0) Error: si alguno de los punteros a las listas son NULL
                         ( 1) Si se pudo agregar el valor ingresado al nombre del empleado
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief (Getter de nombre)  Obtiene el nombre del empleado
 *
 *  \param Employee* this puntero apuntando al empleado
 *  \param char* nombre del empleado
 *  \return int Retorna  ( 0) Error: si alguno de los punteros a las listas son NULL
                         ( 1) Si se pudo obtener el nombre del empleado
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief  (Setter de horas trabajadas) : Agrega el valor ingresado a las horas trabajadas del empleado
 *
 *  \param Employee* this : puntero apuntando al empleado
    \param int horasTrabajadas : horas trabajadas del empleado
 *  \return int Retorna ( 0) Si el empleado o las horas trabajadas es NULL
                        ( 1) Si se pudo agregar el valor a las horas trabajadas del empleado
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief (Getter de horas trabajadas) : obtiene las horas trabajadas del empleado
 *
 *  \param Employee* this : puntero apuntando al empleado
    \param int* horasTrabajadas : horas trabajadas del empleado
 *  \return int Retorna  ( 0) Si el empleado o las horas trabajadas es NULL
                         ( 1) Si se pudo obtener las horas trabajadas del empleado
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief  (Setter de sueldo) : Agrega el valor ingresado al sueldo del empleado
 *
 *  \param Employee* this puntero apuntando al empleado
    \param float sueldo : sueldo del empleado
 *  \return int Retorna  ( 0) Si el empleado o el sueldo es NULL
                         ( 1) Si se pudo agregar el valor ingresado al sueldo del empleado
 */
int employee_setSueldo(Employee* this,float sueldo);

/** \brief (Getter de sueldo) : obtiene el sueldo del empleado
 *
 *  \param Employee* this puntero apuntando al empleado
 * \return int Retorna  ( 0) Si el empleado o el sueldo es NULL
                        ( 1) Si se pudo obtener el sueldo del empleado
 */
int employee_getSueldo(Employee* this,float* sueldo);


/** \brief Compara 2 valores de tipo char*
 *
 *  \param void* e1 : Puntero al primer elemento
 *  \param void* e2 : Puntero al segundo elemento
 * \return int Retorna  ( 0) Si el primer elemento es menor al segundo
                        ( 1) Si el primer elemento es mayor al segundo
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief Compara 2 valores de tipo int
 *
 *  \param void* e1 Puntero al primer elemento
 *  \param void* e2 Puntero al segundo elemento
 *  \return int Retorna  (-1) Si el primer elemento es menor al segundo
                         ( 1) Si el primer elemento es mayor al segundo
                         ( 0) Si son iguales ambos elementos
 */
int employee_CompareById(void* e1, void* e2);

/** \brief Compara 2 valores de tipo float
 *
 *  \param void* e1 Puntero al primer elemento
 *  \param void* e2 Puntero al segundo elemento
 *  \return int Retorna  (-1) Si el primer elemento es menor al segundo
                         ( 1) Si el primer elemento es mayor al segundo
                         ( 0) Si son iguales ambos elementos
 */
int employee_CompareBySueldo(void* e1, void* e2);

/** \brief Compara 2 valores de tipo int
 *
 *  \param void* e1 Puntero al primer elemento
 *  \param void* e2 Puntero al segundo elemento
 *  \return int Retorna  (-1) Si el primer elemento es menor al segundo
                         ( 1) Si el primer elemento es mayor al segundo
                         ( 0) Si son iguales ambos elementos
 */
int employee_CompareByHorasTrabajadas(void* e1, void* e2);

/** \brief imprime un empleado
 *
 *  \param Employee* this puntero apuntando al empleado
 *  \return -
 */
void printEmployee(Employee* employee);

/** \brief Devuelve el indice de la lista en donde se encuentra el empleado del id que se desea buscar
 *
 *  \param LinkedList* linkedList puntero apuntando a la lista
 *  \return int Retorna  (-1) Error: si no se encontro el id a buscar en los empleados de la lista
                         ( indice) indice del empleado a buscar por el id
 */
int getIndexOfEmployeeById(LinkedList* LinkedList, int id);
#endif // employee_H_INCLUDED
