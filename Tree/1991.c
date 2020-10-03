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
void t_pre(Node *tracker);
void t_in(Node *tracker);
void t_ppost(Node *tracker);
Node* t_post(Node *node, char mid);
char mid, left, right;
Node *midNode;

void nojam1991(){
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%c",&mid);
		midNode=t_find(mid);
		scanf("%c %c",&left,&right);
		t_push(midNode, left, right);
	}
	t_pre(root);
	t_in(root);
	t_ppost(root);
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
		node = malloc(sizeof(Node));
		node-> data= mid;
		node-> Lnode = NULL;
		node-> Rnode = NULL;
		root=node;
		return root;
	}
	Node *tracker;
	tracker=root;
	tracker=t_post(tracker, mid);
	return tracker;
}

Node* t_post(Node *node, char mid){
	if(node!=NULL){
		t_post(node->Lnode, mid);
		t_post(node->Rnode, mid);
		if(node->data==mid){
			return node;
		}
		
	}
	return NULL;
}
void t_in(Node* tracker){
	if(tracker!=NULL){
		t_in(tracker->Lnode);
		printf("%c",tracker->data);
		t_in(tracker->Rnode);
	}
	printf("\n");
	return;
}
void t_pre(Node* tracker){
	if(tracker!=NULL){
		printf("%c",tracker->data);
		t_pre(tracker->Lnode);
		t_pre(tracker->Rnode);
	}
	printf("\n");
	return;
}
void t_ppost(Node *tracker){
	if(tracker!=NULL){
		t_ppost(tracker->Lnode);
		t_ppost(tracker->Rnode);
		printf("%c",tracker->data);
	}
	printf("\n");
	return;
}
