#include "../include/node.h"

void init_node(node* n, int x, int y, float cost, float other_value){
    n->x = x;
    n->y = y;
    n->cost = cost;
    n->other_value = other_value;
}