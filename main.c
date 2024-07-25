#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "constant.h"
#include "read_ship_details.h"
#include "grid_initialise.h"
#include "print_grid.h"
#include "user_interface.h"
#include "update_grid.h"
#include "linked_list.h"
#include "file_save_n_read.h"


/*
This is the main function act like a control room and calling functions that 
neccesary for this program
There are a pleanty of header files above which needed for the main function
*/

int main(int argc, char* argv[])
{
    /*
    This is declaring the 2D array created using malloc for the grid, 
    which will later been printed out and let the user to guess the 
    ship location
    */
    int** my_ocean;

    /*
    This is a 2D array created using malloc, it will store the ship input 
    data such as location, ship length, ship name, etc. which provided from the 
    file given
    */
    char** ship_indata;
    /*
    i: is for looping purpose, 
    ship_count: for storing the count of ship after processing the input file 
    from the read_ship_details function.
    grid_row: the input file will provide the row count for the grod, this 
    variable is for storing the ineger if the row number. 
    grid_col: similar to grid_row, this variable is for storing the column 
    count. 
    user_input: is for storing the action user choose, either continue 
    game or exit, 
    y_input: is the y-axis which user aim for attack, it works together 
    with x_input
    location_code: in the gridinItialise.c file, each block of the grid 
    have a unique integers for marking whether is there a ship or not, 
    hence this variable is created for differentiating whether is there 
    any boat and which boat is at the spot which user choose to attack
    */
    int i, ship_count, grid_row, grid_col, user_input, y_input, location_code;
    
    /*
    x_input: is the variable storing for the x-axis which user aiming for
    file_name: a sring for storing the filename.
    */
    char x_input, file_name[MAX_STRING_LENGTH];

    /*
    ships_profile: The ship's profile have data type of typedef struct 
    defined in constand.h, it is to store the ships profile
    */
    ship_t** ships_profile;

    /*
    command_history: have data type of list_t which is also initialised by a typedef in the linkedlist.h file and this is a list to store the command history for users to replay, save or load the game from this list. 
    */
    list_t* command_history;

    /*
    This is a list node created to keep track of the cirrent node pointing. It is for looping purpose.
    */
    list_node_t* current;

    /*
    If the command line parameter does not give in a filename, an error message will be printed out and guide the user to use the program correctly. 
    */
    if (argc < 2)
    {
        printf("ERROR! usage './battleship <name>'\n");
        return 1;
    }

    /*Clearing the console and re-print the map on every action*/
    system("clear");

    /*Calling get_ship_location() function and store those ships details into 
    the ship_indata variable declared above*/
    ship_indata = read_ship_details(argv[1], &ship_count, &grid_row, 
                                     &grid_col);

    /*Call initialiseOcean() fucntion to store the 2D grid into my_ocean 
    variable*/
    my_ocean = initialise_ocean(grid_row, grid_col);
    /*Create the ship profile*/
    ships_profile = create_ship_profile(ship_count);    
    /*Create a list before adding the command onto the list.*/
    command_history = createList();
    /*Process the ships detail and store into their profile*/
    process_detail(ship_indata, my_ocean, ships_profile, grid_row, grid_col, 
                   ship_count);
    /*After placing each ship, we print them out*/
    print_grid(my_ocean, grid_row, grid_col, ship_count);
    printf("\n");

    do
    {
        /*Calling menu and passing in a address of a variable*/
        menu(&user_input);
        
        if (user_input == 1)
        {
            /*Let user to aim for the location they would like to attack*/
            addToList(command_history, give_attack(&x_input, &y_input));

            /*Cheking the spot that user attack on the grid, whether is there a ship*/
            check_if_hit(my_ocean, x_input, y_input, &location_code, 
                         ship_count);

            /*After updating the grid, print out the updated version griid to 
            the users*/
            print_result(my_ocean, location_code, ships_profile, grid_row, 
                         grid_col, ship_count);
            update_ship_sunk(ships_profile, ship_count); 
            win_the_game(ships_profile, ship_count);
        }

        else if (user_input == 2)
        {
            /*
            Prompt the user to enter a filename and save the contents of the
            history linked list to a file.
            */
            printf("Please enter the file name for saving history\n");
            scanf("%s", file_name);
            /*Pass in the argument to the function to save the history linked 
            list to the file.*/
            save_list(command_history, file_name);
            printf("File name: %s\n", file_name);
        }

        else if (user_input == 3)
        {
            /*
            Prompt the user to enter a filename and load the contents of the
            file into the history linked list.
            */
            printf("Please enter the file name for loading history\n");
            scanf("%s", file_name);
            /*Pass the history linked list and the file name into the function to perform the file loading operation.*/
            load_list(command_history, file_name);
            printf("File name: %s\n", file_name);
        }

        if (user_input == 3 || user_input == 4)
        {
            /*Renew the grid, this option will perform the replay of the game 
            history. */
            my_ocean = initialise_ocean(grid_row, grid_col);
            process_detail(ship_indata, my_ocean, ships_profile, grid_row, 
                           grid_col, ship_count);

            print_grid(my_ocean, grid_row, grid_col, ship_count);
            printf("Original state\n");
            sleep(1);
            
            /*The history linked list will be loop trough and the node will be read one by one to replay the game history*/
            current = command_history->head;
            while (current != NULL)
            {
                sscanf(current->value, "%c%d", &x_input, &y_input);
                check_if_hit(my_ocean, x_input, y_input, &location_code, 
                         ship_count);
                print_result(my_ocean, location_code, ships_profile, grid_row, 
                            grid_col, ship_count);
                update_ship_sunk(ships_profile, ship_count); 
                win_the_game(ships_profile, ship_count);
                printf("The location you shoot: %s\n", (char*)current->value);
                sleep(1);
                current = current->next;
            }
        }
    } while (user_input != 5);

    if (user_input == 5)
    {   /*Free all memory allocation to avoid memory leaks before exiting 
        the program*/
        freeList(command_history);
        for (i = 0; i < ship_count; i++)
        {
            free(ship_indata[i]);
            ship_indata[i] = NULL;
        }
        for (i = 0; i < grid_row; i++)
        {
            free(my_ocean[i]);
            my_ocean[i] = NULL;
        }
        for (i = 0; i < ship_count; i++)
        {
            free(ships_profile[i]);
            ships_profile[i] = NULL;
        }
        free(ship_indata);
        ship_indata = NULL;
        free(my_ocean);
        my_ocean = NULL;
        free(ships_profile);
        ships_profile = NULL;

        printf("Good Bye!\n");
        exit(0);
    }

    return 0;
}

