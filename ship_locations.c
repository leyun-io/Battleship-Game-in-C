#include<stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ship_locations.h"
#include "constant.h"


/*  this file and the corresponding header file (ship_locations.c and 
    ship_locations.h) contains a
    single function you can use to get some metadata that you need to create
    the 2d map array in your game. 
    
    if you want to make your own metadata for the map (e.g changing 
    the ship positions),
    you can modify the metadata table here. keep in mind that
    we will test your assignment with our own metadata. */

/*  This file only contain one single function which is get_ship_location, 
    this function create a 2D array using malloc and storing information 
    details for each ship (ship location, the direction facing, ship length 
    and ship name) which will be later used in put_ship function which 
    written in put_ship.c file. This function return the table created to 
    the main function and will be stored into a variable in main.c*/

char** get_ship_locations()
{
    /*This variable is for looping purpose, it will loop from 0 to 1 
    number smaller than number of ship count*/
    int i;

    /*This is a 2D array and will later be created for storing each 
    ship details*/
    char** table;


    /* now it is time to malloc the array of strings */
    table = (char**) malloc(sizeof(char*) * (SHIP_COUNT));

    /*loop through each major array and srote the minor array in to it*/
    for(i = 0 ; i < (SHIP_COUNT) ; i++)
    {
        /*each string is also mallocc'd, don't forget to free them! */
        table[i] = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    }
    
    /* now it is time to fill the array of strings with the data */
    strcpy(table[0], "D4 W 3 Nullbyte Submarine");
    strcpy(table[1], "A1 S 3 SSASR Popoto");
    strcpy(table[2], "C2 E 2 CPN \"Rogers\" Steve");
    strcpy(table[3], "F6 W 5 BS Galactica");

    return table; /* return the array */

}
