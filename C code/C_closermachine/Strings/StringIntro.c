#include <stdio.h>

int main()
{
    /*
    myArray is a standard char array and myString is a null-terminated char array
    i.e. a string. Notice that single quotes are used for character literals and \0 is
    the escape character for a null char. Notice also that myString is one element
    longer than myArray and this is the small overhead of using null-terminated
    strings
    */
    char myArray[3] = {'a', 'b', 'c'};
    char myString[4] = {'a', 'b', 'c', '\0'};
    printf("%s\n", myString);

    myString[0] = 'z';
    printf("%s\n", myString);

    char string[] = "Este es my string"; // Automaticamente se le agrega un \0 en el ultimo lugar

    return 0;
}