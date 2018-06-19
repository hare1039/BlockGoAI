#include "General.h"
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

int Heuristic_Function(int PC_1, int &Length, int &Connectivity, int &Connect_Point, bool &S_Connected_p1, bool &S_Connected_p2, int &Boundary, int &Up, int &Down, int &Left, int &Right, int &Connected_Value, int &S_Domain_Boun_p1, int &S_Domain_Boun_p2, int &Self_Domain, int &Attack, int &step){

  int Heuristic_Value = 0;
  int Star = 0;
  int Bad_Boun = 0;
  bool Connected_1 = false;
  bool Connected_2 = false;
  bool Connected_3 = false;
  bool Connected_4 = false;
  Length = 0;
  Connect_Point = 0;
  Connectivity = 0;//connected points
  Boundary = 0;//closeness to boundary
  Up = 13;
  Down = 0;
  Left = 13;
  Right = 0;
  Connected_Value = 0;
  Attack = 0;
  Self_Domain = 0;


//------------------------------------------------------------------Initialized Simulated Map------------------------------------------------------------------//
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
              }
              else {
                  S_temporary_map[S_x_of_block + ii][S_y_of_block + jj] = 'X';
              }
              if(((S_x_of_block + ii) == 4 || (S_x_of_block + ii) == 10) && ((S_y_of_block + jj) == 4 || (S_y_of_block + jj) == 10)){
                Star = 1;
              }
              if(((S_x_of_block + ii) == 1 || (S_x_of_block + ii) == 13) || ((S_y_of_block + jj) == 1 || (S_y_of_block + jj) == 13)){
                Bad_Boun = Bad_Boun + 1;
              }
          }
      }
  }
//------------------------------------------------------------------Initialized Simulated Map------------------------------------------------------------------//

//-----------------------------------------------------------------Length-----------------------------------------------------------------
  if(PC_1 < 3){
    Length = 1;
  }
  else if(PC_1 == 8){
    Length = 4;
  }
  else{
    Length = 3;
  }
//-----------------------------------------------------------------Length-----------------------------------------------------------------


//--------------------------------------------------------------Connectivity--------------------------------------------------------------
  for (int k = 0; k < 4; k++) {
      for (int l = 0; l < 4; l++) {
        if(S_block[k][l]){
          if(S_player1){
                if(S_temporary_map[S_x_of_block + k + 1][S_y_of_block + l] == 'O'){
                  Connect_Point = Connect_Point + 1;
                }
                if(S_temporary_map[S_x_of_block + k - 1][S_y_of_block + l] == 'O'){
                  Connect_Point = Connect_Point + 1;
                }
                if(S_temporary_map[S_x_of_block + k][S_y_of_block + l + 1] == 'O'){
                  Connect_Point = Connect_Point + 1;
                }
                if(S_temporary_map[S_x_of_block + k][S_y_of_block + l - 1] == 'O'){
                  Connect_Point = Connect_Point + 1;
                }

                switch (Connect_Point) {
                  case 0:
                    Connectivity = Connectivity;
                  case 1:
                    Connectivity = Connectivity + 3;
                    break;
                  case 2:
                    Connectivity = Connectivity + 5;
                    break;
                  case 3:
                    Connectivity = Connectivity - 5;
                    break;
                  case 4:
                    Connectivity = Connectivity - 7;
                    break;
                }
                Connect_Point = 0;
          }
          else {
              if(S_temporary_map[S_x_of_block + k + 1][S_y_of_block + l] == 'X'){
                Connect_Point = Connect_Point + 1;
              }
              if(S_temporary_map[S_x_of_block + k - 1][S_y_of_block + l] == 'X'){
                Connect_Point = Connect_Point + 1;
              }
              if(S_temporary_map[S_x_of_block + k][S_y_of_block + l + 1] == 'X'){
                Connect_Point = Connect_Point + 1;
              }
              if(S_temporary_map[S_x_of_block + k][S_y_of_block + l - 1] == 'X'){
                Connect_Point = Connect_Point + 1;
              }

              switch (Connect_Point) {
                case 0:
                  Connectivity = Connectivity;
                case 1:
                  Connectivity = Connectivity + 3;
                  break;
                case 2:
                  Connectivity = Connectivity + 5;
                  break;
                case 3:
                  Connectivity = Connectivity - 5;
                  break;
                case 4:
                  Connectivity = Connectivity - 7;
                  break;
              }
              Connect_Point = 0;
        }
      }
    }
  }

  if( (S_Connected_p1 == false && S_player1 == 1) || (S_Connected_p2 == false && S_player1 == 0)){
    for(int i = 0; i<4; i++){
      for(int j = 0; j<4; j++){
        if (S_block[i][j]) {
          if(S_player1){
            if(S_connected_map[S_x_of_block + i + 1][S_y_of_block + j] == 1 || S_connected_map[S_x_of_block + i][S_y_of_block + j+1] == 1 || S_connected_map[S_x_of_block + i -1][S_y_of_block + j] == 1 || S_connected_map[S_x_of_block + i][S_y_of_block + j-1] == 1){
              Connected_1 = true;
            }
            if(S_connected_map[S_x_of_block + i + 1][S_y_of_block + j] == 2 || S_connected_map[S_x_of_block + i][S_y_of_block + j+1] == 2 || S_connected_map[S_x_of_block + i -1][S_y_of_block + j] == 2 || S_connected_map[S_x_of_block + i][S_y_of_block + j-1] == 2){
              Connected_2 = true;
            }
          }
          else{
            if(S_connected_map[S_x_of_block + i + 1][S_y_of_block + j] == 3 || S_connected_map[S_x_of_block + i][S_y_of_block + j+1] == 3 || S_connected_map[S_x_of_block + i -1][S_y_of_block + j] == 3 || S_connected_map[S_x_of_block + i][S_y_of_block + j-1] == 3){
              Connected_3 = true;
            }
            if(S_connected_map[S_x_of_block + i + 1][S_y_of_block + j] == 4 || S_connected_map[S_x_of_block + i][S_y_of_block + j+1] == 4 || S_connected_map[S_x_of_block + i -1][S_y_of_block + j] == 4 || S_connected_map[S_x_of_block + i][S_y_of_block + j-1] == 4){
              Connected_4 = true;
            }
          }
        }
      }
    }

    if(S_player1){
      if(Connected_1 == true && Connected_2 == true){
        Connected_Value = 1000;
      }
    }
    else{
      if(Connected_3 == true && Connected_4 == true){
        Connected_Value = 1000;
      }
    }

  }
//--------------------------------------------------------------Connectivity--------------------------------------------------------------


//--------------------------------------------------------------Boundary--------------------------------------------------------------
    for(int kk = 1; kk<14; kk++){
      for(int ll = 1; ll<14; ll++){
        if(S_player1){
          if(S_temporary_map[kk][ll] == 'O' && Up > kk){
            Up = kk;
          }
          if(S_temporary_map[kk][ll] == 'O' && Down < kk)
            Down = kk;
        }
        else{
          if(S_temporary_map[kk][ll] == 'X' && Up > kk){
            Up = kk;
          }
          if(S_temporary_map[kk][ll] == 'X' && Down < kk)
            Down = kk;
        }
      }
    }

    for(int m = 1; m<14; m++){
      for(int n = 1; n<14; n++){
        if(S_player1){
          if(S_temporary_map[n][m] == 'O' && Left > m){
             Left = m;
          }
          if(S_temporary_map[n][m] == 'O' && Right < m)
            Right = m;
        }
        else{
          if(S_temporary_map[n][m] == 'X' && Left > m){
            Left = m;
          }
          if(S_temporary_map[n][m] == 'X' && Right < m)
            Right = m;
        }
      }
    }


    if(S_player1){
      if(S_Domain_Boun_p1 == 1){
        Boundary = (13 - Up) + 1.5*(Down - 1) + 2.5*(13 - Left) + 2.5*(Right - 1);
      }
      else if (S_Domain_Boun_p1 == 2){
        Boundary = 2.5*(13 - Up) + 2.5*(Down - 1) + (13 - Left) + 1.5*(Right - 1);
      }
    }
    else{
        if(S_Domain_Boun_p2 == 1){
          Boundary = (13 - Up) + 1.5*(Down - 1) + 2.5*(13 - Left) + 2.5*(Right - 1);
        }
        else if(S_Domain_Boun_p2 == 2){
          Boundary = 2.5*(13 - Up) + 2.5*(Down - 1) + (13 - Left) + 1.5*(Right - 1);
        }
        else if(S_Domain_Boun_p2 == 3){
          Boundary = 1.5*(13 - Up) + (Down - 1) + 2.5*(13 - Left) + 2.5*(Right - 1);
        }
        else if(S_Domain_Boun_p2 == 4){
          Boundary = 2.5*(13 - Up) + 2.5*(Down - 1) + 1.5*(13 - Left) + (Right - 1);
        }
    }
    if(step > 4){
      if(Left == 1){
        Boundary = Boundary + 200;
      }
      if(Right == 13){
        Boundary = Boundary + 100;
      }
      if(Down == 13){
        Boundary = Boundary + 100;
      }
      if(Up == 1){
        Boundary = Boundary + 100;
      }
    }
//--------------------------------------------------------------Boundary--------------------------------------------------------------



//--------------------------------------------------------------Eliminate star war--------------------------------------------------------------
  if(Star == 1){
    Star = -500;
  }
//--------------------------------------------------------------Eliminate star war--------------------------------------------------------------

//--------------------------------------------------------------Eliminate Boundary--------------------------------------------------------------
  if(Bad_Boun == 1){
    Bad_Boun = 0;
  }
  else if(Bad_Boun > 1){
    Bad_Boun = Bad_Boun - 1;
    Bad_Boun = (-10)*Bad_Boun;
  }
//--------------------------------------------------------------Eliminate Boundary--------------------------------------------------------------

//---------------------------------------------------------------Attack Opponent----------------------------------------------------------------
for(int i = 0; i<4; i++){
  for(int j = 0; j<4; j++){
    if (S_block[i][j]) {
      if(S_player1){
        if((S_x_of_block +i > 1 || S_x_of_block +i < 13) && (S_y_of_block +j > 1 || S_y_of_block +j < 13)){
          if(S_temporary_map[S_x_of_block + i + 1][S_y_of_block + j] == 'X' || S_temporary_map[S_x_of_block + i][S_y_of_block + j + 1] == 'X' ||  S_temporary_map[S_x_of_block + i - 1][S_y_of_block + j] == 'X' ||  S_temporary_map[S_x_of_block + i][S_y_of_block + j - 1] == 'X'
             || S_temporary_map[S_x_of_block + i + 1][S_y_of_block + j + 1] == 'X' || S_temporary_map[S_x_of_block + i -1][S_y_of_block + j + 1] == 'X' ||  S_temporary_map[S_x_of_block + i + 1][S_y_of_block + j - 1] == 'X' ||  S_temporary_map[S_x_of_block + i - 1][S_y_of_block + j - 1] == 'X') {
               Attack = Attack + 5;
          }
          else if(S_temporary_map[S_x_of_block + i + 2][S_y_of_block + j] == 'X' || S_temporary_map[S_x_of_block + i][S_y_of_block + j + 2] == 'X' ||  S_temporary_map[S_x_of_block + i - 2][S_y_of_block + j] == 'X' ||  S_temporary_map[S_x_of_block + i][S_y_of_block + j - 2] == 'X'
             || S_temporary_map[S_x_of_block + i + 2][S_y_of_block + j + 2] == 'X' || S_temporary_map[S_x_of_block + i -2][S_y_of_block + j + 2] == 'X' ||  S_temporary_map[S_x_of_block + i + 2][S_y_of_block + j - 2] == 'X' ||  S_temporary_map[S_x_of_block + i - 2][S_y_of_block + j - 2] == 'X') {
               Attack = Attack + 3;
          }
          else if(S_temporary_map[S_x_of_block + i + 3][S_y_of_block + j] == 'X' || S_temporary_map[S_x_of_block + i][S_y_of_block + j + 3] == 'X' ||  S_temporary_map[S_x_of_block + i - 3][S_y_of_block + j] == 'X' ||  S_temporary_map[S_x_of_block + i][S_y_of_block + j - 3] == 'X'
             || S_temporary_map[S_x_of_block + i + 3][S_y_of_block + j + 3] == 'X' || S_temporary_map[S_x_of_block + i -3][S_y_of_block + j + 3] == 'X' ||  S_temporary_map[S_x_of_block + i + 3][S_y_of_block + j - 3] == 'X' ||  S_temporary_map[S_x_of_block + i - 3][S_y_of_block + j - 3] == 'X') {
               Attack = Attack + 1;
          }
        }
      }
      else{
        if((S_x_of_block +i > 1 || S_x_of_block +i < 13) && (S_y_of_block +j > 1 || S_y_of_block +j < 13)){
          if(S_temporary_map[S_x_of_block + i + 1][S_y_of_block + j] == 'O' || S_temporary_map[S_x_of_block + i][S_y_of_block + j + 1] == 'O' ||  S_temporary_map[S_x_of_block + i - 1][S_y_of_block + j] == 'O' ||  S_temporary_map[S_x_of_block + i][S_y_of_block + j - 1] == 'O'
             || S_temporary_map[S_x_of_block + i + 1][S_y_of_block + j + 1] == 'O' || S_temporary_map[S_x_of_block + i -1][S_y_of_block + j + 1] == 'O' ||  S_temporary_map[S_x_of_block + i + 1][S_y_of_block + j - 1] == 'O' ||  S_temporary_map[S_x_of_block + i - 1][S_y_of_block + j - 1] == 'O') {
               Attack = Attack + 5;
          }
          else if(S_temporary_map[S_x_of_block + i + 2][S_y_of_block + j] == 'O' || S_temporary_map[S_x_of_block + i][S_y_of_block + j + 2] == 'O' ||  S_temporary_map[S_x_of_block + i - 2][S_y_of_block + j] == 'O' ||  S_temporary_map[S_x_of_block + i][S_y_of_block + j - 2] == 'O'
             || S_temporary_map[S_x_of_block + i + 2][S_y_of_block + j + 2] == 'O' || S_temporary_map[S_x_of_block + i -2][S_y_of_block + j + 2] == 'O' ||  S_temporary_map[S_x_of_block + i + 2][S_y_of_block + j - 2] == 'O' ||  S_temporary_map[S_x_of_block + i - 2][S_y_of_block + j - 2] == 'O') {
               Attack = Attack + 3;
          }
          else if(S_temporary_map[S_x_of_block + i + 3][S_y_of_block + j] == 'O' || S_temporary_map[S_x_of_block + i][S_y_of_block + j + 3] == 'O' ||  S_temporary_map[S_x_of_block + i - 3][S_y_of_block + j] == 'O' ||  S_temporary_map[S_x_of_block + i][S_y_of_block + j - 3] == 'O'
             || S_temporary_map[S_x_of_block + i + 3][S_y_of_block + j + 3] == 'O' || S_temporary_map[S_x_of_block + i -3][S_y_of_block + j + 3] == 'O' ||  S_temporary_map[S_x_of_block + i + 3][S_y_of_block + j - 3] == 'O' ||  S_temporary_map[S_x_of_block + i - 3][S_y_of_block + j - 3] == 'O') {
               Attack = Attack + 1;
          }
        }
      }
    }
  }
}
//---------------------------------------------------------------Attack Opponent----------------------------------------------------------------

//-----------------------------------------------------------------Self Domain------------------------------------------------------------------
for (int ii = 0; ii < 4; ii++) {
    for (int jj = 0; jj < 4; jj++) {
        if (S_block[ii][jj]) {
            if (S_player1) {
                if(S_Domain_Boun_p1 == 1){
                  if(S_x_of_block + ii < 6){
                      Self_Domain = Self_Domain - 50;
                  }
                }
                else if(S_Domain_Boun_p1 == 2){
                  if(S_y_of_block + jj < 6){
                      Self_Domain = Self_Domain - 50;
                  }
                }
            }
            else {
                if(S_Domain_Boun_p2 == 1){
                  if(S_x_of_block + ii < 6){
                      Self_Domain = Self_Domain - 50;
                  }
                }
                else if(S_Domain_Boun_p2 == 2){
                  if(S_y_of_block + jj < 6){
                      Self_Domain = Self_Domain - 50;
                  }
                }
                else if(S_Domain_Boun_p2 == 3){
                  if(S_x_of_block + ii > 8){
                      Self_Domain = Self_Domain - 50;
                  }
                }
                else if(S_Domain_Boun_p2 == 4){
                  if(S_y_of_block + jj > 8){
                      Self_Domain = Self_Domain - 50;
                  }
                }
            }

        }
    }
}
//-----------------------------------------------------------------Self Domain------------------------------------------------------------------

  /*Length : 1,3,4
   Connectivity : 4 blocks for one time
   Boundary : Up , Down, Left, Right, 0~12
   Star : one penalty
   Bad_Boun : 4 blocks for one time
   Connected_Value : one time for one connected
   Attack : 4 blocks for one time
   Self_Domain : 4 blocks for one time

 */
  if(step < 5){
    Heuristic_Value = 10*Length + Connectivity + 2*Boundary + Star + Bad_Boun + Connected_Value + Attack + Self_Domain;
  }
  else{
    Heuristic_Value = 10*Length + Connectivity + 3*Boundary + Star + Bad_Boun + Connected_Value + Attack + Self_Domain;
  }

  /*
  Connectivity, Boundary, Attack
  */

  //Heuristic_Value = 5*Length + Connectivity + Boundary + Star + Bad_Boun + Connected_Value + Attack + Self_Domain;
  return Heuristic_Value;
}

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


//void AI_Sel(int player, int type, int step, bool &S_Connected_p1, bool &S_Connected_p2, int &S_Domain_Boun_p1, int &S_Domain_Boun_p2)
int S_player(int S_player, int S_iffirst, int step, int child_number)
{
  int  PC_1 = 1;
  int  PC_2[2] = {1,1};
  int  PC_3 = 1;
  bool block_sel = false;
  bool overlapped = false;
  bool Out_Range = false;
  bool Connected_Star = false;
  bool temp[4][4];
  bool pass = true;
  bool AI_Error = true;
  bool H_finish = false;
  bool H_target = false;
  int temp_max = 0;
  int temp_len = 0;
  int temp_con = 0;
  int temp_bou = 0;
  int temp_c = 0;
  int temp_s = 0;
  int temp_a = 0;
  int Instr[10][6]= {0};
  int child_num = 0;
  int Heuristic_Value = 0;
  int Length = 0;
  int Connectivity = 0;//connected points
  int Connect_Point = 0;
  int Boundary = 0;//closeness to boundary
  int Up = 13;
  int Down = 0;
  int Left = 13;
  int Right = 0;
  int temp_step = 0;
  int Connected_Value = 0;
  int Self_Domain = 0;
  int Attack = 0;

  srand(time(NULL));


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
    /*for (int i = 1; i < 14; i++) {
        for (int j = 1; j < 14; j++) {
            if (S_temporary_map[i][j] == '*') {
                printf(" \e[33m%c\e[0m ", S_temporary_map[i][j]);
            } else if (temporary_map[i][j] == 'O') {
                printf(" \e[32m%c\e[0m ", S_temporary_map[i][j]);
            } else if (temporary_map[i][j] == 'X') {
                printf(" \e[31m%c\e[0m ", S_temporary_map[i][j]);
            } else {
                printf(" %c ", S_temporary_map[i][j]);
            }
        }
        printf("\n");
    }*/
    /*printf("======================== Connected Sequence ========================\n\n");
  		for (int i = 1; i < 14; i++) {
  			for (int j = 1; j < 14; j++) {
  	      if (S_connected_map[i][j] == 1 || S_connected_map[i][j] == 2) {
  	          printf(" \e[32m%d\e[0m ", S_connected_map[i][j]);
          } else if (S_connected_map[i][j] == 3 || S_connected_map[i][j] == 4) {
      	      printf(" \e[31m%d\e[0m ", S_connected_map[i][j]);
  	      } else {
  	          printf(" %d ", S_connected_map[i][j]);
  	      }
  	    }
  	    printf("\n");
  	  }
  		printf("======================== Connected Sequence ========================\n\n");
  		printf("\n\n\n");
    printf("SHIT!\n");
    sleep(3);*/


    while(H_finish == false){
        AI_Error = true;

        while (AI_Error == true || H_target == true){

            overlapped = false;
            Out_Range = false;
            Connected_Star = false;
            AI_Error = false;

            if(H_target == true){
              /*for(int i = 0; i < 10 ; i++){
                printf("child_num : %d\n", i);
                printf("Instr[0]: %d\n",Instr[i][0]);
                printf("Instr[1]: %d\n",Instr[i][1]);
                printf("Instr[2]: %d\n",Instr[i][2]);
                printf("Instr[3]: %d\n",Instr[i][3]);
                printf("Instr[4]: %d\n",Instr[i][4]);
                printf("Instr[5]: %d\n",Instr[i][5]);
              }*/
              child_num = child_number;
              PC_1 = Instr[child_num][0];
              PC_2[0] = Instr[child_num][1];
              PC_2[1] = Instr[child_num][2];
              PC_3 = Instr[child_num][3];
              H_finish = true;
              H_target = false;
            }

            S_using_block = PC_1;
            S_x_of_block = PC_2[0];
            S_y_of_block = PC_2[1];

            if((S_player1 == 1 && S_p1_used_block[PC_1 - 1] == true) || (S_player1 == 0 && S_p2_used_block[PC_1 - 1] == true)){
              AI_Error = true;
            }

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
                            if(S_player1){
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

            if(AI_Error == true){

              if(PC_3 < 4){
                PC_3 = PC_3 + 1;
              }
              else{
                PC_3 = 1;
                if(PC_1 < 9){
                  PC_1 = PC_1 + 1;
                }
                else{
                  PC_1 = 1;
                  if(PC_2[1] < 13){
                    PC_2[1] = PC_2[1] + 1;
                  }
                  else{
                    PC_2[1] = 1;
                    if(PC_2[0] < 13){
                      PC_2[0] = PC_2[0] + 1;
                    }
                    else{
                      H_target = true;
                    }
                  }
                }
              }
            }

        }

        if(step < 2 || H_finish == true){
          break;
        }
        else{
              Heuristic_Value = Heuristic_Function(PC_1,Length,Connectivity,Connect_Point,S_Connected_p1,S_Connected_p2,Boundary,Up,Down,Left,Right,Connected_Value,S_Domain_Boun_p1,S_Domain_Boun_p2,Self_Domain,Attack,step);
              for(int i = 0 ; i < 10; i ++){
                if(Instr[i][4] < Heuristic_Value){
                  if(Instr[i][4] != 0){
                    for(int j = 9; j > i; j--){
                      Instr[j][0] = Instr[j-1][0];
                      Instr[j][1] = Instr[j-1][1];
                      Instr[j][2] = Instr[j-1][2];
                      Instr[j][3] = Instr[j-1][3];
                      Instr[j][4] = Instr[j-1][4];
                      Instr[j][5] = Instr[j-1][5];
                    }
                    Instr[i][0] = PC_1;
                    Instr[i][1] = PC_2[0];
                    Instr[i][2] = PC_2[1];
                    Instr[i][3] = PC_3;
                    Instr[i][4] = Heuristic_Value;
                    Instr[i][5] = Connected_Value;
                    break;
                  }
                  else{
                    Instr[i][0] = PC_1;
                    Instr[i][1] = PC_2[0];
                    Instr[i][2] = PC_2[1];
                    Instr[i][3] = PC_3;
                    Instr[i][4] = Heuristic_Value;
                    Instr[i][5] = Connected_Value;
                    break;
                  }
                }
              }
              /*if(temp_max < Heuristic_Value){
                Instr[0] = PC_1;
                Instr[1] = PC_2[0];
                Instr[2] = PC_2[1];
                Instr[3] = PC_3;
                temp_max = Heuristic_Value;
                temp_len = Length;
                temp_con = Connectivity;
                temp_bou = Boundary;
                temp_c = Connected_Value;
                temp_s = Self_Domain;
                temp_a = Attack;
              }*/
              if(PC_3 < 4){
                PC_3 = PC_3 + 1;
              }
              else{
                PC_3 = 1;
                if(PC_1 < 9){
                  PC_1 = PC_1 + 1;
                }
                else{
                  PC_1 = 1;
                  if(PC_2[1] < 13){
                    PC_2[1] = PC_2[1] + 1;
                  }
                  else{
                    PC_2[1] = 1;
                    if(PC_2[0] < 13){
                      PC_2[0] = PC_2[0] + 1;
                    }
                    else{
                      H_target = true;
                    }
                  }
                }
              }
        }

    }

    if(Instr[child_num][5] == 1000 && S_player1 == 1){
      S_Connected_p1 = true;
    }
    else if(Instr[child_num][5] == 1000 && S_player1 == 0){
      S_Connected_p2 = true;
    }

      switch (S_using_block) {
          case 1:
              if(S_player1 == 1){
                  S_p1_used_block[0] = true;
              }
              else{
                  S_p2_used_block[0] = true;
              }
              break;
          case 2:
              if(S_player1 == 1){
                  S_p1_used_block[1] = true;
              }
              else{
                  S_p2_used_block[1] = true;
              }
              break;
          case 3:
              if(S_player1 == 1){
                  S_p1_used_block[2] = true;
              }
              else{
                  S_p2_used_block[2] = true;
              }
              break;
          case 4:
              if(S_player1 == 1){
                  S_p1_used_block[3] = true;
              }
              else{
                  S_p2_used_block[3] = true;
              }
              break;
          case 5:
              if(S_player1 == 1){
                  S_p1_used_block[4] = true;
              }
              else{
                  S_p2_used_block[4] = true;
              }
              break;
          case 6:
              if(S_player1 == 1){
                  S_p1_used_block[5] = true;
              }
              else{
                  S_p2_used_block[5] = true;
              }
              break;
          case 7:
              if(S_player1 == 1){
                  S_p1_used_block[6] = true;
              }
              else{
                  S_p2_used_block[6] = true;
              }
              break;
          case 8:
              if(S_player1 == 1){
                  S_p1_used_block[7] = true;
              }
              else{
                  S_p2_used_block[7] = true;
              }
              break;
          case 9:
              if(S_player1 == 1){
                  S_p1_used_block[8] = true;
              }
              else{
                  S_p2_used_block[8] = true;
              }
              break;
      }


      S_printf_temporary_map();
      /*printf("Step:%d\n",step);
      if (step > 1) {
	      printf("Heuristic Value: %d\n",temp_max);
	      printf("Block Length: %d\n",temp_len);
	      printf("Connectivity of Points: %d\n",temp_con);
	      printf("Closeness to Boundary: %d\n", temp_bou);
	      printf("Selected Block Type: %d\n", Instr[0]);
	      printf("X nad Y Coordinates: (%d,%d)\n", Instr[1], Instr[2]);
	      printf("Rotation Degree: %d\n", Instr[3]);
        printf("S_Connected_p1: %d\n", S_Connected_p1);
        printf("S_Connected_p2: %d\n", S_Connected_p2);
        printf("Connected_Value: %d\n", temp_c);
        printf("Self_Domain: %d\n", temp_s);
        printf("Attack: %d\n", temp_a);
        printf("S_Domain_Boun_p1: %d\n", S_Domain_Boun_p1);
        printf("S_Domain_Boun_p2: %d\n", S_Domain_Boun_p2);
	      printf("\n\n");
      }*/
      step = step + 1;
      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++) {
          if(step > 1){
            if (S_block[ii][jj]) {
              if(S_player1){
                if(S_connected_map[S_x_of_block + ii + 1][S_y_of_block + jj] == 1 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj+1] == 1 || S_connected_map[S_x_of_block + ii -1][S_y_of_block + jj] == 1 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj-1] == 1){
                  temp_step = 1;
                  break;
                }
                else if(S_connected_map[S_x_of_block + ii + 1][S_y_of_block + jj] == 2 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj+1] == 2 || S_connected_map[S_x_of_block + ii -1][S_y_of_block + jj] == 2 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj-1] == 2){
                  temp_step = 2;
                  break;
                }
              }
              else{
                if(S_connected_map[S_x_of_block + ii + 1][S_y_of_block + jj] == 3 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj+1] == 3 || S_connected_map[S_x_of_block + ii -1][S_y_of_block + jj] == 3 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj-1] == 3){
                  temp_step = 3;
                  break;
                }
                else if(S_connected_map[S_x_of_block + ii + 1][S_y_of_block + jj] == 4 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj+1] == 4 || S_connected_map[S_x_of_block + ii -1][S_y_of_block + jj] == 4 || S_connected_map[S_x_of_block + ii][S_y_of_block + jj-1] == 4){
                  temp_step = 4;
                  break;
                }
              }
            }
          }
        }
      }

      if(S_player1){
        if(temp_step == 0){
          temp_step = 2;
        }
      }
      else{
        if(temp_step == 0){
          temp_step = 4;
        }
      }

      for (int ii = 0; ii < 4; ii++) {
        for (int jj = 0; jj < 4; jj++){
          if(step > 1){
            if (S_block[ii][jj]) {
                  S_connected_map[S_x_of_block + ii][S_y_of_block + jj] = temp_step;
            }
          }
        }
      }

      for (int i = 1; i < 14; i++) {
          for (int j = 1; j < 14; j++) {
              S_Map[i][j] = S_temporary_map[i][j];
          }
      }
      /*printf("======================== Connected Sequence ========================\n\n");
  		for (int i = 1; i < 14; i++) {
  			for (int j = 1; j < 14; j++) {
  	      if (S_connected_map[i][j] == 1 || S_connected_map[i][j] == 2) {
  	          printf(" \e[32m%d\e[0m ", S_connected_map[i][j]);
          } else if (S_connected_map[i][j] == 3 || S_connected_map[i][j] == 4) {
      	      printf(" \e[31m%d\e[0m ", S_connected_map[i][j]);
  	      } else {
  	          printf(" %d ", S_connected_map[i][j]);
  	      }
  	    }
  	    printf("\n");
  	  }
  		printf("======================== Connected Sequence ========================\n\n");
  		printf("\n\n\n");*/
      S_file_Array2[block_count2]=Instr[child_num][1];
      S_file_Array2[block_count2+1]=Instr[child_num][2];
      S_file_Array2[block_count2+2]=Instr[child_num][0];
      S_file_Array2[block_count2+3]=Instr[child_num][3]-1;
      S_block_count2+=4;

      if (S_iffirst == 1) {
          S_expansion_block[0] = PC_1;
          S_expansion_block[1] = PC_2[0];
          S_expansion_block[2] = PC_2[1];
          S_expansion_block[3] = PC_3;
      }

      return 100;
//-----------------------------------------------------------------------------------`

}
