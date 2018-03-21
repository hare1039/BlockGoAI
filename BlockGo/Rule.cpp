#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "General.h"

void transfer()
{

    bool row = false;

    bool col = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block[0][j] == true) {
                row = true;
                break;
            }
        }
        if (row == true) {
            break;
        } else if (row == false) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    block[i][j] = block[i + 1][j];
                }
            }
            for (int k = 0; k < 4; k++) {
                block[3][k] = false;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (block[j][0] == true) {
                col = true;
                break;
            }
        }
        if (col == true) {
            break;
        } else if (col == false) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    block[j][i] = block[j][i + 1];
                }
            }
            for (int k = 0; k < 4; k++) {
                block[k][3] = false;
            }
        }
    }
}

void player(int player, int choice)
{

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            block[i][j] = false;
        }
    }

    if (player == 1) {
        player1 = true;
    } else {
        player1 = false;
    }

    printf_temporary_map();

    while (1) {
        char order;
        int PC_1;
        int PC_2[1];
        int PC_3;
        bool block_sel = false;
        bool overlapped = false;
        bool Out_Range = false;
        bool Connected_Star = false;
        bool temp[4][4];
        bool pass = true;
        bool AI_Error = true;

        if (choice == 0) {
            scanf("%c", &order);

            if (order == 'w') {
                x_of_block -= 1;
                for (int ii = 0; ii < 4; ii++) {
                    for (int jj = 0; jj < 4; jj++) {
                        if (block[ii][jj]) {
                            if (x_of_block + ii == 0) {
                                Out_Range = true;
                                x_of_block += 1;
                                break;
                            }
                        }
                    }
                    if (Out_Range)
                        break;
                }
                printf_temporary_map();
                if (Out_Range) {
                    printf("\nThe Area is out of Range!\n");
                }
            } else if (order == 's') {
                x_of_block += 1;
                for (int ii = 0; ii < 4; ii++) {
                    for (int jj = 0; jj < 4; jj++) {
                        if (block[ii][jj]) {
                            if (x_of_block + ii == 14) {
                                Out_Range = true;
                                x_of_block -= 1;
                                break;
                            }
                        }
                    }
                    if (Out_Range)
                        break;
                }
                printf_temporary_map();
                if (Out_Range) {
                    printf("\nThe Area is out of Range!\n");
                }
            } else if (order == 'a') {
                y_of_block -= 1;
                for (int ii = 0; ii < 4; ii++) {
                    for (int jj = 0; jj < 4; jj++) {
                        if (block[ii][jj]) {
                            if (y_of_block + jj == 0) {
                                Out_Range = true;
                                y_of_block += 1;
                                break;
                            }
                        }
                    }
                    if (Out_Range)
                        break;
                }
                printf_temporary_map();
                if (Out_Range) {
                    printf("\nThe Area is out of Range!\n");
                }
            } else if (order == 'd') {
                y_of_block += 1;
                for (int ii = 0; ii < 4; ii++) {
                    for (int jj = 0; jj < 4; jj++) {
                        if (block[ii][jj]) {
                            if (y_of_block + jj == 14) {
                                Out_Range = true;
                                y_of_block -= 1;
                                break;
                            }
                        }
                    }
                    if (Out_Range)
                        break;
                }
                printf_temporary_map();
                if (Out_Range) {
                    printf("\nThe Area is out of Range!\n");
                }
            } else if (order == '1') {
                if ((player == 1 && !p1_used_block[0]) || (player == 0 && !p2_used_block[0])) {
                    using_block = 1;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block1[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '2') {
                if ((player == 1 && !p1_used_block[1]) || (player == 0 && !p2_used_block[1])) {
                    using_block = 2;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block2[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '3') {
                if ((player == 1 && !p1_used_block[2]) || (player == 0 && !p2_used_block[2])) {
                    using_block = 3;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block3[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '4') {
                if ((player == 1 && !p1_used_block[3]) || (player == 0 && !p2_used_block[3])) {
                    using_block = 4;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block4[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '5') {
                if ((player == 1 && !p1_used_block[4]) || (player == 0 && !p2_used_block[4])) {
                    using_block = 5;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block5[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '6') {
                if ((player == 1 && !p1_used_block[5]) || (player == 0 && !p2_used_block[5])) {
                    using_block = 6;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block6[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '7') {
                if ((player == 1 && !p1_used_block[6]) || (player == 0 && !p2_used_block[6])) {
                    using_block = 7;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block7[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '8') {
                if ((player == 1 && !p1_used_block[7]) || (player == 0 && !p2_used_block[7])) {
                    using_block = 8;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block8[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == '9') {
                if ((player == 1 && !p1_used_block[8]) || (player == 0 && !p2_used_block[8])) {
                    using_block = 9;
                    for (int nn = 0; nn < 4; nn++) {
                        for (int mm = 0; mm < 4; mm++) {
                            block[nn][mm] = block9[nn][mm];
                        }
                    }
                    printf_temporary_map();
                } else {
                    printf_temporary_map();
                    printf("\nThe Block has been used!\n");
                }
            }

            else if (order == 'c') {
                for (int nn = 0; nn < 4; nn++) {
                    for (int mm = 0; mm < 4; mm++) {
                        temp[nn][mm] = block[nn][mm];
                    }
                }
                block[0][0] = temp[3][0];
                block[0][1] = temp[2][0];
                block[0][2] = temp[1][0];
                block[0][3] = temp[0][0];
                block[1][0] = temp[3][1];
                block[1][1] = temp[2][1];
                block[1][2] = temp[1][1];
                block[1][3] = temp[0][1];
                block[2][0] = temp[3][2];
                block[2][1] = temp[2][2];
                block[2][2] = temp[1][2];
                block[2][3] = temp[0][2];
                block[3][0] = temp[3][3];
                block[3][1] = temp[2][3];
                block[3][2] = temp[1][3];
                block[3][3] = temp[0][3];
				block_change1+=1;

                for (int ii = 0; ii < 4; ii++) {
                    for (int jj = 0; jj < 4; jj++) {
                        if (block[ii][jj]) {
                            if (x_of_block + ii < 1 || x_of_block + ii > 13) {
                                Out_Range = true;
                                break;
                            } else if (y_of_block + jj < 1 || y_of_block + jj > 13) {
                                Out_Range = true;
                                break;
                            }
                        }
                    }
                    if (Out_Range)
                        break;
                }

                if (Out_Range) {
                    block[0][0] = temp[0][0];
                    block[0][1] = temp[0][1];
                    block[0][2] = temp[0][2];
                    block[0][3] = temp[0][3];
                    block[1][0] = temp[1][0];
                    block[1][1] = temp[1][1];
                    block[1][2] = temp[1][2];
                    block[1][3] = temp[1][3];
                    block[2][0] = temp[2][0];
                    block[2][1] = temp[2][2];
                    block[2][2] = temp[2][2];
                    block[2][3] = temp[2][3];
                    block[3][0] = temp[3][0];
                    block[3][1] = temp[3][1];
                    block[3][2] = temp[3][2];
                    block[3][3] = temp[3][3];
                    block_change1-=1;
                }
                printf_temporary_map();
                if (Out_Range) {
                    printf("\nThe Area is out of Range!\n");
                }
            }

            else if (order == 'y') {
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        if (block[i][j]) {
                            block_sel = true;
                        }
                    }
                }

                if (block_sel) {
                    for (int ii = 0; ii < 4; ii++) {
                        for (int jj = 0; jj < 4; jj++) {
                            if (block[ii][jj]) {
                                if (Map[x_of_block + ii][y_of_block + jj] == '*') {
                                    Connected_Star = true;
                                } else if (player) {
                                    if (Map[x_of_block + ii + 1][y_of_block + jj] == 'O' || Map[x_of_block + ii - 1][y_of_block + jj] == 'O' ||
                                        Map[x_of_block + ii ][y_of_block + jj + 1] == 'O' || Map[x_of_block + ii ][y_of_block + jj - 1] == 'O') {
                                        Connected_Star = true;
                                    }
                                } else if(!player){
                                    if (Map[x_of_block + ii + 1][y_of_block + jj] == 'X' || Map[x_of_block + ii - 1][y_of_block + jj] == 'X' ||
                                        Map[x_of_block + ii ][y_of_block + jj + 1] == 'X' || Map[x_of_block + ii ][y_of_block + jj - 1] == 'X') {
                                        Connected_Star = true;
                                    }
                                }
                            }
                        }
                    }

                    if (Connected_Star) {
                        for (int ii = 0; ii < 4; ii++) {
                            for (int jj = 0; jj < 4; jj++) {
                                if (block[ii][jj]) {
                                    if (Map[x_of_block + ii][y_of_block + jj] == 'O' || Map[x_of_block + ii][y_of_block + jj] == 'X') {
                                        overlapped = true;
                                        break;
                                    }
                                }
                            }
                            if (overlapped)
                                break;
                        }

                        if (overlapped) {
                            printf_temporary_map();
                            printf("\nPlease Select other places for the chosen block! The Area is overlapped!\n");
                        }

                        else {
                            if(player == 1){
                                if (using_block == 1) {
                                    p1_used_block[0] = true;
                                } else if (using_block == 2) {
                                    p1_used_block[1] = true;
                                } else if (using_block == 3) {
                                    p1_used_block[2] = true;
                                } else if (using_block == 4) {
                                    p1_used_block[3] = true;
                                } else if (using_block == 5) {
                                    p1_used_block[4] = true;
                                } else if (using_block == 6) {
                                    p1_used_block[5] = true;
                                } else if (using_block == 7) {
                                    p1_used_block[6] = true;
                                } else if (using_block == 8) {
                                    p1_used_block[7] = true;
                                } else if (using_block == 9) {
                                    p1_used_block[8] = true;
                                }
                            }
                            else{
                                if (using_block == 1) {
                                    p2_used_block[0] = true;
                                } else if (using_block == 2) {
                                    p2_used_block[1] = true;
                                } else if (using_block == 3) {
                                    p2_used_block[2] = true;
                                } else if (using_block == 4) {
                                    p2_used_block[3] = true;
                                } else if (using_block == 5) {
                                    p2_used_block[4] = true;
                                } else if (using_block == 6) {
                                    p2_used_block[5] = true;
                                } else if (using_block == 7) {
                                    p2_used_block[6] = true;
                                } else if (using_block == 8) {
                                    p2_used_block[7] = true;
                                } else if (using_block == 9) {
                                    p2_used_block[8] = true;
                                }
                            }

                            printf_temporary_map();
                            for (int i = 1; i < 14; i++) {
                                for (int j = 1; j < 14; j++) {
                                    Map[i][j] = temporary_map[i][j];
                                }
                            }
                            int direct1=(block_change1%4);
                            file_Array1[block_count1]=x_of_block;
                            file_Array1[block_count1+1]=y_of_block;
                            file_Array1[block_count1+2]=using_block;
                            file_Array1[block_count1+3]=direct1;
                            block_count1+=4;
                            block_change1=0;
                            return;
                        }
                    } else {
                        printf_temporary_map();
                        printf("\nPlease Select other places for the chosen block! The Selection is invalid!\n");
                    }

                }

                else if (!block_sel) {
                    printf_temporary_map();
                    x_of_block = 1;
                    y_of_block = 1;
                    printf("\nPlease Select one kind of Block(Input 1~9!!)\n");
                }

            }

            else {
                if (!block_sel) {
                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            if (block[i][j]) {
                                block_sel = true;
                            }
                        }
                    }
                    if (!block_sel) {
                        printf_temporary_map();
                        x_of_block = 1;
                        y_of_block = 1;
                        printf("\nPlease Select one kind of Block(Input 1~9!!)\n");
                    }
                } else {
                    printf("\nPlease Input Correct Instruction!\n");
                }
            }

        }

        //----------------------------------Player2---------------------------------------//

        else if (choice == 1) {

            while (AI_Error == true) {
                overlapped = false;
                Out_Range = false;
                Connected_Star = false;
                AI_Error = false;
                PC_1 = (rand() % 9 + 1);
                PC_2[0] = (rand() % 13 + 1);
                PC_2[1] = (rand() % 13 + 1);
                PC_3 = (rand() % 4 + 1);
                if (PC_1 < 1 || PC_1 > 9) {
                    AI_Error = true;
                } else if ((player == 1 && p1_used_block[PC_1 - 1] == true) || (player == 0 && p2_used_block[PC_1 - 1] == true)) {
                    AI_Error = true;
                } else {
                    if ((PC_2[0] < 1 || PC_2[0] > 13) || (PC_2[1] < 1 || PC_2[1] > 13)) {
                        AI_Error = true;
                    } else if ((PC_2[0] > 0 && PC_2[0] < 14) && (PC_2[1] > 0 && PC_2[1] < 14)) {
                        if (PC_3 < 1 || PC_3 > 4) {
                            AI_Error = true;
                            pass = false;
                        }

                        else {
                            using_block = PC_1;
                            x_of_block = PC_2[0];
                            y_of_block = PC_2[1];

                            switch (PC_1) {
                                case 1:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block1[nn][mm];
                                        }
                                    }
                                    break;
                                case 2:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block2[nn][mm];
                                        }
                                    }
                                    break;
                                case 3:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block3[nn][mm];
                                        }
                                    }
                                    break;
                                case 4:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block4[nn][mm];
                                        }
                                    }
                                    break;
                                case 5:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block5[nn][mm];
                                        }
                                    }
                                    break;
                                case 6:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block6[nn][mm];
                                        }
                                    }
                                    break;
                                case 7:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block7[nn][mm];
                                        }
                                    }
                                    break;
                                case 8:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block8[nn][mm];
                                        }
                                    }
                                    break;
                                case 9:
                                    for (int nn = 0; nn < 4; nn++) {
                                        for (int mm = 0; mm < 4; mm++) {
                                            block[nn][mm] = block9[nn][mm];
                                        }
                                    }
                                    break;
                            }

                            for (int i = 1; i < PC_3; i++) {
                                for (int nn = 0; nn < 4; nn++) {
                                    for (int mm = 0; mm < 4; mm++) {
                                        temp[nn][mm] = block[nn][mm];
                                    }
                                }
                                block[0][0] = temp[3][0];
                                block[0][1] = temp[2][0];
                                block[0][2] = temp[1][0];
                                block[0][3] = temp[0][0];
                                block[1][0] = temp[3][1];
                                block[1][1] = temp[2][1];
                                block[1][2] = temp[1][1];
                                block[1][3] = temp[0][1];
                                block[2][0] = temp[3][2];
                                block[2][1] = temp[2][2];
                                block[2][2] = temp[1][2];
                                block[2][3] = temp[0][2];
                                block[3][0] = temp[3][3];
                                block[3][1] = temp[2][3];
                                block[3][2] = temp[1][3];
                                block[3][3] = temp[0][3];
                            }

                            transfer();

                            for (int ii = 0; ii < 4; ii++) {
                                for (int jj = 0; jj < 4; jj++) {
                                    if (block[ii][jj] == true) {
                                        PC_2[0] = PC_2[0] + ii;
                                        PC_2[1] = PC_2[1] + jj;
                                        if ((PC_2[0] < 1 || PC_2[0] > 13) || (PC_2[1] < 1 || PC_2[1] > 13)) {
                                            Out_Range = true;
                                            PC_2[0] = PC_2[0] - ii;
                                            PC_2[1] = PC_2[1] - jj;
                                            break;
                                        }
                                        PC_2[0] = PC_2[0] - ii;
                                        PC_2[1] = PC_2[1] - jj;
                                    }
                                }
                                if (Out_Range)
                                    break;
                            }

                            for (int ii = 0; ii < 4; ii++) {
                                for (int jj = 0; jj < 4; jj++) {
                                    if (block[ii][jj]) {
                                        if (Map[PC_2[0] + ii][PC_2[1] + jj] == '*') {
                                            Connected_Star = true;
                                        } else {
                                            if(player){
                                                if (Map[PC_2[0] + ii + 1][PC_2[1] + jj] == 'O' || Map[PC_2[0] + ii - 1][PC_2[1] + jj] == 'O' ||
                                                Map[PC_2[0] + ii ][PC_2[1] + jj + 1] == 'O' || Map[PC_2[0] + ii ][PC_2[1] + jj - 1] == 'O') {
                                                    Connected_Star = true;
                                                }
                                            }
                                            else{
                                                if (Map[PC_2[0] + ii + 1][PC_2[1] + jj] == 'X' || Map[PC_2[0] + ii - 1][PC_2[1] + jj] == 'X' ||
                                                Map[PC_2[0] + ii ][PC_2[1] + jj + 1] == 'X' || Map[PC_2[0] + ii ][PC_2[1] + jj - 1] == 'X') {
                                                    Connected_Star = true;
                                                }
                                            }
                                        }
                                    }
                                }
                            }

                            for (int ii = 0; ii < 4; ii++) {
                                for (int jj = 0; jj < 4; jj++) {
                                    if (block[ii][jj]) {
                                        if (Map[PC_2[0] + ii][PC_2[1] + jj] == 'O' || Map[PC_2[0] + ii][PC_2[1] + jj] == 'X') {
                                            overlapped = true;
                                            break;
                                        }
                                    }
                                }
                            }

                            if (Out_Range) {
                                for (int nn = 0; nn < 4; nn++) {
                                    for (int mm = 0; mm < 4; mm++) {
                                        block[nn][mm] = false;
                                    }
                                }
                                AI_Error = true;
                            } else if (!Connected_Star) {
                                for (int nn = 0; nn < 4; nn++) {
                                    for (int mm = 0; mm < 4; mm++) {
                                        block[nn][mm] = false;
                                    }
                                }
                                AI_Error = true;
                            } else if (overlapped) {
                                for (int nn = 0; nn < 4; nn++) {
                                    for (int mm = 0; mm < 4; mm++) {
                                        block[nn][mm] = false;
                                    }
                                }
                                AI_Error = true;
                            }
                        }
                    }
                }
            }

            switch (using_block) {
                case 1:
                    if(player == 1){
                        p1_used_block[0] = true;
                    }
                    else{
                        p2_used_block[0] = true;
                    }
                    break;
                case 2:
                    if(player == 1){
                        p1_used_block[1] = true;
                    }
                    else{
                        p2_used_block[1] = true;
                    }
                    break;
                case 3:
                    if(player == 1){
                        p1_used_block[2] = true;
                    }
                    else{
                        p2_used_block[2] = true;
                    }
                    break;
                case 4:
                    if(player == 1){
                        p1_used_block[3] = true;
                    }
                    else{
                        p2_used_block[3] = true;
                    }
                    break;
                case 5:
                    if(player == 1){
                        p1_used_block[4] = true;
                    }
                    else{
                        p2_used_block[4] = true;
                    }
                    break;
                case 6:
                    if(player == 1){
                        p1_used_block[5] = true;
                    }
                    else{
                        p2_used_block[5] = true;
                    }
                    break;
                case 7:
                    if(player == 1){
                        p1_used_block[6] = true;
                    }
                    else{
                        p2_used_block[6] = true;
                    }
                    break;
                case 8:
                    if(player == 1){
                        p1_used_block[7] = true;
                    }
                    else{
                        p2_used_block[7] = true;
                    }
                    break;
                case 9:
                    if(player == 1){
                        p1_used_block[8] = true;
                    }
                    else{
                        p2_used_block[8] = true;
                    }
                    break;
            }
            printf_temporary_map();
            for (int i = 1; i < 14; i++) {
                for (int j = 1; j < 14; j++) {
                    Map[i][j] = temporary_map[i][j];
                }
            }
            file_Array2[block_count2]=PC_2[0];
            file_Array2[block_count2+1]=PC_2[1];
            file_Array2[block_count2+2]=PC_1;
            file_Array2[block_count2+3]=PC_3-1;
            block_count2+=4;


            return;
        }
    }
}
