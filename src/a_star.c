#include "../include/a_star.h"

int heuristic(int x, int y, int x_end, int y_end){
    return abs(x - x_end) + abs(y - y_end);
}

void verify_a_star_neighbors(float** board, int height, int width, 
                    int x_end, int y_end, int** visited, node** path, 
                    priority_queue* pq, node last_node){
    
    int x = last_node.x;
    int y = last_node.y;
    float value = last_node.real_value;
    
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(!check_valid_neighbors(board, visited, x, y, i, j, height, width))
                continue;

            float new_val = value + board[y+j][x+i];
            float old_val = path[y+j][x+i].real_value;
            float pred_val = new_val + heuristic(x+i, y+j, x_end, y_end);

            if(old_val == -1 || new_val < old_val){
                path[y+j][x+i].x = x;
                path[y+j][x+i].y = y;
                path[y+j][x+i].value = pred_val;
                path[y+j][x+i].real_value = new_val;
            }
            
            add_to_priority_queue(pq, x+i, y+j, pred_val, new_val);
        }
    }
}

void a_star(float** board, int height, int width, 
        int x_start, int y_start, int x_end, int y_end){
    node n;
    priority_queue* pq = init_priority_queue(height * width);

    int** visited = create_visited_matrix(height, width);
    node** paths = create_path_matrix(height, width);

    paths[y_start][x_start].value = 0;

    add_to_priority_queue(pq, x_start, y_start, 0.0, 0.0);

    while(pq->size != 0){
        n = remove_from_priority_queue(pq);

        if(visited[n.y][n.x])
            continue;
        
        visited[n.y][n.x] = 1;

        if(n.x == x_end && n.y == y_end){
            printf("%.1f ", n.real_value);
            print_path(paths, n.x, n.y);
            printf("\n");
            return;
        }

        verify_a_star_neighbors(board, height, width, 
                    x_end, y_end, visited, paths, pq, n);
        
    }
}