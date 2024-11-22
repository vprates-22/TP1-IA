#include "../include/queue.h"

queue_node* init_queue_node(int x, int y, float cost, float other_value){
    queue_node* n = malloc(sizeof(queue_node));
    
    init_node(&(n->n), x, y, cost, other_value);

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
    if(q->size++ == 0){
        q->top = n;
    } else {
        q->bottom->next = n;
        n->prior = q->bottom;
    }

    q->bottom = n;
}

queue_node* remove_from_queue(queue* q){
    if(q->size==0)
        return NULL;

    queue_node *n;

    n = q->top;
    q->top = q->top->next;

    if(--q->size != 0){
        return n;
    }

    q->bottom = NULL;

    return n;
}

void free_queue(queue* q){
    queue_node* n;
    while(q->size != 0){
        n = remove_from_queue(q);
        free(n);
    }
}