#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "General.h"

void S_printf_temporary_map()
{
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            S_temporary_map[i][j] = S_Map[i][j];
        }
    }

    for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
            if (S_block[ii][jj]) {
                if (S_player1) {
                    S_temporary_map[S_x_of_block + ii][S_y_of_block + jj] = 'O';
                } else {
                    S_temporary_map[S_x_of_block + ii][S_y_of_block + jj] = 'X';
                }
            }
        }
    }
    return;
}