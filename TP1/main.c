#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(){
    int primerOperando;
    int segundoOperando;
    int opcion;
    printf("Ingrese el primer operando : \n");
    scanf("%d",&primerOperando);
    printf("Ingrese el segundo operando : \n");
    scanf("%d",&segundoOperando);

    imprimirMenu();
    scanf("%d",&opcion);
    realizarOperacion(opcion,primerOperando,segundoOperando);
    return 0;
}
