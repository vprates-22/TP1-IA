#include <stdio.h>
#include <stdlib.h>

#include "./include/greedy.h"
#include "./include/a_star.h"
#include "./include/bfs.h"
#include "./include/ucs.h"

float** read_board(char* input_file, int* height, int* width){
    FILE* file;
    float** board;

    char cell;

    file = fopen(input_file, "rt");
    fscanf(file, "%d %d\n", width, height);

    board = malloc((*height) * sizeof(float*));
    for(int i = 0; i < (*height); i++){
        board[i] = malloc((*width) * sizeof(float));
        for(int j = 0; j < (*width); j++){
            fscanf(file, "%c", &cell);
            switch(cell){
                case '.':
                    board[i][j] = 1.0;
                    break;
                case ';':
                    board[i][j] = 1.5;
                    break;  
                case '+':
                    board[i][j] = 2.5;
                    break;
                case 'x':
                    board[i][j] = 6.0;
                    break;
                case '@':
                    board[i][j] = -1;
                    break;
                default:
                    break;
            }
        }
        fscanf(file, "%c", &cell); // consome quebra de linha
    }
    fclose(file);

    return board;
}

int main(int argc, char** argv){
    int x_start = atoi(argv[3]);
    int y_start = atoi(argv[4]);
    int x_end   = atoi(argv[5]);
    int y_end   = atoi(argv[6]);
    
    int height, width;
    float** board;

    board = read_board(argv[1], &height, &width);

    if(strcmp(argv[2], "BFS") == 0){
        breadth_first_search(board, height, width,
                x_start, y_start, x_end, y_end);
    } else if(strcmp(argv[2], "IDS") == 0){
        // uniform_cost_search(board, height, width,
        //         x_start, y_start, x_end, y_end);
    } else if(strcmp(argv[2], "UCS") == 0){
        uniform_cost_search(board, height, width,
                x_start, y_start, x_end, y_end);
    } else if(strcmp(argv[2], "Greedy") == 0){
        greedy(board, height, width,
                x_start, y_start, x_end, y_end);
    } else if(strcmp(argv[2], "Astar") == 0){
        a_star(board, height, width,
                x_start, y_start, x_end, y_end);
    }    

    free_matrix((void**)board, height);

    return 0;
}