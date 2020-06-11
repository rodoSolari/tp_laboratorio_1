#include "Menu.h"

void imprimirMenuPrincipal(){
    printf("Menu:\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo 'data.csv' (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo 'data.bin' (modo binario).\n");
    printf("10. Salir\n");
}

void imprimirMenuModificarEmployee(){
    printf("Menu para modificacion:\n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar horas trabajadas\n");
    printf("3. Modificar sueldo\n");
    printf("4. Salir\n");
    printf("\n");
}

void imprimirRetornoController(int retorno,char mensaje[], char errorMensaje[]){
    if(retorno == 1){
        printf("%s\n",mensaje);
    }else if(retorno == 0){
        printf("%s\n",errorMensaje);
    }else{
        printf("Error, no se encuentra la lista o el archivo");
    }
}
