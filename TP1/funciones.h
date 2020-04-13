#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//imprime el menu de la calculadora con los 2 numeros ingresados actualizados
void imprimirMenu(int primerNumero,int segundoNumero);

//Devuelve la suma de 2 numeros
int suma(int primerNumero, int segundoNumero);

//Devuelve la resta de 2 numeros
int resta(int primerNumero, int segundoNumero);

//Devuelve la multiplicacion de 2 numeros
int multiplicar(int primerNumero, int segundoNumero);

//Devuelve la division de 2 numeros
int dividir(int primerNumero, int segundoNumero);

//devuelve el factorial del primer numero ingresado
int calcularFactorial(int num);

//realizar la operacion que elije el usuario con los 2 numeros ingresados
void realizarOperacion(int opcion,int primerNumero,int segundoNumero);

#endif // FUNCIONES_H_INCLUDED
