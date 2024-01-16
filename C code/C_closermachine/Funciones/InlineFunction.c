/*
Functions are the best way to organize your program – a function for every
identifiable task. Some programmers worry that having so many functions is
inefficient. The overhead is the time taken to call the function and the time
for the return. In practice this overhead is usually well worth the
improvement in program maintainability. However, sometimes a function
does so little that it it seems that it might be better to code it each time it is
needed. Inline functions give you the best of both worlds, but they were only
introduced in C99.

Any function that is marked as inline has its call expanded as if its body had
been written in place of the call. However, things aren’t quite as simple as
this. The inline qualifier is only a hint to the compiler to inline the function.
If the compiler decides not to then you will get an error from the linker as
there is no non-inline version of the function defined. To avoid this you can
mark a function as static
*/
#include <stdio.h>

static inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    int c = add(2, 3);

    printf("%d \n", c);

    return 0;
}