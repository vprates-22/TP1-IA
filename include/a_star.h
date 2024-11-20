#ifndef A_STAR_H
#define A_STAR_H

void a_star(float** board, int height, int width, 
        int x_start, int y_start, int x_end, int y_end);
void verify_a_star_neighbors();

#endif