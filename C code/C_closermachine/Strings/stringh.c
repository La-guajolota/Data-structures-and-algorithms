#include <stdio.h>
#include <string.h>

int main()
{
    char string1[10] = "abc";
    printf("%d cantidad de caracteres\n", strlen(string1));

    /*
    Other commonly used string functions are:
         strcat - concatenate two strings
         strchr - string scanning operation
         strcmp - compare two strings
         strcpy - copy a string
    Using these is generally obvious.
    */
    //! Cocatenar
    char string2[] = "_extra";
    strcat(string1, string2);
    printf("Nuevo contenido agregado en string1:%s\n", string1);

    //! Scaneo
    char *position = strchr(string1, '_');
    printf("Adress: %x Contenido: %c\n", position, *position);

    //! Comparamaos dos strings
    char stringA[] = "HOLA SOY ADRIAN";
    char stringB[] = "123";
    int rslt = strcmp(stringB, stringA);
    printf("rslt: %d\n", rslt);

    //! Copiamos string
    char copy[10] = "holaHola";
    strcpy(copy, "copia");
    printf("%s\n", copy);

    return 0;
}