#ifndef GREEDY_H
#define GREEDY_H

#include "./utils.h"

float verify_greedy_neighbors(float** board, int height, int width,
                            int** visited, int* x, int* y, int x_end, int y_end);
void greedy(float** board, int height, int width, 
    int x_start, int y_start, int x_end, int y_end);

#endif