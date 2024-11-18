#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include "./node.h"

typedef struct queue_node{
    node n;
    struct queue_node* prior;
    struct queue_node* next;
} queue_node;

typedef struct{
    int size;
    queue_node* top;
    queue_node* bottom;
} queue;

queue_node* init_queue_node(int x, int y, float value);

queue* init_queue();
void add_to_queue(queue* q, queue_node* n);
queue_node* remove_from_queue(queue *q, int first);
queue_node* fifo_remove_from_queue(queue* q);
queue_node* lifo_remove_from_queue(queue* q);
void free_queue(queue* q);

#endif