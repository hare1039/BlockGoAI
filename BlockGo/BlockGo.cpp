#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "General.h"
#include <string>

using namespace std;

int aaaa;

allblock blocklife1[30];
allblock blocklife2[30];

char temporary_map[15][15];
char Map[15][15];
bool block[4][4];
int x_of_block = 1;
int y_of_block = 1;

bool block1[4][4] = { { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false } };
bool block2[4][4] = { { true, false, false, false }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false } };
bool block3[4][4] = { { true, false, false, false }, { true, true, false, false }, { true, false, false, false }, { false, false, false, false } };
bool block4[4][4] = { { true, true, false, false }, { false, true, true, false }, { false, false, false, false }, { false, false, false, false } };
bool block5[4][4] = { { false, true, true, false }, { true, true, false, false }, { false, false, false, false }, { false, false, false, false } };
bool block6[4][4] = { { true, false, false, false }, { true, true, true, false }, { false, false, false, false }, { false, false, false, false } };
bool block7[4][4] = { { false, false, true, false }, { true, true, true, false }, { false, false, false, false }, { false, false, false, false } };
bool block8[4][4] = { { true, true, true, true }, { false, false, false, false }, { false, false, false, false }, { false, false, false, false } };
bool block9[4][4] = { { true, true, false, false }, { true, true, false, false }, { false, false, false, false }, { false, false, false, false } };

bool player1;

bool p1_used_block[9] = { false, false, false, false, false, false, false, false, false };
bool p2_used_block[9] = { false, false, false, false, false, false, false, false, false };

int using_block = 0;

int final_map[15][15];
int unkown_number = 0;
int search_array[600];
int search_array_number = 0;
int number_of_p1 = 0;
int number_of_p2 = 0;

int final_map1[15][15];
int final_map2[15][15];

int block_begin1 = 0;
int block_end1 = 0;

int block_begin2 = 0;
int block_end2 = 0;

bool boundary[48];
int boundary_number = 0;

int live_or_dead_map[15][15];

int file_Array1[36];
int file_Array2[36];
int block_count1 = 0;
int block_count2 = 0;
int block_change1 = 0;

bool webmode = false;

struct allblock S_blocklife1[30];
struct allblock S_blocklife2[30];

char S_temporary_map[15][15];
char S_Map[15][15];
bool S_block[4][4];
int S_x_of_block;
int S_y_of_block;

bool S_block1[4][4];
bool S_block2[4][4];
bool S_block3[4][4];
bool S_block4[4][4];
bool S_block5[4][4];
bool S_block6[4][4];
bool S_block7[4][4];
bool S_block8[4][4];
bool S_block9[4][4];

bool S_player1;

bool S_p1_used_block[9];
bool S_p2_used_block[9];

int S_using_block;

int S_final_map[15][15];
int S_unkown_number;
int S_search_array[600];
int S_search_array_number;
int S_number_of_p1;
int S_number_of_p2;

int S_final_map1[15][15];
int S_final_map2[15][15];

int S_block_begin1;
int S_block_end1;

int S_block_begin2;
int S_block_end2;

bool S_boundary[48];
int S_boundary_number;

int S_live_or_dead_map[15][15];

int S_file_Array1[36];
int S_file_Array2[36];
int S_block_count1;
int S_block_count2;
int S_block_change1;

int S_expansion_block[4];

struct block_node* reg_node;

int main(int argc, char* argv[])
{
    if (argc >= 2 && std::string(argv[1]) == "web") {
        webmode = true;
    }

    block_node n;
    reg_node = &n;

    //-----------------------------Intro_MapDisplay-----------------------------
    initialize_block();
    initialize_map();
    introduction();
    //-----------------------------Intro_MapDisplay-----------------------------

    int choice;
    int Algorithm;
    for (int k = 0; k < 9; k++) {
        printf("\nDo you want to let whom play this bout P1\n");
        printf("1. Player\n");
        printf("2. AI\n");
        printf("Please Select Play Mode：");
        // scanf("%d", &choice);
        {
            char c = std::fgetc(stdin);
            choice = c - '0';
        }
        printf("\n");

        while (choice < 1 || choice > 2) {
            printf("Please select available play mode!\n");
            printf("Please Select Player：");
            //            scanf("%d", &choice);
            char c = std::fgetc(stdin);
            choice = c - '0';
            printf("\n");
        }

        // reset map (x, y) to (1, 1)
        x_of_block = 1;
        y_of_block = 1;

        if (choice == 1) {
            player(1, 0, 2, k + 1);
        } else if (choice == 2) {
            player(1, 2, 0, k + 1);
        }

        printf("\nDo you want to let whom play this bout P2\n");
        printf("1. Player\n");
        printf("2. AI\n");
        printf("Please Select Player：");
        // scanf("%d", &choice);
        {
            char c = std::fgetc(stdin);
            choice = c - '0';
        }
        printf("\n");

        while (choice < 1 || choice > 2) {
            printf("Please select available play mode!\n");
            printf("Please Select Play Mode：");
            // scanf("%d", &choice);
            char c = std::fgetc(stdin);
            choice = c - '0';
            printf("\n");
        }

        // reset map (x, y) to (1, 1)
        x_of_block = 1;
        y_of_block = 1;

        if (choice == 1) {
            if (not webmode) {
                system("clear");
            }
            player(0, 0, 2, k + 1);
        } else if (choice == 2) {
            if (not webmode) {
                system("clear");
            }
            player(0, 2, 0, k + 1);
        }
    }

    //-----------------------------Cal_Result-----------------------------

    int p1num = 0;
    int p2num = 0;
    //new begin
    for (int aaa = 0; aaa < 48; aaa++) {
        boundary[aaa] = false;
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (Map[i][j] == '-') {
                final_map1[i][j] = 2;
                final_map2[i][j] = 2;
            } else if (Map[i][j] == 'O') {
                final_map1[i][j] = 0;
                final_map2[i][j] = 3;
                p1num++;
            } else if (Map[i][j] == 'X') {
                final_map1[i][j] = 3;
                final_map2[i][j] = 0;
                p2num++;
            } else {
                final_map1[i][j] = 3;
                final_map2[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (final_map1[i][j] == 0) {

                search_block1(i, j);

                if (decide_if_live() || decide_if_2_1(1)) {
                    for (int aa = block_begin1; aa < block_end1; aa++) {
                        blocklife1[aa].if_live = true;
                    }
                } else {
                    for (int aa = block_begin1; aa < block_end1; aa++) {
                        blocklife1[aa].if_live = false;
                    }
                }
                block_begin1 = block_end1;
                for (int aaa = 0; aaa < 48; aaa++) {
                    boundary[aaa] = false;
                }
                boundary_number = 0;
            }
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (final_map2[i][j] == 0) {
                search_block2(i, j);

                if (decide_if_live() || decide_if_2_1(2)) {
                    for (int aa = block_begin2; aa < block_end2; aa++) {
                        blocklife2[aa].if_live = true;
                    }
                } else {
                    for (int aa = block_begin2; aa < block_end2; aa++) {
                        blocklife2[aa].if_live = false;
                    }
                }
                block_begin2 = block_end2;
                for (int aaa = 0; aaa < 48; aaa++) {
                    boundary[aaa] = false;
                }
                boundary_number = 0;
            }
        }
    }
    for (int aaa = 0; aaa < 30; aaa++) {
        if (blocklife1[aaa].if_live == false) {
            Map[blocklife1[aaa].x][blocklife1[aaa].y] = '+';
        }
        if (blocklife2[aaa].if_live == false) {
            Map[blocklife2[aaa].x][blocklife2[aaa].y] = '+';
        }
    }
    printf(" ");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            printf(" %c ", Map[i][j]);
        }
        printf(" \n ");
    }
    //new end
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (Map[i][j] == '-') {
                final_map[i][j] = 2;
            } else if (Map[i][j] == 'O') {
                final_map[i][j] = 3;
            } else if (Map[i][j] == 'X') {
                final_map[i][j] = 4;
            } else {
                final_map[i][j] = 0;
            }
        }
    }
    printf(" ");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            printf(" %d ", final_map[i][j]);
        }
        printf(" \n ");
    }

    for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            if (final_map[i][j] == 0) {

                search_number(i, j);

                decide_whose_number();

                clear_search_array();
            }
        }
    }

    printf("territory of p1: %d\n", number_of_p1);
    printf("territory of p2: %d\n", number_of_p2);
    if (webmode) {
        std::fprintf(stderr,
            "{\"winner\": {\"player\": %d, \"result\": {\"p1\": %d, \"p2\": %d}}}\n",
            (number_of_p1 > number_of_p2) ? 1 : 2, number_of_p1, number_of_p2);
        std::fflush(stderr);
    }

    int winner = 0;
    if (number_of_p1 > number_of_p2) {
        FILE* fp;
        fp = fopen("history.txt", "a");
        for (int i = 0; i < 35; i++) {
            fprintf(fp, "%d ", file_Array1[i]);
        }
        fprintf(fp, "%d\n", file_Array1[35]);

        for (int i = 0; i < 35; i++) {
            fprintf(fp, "%d ", file_Array2[i]);
        }
        fprintf(fp, "%d\n", file_Array2[35]);
        fclose(fp);
        printf("P1 win\n");
        winner = 1;
    } else if (number_of_p1 < number_of_p2) {
        FILE* fp;
        fp = fopen("history.txt", "a");
        for (int i = 0; i < 35; i++) {
            fprintf(fp, "%d ", file_Array2[i]);
        }
        fprintf(fp, "%d\n", file_Array2[35]);

        for (int i = 0; i < 35; i++) {
            fprintf(fp, "%d ", file_Array1[i]);
        }
        fprintf(fp, "%d\n", file_Array1[35]);
        fclose(fp);
        printf("P2 win\n");
        winner = 2;
    } else {
        printf("DRAW");
        winner = 0;
    }

    return 0;
}
