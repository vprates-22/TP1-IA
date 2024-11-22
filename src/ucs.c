#include "../include/ucs.h"

void verify_ucs_neighbors(float** board, int height, int width, 
                int** visited, node** path, priority_queue* pq, node last_node){
    int x = last_node.x;
    int y = last_node.y;
    float cost = last_node.cost;

    for(int i = -1; i < 2; i++){
        for(int j = -1 ; j < 2; j++){
            if(!check_valid_neighbors(board, visited, x, y, i, j, height, width))
                continue;
            
            if(path[y+j][x+i].cost < 0 ||
               cost + board[y+j][x+i] < path[y+j][x+i].cost){
                
                path[y+j][x+i].x = x;
                path[y+j][x+i].y = y;
                path[y+j][x+i].cost = cost + board[y+j][x+i];
            }

            add_to_priority_queue(pq, x+i, y+j, cost + board[y+j][x+i], cost + board[y+j][x+i]);
        }
    }
}

void uniform_cost_search(float** board, int height, int width, 
                int x_start, int y_start, int x_end, int y_end){
    node n;
    priority_queue* pq = init_priority_queue(height * width);

    node** paths = create_path_matrix(height, width);
    int** visited = create_visited_matrix(height, width);

    paths[y_start][x_start].cost = 0.0;

    add_to_priority_queue(pq, x_start, y_start, 0.0, 0.0);
    
    while(pq->size != 0){
        n = remove_from_priority_queue(pq);
        
        if(visited[n.y][n.x])
            continue;

        if(n.x == x_end && n.y == y_end){
            print_result(paths, n);
            break;
        }
        
        verify_ucs_neighbors(board, height, width, visited, paths, pq, n);
        
        visited[n.y][n.x] = 1;
    }
}