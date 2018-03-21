struct allblock {
    int x;
    int y;
    bool if_live;
    bool if_live1;
};

extern allblock blocklife1[30];
extern allblock blocklife2[30];

extern char temporary_map[15][15];
extern char Map[15][15];
extern bool block[4][4];
extern int x_of_block;
extern int y_of_block;

extern bool block1[4][4];
extern bool block2[4][4];
extern bool block3[4][4];
extern bool block4[4][4];
extern bool block5[4][4];
extern bool block6[4][4];
extern bool block7[4][4];
extern bool block8[4][4];
extern bool block9[4][4];

extern bool player1;

extern bool p1_used_block[9];
extern bool p2_used_block[9];

extern int using_block;

extern int final_map[15][15];
extern int unkown_number;
extern int search_array[60];
extern int search_array_number;
extern int number_of_p1;
extern int number_of_p2;

extern int final_map1[15][15];
extern int final_map2[15][15];

extern int block_begin1;
extern int block_end1;

extern int block_begin2;
extern int block_end2;

extern bool boundary[48];
extern int boundary_number;

extern int live_or_dead_map[15][15];

extern int file_Array1[36];
extern int file_Array2[36];
extern int block_count1;
extern int block_count2;
extern int block_change1;

/*------------------Intro_MapDisplay------------------*/
void introduction();
void reduction_block();
void reduction_map();
void printf_temporary_map();
/*------------------Intro_MapDisplay------------------*/


/*------------------------Rule------------------------*/
void transfer();
void player(int player, int choice);
/*------------------------Rule------------------------*/

/*---------------------Cal_Result---------------------*/
void search_block1(int x, int y);
void search_block2(int x, int y);
bool decide_if_live();
void clear_live_or_dead_map();
void dead_or_life2_search(int x, int y);
bool decide_if_2_1(int p1);
void clear_search_array();
void search_number(int x, int y);
void decide_whose_number();
/*---------------------Cal_Result---------------------*/
