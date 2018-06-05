#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "General.h"

void S_transfer()
{

    bool row = false;

    bool col = false;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (S_block[0][j] == true) {
                row = true;
                break;
            }
        }
        if (row == true) {
            break;
        } else if (row == false) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    S_block[i][j] = S_block[i + 1][j];
                }
            }
            for (int k = 0; k < 4; k++) {
                S_block[3][k] = false;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (S_block[j][0] == true) {
                col = true;
                break;
            }
        }
        if (col == true) {
            break;
        } else if (col == false) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    S_block[j][i] = S_block[j][i + 1];
                }
            }
            for (int k = 0; k < 4; k++) {
                S_block[k][3] = false;
            }
        }
    }
}

int S_player(int S_player, int S_iffirst)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            S_block[i][j] = false;
        }
    }

    if (S_player == 1) {
        S_player1 = true;
    } else {
        S_player1 = false;
    }

    S_printf_temporary_map();

    while (1) {
        char order;
        int  PC_1 = 0;
        int  PC_2[2] = {0,0};
        int  PC_3 = 0;
        //   PC_1    -- S_block no.
        //   PC_2[0] -- x
        //   PC_2[1] -- y
        //   PC_3    -- rotate
        bool block_sel = false;
        bool overlapped = false;
        bool Out_Range = false;
        bool Connected_Star = false;
        bool temp[4][4];
        bool pass = true;
        bool AI_Error = true;
        //-----------------Heuristic Parameters//-----------------
        int H_Value = -1;
        int Instr_Value[4] = {0,0,0,0};
        bool H_Finish = false;
        int perimeter = 0;
        int closeness = 0;
        int temp_value = 0;
        //-----------------Heuristic Parameters//-----------------
		int error_count=0;
		while (AI_Error == true){
			overlapped = false;
			Out_Range = false;
			Connected_Star = false;
			AI_Error = false;
			
			if(S_player == 1){
				int remainder_block_number=0;
				for(int i=0;i<9;i++){
					if( S_p1_used_block[i] == false){
						remainder_block_number++;
					}
				}
				int pc1=0;
				pc1=(rand() % remainder_block_number + 1);
				for(int j=0;j<9;j++){
					if( S_p1_used_block[j] == false){
						pc1--;
					}
					if(pc1==0){
						PC_1=j+1;
						break;
					}
				}
				PC_2[0] = (rand() % 13 + 1);
				PC_2[1] = (rand() % 13 + 1);
				PC_3 = (rand() % 4 + 1);
			}
			else{
				int remainder_block_number=0;
				for(int i=0;i<9;i++){
					if( S_p2_used_block[i] == false){
						remainder_block_number++;
					}
				}
				int pc1=0;
				pc1=(rand() % remainder_block_number + 1);
				for(int j=0;j<9;j++){
					if( S_p2_used_block[j] == false){
						pc1--;
					}
					if(pc1==0){
						PC_1=j+1;
						break;
					}
				}
				PC_2[0] = (rand() % 13 + 1);
				PC_2[1] = (rand() % 13 + 1);
				PC_3 = (rand() % 4 + 1);
			}
			/*PC_1 = (rand() % 9 + 1);
			PC_2[0] = (rand() % 13 + 1);
			PC_2[1] = (rand() % 13 + 1);
			PC_3 = (rand() % 4 + 1);*/
			printf("		%d\n",error_count);
			error_count++;
			if(error_count>30000){
				printf("		dont find piont\n");
				scanf("%d", &aaaa);
				return 55;
			}
			
			//--------------Test--------------
			if (PC_1 < 1 || PC_1 > 9) {
				AI_Error = true;
			} else if ((S_player == 1 && S_p1_used_block[PC_1 - 1] == true) || (S_player == 2 && S_p2_used_block[PC_1 - 1] == true)) {
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
						S_using_block = PC_1;
						S_x_of_block = PC_2[0];
						S_y_of_block = PC_2[1];

						switch (PC_1) {
							case 1:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block1[nn][mm];
									}
								}
								break;
							case 2:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block2[nn][mm];
									}
								}
								break;
							case 3:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block3[nn][mm];
									}
								}
								break;
							case 4:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block4[nn][mm];
									}
								}
								break;
							case 5:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block5[nn][mm];
									}
								}
								break;
							case 6:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block6[nn][mm];
									}
								}
								break;
							case 7:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block7[nn][mm];
									}
								}
								break;
							case 8:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block8[nn][mm];
									}
								}
								break;
							case 9:
								for (int nn = 0; nn < 4; nn++) {
									for (int mm = 0; mm < 4; mm++) {
										S_block[nn][mm] = S_block9[nn][mm];
									}
								}
								break;
						}

						for (int i = 1; i < PC_3; i++) {
							for (int nn = 0; nn < 4; nn++) {
								for (int mm = 0; mm < 4; mm++) {
									temp[nn][mm] = S_block[nn][mm];
								}
							}
							S_block[0][0] = temp[3][0];
							S_block[0][1] = temp[2][0];
							S_block[0][2] = temp[1][0];
							S_block[0][3] = temp[0][0];
							S_block[1][0] = temp[3][1];
							S_block[1][1] = temp[2][1];
							S_block[1][2] = temp[1][1];
							S_block[1][3] = temp[0][1];
							S_block[2][0] = temp[3][2];
							S_block[2][1] = temp[2][2];
							S_block[2][2] = temp[1][2];
							S_block[2][3] = temp[0][2];
							S_block[3][0] = temp[3][3];
							S_block[3][1] = temp[2][3];
							S_block[3][2] = temp[1][3];
							S_block[3][3] = temp[0][3];
						}

						S_transfer();

						for (int ii = 0; ii < 4; ii++) {
							for (int jj = 0; jj < 4; jj++) {
								if (S_block[ii][jj] == true) {
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
								if (S_block[ii][jj]) {
									if (S_Map[PC_2[0] + ii][PC_2[1] + jj] == '*') {
										Connected_Star = true;
									} else {
										if(S_player==1){
											if (S_Map[PC_2[0] + ii + 1][PC_2[1] + jj] == 'O' || S_Map[PC_2[0] + ii - 1][PC_2[1] + jj] == 'O' ||
											S_Map[PC_2[0] + ii ][PC_2[1] + jj + 1] == 'O' || S_Map[PC_2[0] + ii ][PC_2[1] + jj - 1] == 'O') {
												Connected_Star = true;
											}
										}
										else{
											if (S_Map[PC_2[0] + ii + 1][PC_2[1] + jj] == 'X' || S_Map[PC_2[0] + ii - 1][PC_2[1] + jj] == 'X' ||
											S_Map[PC_2[0] + ii ][PC_2[1] + jj + 1] == 'X' || S_Map[PC_2[0] + ii ][PC_2[1] + jj - 1] == 'X') {
												Connected_Star = true;
											}
										}
									}
								}
							}
						}

						for (int ii = 0; ii < 4; ii++) {
							for (int jj = 0; jj < 4; jj++) {
								if (S_block[ii][jj]) {
									if (S_Map[PC_2[0] + ii][PC_2[1] + jj] == 'O' || S_Map[PC_2[0] + ii][PC_2[1] + jj] == 'X') {
										overlapped = true;
										break;
									}
								}
							}
						}

						if (Out_Range) {
							for (int nn = 0; nn < 4; nn++) {
								for (int mm = 0; mm < 4; mm++) {
									S_block[nn][mm] = false;
								}
							}
							AI_Error = true;
						} else if (!Connected_Star) {
							for (int nn = 0; nn < 4; nn++) {
								for (int mm = 0; mm < 4; mm++) {
									S_block[nn][mm] = false;
								}
							}
							AI_Error = true;
						} else if (overlapped) {
							for (int nn = 0; nn < 4; nn++) {
								for (int mm = 0; mm < 4; mm++) {
									S_block[nn][mm] = false;
								}
							}
							AI_Error = true;
						}
					}
				}
			}
		}
		error_count=0;
		

   

		switch (S_using_block) {
			case 1:
				if(S_player == 1){
					S_p1_used_block[0] = true;
				}
				else{
					S_p2_used_block[0] = true;
				}
				break;
			case 2:
				if(S_player == 1){
					S_p1_used_block[1] = true;
				}
				else{
					S_p2_used_block[1] = true;
				}
				break;
			case 3:
				if(S_player == 1){
					S_p1_used_block[2] = true;
				}
				else{
					S_p2_used_block[2] = true;
				}
				break;
			case 4:
				if(S_player == 1){
					S_p1_used_block[3] = true;
				}
				else{
					S_p2_used_block[3] = true;
				}
				break;
			case 5:
				if(S_player == 1){
					S_p1_used_block[4] = true;
				}
				else{
					S_p2_used_block[4] = true;
				}
				break;
			case 6:
				if(S_player == 1){
					S_p1_used_block[5] = true;
				}
				else{
					S_p2_used_block[5] = true;
				}
				break;
			case 7:
				if(S_player == 1){
					S_p1_used_block[6] = true;
				}
				else{
					S_p2_used_block[6] = true;
				}
				break;
			case 8:
				if(S_player == 1){
					S_p1_used_block[7] = true;
				}
				else{
					S_p2_used_block[7] = true;
				}
				break;
			case 9:
				if(S_player == 1){
					S_p1_used_block[8] = true;
				}
				else{
					S_p2_used_block[8] = true;
				}
				break;
		}

		S_printf_temporary_map();
		for (int i = 1; i < 14; i++) {
			for (int j = 1; j < 14; j++) {
				S_Map[i][j] = S_temporary_map[i][j];
			}
		}
		if(S_iffirst==1){
			S_expansion_block[0]=PC_1;
			S_expansion_block[1]=PC_2[0];
			S_expansion_block[2]=PC_2[1];
			S_expansion_block[3]=PC_3;
		}
		
		return 100;
	}
}
