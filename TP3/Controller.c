#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Menu.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int respuesta;
    if(path != NULL || pArrayListEmployee != NULL){
        pFile = fopen(path,"r");
        if((parser_EmployeeFromText(pFile,pArrayListEmployee)==1)){
            respuesta = 1;
        }else{
            respuesta = 0;
        }
    }else{
        respuesta = -1;
    }
    return respuesta;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int respuesta;
    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"rb");
        if(parser_EmployeeFromBinary(pFile,pArrayListEmployee)==1){
            respuesta = 1;
        }else{
            respuesta = 0;
        }
    }else{
        respuesta = -1;
    }
    return respuesta;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* newEmployee;
    int idNewEmployee;
    char nombreNewEmployee[50];
    int horasTrabajadasNewEmployee;
    float sueldoNewEmployee;
    int respuesta = -1;

    if(pArrayListEmployee!=NULL){
        newEmployee = employee_new();
        getString(nombreNewEmployee,"Ingrese el nombre : ","Error , ingrese un nombre valido ");
        getInt(&horasTrabajadasNewEmployee,"Ingrese las horas trabajadas : ","Error, ingrese un numero valido : ",0,500);
        getFloat(&sueldoNewEmployee,"Ingrese el sueldo : ","Error, ingrese un numero valido : ");
        idNewEmployee = ll_len(pArrayListEmployee)+1;

        employee_setId(newEmployee,idNewEmployee);
        employee_setNombre(newEmployee,nombreNewEmployee);
        employee_setHorasTrabajadas(newEmployee,horasTrabajadasNewEmployee);
        employee_setSueldo(newEmployee,sueldoNewEmployee);

        ll_add(pArrayListEmployee,newEmployee);
        printEmployee(newEmployee);
        respuesta = 1;
    }
    controller_ListEmployee(pArrayListEmployee);
    return respuesta;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int indice;
    char nombre[50];
    int horasTrabajadas;
    float sueldo;
    int opcion;
    int respuesta = -1;
    Employee* employee;
    if(pArrayListEmployee == NULL){
        respuesta = -1;
    }else{
        printf("Ingrese el id a buscar : ");
        scanf("%d",&id);
        indice = getIndexOfEmployeeById(pArrayListEmployee,id);
        if(indice>=0){
            employee = ll_get(pArrayListEmployee,indice-1);  //porque el indice de la lista comienza en cero
            printf("Datos del empleado a modificar : \n");
            printEmployee(employee);
            if(pArrayListEmployee!=NULL){
                do{
                    imprimirMenuModificarEmployee();
                    scanf("%d",&opcion);
                    switch(opcion){
                        case 1:
                            getString(nombre,"Ingrese el nombre : ","Error , ingrese un nombre valido ");
                            employee_setNombre(employee,nombre);
                            printf("Modificado\n");
                            printEmployee(employee);
                            break;
                        case 2:
                            getInt(&horasTrabajadas,"Ingrese las horas trabajadas : ","Error, ingrese un numero valido : ",0,500);
                            employee_setHorasTrabajadas(employee,horasTrabajadas);
                            printf("Modificado\n");
                            printEmployee(employee);
                            break;
                        case 3:
                            getFloat(&sueldo,"Ingrese el sueldo : ","Error, ingrese un numero valido : ");
                            employee_setSueldo(employee,sueldo);
                            printf("Modificado\n");
                            printEmployee(employee);
                            break;
                        default:
                            if(opcion!=4){
                                printf("Por favor, ingrese una opcion valida \n");
                            }
                    }
                }while(opcion!=4);
                respuesta = 1;
            }
        }else{
            respuesta = 0;
        }
    }
    return respuesta;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int indice;
    int respuesta = -1;
    if(pArrayListEmployee==NULL){
        respuesta = -1;
    }else{
        printf("Ingrese el id a buscar : ");
        scanf(" %d",&id);
        indice = getIndexOfEmployeeById(pArrayListEmployee,id);
        if(indice>=0){
            printf("Empleado a eliminar : \n");
            printEmployee(ll_get(pArrayListEmployee,indice-1));
            ll_remove(pArrayListEmployee,indice-1);
            respuesta = 1;
        }else{
            respuesta = 0;
        }
    }
    return respuesta;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int tamLinkedList = ll_len(pArrayListEmployee);
    int i;
    int respuesta;
    if(tamLinkedList == 0 || pArrayListEmployee==NULL){
        respuesta = 0;
    }else{
        printf("    ID      Nombre      Horas trabajadas     Sueldo  \n");
        for(i=0;i<tamLinkedList;i++){
            printEmployee(ll_get(pArrayListEmployee,i));
        }
        respuesta = 1;
    }
    return respuesta;

}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int respuesta = -1;
    if(pArrayListEmployee == NULL){
        respuesta = -1;
    }else{
        do{
            printf("Ingrese una opcion : \n");
            printf("1. Ordenar por nombre\n");
            printf("2. Ordenar por id\n");
            printf("3. Ordenar por horas trabajadas\n");
            printf("4. Ordenar por sueldo\n");
            printf("5. Salir\n");
            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                    printf("Ordenando...\n");//Tarda unos segundos en ordenar
                    ll_sort(pArrayListEmployee,employee_CompareByName,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 2:
                    printf("Ordenando...\n");//Tarda unos segundos en ordenar
                    ll_sort(pArrayListEmployee,employee_CompareById,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 3:
                    printf("Ordenando...\n");//Tarda unos segundos en ordenar
                    ll_sort(pArrayListEmployee,employee_CompareByHorasTrabajadas,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                case 4:
                    printf("Ordenando...\n");//Tarda unos segundos en ordenar
                    ll_sort(pArrayListEmployee,employee_CompareBySueldo,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
                default:
                    if(opcion!=5){
                        printf("Error, ingrese un valor valido\n");
                    }
                    break;
            }
        }while(opcion!=5);
        respuesta = 1;
    }
    return respuesta;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int i=0;
    int tamLinkedList = ll_len(pArrayListEmployee);
    int respuesta;

    FILE* pFile;
    if(path==NULL){
        respuesta = -1;
    }else{
        pFile = fopen(path,"w");
        Employee* employee;

        if(pFile == NULL || pArrayListEmployee == NULL){
            respuesta = -1;
        }
        else{
            fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n"); //imprimo la cabecera en el nuevo archivo
            do{
                employee = ll_get(pArrayListEmployee,i);
                fprintf(pFile,"%d,%s,%d,%2.f\n",employee->id,employee->nombre,employee->horasTrabajadas,employee->sueldo);
                i++;
            }while(i<tamLinkedList);
            respuesta = 1;
        }
        fclose(pFile);
    }
    return respuesta;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int i=0;
    int tamLinkedList = ll_len(pArrayListEmployee);
    FILE* pFile;
    int respuesta = 0;
    if(path==NULL){
        respuesta = -1;
    }else{
        pFile = fopen(path,"wb");
        Employee* employee;

        if(path == NULL || pArrayListEmployee == NULL){
            respuesta = -1;
        }else{
            do{
                employee = ll_get(pArrayListEmployee,i);
                fwrite(employee,sizeof(Employee),1,pFile);
                i++;
            }while(i<tamLinkedList);
            respuesta = 1;
        }
        fclose(pFile);
    }
    return respuesta;
}

