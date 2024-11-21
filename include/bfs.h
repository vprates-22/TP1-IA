#ifndef BFS_H
#define BFS_H

#include "./utils.h"

void verify_bfs_neighbors(float** board, int height, int width, 
                      int** visited, node** path, queue* q, queue_node* last_node);
void breadth_first_search(float** board, int height, int width, 
                int x_start, int y_start, int x_end, int y_end);
#endif