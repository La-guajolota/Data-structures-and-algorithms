#include <stdio.h>
#include <stdlib.h>

/*
* Several issues surround the free function
that encourage some programmers to create
their own version of this function. The free function does not check the pointer passed
to see whether it is NULL and does not set the pointer to NULL before it returns. Setting
a pointer to NULL after freeing is a good practice.

todo: Using the void type
allows all types of pointers to be passed. However, we get a warning
if we do not explicitly cast the pointer type to
void when we call the function. If we explicitly perform the cast, then the warning goes
away.

!The safeFree macro,
shown below, calls the saferFree function with this cast and uses
the address-of operator, thus alleviating the need for a function’s user to perform the
cast and to pass the pointer’s address.

TODO: #define safeFree(p) saferFree((void**)&(p))
*/
void saferFree(void **pp)
{
    if (pp != NULL && *pp != NULL)
    {
        free(*pp);
        *pp = NULL;
    }
}

int main()
{
    int *pi;
    pi = (int *)malloc(sizeof(int));
    *pi = 5;

    printf("Before: %p\n", pi);
    saferFree((void **)&(pi));
    printf("After: %p\n", pi);
    saferFree((void **)&(pi));

    /*
    Assuming malloc returned memory from address 1000, the output of this sequence will
    be 1000 and then 0. The second use of the safeFree macro with a NULL value does not
    terminate the application, as the function detects and ignores it.
    */

    return (EXIT_SUCCESS);
}