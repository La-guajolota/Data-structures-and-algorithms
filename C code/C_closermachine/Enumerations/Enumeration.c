#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum week // An enumeration is just an assignment of integers to labels.
    {
        sunday = 0,
        monday = 1,
        tuesday = 2,
        wednesday = 3,
        thursday = 4,
        friday = 5,
        saturday = 6
    };

    enum week work; // variable del tipo week
    work = friday;
    printf("work: %d\n", work);

    enum week Work_week[7] = {0}; // Arreglo del tipo week
    Work_week[monday] = 9;

    for (enum week day = sunday; day <= saturday; day++)
    {
        printf("Work_week[%d] = %d\n", day, Work_week[day]);
    }

    // Another is to define what looks like a boolean type using:
    enum bool
    {
        false,
        true
    };
    enum bool mybool;

    mybool = true; // Notice that this myBool is still an int and true is 1 and false is 0.

    return 0;
}