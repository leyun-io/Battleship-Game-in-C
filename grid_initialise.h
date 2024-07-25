#ifndef GRID_INITIALISE_H
#define GRID_INITIALISE_H

#include "constant.h"

int** initialise_ocean(int row_num, int col_num);
ship_t** create_ship_profile(int ship_count);
void process_detail(char** details, int** grid, ship_t** list,
                    int row, int col, int ship_count);
void put_ship(int** grid, int ship_code, int x_loc, int y_loc, int ship_len, 
              char direction, int grid_row, int grid_col);

#endif
