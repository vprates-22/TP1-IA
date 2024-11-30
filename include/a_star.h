#ifndef A_STAR_H
#define A_STAR_H

#include "./utils.h"

void verify_a_star_neighbors(float** board, int height, int width, 
                    int x_end, int y_end, int** visited, node** path, 
                    priority_queue* pq, node last_node);
void a_star(float** board, int height, int width, 
        int x_start, int y_start, int x_end, int y_end);

#endif