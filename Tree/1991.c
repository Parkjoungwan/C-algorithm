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
Node* t_find(Node *tracker,char mid);
void t_pre(Node *tracker);
void t_in(Node *tracker);
void t_ppost(Node *tracker);
Node *midNode;

void nojam1991(){
	scanf("%d", &N);	
	char mid, left, right;
	for(int i=0;i<N;i++){
		scanf("%c",&mid);
		if(mid=='\n'||mid==' ') scanf("%c",&mid);
		midNode=t_find(root,mid);
		scanf("%c",&left);
		if(left==' '||left=='\n') scanf("%c",&left);
		scanf("%c",&right);
		if(right==' '||right=='\n') scanf("%c",&right);
		t_push(midNode, left, right);
	}
	t_pre(root);
	printf("\n");
	t_in(root);
	printf("\n");
	t_ppost(root);
	printf("\n");
}

int main(){
	nojam1991();
}

void t_push(Node* mid, char left, char right){
	Node *lnode, *rnode;
	if(left!='.'){
		lnode = malloc(sizeof(Node));
		lnode->data = left;
		lnode->Lnode = NULL;
		lnode->Rnode = NULL;
		mid->Lnode = lnode;
	}else{
		mid->Lnode = NULL;
	}
	if(right!='.'){
		rnode = malloc(sizeof(Node));
		rnode->data = right;
		rnode->Lnode = NULL;
		rnode->Rnode = NULL;
		mid->Rnode = rnode;
	}else{
		mid->Rnode = NULL;
	}
}

Node* t_find(Node* tracker,char mid){
	if(root==NULL){
		Node *node;
		node = malloc(sizeof(Node));
		node-> data= mid;
		node-> Lnode = NULL;
		node-> Rnode = NULL;
		root=node;
		return root;
	}else if(tracker!=NULL){
		if(tracker->data==mid){
			return tracker;
		}else{
			Node *tmp = t_find(tracker->Lnode,mid);
			if(tmp!=NULL){
				return tmp;
			}
			return t_find(tracker->Rnode,mid);
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
	return;
}
void t_pre(Node* tracker){
	if(tracker!=NULL){
		printf("%c",tracker->data);
		t_pre(tracker->Lnode);
		t_pre(tracker->Rnode);
	}
	return;
}
void t_ppost(Node *tracker){
	if(tracker!=NULL){
		t_ppost(tracker->Lnode);
		t_ppost(tracker->Rnode);
		printf("%c",tracker->data);
	}
	return;
}
