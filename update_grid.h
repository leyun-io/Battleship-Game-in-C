#ifndef UPDATE_GRID_H
#define UPDATE_GRID_H
#include "constant.h"

int** check_if_hit(int** grid, char x_axis, int y_axis, 
                   int* location_code, int ship_count);
int print_result(int** grid, int location_code, ship_t** profile, 
                 int row_num, int col_num, int ship_count);
void update_ship_sunk(ship_t** profile, int ship_count);
void win_the_game(ship_t** profile, int ship_count);

#endif
