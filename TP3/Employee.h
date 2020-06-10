#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "ValidarDatos.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char nombre[100];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);

void printEmployee(Employee* employee);
#endif // employee_H_INCLUDED
