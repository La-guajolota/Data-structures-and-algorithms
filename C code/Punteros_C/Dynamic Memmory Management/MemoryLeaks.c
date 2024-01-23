#include <stdio.h>
#include <stdlib.h>

/*
* A memory leak
occurs when allocated memory is never
used again but is not freed. This can happen when:

!• The memory’s address is lost

!• The free function is never invoked though it
should be (sometimes called a hidden leak)
*/

int main()
{
    /*
    The variable chunk is assigned memory from the heap. However, this memory is not
    freed before another block of memory is assigned to it. Eventually, the application will
    run out of memory and terminate abnormally. At minimum, memory is not being used
    efficiently.
    */

    //// char *chunk;
    ////while (1)
    ////{
    ////chunk = (char *)malloc(1000000);
    ////printf("Allocating\n");
    ////}

    return 0;
}