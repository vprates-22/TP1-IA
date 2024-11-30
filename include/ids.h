#ifndef IDS_H
#define IDS_H

#include "./utils.h"

void verify_dfs_neighbors(float** board, int** visited, int height, int width, 
                          node** path, priority_queue* pq, node last_node);
int depth_limited_search(int max_depth, float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end, node** path);
void iterative_deepening_search(float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end);

#endif