#include "../include/priority_queue.h"

priority_queue* init_priority_queue(long max_size){
    priority_queue* pq = malloc(sizeof(priority_queue));

    pq->queue = malloc(max_size * sizeof(node*));
    for(int i = 0; i < max_size; i++){
        pq->queue[i] = malloc(sizeof(node));
    }

    pq->max_size = max_size;
    pq->size = 0;

    return pq;
}

void swap(node* a, node* b){
    int x = a->x;
    int y = a->y;
    float cost = a->cost;
    float other_value = a->other_value;

    a->x = b->x;
    a->y = b->y;
    a->cost = b->cost;
    a->other_value = b->other_value;
    
    b->x = x;
    b->y = y;
    b->cost = cost;
    b->other_value = other_value;
}

void correct_parents(priority_queue* pq, int index){
    int parent_index = (index - 1) / 2;
    if(index && pq->queue[parent_index]->cost > pq->queue[index]->cost){
        swap(pq->queue[parent_index], pq->queue[index]);
        correct_parents(pq, parent_index);
    }
}

void add_to_priority_queue(priority_queue* pq, int x, int y,
                             float cost, float other_value){
    if(pq->size == pq->max_size) 
        return;

    init_node(pq->queue[pq->size], x, y, cost, other_value);
    correct_parents(pq, pq->size++);
}

void correct_children(priority_queue* pq, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->queue[left]->cost < pq->queue[smallest]->cost){
        smallest = left;
    }

    if (right < pq->size && pq->queue[right]->cost < pq->queue[smallest]->cost){
        smallest = right;
    }

    if (smallest != index) {
        swap(pq->queue[index], pq->queue[smallest]);
        correct_children(pq, smallest);
    }
}

node remove_from_priority_queue(priority_queue* pq){
    node n = *pq->queue[0];
    node bottom = *pq->queue[--pq->size];    
    init_node(pq->queue[0], bottom.x, bottom.y, 
                    bottom.cost, bottom.other_value);
    correct_children(pq, 0);
    return n;
}