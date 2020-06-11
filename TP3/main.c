#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int opcion;
    int retorno;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        imprimirMenuPrincipal();

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                retorno = controller_loadFromText("data.csv",listaEmpleados);
                imprimirRetornoController(retorno,"Cargado con exito del archivo","Error, no existe el archivo");
                break;
            case 2:
                retorno = controller_loadFromBinary("data.bin",listaEmpleados);
                imprimirRetornoController(retorno,"Cargado con exito del archivo","Error, no existe el archivo");
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                break;
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 10);
    return 0;
}
