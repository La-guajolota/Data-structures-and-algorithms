/*

In this recipe, we will make a structure that stores the information of an order placed by a
specific customer. A structure is a user-defined data type that can store several members of
different data types within it. The structure will have members for storing the order
number, email address, and password of the customer:

    struct cart
    {
        int orderno;
        char emailaddress[30];
        char password[30];
    };

The preceding structure is named cart, and comprises three members – orderno of
the int type for storing the order number of the order placed by the customer,
and emailaddress and password of the string type for storing the email address and
password of the customer, respectively.

*/

#include <stdio.h>
#include <stdlib.h>

struct cart
{
    int orderno;
    char emailaddress[30];
    char password[30];
};

void main(){
    struct cart mycart;//Intancia a la estructura
    struct cart *ptrcart, *ptrcust;//Punteros que apuntan a tipos de datos cart
    
    ptrcart = &mycart;//Apunta al objeto mycart

    printf("Enter order number: ");
    scanf("%d",&mycart.orderno);
    printf("Enter email address: ");
    scanf("%s",mycart.emailaddress);
    printf("Enter password: ");
    scanf("%s",mycart.password);

    printf("\nDetails of the customer are as follows:\n");
    printf("Order number : %d\n", ptrcart->orderno);
    printf("Email address : %s\n", ptrcart->emailaddress);
    printf("Password : %s\n", ptrcart->password);

    printf("\nEnter new email address: ");
    scanf("%s",ptrcart->emailaddress);
    printf("Enter new password: ");
    scanf("%s",ptrcart->password);
    printf("\nModified customer's information is:\n");
    printf("Order number: %d\n", mycart.orderno);
    printf("Email address: %s\n", mycart.emailaddress);
    printf("Password: %s\n", mycart.password);

    ptrcust=(struct cart *)malloc(sizeof(struct cart));
    
    printf("\nEnter information of another customer:\n");
    printf("Enter order number: ");
    scanf("%d",&ptrcust->orderno);
    printf("Enter email address: ");
    scanf("%s",ptrcust->emailaddress);
    printf("Enter password: ");
    scanf("%s",ptrcust->password);
    printf("\nDetails of the second customer are as follows:\n");
    printf("Order number : %d\n", ptrcust->orderno);
    printf("Email address : %s\n", ptrcust->emailaddress);
    printf("Password : %s\n", ptrcust->password);

    system("pause");
}