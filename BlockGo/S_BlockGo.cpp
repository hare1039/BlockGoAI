#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "General.h"
#include <string>

int S_Simulate(int whichplayer, int whichbout)
{
    //-----------------------------Rule-----------------------------
    int player_return = 0;
    if (whichplayer == 1 && whichbout < 10) {
        //printf("Simulate_player1\n");
        S_x_of_block = 1;
        S_y_of_block = 1;
        player_return = S_player(1, 1);
        if (player_return == 55) {
            //printf("	sim error\n");
            //scanf("%d", &aaaa);
            return 3;
        }

        S_x_of_block = 1;
        S_y_of_block = 1;
        player_return = S_player(2, 0);
        if (player_return == 55) {
            //printf("	sim error\n");
            //scanf("%d", &aaaa);
            return 3;
        }

        for (int k = whichbout + 1; k < 10; k++) {

            S_x_of_block = 1;
            S_y_of_block = 1;
            player_return = S_player(1, 0);
            if (player_return == 55) {
                //printf("	sim error\n");
                //scanf("%d", &aaaa);
                return 3;
            }

            S_x_of_block = 1;
            S_y_of_block = 1;
            player_return = S_player(2, 0);
            if (player_return == 55) {
                //printf("	sim error\n");
                //scanf("%d", &aaaa);
                return 3;
            }
        }

    } else if (whichplayer == 2 && whichbout < 10) {
        //printf("Simulate_player2\n");
        S_x_of_block = 1;
        S_y_of_block = 1;
        player_return = S_player(2, 1);
        if (player_return == 55) {
            //printf("	sim error\n");
            //scanf("%d", &aaaa);
            return 3;
        }

        for (int k = whichbout + 1; k < 10; k++) {

            S_x_of_block = 1;
            S_y_of_block = 1;
            player_return = S_player(1, 0);
            if (player_return == 55) {
                //printf("	sim error\n");
                //scanf("%d", &aaaa);
                return 3;
            }

            S_x_of_block = 1;
            S_y_of_block = 1;
            player_return = S_player(2, 0);
            if (player_return == 55) {
                //printf("	sim error\n");
                //scanf("%d", &aaaa);
                return 3;
            }
        }
    }

    //-----------------------------Rule-----------------------------

    //-----------------------------Cal_Result-----------------------------

    int p1num = 0;
    int p2num = 0;
    //new begin
    for (int aaa = 0; aaa < 48; aaa++) {
        S_boundary[aaa] = false;
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (S_Map[i][j] == '-') {
                S_final_map1[i][j] = 2;
                S_final_map2[i][j] = 2;
            } else if (S_Map[i][j] == 'O') {
                S_final_map1[i][j] = 0;
                S_final_map2[i][j] = 3;
                p1num++;
            } else if (S_Map[i][j] == 'X') {
                S_final_map1[i][j] = 3;
                S_final_map2[i][j] = 0;
                p2num++;
            } else {
                S_final_map1[i][j] = 3;
                S_final_map2[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (S_final_map1[i][j] == 0) {

                S_search_block1(i, j);

                if (S_decide_if_live() || S_decide_if_2_1(1)) {
                    for (int aa = S_block_begin1; aa < S_block_end1; aa++) {
                        S_blocklife1[aa].if_live = true;
                    }
                } else {
                    for (int aa = S_block_begin1; aa < S_block_end1; aa++) {
                        S_blocklife1[aa].if_live = false;
                    }
                }
                S_block_begin1 = S_block_end1;
                for (int aaa = 0; aaa < 48; aaa++) {
                    S_boundary[aaa] = false;
                }
                S_boundary_number = 0;
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (S_final_map2[i][j] == 0) {
                S_search_block2(i, j);

                if (S_decide_if_live() || S_decide_if_2_1(2)) {
                    for (int aa = S_block_begin2; aa < S_block_end2; aa++) {
                        S_blocklife2[aa].if_live = true;
                    }
                } else {
                    for (int aa = S_block_begin2; aa < S_block_end2; aa++) {
                        S_blocklife2[aa].if_live = false;
                    }
                }
                S_block_begin2 = S_block_end2;
                for (int aaa = 0; aaa < 48; aaa++) {
                    S_boundary[aaa] = false;
                }
                S_boundary_number = 0;
            }
        }
    }
    for (int aaa = 0; aaa < 30; aaa++) {
        if (S_blocklife1[aaa].if_live == false) {
            S_Map[S_blocklife1[aaa].x][S_blocklife1[aaa].y] = '+';
        }
        if (S_blocklife2[aaa].if_live == false) {
            S_Map[S_blocklife2[aaa].x][S_blocklife2[aaa].y] = '+';
        }
    }
    //new end
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (S_Map[i][j] == '-') {
                S_final_map[i][j] = 2;
            } else if (S_Map[i][j] == 'O') {
                S_final_map[i][j] = 3;
            } else if (S_Map[i][j] == 'X') {
                S_final_map[i][j] = 4;
            } else {
                S_final_map[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            if (S_final_map[i][j] == 0) {

                S_search_number(i, j);

                S_decide_whose_number();

                S_clear_search_array();
            }
        }
    }

    if (S_number_of_p1 > S_number_of_p2) {
        //printf("Simulate_end_win1\n");
        //scanf("%d", &aaaa);
        return 1;
    } else if (S_number_of_p1 < S_number_of_p2) {
        //printf("Simulate_end_win2\n");
        //scanf("%d", &aaaa);
        return 2;
    } else {
        //printf("Simulate_end_no_win\n");
        //scanf("%d", &aaaa);
        return 0;
    }
}
