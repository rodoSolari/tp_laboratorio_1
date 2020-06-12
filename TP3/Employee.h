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

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

int employee_CompareByName(void* e1, void* e2);
int employee_CompareById(void* e1, void* e2);
int employee_CompareBySueldo(void* e1, void* e2);
int employee_CompareByHorasTrabajadas(void* e1, void* e2);

void printEmployee(Employee* employee);
int getIndexOfEmployeeById(LinkedList* LinkedList, int id);
#endif // employee_H_INCLUDED
