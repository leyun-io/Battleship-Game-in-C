#include <stdio.h>
#include <stdlib.h>
#include "print_grid.h"


/*This file contain only one function and this function is for printing out 
the grid, this function accept an argument which is the grid generated in 
grid_initialise.c and updated in put_ship.c hence every block of the grid 
is already have their own role now. The collumn is represented as character 
and the collumn is represented as integer. Each block will be printed out 
according to the integer they carry, this integer is like a identifier which 
is generated for each block on the grid in put_ship.c file*/

int print_grid(int** grid, int row_num, int col_num, int ship_count)
{
    /*
    col: this is for looping through each collumn and print them out one by one
    row: this is for looping through each collumn and print out each collumn in 
    that row
    ASCII: this is a variable for looping and print for the x-axis serial 
    number*/
    int col, row, ASCII;

    system("clear"); 
    printf("\n");

    for(row = 0; row < row_num; row++ )
    {
        if (row == 0)
        {
            printf(" |");
            for (ASCII = 0; ASCII < col_num; ASCII++)
            {
                printf("%c|", ASCII + 65);
            }
            printf("\n");
            printf("----------------");
            printf("\n");
        }
        else
        {
            for (row = 0; row < row_num; row++)
            {
                printf("%c|", row + 48);
                for (col = 0; col < col_num; col++)
                {
                    /*When there are no ship at this location*/
                    if(grid[row][col] == -1)
                    {
                        printf(" |");
                    }

                    /*Debug mode - when there is a ship at this point but have 
                    not been attacked and print out 'S' on the grid*/
                    #ifdef DEBUG
                    if (grid[row][col] >= 0 && grid[row][col] < ship_count)
                    {
                        printf("%c|", 83);
                    }
                    #endif

                    /*Normal player mode - when there is a ship here but have 
                    not been attacked yet, so it looks same as there is nothing 
                    here*/
                    #ifndef DEBUG
                    /*There are a ship but not yet being hit*/
                    if (grid[row][col] >= 0 && grid[row][col] < ship_count)
                    {
                        printf(" |");
                    }
                    #endif
                    
                    /*Miss - there are nothing here*/
                    else if(grid[row][col] == -2)
                    {
                        printf("O|");
                    }

                    /*Hit - the user hit the ship*/
                    else if(grid[row][col] == -3)
                    {
                        printf("X|");
                    }
                    
                }
                printf("\n");
                printf("----------------");
                printf("\n");
            }
        }
    }
    return 0;
}
