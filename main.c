#include <stdio.h>
#include <stdlib.h>

#include "./include/utils.h"
#include "./include/queue.h"
#include "./include/bfs.h"

// #define INF __FLT_MAX__

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
    int x_start = atoi(argv[2]);
    int y_start = atoi(argv[3]);
    int x_end   = atoi(argv[4]);
    int y_end   = atoi(argv[5]);
    
    int height, width;
    float** board;

    board = read_board(argv[1], &height, &width);

    float value = breadth_first_search(board, height, width,
                        x_start, y_start, x_end, y_end);

    printf("%f\n", value);

    free_matrix((void**)board, height);

    return 0;
}