#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Address
{
    char street[25];
    char zip[25];
};

typedef struct Person
{
    char name[25];
    struct Address add;
} Person_t;

int main()
{
    Person_t me;
    strcpy(me.name, "Adrián");
    strcpy(me.add.street, "Casa_canton");
    strcpy(me.add.zip, "Comuna_lechuguera");

    printf("%s de %s de %s\n", me.name, me.add.street, me.add.zip);

    Person_t *ptr_persona;
    ptr_persona = &me;
    strcpy(ptr_persona->name, "Juan Pepe");

    printf("%s de %s de %s\n", me.name, me.add.street, me.add.zip);

    return 0;
}