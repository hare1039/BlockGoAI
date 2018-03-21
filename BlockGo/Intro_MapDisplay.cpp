#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "General.h"


void introduction()
{
    printf(" welcome to game that called 'block out' \n");
    printf(" following show how to control this game \n");
    printf("\n w : up \n");
    printf("\n s : down \n");
    printf("\n a : left \n");
    printf("\n d : right \n");
    printf("\n 1 : 口 \n");
    printf("\n 2 : 口 \n");
    printf("\n 3 : 口\n");
    printf("     口口\n");
    printf("     口\n");
    printf("\n 4 : 口口 \n");
    printf("       口口 \n");
    printf("\n 5 :   口口\n");
    printf("     口口\n");
    printf("\n 6 : 口\n");
    printf("     口口口\n");
    printf("\n 7 :     口\n");
    printf("     口口口\n");
    printf("\n 8 : 口口口口\n");
    printf("\n 9 : 口口 \n");
    printf("     口口 \n");
    printf("\n c : change directiono of block \n");
    printf("\n y : make a decision to set up the block in here\n");
    printf("\n Are you ready?\n");
    return;
}

void reduction_block()
{
    for (int iii = 0; iii < 4; iii++) {
        for (int jjj = 0; jjj < 4; jjj++) {
            block[iii][jjj] = false;
        }
    }
}

void reduction_map()
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

    system("clear");

    if (player1 == true) {
        printf("\n               Player1:O               \n\n");
    } else {
        printf("\n               Player2:X               \n\n");
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
                printf(" \e[33m%c\e[0m ", temporary_map[i][j]);
            } else if (temporary_map[i][j] == 'O') {
                printf(" \e[32m%c\e[0m ", temporary_map[i][j]);
            } else if (temporary_map[i][j] == 'X') {
                printf(" \e[31m%c\e[0m ", temporary_map[i][j]);
            } else {
                printf(" %c ", temporary_map[i][j]);
            }
        }
        printf("\n");
    }

    return;
}
