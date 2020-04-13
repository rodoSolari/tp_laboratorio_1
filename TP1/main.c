#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    int opcion;
    imprimirMenu(0,0);
    scanf("%d",&opcion);
    realizarOperacion(opcion,0,0);
    return 0;
}
