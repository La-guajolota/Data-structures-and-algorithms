/*
A Stack is a structure that can be implemented with arrays as well as linked lists. It is a sort
of a bucket where the value you enter will be added at the bottom. The next item that you
add to a stack will be kept just above the item that was added previously. The procedure of
adding a value to the stack is called a push operation and the procedure of getting a value
out of the stack is called a pop operation. The location where the value can be added or
taken out of the stack is pointed at by a pointer called top. The value of the top pointer is -1
when the stack is empty

When the push operation is executed, the value of top is incremented by 1, so that it can
point to the location in the stack where the value can be pushed:

Now, the next value that will be pushed will be kept above value 1. More precisely, the
value of the top pointer will be incremented by 1, making its value 1, and the next value
will be pushed to the stack[1] location, as follows:

So, you can see that the stack is a Last In First Out (LIFO) structure; that is, the last value
that was pushed sits at the top.
Now, when we execute a pop operation, the value at the top, that is, value 2, will be
popped out first, followed by the popping out of value 1. Basically, in the pop operation,
the value pointed at by the top pointer is taken out, and then the value of top is
decremented by 1 so that it can point at the next value to be popped out.
*/
#include <stdlib.h>
# include <stdio.h>
# include <math.h>
#define max 10 //Cantidad maxima del stack

int top=-1;//Iniciamos con stack vacio
int stack[max];//Stack

//Metodos para la estuctura de dato Stack
void push(int);//Agrgamos 
int pop();//Removemos

int findarmstrong(int );//Encontramos un numero de armstrong

void main(){
    int n;

    printf("Enter a number ");
    scanf("%d",&n);

    if (findarmstrong(n))
        printf("%d is an armstrong number \n",n);
    else printf("%d is not an armstrong number \n", n);

    system("pause");
}

int findarmstrong(int numb){
    int j, remainder, temp,count,value;
    temp=numb;
    count=0;

    while(numb >0){//Pushamos los digitos al stack
        remainder=numb%10;
        push(remainder);
        count++;
        numb=numb/10;
    }

    numb=temp;
    value=0;

    while(top >=0){//Popeamos los digitos LIFO
        j=pop();
        value=value+pow(j,count);
    }

    if(value==numb)return 1;
    else return 0;
}

/*********************************************
Funciones para la estructura de datos en STACK
*********************************************/

void push(int m){
    top++;//Aumentamos el indicador
    stack[top]=m;//Agregamso al nuevo elemento al stack
}

int pop(){
    int j;

    if(top==-1)return(top);//Si esta vacio el stack
    else{
        j=stack[top];//Elemento en el tope
        top--;//Disminuimos el indicador
        return(j);//Regresamso ese elemento que se removio
    }
}