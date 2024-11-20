#include "../include/greedy.h"

float verify_greedy_neighbors(float** board, int height, int width,
                            int** visited, int* x, int* y, int x_end, int y_end){
    float val = 0.0;
    float best_val = __INT_MAX__;

    int best_dist = __INT_MAX__;
    
    int temp_x = *x;
    int temp_y = *y;

    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            // só permite que sejam (-1,0)/(0,-1)/(0,1)/(1,0)
            if(i == j || i + j == 0)
                continue;
            // impede segmentation fault
            if(0 > (*y)+j || (*y)+j >= height || 
               0 > (*x)+i || (*x)+i >= width)
                continue;
            // verifica se é parede
            if(board[(*y)+j][(*x)+i] < 0)
                continue;
            // verifica se já foi visto ou adicionada à fila
            if(visited[(*y)+j][(*x)+i])
                continue;

            int dist = abs(y_end - ((*y) + j)) + abs(x_end - ((*x) + i));

            if(board[(*y)+j][(*x)+i] < best_val ||
            (board[(*y)+j][(*x)+i] < best_val && dist < best_dist)
            ){
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

    paths[y_start][x_start].value = 0.0;

    int x = x_start;
    int y = y_start;
    float value = 0.0;

    int x_prior = x;
    int y_prior = y;

    paths[y][x].x = x;
    paths[y][x].y = y;
    paths[y][x].value = value;

    while(1){
        if(x == x_end && y == y_end){
            printf("%f ", value);
            print_path(paths, x_end, y_end);
            printf("\n");
            return;
        }

        x_prior = x;
        y_prior = y;
        
        visited[y][x] = 1;
        value += verify_greedy_neighbors(board, height, width, 
                                visited, &x, &y, x_end, y_end);

        if(x == x_prior && y == y_prior){
            printf("Caminho não encontrado\n");
            printf("%f ", value);
            print_path(paths, x, y);
            printf("\n");
            return;
        }

        paths[y][x].x = x_prior;
        paths[y][x].y = y_prior;
        paths[y][x].value = value;
    }
}