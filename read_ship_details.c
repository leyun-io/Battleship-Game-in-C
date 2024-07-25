#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "constant.h"

/*
This function will read the ships detail from the file and store those 
information in a 2d array for the grid initialising. The first argument of this 
function takes in is the file name for reading the information, the second 
argument is the ship count pointer for the main function knowing the ship count,
the third argument it takes in is the row number pointer for the main function 
to knows the row number and similar to the fourth argument is for knowing the 
column number. 
*/
char** read_ship_details(char file_name[], int* ship_count_ptr, 
                         int* row_num_ptr, int* col_num_ptr)
{
    /*
    i: for looping purpose
    row_num: the row number of the grid
    col_num: the column number of the grid
    ship_count; the ship number.
    */
    int i, row_num, col_num, ship_count = 0;
    /*operator: knowing the operation of the first two onteger give in the file*/
    char operator;
    /*
    ship_details: storing the ship details
    temp_details: storing the temporary ship details which will later append to the ship_details variable.
    */
    char ship_details[MAX_STRING_LENGTH];
    char temp_details[MAX_STRING_LENGTH];
    /*token: to get each line*/
    char* token;
    /*table: the 2D array storing the ships details*/
    char** table;

    FILE* infile = fopen(file_name, "r");
    /*Error execption*/
    if(infile == NULL) 
    {
         perror("Unable to open file!");
         exit(1);
    }
    /*Scanning the details given in the file to different variable*/
    fscanf(infile, "%d%c%d", &row_num, &operator, &col_num);
    /*
    Store the row number and column number to the pointer variable to return back to the main function.
    */
    *row_num_ptr = row_num;
    *col_num_ptr = col_num;
    
    /*Scan through the ship details line by line*/
    while(fgets(temp_details, sizeof(temp_details), infile) != NULL) 
    {
        ship_count++;
        fscanf(infile, "%127[^\n]", temp_details);
        strcat(ship_details, temp_details); 
        strcat(ship_details, "\n");
        puts(temp_details);
    }
    /*Store the ship count into the ship count pointer variable*/
    *ship_count_ptr = ship_count;

    /* now it is time to malloc the array of strings */
    table = (char**)malloc(sizeof(char*) *(ship_count));

    /*loop through each major array and srote the minor array in to it*/
    for(i = 0 ; i < ship_count ; i++)
    {
        /*each string is also mallocc'd, don't forget to free them! */
        table[i] = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
    }

    /*Seperate the ship_details and store it into the 2d array called as "table" line by line.*/
    token = strtok(ship_details, "\n");
    strcpy(table[0], token);
    for (i = 1 ; i < ship_count ; i++)
    {
        token = strtok(NULL, "\n");
        strcpy(table[i], token);
    }

    fclose(infile);
    return table;
}
