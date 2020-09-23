#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *Lnode;
	struct Node *Rnode;
}Node;

Node * root;
int N;
int F;
void t_push(int num);
void t_find(int num);

void nojam1920(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int num;
		scanf("%d",&num);
		t_push(num);
	}
	scanf("%d",&F);
	int find[100001];
	for(int i=0;i<F;i++){
		scanf("%d",&find[i]);
	}	
	for(int i=0;i<F;i++){
		t_find(find[i]);
	}
}

int main(){
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
				break;
			}
			tracker=tracker->Rnode;
		}else{
			if(tracker->Lnode==NULL){
				tracker->Lnode=node;
				node->data=num;
				node->Lnode=NULL;
				node->Rnode=NULL;
				break;
			}
			tracker=tracker->Lnode;
		}
	}
	return;
}
void  t_find(int num){
	Node *tracker;
	tracker=root;
	int exist=0;
	while(tracker!=NULL){
		if(tracker->data<num){
			if(tracker->Rnode==NULL) break;
			tracker=tracker->Rnode;
		}
		if(tracker->data>num){
			if(tracker->Lnode==NULL) break;
			tracker=tracker->Lnode;
		}
		if(tracker->data==num){
			exist=1;
			break;
		}
	}
	printf("%d\n",exist);
}
