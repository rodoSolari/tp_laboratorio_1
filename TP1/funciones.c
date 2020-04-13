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
    return primerNumero/segundoNumero;
}

long int calcularFactorial(int num){
    long int factorial = 1;

    for(int i=num;i>1;i--){
        factorial=factorial*i;
    }
    return factorial;
}

void realizarOperacion(int opcion,int primerNumero,int segundoNumero){
    while(opcion!=5){
        switch(opcion){
            case 1:
                printf("Ingrese el primer operando : \n");
                scanf("%d",&primerNumero);
                system("cls");
                break;
            case 2:
                printf("Ingrese el segundo operando : \n");
                scanf("%d",&segundoNumero);
                system("cls");
                break;
            case 3:
                system("cls");
                printf(" |a) suma (%d + %d)\n|",primerNumero,segundoNumero);
                printf(" |b) resta (%d - %d) \n|",primerNumero,segundoNumero);
                printf(" |c) multiplicacion (%d * %d)\n|",primerNumero,segundoNumero);
                printf(" |d) division (%d/%d) \n|",primerNumero,segundoNumero);
                printf(" |e) factorial del primer operando\n");
                break;
            case 4:
                system("cls");
                printf(" a)el resultado de la suma : %d + %d es : %d\n",primerNumero,segundoNumero,suma(primerNumero,segundoNumero));
                printf(" b)el resultado de la resta : %d - %d es : %d\n",primerNumero,segundoNumero,resta(primerNumero,segundoNumero));
                printf(" c)el resultado de la multiplicacion : %d * %d es : %d\n",primerNumero,segundoNumero,multiplicar(primerNumero,segundoNumero));
                if(segundoNumero == 0){
                    printf("error : no se puede dividir por cero");
                }else{
                    printf(" d)el resultado de la division : %d / %d es : %f\n",primerNumero,segundoNumero,dividir((float)primerNumero,(float)segundoNumero));
                }
                if(primerNumero<0){
                    printf("Error, no se puede realizar el factorial de %d\n",segundoNumero);
                }else{
                    printf(" e)El factorial de %d es: %ld\n",primerNumero,calcularFactorial(primerNumero));
                }
                if(primerNumero<0){
                    printf("Error, no se puede realizar el factorial de %d\n",segundoNumero);
                }else{
                    printf(" el factorial de %d es: %ld\n",segundoNumero,calcularFactorial(segundoNumero));
                }
                break;
            default:
                printf("Opcion incorrecta : por favor ingrese un numero valido");
        }
        imprimirMenu(primerNumero,segundoNumero);
        scanf("%d", &opcion);
    }
}
