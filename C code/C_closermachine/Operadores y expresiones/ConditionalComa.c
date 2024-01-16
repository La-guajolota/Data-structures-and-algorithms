#include <stdio.h>

int main()
{
    /*
        ********************************************************
        * De la forma: Es una alternativa forma del statement IF
        * ******************************************************
            ! expression1 ? expression2 : expression3
            first evaluates expression1 and treats it as a Boolean. If this is true, i.e., nonzero,
            then the result is expression2, but if it is false, i.e., zero, then the result is expression3.
    */
    int a = 4, size = 3;
    int ans1 = (a < 0) ? 1 : 0;
    printf("ans1: %d\n", ans1);

    /*
        The advantage of the conditional expression is that it is an expression and
        can be used as part of a larger expression. For example:
    */
    int ans2 = (a < 0) ? 1 : -1 * size; // Adding parentheses for clarity
    printf("ans2: %d\n", ans2);

    /*
        The comma operator, as distinct from other uses of the comma, is perhaps the
        most puzzling in C. The comma is only treated as an operator if it is part of an
        expression:

        !expression1, expression2;

        First expression1 is evaluated and the result is thrown away. Then
        expression2 is evaluated and it is returned as the result.

        The obvious answer is that you want it when an expression has a side effect
        that you are interested in more than its result.
        For example:
    */
    int i = 2, b = 1;
    int ans3 = (i++, b + i);
    printf("ans3: %d", ans3);

    return 0;
}
