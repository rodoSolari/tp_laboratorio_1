#include <stdio.h>
#include <stdlib.h>

void imprimirMenu(float primerNumero,float segundoNumero){
    printf("|Ingrese el numero de la opcion que quiera realizar :\n");
    printf("\n");
    printf(" -----------CALCULADORA------------ \n");
    printf("1)Ingresar primer operando  :  A = %.2f\n", primerNumero);
    printf("2)Ingresar segundo operando  : B = %.2f\n", segundoNumero);
    printf("3)calcular todas las operaciones: \n");
    printf("4)Informar resultados\n");
    printf("5) salir \n");
    printf("|                                   \n");
    printf(" ---------------------------------- \n");
}

float sumar(float primerNumero,float segundoNumero){
    return primerNumero+segundoNumero;
}

float restar(float primerNumero,float segundoNumero){
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
    int activarInformeResultado = 0; //se ultiliza para que realice primero las operaciones para luego activar la opcion 4
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
                float suma = sumar(primerNumero,segundoNumero);
                float resta = restar(primerNumero,segundoNumero);
                float multiplicacion = multiplicar(primerNumero,segundoNumero);
                float division = division = dividir(primerNumero,segundoNumero);;
                unsigned long int factorialPrimero;
                unsigned long int factorialSegundo;
                printf(" |a) suma (%.2f + %.2f)\n|",primerNumero,segundoNumero);
                printf(" |b) resta (%.2f - %.2f) \n|",primerNumero,segundoNumero);
                printf(" |c) multiplicacion (%.2f * %.2f)\n|",primerNumero,segundoNumero);
                printf(" |d) division (%.2f/%.2f) \n|",primerNumero,segundoNumero);
                printf(" |e) factorial de A = %.2f y B = %.2f\n",primerNumero,segundoNumero);
                factorialPrimero = calcularFactorial((int)primerNumero);
                factorialSegundo = calcularFactorial((int)segundoNumero);
                activarInformeResultado = 1;   //para poder informar los resultados activando la opcion 4
                break;
            case 4:
                if(activarInformeResultado){ //si el usuario ingreso la opcion 3 para realizar las operaciones, entonces se informan los resultados
                    system("cls");
                    printf(" a)el resultado de la suma : %.2f + %.2f es : %.2f\n",primerNumero,segundoNumero,suma);
                    printf(" b)el resultado de la resta : %.2f - %.2f es : %.2f\n",primerNumero,segundoNumero,resta);
                    printf(" c)el resultado de la multiplicacion : %.2f * %.2f es : %.2f\n",primerNumero,segundoNumero,multiplicacion);
                    if(segundoNumero == 0){
                        printf(" d)error : no se puede dividir por cero\n");
                    }else{
                        printf(" d)el resultado de la division : %.2f / %.2f es : %f\n",primerNumero,segundoNumero,division);
                    }
                    if(primerNumero<0){
                        printf("    e)Factorial: Error, no se puede realizar el factorial de %d\n",(int)segundoNumero);
                    }else{
                        printf(" e)El factorial de %d es: %lu\n",(int)primerNumero,factorialPrimero);
                    }
                    if(primerNumero<0){
                        printf(" e)Error, no se puede realizar el factorial de %d\n",(int)segundoNumero);
                    }else{
                        printf(" el factorial de %d es: %lu\n",(int)segundoNumero,factorialSegundo);
                    }
                }else{
                    printf("por favor, ingrese la opcion 3 para realizar las operaciones\n");
                }
                activarInformeResultado = 0;  // se vuelve a reiniciar por si ingresa algun cambio en los numeros
                break;
            default:
                printf("Opcion incorrecta : por favor ingrese un numero valido\n");
        }
        imprimirMenu(primerNumero,segundoNumero);
        scanf("%d", &opcion);
    }
}
