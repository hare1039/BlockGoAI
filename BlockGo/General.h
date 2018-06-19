#include <cstdio>
struct allblock {
    int x;
    int y;
    bool if_live;
    bool if_live1;
};

extern int aaaa;

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
extern int search_array[600];
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
extern bool webmode;

extern int connected_map[15][15];
extern bool Connected_p1;
extern bool Connected_p2;
extern int Domain_Boun_p1;
extern int Domain_Boun_p2;

/*------------------Intro_MapDisplay------------------*/
void introduction();
void initialize_block();
void initialize_map();
void printf_temporary_map();
/*------------------Intro_MapDisplay------------------*/


/*------------------------Rule------------------------*/
void transfer();
void player(int player, int choice, int bout);
int Computing_perimeter();
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

/*------------------------MCTS------------------------*/
struct block_node{

    struct block_node *parent;
    struct block_node *child;
    struct block_node *leftsibling;
    struct block_node *rightsibling;

    int block_number;
    int c;
	int x;
    int y;
    double win;
    double number;
    int which_player;
    int bout;
	int child_number;
};

struct block_node* new_node(int block_number, int c, int x, int y, int which_player, int bout);
void addChild(struct block_node *node, struct block_node *child) ;
void deleteNode(struct block_node *node);
struct block_node* UCT(struct block_node *node,int t);
struct block_node* MCTS(struct block_node *root);
struct block_node* MCTS_reuse(struct block_node *root);

extern struct block_node* reg_node;
/*------------------------MCTS------------------------*/

/*------------------------Simulation------------------------*/
extern struct allblock S_blocklife1[30];
extern struct allblock S_blocklife2[30];

extern char S_temporary_map[15][15];
extern char S_Map[15][15];
extern bool S_block[4][4];
extern int S_x_of_block;
extern int S_y_of_block;

extern bool S_block1[4][4];
extern bool S_block2[4][4];
extern bool S_block3[4][4];
extern bool S_block4[4][4];
extern bool S_block5[4][4];
extern bool S_block6[4][4];
extern bool S_block7[4][4];
extern bool S_block8[4][4];
extern bool S_block9[4][4];

extern bool S_player1;

extern bool S_p1_used_block[9];
extern bool S_p2_used_block[9];

extern int S_using_block;

extern int S_final_map[15][15];
extern int S_unkown_number;
extern int S_search_array[600];
extern int S_search_array_number;
extern int S_number_of_p1;
extern int S_number_of_p2;

extern int S_final_map1[15][15];
extern int S_final_map2[15][15];

extern int S_block_begin1;
extern int S_block_end1;

extern int S_block_begin2;
extern int S_block_end2;

extern bool S_boundary[48];
extern int S_boundary_number;

extern int S_live_or_dead_map[15][15];

extern int S_file_Array1[36];
extern int S_file_Array2[36];
extern int S_block_count1;
extern int S_block_count2;
extern int S_block_change1;

extern int S_expansion_block[4];

extern int S_connected_map[15][15];
extern bool S_Connected_p1;
extern bool S_Connected_p2;
extern int S_Domain_Boun_p1;
extern int S_Domain_Boun_p2;

void S_source_assign();
int S_Simulate(int whichplayer, int whichbout, int child_number);

void S_printf_temporary_map();

void S_transfer();
int S_player(int S_player, int iffirst, int step, int child_number);

void S_search_block1(int x, int y);
void S_search_block2(int x, int y);
bool S_decide_if_live();
void S_clear_live_or_dead_map();
void S_dead_or_life2_search(int x, int y);
bool S_decide_if_2_1(int p1);
void S_clear_search_array();
void S_search_number(int x, int y);
void S_decide_whose_number();
/*------------------------Simulation------------------------*/
