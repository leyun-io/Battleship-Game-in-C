#include <stdio.h>
#include <stdlib.h>
#include "user_interface.h"
#include "print_ship.h"


/*This .c file contain 2 function for user interface, menu funciton and 
give_attack function.*/

/*Menu function - this is just a simple function for letting the user to choose 
either continue the game or exit game. It accept an argument which is a pointer 
variable to kept the user's option, a do-while loop is implemented here so 
that when users enters an invalid option the menu will showed up again*/

int menu(int* user_option)
{
    *user_option = 0;
    do
    {
        *user_option = 1;
        printf("\nEnter a command: \n");
        printf("1. Shoot \n");
        printf("2. Quit game \n");
        scanf("%d", user_option);
    }while (*user_option != 1 && *user_option != 2);

    return 0;
}

/**************************************************/

/*This is a function for letting the users to aim for the attack target and 
give attack. This function accept two argument, ome is character x_input 
which is the x-axis the user aim for, another is an integer y_input for the 
y-axis coordinate. Both of them are pointer variable, this function check 
the valid input in another slightly different way, after the user enters an 
invalid input, the function will print out a message to inform the user the 
format of attacking their target so that they know how to enter a valid 
location*/

int give_attack(char* x_input, int* y_input)
{
    *x_input = '\0';
    *y_input = 0;
    
    printf("\nEnter a location: ");
    
    getchar();
    scanf("%c%d", x_input, y_input);

    if (*x_input < 'A' || *x_input > 'G' 
        || *y_input < 0 || *y_input > 6)
    {
        printf("Please enter a valid location.\nFor example: B2\n");
        give_attack(x_input, y_input);
    }
    return 0;
}

