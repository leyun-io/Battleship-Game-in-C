#include <stdio.h>
#include <stdlib.h>
#include "file_save_n_read.h"
#include "linked_list.h"
#include "constant.h"

/*
This is the function for saving the game, it will take in two argument, the 
first is the history command line which is a linked list that stored a list of 
the users' movement during the game. The second is the filename that the user 
input to store the contents of the history linked list.
*/
void save_list(list_t* list, char file_name[])
{
    /*
    new_file: a file to open for writing purpose, the history command will be 
    saved into this file.
    current: a list node created for pointing to the first node of the list and 
    will help in later linked list reading.
    */
    FILE* new_file;
    list_node_t* current; 

    /*Open the file and write*/
    new_file = fopen(file_name, "w");

    /*Point the current to the head of the list.*/
    current = list->head; 
    /*Loop through the list and store the content inside the history list 
    into the file*/
    while (current != NULL)
    {
        fprintf(new_file, "%s", (char*)current->value);
        fprintf(new_file, "\n");
        current = current->next;
    }

    fclose(new_file);
}

/**************************************************/

/*
This function is the "Load" feature in the menu. It will load the content 
from a file. It take two arguments, one is the command history linked list, 
while the other is the file name that the user will like to load to replay it. 
*/
void load_list(list_t* list, char file_name[])
{
    /*
    history_file: a file to open for reading purpose, the history command 
    will be loaded from this file.
    line: an array of character to store the info loaded from the history_file
    */
    FILE* history_file;
    char line[MAX_STRING_LENGTH];

    /*Open the file for reading purpose.*/
    history_file = fopen(file_name, "r");

    /*Error handling: if the file does not exist.*/
    if(history_file == NULL) 
    {
         perror("ERROR! Unable to open file.");
         exit(1);
    }

    /*Loop through the file and save the information from the history file 
    to the history linked list.*/
    while(fgets(line, sizeof(line), history_file))
    {
        char* newnode;
        newnode = (char*)calloc(3, sizeof(char));
        sscanf(line, "%s\n", newnode);
        addToList(list, newnode);
    }
    fclose(history_file);
}
