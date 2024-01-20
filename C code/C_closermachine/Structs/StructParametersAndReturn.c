#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct myStruct
{
    char name[25];
    int age;
};

void addToAge(struct myStruct person)
{
    person.age = person.age + 1;
}

/*
    Notice that what happens is that the new struct me is set to harry, 19 by the
    return value of the person struct in the function.
    !The original struct is not returned, only its values are.
*/
struct myStruct makeperson(char *name, int age)
{
    struct myStruct person;
    strcpy(person.name, name);
    person.age = age;

    return person;
}

int main()
{
    struct myStruct P1 = makeperson("PEPE", 21);
    printf("%s de %d años\n", P1.name, P1.age);

    return 0;
}