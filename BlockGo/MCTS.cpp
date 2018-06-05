#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "General.h"

void S_source_assign(){
	int i,j;
	for(i=0;i<30;i++){
		S_blocklife1[i]=blocklife1[i];
		S_blocklife2[i]=blocklife2[i];
	}

	for(i=0;i<15;i++){
		for(j=0;j<15;j++){
			S_temporary_map[i][j]=temporary_map[i][j];
			S_Map[i][j]=Map[i][j];
			S_final_map[i][j]=final_map[i][j];
			S_final_map1[i][j]=final_map1[i][j];
			S_final_map2[i][j]=final_map2[i][j];
			S_live_or_dead_map[i][j]=live_or_dead_map[i][j];
		}
	}

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			S_block[i][j]=block[i][j];
			S_block1[i][j]=block1[i][j];
			S_block2[i][j]=block2[i][j];
			S_block3[i][j]=block3[i][j];
			S_block4[i][j]=block4[i][j];
			S_block5[i][j]=block5[i][j];
			S_block6[i][j]=block6[i][j];
			S_block7[i][j]=block7[i][j];
			S_block8[i][j]=block8[i][j];
			S_block9[i][j]=block9[i][j];
		}
	}

	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			S_p1_used_block[i]=p1_used_block[i];
			S_p2_used_block[i]=p2_used_block[i];
		}
	}

	for(i=0;i<600;i++){
			S_search_array[i]=search_array[i];
	}
	for(i=0;i<48;i++){
			S_boundary[i]=boundary[i];
	}
	for(i=0;i<36;i++){
			S_file_Array1[i]=file_Array1[i];
			S_file_Array2[i]=file_Array2[i];
	}

	S_x_of_block=x_of_block;
	S_y_of_block=y_of_block;
	
	S_player1=player1;
	
	S_using_block=using_block;
	
	S_unkown_number=unkown_number;
	
	S_search_array_number=search_array_number;
	S_number_of_p1=number_of_p1;
	S_number_of_p2=number_of_p2;
	
	S_block_begin1=block_begin1;
	S_block_end1=block_end1;
	
	S_block_begin2=block_begin2;
	S_block_end2=block_end2;
	
	S_boundary_number=boundary_number;
	
	S_block_count1=block_count1;
	S_block_count2=block_count2;
	S_block_change1=block_change1;
	return;
}

struct block_node* new_node(int block_number, int c, int x, int y, int which_player, int bout) {
    struct block_node *node = (struct block_node*)malloc(sizeof(struct block_node));
    node->block_number = block_number;
    node->parent = NULL;
    node->child = NULL;
    node->leftsibling = node;
    node->rightsibling = node;

	node->x=x;
	node->y=y;
	node->c=c;
	node->which_player=which_player;
	node->win=0.0;
	node->number=0.0;
	node->child_number=0;
	node->bout=bout;
    return node;
	
}

void addChild(struct block_node *node, struct block_node *child) {
    child->parent = node;
    if(node->child == NULL) {
        node->child = child;
    }
    else {
        child->leftsibling = node->child->leftsibling;
        child->rightsibling = node->child;
        node->child->leftsibling->rightsibling = child;
        node->child->leftsibling = child;
    }
	node->child_number++;
	return;
}

void deleteNode(struct block_node *node) {
    free(node);
	return;
}

struct block_node* UCT(struct block_node *node,int t){
	//printf("UCT\n\n");
	//scanf("%d", &aaaa);
	struct block_node *final_child;
	struct block_node *child = node->child;
	double max;
	max=(child->win/child->number)+sqrt( ( log(t) )/child->number );
	int child_number=1;
	final_child=child;
	
	//printf("max=%lf\n",max);
	//printf("child_number=%d\n\n",child_number);
	
	int max_child_number=child_number;
	
	child=child->rightsibling;
	double new_max;
	
	while(child!=node->child){
		child_number++;
		new_max = (child->win/child->number)+sqrt( ( log(t) )/child->number );
		//printf("max=%lf\n",new_max);
		//printf("child_number=%d\n\n",child_number);
		if( max< new_max ){
			max=new_max;
			max_child_number=child_number;
			final_child=child;
		}
		child=child->rightsibling;
	}
	//printf("max=%lf\n",max);
	//printf("max_child_number=%d\n",max_child_number);

	//printf("UCT_end\n");
	//scanf("%d", &aaaa);
	
	return final_child;
}

struct block_node* MCTS(struct block_node *root) {
	//printf("MCTS\n");
	//scanf("%d", &aaaa);
	int before_num=root->number;
	int t=before_num;
	int com=0;

	while(t<(200000+before_num)){
		printf("t = %d\n",t);
		//scanf("%d", &aaaa);
		//----------------------------Selection----------------------------//
		S_source_assign();
		int select=0;
		struct block_node *leaf;
		leaf=root;
		while(select==0){
			if(leaf->child_number<25){
				select++;
			}
			else{
				leaf=UCT(leaf,t);
				
				int S_w_player;
				int PC_1 = 0;
				int PC_2[2] = {0,0};
				int PC_3 = 0;
				
					
				S_w_player=leaf->which_player;
				S_player1=(leaf->which_player==1)?true:false;
				PC_1 = leaf->block_number;
				PC_2[0] = leaf->x;
				PC_2[1] = leaf->y;
				PC_3 = leaf->c;
				//printf("UCT->next->node : player:%d  number=%d  x=%d  y=%d  c=%d \n",S_w_player,PC_1,PC_2[0],PC_2[1],PC_3);
				//scanf("%d", &aaaa);
				
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
				bool temp[4][4];
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

				
				switch (S_using_block) {
					case 1:
						if(S_w_player == 1){
							S_p1_used_block[0] = true;
						}
						else{
							S_p2_used_block[0] = true;
						}
						break;
					case 2:
						if(S_w_player == 1){
							S_p1_used_block[1] = true;
						}
						else{
							S_p2_used_block[1] = true;
						}
						break;
					case 3:
						if(S_w_player == 1){
							S_p1_used_block[2] = true;
						}
						else{
							S_p2_used_block[2] = true;
						}
						break;
					case 4:
						if(S_w_player == 1){
							S_p1_used_block[3] = true;
						}
						else{
							S_p2_used_block[3] = true;
						}
						break;
					case 5:
						if(S_w_player == 1){
							S_p1_used_block[4] = true;
						}
						else{
							S_p2_used_block[4] = true;
						}
						break;
					case 6:
						if(S_w_player == 1){
							S_p1_used_block[5] = true;
						}
						else{
							S_p2_used_block[5] = true;
						}
						break;
					case 7:
						if(S_w_player == 1){
							S_p1_used_block[6] = true;
						}
						else{
							S_p2_used_block[6] = true;
						}
						break;
					case 8:
						if(S_w_player == 1){
							S_p1_used_block[7] = true;
						}
						else{
							S_p2_used_block[7] = true;
						}
						break;
					case 9:
						if(S_w_player == 1){
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
			}
		}
		//----------------------------Selection----------------------------//
		int whichplay;
		int which_bout;
		
		int ifwin;
		bool different_child = false;
		
		if(leaf->bout!=9 || leaf->which_player!=2){
			
			whichplay=(leaf->which_player==1)?2:1;
			which_bout=(leaf->which_player==1)?(leaf->bout):(leaf->bout+1);
			printf("sim start\n");
			ifwin=S_Simulate(whichplay, which_bout);
			printf("sim end\n");
			//----------------------------Expansion----------------------------//
			struct block_node *newchild=new_node(S_expansion_block[0], S_expansion_block[3], S_expansion_block[1], S_expansion_block[2], whichplay, which_bout);
			addChild(leaf,newchild);
			leaf=newchild;
			//----------------------------Expansion----------------------------//
		} else{
			whichplay=1;
			which_bout=10;
			ifwin=S_Simulate(whichplay, which_bout);
		}	
	
		
		
		//-------------------------Backpropagation-------------------------//
		while(leaf!=root){
			
			if(leaf->which_player==1 && ifwin==1){
				leaf->win+=1.0;
				leaf->number+=1.0;
			}
			else if(leaf->which_player==1 && ifwin==2){
				leaf->win+=0.0;
				leaf->number+=1.0;
			}
			else if(leaf->which_player==2 && ifwin==2){
				leaf->win+=1.0;
				leaf->number+=1.0;
			}
			else if(leaf->which_player==2 && ifwin==1){
				leaf->win+=0.0;
				leaf->number+=1.0;
			}
			else if(ifwin==0){
				leaf->win+=0.0;
				leaf->number+=1.0;
			}
			else if(ifwin==3){
				leaf->win+=0.0;
				leaf->number+=0.0;
			}
			leaf=leaf->parent;
		}
		//-------------------------Backpropagation-------------------------//
		
		t+=1;
		
		
	}
	
	struct block_node *final_return_node;
	struct block_node *return_node = root->child;
	double max= return_node->win/return_node->number;
	final_return_node=return_node;
	int child_number=1;
	int max_child_number=child_number;
	
	return_node=return_node->rightsibling;
	double new_max;
	
	while(return_node!=root->child){
		child_number++;
		new_max = return_node->win/return_node->number;
		
		if( max< new_max ){
			max=new_max;
			max_child_number=child_number;
			final_return_node=return_node;
		}
		return_node=return_node->rightsibling;
	}
	
	return final_return_node;
}
