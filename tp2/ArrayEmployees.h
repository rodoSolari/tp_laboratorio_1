#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include <string.h>
#include <stdio.h>
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


int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int employeeSearchFirstEmpty(Employee* array,int limite);
void printOneEmployee(Employee list);
void informarPromedio(Employee* list, int len);
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
