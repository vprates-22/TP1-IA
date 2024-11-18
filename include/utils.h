#ifndef UTILS_H
#define UTILS_H

#include <string.h>
#include "./queue.h"

void** create_matrix(size_t size_of, int height, int width, void* default_value);
int** create_visited_matrix(int height, int width);
queue_node** create_path_matrix(int height, int width);
void free_matrix(void** board, int height);

#endif