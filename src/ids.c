#include "../include/ids.h"

int check_ids_neighbors(int depth, float** board, int** visited, int height, int width,
                        int x, int y, float cost, int x_end, int y_end, node** path){
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(!check_valid_neighbors(board, visited, x, y, i ,j, height, width))
                continue;

            path[y+j][x+i].x = x;
            path[y+j][x+i].y = y;
            path[y+j][x+i].cost = cost + board[y+j][x+i];
            path[y+j][x+i].other_value = cost + board[y+j][x+i];

            visited[y][x] = 1;

            if(depth_limited_search(depth, board, visited, height, width, x+i, y+j, cost + board[y+j][x+i], x_end, y_end, path))
                return 1;

            visited[y][x] = 0;
        }
    }
    return 0;
}

int depth_limited_search(int depth, float** board, int** visited, int height, int width, 
                        int x, int y, float cost, int x_end, int y_end, node** path){

    if(x == x_end && y == y_end){
        return 1;
    }

    if(depth <= 0){
        return 0;
    }
    
    return check_ids_neighbors(depth-1, board, visited, height, width, x, y, cost, x_end, y_end, path);
}

void iterative_deepening_search(float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end){
    int max_depth = 0;
    int result = 0;

    int** visited = create_visited_matrix(height, width);
    node** paths = create_path_matrix(height, width);
    paths[y_start][x_start].cost = 0;


    while(!result){
        result = depth_limited_search(max_depth, board, visited, height, width, 
                                x_start, y_start, 0.0, x_end, y_end, paths);
        max_depth++;
    }

    node n;
    init_node(&n, x_end, y_end, paths[y_end][x_end].cost, paths[y_end][x_end].cost);

    print_result(paths, n);
}