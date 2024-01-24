#include <stdio.h>

void fun2();
void fun1();

int main()
{
    int var4;
    printf("Program stack example MAIN()\n");
    fun1();

    return 0;
}

void fun2()
{
    int *var1;
    int var2;
    printf("Program stack example FUNC2()\n");
}

void fun1()
{
    int *var3;
    printf("Program stack example FUN1()\n");
    fun2();
}