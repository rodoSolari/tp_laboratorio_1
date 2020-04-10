#include <stdio.h>
#include <stdlib.h>

void imprimirMenu(){
    printf("|Ingrese el numero de la opcion que quiera realizar :\n");
    printf(" -----------CALCULADORA------------ \n");
    printf(" |1) suma\n|");
    printf("|2) resta \n|");
    printf("|3) multiplicacion \n|");
    printf("|4) division \n|");
    printf("|5) factorial del primer operando\n");
    printf(" |6) salir \n");
    printf("|                                   \n");
    printf(" ---------------------------------- \n");
}

int suma(int primerNumero, int segundoNumero){
    printf("el resultado de la suma : %d + %d es : ",primerNumero,segundoNumero);
    return primerNumero+segundoNumero;
}

int resta(int primerNumero, int segundoNumero){
    printf("el resultado de la resta : %d - %d es : ",primerNumero,segundoNumero);
    return primerNumero-segundoNumero;
}

int multiplicar(int primerNumero, int segundoNumero){
    printf("el resultado de la multiplicacion : %d * %d es : ",primerNumero,segundoNumero);
    return primerNumero*segundoNumero;
}

float dividir(float primerNumero, float segundoNumero){
    if(segundoNumero == 0){
        printf("error : no se puede dividir por cero");
    }else{
        printf("el resultado de la division : %d / %d es : ",(int)primerNumero,(int)segundoNumero);
        return primerNumero/segundoNumero;
    }
    return primerNumero/segundoNumero;
}

int calcularFactorial(int num){
    int factorial = 1;

    for(int i=num;i>1;i--){
        factorial=factorial*i;
    }
    return factorial;
}

void realizarOperacion(int opcion,int primerOperando, int segundoOperando){
    while(opcion>6 || opcion <1){
        printf("Opcion incorrecta : por favor ingrese un numero valido");
        imprimirMenu();
        scanf("%d", &opcion);
    }
    int resultado;
    if(opcion!=6){
        switch(opcion){
            case 1:
                resultado = suma(primerOperando,segundoOperando);
                printf("%d",resultado);
                break;
            case 2:
                resultado = resta(primerOperando,segundoOperando);
                printf("%d",resultado);
                break;
            case 3:
                resultado = multiplicar(primerOperando,segundoOperando);
                printf("%d",resultado);
                break;
            case 4:
                printf("Casteado :: resultado : %f",dividir((float)primerOperando,(float)segundoOperando));
                break;
            case 5:
                resultado = calcularFactorial(primerOperando);
                printf("%d",resultado);
                break;
        }
        //printf("%d",resultado);
    }
}
