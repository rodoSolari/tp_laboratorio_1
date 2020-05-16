#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"

int main()
{
    Employee listadoEmployees[MAX_EMPLOYEES];
    if(initEmployees(listadoEmployees,MAX_EMPLOYEES)==0){
        printf("__listado inicializado__\n");
        iniciarMenu(listadoEmployees);
    }else{
        printf("Error al inicializar el listado\n");
    }
    return 0;
}
