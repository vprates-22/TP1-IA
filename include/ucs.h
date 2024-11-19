#ifndef UCS_H
#define UCS_H

#include "./utils.h"
#include "./priority_queue.h"

float uniform_cost_search(float** board, int height, int width, 
                int x_start, int y_start, int x_end, int y_end);
void verify_ucs_neighbors(float** board, int height, int width, 
                int** visited, node** path, priority_queue* pq, node last_node);

#endif