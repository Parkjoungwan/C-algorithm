#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node * Lnode;
	struct Node * Rnode;
}Node;

Node * root;
void t_push(int num);
void postorder(Node *node);
void clear();

void nojam5639(){
	int num;
	while(scanf("%d",&num)!=EOF){
		t_push(num);
	}
	postorder(root);
	root=NULL;
}

int main(){
	nojam5639();
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
void postorder(Node *node){
	if(node!=NULL){
		postorder(node->Lnode);
		postorder(node->Rnode);
		Node *garbege;
		printf("%d\n",node->data);
		garbege=node;
		free(garbege);
	}
}

