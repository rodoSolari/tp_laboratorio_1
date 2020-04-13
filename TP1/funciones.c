#include <stdio.h>
#include <stdlib.h>

void imprimirMenu(int primerNumero,int segundoNumero){
    printf("|Ingrese el numero de la opcion que quiera realizar :\n");
    printf(" -----------CALCULADORA------------ \n");
    printf("1)Ingresar primer operando  :  A = %d\n", primerNumero);
    printf("2)Ingresar segundo operando  : B = %d\n", segundoNumero);
    printf("3)calcular todas las operaciones: \n");
    printf("4)Informar resultados\n");
    printf("5) salir \n");
    printf("|                                   \n");
    printf(" ---------------------------------- \n");
}

int suma(int primerNumero, int segundoNumero){
    return primerNumero+segundoNumero;
}

int resta(int primerNumero, int segundoNumero){
    return primerNumero-segundoNumero;
}

int multiplicar(int primerNumero, int segundoNumero){
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

void realizarOperacion(int opcion, int primerNumero, int segundoNumero){
    while(opcion>5 || opcion <1){
        printf("Opcion incorrecta : por favor ingrese un numero valido");
        imprimirMenu(primerNumero,segundoNumero);
        scanf("%d", &opcion);
    }

    int resultado;
    while(opcion!=5){
        imprimirMenu(primerNumero,segundoNumero);
        switch(opcion){
            case 1:
                printf("Ingrese el primer operando : \n");
                scanf("%d",&primerNumero);
                break;
            case 2:
                printf("Ingrese el segundo operando : \n");
                scanf("%d",&segundoNumero);
                break;
            case 3:
                printf(" |a) suma (%d + %d)\n|",primerNumero,segundoNumero);
                printf(" |b) resta (%d - %d) \n|",primerNumero,segundoNumero);
                printf(" |c) multiplicacion (%d * %d)\n|",primerNumero,segundoNumero);
                printf(" |d) division (%d/%d) \n|",primerNumero,segundoNumero);
                printf(" |e) factorial del primer operando\n");
                break;
            case 4:
                printf(" a)el resultado de la suma : %d + %d es : \n",primerNumero,segundoNumero,suma(primerNumero,segundoNumero));
                printf(" b)el resultado de la resta : %d - %d es : \n",primerNumero,segundoNumero,resta(primerNumero,segundoNumero));
                printf(" c)el resultado de la multiplicacion : %d * %d es : \n",primerNumero,segundoNumero,multiplicar(primerNumero,segundoNumero));
                printf(" d");
                printf(" e)El factorial de %d es: %d y el factorial de %d es %d: %d\n",primerNumero,calcularFactorial(primerNumero),segundoNumero,calcularFactorial(segundoNumero));
                break;
        }
    }
}
