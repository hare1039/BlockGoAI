#include "General.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>

void search_block1(int x, int y)
{
    final_map1[x][y] = 1;
    blocklife1[block_end1].x = x;
    blocklife1[block_end1].y = y;
    block_end1++;

    //up
    if (final_map1[x - 1][y] == 0) {
        search_block1(x - 1, y);
    } else if (final_map1[x - 1][y] == 2) {
        if (y > 0 && y < 13) {
            boundary[0 + y - 1] = true;
            boundary_number++;
        }
    } else {
    }
    //up&right
    if (final_map1[x - 1][y + 1] == 0) {
        search_block1(x - 1, y + 1);
    } else {
    }

    //right
    if (final_map1[x][y + 1] == 0) {
        search_block1(x, y + 1);
    } else if (final_map1[x][y + 1] == 2) {
        if (x > 0 && x < 13) {
            boundary[12 + x - 1] = true;
            boundary_number++;
        }
    } else {
    }

    //right&down
    if (final_map1[x + 1][y + 1] == 0) {
        search_block1(x + 1, y + 1);
    } else {
    }

    //down
    if (final_map1[x + 1][y] == 0) {
        search_block1(x + 1, y);
    } else if (final_map1[x + 1][y] == 2) {
        if (y > 0 && y < 13) {
            boundary[24 + 13 - y] = true;
            boundary_number++;
        }
    } else {
    }

    //down&left
    if (final_map1[x + 1][y - 1] == 0) {
        search_block1(x + 1, y - 1);
    } else {
    }

    //left
    if (final_map1[x][y - 1] == 0) {
        search_block1(x, y - 1);
    } else if (final_map1[x][y - 1] == 2) {
        if (x > 0 && x < 13) {
            boundary[36 + 13 - x] = true;
            boundary_number++;
        }
    } else {
    }

    //left&up
    if (final_map1[x - 1][y - 1] == 0) {
        search_block1(x - 1, y - 1);
    } else {
    }

    //end
    return;
}

void search_block2(int x, int y)
{
    final_map2[x][y] = 1;
    blocklife2[block_end2].x = x;
    blocklife2[block_end2].y = y;
    block_end2++;

    //up
    if (final_map2[x - 1][y] == 0) {
        search_block2(x - 1, y);
    } else if (final_map2[x - 1][y] == 2) {
        if (y > 0 && y < 13) {
            boundary[0 + y - 1] = true;
            boundary_number++;
        }
    } else {
    }

    //up & right
    if (final_map2[x - 1][y + 1] == 0) {
        search_block2(x - 1, y + 1);
    } else {
    }

    //right
    if (final_map2[x][y + 1] == 0) {
        search_block2(x, y + 1);
    } else if (final_map2[x][y + 1] == 2) {
        if (x > 0 && x < 13) {
            boundary[12 + x - 1] = true;
            boundary_number++;
        }
    } else {
    }

    //right & down
    if (final_map2[x + 1][y + 1] == 0) {
        search_block2(x + 1, y + 1);
    } else {
    }

    //down
    if (final_map2[x + 1][y] == 0) {
        search_block2(x + 1, y);
    } else if (final_map2[x + 1][y] == 2) {
        if (y > 0 && y < 13) {
            boundary[24 + 13 - y] = true;
            boundary_number++;
        }
    } else {
    }

    //down & left
    if (final_map2[x + 1][y - 1] == 0) {
        search_block2(x + 1, y - 1);
    } else {
    }

    //left
    if (final_map2[x][y - 1] == 0) {
        search_block2(x, y - 1);
    } else if (final_map2[x][y - 1] == 2) {
        if (x > 0 && x < 13) {
            boundary[36 + 13 - x] = true;
            boundary_number++;
        }
    } else {
    }

    //left & up
    if (final_map2[x - 1][y - 1] == 0) {
        search_block2(x - 1, y - 1);
    } else {
    }

    //end
    return;
}

bool decide_if_live()
{
    if (boundary_number > 1) {
        for (int ii = 0; ii < 48; ii++) {
            for (int jj = 0; jj < boundary_number; jj++) {
                int index = ((ii + jj) % 48);
                if (boundary[index] == true && jj == boundary_number - 1) {
                    return false;
                }
                if (boundary[index] == false) {
                    break;
                }
            }
        }
        return true;
    }
    return false;
}

void clear_live_or_dead_map()
{
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            live_or_dead_map[i][j] = 0;
        }
    }
    for (int ii = 0; ii < 15; ii++) {
        live_or_dead_map[ii][0] = 2;
        live_or_dead_map[0][ii] = 2;
        live_or_dead_map[ii][14] = 2;
        live_or_dead_map[14][ii] = 2;
    }
    return;
}

void dead_or_life2_search(int x, int y)
{
    live_or_dead_map[x][y] = 1;

    //up
    if (live_or_dead_map[x - 1][y] == 0) {
        dead_or_life2_search(x - 1, y);
    } else {
    }
    //right
    if (live_or_dead_map[x][y + 1] == 0) {
        dead_or_life2_search(x, y + 1);
    } else {
    }
    //down
    if (live_or_dead_map[x + 1][y] == 0) {
        dead_or_life2_search(x + 1, y);
    } else {
    }
    //left
    if (live_or_dead_map[x][y - 1] == 0) {
        dead_or_life2_search(x, y - 1);
    } else {
    }

    //end
    return;
}

bool decide_if_2_1(int p1)
{
    clear_live_or_dead_map();
    if (p1 == 1) {
        for (int aa = block_begin1; aa < block_end1; aa++) {
            live_or_dead_map[blocklife1[aa].x][blocklife1[aa].y] = 3;
        }
    }
    if (p1 == 2) {
        for (int aa = block_begin2; aa < block_end2; aa++) {
            live_or_dead_map[blocklife2[aa].x][blocklife2[aa].y] = 3;
        }
    }
    dead_or_life2_search(1, 1);
    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            if (live_or_dead_map[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}

void clear_search_array()
{
    for (int i = 0; i < search_array_number; i++) {
        search_array[i] = -1;
    }
    search_array_number = 0;
    return;
}

void search_number(int x, int y)
{

    final_map[x][y] = 1;
    unkown_number += 1;

    for (int aa = 0; aa < 30; aa++) {
        if (x == blocklife1[aa].x && y == blocklife1[aa].y && blocklife1[aa].if_live == false) {
            unkown_number += 1;
        }
        if (x == blocklife2[aa].x && y == blocklife2[aa].y && blocklife2[aa].if_live == false) {
            unkown_number += 1;
        }
    }
    //up
    if (final_map[x + 1][y] == 0) {
        search_number(x + 1, y);
    } else if (final_map[x + 1][y] == 1) {
        final_map[x + 1][y] = 1;
    } else {
        search_array[search_array_number] = final_map[x + 1][y];
        search_array_number++;
    }
    //down
    if (final_map[x - 1][y] == 0) {
        search_number(x - 1, y);
    } else if (final_map[x - 1][y] == 1) {
        final_map[x - 1][y] = 1;
    } else {
        search_array[search_array_number] = final_map[x - 1][y];
        search_array_number++;
    }
    //left
    if (final_map[x][y - 1] == 0) {
        search_number(x, y - 1);
    } else if (final_map[x][y - 1] == 1) {
        final_map[x][y - 1] = 1;
    } else {
        search_array[search_array_number] = final_map[x][y - 1];
        search_array_number++;
    }
    //right
    if (final_map[x][y + 1] == 0) {
        search_number(x, y + 1);
    } else if (final_map[x][y + 1] == 1) {
        final_map[x][y + 1] = 1;
    } else {
        search_array[search_array_number] = final_map[x][y + 1];
        search_array_number++;
    }
    //end
    return;
}

void decide_whose_number()
{
    bool p1 = false;
    bool p2 = false;
    bool side = false;
    for (int i = 0; i < search_array_number; i++) {
        if (search_array[i] == 2) {
            side = true;
        } else if (search_array[i] == 3) {
            p1 = true;
        } else if (search_array[i] == 4) {
            p2 = true;
        }
    }
    if (p1 == true && p2 == false) {
        number_of_p1 += unkown_number;
        unkown_number = 0;
    } else if (p1 == false && p2 == true) {
        number_of_p2 += unkown_number;
        unkown_number = 0;
    } else {
        unkown_number = 0;
    }
    return;
}
