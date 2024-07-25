#ifndef CHECK_IF_HIT_H
#define CHECK_IF_HIT_H

#include "constant.h"
int** check_if_hit(int* grid[COLUMN], char x_axis, int y_axis, int* location_code);
int print_result(int* grid[COLUMN], int location_code, char ship_name[][MAX_STRING_LENGTH]);

#endif
