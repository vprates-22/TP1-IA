#ifndef NODE_H
#define NODE_H

typedef struct{
    int x;
    int y;
    float value;
} node;

void init_node(node* n, int x, int y, float value);

#endif