/*
The Tower of Hanoi (also called the Tower of Brahma) We are given three
rods and N number of disks, initially all the disks are added to first rod (the
leftmost one) in decreasing size order. The objective is to transfer the entire
stack of disks from first tower to third tower (the rightmost one), moving
only one disk at a time and never a larger one onto a smaller.
*/

#include <stdio.h>

void towerOfHanoi(int num, char src, char dst, char temp);

int main(){

    int num=4;
    printf("Secuencias del Hanoi: \n");
    towerOfHanoi(num, 'A', 'C', 'B');

    return 0;
}
                               //SON LOS PEGS
                  //n discos   source    desteny    tempory
void towerOfHanoi(int num, char src, char dst, char temp){

    if(num<1) return;//como una condición de salida temprana

    towerOfHanoi(num-1,src,temp,dst);//from temp tp dst

    printf("\n Move disk %d from peg %c to peg %c",num,src,dst);

    towerOfHanoi(num-1,temp,dst,src);//from dst to src
}

/*
TowerOfHanoi problem if we want to move N disks from source
to destination, then we first move N-1 disks from source to temp, then move
the lowest Nth disk from source to destination. Then will move N-1 disks
from temp to destination.
*/