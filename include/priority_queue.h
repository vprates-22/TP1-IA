#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdlib.h>
#include "./node.h"

typedef struct priority_queue{
    node** queue;
    long max_size;
    int size;
} priority_queue;

void swap(node* a, node* b);
void correct_parents(priority_queue* pq, int index);
void correct_children(priority_queue* pq, int index);

priority_queue* init_priority_queue(long max_size);

void add_to_priority_queue(priority_queue* pq, int x, int y, 
                            float cost, float other_value);
node remove_from_priority_queue(priority_queue* pq);

#endif