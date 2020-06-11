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
        if((parser_EmployeeFromText(pFile,pArrayListEmployee)==1)){
            printf("Cargado con exito del archivo %s a la lista \n",path);
        }else{
            printf("Error, no existe el archivo");
        }
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
        getInt(&sueldoNewEmployee,"Ingrese el sueldo : ","Error, ingrese un numero valido : ",0,50000);
        idNewEmployee = ll_len(pArrayListEmployee)+1;

        employee_setId(newEmployee,idNewEmployee);
        employee_setNombre(newEmployee,nombreNewEmployee);
        employee_setHorasTrabajadas(newEmployee,horasTrabajadasNewEmployee);
        employee_setSueldo(newEmployee,sueldoNewEmployee);

        ll_add(pArrayListEmployee,newEmployee);

        printf("AGREGADO NUEVO EMPLEADO : \n");
        printEmployee(newEmployee);
    }
    controller_ListEmployee(pArrayListEmployee);
    return 1;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int indice;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    int opcion;
    Employee* employee;
    printf("Ingrese el id a buscar : ");
    scanf(" %d",&id);
    indice = getIndexOfEmployeeById(pArrayListEmployee,id);
    if(indice>=0){
        employee = ll_get(pArrayListEmployee,indice-1);  //porque el indice de la lista comienza en cero
        printf("Datos del empleado a modificar : \n");
        printEmployee(employee);
        if(pArrayListEmployee!=NULL){
            do{
                printf("Menu para modificacion:\n");
                printf("1. Modificar nombre\n");
                printf("2. Modificar horas trabajadas\n");
                printf("3. Modificar sueldo\n");
                printf("4. Salir\n");
                printf("\n");
                scanf("%d",&opcion);
                switch(opcion){
                    case 1:
                        getString(nombre,"Ingrese el nombre : ","Error , ingrese un nombre valido ");
                        employee_setNombre(employee,nombre);
                        break;
                    case 2:
                        getInt(&horasTrabajadas,"Ingrese las horas trabajadas : ","Error, ingrese un numero valido : ",0,500);
                        employee_setHorasTrabajadas(employee,horasTrabajadas);
                        break;
                    case 3:
                        getInt(&sueldo,"Ingrese el sueldo : ","Error, ingrese un numero valido : ",0,50000);
                        employee_setSueldo(employee,sueldo);
                        break;
                    default:
                        if(opcion!=4){
                            printf("Por favor, ingrese una opcion valida \n");
                        }
                }
            }while(opcion!=4);
            printf("Modificado con exito! \n");
        }
    }else{
        printf("No se encontro el id del empleado\n");
    }
    controller_ListEmployee(pArrayListEmployee);
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int indice;

    printf("Ingrese el id a buscar : ");
    scanf(" %d",&id);
    indice = getIndexOfEmployeeById(pArrayListEmployee,id);
    if(indice>=0){
        printf("Empleado a eliminar : \n");
        printEmployee(ll_get(pArrayListEmployee,indice-1));
        ll_remove(pArrayListEmployee,indice-1);
        printf("Eliminado con exito, al presionar una tecla se mostrara la lista\n");
        system("pause");
        controller_ListEmployee(pArrayListEmployee);
    }else{
        printf("No se encontro el empleado a eliminar\n");
    }
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int tamLinkedList = ll_len(pArrayListEmployee);
    int i;
    for(i=0;i<tamLinkedList;i++){
        printEmployee(ll_get(pArrayListEmployee,i));
    }
    return 1;

}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    do{
        printf("Ingrese una opcion : \n");
        printf("1. Ordenar por id\n");
        printf("2. Ordenar por nombre\n");
        printf("3. Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                ll_sort(pArrayListEmployee,employee_CompareByName,1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_CompareById,1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            default:
                if(opcion!=3){
                    printf("Error, ingrese un valor valido\n");
                }
                break;
        }
    }while(opcion!=3);
    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i=0;
    int tamLinkedList = ll_len(pArrayListEmployee);
    FILE* pFile;
    pFile = fopen(path,"w");
    Employee* employee;
    if(pFile == NULL || pArrayListEmployee == NULL){
        return -1;
    }
    do{
        if(i==0){
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        }
        else{
            employee = ll_get(pArrayListEmployee,i);
            fprintf(pFile,"%d  %s  %d  %d\n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);
        }
        i++;
    }while(i<tamLinkedList);
    fclose(pFile);
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    /*FILE *pFile;
    Employee* auxEmployee;

    if(path != NULL || pArrayListEmployee != NULL){
        pFile = fopen(path,"w");
    }*/
    return 1;
}

