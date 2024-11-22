#include "../include/ids.h"

void check_ids_neighbors(float** board, int height, int width, int depth,
                      int** visited, node** path, queue* q, queue_node* last_node){
    int x = last_node->n.x;
    int y = last_node->n.y;
    float cost = last_node->n.cost;

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(!check_valid_neighbors(board, visited, x, y, i ,j, height, width))
                continue;

            
        }
    }
}

int depth_limited_search(int depth, float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end){
    float result = 0.0;

    queue_node* n;
    queue* q = init_queue();

    node** paths = create_path_matrix(height, width);
    int** visited = create_visited_matrix(height, width);

    n = init_queue_node(x_start, y_start, 0.0, 0.0);
    paths[y_start][x_start].cost = 0;

    add_to_queue(q, n);
    while(q->size != 0){
        n = lifo_remove_from_queue(q);

        if(n->n.x == x_end || n->n.y == y_end){
            return 1;
        }
        if(depth < 0)
            return 0;
        
    }

    return 0;
}

void iterative_deepening_search(float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end){
    int max_depth = 0;
    
    while(!depth_limited_search(max_depth, board, height, width, 
                                x_start, y_start, x_end, y_end)){
        max_depth++;
    }

    print_result(paths, n);
}