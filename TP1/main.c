#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    int opcion;
    int primerNumero = 0;
    int segundoNumero = 0;
    imprimirMenu(primerNumero,segundoNumero);  //inicializo el menu con los 2 numeros igual a cero
    scanf("%d", &opcion);
    realizarOperacion(opcion,primerNumero,segundoNumero);
    return 0;
}
