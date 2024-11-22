#include "../include/greedy.h"

float verify_greedy_neighbors(float** board, int height, int width,
                            int** visited, int* x, int* y, int x_end, int y_end){
    float val = 0.0;
    float best_val = __INT_MAX__;

    int temp_x = *x;
    int temp_y = *y;

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(!check_valid_neighbors(board, visited, *x, *y, i, j, height, width))
                continue;

            if(board[(*y)+j][(*x)+i] < best_val){
                best_val = board[(*y)+j][(*x)+i];

                temp_x = (*x) + i;
                temp_y = (*y) + j;
                val = board[(*y)+j][(*x)+i];
            }
        }
    }

    (*x) = temp_x;
    (*y) = temp_y;

    return val;
}

void greedy(float** board, int height, int width, 
        int x_start, int y_start, int x_end, int y_end){

    node** paths = create_path_matrix(height, width);
    int** visited = create_visited_matrix(height, width);

    paths[y_start][x_start].cost = 0.0;

    int x = x_start;
    int y = y_start;
    float cost = 0.0;

    int x_prior = x;
    int y_prior = y;

    paths[y][x].x = x;
    paths[y][x].y = y;
    paths[y][x].cost = cost;

    while(1){
        if(x == x_end && y == y_end){
            node n;
            init_node(&n, x, y, cost, cost);
            print_result(paths, n);
            return;
        }

        x_prior = x;
        y_prior = y;
        
        visited[y][x] = 1;
        cost += verify_greedy_neighbors(board, height, width, 
                                visited, &x, &y, x_end, y_end);

        if(x == x_prior && y == y_prior){
            node n;
            init_node(&n, x, y, cost, cost);
            
            printf("Caminho não encontrado\n");
            print_result(paths, n);
            return;
        }

        paths[y][x].x = x_prior;
        paths[y][x].y = y_prior;
        paths[y][x].cost = cost;
        paths[y][x].other_value = cost;
    }
}