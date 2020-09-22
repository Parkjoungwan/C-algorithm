#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *Lnode;
	strcut Node *Rnode;
}Node;

Node * headroot;
int N;
int F;
void t_push(int num);
void t_find(int num);

void nojam192(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		t_push(num);
	}
	scanf("%d",&F){
		int num;
		scanf("%d",&num);
		t_find(num);
	}	
}

int mani(){
	nojam1920();
}

void t_push(int num){
	return;
}
void t_find(int num){
	return;
}
