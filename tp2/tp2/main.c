#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define MAX_EMPLOYEES 20

int main()
{
    Employee listadoEmployees[MAX_EMPLOYEES];
    int opcion;
    do
    {
        printf("1.Cargar un empleados\n");
        printf("2.Eliminar un empleados\n");
        printf("3.Modificar un empleados\n");
        printf("4.Listar empleados\n");
        printf("5.Ordenar empleados\n");
        printf("7.SALIR\n");
        printf("ELIJA UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printEmployees(listadoEmployees,MAX_EMPLOYEES);
                break;
            case 5:
            break;
        }

    }while(opcion!=7);
    return 0;
}
