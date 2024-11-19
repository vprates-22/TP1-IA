#include "../include/bfs.h"

void verify_bfs_neighbors(float** board, int height, int width, 
                      int** visited, node** path, queue* q, queue_node* last_node){
    int x = last_node->n.x;
    int y = last_node->n.y;
    float val = last_node->n.value;
    queue_node* n;

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            // só permite que sejam (-1,0)/(0,-1)/(0,1)/(1,0)
            if(i == j || i+j == 0) 
                continue;
            // impede segmentation fault
            if(0 > y+j || y+j >= height || 
               0 > x+i || x+i >= width) 
                continue;
            // verifica se é parede
            if(board[y+j][x+i] < 0)
                continue;
            // verifica se já foi visto ou adicionada à fila
            if(visited[y+j][x+i] || path[y+j][x+i].value != -1) 
                continue;

            // o node que antecedeu o vizinho
            path[y+j][x+i].x = x;
            path[y+j][x+i].y = y;
            path[y+j][x+i].value = val + board[y+j][x+i];
            n = init_queue_node(x+i, y+j, val + board[y+j][x+i]); // cria o node
            add_to_queue(q, n); // adiciona à fila
        }
    }
}

float breadth_first_search(float** board, int height,  int width,
                          int x_start,   int y_start, int x_end, int y_end){
    queue_node* n;
    queue* q = init_queue();

    node** paths = create_path_matrix(height, width);
    int** visited = create_visited_matrix(height, width);

    n = init_queue_node(x_start, y_start, 0.0);
    paths[y_start][x_start].value = 0;

    add_to_queue(q, n);

    while(q->size > 0){
        n = fifo_remove_from_queue(q);

        if(!visited[n->n.y][n->n.x]){
            if(n->n.y == y_end && n->n.x == x_end){
                break;
            }
            verify_bfs_neighbors(board, height, width, 
                             visited, paths, q, n);
        }

        visited[n->n.y][n->n.x] = 1;
        free(n);
    }
    free_queue(q);

    return n->n.value;
}