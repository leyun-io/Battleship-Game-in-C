#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*This function create a list by creating the head node using memory 
allocation. Rember to free it*/
list_t* createList()
{
    return calloc(1, sizeof(list_t));
}

/**************************************************/

/*
This function add value into the list by creating a new node and added it to 
the last location of the list. It takes in two arguments, first is the list 
which the new node will be added in, the second argument is the item to add 
into the node, it is a void data tye which means that any data type can be 
added to the list. 
*/
void addToList(list_t* list, void* itemToAdd)
{
    /*
    current: a list node data type created by typedef, it is the pointer node 
    for looping purpose.
    newNode: a list node data type and is use to store the value to add into 
    the list. 
    */
    list_node_t* current;
    list_node_t* newNode;

    /*Locate memory for the new node so that it could added new value into it 
    and will point to the next mode.*/
    newNode = calloc(1, sizeof(list_node_t));
    /*The value of the new node will store the value which about to add in*/
    newNode->value = itemToAdd;

    /*If the list is empty and the new node will be the head of the list.*/
    if (list->head == NULL)
    {
        list->head = newNode;
    }

    /*If there are already value inside the list, so we will add the new node into the last place of the list. */
    else
    {
        /*Point the current node to the head of the list*/
        current = list->head;
        /*Loop through the list to reach to the end of the list.*/
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        current = current->next;
    }
    (list->count)++;
}

/**************************************************/

/*Because each new ndoe we added is created by calloc which will store a memory 
location for in the memory space. Hence, after the program ends, we should free 
those memory allocated. */
void freeList(list_t* list)
{
    /*
    Because we create a list using calloc, and every node created using calloc 
    as well, so we need to free this two thing.
    */
    list_node_t* current; 
    current = list->head; 
    while (current != NULL)
    {
        /*Mark down the next node first and so after we delete 
        the current node, we can still keep track of the previous node.*/ 
        list_node_t* next = current->next; 

        /*Free the current node value*/
        free(current->value); 
        free(current); 

        current = next;
    }

    /*Free the list as well because we use calloc to create the list as well.*/
    free(list);
}
