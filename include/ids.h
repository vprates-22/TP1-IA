#ifndef IDS_H
#define IDS_H

#include "./utils.h"

int depth_limited_search(int depth_limit, float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end);
void iterative_deepening_search(float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end);

#endif