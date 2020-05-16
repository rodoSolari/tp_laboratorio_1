#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define MAX_EMPLOYEES 20

int main()
{
    Employee listadoEmployees[MAX_EMPLOYEES];
    int employeeCargado = 0;
    int opcion;
    int idEliminar;
    int orden;
    if(initEmployees(listadoEmployees,MAX_EMPLOYEES)==0){
        printf("__listado inicializado__\n");
    }else{
        printf("Error al inicializar el listado\n");
    }
    Employee newEmployee;

    do
    {
        printf("1.Cargar un empleados\n");
        printf("2.Modificar un empleados\n");
        printf("3.Eliminar un empleados\n");
        printf("4.Listar empleados\n");
        printf("5.Ordenar empleados\n");
        printf("6.SALIR\n");
        printf("ELIJA UNA OPCION: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                createNewEmployee(listadoEmployees,newEmployee,MAX_EMPLOYEES);
                employeeCargado++;
                break;
            case 2:
                if(employeeCargado>=1){
                    //modificarEmpleado(listadoEmployees,MAX_EMPLOYEES);
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
                printf("ingrese el orden\n    1:ascendente    0:descendente");
                scanf("%d",&orden);
                sortEmployees(listadoEmployees,MAX_EMPLOYEES,orden);
                //informarPromedio(listadoEmployees,MAX_EMPLOYEES,orden);
                break;
        }

    }while(opcion!=6);
    return 0;
}
