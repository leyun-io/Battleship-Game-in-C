#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grid_initialise.h"
#include "constant.h"


/*  This file contains only one function and is for creating the grid so 
    each block inside the grid can store a integer which use to identify 
    the situation of that location, which can also be viewed as the ocean. 
    It will create a grid using malloc according to the row and collumn 
    whcih defined in constant.h. This function is created for later use in 
    put_ship function which is located in put_ship.c file and print_ship 
    function which located in print_ship.c file and check_if_hit fucntion 
    which is written in the check_if_hit.c file. After create the 2D array 
    for storing integer, a -1 is stored into each block which means there 
    is nothing at this location*/

int** initialise_ocean()
{
    /*i: for looping purpose, and is for generating the main array using malloc
    row: for looping purpose, loop through each collumn and use to store a unique code on each block
    col: for looping purpose, loop through each row and work together with the variable "row" to execute each block in the table using index*/
    int i, row, col;
    int** ocean = (int**) malloc( ROWS * sizeof(int*));

    /*Loop through each of them and palce a memory location for each of them*/
    for (i = 0; i < ROWS; i++)
    {
        ocean[i] = (int*) malloc( COLUMN * sizeof(int));
    }

    /*fill in the ocean with integers 
    so after that we can update the integer 
    to keep track of the game status*/
    for(row = 0; row < ROWS; row++ )
    {
        for(col = 0; col < COLUMN; col++ )
        {
            ocean[row][col] = -1;
        }
    }
    return ocean;
}
