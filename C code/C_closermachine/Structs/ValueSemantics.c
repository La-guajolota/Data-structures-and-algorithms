#include <stdio.h>
#include <string.h>

struct myStruct
{
    char name[25];
    int age;
};

int main()
{
    struct myStruct me;
    struct myStruct person;

    me.age = 21;
    /*
        Setting the name field is just as easy, but being a string you need to use
        strcpy to set it to a
        !string literal
    */
    strcpy(me.name, "Adrián");
    person = me;

    printf("%d %d\n", me.age, person.age);

    return 0;
}