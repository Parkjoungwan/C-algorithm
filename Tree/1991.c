#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char data;
	struct Node *Lnode;
	struct Node *Rnode;
}Node;
Node *root;
int N;
void t_push(Node* mid, char left, char right);
Node* t_find(char mid);
void t_pre();
void t_in();
void t_post();

void nojam1991(){
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		char mid, left, right;
		scanf("%c",&mid);
		Node *midNode;
		midNode=t_find(mid);
		scanf("%c %c",&left,&right);
		t_push(midNode, left, right);
	}
	t_pre();
	t_in();
	t_post();
}

int main(){
	nojam1991();
}

void t_push(Node* mid, char left, char right){
	Node *lnode, *rnode;
	lnode = malloc(sizeof(Node));
	rnode = malloc(sizeof(Node));
	lnode->data = left;
	lnode->Lnode = NULL;
	lnode->Rnode = NULL;
	rnode->data = right;
	rnode->Lnode = NULL;
	rnode->Rnode = NULL;
	mid->Lnode = lnode;
	mid->Rnode = rnode;
}

Node* t_find(char mid){
	if(root==NULL){
		Node *node;
		node = malloc(sizeof(Node);
		node-> data= mid;
		node-> Lnode = NULL;
		node-> Rnode = NULL;
		root=node;
		return root;
	}
	Node *tracker;
	tracker=root;
	tracker=t_post(tracker, mid);
}

Node* t_post(Node *node, char mid){
	if(node!=NULL){
		t_post(node->Lnode);
		t_post(node->Rnode);
		if(node->data==mid){
			return node;
		}
		
	}
}
