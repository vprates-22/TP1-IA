#ifndef GREEDY_H
#define GREEDY_H

#include "./utils.h"

void verify_greedy_neighbors(float** board, int height, int width, 
                            int x_end, int y_end, int** visited, node** path, 
                            priority_queue* pq, node last_node);
void greedy(float** board, int height, int width, 
    int x_start, int y_start, int x_end, int y_end);

#endif