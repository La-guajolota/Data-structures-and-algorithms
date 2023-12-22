/*
    A singly linked list consists of several nodes that are connected through pointers
    As you can see, a node of a singly linked list is a structure composed of two parts:
    
    ^Data: This can be one or more variables (also called members) of integer, float,
    string, or any data type. To keep the program simple, we will take data as a
    single variable of the integer type.
    
    ^Pointer: This will point to the structure of the type node. Let's call this
    pointer next in this program, though it can be under any name

*/

/*
    We will use bubble sort for sorting the linked list. Bubble sort is a sequential sorting
    technique that sorts by comparing adjacent elements. It compares the first element with the
    second element, the second element with the third element, and so on. The elements are
    interchanged if they are not in the preferred order. For example, if you are sorting elements
    into ascending order and the first element is larger than the second element, their values
    will be interchanged. Similarly, if the second element is larger than the third element, their
    values will be interchanged too.
    This way, you will find that, by the end of the first iteration, the largest value will bubble
    down towards the end of the list. After the second iteration, the second largest value will be
    bubbled down to the end of the list. In all, n-1 iterations will be required to sort the n
    elements using bubble sort algorithm.
    Let's understand the steps in creating and sorting a singly linked list.
*/

/*
    Las listas enlazadas son estructuras de datos ampliamente utilizadas en programación por varias razones. 
    A continuación, se presentan algunos casos comunes en los que se utilizan listas enlazadas:

    1. **Inserción y Eliminación Eficiente:**
    Las listas enlazadas permiten una inserción y eliminación eficiente de elementos en cualquier posición, incluso 
    en el medio de la lista, ya que no es necesario mover o reorganizar elementos contiguos, como en el caso de un array.

    2. **Tamaño Dinámico:**
    Las listas enlazadas tienen un tamaño dinámico. Pueden crecer o disminuir de tamaño fácilmente durante la ejecución del 
    programa, ya que la memoria se asigna y libera dinámicamente.

    3. **Acceso Aleatorio no Requerido:**
    Si el acceso aleatorio a los elementos no es un requisito importante para una aplicación y la mayoría de las operaciones 
    se centran en la inserción, eliminación y recorrido secuencial, las listas enlazadas pueden ser más eficientes que los arrays.

    4. **Implementación de Pilas y Colas:**
    Las listas enlazadas se utilizan para implementar estructuras de datos como pilas y colas de manera eficiente. En una 
    pila, los elementos se agregan y eliminan desde un extremo, mientras que en una cola se agregan en un extremo y se eliminan desde el otro.

    5. **Memoria Fragmentada:**
    Si la memoria está fragmentada y no hay un bloque continuo de memoria disponible para almacenar una estructura de datos, las 
    listas enlazadas permiten utilizar bloques de memoria dispersos.

    6. **Implementación de Estructuras de Datos más Complejas:**
    Las listas enlazadas se utilizan como base para implementar estructuras de datos más complejas, como árboles, grafos y listas 
    doblemente enlazadas.

    7. **Ordenamiento Eficiente:**
    Al insertar o eliminar elementos en el medio de una lista enlazada, el proceso es más eficiente que en un array, especialmente cuando 
    se trata de grandes cantidades de datos.

    8. **Manejo de Elementos de Tamaño Variable:**
    Las listas enlazadas permiten el almacenamiento eficiente de elementos de tamaño variable, ya que cada nodo puede contener datos de diferente longitud.

    En resumen, las listas enlazadas son útiles en situaciones donde se requieren operaciones eficientes de inserción y eliminación, se 
    necesita un tamaño dinámico, o se está implementando una estructura de datos más compleja. Sin embargo, es importante señalar que también 
    ienen desventajas, como el acceso secuencial y la asignación de memoria adicional para los punteros. La elección entre listas enlazadas y otras 
    estructuras de datos depende de los requisitos específicos de cada aplicación.
*/

#include<stdio.h>
#include <stdlib.h>//Necesaria para malloc
struct node{
    int data;//Elemento a ordenar
    struct node *next;//ptr a siguiente nodo
};

void main(){

    struct node *temp1, *temp2, *t, *newNode, *startList;//Punteros a datos de tipo node
    int n,k,i,j;

    /*
    Un puntero, su valor inicial no está definido y puede contener 
    cualquier dirección de memoria, incluido un valor no válido. Por lo tanto, es 
    una buena práctica inicializar un puntero antes de usarlo.
    */
    startList = NULL;//Inicializamos la lista como vacia

    printf("How many elements are there in the linked list ?");
    scanf("%d",&n);
    printf("Enter elements in the linked list\n");

    for(i=1;i<=n;i++){
        if(startList==NULL){//UNA UNICA VEZ!!!
            
            //MALLOC Devuelve un puntero genérico (void *) que apunta al inicio del bloque de memoria asignado.
                    //CASTING     //Asignacion de memoria (Se regresa un puntero genrico)
            newNode=(struct node *)malloc(sizeof(struct node));//Inicialización dinámica con malloc 
            scanf("%d",&newNode->data);//Agregamos elemento

            newNode->next=NULL;//El contenido del nodo siguiente es vacio

            /*
                Two pointers, startList and temp1, are set to point at the first node. The4.
                startList pointer will keep pointing at the first node of the linked list. The
                temp1 pointer will be used to link the nodes 
            */

            startList = newNode;//startList almacena la direccion del nodo
            temp1=startList;//temp1 almacena la direccion de startlist

        }else{// DEMAS NUEVOS NODOS!!!
            newNode=(struct node *)malloc(sizeof(struct node));
            scanf("%d",&newNode->data);

            newNode->next=NULL;//El contenido del nodo siguiente es vacio

            /*
                To connect the newly created nodes, the following two tasks are performed:
        
                1 The next member of temp1 is set to point at the newly created node.
                2 The temp1 pointer is shifted to point at the newly created node
            */

            temp1->next = newNode;//Enlazamiento entre nodo anterior con recientement creado
            temp1=newNode;//Apuunta al ultimo nodo creado
        }
    }

    /*
        When the for loop gets over, we will have a singly linked list with its first node6.
        pointed at by startList, and the next pointer of the last node pointing at
        NULL. This linked list is ready to undergo the sorting procedure.
    */

   //ALGORIMO BURBUJA
    for(i=n-2;i>=0;i--){//Iniciamos iteracion Enecima sucecion de permutaciones

        temp1=startList;//Apunta al primer nodo
        temp2=temp1->next;//Apunta al siguiente nodo que se apuna desde temp1

        for(j=0;j<=i;j++){//buble down de inicio a fin

            if(temp1->data > temp2->data){//Comparamos
                k=temp1->data;//El mayor que en rl buffer K latch
                temp1->data=temp2->data;//Cambiamos de lugar los data
                temp2->data=k;//Se pasa el mayor al nodo contiguo
            }
            temp1=temp2;//Nodo contiguo pasa a ser el principal
            temp2=temp2->next;//Nuevo nodo contiguo
        }
    }
    
    printf("Sorted order is: \n");
    t=startList;
    
    while(t!=NULL){//Iteramos
        printf("%d\t",t->data);
        t=t->next;
    }

    /*
        En este ejemplo, se asigna dinámicamente memoria, pero la memoria nunca se 
        libera usando free. Aunque el sistema operativo liberará automáticamente la memoria cuando 
        el programa termine, es una buena práctica liberar la memoria manualmente antes de que el 
        programa finalice.
    */
    // Olvidar liberar la memoria
    // free(p); <-- Esto falta
    temp1=startList;//Apunta al primer nodo
    temp2=temp1->next;//Apunta al segundo nodo
    do{

        free(temp1);//Liberamos espacio de memoria de N nodo
        temp1=temp2;//Nodo contiguo pasa a ser el principal
        temp2=temp2->next;//Nuevo nodo contiguo

    } while (temp2->next !=  NULL);//Hasta llegar al ultimo nodo
    free(temp1);//Liberamos el espcio del ultimo nodo

    system("pause");
}