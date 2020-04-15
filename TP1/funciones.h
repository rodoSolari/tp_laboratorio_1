#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//imprime el menu de la calculadora con los 2 numeros ingresados actualizados
void imprimirMenu(float primerNumero,float segundoNumero);

//Devuelve la suma de 2 numeros
float sumar(float primerNumero,float segundoNumero);

//Devuelve la resta de 2 numeros
float restar(float primerNumero,float segundoNumero);

//Devuelve la multiplicacion de 2 numeros
float multiplicar(float primerNumero,float segundoNumero);

//Devuelve la division de 2 numeros
float dividir(float primerNumero,float segundoNumero);

//devuelve el factorial del primer numero ingresado
long int calcularFactorial(int num);

//realizar la operacion que elije el usuario con los 2 numeros ingresados
void realizarOperacion(int opcion,float primerNumero,float segundoNumero);

#endif // FUNCIONES_H_INCLUDED
