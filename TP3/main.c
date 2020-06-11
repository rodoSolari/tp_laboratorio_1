#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"

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
                retorno = controller_addEmployee(listaEmpleados);
                imprimirRetornoController(retorno,"Cargado con exito nuevo empleado","Error, no existe la lista o el archivo");
                break;
            case 4:
                retorno = controller_editEmployee(listaEmpleados);
                imprimirRetornoController(retorno,"Modificado con exito!","No se encontro el id del empleado");
                break;
            case 5:
                retorno = controller_removeEmployee(listaEmpleados);
                imprimirRetornoController(retorno,"Eliminado con exito!","No se encontro el empleado a eliminar");
                break;
            case 6:
                retorno = controller_ListEmployee(listaEmpleados);
                imprimirRetornoController(retorno,"Lista de empleados realizado con exito ","La lista se encuentra vacia o no existe");
                break;
            case 7:
                retorno = controller_sortEmployee(listaEmpleados);
                imprimirRetornoController(retorno,"Lista de empleados ordenados realizado con exito"," ");
                break;
            case 8:
                retorno = controller_saveAsText("data.csv",listaEmpleados);
                imprimirRetornoController(retorno,"Lista de empleados guardado en modo texto con exito"," ");
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                imprimirRetornoController(retorno,"Lista de empleados guardado en modo binario con exito ","No existe el nombre del archivo ingresado");
                break;
        }
        system("pause");
        system("cls");
    }while(opcion != 10);
    return 0;
}
