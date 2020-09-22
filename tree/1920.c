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
	Node *node;
	node = malloc(sizeof(Node));
	if(root==NULL){
		root=node;
		node->data=num;
		node->Lnode=NULL;
		node->Rnode=NULL;
		return;
	}
	Node *tracker=root;
	while(tracker!=NULL){
		if(tracker->data<num){
			if(tracker->Rnode==NULL){
				tracker->Rnode=node;
				node->data=num;
				node->Lnode=NULL;
				node->Rnode=NULL;
			}
			tracker=tracker->Rnode;
		}else{
			if(tracker->Lnode==NULL){
				tracker->Lnode=node;
				node->data=num;
				node->Lnode=NULL;
				node->Rnode=NULL;
			}
			tracekr=tracekr->Lnode;
		}
	}
	return;
}
void  t_find(int num){
	Node *tracker=root;
	int exist=0;
	while(tracker!=NULL){
		if(tracker->data<num){
			tracker=tracker->Rnode;
		}
		if(tracekr->data>num){
			tracekr=tracekr->Lnode;
		}
		if(tracker->data==num){
			exist=1;
		}
	}
	printf("%d",exist);
}
