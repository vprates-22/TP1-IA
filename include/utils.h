#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include <stdio.h>
#include "./queue.h"
#include "./priority_queue.h"

void** create_matrix(size_t size_of, int height, int width, void* default_value);
int** create_visited_matrix(int height, int width);
node** create_path_matrix(int height, int width);
void free_matrix(void** board, int height);
void print_path(node** paths, int x, int y);
void print_result(node** paths, node n);
int check_valid_neighbors(float** board, int**visited, int x, int y, 
                        int i, int j, int height, int width);
int heuristic(int x, int y, int x_end, int y_end);

#endif