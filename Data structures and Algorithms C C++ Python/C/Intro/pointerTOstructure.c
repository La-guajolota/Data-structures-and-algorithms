/*
Pointers can be used to access the various elements 
of a structure. The various elements of a structure 
are accessed by pointer using -> operator.
*/

#include <stdio.h>

struct student{
    int rollNo;
    char* firstName;
    char* lastName;
};

int main(){
    int i=0;
    struct student A;//Instancia de la estructura
    struct student* ptrSTUD;//Puntero a un dato tipo student

    ptrSTUD = &A;

    ptrSTUD->rollNo = 1;
    ptrSTUD->firstName = "Juan";
    ptrSTUD->lastName = "Pepe";

    printf("Roll No: %d Student Name: %s %s",ptrSTUD->rollNo,ptrSTUD->firstName,ptrSTUD->lastName);

    return 0;
}
