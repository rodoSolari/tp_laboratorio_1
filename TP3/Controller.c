#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    if(path != NULL || pArrayListEmployee != NULL){
        pFile = fopen(path,"r");
        parser_EmployeeFromText(pFile,pArrayListEmployee);
    }
    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    if(path != NULL || pArrayListEmployee != NULL){
        pFile = fopen(path,"rb");
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
    }
    return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;
    int idNewEmployee;
    char nombreNewEmployee[50];
    int horasTrabajadasNewEmployee;
    int sueldoNewEmployee;

    if(pArrayListEmployee!=NULL){
        newEmployee = employee_new();
        getString(nombreNewEmployee,"Ingrese el nombre : ","Error , ingrese un nombre valido ");
        getInt(&horasTrabajadasNewEmployee,"Ingrese las horas trabajadas : ","Error, ingrese un numero valido : ",0,500);
        getInt(&sueldoNewEmployee,"Ingrese las horas trabajadas : ","Error, ingrese un numero valido : ",0,50000);
        idNewEmployee = ll_len(pArrayListEmployee)+1;
        employee_setId(newEmployee,idNewEmployee);
        employee_setNombre(newEmployee,nombreNewEmployee);
        employee_setHorasTrabajadas(newEmployee,horasTrabajadasNewEmployee);
        employee_setSueldo(newEmployee,sueldoNewEmployee);
        ll_add(pArrayListEmployee,newEmployee);

        printf("NUEVO EMPLEADO : \n");
        printEmployee(newEmployee);
    }
    return 1;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int idNewEmployee;
    char nombreNewEmployee[50];
    int horasTrabajadasNewEmployee;
    int sueldoNewEmployee;
    int opcion;
    do{
        printf("Menu para modificacion:\n");
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        switch(opcion){

        }
    }while(opcion!=5);
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;

}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

