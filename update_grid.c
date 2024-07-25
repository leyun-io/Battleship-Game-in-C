#include <stdio.h>
#include <stdlib.h>
#include "print_grid.h"
#include "update_grid.h"

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

int** check_if_hit(int** grid, char x_axis, int y_axis, 
                   int* location_code, int ship_count)
{

    /*convert_intx: this is a variable for storing the serial number for 
    x-axis after converting the character that users enter for x coordinate 
    into an integer*/
    int convert_intx;
    convert_intx = (int)(x_axis) - 65;
    *location_code = grid[y_axis][convert_intx];

    if (grid[y_axis][convert_intx] >= 0 && 
        grid[y_axis][convert_intx] <= ship_count)
    {
        /*If there is a ship at that location, then mark the spot as HIT*/
        grid[y_axis][convert_intx] = -3;
    }

    else if (grid[y_axis][convert_intx] == -1)
    {
        /*If there is no ship on the location*/
        grid[y_axis][convert_intx] = -2;
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

int print_result(int** grid, int location_code, ship_t** profile,
                 int row_num, int col_num, int ship_count)
{
    if (location_code >= 0 && location_code <= ship_count)
    {
        print_grid(grid, row_num, col_num, ship_count);
        printf("You hit the %s!\n", profile[location_code]->ship_name);
        /*Update the ship status and this will be used in the update_ship_sunk 
        function to keep track of the ship status. */
        profile[location_code]->status = profile[location_code]->status - 3;
    }

    else if (location_code == -1)
    {
        print_grid(grid, row_num, col_num, ship_count);
        printf("Miss!\n");
    }

    else if (location_code == -2 || location_code == -3)
    {
        print_grid(grid, row_num, col_num, ship_count);
        printf("Try another location.\n");
    }

    else
    {
        printf("Plese enter a valid location.\n");
    }

    return 0;
}

/**************************************************/

/*
This function will check the status of the ship, whereas the ship is sunk 
or not. After each block of the ship is hit, the status will add -3 into it 
and after the status is -3 times the legth of the ship, means that the ship 
has been sunk. After it has been sunk, the status become 1 means that the ship is sunk and the message have been printed out before.
*/
void update_ship_sunk(ship_t** profile, int ship_count)
{
    int i;
    for ( i = 0; i < ship_count; i++)
    {
        if (profile[i]->status == profile[i]->ship_len * -3)
        {
            printf("Congratulation! You have sunk the %s\n", 
                   profile[i]->ship_name);
            
            /*After printed out the message, change the status to make sure 
            the message only appears once*/
            profile[i]->status = 1;
        }
    }
}

/**************************************************/

/*After the ship have been sunk, the status will be turn to 1, which means 
that the ship is sunk and the message have been printed out before. And if 
all of the ships' status on the ocean become 1, which is 1 times the number 
of ships, it means that all of the ships have been sunk and the victory 
message will be printed out. This function will also print the count of 
shipwrecks in each attack that the user make. */
void win_the_game(ship_t** profile, int ship_count)
{
    int i, shipwrecks = 0;
    for ( i = 0; i < ship_count; i++)
    {
        if (profile[i]->status == 1)
        {
            shipwrecks++;
        }
    }
    if (shipwrecks == ship_count)
    {
        printf("VICTORY! You have sunk all the boat! \\('v')/\n");
    }
    else
    {
        printf("\n");
        printf("\nCount of shipwrecks: %d\n", shipwrecks);
    }


}
