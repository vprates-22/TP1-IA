#ifndef BFS_H
#define BFS_H

#include "../include/utils.h"
#include <stdio.h>

float breadth_first_search(float** board, int height, int width, 
                int x_start, int y_start, int x_end, int y_end);
void verify_neighbors(float** board, int height, int width, 
                      int** visited, queue_node** path, queue* q, queue_node* last_node);
#endif