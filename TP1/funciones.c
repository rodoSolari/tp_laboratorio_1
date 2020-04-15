#include <stdio.h>
#include <stdlib.h>

void imprimirMenu(float primerNumero,float segundoNumero){
    printf("|Ingrese el numero de la opcion que quiera realizar :\n");
    printf(" -----------CALCULADORA------------ \n");
    printf("1)Ingresar primer operando  :  A = %.2f\n", primerNumero);
    printf("2)Ingresar segundo operando  : B = %.2f\n", segundoNumero);
    printf("3)calcular todas las operaciones: \n");
    printf("4)Informar resultados\n");
    printf("5) salir \n");
    printf("|                                   \n");
    printf(" ---------------------------------- \n");
}

float suma(float primerNumero,float segundoNumero){
    return primerNumero+segundoNumero;
}

float resta(float primerNumero,float segundoNumero){
    return primerNumero-segundoNumero;
}

float multiplicar(float primerNumero,float segundoNumero){
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

void realizarOperacion(int opcion,float primerNumero, float segundoNumero){
    while(opcion!=5){
        switch(opcion){
            case 1:
                printf("Ingrese el primer operando : \n");
                scanf("%f",&primerNumero);
                system("cls");
                break;
            case 2:
                printf("Ingrese el segundo operando : \n");
                scanf("%f",&segundoNumero);
                system("cls");
                break;
            case 3:
                system("cls");
                printf(" |a) suma (%.2f + %.2f)\n|",primerNumero,segundoNumero);
                printf(" |b) resta (%.2f - %.2f) \n|",primerNumero,segundoNumero);
                printf(" |c) multiplicacion (%.2f * %.2f)\n|",primerNumero,segundoNumero);
                printf(" |d) division (%.2f/%.2f) \n|",primerNumero,segundoNumero);
                printf(" |e) factorial de A = %.2f y B = %.2f\n",primerNumero,segundoNumero);
                break;
            case 4:
                system("cls");
                printf(" a)el resultado de la suma : %.2f + %.2f es : %.2f\n",primerNumero,segundoNumero,suma(primerNumero,segundoNumero));
                printf(" b)el resultado de la resta : %.2f - %.2f es : %.2f\n",primerNumero,segundoNumero,resta(primerNumero,segundoNumero));
                printf(" c)el resultado de la multiplicacion : %.2f * %.2f es : %.2f\n",primerNumero,segundoNumero,multiplicar(primerNumero,segundoNumero));
                if(segundoNumero == 0){
                    printf("error : no se puede dividir por cero");
                }else{
                    printf(" d)el resultado de la division : %.2f / %.2f es : %f\n",primerNumero,segundoNumero,dividir(primerNumero,segundoNumero));
                }
                if(primerNumero<0){
                    printf("Error, no se puede realizar el factorial de %d\n",(int)segundoNumero);
                }else{
                    printf(" e)El factorial de %d es: %ld\n",(int)primerNumero,calcularFactorial((int)primerNumero));
                }
                if(primerNumero<0){
                    printf("Error, no se puede realizar el factorial de %d\n",(int)segundoNumero);
                }else{
                    printf(" el factorial de %d es: %ld\n",(int)segundoNumero,calcularFactorial((int)segundoNumero));
                }
                break;
            default:
                printf("Opcion incorrecta : por favor ingrese un numero valido");
        }
        imprimirMenu(primerNumero,segundoNumero);
        scanf("%d", &opcion);
    }
}
