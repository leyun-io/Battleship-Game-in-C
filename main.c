#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constant.h"
#include "ship_locations.h"
#include "grid_initialise.h"
#include "print_ship.h"
#include "put_ship.h"
#include "user_interface.h"
#include "check_if_hit.h"


/*This is the main function act like a control room and calling functions that neccesary for this program
There are a pleanty of header files above which needed for the main function*/

int main()
{
    /*This is declaring the 2D array created using malloc for the grid, 
    which will later been printed out and let the user to guess the 
    ship location*/
    int** my_ocean;  

    /*This is a 2D array created using malloc, a combination of 4 string 
    for storing each ship's information such as location, ship length, ship 
    name, etc.*/
    char** ship_details;

    /*This is a 2D array created for storing each ship's name so that the 
    ship name will be printed out after being hitted*/
    char ship_name[SHIP_COUNT][MAX_STRING_LENGTH];

    /*
        i: is for looping purpose, 
        user_input: is for storing the action user choose, either continue 
        game or exit, 
        y_input: is the y-axis which user aim for attack, it works together 
        with x_input
        location_code: in the gridinItialise.c file, each block of the grid 
        have a unique integers for marking whether is there a ship or not, 
        hence this variable is created for differentiating whether is there 
        any boat and which boat is at the spot which user choose to attack
      */
    int i, user_input, y_input, location_code;

    /*x_input: is the variable storing for the x-axis which user aiming for*/
    char x_input = '\0';

    /*Clearing the console and re-print the map on every action*/
    system("clear");

    /*Call initialiseOcean() fucntion to store the 2D grid into my_ocean variable*/
    my_ocean = initialise_ocean();

    /*Calling get_ship_location() function and store those ships details into the ship_details variable declared above*/
    ship_details = get_ship_locations();

    /*Placing ships onto the grid after got the ship locations and other details*/
    put_ship(ship_details, my_ocean, ship_name);

    /*After placing each ship, we print them out*/
    print_grid(my_ocean);
    printf("\n");
    do
    {   
        /*Calling menu and passing in a address of a variable*/
        menu(&user_input);
        if (user_input == 1)
        {   
            /*Let user to aim for the location they would like to attack*/
            give_attack(&x_input, &y_input);

            /*Cheking the spot that user attack on the grid, whether is there a ship*/
            check_if_hit(my_ocean, x_input, y_input, &location_code);
            system("clear");

            /*After updating the grid, print out the updated version griid to the users*/
            print_result(my_ocean, location_code, ship_name);
        }
    } while (user_input != 2);

    if (user_input == 2)
    {   /*Free all memory allocation to avoid memory leaks before exiting 
        the program*/
        for (i = 0; i < SHIP_COUNT; i++)
        {
            free(ship_details[i]);
            ship_details[i] = NULL;
        }

        for (i = 0; i < ROWS; i++)
        {
            free(my_ocean[i]);
            my_ocean[i] = NULL;
        }
        free(ship_details);
        ship_details = NULL;
        free(my_ocean);
        my_ocean = NULL;

        printf("Good Bye!\n");
        exit(0);
    }

    return 0;
}

