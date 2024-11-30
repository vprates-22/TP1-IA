#include "../include/ids.h"

void verify_dfs_neighbors(float** board, int** visited, int height, int width, 
                          node** path, priority_queue* pq, node last_node){

    int x = last_node.x;
    int y = last_node.y;
    float cost = last_node.cost;
    
    for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
            if(!check_valid_neighbors(board, visited, x, y, i ,j, height, width))
                continue;

            path[y+j][x+i].x = x;
            path[y+j][x+i].y = y;
            path[y+j][x+i].cost = cost + board[y+j][x+i];
            path[y+j][x+i].other_value = last_node.other_value + 1;

            add_to_priority_queue(pq, x+i, y+j, cost + board[y+j][x+i], last_node.other_value-1);
        }
    }                
}

int depth_limited_search(int max_depth, float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end, node** path){
    node n;

    int** visited = create_visited_matrix(height, width);
    priority_queue *pq = init_priority_queue(height * width);

    add_to_priority_queue(pq, x_start, y_start, 0.0, max_depth);

    while(pq->size != 0){
        n = remove_from_priority_queue(pq);

        if(n.x == x_end && n.y == y_end)
            return 1;

        if(n.other_value == 0)
            continue;

        visited[n.y][n.x] = 1;

        verify_dfs_neighbors(board, visited, height, width, path, pq, n);
    }
    free_matrix((void**)visited, height);
    free_priority_queue(pq);

    return 0;
}

void iterative_deepening_search(float** board, int height, int width, 
                        int x_start, int y_start, int x_end, int y_end){
    int max_depth = 0;
    int result = 0;

    node** paths = create_path_matrix(height, width);
    
    paths[y_start][x_start].cost = 0;

    while(!result){
        max_depth++;
        result = depth_limited_search(max_depth, board, height, width, 
                                x_start, y_start, x_end, y_end, paths);
    }

    node n;
    init_node(&n, x_end, y_end, paths[y_end][x_end].cost, paths[y_end][x_end].cost);

    print_result(paths, n);
}