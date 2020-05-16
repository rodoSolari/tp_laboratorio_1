#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define MAX_EMPLOYEES 20

int main()
{
    Employee listadoEmployees[MAX_EMPLOYEES];
    int employeeCargado = 0;
    int opcion,idEliminar,idModificar,orden;
    Employee newEmployee;
    if(initEmployees(listadoEmployees,MAX_EMPLOYEES)==0){
        printf("__listado inicializado__\n");
        do
        {
            imprimirMenu();
            scanf("%d",&opcion);
            switch(opcion){
                case 1:
                    createNewEmployee(listadoEmployees,newEmployee,MAX_EMPLOYEES);
                    employeeCargado++;
                    break;
                case 2:
                    if(employeeCargado>=1){
                        printf("Ingrese el id del empleado a modificar: ");
                        scanf("%d",&idModificar);
                        modificarEmpleado(listadoEmployees,idModificar,MAX_EMPLOYEES);
                    }else{
                        printf("No hay empleados cargados en la lista, por favor ingrese primero la opcion 1");
                    }
                    break;
                case 3:
                    if(employeeCargado>=1){
                        printf("Ingrese el id del empleado: ");
                        scanf("%d",&idEliminar);
                        if(removeEmployee(listadoEmployees,MAX_EMPLOYEES,idEliminar)==0){
                            printf("Eliminado con exito!\n");
                            employeeCargado--;
                        }else{
                            printf("Error al eliminar el empleado \n");
                        }
                    }else{
                        printf("No hay empleados cargados en la lista, por favor ingrese primero la opcion 1");
                    }
                    break;
                case 4:
                    if(employeeCargado>=1){
                        printEmployees(listadoEmployees,employeeCargado);
                    }else{
                        printf("No hay empleados cargados en la lista, por favor ingrese primero la opcion 1");
                    }
                    break;
                case 5:
                    if(employeeCargado>=1){
                        printf("ingrese el orden\n    1:ascendente    0:descendente\n");
                        scanf("%d",&orden);
                        sortEmployees(listadoEmployees,MAX_EMPLOYEES,orden);
                        informarPromedio(listadoEmployees,MAX_EMPLOYEES);
                    }else{
                        printf("No hay empleados cargados en la lista, por favor ingrese primero la opcion 1");
                    }
                    break;
            }
        system("pause");
        system("cls");
        }while(opcion!=6);
    }else{
        printf("Error al inicializar el listado\n");
    }
    return 0;
}
