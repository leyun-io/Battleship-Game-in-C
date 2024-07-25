#include <stdio.h>
#include "constant.h"
#include "put_ship.h"


/*This c file contain only one single function which is use to process the 
ship details and store different information to different variable for later 
use, this funciton needs a few argument which is 
The ship details: pass in firstly and the details will be created in the 
ship_location function written in ship_location.c file, the ship details will
be process firstly in this function and stored in five variables. 
The grid: which is the basement of the game, each block in the grid carries a 
value and is for identifying the situation of that point, in this funciton we 
will update this grid according to the ship location, each ship will be given a 
unique integer and is for later use in printing out the grid
name: the last argument pass in is for storing the ship name, this is a 
pointer argument so that it can be executable in main function and used to 
print out the ship name when the ship is attacked.*/

int** put_ship(char* details[SHIP_COUNT], int* grid[COLUMN], 
               char name[][MAX_STRING_LENGTH])
{

    /*i: for looping purpose, looping through each ship number so that 
    information can be processed one by one
    axis_y: this is an array to store each ship's y-axis coordinate
    ship_len: this is a variable to store the ship's length and will be use for 
    looping when locating the ships
    axis_x: this is for storing the x_axis coordinate of the ship
    direction: this is the direction of the ship facing
    count: a variable for looping through until reach the length of the ships. 
    int_xaxis: this is to convert the x_axis which type as a character and 
    convert it to integer. 
    grid_row: for looping each row in the grid
    grid_col: for looping each collumn in the grid
    */
    int i, axis_y[SHIP_COUNT], ship_len[SHIP_COUNT]; 
    char axis_x[SHIP_COUNT], direction[SHIP_COUNT];
    int count, int_xaxis, grid_row, grid_col; 

    /*Loop through each ship and process the information stored in "details" 
    which is created in the ship_location function in ship_location.c file.*/
    for(i = 0; i < 4; i++)
    {
        sscanf(details[i], "%c%d %c %d %[^\n]", &axis_x[i], &axis_y[i], 
               &direction[i], &ship_len[i], name[i]);
    
        /*if the preccessed information of the ship is facing a certain 
        direction, then find the corresponding location on the grid then place 
        them, note that each ship location have their unique integer storing in 
        the grid basement*/
        /*Face North*/
        if (direction[i] == 'N')
        {
            int_xaxis = (int)(axis_x[i]) - 65;
            for (grid_col = 0; grid_col < COLUMN; grid_col++)
            {
                if (grid_col == int_xaxis)
                {
                    for (grid_row = 0; grid_row < ROWS; grid_row++)
                    {
                        if (grid_row == axis_y[i])
                        {
                            for (count = 0; count < ship_len[i]; count++)
                            {
                                grid[grid_row][grid_col - count] = i;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
        }

        /*Face East*/
        if (direction[i] == 'E')
        {
            int_xaxis = (int)(axis_x[i]) - 65;
            for (grid_row = 0; grid_row < ROWS; grid_row++)
            {
                if (grid_row == axis_y[i])
                {
                    for (grid_col = 0; grid_col < COLUMN; grid_col++)
                    {
                        if (grid_col == int_xaxis)
                        {
                            for (count = 0; count < ship_len[i]; count++)
                            {
                                grid[grid_row][grid_col + count] = i;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
        }

        /*Face South*/
        if (direction[i] == 'S')
        {
            int_xaxis = (int)(axis_x[i]) - 65;
            for (grid_col = 0; grid_col < COLUMN; grid_col++)
            {
                if (grid_col == int_xaxis)
                {
                    for (grid_row = 0; grid_row < ROWS; grid_row++)
                    {
                        if (grid_row == axis_y[i])
                        {
                            for (count = 0; count < ship_len[i]; count++)
                            {
                                grid[grid_row + count][grid_col] = i;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
        }
        
        /*Face West*/
        if (direction[i] == 'W')
        {
            int_xaxis = (int)(axis_x[i]) - 65;
            for (grid_row = 0; grid_row < ROWS; grid_row++)
            {
                if (grid_row == axis_y[i])
                {
                    for (grid_col = 0; grid_col < COLUMN; grid_col++)
                    {
                        if (grid_col == int_xaxis)
                        {
                            for (count = 0; count < ship_len[i]; count++)
                            {
                                grid[grid_row][grid_col - count] = i;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
        }

    }
    return grid;
}
