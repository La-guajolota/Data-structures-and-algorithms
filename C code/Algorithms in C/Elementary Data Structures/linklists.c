/*
 * Autor: Adrián Silva Palafox
 * Fecha: 30/12/2023
 * Descripción: Metodos para trabajar con listas enlazadas
 * Versión: 0.1.1
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
un nodode inicio(head) y fin(z)
********************************/
struct node *head, *z, *t;//Punteros del tipo node

void linklist_init(){//Inicializa una lista enlazada
    head = (struct node*) malloc(sizeof(struct node));//heade apunta a un NUEVO espacio de memoria del tipo node
    z = (struct node*) malloc(sizeof(struct node));//z apunta a un NUEVO espacio de memoria del tipo node
    
    head->next = z;//head apunta a z
    z->next = z;//z apunta asi mismo
}

void delete_next(struct node *t){//Elimina el nodo singuiente del nodo al que apunta t
    struct node *deleted_node;
    deleted_node = t->next;

    t->next = t->next->next;//Sacamos de la cadena al nodo no deseado

    //No sea ha liberado la memoria, usamos free!!!
    //Solo se excluyo el nodo de la lista
    free(deleted_node);
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

    //Agregar 1 al 10
    struct node *aux;
    aux = insert_after(1,head);
    for (int i=2; i<=10; i++){

        aux = insert_after(i,aux);

    }

    //Revisa todos los nodos de la lista enlazada
    aux = head->next;
    do{
        
        printf("Nodo con elemento: %d\n",aux->key);
        printf("Nodo apunta a esta direccion: %x\n",aux->next);

        aux = aux->next;//Siguiente nodo

    } while(aux->next != z->next);    
    //Ultimo nodo antes de z
    printf("Nodo con elemento: %d\n",aux->key);
    printf("Nodo apunta a esta direccion: %x\n",aux->next);

    printf("Borramos el nodo 3\n");
    delete_next(head->next->next);//El tercer nodo

    //Revisa todos los nodos de la lista enlazada
    aux = head->next;
    do{
        
        printf("Nodo con elemento: %d\n",aux->key);
        printf("Nodo apunta a esta direccion: %x\n",aux->next);

        aux = aux->next;//Siguiente nodo

    } while(aux->next != z->next);    
    //Ultimo nodo antes de z
    printf("Nodo con elemento: %d\n",aux->key);
    printf("Nodo apunta a esta direccion: %x\n",aux->next);

    return 0;
}