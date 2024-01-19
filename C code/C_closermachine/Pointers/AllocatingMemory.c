#include <stdio.h>
#include <stdlib.h>

/*
To recap:

!The stack
is often referred to as automatic or auto memory because it
is what a program gets to use by default. For example, any local
variables that you create within a function are allocated on the stack.
It is in the nature of stack memory that it can only be accessed by the
parts of the program that it was allocated to. So only a function can
access the local variables it creates.

!Heap memory:
is accessible from any part of a program, irrespective of
what allocated it. This is one of the things that makes it useful. The
other useful characteristic of the heap is that you can reallocate or
deallocate any memory you are using. This makes it very powerful
and very general.
*/
int main()
{
    void *pointer = malloc(100); // block of 100 bytes
    printf("%p\n", pointer);

    pointer = realloc(pointer, 200); // rellocate it to 200 bytes
    printf("%p\n", pointer);

    free(pointer); // Liberamos la memoria

    return 0;
}