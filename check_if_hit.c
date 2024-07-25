#include <stdio.h>
#include <stdlib.h>
#include "print_ship.h"
#include "constant.h"
#include "check_if_hit.h"

/*This .c file include two function, one is function check_if_hit while 
another is print_result. Both of them is for updating the grid after 
users attack a ship*/


/*check_if_hit - This function takes a few argument and then check whether 
is there any ship at the location where user attacked.

The first argument passed in is the grid, so that we can check that is there 
any ship at certain block of the grid. If there is a ship at that location, 
the location code(which stands for the situation for each block) will change 
to 5, else it will change to 4
The second and third argument are use for extracting the block according to 
the coordinate the users enter in the main function in main.c to check and 
update whether is there any ship over that point.
While the last argument is the most critical for the next function which 
need for printing out the ship name, this argument is a pointer variable 
and this pointer variable will store the ship location code, in to it and 
after passed to the next function (print_result function) the ship's name 
can be get using this unique number*/

int** check_if_hit(int* grid[COLUMN], char x_axis, int y_axis, 
                   int* location_code)
{

    /*convert_intx: this is a variable for storing the serial number for 
    x-axis after converting the character that users enter for x coordinate 
    into an integer*/
    int convert_intx;
    convert_intx = (int)(x_axis) - 65;
    *location_code = grid[y_axis][convert_intx];

    if (grid[y_axis][convert_intx] >= 0 && grid[y_axis][convert_intx] <= 3)
    {
        /*If there is a ship at that location, then mark the spot as HIT*/
        grid[y_axis][convert_intx] = 5;
    }

    else if (grid[y_axis][convert_intx] == -1)
    {
        grid[y_axis][convert_intx] = 4;
    }
    
    return grid;
}

/**************************************************/


/*After the check_if_hit fucntion has update the grid, this function will print 
out the result and also a line of comment to notify the users whether their 
attack hit a ship or miss. This function print out the grid by calling the 
function and print out the message followed by the ship name if they hit a 
ship.
The function accept three arguments which is the grid for printing out, the 
location for executing the ship name, and of course the arrays that store ship 
names*/

int print_result(int* grid[COLUMN], int location_code, 
                 char ship_name[][MAX_STRING_LENGTH])
{   
    if (location_code >= 0 && location_code <= 3)
    {
        print_grid(grid);
        printf("You hit the %s!\n", ship_name[location_code]);
    }
    
    else if (location_code == -1)
    {
        print_grid(grid);
        printf("Miss!\n");
    }
    
    else if (location_code == 4 || location_code == 5)
    {
        print_grid(grid);
        printf("Try another location.\n");
    }

    else
    {
        printf("Plese enter a valid location.\n");
    }

    return 0;
}
