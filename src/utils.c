#include "../include/utils.h"

void** create_matrix(size_t size_of, int height, int width, void* default_value){
    void** matrix = malloc(height * sizeof(void*));
    
    for(int i = 0; i < height; i++){
        matrix[i] = malloc(width * size_of);
        for(int j = 0; j < width; j++){
            memcpy((char*)matrix[i] + j * size_of, default_value, size_of);
        }
    }
    
    return matrix;
}

int** create_visited_matrix(int height, int width){
    int default_value = 0;
    void** matrix = create_matrix(sizeof(int), height, width, &default_value);
    int** visited = (int**)matrix;

    return visited;
}

queue_node** create_path_matrix(int height, int width){
    queue_node* default_value = init_queue_node(-1, -1, 0);
    void** matrix = create_matrix(sizeof(queue_node), height, width, default_value);
    free(default_value);


    queue_node** visited = (queue_node**)matrix;
    return visited;
}

void free_matrix(void** board, int height){
    for(int i = 0; i < height; i++){
        free(board[i]);
    }
    free(board);
}