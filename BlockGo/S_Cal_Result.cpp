#include "General.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

void S_search_block1(int x, int y)
{
    S_final_map1[x][y] = 1;
    S_blocklife1[S_block_end1].x = x;
    S_blocklife1[S_block_end1].y = y;
    S_block_end1++;

    //up
    if (S_final_map1[x - 1][y] == 0) {
        S_search_block1(x - 1, y);
    } else if (S_final_map1[x - 1][y] == 2) {
        if (y > 0 && y < 13) {
            S_boundary[0 + y - 1] = true;
            S_boundary_number++;
        }
    } else {
    }

    //up & right
    if (S_final_map1[x - 1][y + 1] == 0) {
        S_search_block1(x - 1, y + 1);
    } else {
    }

    //right
    if (S_final_map1[x][y + 1] == 0) {
        S_search_block1(x, y + 1);
    } else if (S_final_map1[x][y + 1] == 2) {
        if (x > 0 && x < 13) {
            S_boundary[12 + x - 1] = true;
            S_boundary_number++;
        }
    } else {
    }

    //right & down
    if (S_final_map1[x + 1][y + 1] == 0) {
        S_search_block1(x + 1, y + 1);
    } else {
    }

    //down
    if (S_final_map1[x + 1][y] == 0) {
        S_search_block1(x + 1, y);
    } else if (S_final_map1[x + 1][y] == 2) {
        if (y > 0 && y < 13) {
            S_boundary[24 + 13 - y] = true;
            S_boundary_number++;
        }
    } else {
    }

    //down & left
    if (S_final_map1[x + 1][y - 1] == 0) {
        S_search_block1(x + 1, y - 1);
    } else {
    }

    //left
    if (S_final_map1[x][y - 1] == 0) {
        S_search_block1(x, y - 1);
    } else if (S_final_map1[x][y - 1] == 2) {
        if (x > 0 && x < 13) {
            S_boundary[36 + 13 - x] = true;
            S_boundary_number++;
        }
    } else {
    }
    //left & up
    if (S_final_map1[x - 1][y - 1] == 0) {
        S_search_block1(x - 1, y - 1);
    } else {
    }

    //end
    return;
}

void S_search_block2(int x, int y)
{
    S_final_map2[x][y] = 1;
    S_blocklife2[S_block_end2].x = x;
    S_blocklife2[S_block_end2].y = y;
    S_block_end2++;

    //up
    if (S_final_map2[x - 1][y] == 0) {
        S_search_block2(x - 1, y);
    } else if (S_final_map2[x - 1][y] == 2) {
        if (y > 0 && y < 13) {
            S_boundary[0 + y - 1] = true;
            S_boundary_number++;
        }
    } else {
    }

    //up & right
    if (S_final_map2[x - 1][y + 1] == 0) {
        S_search_block2(x - 1, y + 1);
    } else {
    }

    //right
    if (S_final_map2[x][y + 1] == 0) {
        S_search_block2(x, y + 1);
    } else if (S_final_map2[x][y + 1] == 2) {
        if (x > 0 && x < 13) {
            S_boundary[12 + x - 1] = true;
            S_boundary_number++;
        }
    } else {
    }

    //right & down
    if (S_final_map2[x + 1][y + 1] == 0) {
        S_search_block2(x + 1, y + 1);
    } else {
    }

    //down
    if (S_final_map2[x + 1][y] == 0) {
        S_search_block2(x + 1, y);
    } else if (S_final_map2[x + 1][y] == 2) {
        if (y > 0 && y < 13) {
            S_boundary[24 + 13 - y] = true;
            S_boundary_number++;
        }
    } else {
    }

    //down & left
    if (S_final_map2[x + 1][y - 1] == 0) {
        S_search_block2(x + 1, y - 1);
    } else {
    }

    //left
    if (S_final_map2[x][y - 1] == 0) {
        S_search_block2(x, y - 1);
    } else if (S_final_map2[x][y - 1] == 2) {
        if (x > 0 && x < 13) {
            S_boundary[36 + 13 - x] = true;
            S_boundary_number++;
        }
    } else {
    }

    //left & up
    if (S_final_map2[x - 1][y - 1] == 0) {
        S_search_block2(x - 1, y - 1);
    } else {
    }

    //end
    return;
}

bool S_decide_if_live()
{
    if (S_boundary_number > 1) {
        for (int ii = 0; ii < 48; ii++) {
            for (int jj = 0; jj < S_boundary_number; jj++) {
                int index = ((ii + jj) % 48);
                if (S_boundary[index] == true && jj == S_boundary_number - 1) {
                    return false;
                }
                if (S_boundary[index] == false) {
                    break;
                }
            }
        }
        return true;
    }
    return false;
}

void S_clear_live_or_dead_map()
{
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            S_live_or_dead_map[i][j] = 0;
        }
    }
    for (int ii = 0; ii < 15; ii++) {
        S_live_or_dead_map[ii][0] = 2;
        S_live_or_dead_map[0][ii] = 2;
        S_live_or_dead_map[ii][14] = 2;
        S_live_or_dead_map[14][ii] = 2;
    }
    return;
}

void S_dead_or_life2_search(int x, int y)
{
    S_live_or_dead_map[x][y] = 1;

    //up
    if (S_live_or_dead_map[x - 1][y] == 0) {
        S_dead_or_life2_search(x - 1, y);
    } else {
    }
    //right
    if (S_live_or_dead_map[x][y + 1] == 0) {
        S_dead_or_life2_search(x, y + 1);
    } else {
    }
    //down
    if (S_live_or_dead_map[x + 1][y] == 0) {
        S_dead_or_life2_search(x + 1, y);
    } else {
    }
    //left
    if (S_live_or_dead_map[x][y - 1] == 0) {
        S_dead_or_life2_search(x, y - 1);
    } else {
    }

    //end
    return;
}

bool S_decide_if_2_1(int p1)
{
    S_clear_live_or_dead_map();
    if (p1 == 1) {
        for (int aa = S_block_begin1; aa < S_block_end1; aa++) {
            S_live_or_dead_map[S_blocklife1[aa].x][S_blocklife1[aa].y] = 3;
        }
    }
    if (p1 == 2) {
        for (int aa = S_block_begin2; aa < S_block_end2; aa++) {
            S_live_or_dead_map[S_blocklife2[aa].x][S_blocklife2[aa].y] = 3;
        }
    }
    S_dead_or_life2_search(1, 1);
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            if (S_live_or_dead_map[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

void S_clear_search_array()
{
    for (int i = 0; i < S_search_array_number; i++) {
        S_search_array[i] = -1;
    }
    S_search_array_number = 0;
    return;
}

void S_search_number(int x, int y)
{

    S_final_map[x][y] = 1;
    S_unkown_number += 1;

    for (int aa = 0; aa < 30; aa++) {
        if (x == S_blocklife1[aa].x && y == S_blocklife1[aa].y && S_blocklife1[aa].if_live == false) {
            S_unkown_number += 1;
        }
        if (x == S_blocklife2[aa].x && y == S_blocklife2[aa].y && S_blocklife2[aa].if_live == false) {
            S_unkown_number += 1;
        }
    }
    //up
    if (S_final_map[x + 1][y] == 0) {
        S_search_number(x + 1, y);
    } else if (S_final_map[x + 1][y] == 1) {
        S_final_map[x + 1][y] = 1;
    } else {
        S_search_array[S_search_array_number] = S_final_map[x + 1][y];
        S_search_array_number++;
    }
    //down
    if (S_final_map[x - 1][y] == 0) {
        S_search_number(x - 1, y);
    } else if (S_final_map[x - 1][y] == 1) {
        S_final_map[x - 1][y] = 1;
    } else {
        S_search_array[S_search_array_number] = S_final_map[x - 1][y];
        S_search_array_number++;
    }
    //left
    if (S_final_map[x][y - 1] == 0) {
        S_search_number(x, y - 1);
    } else if (S_final_map[x][y - 1] == 1) {
        S_final_map[x][y - 1] = 1;
    } else {
        S_search_array[S_search_array_number] = S_final_map[x][y - 1];
        S_search_array_number++;
    }
    //right
    if (S_final_map[x][y + 1] == 0) {
        S_search_number(x, y + 1);
    } else if (S_final_map[x][y + 1] == 1) {
        S_final_map[x][y + 1] = 1;
    } else {
        S_search_array[S_search_array_number] = S_final_map[x][y + 1];
        S_search_array_number++;
    }
    //end
    return;
}

void S_decide_whose_number()
{
    bool p1 = false;
    bool p2 = false;
    bool side = false;
    for (int i = 0; i < S_search_array_number; i++) {
        if (S_search_array[i] == 2) {
            side = true;
        } else if (S_search_array[i] == 3) {
            p1 = true;
        } else if (S_search_array[i] == 4) {
            p2 = true;
        }
    }
    if (p1 == true && p2 == false) {
        S_number_of_p1 += S_unkown_number;
        S_unkown_number = 0;
    } else if (p1 == false && p2 == true) {
        S_number_of_p2 += S_unkown_number;
        S_unkown_number = 0;
    } else {
        S_unkown_number = 0;
    }
    return;
}
