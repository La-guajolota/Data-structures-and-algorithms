#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mystruct
{
    char name[25];
    int age;
};

void addToAge(struct mystruct *person)
{
    (*person).age = (*person).age + 1;
}

/*
You can use a pointer to struct to return a struct but as in the case of an
array the struct so returned cannot be a local variable. In other words you
have to use malloc to allocate the memory on the heap.
For example, the makePerson function can be rewritten to create a struct on
the heap:
*/
struct mystruct *makeperson(char *name, int age)
{
    struct mystruct *newPerson = (struct mystruct *)malloc(sizeof(struct mystruct));
    strcpy((*newPerson).name, name);
    (*newPerson).age = age;

    return newPerson;
}

int main()
{
    struct mystruct Me = {"Adrián", 21};
    struct mystruct *ptrMyStruct; // Puntero de tipo mystruct

    addToAge(&Me); // Aunque es solo necesario una direccion de memoria
    printf("%s de %d años\n", Me.name, Me.age);

    ptrMyStruct = makeperson("jUAN PEPE", 123);
    printf("%s de %d años\n", (*ptrMyStruct).name, (*ptrMyStruct).age);

    addToAge(ptrMyStruct);
    printf("%s de %d\n", ptrMyStruct->name, ptrMyStruct->age); // Otra notacion menos engorrosa
    return 0;
}