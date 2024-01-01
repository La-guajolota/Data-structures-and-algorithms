#include <stdlib.h>
#include <stdio.h>


void main(){

    int i = 10;//Variable de tipo entero que almacena el numero 100
    int *j;//Declaracion de puntero de tipo entero
    printf("Valor contenido en i: %x, direccion de i: %x\n",i,&i);

    /*
        In the case of pointers, & (ampersand) represents the memory address and
        * (asterisk) represents content in the memory address.
    */
    j = &i;//j almacena la direccion de memoria de i
    printf("Valor contenido en j: %x, Valor contenido en *j: %x (El valor a la direccion de memoria que j apunta), direccion de j: %x\n",j,*j,&j);

    int **k;//Esto es deffinir un puntero para un puntero  de tipo  entero
    k=&j;//El puntero k apunta a la direccion de memoria del puntero j, ambos de tipo entero
    printf("Valor contenido en k: %x, Valor contenido en *k: %x (El valor a la direccion de memoria que k apunta), direccion de k: %x\n",k,*k,&k);

    /*
        To display the address of i through k, we need to use *k, because *k means that it will
        display the contents of the memory address pointed at by k. Now, k is pointing at j and the
        content in j is the address of i:
    */
    printf("Address of i  atraves de &i,j,*k = %x %x %x\n",&i,j,*k);

    //Similarly, to display the value of i through k, **k has to be used as follows:
    printf("Value of i is %d %d %d %d A traves de i,*(&i),*j,**k \n",i,*(&i),*j,**k);


    /*
        Es importante tener en cuenta que el tamaño devuelto por sizeof() está en bytes 
        y puede variar según la arquitectura y el compilador utilizados. sizeof() es 
        especialmente útil al trabajar con asignación dinámica de memoria, manipulación
        de datos binarios y operaciones relacionadas con el tamaño de los objetos en 
        memoria.
    */
    int *p;
    printf("sizeof puntero de tipo entero: %d bytes\n",sizeof(p));


    /*
        malloc es una función en C (y en algunos otros lenguajes de programación) que se 
        utiliza para asignar dinámicamente un bloque de memoria en el montón (heap). Su 
        nombre proviene de "memory allocation
    */
   

    system("pause");    
}