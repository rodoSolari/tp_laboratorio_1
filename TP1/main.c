#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    int opcion;
    int primerNumero = 0;
    int segundoNumero = 0;
    imprimirMenu(primerNumero,segundoNumero);
    scanf("%d", &opcion);
    realizarOperacion(opcion,primerNumero,segundoNumero);
    return 0;
}
