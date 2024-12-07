#include "../include/ids.h"

int verify_dfs_neighbors(int depth, int max_depth, float** board, int height, int width, 
                          int x, int y, float cost, int x_end, int y_end, 
                          int** visited, node** path){    
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(!check_valid_neighbors(board, visited, x, y, i ,j, height, width))
                continue;

            if(path[y+j][x+i].other_value != -1 && path[y+j][x+i].other_value <= depth)
                continue;

            path[y+j][x+i].x = x;
            path[y+j][x+i].y = y;
            path[y+j][x+i].cost = cost + board[y+j][x+i];
            path[y+j][x+i].other_value = depth;

            visited[y+j][x+i] = 1;

            if(depth_limited_search(depth, max_depth, board, height, width, x+i, y+j, cost + board[y+j][x+i],
                                        x_end, y_end, visited, path))
                return 1;

            visited[y+j][x+i] = 0;
        }
    }
    return 0;  
}

int depth_limited_search(int depth, int max_depth, float** board, int height, int width, 
                        int x, int y, int cost, int x_end, int y_end,
                        int** visited, node** path){
    if(x == x_end && y == y_end)
        return 1;
    
    if(depth == max_depth)
        return 0;
    
    return verify_dfs_neighbors(depth+1, max_depth, board, height, width, x, y, cost,
                                 x_end, y_end, visited, path);
}

void iterative_deepening_search(float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end){
    int max_depth = 0;

    int** visited = create_visited_matrix(height, width);
    node** paths;

    while(1){
        paths = create_path_matrix(height, width);
        
        paths[y_start][x_start].cost = 0;
        paths[y_start][x_start].other_value = 0;
        
        max_depth++;
        if(depth_limited_search(0, max_depth, board, height, width, 
                                x_start, y_start, 0.0, x_end, y_end, visited,  paths))
            break;

        free_matrix((void**)paths, height);
    }

    node n;
    init_node(&n, x_end, y_end, paths[y_end][x_end].cost, paths[y_end][x_end].cost);

    print_result(paths, n);
}