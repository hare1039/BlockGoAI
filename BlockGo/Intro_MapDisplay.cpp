#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "General.h"


void introduction()
{
    fprintf(ofp, " welcome to game that called 'block out' \n");
    fprintf(ofp, " following show how to control this game \n");
    fprintf(ofp, "\n s : down \n");
    fprintf(ofp, "\n w : up \n");
    fprintf(ofp, "\n a : left \n");
    fprintf(ofp, "\n d : right \n");
    fprintf(ofp, "\n 1 : 口 \n");
    fprintf(ofp, "\n 2 : 口 \n");
    fprintf(ofp, "\n 3 : 口\n");
    fprintf(ofp, "     口口\n");
    fprintf(ofp, "     口\n");
    fprintf(ofp, "\n 4 : 口口 \n");
    fprintf(ofp, "       口口 \n");
    fprintf(ofp, "\n 5 :   口口\n");
    fprintf(ofp, "     口口\n");
    fprintf(ofp, "\n 6 : 口\n");
    fprintf(ofp, "     口口口\n");
    fprintf(ofp, "\n 7 :     口\n");
    fprintf(ofp, "     口口口\n");
    fprintf(ofp, "\n 8 : 口口口口\n");
    fprintf(ofp, "\n 9 : 口口 \n");
    fprintf(ofp, "     口口 \n");
    fprintf(ofp, "\n c : change directiono of block \n");
    fprintf(ofp, "\n y : make a decision to set up the block in here\n");
    fprintf(ofp, "\n Are you ready?\n");
    return;
}

void initialize_block()
{
    for (int iii = 0; iii < 4; iii++) {
        for (int jjj = 0; jjj < 4; jjj++) {
            block[iii][jjj] = false;
        }
    }
}

void initialize_map()
{
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            Map[i][j] = '+';
        }
    }
    for (int ii = 0; ii < 15; ii++) {
        Map[ii][0] = '-';
        Map[0][ii] = '-';
        Map[ii][14] = '-';
        Map[14][ii] = '-';
    }
    Map[4][4] = '*';
    Map[4][10] = '*';
    Map[10][4] = '*';
    Map[10][10] = '*';
    return;
}

void printf_temporary_map()
{

    //system("clear");
    fprintf(ofp, "\n\n\n");
    if (player1 == true) {
        fprintf(ofp, "\n               Player1:O               \n\n");
    } else {
        fprintf(ofp, "\n               Player2:X               \n\n");
    }

    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            temporary_map[i][j] = Map[i][j];
        }
    }

    for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
            if (block[ii][jj]) {
                if (player1) {
                    temporary_map[x_of_block + ii][y_of_block + jj] = 'O';
                } else {
                    temporary_map[x_of_block + ii][y_of_block + jj] = 'X';
                }
            }
        }
    }

    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            if (temporary_map[i][j] == '*') {
                fprintf(ofp, " \e[33m%c\e[0m ", temporary_map[i][j]);
            } else if (temporary_map[i][j] == 'O') {
                fprintf(ofp, " \e[32m%c\e[0m ", temporary_map[i][j]);
            } else if (temporary_map[i][j] == 'X') {
                fprintf(ofp, " \e[31m%c\e[0m ", temporary_map[i][j]);
            } else {
                fprintf(ofp, " %c ", temporary_map[i][j]);
            }
        }
        fprintf(ofp, "\n");
    }

    return;
}
