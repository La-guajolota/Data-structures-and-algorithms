/*
 * Autor: Adrián Silva Palafox
 * Fecha: 29/12/2023
 * Versión: 0.0.1
 */

/*
    Imprimimos los primeros numeros primos
    
    La Criba de Eratóstenes es un algoritmo eficiente para 
    encontrar todos los números primos hasta un cierto límite 

    PSEUDOCODIGO:

    function criba_de_eratostenes(limite):
    // Inicializar una lista de booleanos para marcar los números primos
    primos = [true, true, ..., true] // Una entrada por cada número hasta el límite
    primos[0] = primos[1] = false  // 0 y 1 no son primos

    // Marcar los múltiplos de cada número primo encontrado
    for i desde 2 hasta raiz_cuadrada(limite) hacer
        si primos[i] es true entonces
            // Marcar los múltiplos de i como no primos
            for j desde i * i hasta limite hacer
                primos[j] = false

    // Crear una lista de números primos
    resultado = []
    for cada numero desde 0 hasta limite hacer
        si primos[numero] es true entonces
            resultado.agregar(numero)

    devolver resultado

*/

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(){

    int i, j, a[N+1];

    //Desde el a[2] al a[N] ==> 1
    for (a[1]=0, i=2; i<=N; i++) a[i]=1;//Asumimos todos como primos despues del 1

    for (i=2; i<=N/2; i++){
        
        for (j=2; j<=N/i; j++){
            
            //Un multiplo de un numero no puede ser primo 
            a[i*j] = 0;//No es primo
        }
    }

    for (i=1 ; i<=N; i++){//Imprimimos los que si son primos
        if(a[i]) printf("%4d \n", i);
    }
    
    system("pasuse");
    return 0;
}

/*
Otro refinamiento consiste en generar una lista solo con números impares 
(pues los números pares distintos de 2 se sabe que no son primos), e ir 
tachando los múltiplos de los números primos mediante incrementos de 2p, es decir, los 
múltiplos impares (2k+1)p de cada primo p.
*/