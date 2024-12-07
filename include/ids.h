#ifndef IDS_H
#define IDS_H

#include "./utils.h"

int verify_dfs_neighbors(int depth, int max_depth, float** board, int height, int width, 
                          int x, int y, float cost, int x_end, int y_end, 
                          int** visited, node** path);
int depth_limited_search(int depth, int max_depth, float** board, int height, int width, 
                         int x, int y, int cost, int x_end, int y_end,
                         int** visited, node** path);
void iterative_deepening_search(float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end);

#endif