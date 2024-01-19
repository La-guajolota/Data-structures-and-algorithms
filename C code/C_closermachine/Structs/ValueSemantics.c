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
    struct myStruct person = {.name = "Juan", .age = 9999};

    me.age = 21;
    /*
        Setting the name field is just as easy, but being a string you need to use
        strcpy to set it to a
        !string literal
    */
    strcpy(me.name, "Adrián");

        return 0;
}