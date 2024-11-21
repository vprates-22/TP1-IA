#include "../include/node.h"

void init_node(node* n, int x, int y, float value, float real_value){
    n->x = x;
    n->y = y;
    n->value = value;
    n->real_value = real_value;
}