#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grid_initialise.h"
#include "constant.h"


/*  
This function is for creating the grid so each block inside the grid can 
store an integer which use to identify the situation of that location, 
which can also be viewed as the ocean. 
It will create a grid using malloc according to the row and collumn. 
This function is created for later use in put_ship function which is located 
in put_ship.c file and print_ship function which located in print_ship.c 
file and check_if_hit fucntion which is written in the check_if_hit.c file.
After create the 2D array for storing integer, a -1 is stored into each 
block which means there is nothing at this location
*/

int** initialise_ocean(int row_num, int col_num)
{
    /*i: for looping purpose, and is for generating the main array using malloc
    row: for looping purpose, loop through each collumn and use to store a unique code on each block
    col: for looping purpose, loop through each row and work together with the variable "row" to execute each block in the table using index*/
    int i, row, col;
    int** ocean = (int**)malloc( row_num * sizeof(int*));

    /*Loop through each of them and palce a memory location for each of them*/
    for (i = 0; i < row_num; i++)
    {
        ocean[i] = (int*)malloc( col_num * sizeof(int));
    }

    /*fill in the ocean with integers 
    so after that we can update the integer 
    to keep track of the game status*/
    for(row = 0; row < row_num; row++ )
    {
        for(col = 0; col < col_num; col++ )
        {
            ocean[row][col] = -1;
        }
    }
    return ocean;
}

/**************************************************/

/*
This function will create a struct for each to store their information. Those information will then pass into the process_detail function to input those information into the empty struct created in this function. 
*/
ship_t** create_ship_profile(int ship_count)
{
    /*i: an integer data type for looping purpose.*/
    int i;
    /*Create a 2d array using malloc for storing the ship's profile*/
    ship_t** ship_profile = (ship_t**)malloc(sizeof(ship_t*) * ship_count);
    for (i = 0; i < ship_count; i++)
    {
        /*Each loop will create a struct for each ship to store their info.*/
        ship_profile[i] = (ship_t*)malloc(1 * sizeof(ship_t));
    }
    return ship_profile;
}

/**************************************************/

/*
This function is use to process the ship details and store different 
information to different variable for later use, this funciton need 
a few argument which is:
The ship details: pass in firstly and the details will be created in the 
ship_location function written in ship_location.c file, the ship details will
be process firstly in this function and stored in five variables. 
The grid: which is the basement of the game, each block in the grid carries a 
value and is for identifying the situation of that point, in this funciton we 
will update this grid according to the ship location, each ship will be given a 
unique integer and is for later use in printing out the grid.
The ship profile: the profile is an empty 2d array for this stage and will 
be filled in the ship details after this function process and store the data 
into it. 
Row of grid: The row of the grid will be know from the input file given.
Column of the grid: The column number of the grid given by the input file.
*/

void process_detail(char** details, int** grid, ship_t** profile,
                    int row, int col, int ship_count)
{
    /*i: for looping purpose, looping through each ship number so that 
    information can be processed one by one
    axis_x: this is for storing the x_axis coordinate of the ship
    */

    int i;
    char axis_x;


    /*Loop through each ship and process the information stored in the 
    profile which created from the create_ship_profile function.*/
    for(i = 0; i < ship_count; i++)
    {
        sscanf(details[i], "%c%d %c %d %[^\n]", 
                                                &axis_x, 
                                                &profile[i]->y_loc, 
                                                &profile[i]->direction, 
                                                &profile[i]->ship_len, 
                                                profile[i]->ship_name);

        profile[i]->x_loc = (int)(axis_x) - 65;
        put_ship(grid, i, profile[i]->x_loc, profile[i]->y_loc, 
                 profile[i]->ship_len, profile[i]->direction, row, col);
        profile[i]->status = 0;
    }
}

/**************************************************/

/*
if the preccessed information of the ship is facing a certain 
direction, then find the corresponding location on the grid then place 
them, note that each ship location have their unique integer storing in 
the grid basement
*/
void put_ship(int** grid, int ship_code, int x_loc, int y_loc, int ship_len, 
              char direction, int grid_row, int grid_col)
{
    int row, col, len_count;
    for (row = 0; row < grid_row; row++)
        {
            if (row == y_loc)
            {
                for (col = 0; col < grid_col; col++)
                {
                    if (col == x_loc)
                    {
                        for (len_count = 0; len_count < ship_len; len_count++)
                        {
                            if (direction == 'N')
                            {
                            grid[row][col - len_count] = ship_code;
                            }

                            else if (direction == 'E')
                            {
                            grid[row][col + len_count] = ship_code;
                            }
                                
                            else if (direction == 'S')
                            {
                            grid[row + len_count][col] = ship_code;
                            }

                            else if (direction == 'W')
                            {
                            grid[row][col - len_count] = ship_code;
                            }
                        }
                    }
                }
            }        
        }
}
