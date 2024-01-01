/*
 * Autor: Adrián Silva Palafox
 * Fecha: 30/12/2023
 * Descripción: Metodos para trabajar con listas enlazadas circulares
 *              aplicaremos la estructura para resolver el Josephus problem
 * Versión: 0.0.1
 */

#include <stdio.h>
#include <stdlib.h>

struct node{//Tipo de dato nodo
    int key;//Elementos de tipo int
    struct node *next;//Siguiente nodo
};

/********************************
En este ejemplo se tendra en 
uso la convencion de contar con 
un nodode glue para hacer circular 
la lista en lazada. Este nodo une al primer
nodo y al ultimo nodo
********************************/
struct node *glue, *t;//Punteros del tipo node

void linklist_init(){//Inicializa una lista enlazada
    glue = (struct node*) malloc(sizeof(struct node));//heade apunta a un NUEVO espacio de memoria del tipo node
    
    glue->next = glue;
    glue->key = 0; //El nodo enlace contiene el 0 en este caso
}

struct node *insert_after(int v, struct node *t){//Agregamos un nuevo nodo a la lista
    struct node *x;
    x = (struct node*) malloc(sizeof(struct node));//x apunta a un NUEVO espacio de memoria del tipo node
    
    x->key = v;//Este nuevo nodo almacena el elemeto v
    x->next = t->next;//Apuntara a donde anterior mente lo hacia el nodo a su izquierda
    t->next = x;

    return x;//Regresamos el puntero x
}

//Testeo implementacion
int main(){

    //Inicializamos el tipo de dato lista enlazada
    linklist_init();

    int N, M, i;
    // Solicitud de entrada
    printf("Ingrese el número de personas (N) y la primera muerta (M): ");
    scanf("%d %d", &N, &M);

    //Agregar 1 al N
    struct node *aux;
    aux = insert_after(1,glue);
    for (int i=2; i<=N; i++){

        aux = insert_after(i,aux);

    }

    //Revisa todos los nodos de la lista enlazada
    aux = glue->next;
    do{
        
        printf("Nodo con elemento: %d\n",aux->key);
        printf("Nodo apunta a esta direccion: %x\n",aux->next);

        aux = aux->next;//Siguiente nodo

    } while(aux->next != glue);    
    //Ultimo nodo antes de z
    printf("Nodo con elemento: %d\n",aux->key);
    printf("Nodo apunta a esta direccion: %x\n",aux->next);

    //Comienza el suicidio colectivo
    printf("\n Las kills son en este orden: \n");
    aux->next = glue;
    while (aux != aux->next){//Mientras la lista no tenga elementos un solo nodo
        
        for(i=1;i<M;i++) aux = aux->next;//Avanzamos a un nodo antes que el M
        printf("Muere el nodo: %d \n", aux->next->key);// M
        glue = aux->next; //El puntero nodo glue ahora es el nodo M
        aux->next = aux->next->next;// Nodo M-1 apunta al nodo M+1 
        free(glue);//Matamos 

    }
    

    printf("SOBREVIVIMETE ES: %d \n", aux->key);

    system("pause");
    return 0;
}