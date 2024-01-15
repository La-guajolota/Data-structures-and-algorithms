#include <stdio.h>

int main()
{
    //! This means you can’t assign to it
    const int myvar = 42;

    /*
        !volatile
            Una variable que puede cambiar por
            acciones externas

            Typically a volatile variable corresponds to
            some
        !hardware register or memory location
            that is being changed by the hardware.
            You need to declare such a variable as volatile to stop the
            compiler from assuming that it doesn’t change between reads

            **    In this case the compiler could well remove the second a=time instruction on
                the grounds that time cannot have changed. To make sure that this doesn’t
                happen time has to be declared as:

                !volatile int time;
    */
    int time, a;
    a = time;
    // do something else that doesn’t assign to time; ...
    a = time;

    // A very common use of volatile is to make sure a null for loop isn’t optimized
    // away. That is:

    /*
        is usually not removed by an optimizing compiler but without the volatile it
        often is silently removed leaving the programmer wondering why the timing
        loop isn't slowing the program down.
    */
    for (volatile int i; i < 500; i++)
    {
    };

    return 0;
}