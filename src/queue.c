#include "../include/queue.h"

queue_node* init_queue_node(int x, int y, float value){
    queue_node* n = malloc(sizeof(queue_node));
    
    init_node(&(n->n), x, y, value);

    n->prior = NULL;
    n->next = NULL;

    return n;
}

queue* init_queue(){
    queue* q = malloc(sizeof(queue));

    q->size = 0;
    q->top = NULL;
    q->bottom = NULL;

    return q;
}

void add_to_queue(queue* q, queue_node* n){
    if(q->size == 0){
        q->top = n;
    } else {
        q->bottom->next = n;
        n->prior = q->bottom;
    }

    q->bottom = n;
    q->size++;
}

queue_node* remove_from_queue(queue* q, int first){
    if(q->size==0)
        return NULL;

    queue_node *n;

    if(first){
        n = q->top;
        q->top = q->top->next;
    } else {
        n = q->bottom;
        q->bottom = q->bottom->prior;
    }

    q->size--;

    if(q->size == 0){
        if(first)
            q->bottom = NULL;
        else
            q->top = NULL;
    }

    return n;
}

queue_node* lifo_remove_from_queue(queue* q){
    return remove_from_queue(q, 0);
}

queue_node* fifo_remove_from_queue(queue* q){
    return remove_from_queue(q, 1);
}

void free_queue(queue* q){
    queue_node* n;
    while(q->size != 0){
        n = remove_from_queue(q, 1);
        free(n);
    }
}