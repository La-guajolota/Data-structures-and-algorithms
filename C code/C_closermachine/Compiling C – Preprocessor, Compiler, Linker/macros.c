#include <stdio.h>

#define PI 3.14159

#define pi(n) 3.14159 * n // Function macros

#define Hola(n) "Hola veces n"

#define MUL(A, B) (A) * (B)
#define SUM(A, B) (A) + (B)

/*
Finally the #, or stringizing operator, converts a parameter into a string
constant, i.e. a quoted string, without expanding it
*/
#define MKSTRING(s) #s

/*
The ## token-pasting operator allows concatenation of parameters. In this
case the arguments are expanded before being concatenated.
*/
#define CREATSTRUCT(type, name) \
    type name;                  \
    type##*name##p

CREATSTRUCT(struct mystruct, myvar);

int main()
{
    int x = pi(2); // todo: Notice that macros don’t have any idea of data type

    printf("%s\n", Hola(10));

    int r = SUM(MUL(x, 6), 2);

    printf(MKSTRING(HOLASSS !!!));

    return 0;
}