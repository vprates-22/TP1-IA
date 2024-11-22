#ifndef NODE_H
#define NODE_H

typedef struct{
    int x;
    int y;
    float cost;
    float real_value;
} node;

void init_node(node* n, int x, int y, float cost, float real_value);

#endif