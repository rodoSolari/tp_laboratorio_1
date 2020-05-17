#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_EMPLOYEES 20
#define NAME_LEN 51
#define LASTNAME_LEN 51
#define UP 1
#define DOWN 0
#define EMPTY 1
#define FULL 0

typedef struct{
    int id;
    char name[NAME_LEN];
    char lastName[LASTNAME_LEN];
    float salary;
    int sector;
    int isEmpty;
} Employee;

void iniciarMenu(Employee* listadoEmployees);
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


/** \brief Imprime menu inicial
* \param -
* \return -
*
*/
void imprimirMenu();

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);


/** \brief Imprime un empleado de la lista
*
* \param list Employee*
* \return -
*/
void printOneEmployee(Employee list);

/** \brief Imprime todos los empleados de la lista recibida
*
* \param list Employee*
* \param len int
* \return -
*
*/
int printEmployees(Employee* list, int len);

/** \brief
*
* \param array employee*
* \param tam int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int employeeSearchFirstEmpty(Employee* array,int limite);


/**\brief Informa por pantalla Total y promedio de los salarios, y cuántos empleados superan el salario promedio
*
* \param list Employee
* \param len int
*  \return -
*/
void informarPromedio(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
void createNewEmployee();


/** \brief Modifica el empleado que quiere el usuario ingresando el ID
*
* \param listado[] Employee
* \param id int
* \param int tam
* \return -
*
*/
void modificarEmpleado(Employee listado[],int id, int tam);
#endif // ARRAYEMPLOYEES_H_INCLUDED
