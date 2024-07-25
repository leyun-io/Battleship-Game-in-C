#ifndef CONSTANT_H
#define CONSTANT_H

#define MAX_STRING_LENGTH 256

/*
Ship is a struct create using typedef which will use to store the information of each ship, such as the location coordinate, the direction, the length of the ship, the ship name and whether the ship has been sunk
*/
typedef struct ship
{
    int x_loc;
    int y_loc;
    char direction;
    int ship_len;
    char ship_name[MAX_STRING_LENGTH];
    int status;
} ship_t;

#endif
