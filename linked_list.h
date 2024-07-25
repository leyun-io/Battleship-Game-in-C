#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
Typedef a struct, inside the struct have a void data type variable name called as value. it can store any data tyoe into it. The next is the struct of the ListNode (itself) and this will point to the next node.*/
typedef struct ListNode
{
    void* value;
    struct ListNode* next;
} list_node_t;

/*
Typedef a struct called as list_t, this is use to create the list with first 
create the head node first, then we can add value into the end of the list. 
It also keep track of the node count of the list. 
*/
typedef struct LinkedList
{
    list_node_t* head;
    int count;
} list_t;

list_t* createList();
void addToList(list_t* list, void* itemToAdd);
void freeList(list_t* list);
void* getListItemAt(int index, list_t* list);

#endif
