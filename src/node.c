#include "../include/node.h"

void init_node(node* n, int x, int y, float cost, float real_value){
    n->x = x;
    n->y = y;
    n->cost = cost;
    n->real_value = real_value;
}