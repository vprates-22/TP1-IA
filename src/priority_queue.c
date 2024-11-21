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
    float value = a->value;
    float real_value = a->real_value;

    a->x = b->x;
    a->y = b->y;
    a->value = b->value;
    a->real_value = b->real_value;
    
    b->x = x;
    b->y = y;
    b->value = value;
    b->real_value = real_value;
}

void correct_parents(priority_queue* pq, int index){
    int parent_index = (index - 1) / 2;
    if(index && pq->queue[parent_index]->value > pq->queue[index]->value){
        swap(pq->queue[parent_index], pq->queue[index]);
        correct_parents(pq, parent_index);
    }
}

void add_to_priority_queue(priority_queue* pq, int x, int y,
                             float value, float real_value){
    if(pq->size == pq->max_size) 
        return;

    init_node(pq->queue[pq->size], x, y, value, real_value);
    correct_parents(pq, pq->size);
    pq->size++;
}

void correct_children(priority_queue* pq, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->queue[left]->value < pq->queue[smallest]->value){
        smallest = left;
    }

    if (right < pq->size && pq->queue[right]->value < pq->queue[smallest]->value){
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
                    bottom.value, bottom.real_value);
    correct_children(pq, 0);
    return n;
}